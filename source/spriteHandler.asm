.ifndef __SPRITE_HANDLER__
.define __SPRITE_HANDLER__

.bank 0 slot 0

;converts a object into sprites, taking in acount the most significant part
; of the objects Ys.
;iy:object Address
;h : most significant part of the attribute Table of the object
;de : postion on the sprite Table
;returns:
;de will be positioned on the next free position in the sprite table
;destroys:
;everything else, but the index registers
.section "verticalObjectToSprites" free
verticalObjectToSprites:
	ld l, (iy + miscObject.frame)
	dec l
	ret m
	
	sla l
	ld c, (hl)
	inc l
	ld h, (hl)
	ld l, c
	ld b, (hl)
	inc hl
	ld a, (iy + miscObject.y)
		
-:		push af
		add a, (hl)
		inc hl
		ld c, a
		sbc a, a
		cp (iy + miscObject.y + 1)
		jr nz, +
			ld a, 231
			cp c
			jr c, +
				ld a, (resolutionDependencies.objectToSpriteYOffset)
				add a, c
				ld (de), a
				rlc e
				set 7, e
				ld a, (hl)
				add a, (iy + miscObject.x)
				ld (de), a
				inc hl
				inc e
				ld c, d; make sure b will not be decremented
				ldi
				res 7, e
				rrc e
			jr ++
+:				inc hl
				inc hl
++:			pop af
	djnz -
	ret
.ends


;convert the 18 first objects in the sprite table into sprites, cleaning
;all the rest of the sprite table
;returns:
;de: next free position on the sprite table
;iy: 19th object
;b : 0
.section "verticalObjectsToSprites" free
verticalObjectsToSprites:	
	call clearSpriteTable
	ld de, spriteTable
	ld iy, miscObjectTable.1.frame
	ld b, $12	
-:		push bc
		ld h, >miscObjects
		call verticalObjectToSprites

		ld bc, _sizeof_miscObject
		add iy, bc
		pop bc	
	djnz -
	ret		
.ends


;Clear object table
.section "clearObjectTable" free
clearObjectTable:
	xor a
	ld hl, objectTable
	ld bc, 2	;objectTable size is 512
-:
			ld (hl), a
			inc l
		djnz -
		dec c
	jr nz, -	
;fallThrow
;set $f1 to all ys sprites.
clearSpriteTable:;Lbl_8473:
	ld a, $f0
	ld b, 64
	ld hl, spriteTable
	
-:		ld (hl), a
		inc l
	djnz -	
	ret
.ends


.macro megamanObjectToSprites
megamanObjectToSprites.beggining.\@:	
	ld a, (hl)	;object.1.flags
	rla
	jr nc, megamanObjectToSprites.endLabel.\@ 
	rla	;save mirror flag in carry
	
	inc h; ld l, object.2.id
	ld e, (hl);load attribute pointer
	ld d, >objectAttrAddresses;	starting in frameTimers
	
	inc l; ld hl, object.2.frameTimer
	
	ld a, (generalFlags)
	bit MegamanFreezedBit, a
	jr nz, megamanObjectToSprites.saveMegamanTilesPointer.\@
		dec (hl)
		jp p, megamanObjectToSprites.saveMegamanTilesPointer.\@
			ld a, (de)
			ld (hl), a
			dec h; ld hl, object.1.frame
			inc d;objectAttrFrame
			
			dec (hl)
			dec (hl)
			
			jp p, megamanObjectToSprites.saveMegamanTilesPointerIgnoreDecH.\@
				ld a, (de)
				ld (hl), a
				inc h; faster than jp megamanObjectToSprites.saveMegamanTilesPointerIgnoreDecH.\@
megamanObjectToSprites.saveMegamanTilesPointer.\@			
	dec h; ld hl, object.1.frame		
megamanObjectToSprites.saveMegamanTilesPointerIgnoreDecH.\@:		
	ld d, >objectAttrAddresses.lo 
	ld a, (de)
	adc a, (hl)	
	rlca	;a*4 + 2*mirrorFlag	
	
	
	inc d	;objectAttrFrameList.hi
	ex AF, af'
	
	ld A, (de)
	
	exx
		ld H, A
		ld A, (megamanFireingPose)
		add A, A
		jp z, +
			inc H
		jp nc, +	
			inc H
+:	
		ex af, AF'
		ld L, a
		ld a, (HL)
		inc L
		ld L, (HL)
		ld H, a
		
		ld a, (HL)
		inc L 
		ld (megamanNextTilesLoader), a
	exx
	
	inc l
	inc l	;ld hl, object.y.hi
	ld a, (hl)	;ld y coordinate 
	add	a, c ;subtract resolution dependency Y's offset
	ex AF, af'
	
	inc l
	inc l	; ld hl, object.x.hi
	ld A, (hl)
	sub iyl	;subtract scroll
	;here I could test for clipping the entire object
	;however, the NES code assumes that at least
	;some of the object will be visible, so this is
	;probable handled on the object function.
	
	exx
	add A, (HL)	;subtract X offset
	inc L
	
megamanObjectToSprites.skipAfterCarry.\@:
	ld B, 4
	
			;the first X coordinate have an extra pixel to be subtracted
			;this is used because otherwise, the previous test would be "carry or zero".
			;And sprites with a zero coordinate should not be visible, otherwise the end mark($ff)
			;could be summed and still the result would not result in a carry
	inc A	;remove the extra unit in the offset X
-:
		ld C, A
		ex af, AF'

			add a, (HL)
			inc L
			cp iyh	;check if y is equal $d0 (or 224 in extented
				;resolution)
			inc B; go to the next tile index
			jr z, megamanObjectToSprites.skip.\@

			dec E
			ld (DE), a

			push BC

megamanObjectToSprites.skip.\@:		
		ex AF, af'
		
		add A, (HL)
		inc L
	jr nc, -
	exx
megamanObjectToSprites.endLabel.\@:
.endm

;\1: inverted
;\2: begginingLabel
;\3: endLabel
.macro gameplayObjectToSprites.end
	exx
	;inc h
	.if 1 == \1
		ld a, 1 + (-1 * _sizeof_object.1)
		add a, l
		ld l, a	;previosObject
		jp nz, \2 
	.else
		inc l
		inc l
		inc l	;nextObject
		jp nz, \2 
	.endif
	jp \3
.endm

;\1: spriteTableFilledJpAddr
.macro pushY
	dec e
	ld (de), a
	jr z, \1
.endm

;USES OBJECT TABLE

;\1: inverted
;\2: endLabel
.macro gameplayObjectToSprites
gameplayObjectToSprites.beggining.\@:	
	ld a, (hl)	;object.1.flags
	rla
	jr nc, gameplayObjectToSprites.skipObject.\@ 
	rla	;save carry flag
	
	inc h; ld l, object.2.id
	ld e, (hl);load attribute pointer
	ld d, >objectAttrAddresses;	starting in frameTimers
	
		inc l; ld hl, object.2.frameTimer
		djnz +
		inc b
		
		dec (hl)
		jp p, +
			ld a, (de)
			ld (hl), a
			dec h; ld hl, object.1.frame
			inc d;objectAttrFrame
			dec (hl)
			dec (hl)
			
			jp p, ++
				ld a, (de)
				ld (hl), a
				jp ++

+:		inc d;objectAttrFrame
		dec h ; ld hl, object.1.frame
++:		
	
	inc d ;objectAttrFrameList.lo
	ld a, (de)
	adc a, (hl)	
	rlca	;a*4 + 2*mirrorFlag	
	
	inc d	;objectAttrFrameList.hi
	ex AF, af'
	ld A, (de)

	exx
		ld H, A
		ex af, AF'
		ld L, a
		ld a, (HL)
		or a	;if the pointer is equal to zero
		jp nz, +
		
			exx
			inc h
		
gameplayObjectToSprites.skipObject.\@:
			.if 1 == \1
				ld a, -1*_sizeof_object.1
			.else
				ld a, _sizeof_object.1
			.endif
			add a, l
			ld l, a	 ;nextObject
			jp nz, gameplayObjectToSprites.beggining.\@
			jp \2
+:
		inc L
		ld L, (HL)
		ld H, a
	exx
	
	inc l
	inc l	;ld hl, object.y.hi
	ld a, (hl)	;ld y coordinate 
	add	a, c ;subtract resolution dependency Y's offset
	ex AF, af'
	
	inc l
	inc l	; ld hl, object.x.hi
	ld A, (hl)
	sub iyl	;subtract scroll
	;here I could test for clipping the entire object
	;however, the NES code assumes that at least
	;some of the object will be visible, so this is
	;probable handled on the object function.
	
	exx
	add A, (HL)	;subtract X offset
	inc L
	
	;if the object is before the left end of the screen
	;than we have to skip sprites until one of than become visible
	jr nc, gameplayObjectToSprites.skipUntilCarry.\@
		
		;peraphs is a good time to eliminate the object
		;if is completly out of screen
		;for now, I'm just relaying that will not be
		;end sprite
		;gameplayObjectToSprites.end \1, gameplayObjectToSprites.beggining.\@, \2

	
gameplayObjectToSprites.skipAfterCarry.\@:	
			;the first X coordinate have an extra pixel to be subtracted
			;this is used because otherwise, the previous test would be "carry or zero".
			;And sprites with a zero coordinate should not be visible, otherwise the end mark($ff)
			;could be summed and still the result would not result in a carry
	inc A	;remove the extra unit in the offset X
-:
		ld C, A
		ex af, AF'

			add a, (HL)
			inc L
			cp iyh	;check if y is equal $d0 (or 224 in extented
				;resolution)
			jr z, gameplayObjectToSprites.skip.\@

			pushY gameplayObjectToSprites.spriteTableFilled.\@
			ld B, (HL)
			push BC

gameplayObjectToSprites.skip.\@:		
		ex AF, af'
		inc L
		
		add A, (HL)
		inc L
	jr nc, -

gameplayObjectToSprites.endSprite.\@:	
	;end sprite
	gameplayObjectToSprites.end \1, gameplayObjectToSprites.beggining.\@, \2
	;spriteTableFilled
gameplayObjectToSprites.spriteTableFilled.\@:
	ld sp, (spHolder)
	ret
	
gameplayObjectToSprites.skipUntilCarry.\@:
		ex af, AF'
			add a, (HL)
			inc L
			inc L
		ex AF, af'
		
		add A, (HL)
		inc L
	
	jp nc, gameplayObjectToSprites.skipUntilCarry.\@
	;jp gameplayObjectToSprites.skipAfterCarry.\@;	if is negative
	
	;thie next line can replace the previous test if there is a chance that the
	;object is complete off screen on the left side.
	;if that is the case, than we must than put the end object code after the test
	
	jp p, gameplayObjectToSprites.skipAfterCarry.\@
	jp gameplayObjectToSprites.endSprite.\@
.endm



;de: sprite table pointer
;a: life
;b: x position of the bar
.macro gameplayObjectsToSprites.updateStatusSprites
	ld c, a
	rlca
	add a, c
	ld h, >updateStatusTable
	ld l, a
	ld a, (hl)
	inc l
	ld c, (hl)
	inc l
	ex af, af'
	ld a, (hl)
	ld l, b
	ld b, a
	
	ld a, $40 
	ld h, 4
	dec b
	jr z, +
-:	
		pushY ++
		sub 8
		push hl
	djnz -
+:	ld h, c	
	pushY ++
	sub 8
	push hl

	ex af, af'
	ld b, a
	ex af, af'

	ld h, 0
	dec b
	jr z, ++
-:	
		pushY ++
		sub 8
		push hl
	djnz -
++:
	ld sp, (spHolder)
	ret
	
.endm

;triplets for each possible measure between 28 - 0
;
.section "updateStatusTable" align $100 free
updateStatusTable:
	.db 7, 0, 1
	
	.db 7, 1, 1
	.db 7, 2, 1
	.db 7, 3, 1
	.db 7, 4, 1
	
	.db 6, 1, 6
	.db 6, 2, 2
	.db 6, 3, 2
	.db 6, 4, 2
              
	.db 5, 1, 3
	.db 5, 2, 3
	.db 5, 3, 3
	.db 5, 4, 3
              
	.db 4, 1, 4
	.db 4, 2, 4
	.db 4, 3, 4
	.db 4, 4, 4
              
	.db 3, 1, 5
	.db 3, 2, 5
	.db 3, 3, 5
	.db 3, 4, 5
	          
	.db 2, 1, 6
	.db 2, 2, 6
	.db 2, 3, 6
	.db 2, 4, 6
              
	.db 1, 1, 7
	.db 1, 2, 7
	.db 1, 3, 7
	.db 1, 4, 7	
          	
	
.ends


.section "gameplayObjectsToSprites" free
gameplayObjectsToSprites:
	
	call clearSpriteTable ; No way the best way to do this	
	
	mapPage2 :objectAttrAddresses
	ld (spHolder), sp
	ld sp, spriteTableBottom+128
	exx
	ld DE, spriteTable+64
	exx
	
	ld hl, objectTable.1.1.flags
	
	ld iy, (hScroll); ld iyl, (hScroll)
	ld bc, (resolutionDependencies.objectToSpriteYOffset)
	ld iyh, b; resolutionDependencies.screenResolution

	megamanObjectToSprites
	
	ld b, 1;	animation set indicator
	ld a, (frameCounter)
	rra
	jp gameplayObjectsToSprites.nonInverted
	;jp c, gameplayObjectsToSprites.nonInverted
		ld l, <objectTable.1.32.flags
		;gameplayObjectToSprites 1, ++
		jp ++
gameplayObjectsToSprites.nonInverted:
		
		ld l, <objectTable.1.2.flags
		gameplayObjectToSprites 0, ++
++: 
	exx
	ld a, (megamanLife)	
	ld B, 24 
	gameplayObjectsToSprites.updateStatusSprites
	
.ends


.endif