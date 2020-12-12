.ifndef __PASSWORD_EDITOR_ASM__
.define __PASSWORD_EDITOR_ASM__

.bank 0 slot 0

.define ballsBuffer $ca00 ; length: 5
.define cursorColor ($ca00 + 5)

;positions of the balls indicating if a specified boss is alive or dead
;been the 3 most significant bytes are Y and the lesat 5 significant bytes
;contains the mask to be applied on that line.
.section "passwordEditor.bossesExpectedPositions" free
passwordEditor.bossesExpectedPositions:
	.db ((1 << 5) | (1 << 2)), ((2 << 5) | (1 << 0)); bubbleman
	.db ((2 << 5) | (1 << 1)), ((3 << 5) | (1 << 2)); airman
	.db ((1 << 5) | (1 << 3)), ((0 << 5) | (1 << 3)); quickman
	.db ((2 << 5) | (1 << 4)), ((0 << 5) | (1 << 1)); heatman
	.db ((0 << 5) | (1 << 4)), ((2 << 5) | (1 << 2)); woodman
	.db ((3 << 5) | (1 << 0)), ((3 << 5) | (1 << 4)); metalman
	.db ((3 << 5) | (1 << 3)), ((1 << 5) | (1 << 0)); flashman
	.db ((3 << 5) | (1 << 1)), ((1 << 5) | (1 << 4)); crashman
.ends

.section "passwordEditor.cursorPositionTable" align $100 free
passwordEditor.cursorPositionTable:
	.db 0*16, 4*16, 1*16, 0*16
	.db 1*16, 0*16, 2*16, 1*16
	.db 2*16, 1*16, 3*16, 0*16
	.db 3*16, 2*16, 4*16, 3*16
	.db 4*16, 3*16, 0*16, 4*16
.ends

;loads the objects to the editor
.macro passwordEditor.loadPasswordSprites
	ld a, miscObject.passwordEditor.general
	ld (miscObjectTable.1.frame), a
	ld a, miscObject.passwordEditor.cursor
	ld (miscObjectTable.2.frame), a
	call verticalObjectsToSprites
.endm

;puts a new or remove a ball on the grid
; hl : pressedKeys
;returns:
;zf : 1 if a key is actually positioned
; d : $ff, if was suposed to remove a ball, 
;	  $00, if was suposed to positioning one.
.macro passwordEditor.passwordBallPositioning
	; get a byte full of zeroes or full of ones, depending in witch
	;key trigged the call to this macro.
	ld a, (hl)
	.rept 4
		add a, a
	.endr
	sbc a, a
	ld h, a
	
	;get byte index to the ballsBuffer
	ld de, miscObjectTable.2.y
	ld a, (de)
	.rept 4
		rrca
	.endr
	ld l, a
	dec e
	dec e	; miscObjectTable.2.x
	;get bit mask to be applied on the index obteined before
	ld a, (de)
	ld bc, (16 << 8) | %10000000
	add a, b
passwordEditor.passwordBallPositioningUnrollBits:
		rlc c
		sub b
	jr nz, passwordEditor.passwordBallPositioningUnrollBits
	
	ld d, h
	ld h, >ballsBuffer
	
	ld a, (hl)
	xor d
	or c
	xor d
	cp (hl)
	ld (hl), a
	
.endm

;converts the ball buffers system to objects in the object table.
.macro passwordEditor.ballsBufferToObjects
	ld hl, miscObjectTable.3.frame
	ld de, _sizeof_miscObject
	ld bc, 9 << 8
	push hl
-: 		ld (hl), c
		add hl, de
	djnz -
	
	pop iy
	ld hl, ballsBuffer + 4
--:		ld bc, (4 << 12)|(1 << 4)
-:			ld a, (hl)
			and c
			jr z, +
				ld (iy + miscObject.frame), miscObject.passwordEditor.ball
				ld (iy + miscObject.x), b
				ld a, l
				.rept 4
					add a, a
				.endr
				ld (iy + miscObject.y), a
				add iy, de
+:			srl c
			ld a, b
			sub 16
			ld b, a
		jr nc, -
		dec l
	jp p, --	
.endm

;updates the ball counter on the screen by changing the tile in the Vram
; a: value of the counter change (1 or -1)
.section "passwordEditor.updateBallCounter" free
passwordEditor.updateBallCounterRawDataInit:
	.db $01 
	.dw VramWrite | $05e0, endSeqOuti - 64
passwordEditor.updateBallCounter:
	ld bc, (64 << 8) | (VdpDataPort + 5)
	ld e, a
	.rept 5
		add a, a
	.endr
	add a, $c0
	out (VdpControlPort), a
	ld a, $31
	bit 3, e ;the original value is 8 or 9, so the carry flag will ocur in the last add a, a
	jr nz, +
	jr nc, ++
+:		inc a
++:	out (VdpControlPort), a
	
	ld de, vramRaw.haveData
	mapPage2 :passwordEditor.updateBallCounterRawDataInit
	ld hl, passwordEditor.updateBallCounterRawDataInit
	fastLdir 5
	ex de, hl
-:		ini
	djnz -	
	ret
.ends


;animate the cursor and the balls counter
.section "passwordEditor.passCursorColors" align $100 free
passwordEditor.passCursorColors:
	.db $00 $15 $2a $3f $3f $3f $2a $15
.ends
.macro passwordEditor.animatePassCursor
	ld hl, palette.hasNewPalette
	inc (hl)
	
	ld l, <(palette.buffer + 17)
	xor a
	or ixh
	jr z, ++
		ld de, cursorColor
		ld a, (de)
		inc a
		and %00001111
+:		ld (de), a
		ld d, >passwordEditor.passCursorColors
		rra
		ld e, a
		ld a, (de)
++:	ld (hl), a	
.endm

;hl: address of the expected boss position in the buffer
;zf: if the boss is present, the flag will return != 0
.section "passwordEditor.isBossPresent" free
passwordEditor.isBossPresent:
	ld a, (hl)
	push bc
	ld c, a
	rlca
	rlca
	rlca
	ld e, a
	ld d, >ballsBuffer
	ld a, c
	and %00011111
	ld b, ixl
	inc b
	rrca
-:		rlca
		cp %00100000
		jr nz, +
		ld a, 1
		inc e
+:	djnz -
	ld c, a
	ld a, %00000011
	and e
	inc a
	ld e, a
	ld a, (de)
	and c
	pop bc
	ret	
.ends

; \1: jump location when the password is correct
; returns:
; c: bosses
; ixl: eTanks
.macro passwordEditor.validadePassword
	ld hl, passwordEditor.bossesExpectedPositions
	ld c, $ff ; numETanks
	
	ld a, (ballsBuffer)
-:		inc c
		srl a
	jr nz, -		
	ld ixl, c		
	ld bc, 1		;b: bosses beat´n, c: mask

-:		call passwordEditor.isBossPresent
		inc hl
		jr nz, +
		call passwordEditor.isBossPresent
		jp z, ++
			ld a, c
			add a, b
			ld b, a
+:			inc hl
		sla c
	jr nz, -
	jp \1
++:	
.endm

; b: bosses beaten
; ixl: num etanks 
.section "passwordEditor.passwordHitText" free
passwordEditor.passwordHitText:
	.byte 1
	.word $3a96 | VramWrite
	.word endSeqOuti - 8*4
	.word $0198
	.word $01A8
	.asc " B A Q H W M F C 1 2 3"
.ends
.macro passwordEditor.passwordHit
	ld c, 0
	ld a, Item1Boss ; HeatMan
	and b
	.if 1 == Item1Boss
		add a, c
		ld c, a
	.else
		jr z, +
			inc c
	.endif
+:	ld a, Item2Boss ; AirMan
	and b
	.if 2 == Item2Boss
		add a, c
		ld c, a
	.else
		jr z, +
			set 1, c
	.endif
+:	ld a, Item3Boss ;FlashMan
	and b
	.if 4 == Item3Boss
		add a, c
		ld c, a
	.else
		jr z, +
			set 2, c
	.endif
+:
	ld hl, numEtanks
	ld e, ixl
	ld (hl), e  ;numEtanks
	inc l
	ld (hl), b  ; bossesBeaten
	inc l
	ld (hl), c  ; itens
	push bc
	call passwordEditor.cleanAndFade
	
	ld hl, passwordHitMap
	call loadBlueGridScreenFromLeft

	ld hl, passwordEditor.passwordHitText
	ld de, vramRaw.haveData
	fastLdir 7
	push hl
	ld hl, vramRaw.buffer
	fastLdir 46
	pop hl
	ld e, <vramRaw.buffer + 2
	fastLdir 2
	
	pop ix
	ld a, ixh 
	ld bc, (8 << 8) | (16 + 1 + 6 + 1)
	
-:			rra
			jr c, +
				ldi
				inc hl
				dec c
				inc e
				inc e
			jr ++
+:				ldi
				inc e
				ldi
++:				inc e
			djnz -
	
		ld a, ixl
		ld b, 3
		dec c
	jr nz, -

	ld bc, (3 << 8)| $ff
-		push bc
		call prepareForVblank
		ld hl, vramRaw.haveData
		inc (hl)
		inc l
		ld a, 128
		add a, (hl)
		ld (hl), a
		inc l
		jr nc, +
			inc (hl)
+:		ld de, vramRaw.buffer
		ld hl, vramRaw.buffer + 16
		fastLdir 32
		pop bc
	djnz -	
	ld hl, vramRaw.haveData
	ld (hl), b
	call passwordEditor.fadeInContent
.endm


;shows the password editor screen, this function will expect
;the blue grid vdp stuff already loaded.
;returns
;zf: 1 if has a password hit, or 0 if it's fails
.section "passwordEditor" free
passwordEditor:
	ld hl, ballsBuffer
	ld b, 6
	xor a
-:		ld (hl), a
		inc l
	djnz -	
	call passwordEditor.fadeOutContent
	call clearObjectTable
	
	mapPage2 :passwordMenuMap
	ld hl, passwordMenuMap
	call loadBlueGridScreenFromLeft
	mapPage2 :miscObjects
	passwordEditor.loadPasswordSprites
	ld a, 9
	call passwordEditor.updateBallCounter
	call passwordEditor.fadeInContent
	ld hl, pressedKeys
	;ixl: number of frames that the cursor stand still with a key holded
	;ixh: number of balls left to be positioned
	ld ix, (9 << 8) | $19
passwordEditor.passwordMainLoop:	
		ld a, UKey | DKey | LKey | RKey
		and (hl)
		jr nz, updateCursorPositionJp
		
		ld a, BKey | CKey
		and (hl)
		jr z, passwordEditor.passCheckDpadHolded
		passwordEditor.passwordBallPositioning
		;if nothing has changed (tryng to remove a ball where didn't existed
		;or positioning one where alread there's one), then, do not update the
		;counter
		jr z, passwordEditor.passResetTimer
			ld a, d
			add a, a
			jp nz, +
				push af
				ld hl, upSfx
				call PSGSFXPlay
				pop af
+:			inc a
			neg
			add a, ixh
			ld ixh, a
			call passwordEditor.updateBallCounter
		jr passwordEditor.passResetTimer
passwordEditor.passCheckDpadHolded:	
		ld l, <holdedKeys
		ld a, UKey | DKey | LKey | RKey
		and (hl)
		jr z, passwordEditor.passResetTimer
		
		dec ixl
		jr nz, passwordEditor.ballsBufferToObjects
		ld ixl, $19 - 8
updateCursorPositionJp:
		ld d, >passwordEditor.cursorPositionTable
		ld b, 2
		call updateCursorPosition
		jr passwordEditor.ballsBufferToObjects
passwordEditor.passResetTimer:		
		ld ixl, $19
		ld l, <pressedKeys
		
passwordEditor.ballsBufferToObjects:	
		mapPage2 :miscObjects
	
		passwordEditor.animatePassCursor
		passwordEditor.ballsBufferToObjects
		call verticalObjectsToSprites
		call prepareForVblank
		
		xor a
		cp ixh
	jp nz, passwordEditor.passwordMainLoop
passwordEditor.validadePassword:
	passwordEditor.validadePassword passwordEditor.passwordHit
	call passwordEditor.cleanAndFade
	
	mapPage2 :startPasswordMenuMapEnd
	ld hl, startPasswordMenuMapEnd
	call loadBlueGridScreenFromRight
	
	mapPage2 :blueGrid.passwordFailText
	ld hl, blueGrid.passwordFailText
	call loadActiveText
	
	call passwordEditor.fadeInContent
	call passwordEditor.delay
	call passwordEditor.fadeOutContent
	inc b ; turn z flag 0
	ret
passwordEditor.passwordHit:
	passwordEditor.passwordHit
	jp passwordEditor.delay ;call + ret
.ends	


;delays utilized after a password after an password input atempt
;returns:
; b: 0
; zf: 1
.section "passwordEditor.delay" free
passwordEditor.delay:
	ld b, $7d
-:		push bc
		call prepareForVblank
		pop bc
	djnz -
	ret
.ends

.section "passwordEditor.cleanAndFade" free
passwordEditor.cleanAndFade:
	call passwordEditor.delay
	call passwordEditor.fadeOutContent
	call clearObjectTable
	jp prepareForVblank ; call + ret
	
.ends


;fade out the tipical content in a blue grid screen (maybe move this to a file apart)
;return
; b: 0
;zf: 1
.section "passwordEditor.fadeOutContent" free
passwordEditor.fadeOutContent:
	ld bc, (16 << 8) | %00000011 
-:		ld a, c
		and b
		push bc
		jr nz, +
			ld hl, palette.hasNewPalette
			inc (hl)
			inc l
			inc l
			ld hl, palette.buffer
			ld b, BackgroundDinamicPalEntries
			call fadeOutPalette
			ld l, (<palette.buffer) + 17
			ld b, SpriteDinamicPalEntries
			call fadeOutPalette
+:		call prepareForVblank
		pop bc
	djnz -
	ret	
.ends

.section "passwordEditor.fadeInContent" free
passwordEditor.fadeInContent:
	mapPage2 :blueGrid.backgroundPalette
	ld b, 4
-:		push bc
		call prepareForVblank
		pop bc
		ld a, (frameCounter)
		and %00000011
		jr nz, -
			ld hl, palette.hasNewPalette
			inc (hl)
			inc l
			ld de, blueGrid.backgroundPalette+1
			ex de, hl
			push bc
			ld c, b
			ld b, BackgroundDinamicPalEntries
			call fadeInPalette
			ld hl, blueGrid.spritePalette + 1
			ld de, palette.buffer + 17
			pop bc
			push bc
			ld c, b
			ld b, SpriteDinamicPalEntries
			call fadeInPalette
			pop bc
	djnz -
	call prepareForVblank
	ret
.ends

.endif