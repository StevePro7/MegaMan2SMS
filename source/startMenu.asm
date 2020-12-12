.ifndef __START_MENU_ASM__
.define __START_MENU_ASM__

.define StartMenu.arrowXpos $58
.define StartMenu.arrowStartYpos $60
.define StartMenu.arrowYMovement (StartMenu.arrowStartYpos*2 + $10) & $ff

.bank 0 slot 0

;loads the start menu directly, it also load all nessessary stuff into vram.
;returns
;zf: 0 if start was selected, 1 if password was selected
.section "startMenu.load" free
startMenu.load:
	ld hl, 0
	ld (verticalScroll), hl
	ld (visualHScroll), hl
	ld (hScroll), hl

	ld hl, startPasswordMenuMap
	call loadBlueGridScreenDirectly
	call clearObjectTable
	
	;set the text to black
	xor a
	ld (palette.buffer + 1), a
	
	call turnOnVdp
	
	mapPage2 :blueGrid.startPasswordText
	ld hl, blueGrid.startPasswordText
	call loadActiveText
	
	;show text
	ld hl, palette.hasNewPalette
	inc (hl)
	inc l
	inc l
	ld (hl), $3f

startMenu.startMenuLoop:	
	mapPage2 :miscObjects

	ld a, StartMenu.arrowXpos
	ld (miscObjectTable.1.x), a
	ld hl, miscObjectTable.1.frame
	ld de, StartMenu.arrowStartYpos | (miscObject.opening.arrow << 8)
	ld (hl), d
-:		ld a, (frameCounter)
		and $08
		ld a, $f0
		jr z, +
			ld a, e
+:		ld (miscObjectTable.1.y), a
		
		push de
		call verticalObjectsToSprites
		call prepareForVblank
		pop de
		ld a, (hl)
		and StartKey | BKey | UKey | DKey
		jr z, -
		and StartKey | BKey
		jr nz, +
			ld hl, cursorSfx
			call PSGSFXPlay
			ld a, StartMenu.arrowYMovement
			sub e
			ld e, a
	jr -

+:  ld a, $60
	cp e
	ret
.ends


.section "startMenu.scroll" free
startMenu.scroll:
	mapPage2 :blueGrid.startPasswordText
	ld hl, blueGrid.startPasswordText
	call loadActiveText
	
	call passwordEditor.fadeInContent
	jp startMenu.startMenuLoop
.ends


.endif