.ifndef __WEAPONS_ASM__
.define __WEAPONS_ASM__

.define WeaponFireingTimer 14
.define WeaponThrowingTimer $80 | WeaponFireingTimer
	

;de: weaponsAttributes
;hl: objectTable.1.x.flags : flags position of the shot in the objectTable
.section "weapons.setWeaponObject" free
weapons.setWeaponObject:
	ld a, (de)
	inc e
	ld (megamanFireingPose), a
	ex de, hl
	
	ld a, (objectTable.1.1.flags) ; check if megaman is facing left or right
	add a, a; will put the mirror flag on the right position
	jp m, weapons.setWeaponObject.facingLeft 
	
weapons.setWeaponObject.facingRight:	
	ldi ; de: objectTable.1.n.flags
	
	xor a
	ld (de), a ; de: objectTable.1.n.frame
	inc e
	inc e
	
	ld a, (objectTable.1.1.y+1)
	ld (de), a ; de: objectTable.1.n.y.hi
	inc e
	inc e
	
	ld a, (objectTable.1.1.x+1)
	add a, (hl)
	ld (de), a ; de: objectTable.1.n.x.hi
	inc e
	inc l

	ld a, (objectTable.1.1.x.higher)
	adc a, 0
	ld (de), a ; de: objectTable.1.n.x.higher

	jp +
	
weapons.setWeaponObject.facingLeft:
	ld a, (hl)
	or ObjectMirrorFlag
	ld (de), a ; de: objectTable.1.n.flags
	inc e
	inc l

	xor a
	ld (de), a ; de: objectTable.1.n.frame
	inc e
	inc e
	
	ld a, (objectTable.1.1.y+1)
	ld (de), a  ; de: objectTable.1.n.y.hi
	inc e
	inc e
	
	ld a, (objectTable.1.1.x+1)
	sub (hl)
	ld (de), a ; de: objectTable.1.n.x.hi
	inc e
	inc l

	ld a, (objectTable.1.1.x.higher)
	sbc a, 0
	ld (de), a  ; de: objectTable.1.n.x.higher

+:	
	ld a, $ff & (objectTable.2.1.id - objectTable.1.1.x.higher)
	add a, e
	ld e, a
	inc d
	
	ldi ; de: objectTable.2.n.id
	
	
	xor a
	ld (de), a ; de: objectTable.2.n.frameTimer
	inc e
	ldi	; de: objectTable.2.n.ySpeed.lo
	ldi ; de: objectTable.2.n.ySpeed.hi
	ldi ; de: objectTable.2.n.xSpeed.lo
	ldi; de: objectTable.2.n.xSpeed.hl

	ld a, (hl)
	inc hl
	ld h, (hl)
	ld l, a
	jp PSGSFXPlay ; call + ret
	
.ends

;a: holdedKeys
.section "weapons.megamanShot" free
weapons.megamanShot:
	and $0f
	ld l, a
	ld a, (selectedWeapon)
	or a
	jp z, weapons.megamanBuster ;call + ret
	jp weapons.metalmanBuster ;call + ret
	
.ends

.macro weapons.initialMetalManHeader
	.db WeaponThrowingTimer
	.db ObjectActiveFlag ;flags
	.db 0 ;x.hi
	.db <objectAttr.metalmanBuster ;id
.endm

.section "weapons.initialWeaponsData" align $100 free
weapons.initialMetalmanBusterData:
	.db <weapons.initialMetalmanBusterData.hor
	.db <weapons.initialMetalmanBusterData.top
	.db <weapons.initialMetalmanBusterData.dow
	.db <weapons.initialMetalmanBusterData.top
	
	.db <weapons.initialMetalmanBusterData.hor
	.db <weapons.initialMetalmanBusterData.dtop
	.db <weapons.initialMetalmanBusterData.ddow
	.db <weapons.initialMetalmanBusterData.dtop	
	
	.db <weapons.initialMetalmanBusterData.hor
	.db <weapons.initialMetalmanBusterData.dtop
	.db <weapons.initialMetalmanBusterData.ddow
	.db <weapons.initialMetalmanBusterData.dtop	
	
	.db <weapons.initialMetalmanBusterData.hor
	.db <weapons.initialMetalmanBusterData.top
	.db <weapons.initialMetalmanBusterData.dow
	.db <weapons.initialMetalmanBusterData.top
	
weapons.initialMetalmanBusterData.dow:
	weapons.initialMetalManHeader
	.dw $0400 ;ySpeed
	.dw $0000 ;xSpeed
	.dw metalBladeSfx
	;.db $01  OutraPropriedade	
weapons.initialMetalmanBusterData.ddow:
	weapons.initialMetalManHeader
	.dw $02d4 ;ySpeed
	.dw $02d4 ;xSpeed
	.dw metalBladeSfx
	;.db $01  OutraPropriedade	
weapons.initialMetalmanBusterData.hor:
	weapons.initialMetalManHeader
	.dw $0000 ;ySpeed
	.dw $0400 ;xSpeed
	.dw metalBladeSfx
	;.db $01  OutraPropriedade	
weapons.initialMetalmanBusterData.dtop:
	weapons.initialMetalManHeader
	.dw $fd2c ;ySpeed
	.dw $02d4 ;xSpeed
	.dw metalBladeSfx
	;.db $01  OutraPropriedade	
weapons.initialMetalmanBusterData.top:
	weapons.initialMetalManHeader
	.dw $fc00 ;ySpeed
	.dw $000 ;xSpeed
	.dw metalBladeSfx
	;.db $01  OutraPropriedade	
	
weapons.initialMegamanBusterData:
	.db WeaponFireingTimer
	.db ObjectActiveFlag ;flags
	.db 10 ;x.hi
	.db <objectAttr.megamanBuster ;id
	.dw $0000 ;ySpeed
	.dw $0400 ;xSpeed
	.dw busterSfx
	;.db $01  OutraPropriedade
		
.ends

.section "weapons.metalmanBuster" free
weapons.metalmanBuster:
	ld a, (pressedKeys)
	and BKey
	ret z 
	
	ld h, >weapons.initialMetalmanBusterData
	ld l, (hl)
	ex de, hl
	
	jp weapons.megamanBuster.selectEmptySpot
	
.ends

.section "weapons.megamanBuster" free
weapons.megamanBuster:
	ld a, (pressedKeys)
	and BKey
	ret z 
	
	ld de, weapons.initialMegamanBusterData

weapons.megamanBuster.selectEmptySpot:
	ld hl, objectTable.1.2.flags
	or (hl);Active flag is bit 7 and, bit 7 will be 0 on reg a.
	jp p, weapons.setWeaponObject 

	ld l, <objectTable.1.3.flags
	xor (hl)
	jp m, weapons.setWeaponObject 

	ld l, <objectTable.1.4.flags
	or (hl)
	jp p, weapons.setWeaponObject 

	ret
.ends

.endif