.ifndef __MAPS_ENGINE_ASM__
.define __MAPS_ENGINE_ASM__

.define TileLadder 64
.define MegamanScrollDownSpeed $fc7a
.define MegamanScrollRightSpeed $0070
 

;c: line
;destroys everything
.section "gameplayMapsEngine.loadLine" free
gameplayMapsEngine.loadLine:
	ld hl, vramRaw.haveData
	ld (hl), 1
	inc c	;adjust the line, now 0 is the one to be loaded on $3800
	res 5, c
	ld a, c
	inc l
	ex de, hl
	
	;calculate the Vram address to the line
	add a, 2
	and %00011111
	rla
	rla
	rla
	ld l, a
	ld h, 0
	add hl, hl
	add hl, hl
	add hl, hl
	ld a, VramWrite.hi | $37
	add a, h
	cp VramWrite.hi | $3f
	jr c, +
		sub $3f - $37
+:	
	ex de, hl
	ld (hl), e
	inc l
	ld (hl), a
	inc l
	
	ld (hl), <endSeqOuti-128
	inc l
	ld (hl), >(endSeqOuti - 128)
	inc l; vramRaw.buffer
	push hl	;saves vramRaw.buffer on the stack
	
	;load the first metatile address and the line number
	ld hl, (hScroll) 	
	ld l, c	
teste14:
	xor a
	srl l
	;load least significant bit of the line to a, this indicates witch bytes of the meta tile will be loaded.
	rra
	rlca
	
	ld bc, $10ff

-:		ld e, (hl)
		ld d, >metaTiles
		ex (sp), hl
		ex de, hl

		or a
		jr z, +
			inc h
			inc h
			inc l
			inc l
			
+:		
		push hl
		ldi
		inc h
		ldi

		pop hl
		set 2, h
		ldi
		inc h
		ldi

		ex de, hl
		ex (sp), hl
		ld e, a
		ld a, 16
		add a, l
		ld l, a
		ld a, e
		teste15:
	djnz -
	
	pop de
	ret
.ends

;output in hl
.section "gameplayMapsEngine.adjustScrollPostion" free
gameplayMapsEngine.adjustScrollPostion:
	sub $80	;convert megaman position into scroll position
	ld l, a		;save new scroll.lo position
	jp c, +
	
	ld a, (limits.ending)
	cp h
	ret nz
		ld l, 0
		ret
+:
	ld a, (limits.beginning)
	cp h
	
	jp nz, ++
		ld l, 0
		ret
++:
	dec h		
	ret
.ends


;a: megaman position hi
;h: megaman position higher
.section "gameplayMapsEngine.horizontalScrollLeft" free
gameplayMapsEngine.horizontalScrollLeftCorrect:
;this correction is necessary because h will come with
;the next block position, not necessary megaman position,
;so when this happens, it's here we should jump
	inc h
gameplayMapsEngine.horizontalScrollLeft:
	call gameplayMapsEngine.adjustScrollPostion
	
gameplayMapsEngine.horizontalScrollLeftNoAdjust:	
	ld de, (visualHScroll) ; loads old hScroll
	ld (hScroll), hl ;saves new
	
	
	;if the new scroll is the same as the previous visual scroll, we have nothing to do
	;since all states will remain tha same (we will still locked to load a colum next frame, if the column to load
	;is on the right, or we will just walk pass the already loaded column to the right, if the column to load is on the left).
	ld a, e
	cp l
	ret z
	
	dec a;this is done bocause if E is with a multiple of eight, we shoud not count as a crossing
	xor l
	
	;if we are crossing a multiple of 8 position, we are sure to have to load another column, so we
	;lock the visual scroll position to the closest multiple of eight, so a column can be load in the next frame.
	and %11111000
	jp z, +
		ld a, e
		and %11111000
		cp e
		jr z,  ++ ;this if for the case where we where locked in a multiple of 8 postition and still are to the left of that
				  ;even after walking right. If that is the case, this test is sure to confirm that
		ld l, a
		ld h, d
+:	
	
	;if the visualScroll is locked in a multiple of eight position
	ld (visualHScroll), hl
	ld a, e
	and %00000111
	jp nz, +
		ld a, (columnToLoad)
		or a ; cp LoadColumnRight
		jr z, +
			ex de, hl
			jp gameplayMapsEngine.loadColumn ;call + ret
+:		ld a, LoadColumnLeft
		ld (columnToLoad), a
		ret

++:
		;this is done for the very rare case when in the previous frame we were moving right and now we are
		;move left but did not catch up, this is very specific, we now that we will have to load a column
		;and save the new scroll.
		;no need to lad the next column to load here, since we are sure to not be ina multiple eight position
		ld (visualHScroll), hl
		jp gameplayMapsEngine.loadColumnRight ;call+ret

		
.ends


;a: megaman position hi
;h: megaman position higher
.section "gameplayMapsEngine.horizontalScrollRight" align $10 free
gameplayMapsEngine.horizontalScrollRightCorrect:
;this correction is necessary because h will come with
;the next block position, not necessary megaman position,
;so when this happens, it's here we should jump
	dec h
gameplayMapsEngine.horizontalScrollRight:
	call gameplayMapsEngine.adjustScrollPostion
	
gameplayMapsEngine.horizontalScrollRightNoAdjust:	
	ld de, (visualHScroll) ; loads old hScroll
	ld (hScroll), hl ;saves new
	
	;if the new scroll is the same as the previous visual scroll, we have nothing to do
	;since all states will remain tha same (we will still locked to load a colum next frame, if the column to load
	;is on the right, or we will just walk pass the already loaded column to the right, if the column to load is on the left).
	ld a, e
	xor l
	ret z
	
	;if we are crossing a multiple of 8 position, we are sure to have to load another column, so we
	;lock the visual scroll position to the closest multiple of eight, so a column can be load in the next frame.
	and %11111000
	jp z, +
		ld a, l
		and %11111000
		ld l, a
		
		add a, 8 ;this if for the case where we where locked in a multiple of 8 postition and still are to the left of that
			 ;even after walking right. If that is the case, this test is sure to confirm that
		cp e
		jr z, +++
		
		
+:	
	
	;if the visualScroll is locked in a multiple of eight position
	ld (visualHScroll), hl
	ld a, e
	and %00000111
	jp nz, +
		ld a, (columnToLoad)
		inc a ; cp LoadLeftColumn, ld a, LoadRightColumn
		jr z, ++
			ex de, hl
			jp gameplayMapsEngine.loadColumnRight	;call+ret	
+:
		xor a; ld a, LoadRightColumn 	
++:		
		ld (columnToLoad), a
	ret

+++:
		;this is done for the very rare case when in the previous frame we were moving right and now we are
		;move right but did not catch up. This is very specific, we now that we will have to load a column
		;and save the new scroll.
		;no need to load the next column to load here, since we are sure to not be in a multiple eight position
		
		ld hl, (hScroll) ; the visualScroll here should be the same as the regular scroll
		 			     ; no need to do this on the left side, since hl arrives in this point unnaltered
		ld (visualHScroll), hl
		ex de, hl
		jp gameplayMapsEngine.loadColumn ;call+ret
	ret

gameplayMapsEngine.loadColumnRight:
gameplayMapsEngine.IncHloadColumn:
	inc h	;get the most significant part of the metaTile's address, based on the most significant part of the scroll
			;its incremented by one because the scroll position indicates the first column on the left 
			
gameplayMapsEngine.loadColumn:
	
	ld a, l
	and %11111000
	ld l, a
	res 3, l ;get the least significant part of the metaTile's address
	
	rrca
	rrca

	;hl: metatiles table
	;de: map table
	ld e, (hl)
	inc e ;ignore the first tile 
	inc e;ignore the first tile 
	ld d, >metaTiles + 2;ignore the first tile 
	
	bit 1, a
	jr z, +
		set 2, d
	
+:	

gameplayMapsEngine.loadOddColumnBuffer:	

;	setDebugBorderColor c221	
	
	exx
	ld DE, (64 << 8) | (>VramWrite | $37)
	ld C, VdpControlPort
	sub D
	out (VdpControlPort), a
	out (C), E
	exx

	ex de, hl
	ld bc, (((7*9)) << 8) | VdpDataPort

	jp +
	
-:		
	.rept 2 index idx	

		inc h
		
		exx
		add a, 64
		out (VdpControlPort), a
		out (C), E		
		exx	
+:	
		outi
		inc sp
		inc h
		outi

		ex de, hl
		inc l
		ld e, (hl)
		dec d
		res 1, d
		ex de, hl
		
		exx
		inc E
		add a, D
		out (VdpControlPort), a
		out (C), E	
		exx
		
		outi
		dec sp
		inc h
		outi
		inc h
		
		exx
		add a, 64
		out (VdpControlPort), a
		out (C), E		
		exx

		outi
		inc sp
		inc h
		outi

		ex de, hl
		inc l
		ld e, (hl)
		dec d
		res 1, d
		ex de, hl
		
		exx
		add a, D
		out (VdpControlPort), a
		out (C), E	
		exx
		
		outi
		dec sp
		inc h
		outi

		
	djnz -
	
	setDebugBorderColor $ff	
	
	
	ei
	ret
	
.ends


.section "gameplayMapsEngine.loadScrollingRight" free
gameplayMapsEngine.loadScrollingRight:
	;ld a, (limits.orientation)
	;push af
	call gameplayMapsEngine.processTransition

+:	;if that is the case, than at least one of the maps involved in the transition had the left column hided
	; so, we go for a more smooth transition in that way.
	
		ld hl, (hScroll)
		push hl	
			call gameplayMapsEngine.loadColumn
		pop af
		dec a
		ld (hScroll+1), a
		ld (visualHScroll+1), a

		ld hl, vdpMisc1Value
		set BitM1HideLeftColoum, (hl)
	
		ld b, 64
	-:		push bc
			ld hl, (hScroll)
			ld de, $0004
			add hl, de
			call gameplayMapsEngine.horizontalScrollRightNoAdjust
			
			ld hl, (objectTable.1.1.x)
			ld de, MegamanScrollRightSpeed
			add hl, de
			ld (objectTable.1.1.x), hl
			call gameplayObjectsToSprites
			call prepareForVblank
			pop bc
		djnz -
		
		ld a, (limits.beginning)
		ld (objectTable.1.1.x.higher), a
		ld a, (limits.orientation)
		rra

	jp nc, +; if horizontal orientation, jusl leave the
		  ;the colum hided and the 1-32 columns showing
		  
		ld hl, (hScroll)
		inc h
	jp gameplayMapsEngine.loadColumn ; call + ret
		  
+:		  
		;It will load columns 1-32, so, if we will
		;show the leftmost column, than
		;its necessary to load the 0 column again
		ld hl, vdpMisc1Value
		res BitM1HideLeftColoum, (hl)
	ret
.ends

;b: number of lines to load
;c: first lines to load
;l: 1 for scrolling down, -1 for scrolling up
;h: 1 if the lines are already preloaded, 2 if is to load the lines without scrolling
;de and hl will not be destroyed
.section "gameplayMapsEngine.verticalScroll" free
gameplayMapsEngine.verticalScroll:

	dec l
	exx
	jr z, +
		ld de, $ffff & (-MegamanScrollDownSpeed)
		jr ++
+:	
		ld de, MegamanScrollDownSpeed
++:
	exx
	inc l
	
--:		push bc
		push hl
		
		dec h
		jr z, +
			push de
			push hl
			call gameplayMapsEngine.loadLine		
			pop hl
			pop de
+:		dec h
		ld b, 1
		jr z, ++
			pop hl
			push hl		;peek the incrementer from the top of the stack
			
			ld b, $02
			add hl, hl
			add hl, hl

-:				ld a, (verticalScroll+1)
				add a, l
				cp d
				jr nz, +
					ld a, e
+:				ld (verticalScroll+1), a

				exx
				ld hl, (objectTable.1.1.y)
				add hl, de
				ld (objectTable.1.1.y), hl
				exx
	
++:				push hl
				push de		;save scrollLimits
				push bc
				exx
				push de
				call gameplayObjectsToSprites
				call prepareForVblank
				pop de
				exx
				pop bc
				pop de
				pop hl
			djnz -	
	
		pop hl
		pop bc
		ld a, c
		add a, l
		;and %00011111
		ld c, a
	djnz --	
	ret
.ends

;h: 1 if the lines are already preloaded, 2 if is to load the lines without scrolling
;de and hl will not be destroyed
.section "gameplayMapsEngine.preLoadScrollDown" free
gameplayMapsEngine.preLoadScrollDown:
	ld a, (resolutionDependencies.verticalScrollEnd)
	ld d, a
	ld e, 0
	ld bc, (resolutionDependencies.preLoadScrollDown)
gameplayMapsEngine.posLoadScrollDown:	
	ld l, 1
	jp gameplayMapsEngine.verticalScroll
.ends

;for loadScrollingDown,
;hl will have the transition pointer
.section "gameplayMapsEngine.scrollDown" free
gameplayMapsEngine.scrollDown:
	ld a, (limits.ending)
	ld hl, hScroll+1
	sub (hl)
	jr nz, gameplayMapsEngine.scrollDownNoTransiontion
		ld l, <endingTransitions.bottom + 1 	;ignore the higher scroll where the transition should happen since it will
										; be here for certain. That information is only usefull for horizontal oriented maps.
		add a, (hl)
		ret z
			ld d, a
			dec l
			ld e, (hl)
			ex de, hl
gameplayMapsEngine.loadScrollingDown:
			push hl
			call object.clearTopHalfObjects
			call gameplayMapsEngine.preAdjust32ColumnVerticalTransition
	
			ld h, 2
			call gameplayMapsEngine.preLoadScrollDown
	
			pop hl
			call gameplayMapsEngine.processTransition
		
			ld h, 1
			call gameplayMapsEngine.preLoadScrollDown
			
			jr +
			
gameplayMapsEngine.scrollDownNoTransiontion:	
	;h will be loaded with something other than 1 or 2
	call object.clearTopHalfObjects
	call gameplayMapsEngine.preLoadScrollDown
	ld hl, hScroll+1
	inc (hl)
	
+:
	ld a, (hScroll+1)
	ld (objectTable.1.1.x.higher), a

	ld bc, (resolutionDependencies.posLoadScrollDown)
	dec h	;h = 0
	call gameplayMapsEngine.posLoadScrollDown
	call gameplayMapsEngine.posAdjust32ColumnVerticalTransition	
	ld a, 1
	ret
.ends

;h: 1 if the lines are already preloaded, 2 if is to load the lines without scrolling
;de and hl will not be destroyed
.section "gameplayMapsEngine.preLoadScrollUp" free
gameplayMapsEngine.preLoadScrollUp:	
	ld bc, (resolutionDependencies.preLoadScrollUp)
	ld a, (resolutionDependencies.verticalScrollEnd)
	ld e, a
	ld d, 0
gameplayMapsEngine.posLoadScrollUp:	
	ld l, -1
	jp gameplayMapsEngine.verticalScroll
.ends

;hl: pointer to the transition
.section "gameplayMapsEngine.scrollUp" free
gameplayMapsEngine.scrollUp:
	call object.clearTopHalfObjects
	
	ld a, (limits.beginning)
	ld hl, hScroll+1
	sub (hl)
	jr nz, gameplayMapsEngine.scrollUpNoTransiontion
		ld l, <beginningTransitions.top + 1	
		
		add a, (hl)
		ret z
			ld d, a
			dec l
			ld e, (hl)
			ex de, hl
gameplayMapsEngine.loadScrollingUp:			
			push hl
			call gameplayMapsEngine.preAdjust32ColumnVerticalTransition
			
			ld h, 2
			call gameplayMapsEngine.preLoadScrollUp
	
			pop hl
			call gameplayMapsEngine.processTransition
		
			ld h, 1
			call gameplayMapsEngine.preLoadScrollUp
			
			jr +
			
gameplayMapsEngine.scrollUpNoTransiontion:	
	
	call gameplayMapsEngine.preLoadScrollUp
	ld hl, hScroll+1
	dec (hl)
	ld hl, visualHScroll+1
	dec (hl)
	
+:
	
	ld a, (hScroll+1)
	ld (objectTable.1.1.x.higher), a
	
	ld bc, (resolutionDependencies.posLoadScrollUp)
	dec h
	call gameplayMapsEngine.posLoadScrollUp
	jp gameplayMapsEngine.posAdjust32ColumnVerticalTransition

.ends

.macro gameplayMapsEngine.playReadyText
	call clearObjectTable

	
	mapPage2 :miscObjects
	xor a
	ld (miscObjectTable.1.x), a
	ld (miscObjectTable.1.y), a
	ld a, miscObject.stageIntro.ready
	ld (miscObjectTable.1.frame), a
	
	ld bc, (8 << 8) | 24
	
gameplayMapsEngine.playReadyText.loop:
			push bc
			call verticalObjectsToSprites
			call prepareForVblank
			pop bc
		djnz gameplayMapsEngine.playReadyText.loop
		ld b, 8
		ld a, (miscObjectTable.1.frame)
		sub miscObject.stageIntro.ready
		neg
		ld (miscObjectTable.1.frame), a
		dec c
	jr nz, gameplayMapsEngine.playReadyText.loop
	call clearObjectTable
	
.endm

;hl: pointer to the transition
.section "gameplayMapsEngine.loadDireclty" free
gameplayMapsEngine.loadDireclty:
	call gameplayMapsEngine.processTransition
	ld hl, (hScroll)
	ld c, 0
-:		push bc
		call gameplayMapsEngine.loadLine
		ld hl, vramRaw.haveData
		dec (hl)
		inc hl ; ld hl, vramRaw.destination
		call outputRawData
		
		pop bc
		inc c
		ld a, 28
		cp c
	jr nz, -
	call gameplayMapsEngine.posAdjust32ColumnVerticalTransition
testeVdp:	
	
	mapPage2 :alphabetTiles
	decompress alphabetTiles + alphabetTiles.A, 0, 5
	decompress alphabetTiles + alphabetTiles.R, 32, 1
	ld ix, alphabetTiles + alphabetTiles.Y
	call decompressSingleTile
	
	mapPage2 :megamanMaterializeTiles
	decompress megamanMaterializeTiles, 5*32, MegamanMaterializeTilesCount

	mapPage2 :megamanBusterTiles
	decompress megamanBusterTiles, WeaponsTiles*32, 1
	xor a
	ld (selectedWeapon), a
	
	call turnOnVdp
	call PSGPlayBuffered
	
.if DEBUG == 0	
	gameplayMapsEngine.playReadyText
.endif	

	ld de, VramWrite
	ld hl, outputStatusBarTiles.megamanLife
	call outputStatusBarTiles	
	ret
	
.ends

.section "gameplayMapsEngine.preAdjust32ColumnVerticalTransition" free
gameplayMapsEngine.preAdjust32ColumnVerticalTransition:
	ld hl, vdpMisc1Value
	res BitM1HideLeftColoum, (hl)

	ld hl, (hScroll)
	jp gameplayMapsEngine.loadColumn
.ends

.section "gameplayMapsEngine.posAdjust32ColumnVerticalTransition" free
gameplayMapsEngine.posAdjust32ColumnVerticalTransition:
	ld a, (limits.orientation)
	rra
	jp nc, ++
;horizontalOrientation	
		ld hl, vdpMisc1Value
		set BitM1HideLeftColoum, (hl)
		
		ld hl, (hScroll)
		ld a, (limits.beginning) 
		cp h
		jp nz, +
			ld a, LoadColumnLeft
			ld (columnToLoad), a ;since the right column will start loaded, there is no need
								;load again when scrolling, so we put the pending column to load
								;to the left
			jp gameplayMapsEngine.loadColumnRight ; call+ret	
+:		
			ld a, LoadColumnRight
			ld (columnToLoad), a ;since the right column will start loaded, there is no need
								;load again when scrolling, so we put the pending column to load
								;to the left
			jp gameplayMapsEngine.loadColumn ; call+ret	
		
++:
;vertical or no orientarion
			ld hl, vdpMisc1Value
			res BitM1HideLeftColoum, (hl)
	ret
.ends


;hl: poiter to the palette
.section "gameplayMapsEngine.loadPalette" free
gameplayMapsEngine.loadPalette:
	push af
	ld de, palette.hasNewPalette
	ld a, 1
	ld (de), a
	inc e
gameplayMapsEngine.loadPalette.mainLoop:
		ld a, (hl)
		cp %01000000	;if the last two bits are cleared
		jr c, gameplayMapsEngine.loadPalette.loadRegularEntry
		cp PaletteEndingMark
		jr nc, gameplayMapsEngine.loadPalette.loadLastEntry
		cp PaletteAnimationMark
		jr nc, gameplayMapsEngine.loadPalette.loadAnimation
		
;new outputAddress		
		and %00111111
		add a, <palette.buffer
		ld e, a
		inc hl
	jr gameplayMapsEngine.loadPalette.mainLoop			
		
gameplayMapsEngine.loadPalette.loadAnimation:
		and %00111111
		ld c, a
		ld b, a
		ld (paletteAnimation.framesPerFrame), bc
		inc hl
		jr z, gameplayMapsEngine.loadPalette.mainLoop
		
		ld a, (hl)
		ld b, a
		and %11110000
		rra
		rra
		rra
		rra
		ld c, a		; c: number of frames
		ld a, b
		and %00001111
		ld b, a		; b:entries per frame
		ld (paletteAnimation.entriesPerFrame), a
		push de ;save the buffer address

		ld a, e
		ld de, paletteAnimation.bufferPosition
		ld (de), a
		
		ld a, <paletteAnimation.buffer
		inc e  ; paletteAnimation.startOfNextFrame
		ld (de), a
		
		inc e ; paletteAnimation.buffer
		inc hl	;next colors
gameplayMapsEngine.loadPalette.loadAnimationOuterLoop:
			push bc
gameplayMapsEngine.loadPalette.loadAnimationInnerLoop:
				ldi
				inc bc
			djnz gameplayMapsEngine.loadPalette.loadAnimationInnerLoop
			pop bc
			dec c
		jr nz , gameplayMapsEngine.loadPalette.loadAnimationOuterLoop
		
		ld a, PaletteAnimationEndMark   ; end of animation mark
		ld (de), a
		
		;remove the eventual ending mark in the last entry of animation
		dec de
		ld a, (de)	
		and %00111111
		ld (de), a
		
		;prepare the buffer to copy the last frame of animation to,
		;the last frame of palette animation will be copied as a regular palette
		ld a, (paletteAnimation.entriesPerFrame)
		ld e, a
		ld d, 0
		or a
		sbc hl, de
		
		;restore buffer
		pop de
	jr gameplayMapsEngine.loadPalette.mainLoop
		
gameplayMapsEngine.loadPalette.loadRegularEntry:		
		ldi
	jr gameplayMapsEngine.loadPalette.mainLoop

gameplayMapsEngine.loadPalette.loadLastEntry ;last entry	
	and %00111111
	ld (de), a
	inc hl
	pop af
	ret
.ends

;de: pointer to the transitions addresses
.macro gemeplayMapsEngine.clearNextTransiotionAddress
	push af
	ld b, 12
	xor a
-:		ld (de), a
		inc e
	djnz -	
	pop af
.endm


;de: pointer to the destination of the descriptor
;hl: pointer to a 3 byte transition descriptor (subroom where the transion might occur, pointer to the transiotion)
.section "gemeplayMapsEngine.loadNextTransitionAddress" free
gemeplayMapsEngine.loadNextTransitionAddress:
	push af
	
	ld a, (hl)
	inc hl
	
	ld b, a
	res 6, b
	set 7, b	;adjust most significant part of the transiotion address
	
	and %11000000
	cp %11000000
	jr z, +
		rlca		;get the two most significan bits, if they are between 0-2, than it's only one transition
		rlca		
		rlca
		
		add a, e
		ld e, a
		ldi
		inc bc ;conpesate for the ldi before
		ld a, b
		
		ld (de), a
		pop af
	ret
	
+:	;two or three transitions			
		ld c, (hl)
		inc hl
		
		ld a, (hl)
		rlca
		rlca
		and %00000011
		ld ixl, 3
-:			dec a
			jr nz, +
			inc e
			inc e
			dec ixl
		jr nz, -
+:			ex de, hl
			ld (hl), c
			inc l
			ld (hl), b
			inc l
			ex de, hl
			
			ld b, (hl)
			set 7, b
			res 6, b
			inc hl
			ld c, (hl)
			inc hl
			dec ixl
		jr nz, -
		dec hl
		dec hl
	pop af
	ret
.ends

;loads the limits of the room, the orientation of the room and initial scroll position
;hl: pointer to the limits, if they are vertical limits, than the first value will be complemented
.macro loadRoomLimits
teste8:	
	ld de, limits.orientation
	ld a, (hl)
	inc l
	ld c, a
	
	;the most significant bits on the first limit, are the indicator of the orinetation of the room
	ld b, 0
	rla
	rl b
	rla
	rl b

	ld a, b
	ld (de), a
	
	ld a, c
	or %11000000
	ld (hScroll+1), a
	ld (visualHScroll+1), a
	inc e
	ld (de), a
	inc e
	ld (de), a
	
	dec b
	ret m	;if so, than we are done 
	
	cp (hl)		;check if the scrolls are reverted
	jr c, loadRoomlimits.scrollsNotReverted		;if that, than the ending limit is first in memory, so the scenario will be loaded
		dec e
loadRoomlimits.scrollsNotReverted:
	ldi	;limits.ending <- second limit
	
.endm

;ld hl: pointer to the pointer to the map
.macro loadGameplayMap
	push af
	
	ld e, (hl)
	inc hl
	ld d, (hl)
	inc hl
	
	push hl
	
	ld a, (stage.compressedMapsBank)
	ld (MapperSlot2), a
	
	ex de, hl
	ld de, gameplayMap
	call aplibDepack
	
	ld a, (stage.bank)
	ld (MapperSlot2), a
	
	pop hl
	pop af
.endm

;returns:
;ix: tiles address in ROM
.macro loadTiles
	ld a, (hl)
	inc hl
	ld b, (hl)	;load tiles origin pointer
	ld ixl, b
	inc hl
	ld b, (hl)
	ld ixh, b
	inc hl
	
	ld b, (hl);	load tiles counter
	inc hl
	
	ld e, (hl); load destination pointer
	inc hl
	ld d, (hl)
	inc hl
	push hl
	ex de, hl
	ld (MapperSlot2), a
	call decompressBTiles
	pop hl
	ld a, (stage.bank)
	ld (MapperSlot2), a
.endm

.macro gameplayMapsEngine.checkForTransitionToHor args noTransition
	ld a, (hScroll+1)
	ld hl, limits.ending
	cp (hl)
	jp nz, gameplayMapsEngine.checkForTransitionToHor.beginning.\@ 
		xor a
		ld l, <endingTransitions.right + 1
		add a, (hl)
		jp z, noTransition
			dec l
			ld l, (hl)
			ld h, a
			jr gameplayMapsEngine.checkForTransitionToHor.end.\@
gameplayMapsEngine.checkForTransitionToHor.beginning.\@:	
	dec l ;limits.beginning
	sub (hl)
	jp nz, noTransition
		ld l, <beginningTransitions.right + 1
		add a, (hl)
		jp z, noTransition
			dec l
			ld l, (hl)
			ld h, a
gameplayMapsEngine.checkForTransitionToHor.end.\@:			
.endm

.macro gameplayMapsEngine.checkForTransitionToVer args noTransition, isTop
	ld a, (hScroll+1)
	ld hl, limits.ending
	cp (hl)
	jp nz, gameplayMapsEngine.checkForTransitionToVer.beginning.\@ 
		xor a
		ld l, <endingTransitions.bottom + isTop*2 + 1
		add a, (hl) ;doing this instead of "ld a, (hl)" will activate the flags
		jp z, noTransition
			dec l
			ld l, (hl)
			ld h, a
			jr gameplayMapsEngine.checkForTransitionToVer.end.\@
gameplayMapsEngine.checkForTransitionToVer.beginning.\@:	
	dec l ;ld l, <limits.beginning
	sub (hl)
	jr nz, noTransition
		ld l, <beginningTransitions.bottom + isTop*2 + 1
		add a, (hl)
		jp z, noTransition
			dec l
			ld l, (hl)
			ld h, a
gameplayMapsEngine.checkForTransitionToVer.end.\@:			
.endm

.macro gameplayMapsEngine.getSpeed
	ld a, b

	ld bc, \1 * 1 ; MegamanWalkingSpeed
	bit BitBKey, a
	jr z, gameplayMapsEngine.getSpeed.testC.\@
		sla c
		rl b
gameplayMapsEngine.getSpeed.testC.\@:
	bit BitCKey, a
	jr z, gameplayMapsEngine.getSpeed.end.\@
		sla c
		rl b
gameplayMapsEngine.getSpeed.end.\@:

	/*.if \1 == -1
		ld h, b
		ld l, c
		or a
		sbc hl, bc
		or a
		sbc hl, bc
		ld b, h
		ld c, l
	
	.endif
*/
.endm 


.section "gameplayMapsEngine.navigate" free
gameplayMapsEngine.navigate:
	call clearSpriteTable
	call turnOnVdp
	call prepareForVblank
-:		
		ld a, (pressedKeys)
		bit BitStartKey, a
		jr z, +
			jp PSGStop	;call + ret
+:	
		ld a, (limits.orientation)
		rra 
		jr c, horizontalOrientationGameplay
		;rra
		;jr c, verticalOrientationGameplay
verticalOrientationGameplay:
			ld a, (pressedKeys)
			and UKey | DKey | RKey
			jp z, +++
			and UKey | DKey
			jr z, ++
			and UKey
			jr z, +
			;UKey
			teste22:
				call gameplayMapsEngine.scrollUp
			jp +++	
+:			;DKey
				call gameplayMapsEngine.scrollDown
			jp +++	
++:			;RKey
				gameplayMapsEngine.checkForTransitionToHor +++
				call gameplayMapsEngine.loadScrollingRight
			jp +++

horizontalOrientationGameplay:
		ld a, (holdedKeys)
		ld b, a
		and RKey | LKey
		jr z, horizontalOrientationCheckTransition
		and RKey
		jr z, +
			gameplayMapsEngine.getSpeed 1
			call gameplayMapsEngine.horizontalScrollRight
			jp horizontalOrientationCheckTransition
+:		;Lkey
			gameplayMapsEngine.getSpeed -1
			call gameplayMapsEngine.horizontalScrollLeft
horizontalOrientationCheckTransition:
			ld a, (pressedKeys)
			and UKey | DKey | RKey
			jp z, +++
			and UKey | DKey
			jr z, ++
			and UKey
			jr z, +
			;UKey
			teste20:
				gameplayMapsEngine.checkForTransitionToVer +++, 1
				call gameplayMapsEngine.loadScrollingUp
			jr +++	
+:			;DKey
teste21:
				gameplayMapsEngine.checkForTransitionToVer +++, 0
				call gameplayMapsEngine.loadScrollingDown
			jr +++	
++:			;RKey
				gameplayMapsEngine.checkForTransitionToHor +++
				call gameplayMapsEngine.loadScrollingRight				
+++:		
		call prepareForVblank
	jp -
.ends


;process a transition to a new area in a stage
;hl:  address to the transition attributes
;returns
;mapperPage1: page of the tiles
;all maps related stuff loaded in theirs respective addresses.
.section "gameplayMapsEngine.processTransition" free
gameplayMapsEngine.processTransition:
	ld a, (stage.bank)
	ld (MapperSlot2), a
	ld a, (hl)  ;loading transiction flags 
				
	rla
	jr nc, +; indicates if this loaded room is a checkpoint
		ld (checkpoint.transition), hl
		inc hl
		ld b, a
		ld a, (hl)
		ld (checkpoint.megamanStartPosition), a
		ld a, b
+:	inc hl
	
	rla
	jr nc, +;indicates if is necessary to load a new palette
		call gameplayMapsEngine.loadPalette
		
+:	ld de, beginningTransitions.bottom
	push de
	gemeplayMapsEngine.clearNextTransiotionAddress
	pop de

	rla
	jr nc, +;indicates if there is a top transition for this room
		call gemeplayMapsEngine.loadNextTransitionAddress
+:	
	ld e, <endingTransitions.bottom
	rla
	jr nc, +;indicates if there is a bottom transition for this room
		call gemeplayMapsEngine.loadNextTransitionAddress

+:	rla
	jr nc, +;indicates if there is a new gameplayMap to load into memory
		loadGameplayMap

+:	rla
	jr nc, +; indicates if is necesary to load new tiles
		loadTiles
+:	
loadRoomLimits:	
	loadRoomLimits

	ret
.ends

;a: transitionCheck
;output
;a = 0; death, not 0, transition done
.section "gameplayMapsEngine.checkTransitions" free
gameplayMapsEngine.checkTransitions:
	rra	;check for bottomTransition
	jp nc, ++
		xor a
		ld (transitionCheck), a
		ld a, (limits.orientation)
		rra ; check if there is a transition or is just a regular scroll down
		jr c, +
		call gameplayMapsEngine.scrollDown
		ld a, 1
	ret	
+	
		gameplayMapsEngine.checkForTransitionToVer +++, 0
		call gameplayMapsEngine.loadScrollingDown
		ld a, 1
	ret
	
++:
	rra ;check for right transition
	jp nc, ++
		xor a
		ld (transitionCheck), a
		
		gameplayMapsEngine.checkForTransitionToHor ++
		call gameplayMapsEngine.loadScrollingRight
		ld a, 1
	ret

++:
		xor a
		ld (transitionCheck), a
		ld a, (limits.orientation)
		rra
		jr c, +
		call gameplayMapsEngine.scrollUp
		ld a, 1
	ret	
+:		
		gameplayMapsEngine.checkForTransitionToVer +++, 1
		call gameplayMapsEngine.loadScrollingUp
		ld a, 1
	ret

+++:
		xor a
	ret

.ends


; loads stuff related to a entire stage:
;	scenario palettes, gameplayMap tiles
;	and first room transition
; hl:	pointer to the structure
.section "gameplayMapsEngine.loadStage" free
gameplayMapsEngine.loadStage:
	call turnOffVdp
	
	ld a, :megamanPalette
	ld hl, megamanPalette
	ld (MapperSlot2), a
	call gameplayMapsEngine.loadPalette
	
	ld a, (stage.bank)
	ld (MapperSlot2), a
	ld hl, (stage.loader)
	
	ld a, (hl)	;load BankTilesNumber
	inc hl
	ld c, (hl)	;load TileCounter
	inc hl
	ld b, 0
	
	ld e, (hl)	;load TilesPointer
	inc hl
	ld d, (hl)
	inc hl
	push hl
	ld ixl, e
	ld ixh, d

	ld hl, ($3700 | VramWrite) >> 5	;calculate destination addr on Vram
	or a ; clear carry flag
	sbc hl, bc
	.rept 5
		add hl, hl
	.endr
	ld (MapperSlot2), a
	
	ld b, c
	call decompressBTiles		;decompress Scenario Tiles
	pop hl

	ld a, (stage.bank)
	ld (MapperSlot2), a
	
	ld a, (hl)
	inc hl
	ld (PSGMusicBank), a
	ld e, (hl)
	inc hl
	ld d, (hl)
	inc hl
	ld (PSGMusicStart), de	
	
teste9:	
	ld a, (hl)	;load tilemapBankNumber
	inc hl
	
	ld e, (hl)	;load tilemapNumber
	inc hl
	ld d, (hl)
	inc hl
	push hl
	ex de, hl
	
	
	ld (MapperSlot2), a
	ld c, (hl)	;load tilemap offset
	inc hl
	ld b, (hl)
	inc hl
	push bc
	ld de, metaTilesTemp
	push de
	call aplibDepack
	
	pop hl	;pop metaTiles
	pop de	;pop offset
	ld bc, 4
gameplayMapsEngine.loadStage.incrementTiles:	
			ld a, (hl)
			add a, e
			ld (hl), a
			inc hl
			ld a, (hl)
			adc a, d
			ld (hl), a
			inc hl
			inc de
		djnz gameplayMapsEngine.loadStage.incrementTiles
		dec c
	jr nz, gameplayMapsEngine.loadStage.incrementTiles	

	ld hl, metaTilesTemp
	ld e, 3
	ld bc, 2024
-:	
		ld a, c
		and $07
		jr nz, +
			ld d, >metaTiles - 1
			dec e
			dec e
			dec e
+:		
		cp $04	
		jr nz, +
			ld a, e
			sub 4
			ld e, a
+:	
		inc d
		ldi
		;dec de
	jp pe, -
	
	
	pop hl
	ld a, (stage.bank)
	ld (MapperSlot2), a
	
	;collision table
	ld de, collisionPropertiesTable
	call aplibDepack
	
	ld a, (hl)
	ld (stage.compressedMapsBank), a
	inc hl

	call gameplayMapsEngine.loadDireclty
	jp turnOnVdp
	
.ends


.endif