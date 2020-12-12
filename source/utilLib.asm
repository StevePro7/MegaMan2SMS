.ifndef __UTIL_LIB_ASM__
.define __UTIL_LIB_ASM__

.bank 0 slot 0

.macro setDebugBorderColor
.if DEBUG == 1
	push af
	ld a, 16
	out (VdpControlPort), a
	ld a, CramWrite.hi
	out (VdpControlPort), a
	
	.if $ff == \1
		ld a, (palette.buffer+16)
	.else
		ld a, \1
	.endif
	
	out (VdpDataPort), a
	pop af
.endif	
.endm

.macro fastOtir args count
  .if count == 256
    call endSeqOuti - 256*2
  .else
    .if count > 256
      ld b, count >> 8
fastOtirLoop:
      call endSeqOuti - 256*2
      djnz fastOtirLoop
    .endif
    .if count & $00ff != 0
      call endSeqOuti - (count & $00ff)*2
    .endif
  .endif
.endm

.macro jpFastOtir args count
  .if count == 256
    jp endSeqOuti - 256*2
  .else
    .if count > 256
      ld b, count >> 8
fastOtirLoop:
      jp endSeqOuti - 256*2
      djnz fastOtirLoop
    .endif
    .if count & $00ff != 0
      jp endSeqOuti - (count & $00ff)*2
    .endif
  .endif
.endm

.macro fastLdir args count
  .if count == 256
    call endSeqLdi - 256*2
  .else
    .if count > 256
      ld b, count >> 8
fastLdirLoop:
      call endSeqLdi - 256*2
      djnz fastLdirLoop
    .endif
    .if count & $00ff != 0
      call endSeqLdi - (count & $00ff)*2
    .endif
  .endif
.endm


.macro jpfastLdir args count
  .if count == 256
    jp endSeqLdi - 256*2
  .else
    .if count > 256
      ld b, count >> 8
fastLdirLoop:
      jp endSeqLdi - 256*2
      djnz fastLdirLoop
    .endif
    .if count & $00ff != 0
      jp endSeqLdi - (count & $00ff)*2
    .endif
  .endif
.endm

.macro jumpDe
  push de
  ret
.endm

.bank 0 slot 0
.section "seqOuti" free
  .rept 256
    outi
  .endr
endSeqOuti:
  ret
.ends

.section "seqLdi" free
  .rept 256
    ldi
  .endr
endSeqLdi:
  ret
.ends

.section "callDe" free
callDe:  
  jumpDe
.ends


;put the vdp into a passive state.
.section "turnOffVdp" free
turnOffVdp: ; Lbl_a52d
	ld a, (vdpMisc2Value)
	and $ff~(M2DisplayEnabled)
	out (VdpControlPort), a
	ld (vdpMisc2Value), a
	
	ld a, VdpMisc2
	out (VdpControlPort), a

	ld a, (vdpMisc1Value)
	and $ff~(M1LineInterrupts)
	out (VdpControlPort), a
	ld (vdpMisc1Value), a
	
	ld a, VdpMisc1
	out (VdpControlPort), a
	
	ret 
.ends

;allows vdp frame interrupts. The vdp will go active on the vBlankHandler
.section "turnOnVdp" free	
turnOnVdp: ; Lbl_a51d ; the Vdp will be enabled on the next vBlank
	;in a, (VdpStatusPort); consume interrupt flag
	ld a, (vdpMisc1Value)
	or M1LineInterrupts
	ld (vdpMisc1Value), a
	out (VdpControlPort), a
	
	ld a, VdpMisc1
	out (VdpControlPort), a
/*	
	ld a, (vdpMisc2Value)
	or M2DisplayEnabled | M2FrameInterrupts
	ld (vdpMisc2Value), a
	out (VdpControlPort), a
	
	ld a, VdpMisc2
	out (VdpControlPort), a
	*/
	ret 
.ends



;de: VDP address
;hl: type of satus bar(megaman life, weapon or boss life)
.section "outputStatusBarTiles" free
outputStatusBarTiles:
	ld c, VdpControlPort
	out (c), e
	out (c), d
	dec c
	
	ld e, 4
----:
		ld d, e
		ld b, 4
---:		
			push bc
			push hl
			ld b, 10
			dec d
			jp m, +
--:					ld hl, outputStatusBarTiles.blackLine
+:			
				ld a, 4
-:					outi
					dec a
 				jr nz, -
			djnz --
			pop hl
			pop bc
		djnz ---	
		dec e
	jp p, ----
	ret
outputStatusBarTiles.blackLine:
	.db $00 $ff $00 $00
outputStatusBarTiles.megamanLife:
	.db $7E $E7 $00 $00
.ends


;load texts during blank period in the following format:
;numLines [numChar+2 vramAddress [char]]
;hl: pointer to the first position
.section "loadPassiveText" free
loadPassiveText:
	ld d, (hl)
	inc l
	ld a, %00000001
	ld c, VdpControlPort
--:		ld b, (hl)
		inc hl 
		outi
		outi
		dec c
-:			outi
			out (VdpDataPort), a
		jr nz, -
		inc c
		dec d
	jp nz, --
	ret
.ends

;loads a text into the screen with the Vdp turned on in the following format:
; numLines [vramAddress fastOtirAddrCall [char]]
;hl: text pointer

.section "loadActiveText" free
loadActiveText:
	ld b, (hl)
	inc hl
--:		push bc
		ld a, 1
		ld de, vramRaw.haveData		
		ld (de), a
		inc e
		ld b, (hl)
		inc hl
		ld c, $ff
		fastLdir 4
-:			ldi
			ld (de), a
			inc e
		djnz -
		push hl
		call prepareForVblank
		pop hl
		pop bc
	djnz --
	ret
.ends

;updates a cursor's position on a grid based menu.
;it will give priority to right or left movements.
;d: most significant part of the position table address
;b: number of right shifts on the position

.section "updateCursorPosition" free
updateCursorPosition:
	jr z, +
		ld hl, cursorSfx
		push af
		call PSGSFXPlay
		pop af
+:	
	ld hl, miscObjectTable.2.y
	cp (UKey | DKey) + 1
	jr c, +
		ld l, <miscObjectTable.2.x
		rra
		rra
		and %00000011
+:	ld e, a
	ld a, (hl)
-:		rrca
	djnz -
	or e
	ld e, a
	ld a, (de)
	ld (hl), a
	ret
.ends


;fade out the pallete in one level
;hl: start position on the palette buffer
;b: number of entries to be faded
.section "fadeOutPalette"
fadeOutPalette:
-:		ld a, (hl)
		call fadeColor
		ld (hl), a
		inc l
	djnz -
	ret
.ends

;fade in the pallete in a especified level
;hl: start position on the stored palette witch will be faded
;de: start position on the destination buffer
;b: number of entries to be faded
;c: level of the fadding (the higher, the darker)
.section "fadeInPalette"
fadeInPalette:
--:		ld a, (hl)
		push bc
-:			dec c
			jr z, +
			call fadeColor
		jr -
+:		pop bc
		ld (de), a
		inc hl
		inc e
	djnz --
	ret
.ends

;fade a color in a, returns also in a
.section "fadeColor" free
fadeColor:
	push hl
	ld h, a
	ld l, %00010000
-:		cp l
		push hl
		jr nc, +
			ld l, 0
			ex (sp), hl
+:		dec l
		and l
		inc l
		sra l
		sra l
	jr nz, -
	
	pop hl
	ld a, h
	sub l
	pop hl
	sub l
	pop hl
	sub l
	pop hl
	ret
.ends

.macro mapPage2
	ld a, \1
	ld (MapperSlot2), a
.endm

.endif