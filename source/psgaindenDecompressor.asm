.ifndef __PSGAINDEN_DECOMPRESSOR_ASM__
.define __PSGAINDEN_DECOMPRESSOR_ASM__

; hl = dest
; de = src
; bc = numberOfTiles

.macro loadBcCounter args count
	.if <count == 0
		ld bc, (<count << 8) | >count
	.else
		ld bc, (<count << 8) | (>count + 1)
	.endif
.endm

; \1 : src
; \2 : dest
; \3 : count
.macro jumpDecompress 
	ld hl, \2 | VramWrite
	ld ix, \1
	.if \3 == 1
		ld (tileDecompVramPtr),hl  ; cache VRAM address
		jp decompressSingleTile
	.else
		.if \3 <= 256
			ld b, \3 & $ff
			jp decompressBTiles
		.else
			ld b, \3 & $ff
			call decompressBTiles
			jp decompressBTilesCachedPointer
		.endif
	.endif
.endm

; \1 : src
; \2 : dest
; \3 : count
.macro decompress 
	ld hl, \2 | VramWrite
	ld ix, \1
	.if 1 == \3
		ld (tileDecompVramPtr),hl  ; cache VRAM address
		call decompressSingleTile
	.else
		.if \3 <= 256
			ld b, \3 & $ff
			call decompressBTiles
		.else
			ld b, \3 & $ff
			call decompressBTiles
			call decompressBTilesCachedPointer
		.endif
	.endif
.endm

.bank 0 slot 0
.section "decompressSingleTile" free
decompressSingleTile:    
	push bc        ; save number of tiles
	ld b,$04     ; count 4 bitplanes
	ld de,tileDecompBuffer ; write to de
    ld c,(ix + 0)    ; c = encoding information for 4 bitplanes
    inc ix

	ld a, $55 ; if a == $55, output the previous tile mirrored
	cp c
	jp z, _OutputMirroredTileToVRAM
	
_DecompressBitplane:
    rlc c        ; %0x = all bits either 0 or 1
    jr nc,_AllTheSame
    rlc c        ; %11 = raw data
    jr c,_RawData

_Compressed:
    ld a,(ix + 0)    ; get method byte
    inc ix

    ex de,hl     ; get bitplane, if it's referring to one
    ld d,a
    and $03
    add a,a      ; calculate address of that bitplane
    add a,a      ; = tileDecompBuffer + bitplane * 8
    add a,a
    ld e,a
    ld a,d       ; get method byte back
    ld d,$00
    ld iy,tileDecompBuffer
    add iy,de    ; now iy points to the referred to bitplane
    ex de,hl

    ; now check the method byte
    cp $03       ; %000000pp
    jr c,_DuplicateBitplane
    cp $10
    jr c,_CommonValue
    cp $13       ; %000100pp
    jr c,_DuplicateBitplaneInvert
    cp $20
    jr c,_CommonValue
    cp $23       ; %001000pp
    jr c,_DuplicateBitplanePartial
    cp $40
    jr c,_CommonValue
    cp $43       ; %010000pp
    jr c,_DuplicateBitplanePartialInvert
    ; fall through

_CommonValue:
    ld h,a       ; h = bitmask
    ld l,(ix + 0)    ; l = common value
    inc ix
    jr _OutputCommonValue

_RawData:
    ld h,$00     ; empty bitmask; no common value
    jr _OutputCommonValue

_AllTheSame:
    rlc c        ; get next bit into carry
    sbc a,a      ; will make $00 if carry = 0, $ff if it's 1
    ld l,a       ; that's the common value
    ld h,$ff     ; full bitmask
    ; fall through

_OutputCommonValue:
    push bc
      ld b,8     ; loop counter
-:    ld a,l     ; get common value
      rlc h      ; get bit out of bitmask
      jr c,+     ; if 1, use the common value
      ld a,(ix + 0)  ; else get it from (ix++)
      inc ix
+:    ld (de),a  ; write to dest
      inc de
      djnz -     ; loop over 8 bytes
    pop bc
  jr _BitplaneDone

_DuplicateBitplane:
    ld hl,$ff00  ; full copy bitmask, empty inversion bitmask
    jr _OutputDuplicate

_DuplicateBitplaneInvert:
    ld hl,$ffff  ; full copy bitmask, full inversion bitmask
    jr _OutputDuplicate

_DuplicateBitplanePartial:
    ld h,(ix + 0)    ; get copy bitmask
    ld l,$00     ; empty inversion bitmask
    inc ix
    jr _OutputDuplicate

_DuplicateBitplanePartialInvert:
    ld h,(ix + 0)    ; get copy bitmask
    ld l,$ff     ; full inversion bitmask
    inc ix
    ; fall through

_OutputDuplicate:
    push bc
      ld b,8     ; loop counter
-:    ld a,(iy + 0)  ; read byte to copy
      inc iy
      xor l      ; apply inversion mask
      rlc h      ; get bit out of bitmask
      jr c,+     ; if 1, use the copied value
      ld a,(ix + 0)  ; else get it from (ix++)
      inc ix
+:    ld (de),a  ; write to dest
      inc de
      djnz -     ; loop over 8 bytes
    pop bc
    ; fall through

_BitplaneDone:
    dec b        ; decrement bitplane counter
    jp nz,_DecompressBitplane ; loop if not zero

_OutputTileToVRAM:
    ld hl,(tileDecompVramPtr)
    ld a, l
	out ($bf), a
	ld a, h
	out ($bf), a
	 ; Add 32 bytes to tileDecompVramPtr
    ld bc,32
    add hl,bc
	ld (tileDecompVramPtr), hl
	
    ld de,$0008  ; we are interleaving every 8th byte
    ld c,e       ; counter for the interleaving run
    ld hl,tileDecompBuffer ; point at data to write

--: ld b,4       ; there are 4 bytes to interleave
    push hl
-:    	ld a,(hl)  ; read byte
		out ($be),a; write to vram
		add hl,de  ; skip 8 bytes
		djnz -
    pop hl
    inc l       ; next interleaving run
    dec c
    jr nz,--

    pop bc
	ret
	
_OutputMirroredTileToVRAM:
    ld hl,(tileDecompVramPtr)
    ld a, l
	out ($bf), a
	ld a, h
	out ($bf), a
    ; Add 32 bytes to tileDecompVramPtr
    ld bc,32
    add hl,bc
	ld (tileDecompVramPtr), hl
	
    ld c,8       ; counter for the interleaving run
    ld hl,tileDecompBuffer ; point at data to write
	ld d, >mirrorTable
		
--: ld b,4       ; there are 4 bytes to interleave
    push hl
-:    	ld e, (hl)
		ld a,(de)  ; read byte
		out ($be),a; write to vram
		ld a, 8 
		add a, l
		ld l, a
		djnz -
    pop hl
    inc l       ; next interleaving run
    dec c
    jr nz,--

	pop bc
	ret	
.ends

.section "mirrorTable" align $100 free
mirrorTable:
    .db $00 $80 $40 $c0 $20 $a0 $60 $e0 $10 $90 $50 $d0 $30 $b0 $70 $f0
	.db $08 $88 $48 $c8 $28 $a8 $68 $e8 $18 $98 $58 $d8 $38 $b8 $78 $f8
	.db $04 $84 $44 $c4 $24 $a4 $64 $e4 $14 $94 $54 $d4 $34 $b4 $74 $f4
	.db $0c $8c $4c $cc $2c $ac $6c $ec $1c $9C $5c $dc $3c $bc $7c $fc
	.db $02 $82 $42 $c2 $22 $a2 $62 $e2 $12 $92 $52 $d2 $32 $b2 $72 $f2
	.db $0a $8a $4a $ca $2a $AA $6a $ea $1a $9a $5a $da $3a $ba $7a $fa
	.db $06 $86 $46 $c6 $26 $a6 $66 $e6 $16 $96 $56 $d6 $36 $b6 $76 $f6
	.db $0e $8e $4e $ce $2e $ae $6e $ee $1e $9e $5e $de $3e $be $7e $fe
	.db $01 $81 $41 $c1 $21 $a1 $61 $e1 $11 $91 $51 $d1 $31 $b1 $71 $f1
	.db $09 $89 $49 $c9 $29 $A9 $69 $e9 $19 $99 $59 $d9 $39 $b9 $79 $f9
	.db $05 $85 $45 $c5 $25 $a5 $65 $e5 $15 $95 $55 $d5 $35 $b5 $75 $f5
	.db $0d $8d $4d $cd $2d $ad $6d $ed $1d $9d $5d $dd $3d $bd $7d $fd
	.db $03 $83 $43 $c3 $23 $a3 $63 $e3 $13 $93 $53 $d3 $33 $b3 $73 $f3
	.db $0b $8b $4b $cb $2b $ab $6b $eb $1b $9b $5b $db $3b $bb $7b $fb
	.db $07 $87 $47 $c7 $27 $a7 $67 $e7 $17 $97 $57 $d7 $37 $b7 $77 $f7
	.db $0f $8f $4f $cf $2f $af $6f $ef $1f $9f $5f $df $3f $bf $7f $ff    
.ends

.bank 0 slot 0
.section "decompressBTiles" free
decompressBTiles:
	ld (tileDecompVramPtr),hl  ; cache VRAM address
decompressBTilesCachedPointer:
-:		call decompressSingleTile
	djnz -
	ret ;done
.ends  

.endif

