.ifndef __OBJECTS_ASM__
.define __OBJECTS_ASM__

;a : (objectTable.1.n.flags)
;de: objectTable.1.n.flags
;hl: objectTable.2.n.ySpeed
.section "object.basicMovement" free
object.basicMovement:
	ld c, a
	inc e
	inc e
	
	ld a, (de)
	add a, (hl)
	ld (de), a
	inc e  ;de: objectTable.1.n.y.hi
	inc l
	ld a, (de)
	add a, (hl)
	cp $f0
	jr nc, object.basicMovement.deactivate

	ld (de), a
	
	bit BitObjectGravitySensibleFlag, c
	jp z, +
		dec l
		ld a, (gravity)
		add a, (hl)
		ld (hl), a
		inc l
		jp nc, +
			inc (hl)
+:		
	inc l 
	inc e

	bit BitObjectMirrorFlag, c
	jr nz, object.basicMovement.toLeft
object.basicMovement.toRight:
		ld a, (de)
		add a, (hl)
		ld (de), a
		inc l
		inc e
		ld a, (de)
		adc a, (hl)
		ld (de), a
		inc e
		jp nc, +
			ex de, hl
			inc (hl)
			ex de, hl
+:			
		ld hl, (hScroll)
		sub l
		jr c, +
			cp $f8
			jp nc, object.basicMovement.deactivate
			ld a, (de)
			sub h
			jp nz, object.basicMovement.deactivate
		ret
+:			cp $f8
			jp nc, object.basicMovement.deactivate
			ld a, (de)
			dec a
			sub h
			jp nz, object.basicMovement.deactivate
		ret
			
		
object.basicMovement.toLeft:
		ld a, (de)
		sub (hl)
		ld (de), a
		inc l
		inc e
		ld a, (de)
		sbc a, (hl)
		ld (de), a
		
		inc e
		jp nc, +
			ex de, hl
			dec (hl)
			ex de, hl
+:	
		ld hl, (hScroll)
		sub l
		jr c, +
			cp $08
			jp c, object.basicMovement.deactivate
			ld a, (de)
			sub h
			jp nz, object.basicMovement.deactivate
		ret
+:			cp $08
			jp c, object.basicMovement.deactivate
			ld a, (de)
			dec a
			sub h
			jp nz, object.basicMovement.deactivate
		ret
object.basicMovement.deactivate:		
	ld a, e
	and %11111000
	ld e, a
	xor a
	ld (de), a
	ret		
		
.ends

.section "object.clearTopHalfObjects" free
object.clearTopHalfObjects:
	ld hl, objectTable.1.2.flags 
	ld a, l
	ld c, a
-:	
		ld (hl), c
		add a, 8
		ld l, a
	jp p, -	
	ret
.ends

.section "object.processTopHalfObjects" free
object.processTopHalfObjects:	
	ld de, objectTable.1.2.flags
	ld hl, objectTable.2.2.ySpeed
	ld a, (de)
	cp ObjectActiveFlag; test if activate
	call nc, object.basicMovement

.rept 13 index idx	
	ld e, <objectTable.1.3.flags + idx*8
	ld hl, objectTable.2.3.ySpeed + idx*8
	ld a, (de)
	cp ObjectActiveFlag; test if activate
	call nc, object.basicMovement
	
.endr
	ld e, <objectTable.1.15.flags
	ld hl, objectTable.2.15.ySpeed
	ld a, (de)
	cp ObjectActiveFlag; test if activate
	jp nc, object.basicMovement ; call +ret

	ret
.ends

.endif
