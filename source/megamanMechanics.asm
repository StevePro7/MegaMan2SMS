

;these speeds are decremented by $100 for test pourposes
.define MegamanSlidingSpeed $0080
.define MegamanStartRunningSpeed $0020
.define MegamanRunningSpeed $0160
.define MegamanLandingSpeed $0000
.define MegamanSteadSpeed $0000
.define MegamanOnAirSpeed $0150
.define MegamanJumpStartSpeed $FB21
.define MegamanStartFallingSpeed $ff00

;these are not
.define MegamanLadderSpeed $00c0
.define MegamanLadderGrabbingSpeed $0c00
.define MovingLeftTileSpeed $ff00
.define MovingRightTileSpeed $0100

;cannot fall faster than this
.define MegamanYSpeedFallingLimit $0b

.define MegamanSlidingFrameTimer 8
.define MegamanLandingFrameTimer 2
.define MegamanStartRunningFrameTimer 5
.define MegamanLadderTimer 7
.define RegularGravity $40

.define MegamanYCollisionOffset $0c

.define PlatformMovement 2
.define SlipperyMovement 2

;\1: speed
.macro loadDePosSpeed
	ld de, 0 - 256 + \1  
.endm
;\1: speed
.macro loadDeNegSpeed
	ld de, 0 - 256 + ($ffff & (-\1)) 
.endm
;\1: speed
.macro loadHlSpeed
	ld hl, 0 - 256 + \1 
.endm


.section "megamanMechanics.bringDown" free
megamanMechanics.bringDown:
	ld hl, <objectAttr.megamanDroppingDown | ($7f<<8)
	ld (objectTable.2.2.id), hl ; also sets frameTimer
	
	ld hl, ObjectActiveFlag
	ld (objectTable.1.2.flags), hl	;also sets frame
	
	ld hl, $1400
	ld (objectTable.1.2.y), hl
	
	ld hl, $8000
	ld (objectTable.1.2.x), hl
	ld (objectTable.1.1.x), hl
	
	ld h, l
	ld (platformSpeed), hl
	
	ld a, (hScroll+1)
	ld (objectTable.1.2.x.higher), a
	ld (objectTable.1.1.x.higher), a
	
	ld hl, objectTable.1.2.y + 1
	
-:		ld a, $10
		add a, (hl)
		ld (hl), a
		ld a, (checkpoint.megamanStartPosition)
		cp (hl)
		jr z, +
		
		push hl
		call gameplayObjectsToSprites
		call prepareForVblank
		pop hl
	jr -
+:		
	ld (objectTable.1.1.y + 1), a
	
	ld hl, teleportInSfx
	call PSGSFXPlay
	
	ld a, 2
	ld (objectTable.2.2.frameTimer), a

-:
		ld a, (objectTable.1.2.frame)
		cp 2
		jr z, +
		
		call gameplayObjectsToSprites
		call prepareForVblank
	jr -
+:	
	ld hl, megamanMechanics.stead
	ld (megamanCurrentMechanic), hl	

	ld a, 0
	ld (objectTable.1.2.flags), a
	
	ld hl, <objectAttr.megamanStead
	ld (objectTable.2.1.id), hl ; also sets frameTimer
	
	ld hl, ObjectActiveFlag
	ld (objectTable.1.1.flags), hl	;also sets frame
	
	ld hl, (gravity)
	ld (objectTable.2.1.ySpeed), hl 
	
	;detect if we are in water, so set something witch I dont know what does.
	ret
.ends


.section "megamanMechanics.startRunning" free
megamanMechanics.startRunningLeft:
	call megamanMechanics.preambleOnGround
	loadDeNegSpeed MegamanStartRunningSpeed
	ld a, (holdedKeys)
	ld c, a
	bit BitLKey, a 
	jr z, +	
		ld a, (objectTable.2.1.frameTimer)
		or a
		jp nz, megamanMechanics.conclusionOnGround	;call + ret
			ld hl, megamanMechanics.runningLeft
			ld (megamanCurrentMechanic), hl
			
			ld a, <objectAttr.megamanRunning
			ld (objectTable.2.1.id), a ; no need to set frame timer since is already zero
			
			;xor a 
			;ld (objectTable.1.1.frame), a ; no need to set frame since is already zero
		jp megamanMechanics.conclusionOnGround
+:		
	and RKey
	jp z, megamanMechanics.stopStartRunning; call+ret

		ld a, ObjectActiveFlag
		ld hl, megamanMechanics.startRunningRight
		loadDePosSpeed MegamanStartRunningSpeed
		ld (objectTable.1.1.flags), a
		ld (megamanCurrentMechanic), hl
	jp megamanMechanics.conclusionOnGround

megamanMechanics.startRunningRight:
	call megamanMechanics.preambleOnGround
	loadDePosSpeed MegamanStartRunningSpeed
	ld a, (holdedKeys)
	bit BitRKey, a 
	jr z, +
		ld a, (objectTable.2.1.frameTimer)
		or a
		jp nz, megamanMechanics.conclusionOnGround	;call + ret
			ld hl, megamanMechanics.runningRight
			ld (megamanCurrentMechanic), hl
			
			ld a, <objectAttr.megamanRunning
			ld (objectTable.2.1.id), a ; no need to set frameTimer since is already zero
			
			;xor a 
			;ld (objectTable.1.1.frame), a ; no need to set frame since is already zero
			
		jp megamanMechanics.conclusionOnGround  ;call + ret
+:	
	and LKey
	jr nz, + ; call + ret

megamanMechanics.stopStartRunning:
		ld hl, megamanMechanics.stead
		ld (megamanCurrentMechanic), hl
		
		ld a, <objectAttr.megamanStead
		ld (objectTable.2.1.id), a ; no need to set frameTimer since is already zero
		
		;ld (objectTable.1.1.frame), a ; no need to set frame since is already zero
		
	jp megamanMechanics.conclusionOnGround ;call+ret		
		
+:		
		ld a, ObjectActiveFlag | ObjectMirrorFlag
		ld hl, megamanMechanics.startRunningLeft
		loadDePosSpeed MegamanStartRunningSpeed
		ld (objectTable.1.1.flags), a
		ld (megamanCurrentMechanic), hl
	jp megamanMechanics.conclusionOnGround ;call+ret

.ends		
	
.section "megamanMechanics.running"	free
megamanMechanics.runningLeft:
	call megamanMechanics.preambleOnGround
	loadDeNegSpeed MegamanRunningSpeed
	ld a, (holdedKeys)
	bit BitLKey, a  
	jp nz, megamanMechanics.conclusionOnGround ;expected behavior, call+ret
	
	and RKey
	jr nz, +
		ld hl, megamanMechanics.slidingLeft
		jp megamanMechanics.startSliding
+:	
		loadDePosSpeed MegamanRunningSpeed
		ld a, ObjectActiveFlag
		ld (objectTable.1.1.flags), a
		ld hl, megamanMechanics.runningRight
		ld (megamanCurrentMechanic), hl
	jp megamanMechanics.conclusionOnGround ;call+ret
				

megamanMechanics.runningRight:
	call megamanMechanics.preambleOnGround
	loadDePosSpeed MegamanRunningSpeed
	ld a, (holdedKeys)
	bit BitRKey, a
	jp nz, megamanMechanics.conclusionOnGround ;expected behavior, call+ret
	and LKey
	jr nz, +
		ld hl, megamanMechanics.slidingRight
megamanMechanics.startSliding:		
		ld (megamanCurrentMechanic), hl
	
		ld hl, <objectAttr.megamanSliding
		ld (objectTable.2.1.id), hl ; also sets frameTimer
		
		ld (objectTable.1.1.frame), a ; a already has zero
	jp megamanMechanics.conclusionOnGround ;call+ret
+:	
		loadDeNegSpeed MegamanRunningSpeed
		ld a, ObjectActiveFlag | ObjectMirrorFlag
		ld (objectTable.1.1.flags), a
		ld hl, megamanMechanics.runningLeft
		ld (megamanCurrentMechanic), hl
	jp megamanMechanics.conclusionOnGround ;call+ret
.ends	

.section "megamanMechanics.onLadder" free
megamanMechanics.onLadder:
	ld a, (holdedKeys)
	bit BitBKey, a
	jp z, +++
		bit BitRKey, a
		jr z, +
			ld hl, objectTable.1.1.flags
			res BitObjectMirrorFlag, (hl)
			jp ++
+:		bit BitLKey, a
		jr z, ++
			ld hl, objectTable.1.1.flags
			set BitObjectMirrorFlag, (hl)
++:	
		call weapons.megamanShot
		ld a, (megamanFireingPose)
+++:		
	ld a, (megamanFireingPose)
	add a, a
	jr z, megamanMechanics.onLadder.notFireing
		rra
		dec a
		ld (megamanFireingPose), a
		
		ld a, (holdedKeys)
		and CKey
		jr nz, megamanMechanics.onLadder.leave
	jp megamanMechanics.onLadder.stead
		
megamanMechanics.onLadder.notFireing:		
	ld a, (holdedKeys)
	rra; bit BitUKey, a
	jp c, megamanMechanics.onLadder.ascending	
	rra; bit BitDKey, a
	jr c, megamanMechanics.onLadder.descending	
	and CKey >> 2
	jr nz, megamanMechanics.onLadder.leave

megamanMechanics.onLadder.stead:
	ld a, MegamanLadderTimer
	ld (objectTable.2.1.frameTimer), a
	ret
	
megamanMechanics.onLadder.leave:
	ld hl, (gravity)
	ld (objectTable.2.1.ySpeed), hl
	
	xor a
	ld hl, objectTable.2.1.id
	ld (hl), <objectAttr.megamanOnAir
	inc l; objectTable.2.1.frameTimer
;	ld (hl), a no need to set frame timer since megaman on Air only have one frame
	dec h; objectTable.1.1.frame
	ld (hl), a
	
	ld hl, megamanMechanics.onAir
	ld (megamanCurrentMechanic), hl
	ret

megamanMechanics.onLadder.descending:	
	ld hl, (objectTable.1.1.y)
	ld de, MegamanLadderSpeed
	add hl, de
	ld (objectTable.1.1.y), hl

	ld a, h
	add a, 12; this is done for two reasons, first, is that we can use just one compare
			 ; to check for transition (original transition strip [e8-f4), now [f4 - ff])
			 ;and also will potitioning the y coordinate on the right tile for ladder checking
	cp $f4
	jr nc, megamanMechanics.onLadder.bottomTransition	 

	ld c, a
	
	ld hl, (objectTable.1.1.x+1)
	ld a, l
	and $f0
	ld l, a
	ld a, c; objectTable.1.1.y+1
	rrca
	rrca
	rrca
	rrca
	and $0f 
	or l
	ld l, a
	
	ld d, >collisionPropertiesTable
	ld e, (hl)
	ld a, (de)
	cp TileLadder
	ret z	;if the bottom tile is a ladder, than we just keep in the ladder

	add a, a	;cp SolidTile
	jr c, ++
		;if the tile is a background, then we should check if the top tile is a ladder	
		ld a, c
		and $0f
		
		cp 8	;if the fine postion is between 4 and 12( the value is corrected now to 0 - 8), than we should rollback
				;the l register twice(one for returning to the original tile position, other to the tile above).
		jp nc, +
			dec l 
+:		dec l

		ld e, (hl)
		ld a, (de)
		cp TileLadder
		jp nz, megamanMechanics.onLadder.leave;	the top tile will be a ladder or a background, if is a ladder, we are still on it.
		ret	
++:	
	;if 'a' is equals one, than we reached the end of the latter, so, is time to became stead
	ld e, 4	;just a small correction to the stead y's position, because it will be diferent, depending
			;if we will come from above or below
megamanMechanics.onLadder.leaveOnGround:		
		ld b, 0
		ld hl, objectTable.1.1.frame
		ld (hl), b
		inc l; objectTable.1.1.y
		ld (hl), b
		inc l; objectTable.1.1.y+1
		ld a, (hl)
		and $f0
		add a, e
		ld (hl), a
		inc h; objectTable.2.1.ySpeed+1
		ld (hl), $ff
		dec l; objectTable.2.1.ySpeed
		ld a, (gravity)
		ld (hl), a
		dec l
		dec l	;objectTable.2.1.id
		ld (hl), <objectAttr.megamanStead
		
		ld hl, megamanMechanics.stead
		ld (megamanCurrentMechanic), hl
	ret	

megamanMechanics.onLadder.topTransition:
		ld a, TopTransitionPending
	jr +	;if we are here, than it's not cpu intensive anymore, so there is no need for replicated code.
megamanMechanics.onLadder.bottomTransition:
		ld a, BottomTransitionPending
+:
		ld (transitionCheck), a		
	ret
	
megamanMechanics.onLadder.ascending:
	ld hl, (objectTable.1.1.y)
	ld de, -MegamanLadderSpeed
	add hl, de
	ld (objectTable.1.1.y), hl
	
	ld a, h
	cp 4
	jr c, megamanMechanics.onLadder.topTransition	
	
	sub 4	;puts the y coordinate in the right position for the lower tile to be checked.
	ld c, a
	
	ld hl, (objectTable.1.1.x+1)
	ld a, l
	and $f0
	ld l, a
	ld a, c; objectTable.1.1.y+1
	rrca
	rrca
	rrca
	rrca
	and $0f 
	or l
	ld l, a
	
	ld a, c	;now get the least signifcant nibble of the position and use to check the displacment of the metatiles
	and $0f
	ld b, l;get the lower tile position
	
	ld d, >collisionPropertiesTable
	cp 8
	jp nc, +
		dec b	;this is the lower tile, and the one we will evaluate first
+:	
	
	ld e, (hl)
	ld a, (de)
	cp TileLadder
	ret z	;if the bottom tile is a ladder, than we just keep in the ladder
	
	ld l, b	;	get the top tile

	ld e, (hl)
	ld a, (de)
	cp TileLadder
	ret z	;if the bottom tile is a ladder, than we just keep in the ladder
	
	ld e, -12
	jp megamanMechanics.onLadder.leaveOnGround
	
	
.ends
	
.section "megamanMechanics.preamble" free
megamanMechanics.preambleOnAir:
	ld a, (megamanFireingPose)
	add a, a
	jp z, +
		rra
		dec a
		ld (megamanFireingPose), a 
+:
	ld a, (holdedKeys)
	bit BitBKey, a 
	jr z, +
		call weapons.megamanShot
		ld a, (holdedKeys)
+:
	and UKey | DKey
	ret z
	
	and UKey
	jr z, megamanMechanics.decendingLadderOnAir
megamanMechanics.clibbingLadderOnAir:	
		ld de, -MegamanLadderSpeed
		exx
		ld hl, (objectTable.1.1.x+1)
		ld a, l
		ld c, l	; save for later, if we are on the ladder, this will be useful
		and $f0
		ld l, a
		ld a, (objectTable.1.1.y+1)
		cp $8a
		jp nz, +
			inc a
			dec a
+:		
		add a, -4;	add displacment for the tile to check
		ld b, a
		and $0f
		cp 8	;if the least significant nibble of Y is now larger than 8, than the tile above megaman and the one
				;imediatly below will be one in the same, so we can continue on the general comparison, as 
		ld a, b
		jp nc, megamanMechanics.grabOnLadder2

		rrca
		rrca
		rrca
		rrca
		and $0f 
		or l
		ld l, a
		ld e, (hl)
		ld d, >collisionPropertiesTable
		ld a, (de)
		cp TileLadder
		jp z, megamanMechanics.grabOnLadder3	; if the tile directly below is a ladder, there is no need to check the above

		dec l
		ld e, (hl)
		ld a, (de)
		cp TileLadder
		ret nz	;both tiles are not ladders
		
		exx
			ld a, (objectTable.1.1.y+1)
			and $f0	;new position after grabbed on ladder
			sub $0c;
			ld (objectTable.1.1.y+1), a
		jp megamanMechanics.grabOnLadder4	;just continue on the 
		
megamanMechanics.decendingLadderOnAir:
		ld de, MegamanLadderSpeed 	
		exx
		ld b, -MegamanYCollisionOffset
		jp megamanMechanics.grabOnLadder

megamanMechanics.preambleOnGround:
	ld a, (holdedKeys)
	bit BitBKey, a
	jr z, +
		call weapons.megamanShot
		ld a, (holdedKeys)
+:
	and UKey | DKey
	ret z
	
	and UKey
	jr z, megamanMechanics.decendingLadderOnGround	

megamanMechanics.clibbingLadderOnGround:	
		ld de, -MegamanLadderSpeed 	
		exx
		ld b, -MegamanYCollisionOffset
		jp megamanMechanics.grabOnLadder

megamanMechanics.decendingLadderOnGround:
		ld de, MegamanLadderGrabbingSpeed
		exx
		ld b, MegamanYCollisionOffset; megaman displacment Tile 
	
megamanMechanics.grabOnLadder:
	ld hl, (objectTable.1.1.x+1)
	ld a, l
	ld c, l	; save for later, if we are on the ladder, this will be useful
	and $f0
	ld l, a
	ld a, (objectTable.1.1.y+1)
	add a, b;	add displacment for the tile to check
megamanMechanics.grabOnLadder2:	
	rrca
	rrca
	rrca
	rrca
	and $0f 
	or l
	ld l, a
	ld e, (hl)
	ld d, >collisionPropertiesTable
	ld a, (de)
	cp TileLadder
	ret nz
megamanMechanics.grabOnLadder3:	
	exx
		ld hl, (objectTable.1.1.y)
		add hl, de	;new position after grabbed on ladder
		ld (objectTable.1.1.y), hl
	
megamanMechanics.grabOnLadder4:	
		ld hl, megamanMechanics.onLadder
		ld (megamanCurrentMechanic), hl

		ld hl, <objectAttr.megamanOnLadder
		ld (objectTable.2.1.id), hl ; also sets frameTimer
		
		;ld hl, objectTable.1.1.frame
		;ld (hl), 0
		;maybe not a good idea
		xor a
		ld (objectTable.1.1.frame), a
	exx
	
	pop de	; just skip this return address, if we grabbed on a ladder, than we should not process the previos mechanic
	
	ld a, (limits.orientation)
	dec a
	jp nz, ++	;if the orientation is not horizontal we correct only megamans position

		ld a, c
		and $F8 ; mask off the three least significant bits, since megaman in ladder
		bit 3, c
		
		jr nz, +
			or $08
			ld (objectTable.1.1.x+1), a
			jp gameplayMapsEngine.horizontalScrollRight ;call+ ret
+:		
			ld (objectTable.1.1.x+1), a
			jp gameplayMapsEngine.horizontalScrollLeft ;call+ ret
++:
		ld a, c
		and $F8 ; mask of the three least significant bits, since megaman in ladder
		or $08
		ld (objectTable.1.1.x+1), a
	ret
	
.ends

.section "megamanMechanics.sliding and landing" free
megamanMechanics.slidingRight:
	call megamanMechanics.preambleOnGround
	loadDePosSpeed MegamanSlidingSpeed
	jp +
megamanMechanics.slidingLeft:
	call megamanMechanics.preambleOnGround
	loadDeNegSpeed MegamanSlidingSpeed
	jp +
megamanMechanics.landing:
	call megamanMechanics.preambleOnGround
	loadDeNegSpeed 0
+:
	ld a, (holdedKeys)
	and LKey | RKey
	jp z, megamanMechanics.testStopLanding

	ld hl, <objectAttr.megamanStartRunning 
	ld (objectTable.2.1.id), hl ; also sets frameTimer
	
	and LKey
	jr nz, +
		ld a, ObjectActiveFlag 
		ld (objectTable.1.1.flags), a

		ld hl, megamanMechanics.startRunningRight
		ld (megamanCurrentMechanic), hl	

	jp megamanMechanics.conclusionOnGround	;call+ret			
+:	
		ld a, ObjectActiveFlag | ObjectMirrorFlag
		ld (objectTable.1.1.flags), a

		ld hl, megamanMechanics.startRunningLeft
		ld (megamanCurrentMechanic), hl	
		
	jp megamanMechanics.conclusionOnGround	;call+ret			

megamanMechanics.testStopLanding:	
megamanMechanics.testStopSliding:		
		ld a, (objectTable.2.1.frameTimer)
		or a
		jp nz, megamanMechanics.conclusionOnGround
			ld hl, megamanMechanics.stead
			ld (megamanCurrentMechanic), hl
			
			ld a, <objectAttr.megamanStead
			ld (objectTable.2.1.id), a ; no need to set frameTimer since is already zero
			
			;ld (objectTable.1.1.frame), a ; a already has zero	
		jp megamanMechanics.conclusionOnGround	
.ends

.section "megamanMechanics.onAir" free
megamanMechanics.onAir:
	call megamanMechanics.preambleOnAir
	ld a, (holdedKeys)
	bit BitRKey, a
	jp z, megamanMechanics.onAirEvalLKey
		ld a, ObjectActiveFlag 
		ld (objectTable.1.1.flags), a
		
		loadDePosSpeed MegamanOnAirSpeed
		
		ld a, (slipOnAirSpeedLeft)
		or a		
		jp z, +
			ld e, a
			ld d, $fe
			xor a
			ld (slipOnAirSpeedLeft), a
+:
		ld (slipOnAirSpeedRight), a;prevent the really rare situation were we change directions on the beggining of the jump
									;and continue sliping after
++:		call megamanMechanics.moveHorizontalOnAir
megamanMechanics.onAirVerticalMove:
		
		ld hl, objectTable.2.1.ySpeed + 1
		ld e, (hl)
		inc e
		jp m, megamanMechanics.onAirUpMove
;megamanMechanics.onAirDownMove
			call megamanMechanics.moveDown
			jr z, megamanMechanics.onAirDownMoveIncSpeed
				;we are landing here, it's jus a matter now to decide if we will run as soon as we touch the ground
				ld hl, stepSfx
				call PSGSFXPlay
				ld a, (holdedKeysPrevious)
				bit BitRKey, a
				jr z, +
					ld hl, megamanMechanics.runningRight
					ld (megamanCurrentMechanic), hl
					ld hl, <objectAttr.megamanRunning
					xor a	;load frame
					jp ++
+:				and LKey
				jr z, +
					ld hl, megamanMechanics.runningLeft
					ld (megamanCurrentMechanic), hl
					ld hl, <objectAttr.megamanRunning
					xor a	;load frame
					jp ++
+:				;vertical landing
					ld hl, megamanMechanics.landing
					ld (megamanCurrentMechanic), hl
					ld hl, <objectAttr.megamanLanding
					xor a 	;load frame
++:
				ld (objectTable.2.1.id), hl ; also sets frameTimer
			;	ld (objectTable.1.1.frame), a ; a already has zero		maybe not a good idea, its already zero			
				ld hl, (gravity)	;on land vertical speed
				ld (objectTable.2.1.ySpeed), hl
				ret
megamanMechanics.onAirDownMoveIncSpeed:
			ld hl, objectTable.2.1.ySpeed
			ld a, (gravity)
			add a, (hl)
			ld (hl), a
			
			inc l
			ld a, 0 ; keep the carry flag intact
			adc a, (hl)	
			ld (hl), a
			sub MegamanYSpeedFallingLimit
			ret nz		
			
			dec l
			ld (hl), a
			ret
				
				
megamanMechanics.onAirUpMove:
			call megamanMechanics.moveUp
			jr nz, megamanMechanics.onAirUpMoveSeilColiding
			ld a, (holdedKeys)	
			and CKey
			jr z, megamanMechanics.onAirUpMoveCutRising
				ld hl, objectTable.2.1.ySpeed
				ld a, (gravity)
				add a, (hl)
				ld (hl), a
				ret nc
					inc l
					inc (hl)
			ret
			
megamanMechanics.onAirUpMoveSeilColiding:
			ld hl, (gravity)
			ld (objectTable.2.1.ySpeed), hl
			ret
			
megamanMechanics.onAirUpMoveCutRising:
+:			; here we must to test, if the speed fter the
			;calculations is $FD01 or more or positive
			;than it should be setted to $fe00
			ld hl, objectTable.2.1.ySpeed
			ld a, (gravity)
			dec a
			add a, (hl)
			jr nc, ++
				inc a
				ld (hl), a
				inc l
				ld a, (hl)
				cp $FC	;(hl) will be incremented,
						;this is why $FC and not FD
				jp p, +
				
					ld (hl), $fe
					dec l
					ld (hl), 0
					ret
+:				
				inc a
				ld (hl), a
			ret	
++:			
			inc a
			ld (hl), a
			ret nz
			inc l
			inc (hl)
			ret
			
megamanMechanics.onAirEvalLKey:
	and LKey
	jr z, +++
		ld a, ObjectActiveFlag | ObjectMirrorFlag
		loadDeNegSpeed MegamanOnAirSpeed
		ld (objectTable.1.1.flags), a
	
		ld a, (slipOnAirSpeedRight)
		or a		
		jp z, +
			ld d, $ff
			ld e, a
			xor a
			ld (slipOnAirSpeedRight), a
			ld (slipOnAirSpeedLeft), a	
			call megamanMechanics.moveHorizontalOnAir
			jp megamanMechanics.onAirVerticalMove
			
+:		ld (slipOnAirSpeedLeft), a	;prevent the really rare situation were we change directions on the beggining of the jump
									;and continue spiping after
		loadDeNegSpeed MegamanOnAirSpeed
		call megamanMechanics.moveHorizontalOnAir
		jp megamanMechanics.onAirVerticalMove
+++:	
		;xor a
		ld (slipOnAirSpeedRight), a
		ld (slipOnAirSpeedLeft), a
		jp megamanMechanics.onAirVerticalMove
.ends


;\1: 1 if we are going down, 0 if goig up
;\2: least signifcant nibble of Ys coordinate, in case of collision
;a: least significant byte of the Ys position
.macro megamanMechanics.moveVertCollisionTest
		ld d, a	; save the position for later
		
		.if \1 == 1		
			add a, MegamanYCollisionOffset
		.else
			sub MegamanYCollisionOffset
		.endif	
		
		exx
		and $f0
		rrca
		rrca
		rrca
		rrca
		ld C, a
		ld HL, (objectTable.1.1.x+1)
		ld E, L	;save for the x position for the fine scroll
		ld a, L
		and $f0
		add a, C	;calculate the metatile where megaman is over
		ld L, a; hl now contais the metatile position of megaman
		
		ld a, E
		and $0f	;get the least signifcant bits of the Xs position (fine Xs position)
		ld D,>collisionPropertiesTable
		
		ld BC, 16
		
		cp 7
		jr nc, megamanMechanics.moveVertCollision.n7.\@
			;if the fine Ys is less than 7, we will look in the metatile
			; on the same column as megaman and the one on the right
			or a
			sbc HL, BC
		jp megamanMechanics.moveVertCollision.n6.\@

megamanMechanics.moveVertCollision.n7.\@:
		cp 9
		jr c, megamanMechanics.moveVertCollision.n4.\@
			;just look into one metatile, the one on the same column as megaman
			;if the fine Ys is less than 7, we will look in the metatile
			; on the same column as megaman and the one on the left
megamanMechanics.moveVertCollision.n6.\@:
		ld E, (HL)
		ld a, (DE)
		add a, a	;cp SolidTile. Take care later to adjust the next comparers
		jp c, megamanMechanics.moveVertCollisionDetected.\@
	
		.if 1 == \1  ;if we are goind down, a ladder tile might be consider a colision	
			add a, a;	if we are goind down, this will be the ladder tile
			jr nc, megamanMechanics.moveVertCollision.n5.\@
				dec L
				ld E, (HL)	
				ld a, (DE)
				inc L
				or a	; check if the tile on top of the ladder is a background one, 
						;only if it is, we consider the ladder a collision
				jp z, megamanMechanics.moveVertCollisionDetected.1.\@
		.endif
			
megamanMechanics.moveVertCollision.n5.\@:		
		add HL, BC

megamanMechanics.moveVertCollision.n4.\@:		
		ld E, (HL)
		ld a, (DE)
		add a, a	;cp SolidTile. Take care later to adjust the next comparers
		jp c, megamanMechanics.moveVertCollisionDetected.\@

		.if 1 == \1 ;if we are goind down, a ladder tile might be consider a colision			
			add a, a;	if we are goind down, this will be the ladder tile
			jr nc, megamanMechanics.moveVertCollision.n3.\@
				dec L
				ld E, (HL)
				ld a, (DE)
				or a	; check if the tile on top of the ladder is a background one, 
						;only if it is, we consider the ladder a collision
				jp z, megamanMechanics.moveVertCollisionDetected.1.\@
		.endif		
megamanMechanics.moveVertCollision.n3.\@:			
		xor a
		ld H, a
		ld L, a
		ld (moveableUnderTileType), a
		ld (platformSpeed), HL
		
		exx
		ld (hl), d
	ret	
megamanMechanics.moveVertCollisionDetected.\@:
.if 1 == \1 ;if we are goind down, a ladder tile might be consider a colision			
		jr nz, megamanMechanics.moveVertCollision.n2.\@
.endif	
megamanMechanics.moveVertCollisionDetected.1.\@:	
		ld H, a
		ld L, a
		ld (platformSpeed), HL
megamanMechanics.moveVertCollisionDetectedFinalizer.\@:
		ld (moveableUnderTileType), a
		exx
		ld a, d
		and $f0
		add a, \2
		ld (hl), a
		dec l
		ld (hl), 0
	ret
	
megamanMechanics.moveVertCollision.n2.\@:		
.if 1 == \1
		add a, a ;cp MovingLeftTile
		jr nc, megamanMechanics.moveVertCollision.n1.\@
			ld HL, MovingLeftTileSpeed
			ld (platformSpeed), HL
			ld a, PlatformMovement
			jp megamanMechanics.moveVertCollisionDetectedFinalizer.\@
megamanMechanics.moveVertCollision.n1.\@:
		add a, a
		jr nc, megamanMechanics.moveVertCollision.n0.\@
			ld HL, MovingRightTileSpeed
			ld (platformSpeed), HL
			ld a, PlatformMovement
			jp megamanMechanics.moveVertCollisionDetectedFinalizer.\@
megamanMechanics.moveVertCollision.n0.\@:
			
			inc a ; ld SlipperyMovement
			jp megamanMechanics.moveVertCollisionDetectedFinalizer.\@
			
.endif
.endm

;e: speed.hi
;hl: objectTable.2.1.ySpeed.hi
;output, z flag: no colision
.section "megamanMechanics.moveVertical" free	
megamanMechanics.moveDown:	
	;add the speed t
	dec l; objectTable.2.1.ySpeed.lo
	ld a, (hl)
	dec h; objectTable.2.1.y.lo
	add a, (hl)
	ld (hl), a
	inc l; objectTable.2.1.y.hi
	ld a, (hl)
	adc a, e

	cp $e8 ; the lowest limit of megaman position
	jp nc, +
		megamanMechanics.moveVertCollisionTest 1 4
+:
	cp $f4	;f4 is the celling of the stage, so if the vertical posistion
			;is bigger than f4, than we are actually on the top of the screen
	ld (hl), a	;save objectTable.2.1.y.hi
	jr nc, +
		ld a, BottomTransitionPending
		ld (transitionCheck), a
+:
		xor a
	ret
		
megamanMechanics.moveUp:
	dec l
	ld a, (hl)
	dec h
	add a, (hl)
	ld (hl), a
	inc l
	ld a, (hl)
	adc a, e

	cp $e8
	jr nc, +
		megamanMechanics.moveVertCollisionTest 0 12
+:
	 ; if we are here, we are hitting the ceilling, so force the position to the ceilling ($f4)
	
	ld (hl), $f4
	dec l
	xor a	;sets the flag for no collision
	ld (hl), a
	ret

.ends

;check if we are in a horiznotal map, if not, just return
.macro megamanMechanics.checkForHorizontalScroll
	ex af, af'
		ld a, (limits.orientation)
		dec a
		ret nz	;if the orientation is not horizontal
	ex af, af'
.endm

;de: speed
.section "megamanMechanics.moveHorizontal" free

megamanMechanics.checkMoveableGround:	
	ld hl, (platformSpeed)
	rra	;cp SliperyMovement
	jr c, megamanMechanics.checkMoveableGround.checkSlippery
		add hl, de
		ex de, hl
		jp megamanMechanics.moveHorizontalOnAir
		
megamanMechanics.checkMoveableGround.checkSlippery:	
	inc d;check if is positive or negative
	jp m, megamanMechanics.checkMoveableGround.negativeSpeed
		dec h
		inc h;check if is postive or negative
		jp m, megamanMechanics.incAndUsePlatformSpeed
			;if both speeds are postive, than the behavior will depend on witch is bigger
			ld a, d
			cp h
			jr c, megamanMechanics.decAndUsePlatformSpeed ;if carry, the speed is larger than the platformSpeed
			jr nz, +
				ld a, e
				cp l
				jr c, megamanMechanics.decAndUsePlatformSpeed ; if speed is larger or equal, than we use it.
+:				
					;if the speed is larger than the platform speed, we will use that.
					ld (platformSpeed), de 
					dec d ;decrement the speed back to prepare to be tested again
		jp megamanMechanics.moveHorizontalOnAir	
		
megamanMechanics.incAndUsePlatformSpeed:
			;if the platformSpeed and mechanic speed have opposite signs
			; than the speed will be platformSpeed increased by 2 or 4
			ld a, d
			or e
			ld bc, $0082
			jr z, +
megamanMechanics.incAndUsePlatformSpeed.short ; we already know that de is not 0
			;if the reguar speed not zero, than we will decrese the speed faster
				inc c
				inc c
+:			
			add hl, bc
			jr c, +
				ld bc, -$0080
				add hl, bc
				ld (platformSpeed), hl
				dec h
				ex de, hl
			jp megamanMechanics.moveHorizontalOnAir	
+:			
				ld hl, 2
				ld (platformSpeed), hl
				dec d
			jp megamanMechanics.moveHorizontalOnAir	
		
megamanMechanics.checkMoveableGround.negativeSpeed:			
		dec h
		inc h;check if is postive or negative
		jp p, megamanMechanics.decAndUsePlatformSpeed
;if both speeds are negative, than the behavior will depend on witch is bigger
			ld a, h
			cp d
			jr c, megamanMechanics.incAndUsePlatformSpeed;if carry is set, speed is larget than platform speed 
			jr nz, +
				ld a, l
				cp e
				jr c, megamanMechanics.incAndUsePlatformSpeed
+:					
					ld (platformSpeed), de	
					dec d ;decrement the speed back to prepare to be tested again
			jp megamanMechanics.moveHorizontalOnAir	
			
megamanMechanics.decAndUsePlatformSpeed:			
			;if the platformSpeed and mechanic speed have opposite signs
			; than the speed will be platformSpeed increased by 2 or 4
			ld a, d
			or e
			
			ld bc, -$0082	;the $008x is for force the carry flag to dhow up early
			jr z, +
megamanMechanics.decAndUsePlatformSpeed.short: ;we already know that de is not 0			
			;if the reguar speed not zero, than we will decrese the speed faster
				dec c
				dec c
+:			
			add hl, bc
			jr nc, +
				ld bc, $0080 ;	;add the $80 to compessate for subtracted before
				add hl, bc
				ld (platformSpeed), hl
				dec h
				ex de, hl
			jp megamanMechanics.moveHorizontalOnAir	
+:			
				ld hl, -2
				ld (platformSpeed), hl
				dec d
			jp megamanMechanics.moveHorizontalOnAir	
	
	
	
megamanMechanics.topScreenCheckBlocks:
;special case where we are above the tob of the screen
;so we just cant go "abover"
	and $1f; we know that bit 4 is one, so, we just leave it.
	rlca
	ld e, a
	jp megamanMechanics.checkBlocks
 
megamanMechanics.moveHorizontalOnGround:
	ld a, (moveableUnderTileType)
	or a
	jp nz, megamanMechanics.checkMoveableGround
	
megamanMechanics.moveHorizontalOnAir:	
	ld hl, objectTable.1.1.x
	ld a, (hl)
	add a, e
	ld (hl), a
	inc l
	
	;speeds come decremented by one, so this test gets faster
	inc d
		
	ld a, d
	jp m, megamanMechanics.moveHorizontalLeft
megamanMechanics.moveHorizontalRight:
		adc a, (hl)
		jr c, ++
			ld ix, gameplayMapsEngine.horizontalScrollRight
			
			inc l	; x.higher
			ld h, (hl) 
			ld c, a 	;save current x position
			add a, 8	;add 8 to put the coordinate on the
						;right block position
			jp nc, megamanMechanics.moveHorizontalConvergence
				dec ixl	;puts the jump for the scroll rotine in the correction position
				inc h
				
megamanMechanics.moveHorizontalConvergence:			
			and $f0
			ld l, a
			
			ld a, (objectTable.1.1.y+1)
			cp $f0
			jr nc, megamanMechanics.topScreenCheckBlocks
						;if is $f0 or greater, than we should
						;use 0 instead
				ld e, a
				and $f0
				rrca
				rrca
				rrca
				rrca
				add a, l
				ld l, a
				ld d, >horizontalTestableBlocksTable
			
				ld a, e
				and $0f
				rlca
				ld e, a
megamanMechanics.checkBlocks:			
			ld d, >horizontalTestableBlocksTable
			ld a, (de)
			ld b, a
			inc e
			ld a, (de)
			add a, l
			ld l, a
			
			ld d, >collisionPropertiesTable
-:			
				ld e, (hl)
				ld a, (de)
				;or a
				add a, a
				jr c, +
				inc l
			djnz -
			
			ld a, c
			ld (objectTable.1.1.x+1), a
			
			megamanMechanics.checkForHorizontalScroll
			jp (ix)
			
+:			;updates the new position with the closest
			;multiple of 8
			ld a, c
			and $f0
			add a, 8
			ld d, a
			ld e, 0
			ld (objectTable.1.1.x), de
			
			megamanMechanics.checkForHorizontalScroll
			jp (ix)
++:	
		;megamanMechanics.checkForHorizontalScroll
		;if we crossed page bondaries, than we are
		;in a horizontal scrolling map, so, no need
		;to test for that
		
		ld (hl), a
		inc l
		inc (hl)
		ld h, (hl)

		;get the scrolling adjusted, so we can use the a
		;register, and the scroll will be in hl
		call gameplayMapsEngine.adjustScrollPostion
		ld a, (limits.ending)
		cp h
		jp nz, gameplayMapsEngine.horizontalScrollRightNoAdjust;call +ret

		
		;if we are after the ending, it's time for transition
		ld a, RightTransitionPending
		ld (transitionCheck), a
		ret
		
megamanMechanics.moveHorizontalLeft:
		adc a, (hl)
		jr nc, ++
			ld ix, gameplayMapsEngine.horizontalScrollLeft
			inc l	; x.higher
			ld h, (hl) 
			ld c, a 	;save current x position
			sub 8	;sub 8 to put the coordinate on the
						;right block position
			jp nc, megamanMechanics.moveHorizontalConvergence
				dec h
				dec ixl;;puts the jump for the scroll rotine in the correction position
			jp megamanMechanics.moveHorizontalConvergence
++:		
		;megamanMechanics.checkForHorizontalScroll
		;if we crossed page bondaries, than we are not
		;in a horizontal scrolling map, so, no need
		;to test for that
		
		
		ld (hl), a
		inc l
		dec (hl)
		ld h, (hl)
		jp gameplayMapsEngine.horizontalScrollLeft		

.ends

;num tiles, offset of first tiles
.section "horizontalTestableBlocksTable" align $100 free
horizontalTestableBlocksTable:
.rept 5
	.db 2, -1
.endr
.rept 7
	.db 3, -1
.endr
.rept 4
	.db 2, 0
.endr
.rept 5
	.db 1, 0
.endr
.rept 11
	.db 2, 0
.endr

.ends

.section "megamanMechanics.stead" free
;megaman start startRunning:
--:
	ld hl, megamanMechanics.startRunningRight
	ld (megamanCurrentMechanic), hl
	ld hl, <objectAttr.megamanStartRunning ;frameTimer sets to 0
	ld (objectTable.2.1.id), hl ; also sets frameTimer

	and RKey
	jr z, ++
		ld a, ObjectActiveFlag
		ld (objectTable.1.1.flags), a ;maybe set frame here, with hl instead of a
		loadDePosSpeed MegamanStartRunningSpeed
		jp megamanMechanics.conclusionOnGround
		
++:	;LeftKeyPressed	
		ld a, ObjectActiveFlag | ObjectMirrorFlag
		ld (objectTable.1.1.flags), a	;maybe should also set frame
		loadDeNegSpeed MegamanStartRunningSpeed
		jp megamanMechanics.conclusionOnGround
		
megamanMechanics.stead:
	call megamanMechanics.preambleOnGround
	ld a, (holdedKeys)
	and LKey | RKey
	jr nz, --
		loadDePosSpeed MegamanSteadSpeed
megamanMechanics.conclusionOnGround:
	ld a, (megamanFireingPose)
	add a, a
	jp z, ++
		jr nc, +
			loadDePosSpeed 0
+:		rra
		dec a
		ld (megamanFireingPose), a
++:	
	ld a, (pressedKeys)
	and CKey 
	jr z, +++
		;if here, we start jumping
		call megamanMechanics.moveHorizontalOnGround
		ld hl, objectTable.2.1.ySpeed + 1
		ld e, (hl)
		inc e
		call megamanMechanics.moveDown
		loadHlSpeed MegamanJumpStartSpeed
		jr nz, +
-:
			ld a, (gravity)
			add a, a
			ld l, a
			sbc a, a
			cpl
			ld h, a
+:			
		ld (objectTable.2.1.ySpeed), hl
		
		xor a
		ld hl, objectTable.2.1.id
		ld (hl), <objectAttr.megamanOnAir
		inc l; objectTable.2.1.frameTimer
		;ld (hl), a: no need to set frame timer, since On air is only one frame
		dec h; objectTable.1.1.frame
		ld (hl), a
		
		ld hl, megamanMechanics.onAir
		ld (megamanCurrentMechanic), hl
		
		ld a, (moveableUnderTileType)
		rra
		ret nc
		
			ld hl, (platformSpeed)
			dec h
			jp nz, + 
			;if the most significant part of platfomr speed is one, than we should
			;slip one frame going into an oposite direction (this will be checked on air),
			; at half the pace we are sliping now.
				ld a, -$80
				add a, l
				ld (slipOnAirSpeedRight), a
				ret
+:			ld a, $fd
			cp l
			ret nz
				;if the most significant part of platfomr speed is $fe, than we should
				;slip one frame going into an oposite direction (this will be checked on air),
				; at half the pace we are sliping now.			
				ld a, $80
				add a, l
				ld (slipOnAirSpeedLeft), a
				ret	

+++:	
		call megamanMechanics.moveHorizontalOnGround
		
		ld hl, objectTable.2.1.ySpeed + 1
		ld e, (hl)
		inc e
		call megamanMechanics.moveDown
		ret nz
		jp -
		
.ends



