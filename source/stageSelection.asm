.ifndef __STAGE_SELECTION_ASM__
.define __STAGE_SELECTION_ASM__

.define QuickManHornLocation VramWrite | $3872
.define PositionFirstFace VramWrite | $388c
.define FirstTileFacePosition 0
.enum tempVars
	bossIntroText dsb 9
	bossTimers dsb 3
	stageSelection.ramPalette dsb stageSelection.palette.size + 1
	stageSelection.ramBlinkPalette dsb stageSelection.palette.size
.ende

.bank 0 slot 0

.section "stageSelection.stageAttributes" free ;align $100 free
stageSelection.stageAttributes:
	.db	$01 :bubblemanIntroData 
	.dw bubblemanIntroData
	.db :bubblemanStage.stageLoader
	.dw bubblemanStage.stageLoader
	.dw bubblemanPalette
	
	.db $02 :airmanIntroData
	.dw airmanIntroData
	.db :airmanStage.stageLoader
	.dw airmanStage.stageLoader
	.dw airmanPalette
	
	.db $04 :quickmanIntroData
	.dw quickmanIntroData
	.db :quickmanStage.stageLoader
	.dw quickmanStage.stageLoader
	.dw quickmanPalette
	
	
	.db $08 :heatmanIntroData
	.dw heatmanIntroData
	.db :heatmanStage.stageLoader
	.dw heatmanStage.stageLoader
	.dw heatmanPalette

	.db $10	:woodmanIntroData
	.dw woodmanIntroData
	.db :woodmanStage.stageLoader
	.dw woodmanStage.stageLoader
	.dw woodmanPalette
	
	.db $20 :metalmanIntroData
	.dw metalmanIntroData
	.db :metalmanStage.stageLoader
	.dw metalmanStage.stageLoader
	.dw metalmanPalette
	
	.db $40 :flashmanIntroData
	.dw flashmanIntroData
	.db :flashmanStage.stageLoader
	.dw flashmanStage.stageLoader
	.dw flashmanPalette
	
	.db $80 :crashmanIntroData
	.dw crashmanIntroData
	.db :crashmanStage.stageLoader
	.dw crashmanStage.stageLoader
	.dw crashmanPalette
.ends

.section "stageSelection.cursorPosition" align $100 free
stageSelection.cursorPosition:
	.db 0*64, 0*64, 1*64, 0*64
	.db 1*64, 0*64, 2*64, 1*64
	.db 2*64, 1*64, 2*64, 2*64
.ends


;loads the stageSelection tilemap into vram
;it's here, and not in the map loaders because it's only loaded here
.macro stageSelection.loadMap
	ld hl, column.buffer
	ld ixh, 64
	ld bc, $0198
	call stageSelection.loadTileToColumn
	fastLdir VramRowCount*2
	
	ld de, 6
	
	ld hl, column.buffer + 2
	ld (hl), e
	inc l
	ld (hl), d
	
	ld l,  <column.buffer + 54
	ld (hl), e
	inc l
	ld (hl), d
	
	mapPage2 :stageSelectionMapLastColumn
	ld hl, stageSelectionMapLastColumn
---:	ld de, column.buffer + 4 ;put the destination pointer back to the begining
		push hl	;save the global origin pointer
		ld l, (hl)
		
		ld c, 27 ;load counter 3 + 3*8(number of entries)
--:			push hl
			ld b, 8
-:				ld a, (hl)
				rla
				rla
				and 1
				
				ldi
				ld (de), a
				inc e
			djnz -
			pop hl
			dec c
		jr nz, --
		
		ld a, ixh
		dec a
		dec a
		ld ixh, a 
		
		call outputColumn
		pop hl
		dec l
	jp p, ---

.endm


;loads a 32x32 boss face or wily logo into the screen
.macro stageSelection.loadBossFace
	push af
	ld a, 1
	ld e, 4
--:		ld c, VdpControlPort
		out (c), l
		out (c), h
		dec c
	
		ld b, 4
-:			out (c), d	
			inc d
			out (VdpDataPort), a
		djnz -
		ld c, 64
		add hl, bc
		dec e
	jr nz, --
	pop af
.endm

;get the position of the cursor and converts to a address
;in the stageAttributes
; \1 address to jump in case the cursor is over wili logo
;return:
; hl: Address on the stageAttributes
;  a: copy of l
.macro stageSelection.cursorPostionToAddress
	ld hl, miscObjectTable.2.y
	ld a, (hl)
	rlca
	rlca
	ld b, a
	rlca		; multiply by 2
	add a, b 	; multiply by 3
	ld b, a
	ld l, <miscObjectTable.2.x
	ld a, (hl)
	rlca
	rlca
	add a, b
	cp $04
	jp z, \1
	jp m, stageSelection.cursorPostionToAddress.ignoreDec
		dec a
stageSelection.cursorPostionToAddress.ignoreDec:
	ld b, a
	rlca
	rlca
	rlca
	add a, b
	;ld l, a
	ld hl, stageSelection.stageAttributes
	add a, l
	ld l, a
	jr nc, stageSelection.cursorPostionToAddress.skipInc
		inc h
stageSelection.cursorPostionToAddress.skipInc:
	
.endm

;hl: position in the column buffer
;bc: name table entry
;return:
;de: will be positioned two positions ahead of hl
;hl: will be preserved
.section "stageSelection.loadTileToColumn" free
stageSelection.loadTileToColumn:
	ld (hl), c
	inc l
	ld (hl), b
	ld d, h
	ld e, l
	dec l
	inc e
	ret
.ends

;blinks the screen while loading boss animation timers, name, palettes
;and tiles.
;hl: pointer to the boss structure
;returns:
; boss palette to palette buffer (in the last 8 entries)
; tiles to vram, starting on $14 index
; animation timers on temp var bossTimers
; boss name on bossIntroText
.macro blinkScreenLoadingBossStuff
teste:	
	push hl
	
	ld a, :teleportOutSfx
	ld hl, teleportOutSfx
	call PSGPlay
	PSGCancelLoop
	
	;loads those palette on a temp location since this function will potentially swap banks
	ld de, stageSelection.ramPalette
	mapPage2 :stageSelection.palette
	ld hl, stageSelection.palette
	fastLdir stageSelection.palette.size*2 + 1	;2 because it has to load both the regular palette and the blink palette
	pop hl
	
	ld a, (hl)
	ld (currentBoss), a
	inc hl
	ld a, (hl)
	ld (MapperSlot2), a
	inc hl
	ld e, (hl)
	inc hl
	ld d, (hl)
	inc hl
	push hl
	ex de, hl
	
	ld de, bossIntroText
	fastLdir 11
	ld a, (hl)
	ld (miscObjectTable.2.frame), a
	inc hl
	
	ex de, hl
	ld ixl, e
	ld ixh, d
	
	ld hl, VramWrite | (20*32)
	ld (tileDecompVramPtr),hl 
	
	call clearSpriteTable
	call prepareForVblank

	ld b, $34
--:		push bc
		ld a, %00000011
		and b
		jr nz, ++
			ld hl, stageSelection.ramBlinkPalette
			ld a, %00000100
			and b
			jr nz, +
				ld l, <stageSelection.ramPalette
+:			call gameplayMapsEngine.loadPalette
++:		ld c, 4
-:			call decompressSingleTile
			dec c
		jr nz, -
		call prepareForVblank
		pop bc
	djnz --
	
	pop hl
	ld a, (hl)
	ld (stage.bank), a
	ld (MapperSlot2), a
	
	inc hl
	ld e, (hl)
	inc hl
	ld d, (hl)
	ld (stage.loader), de
	inc hl
	ld e, (hl)
	inc hl
	ld d, (hl)
	ex de, hl
	call gameplayMapsEngine.loadPalette
	
.endm

.section "stageSelection" free
stageSelection:
	call turnOffVdp
	ld a, 16
	out (VdpControlPort), a
	ld a, CramWrite.hi
	out (VdpControlPort), a
	xor a
	out (VdpDataPort), a
	
	ld a, :stageSelectionTiles
	ld (MapperSlot2), a
	decompress stageSelectionTiles, 0, stageSelectionTilesCount
	decompress bossFacesTiles, 256*32, bossFacesTilesCount
	stageSelection.loadMap
	
	ld hl, PositionFirstFace
	ld a, (bossesBeaten)
	ld d, FirstTileFacePosition
		; bf  ol  bf
	ld c, 3 + 1 + 2 ;this counter have two functions, when hit zero for the first time,
					;it´s time to place the willy logo instead a boss face.
					;ol: outer loop, bf: boss faces
----:	ld b, 3
---:	dec c
		jr z, +		;Write Wily logo and re-value the counter
		rra
		jr nc, ++	;Write boss face
			ld e, a
			ld a, 16
			add a, d
			ld d, a
			ld a, e
			inc h
			push bc
		jr +++
			    ; bf  ol  bf  ol
+:			ld c, 1 + 1 + 3 + 1 ; when hits zero for the second time, it´s to exit the loop
++:			push bc
			stageSelection.loadBossFace
+++:		ld bc, -240
			add hl, bc
			pop bc
		djnz ---
		push bc
		ld bc, $1d0
		add hl, bc
		pop bc
		dec c
	jr nz, ----	
	
	;loads quick man horn
	ld a, (bossesBeaten)
	and QuickMan
	jr nz, +  
		ld a, <QuickManHornLocation
		out (VdpControlPort), a
		ld a, >QuickManHornLocation
		out (VdpControlPort), a
		ld a, 1
		out (VdpDataPort), a
		dec a
		out (VdpDataPort), a
+:	mapPage2 :stageSelection.text 
	ld hl, stageSelection.text
	call loadPassiveText
	
	mapPage2 :stageSelection.palette
	ld hl, stageSelection.palette
	call gameplayMapsEngine.loadPalette
	
	; loads cursor start position
	call clearObjectTable
	ld hl, miscObjectTable.2.y
	ld a, 64
	ld (hl), a
	ld l, <miscObjectTable.2.x
	ld (hl), a
	
	ld a, :stageSelectMusic
	ld hl, stageSelectMusic
	call PSGPlay
	
	call turnOnVdp
	mapPage2 :miscObjects
backToLoop:
-:		call verticalObjectsToSprites
		call prepareForVblank
		ld a, StartKey | BKey
		and (hl) ; hl: pressedKeys
		jr nz, ++
		ld a, UKey | DKey | LKey | RKey
		and (hl)
		ld d, >stageSelection.cursorPosition
		ld b, 4
		call updateCursorPosition
		ld a, (frameCounter)
		ld l, <miscObjectTable.2.frame
		and $08
		ld a, miscObject.stageSelection.cursor
		jr z, +
			xor a
+:		ld (hl), a
	jr backToLoop
++:	

	stageSelection.cursorPostionToAddress backToLoop
	ld a, (bossesBeaten)
	and (hl)
	jr nz, backToLoop
	
	blinkScreenLoadingBossStuff
	ret

.ends

.endif


