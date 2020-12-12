.ifndef __BOSS_INTRODUCTION_ASM__
.define __BOSS_INTRODUCTION_ASM__

;.define bossIntroText tempVars
;.define bossTimers tempVars + 9
.define BossTextStartPosition $3b94 | VramWrite 
.bank 0 slot 0


.section "bossIntroduction.animateBossIntro" free
bossIntroduction.animateBossIntro:
	mapPage2 :opnBossObjectsTable
	ld de, miscObjectTable.2.frameTimer
	ld hl, bossTimers
	ld a, (de)
	add a, (hl)
	jr nc, +
		ld (de), a
		inc l
		ld e, <miscObjectTable.2.frame
		ld a, (de)
		inc a
		cp (hl)
		jr nz, +
			dec a
+:	ld (de), a
	call clearSpriteTable
	ld de, spriteTable
	ld iy, miscObjectTable.2.frame
	ld (iy + miscObject.y + 1), $ff
	ld h, >opnBossObjectsTable
	jp verticalObjectToSprites	;call + ret

.ends

.section "bossIntroduction.animateStars" free
bossIntroduction.animateStars:
	mapPage2 :miscObjects
	ld de, spriteTable + 23
	ld iy, miscObjectTable.3.frame
	ld a, (frameCounter)
	and %00000011
	jr nz, +
		inc (iy + miscObject.x)
+:	ld h, >miscObjects
	call verticalObjectToSprites
	
	ld bc, _sizeof_miscObject
	add iy, bc
	inc (iy + miscObject.x)
	and %00000011
	jr nz, +
		inc (iy + miscObject.x)
+:	ld h, >miscObjects
	call verticalObjectToSprites
	
	ld bc, _sizeof_miscObject
	add iy, bc
	ld a, 4
	add a, (iy + miscObject.x)
	ld (iy + miscObject.x), a
	ld h, >miscObjects
	jp verticalObjectToSprites	;call + ret
	
.ends

;loads the boss introduction map
.macro bossIntroduction.loadMap
	call turnOffVdp
	ld hl, column.buffer
	ld bc, 02
	call stageSelection.loadTileToColumn
	fastLdir 55
	
	ld l, <column.buffer + 20
	ld bc, $0198
	call stageSelection.loadTileToColumn
	fastLdir 10
	
	ld a, $0c
	ld (column.buffer + 18), a
	ld a, $0e 
	ld (column.buffer + 32), a
	ld bc, (31 << 8) | VdpDataPort
-:		push bc
		
		ld a, b
		rla
		call outputColumn
		pop bc
		dec	b
	jp p, -	
.endm

.macro bossIntroduction.loadNonSpecficBossPalette
	ld hl, palette.hasNewPalette
	ld (hl), 1
	inc l
	xor a
	ld bc, $343c
	ld (hl), c
	ld l, <palette.buffer + 2
	ld (hl), a
	inc l
	ld (hl), b
	ld l, <palette.buffer + 16
	ld (hl), a
	ld l, <palette.buffer + 19
	ld (hl), a
.endm

;h: >miscObjectTable.2
.macro bossIntroduction.bringBossDown
	ld l, <miscObjectTable.2.y
	ld (hl), $20
	
-:		ld hl, miscObjectTable.2.frameTimer
		xor a
		ld (hl), a
		ld l, <miscObjectTable.2.y
		ld a, (hl)
		add a, 8
		ld (hl), a
		cp $78
		jr z, +
		call bossIntroduction.animateBossIntro
		call prepareForVblank
	jr -
+	
.endm

.macro bossIntroduction.fadeInStars
	ld c, 4
--:		ld b, 8
		ld a, 1
		cp c
		jr nz, +
			ld b, 5*8
+:		ld hl, palette.hasNewPalette
		inc (hl)
		ld l, <palette.buffer + 19
		ex de, hl
		ld hl, palette.buffer + 17 ;white
		push bc
		ld b,  1
		call fadeInPalette
		pop bc
-:			push bc
			ld hl, miscObjectTable.2.frameTimer
			xor a
			ld (hl), a
			call bossIntroduction.animateBossIntro
			call bossIntroduction.animateStars
			call prepareForVblank
			pop bc
		djnz -
		dec c
	jr nz, --
.endm

.macro bossIntroduction.WriteBossName
	ld hl, vramRaw.destination
	ld de, BossTextStartPosition
	ld (hl), e
	inc l
	ld (hl), d
	inc l
	ld de, endSeqOuti - 2*2
	ld (hl), e
	inc l
	ld (hl), d
	inc hl
	inc l
	ld (hl), 1
	
	ld c, 9
	ld hl, bossIntroText 
		
--:		ld b, 4
		ld a, (hl)
		inc l
		ld (vramRaw.buffer), a
		push hl
		ld hl, vramRaw.haveData
		inc (hl)
		ld l, <vramRaw.destination
		inc (hl)
		inc (hl)
		pop hl
-:			push hl
			push bc
			call bossIntroduction.animateStars
			call prepareForVblank
			pop bc
			pop hl
		djnz -
		dec c
	jr nz, --
	
.endm


;Shows boss animation in the levels introduction
;expects tiles loaded on vram, boss palette loaded on palette buffer
;and text and timer loaded on local vars
.section "bossIntroduction" free
bossIntroduction:
	bossIntroduction.loadMap
	call turnOnVdp
	bossIntroduction.loadNonSpecficBossPalette
	
	
	ld a, :bossIntroductionMusic
	ld hl, bossIntroductionMusic
	call PSGPlay
	PSGCancelLoop
	
	ld b, $18
-:		push bc
		call prepareForVblank
		pop bc
	djnz -	


	ld hl, miscObjectTable.2.x
	ld (hl), $80
	bossIntroduction.bringBossDown
	
	;increase the frame index of the boss by one, leaving the falling frame
	ld l, <miscObjectTable.2.frame
	inc (hl)
	
	;load background stars
	ld de, _sizeof_miscObject
	ld a, miscObject.bosIntro.stars
	add hl, de
	ld b, 3
	
-:		ld (hl), a
		add hl, de
		inc a
	djnz -
	
	bossIntroduction.fadeInStars

	ld b, $50
	call bossIntroduction.animateBframes
		
	bossIntroduction.WriteBossName
	
	ld b, $AA + $15
	jp bossIntroduction.animateBframes ; call+ret
	
	
.ends

;
.section "bossIntroduction.animateBframes" free
bossIntroduction.animateBframes:
-:		push bc
		call clearSpriteTable
		call bossIntroduction.animateBossIntro
		call bossIntroduction.animateStars
		call prepareForVblank
		pop bc
	djnz -
	ret
.ends

.endif