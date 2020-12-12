.ifndef __INTRO_ASM__
.define __INTRO_ASM__

.bank 0 slot 0

;depack all intro tiles
.macro opening.depackTiles
	mapPage2 :alphabetTiles
	decompress alphabetTiles, $3700 - alphabetTilesSize, alphabetTilesCount
	mapPage2 :openingTiles
	decompress openingTiles, $3700 - alphabetTilesSize - openingTilesSize, openingTilesCount
	decompress openingSpritesTiles, MegamanMaxFrameSize, openingSpritesTilesCount
	mapPage2 :megamanSteadTempTiles
	decompress megamanSteadTempTiles, 0, megamanSteadTempTilesCount 
.endm

;fill the name table with spaces
.macro opening.emptyNameTable
	ld de, $3700 | VramWrite
	ld bc, VdpControlPort ; ld b, 0 ; ld c, VdpControlPort
	out (c), e
	out (c), d
	
	dec c ; ld c, VdpDataPort
	ld de, SpaceTile
	ld h, 4
-:			out (c), e
			out (c), d
		djnz - 
		dec h
	jp nz, - 
.endm

;fades in and out the pre opening text
.macro opening.animatePreOpeningText
	ld bc, $2000
	ld hl, palette.buffer
-:		ld (hl), c
		inc l
	djnz -
	
	mapPage2 :preOpeningText
	ld hl, preOpeningText
	call loadPassiveText
	
	call turnOnVdp	
	ld a, (resolutionDependencies.introTextScroll)
	ld (verticalScroll + 1), a
	call fadeText
.endm

;Load all the objects needed to perform the scroll on the intro animation.
.macro opening.loadObjectTable
	call clearObjectTable
	
	mapPage2 :miscObjects
	ld a, $80
	ld (miscObjectTable.1.yFraction), a
	ld (miscObjectTable.1.ySpeed), a
	
	ld a, $28
	ld (miscObjectTable.2.y), a
	
	ld a, $47
	ld (miscObjectTable.4.y), a
	
	ld a, miscObject.opening.windows
	ld (miscObjectTable.6.frame), a
	ld (miscObjectTable.7.frame), a
	
	inc a ; ld a, miscObject.opening.parapeito
	ld (miscObjectTable.3.frame), a
	ld (miscObjectTable.4.frame), a
	
	ld a, miscObject.opening.megamanHead
	ld (miscObjectTable.16.frame), a
	
	ld a, miscObject.opening.megamanBody
	ld (miscObjectTable.17.frame), a
	
	ld hl, $fc3d
	ld (miscObjectTable.16.y), hl
	ld (miscObjectTable.17.y), hl
	
	ld a, $27
	ld (miscObjectTable.6.y), a
	ld a, $6f
	ld (miscObjectTable.7.y), a
	call verticalObjectsToSprites
	
.endm

;shows the screen
.macro opening.fadeInBackground
	mapPage2 :openingPalettesFade
	call turnOnVdp
	ld c, 3 + 3*29
	ld hl, openingPalettesFade
--:		ld b, 8
		push hl
-:			push bc
			call prepareForVblank
			pop bc
			ld a, (hl)
			and StartKey | BKey
			jp nz, skipOpening
		djnz -
		ld hl, palette.hasNewPalette
		inc (hl)
		inc l
		ex de, hl
		pop hl
		fastLdir 29
		dec c
	jp nz, --
.endm

;copies a line of the openinig text into the vramRaw.buffer
; hl: source
; de : destination
; a : 1
;returns:
; c: 1
.section "opening.copyTextLine" free
opening.copyTextLine:
	ld bc, (27 << 8) | ($98 + 27)
-:		ldi
		ld (de), a
		inc e
	djnz -
	ret
.ends

;plays the opening history text
.macro opening.animateOpeningText
	mapPage2 :openingText
	ld hl, VramWrite | $3c46
	ld (vramRaw.destination), hl
	ld hl, endSeqOuti - ((27*4) + 74)*2
	ld (vramRaw.fastOtirCall), hl	
	ld hl, openingText

	ld iyl, 5
--:		ld a, 1
		ld (vramRaw.haveData), a
		ld de, vramRaw.buffer

		call opening.copyTextLine
		
		ex de, hl
		ld b, 37 ; number of entries between two lines
-:			ld (hl), c
			inc l
			ld (hl), a
			inc l
		djnz -
		ex de, hl
		
		call opening.copyTextLine
		
		ex de, hl
		call fadeText
		ex de, hl
		dec iyl
	jr nz, --
.endm


;add a new object to one of the 12 first positions on the object table
;c: type of the object
.macro opening.addNewObject
	ld b, 12
	ld de, _sizeof_miscObject
	ld hl, miscObjectTable.3.frame
addNewObjectLoop:		
		ld a, (hl)
		or a
		jr nz, addNewObjectNextIteration
		
			ld (hl), c
			inc hl
			inc hl
			inc hl
			ld (hl), a
			inc hl
			ld (hl), $e0
			inc hl
			ld (hl), $ff
			jr endAddNewObject
addNewObjectNextIteration:
		add hl, de
		djnz addNewObjectLoop	
endAddNewObject: 		
.endm

;scroll the windows, parapeitos and megaman up to the title screen
;destroys : all but ix
.section "opening.scrollObjects" free
opening.scrollObjects: ; Prg13_Lbl_a61b
	ld iy, miscObjectTable.3
	ld b, 13
	ld a, $e9
	ld de, (miscObjectTable.1.ySpeed)
-:		ld l, (iy + miscObject.frame)
		dec l
		jp m, ++
		
		ld l, (iy + miscObject.yFraction)
		ld h, (iy + miscObject.y)
		add hl, de
		
		ld (iy + miscObject.yFraction), l 
		ld (iy + miscObject.y), h 
		
		jr c, +
			dec (iy + miscObject.y +1)
+:		inc (iy + miscObject.y +1)
		jr nz, ++
		cp h
		jr nc, ++
			ld (iy + miscObject.frame), 0
			
++:		ld hl, _sizeof_miscObject
		ex de, hl
		add iy, de
		ex de, hl
	djnz -
		ld a, c
		cp 23
		jr c, ++
			ld hl, miscObjectTable.2.yFraction
			push hl
			push hl
			ld bc, (2 << 8) | miscObject.opening.windows
			ld hl, miscObjectTable.1.yFraction
-:				ld a, (hl)
				sub e
				ld (hl), a
				inc hl
				ld a, (hl)
				sbc a, d
				ld (hl), a
				jr nc, +
					ld (hl), $48
					dec hl
					ld (hl), $00
					push bc
					push de
					opening.addNewObject
					pop de
					pop bc
+:				pop hl
				inc c
			djnz -
++:	
	ld a, 2
	cp d
	jr z, +
		inc de
		inc de
+:	ld (miscObjectTable.1.ySpeed), de
	
	ld hl, (miscObjectTable.16.y)
	ld c, d
	add hl, bc
	ld (miscObjectTable.16.y), hl
	
	ld hl, (miscObjectTable.17.y)
	ld c, d
	add hl, bc
	ld (miscObjectTable.17.y), hl
	
	ret
.ends

.define speed tempVars
.macro opening.scrollBackgroud
	ld hl, endSeqOuti - 128
	ld (vramRaw.fastOtirCall), hl
	ld hl, (resolutionDependencies.openingFirstVramLine)
	ld (vramRaw.destination), hl
	ld hl, -$0080
	ld (speed), hl
	
	teste24:
	ld c, 35 + 24
	ld ix, (resolutionDependencies.openingFirstDepackedLine)
	
--:				push bc
				dec ix
				dec ix
				mapPage2 :openingMapLines
				ld c, (ix + 0)
				ld b, (ix + 1)
				ld de, vramRaw.buffer
				call loadVerticalScrollingLine
				ld hl, vramRaw.haveData
				inc (hl)
				ld hl, (vramRaw.destination)
				ld de, -64
				add hl, de
				ld a, (resolutionDependencies.nameTableBegining + 1)
				dec a
				;if the new address is less than the top of the Vdp Name Table, than, warp it around.
				cp h
				jr nz, +
					ld h, $3e | VramWrite.hi
+:				ld (vramRaw.destination), hl
				pop bc
				
				ld b, 16
				ld a, c
				cp 23
				;if the global counter is lesser or equal 23, than reduce the local counter to speed the things up. 
				jp m, +
				;if the global counter is equals 23, than, sets the speed new value and clean the palette entries od the title.
				jr nz, ++
					ld hl, -$0200
					ld (speed), hl
					xor a
					ld hl, palette.buffer + 5
					ld (hl), a
					inc a
					ld hl, palette.hasNewPalette
					ld (hl), a
+:				ld b, 4
++:			
-:			ld hl, (verticalScroll)
			ld de, (speed)
			add hl, de
			xor a
;if the new scroll is 0, then warp it around (in the case of extended resolution, it will do nothing)			
			cp h
			jr nz, +
				ld a, (resolutionDependencies.verticalScrollEnd)
				ld h, a
+:			ld (verticalScroll), hl
			push bc
			call opening.scrollObjects
			call titleScreen.animateMegamanHead
			mapPage2 :miscObjects
			call verticalObjectsToSprites
			call prepareForVblank
			pop bc
			ld a, (hl)
			and StartKey | BKey
			jp nz, skipOpening
			
		djnz -
		;if b is 0 than, its time to output a new line to the vdp.
		dec c
	jr nz, --
.endm

;delay between the opening and the title screen
.macro opening.delay
	ld b, $70
-:		push bc
		call titleScreen.animateMegamanHead
		call verticalObjectsToSprites
		call prepareForVblank	
		pop bc
	djnz -
.endm

; Lbl_9ee7
;main flow of the opening intro of the game
.section "opening" free
opening:
	call turnOffVdp
	opening.depackTiles
	opening.emptyNameTable
	call clearSpriteTable
	opening.animatePreOpeningText
;Prg13_Lbl_9f9d:
teste40:
	ld a, (resolutionDependencies.openingScroll)
	ld (verticalScroll + 1), a
	ld hl, (resolutionDependencies.openingFirstDepackedLine)
	ld de, (resolutionDependencies.openingFirstVramLine)
	call loadVerticalScrollingMap
	opening.loadObjectTable
	opening.fadeInBackground
	
	ld a, :openingMusic
	ld hl, openingMusic
	call PSGPlay
	
	opening.animateOpeningText
	opening.scrollBackgroud
	opening.delay
	ret
.ends	

;sets up the vdp name table and the object table to
;the end of the intro animation
;!!! This function hard codes a new stack pointer !!!
.section "skipOpening" free
skipOpening: ;Prg13_Lbl_a7b0
	ld sp, $dfee
	call turnOffVdp
	ld de, $3780 | VramWrite
	
	ld hl, openingMapLines
	call loadVerticalScrollingMap
	ld a, (resolutionDependencies.introTextScroll)
	ld (verticalScroll + 1), a
	
	mapPage2 :openingPalette
	ld hl, openingPalette + 9
	ld de, palette.buffer + 9
	fastLdir 20
	
	call clearObjectTable
	
	ld a, miscObject.opening.windows
	ld (miscObjectTable.4.frame), a
	inc a ; ld a, miscObject.opening.parapeito
	ld (miscObjectTable.3.frame), a
	ld a, miscObject.opening.megamanHead
	ld (miscObjectTable.16.frame), a
	ld (miscObjectTable.16.frameTimer), a
	ld a, miscObject.opening.megamanBody
	ld (miscObjectTable.17.frame), a
	
	ld hl, $00a0
	ld (miscObjectTable.3.y), hl
	ld hl, $00c8
	ld (miscObjectTable.4.y), hl

	ld hl, $0077
	ld (miscObjectTable.16.y), hl
	ld (miscObjectTable.17.y), hl
		
	jp turnOnVdp ; call + ret
.ends

.section "textFadePalette and fadeText routine" free
textFadePalette:
	.byte $00,$15,$2a,$3f,$3f,$3f,$3f,$3f,$3f,$3f,$3f,$3f,$3f,$3f,$3f,$3f
	.byte $3f,$3f,$3f,$3f,$3f,$3f,$3f,$3f,$3f,$3f,$3f,$3f,$3f,$2a,$15,$00
textFadePaletteEnd:
		
fadeText:		
	ld c, textFadePaletteEnd - textFadePalette ;$fes
	ld hl, textFadePalette
--:		ld b, $0a ;Prg13_Lbl_9f60
		ld a, (hl)
		ld (palette.buffer+1), a
		ld a, 1
		ld (palette.hasNewPalette), a
		push hl
-:			push bc
			call prepareForVblank
			pop bc
			ld a, (hl)
			and StartKey | BKey
			jp nz, skipOpening
		djnz -
		pop hl
		inc hl
		dec c
	jp nz, --
	ret
.ends

.endif