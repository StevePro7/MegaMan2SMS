.ifndef __TITLE_SCREEN_ASM__
.define __TITLE_SCREEN_ASM__

.bank 0 slot 0

.define Opening.arrowXpos $30
.define Opening.arrowStartYpos $98
.define Opening.arrowYMovement $40

;number of vBlnaks that each frame will last
.section "titleScreen.megamanExitTimers" free
titleScreen.megamanExitTimers:
	.db 4 4 4 4 12 4 4 4 4 2 2 2
.ends


;animate megamans head before he is getting out of the buiding
.section "titleScreen.animateMegamanHead" free
titleScreen.animateMegamanHead:	
	ld hl, miscObjectTable.16.frameTimer
	dec (hl)
	ret nz
		ld a, 5
		ld (hl), a
		dec hl
		inc (hl)
		inc a; ld a, miscObject.opening.megamanHead + 2
		cp (hl)
		ret nz
			dec (hl)
			dec (hl)
	ret
.ends

;animate megaman exists to the screen.
.macro titleScreen.animateMegamanExit	
	ld c, 12
	ld e, miscObject.opening.megamanHeadExit
		
		ld hl, titleScreen.megamanExitTimers
		push hl
		
--: 	ld a, 4
		cp c
		jr nz, +	
			;when we get here, the head frame anim go back a few steps
			ld e, miscObject.opening.megamanHeadExit + 4
+:		ld a, 3
		cp c
		jr nz, ++
teste5:	
			ld a, :teleportOutSfx
			ld hl, teleportOutSfx
			call PSGPlay
			PSGCancelLoop
			
			;and, when we get here, there is no head anymore, and is the body that animate.
			xor a
			ld (miscObjectTable.17.frame), a
			ld e, miscObject.opening.megamanBodyExit

++:		pop hl
		ld b, (hl)
		inc hl
		push hl
		
		ld hl, miscObjectTable.16.frame
		ld (hl), e
		inc e
		push de
-:			push bc
			call verticalObjectsToSprites
			call prepareForVblank
			pop bc
		djnz -
		pop de
		dec c
	jr nz, --
	pop hl
	
	ld b, $4f
-:		ld a, 15
		ld (miscObjectTable.16.frame), a
		ld hl, (miscObjectTable.16.y)
		ld de, -8
		add hl, de
		ld (miscObjectTable.16.y), hl
		
		push bc
		call verticalObjectsToSprites
		call prepareForVblank
		pop bc

	djnz -	
.endm



;show the title screen of the game.
;this function will expect tiles, nametable and all objects but the cursor loaded.
;returns
; bc: 0, if no action was made.
; difficult: 1 for hard, 0 for normal.
.section "titleScreen" free
titleScreen:
	mapPage2 :titleScreenPalette
	ld hl, palette.hasNewPalette
	inc (hl)
	inc l
	ld de, titleScreenPalette
	ex de, hl
	fastLdir 6
	
	mapPage2 :miscObjects
	
	ld a, :titleMusic
	ld hl, titleMusic
	call PSGPlay
	
	ld a, miscObject.opening.arrow
	ld (miscObjectTable.18.frame), a
	ld a, Opening.arrowXpos
	ld (miscObjectTable.18.x), a
	
	; will contain the Ys position of the arrow
	ld e, Opening.arrowStartYpos
	
	ld bc, $1E0b
-:		ld a, (frameCounter)
		and $08
		ld a, $f0
		jr z, +
			ld a, e
+:		ld (miscObjectTable.18.y), a
		
		push bc
		push de
		call titleScreen.animateMegamanHead
		call verticalObjectsToSprites
		call prepareForVblank
		pop de
		pop bc
		ld a, (hl)
		and StartKey | BKey | UKey | DKey
		jr z, +
		and StartKey | BKey
		jp nz, ++
			;if we got here, than UP or Down were pressed, in this case,
			;change the arrow position and the difficult setting
			ld hl, cursorSfx
			call PSGSFXPlay
			
			ld a, Opening.arrowYMovement
			sub e
			ld e, a
			ld hl, difficult
			ld a, 1
			sub (hl)
			ld (hl), a
+:	djnz -
	dec c
	jr nz, -
	ld a, (PSGMusicStatus)
	or a
	jr z, ++
		call PSGStop
		ld bc, $e201
	jr -
	
++: 
	;save the bc
	push bc	
	call PSGStop
	;clear the arrow
	xor a
	ld (miscObjectTable.18.frame), a
	titleScreen.animateMegamanExit
	pop bc
	
	ret
.ends

.endif