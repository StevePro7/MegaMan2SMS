.ifndef __MAP_LOADERS_ASM__
.define __MAP_LOADERS_ASM__

;loads a single name table line from a vertical oriented map into the
;vramRaw.buffer.
;bc: origin
;de: destination
;returns:
;de: the next free position.
;destroys:
;everything but the index registers.
.section "loadVerticalScrollingLine" free
building:
.db $0A $0B $00 $01 $0E $0F $00 $01 $0E $0F $00 $01
buildingEnd:	

loadVerticalScrollingLine:
	mapPage2 :openingMapLines
	push bc
	ld h, d
	ld l, e
	ld c, 32
	
--:		ex (sp), hl; get origin address
		ld a, (hl)
		or a
		jr z, +
		inc hl
		
		ld e, a ;get local counter
		rrca
		rrca
		and $1f
		inc a
		ld b, a
		
		sub c; subtract local counter from global conter
		neg
		ld c, a
		
		ld a, e ; get the increment
		rlca
		and $01
		ld d, a
		
		ld a, e; get byte
		and $03
		ld e, a
		
		ld a, (hl); get another byte
		inc hl
		ex (sp), hl; get destination address
		
	-:		ld (hl), a
			inc hl
			ld (hl), e
			inc hl
			add a, d
		djnz -	
		
		dec c
		inc c
	jr nz, --
	ld e, l
	ld d, h
	pop bc
	ret
	
+:	ld hl, building
	ld bc, ((buildingEnd - building) << 8) + $ff
	pop de
	inc a ;ld a, $01
	
-:		ldi
		ld (de), a
		inc de
	djnz -	
	ret
.ends	

;loads 28 lines of a vertical orienteded map into vram
;de : Vram Address of the first line in the Name table
;hl : Address of the poiter of the first line
;destroys:
;everything but: ix, iyl
.section "loadVerticalScrollingMap" free
loadVerticalScrollingMap:
	call turnOffVdp
	mapPage2 :openingMapLines
	ld (vramRaw.destination), de
	push hl
	
	ld hl, endSeqOuti - 128
	ld (vramRaw.fastOtirCall), hl
	
	ld iyh, 28
		
-:		ld de, vramRaw.buffer
		pop hl
			ld c, (hl)
			inc hl
			ld b, (hl)
			inc hl
		push hl
		call loadVerticalScrollingLine
		ld c, VdpControlPort
		ld hl, vramRaw.destination
		push hl
		call outputRawData
		pop hl
		
		ld a, $40
		add a, (hl)
		ld (hl), a
		jr nc, +
			inc l
			inc (hl)
			ld a, $3f | VramWrite.hi
			cp (hl)
			jr nz, +
				ld a, (resolutionDependencies.nameTableBegining + 1)
				ld (hl), a
+:		dec iyh
	jr nz, -;	
	pop hl
	ret	
.ends


;hl: address od the column
;c : orientation
.section "depackMenuColumns" free
depackMenuColumns:
	ld de, column.buffer
	ld b, VramRowCount*4
	ld a, 1
-:		ld (de), a
		inc e
	djnz -
	
	ld b, <column.buffer ;load least significant part of the column buffer
		push hl
		push hl
---:	pop hl
		push bc			;saves orientation
		ld c, (hl)
		inc hl
--:			dec c
			jr z, ++
				ld a, (hl)		
				inc hl
				ex (sp), hl		; the top of stack contains the orientation
				add a, l
				ld e, h  		; load least significant part of the column buffer
				ex (sp), hl		; retrieves the orientation to the top of the stack
				
				push af
					ld a, (hl)
					inc hl
					rlca
					rlca
					ld b, a
					and %00111100
					or  %00000010
					add a, e
					ld e, a			   ;set the destination address on the buffer
					
					ld a, b 	
					rlca
					rlca
					and %00001111
					
					ld b, a            ;load number of tile pairs in the middle section
				pop af

				push hl
					ld l, a
					ld h, >blueGridMetaTiles ;load the tile
					call loadTilePair
					dec b
					jr z, +
-:						call loadTilePair
						dec l
						dec l
					djnz -
+:					inc l
					inc l
					call loadTilePair
				pop hl
			jr --
++:		pop bc
		ld a, <column.buffer
		cp b 
		ret nz ; if the least significant part of the column buffer is not 0
			   ;then the second column just have been written
		
		ld a, <columnOrientation.right
		sub c
		ld c, a
		ld b, <column.buffer + (VramRowCount*2)
	jr ---
	ret
	
loadTilePair:
	ld a, 1
	inc bc
	inc bc
	.rept 2
		ldi
		ld (de), a
		inc de
	.endr
	ret	
	
.ends

.macro configureVdpToBlueGridScreen
	call turnOffVdp
	
	ld a, (resolutionDependencies.introTextScroll)
	add a, 8
	ld (verticalScroll+1), a
	xor a
	ld (hScroll), a
	
	ld hl, vdpMisc1Value
	res BitM1HideLeftColoum, (hl)

	mapPage2 :blueGridsTiles
	decompress blueGridsTiles, $2020, blueGridsTilesCount
	mapPage2 :passwordMenuTiles
	decompress passwordMenuTiles, $0400, passwordMenuTilesCount
	mapPage2 :openingSpritesTiles
	decompress openingSpritesTiles + arrowTile, $03E0, 1
	
	mapPage2 :alphabetTiles
	decompress alphabetTiles.1 + alphabetTiles, $0400 + passwordMenuTilesSize, 5
	decompress alphabetTiles.A + alphabetTiles, $0400 + passwordMenuTilesSize + 32*5, 5
	decompress alphabetTiles, $3700 - alphabetTilesSize, alphabetTilesCount
	
	ld b, 80
	ld a, passwordMenuTilesSize
	out (VdpControlPort), a
	ld a, $04 | VramWrite.hi
	out (VdpControlPort), a
-:		
		in a, (VdpDataPort)
		ld a, $ff
		out (VdpDataPort), a 
		in a, (VdpDataPort)
		in a, (VdpDataPort)
	djnz -
	teste25:
	;load the backgroud palette
	ld a, :blueGrid.backgroundPalette
	ld (MapperSlot2), a
	ld hl, blueGrid.backgroundPalette
	ld de, palette.hasNewPalette
	fastLdir 8
	;load the sprite palette
	ld hl, blueGrid.spritePalette
	ld de, palette.buffer + 16
	fastLdir 5

	xor a
	ld (paletteAnimation.framesPerFrame), a
	
.endm


;loads a blueGrid style screen directly (without scrolling, or anything like that)
; it's also loads the nessessary tiles to those screens
; and the palette will be pre loaded into the buffer palette buffer
;hl:screens first column address
.section "loadBlueGridScreenDirectly" free
loadBlueGridScreenDirectly:	
	push hl
	configureVdpToBlueGridScreen
	
	ld a, :mainMenuMusic
	ld hl, mainMenuMusic
	call PSGPlay
	
	pop hl
	mapPage2 :blueGridMetaTiles
	ld ixh, $fe
	
	ld bc, 16 << 8
--:		
		push bc
		call depackMenuColumns
		push hl
		
		ld bc, 2 << 8 | VdpDataPort
-:			push bc
			
			ld a, ixh
			inc a
			inc a
			ld ixh, a
			
			call outputColumn
			
			ld l, <column.buffer + (VramRowCount*2)
			ld de, column.buffer
			fastLdir 2*VramRowCount
			pop bc
		djnz -	
		
		pop hl
		pop bc
	djnz --
	jp turnOnVdp ;call turnOnVdp
				 ;ret
.ends

;number of column at VDP
;a: least significant part of address
; hl, pointer to buffer
.section "outputColumn" free
outputColumn:
	ld hl,column.buffer 
	ld b, VramRowCount*2
	ld e, (>VramWrite | $37)
	
	sub 64
	
-:		ld c, VdpControlPort
		out (c), a
		out (c), e
		dec c

		outi
		add a, 64
		jr nc, +
			inc e
+:			
		outi
	jp nz, -
	ret
.ends
		
;loads a blueGrid style screen scrolling int from left
;hl:menu's first column address
;horizontalScroll: 0
.section "loadBlueGridScreenFromLeft" free
loadBlueGridScreenFromLeft:	
	mapPage2 :blueGridMetaTiles

	ld ixh, $fe
	
	ld bc, <columnOrientation.left | (16 << 8) 
--:		push bc
		call depackMenuColumns
		push hl
		
		ld b, 2
-:			push bc
	
			ld a, (hScroll)
			add a, 8
			ld (hScroll), a
			ld (visualHScroll), a
			call prepareForVblank
		
			ld a, ixh
			inc a
			inc a
			ld ixh, a
			call outputColumn

			.rept 2
				call prepareForVblank
			.endr
			
			ld hl, column.buffer + (VramRowCount*2)
			ld de, column.buffer
			fastLdir 2*VramRowCount
			pop bc
		djnz -
		
		pop hl
		pop bc
	djnz --
	ret
.ends

;loads a blueGrid style screen scrolling it from right
;hl: screens's last column address plus 2
;horizontalScroll: 0
.section "loadBlueGridScreenFromRight" free
loadBlueGridScreenFromRight:	
	mapPage2 :blueGridMetaTiles
	
	ld ixh, VramColumnCount << 1
	
	ld bc, <columnOrientation.right | (16 << 8)
--:		push bc
		inc hl
-:			dec hl
			dec hl
			ld a, %00001111
			cp (hl)
		jp c, -
		
		push hl
		call depackMenuColumns
		
		ld b, 2
-:			push bc
			
			ld a, (hScroll)
			sub 8
			ld (hScroll), a
			ld (visualHScroll), a
			call prepareForVblank
			
			ld a, ixh
			dec a
			dec a
			ld ixh, a 
			call outputColumn
			
			.rept 2
				call prepareForVblank
			.endr
			ld hl, column.buffer + (VramRowCount*2)
			ld de, column.buffer
			fastLdir 2*VramRowCount
			pop bc
		djnz -

		pop hl
		
		pop bc
	djnz --
	ret
.ends



.endif