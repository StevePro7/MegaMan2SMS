.slot 2
.section "heatmanStage.tiles" superfree
heatmanStage.tiles:
	.incbin "imagens\heatmanstage.psgcompr" skip 2
.ends

.slot 2
.section "heatmanStage.metaTiles" superfree
heatmanStage.metaTiles:
	.dw $0113
	.db $00 $A5 $01 $E2 $FE $FF $15 $CC $48 $FD $FE $FC $A7 $02 $56 $7E
	.db $C7 $65 $FB $09 $FA $2B $02 $11 $F8 $01 $7E $8D $F1 $D6 $F9 $F7
	.db $95 $09 $F6 $02 $F3 $93 $F3 $F5 $29 $09 $F4 $02 $67 $F3 $E1 $F2
	.db $01 $F1 $07 $E8 $FC $7E $ED $65 $F0 $09 $EF $3A $02 $C8 $EE $B2
	.db $64 $84 $BE $02 $7E $4F $65 $83 $09 $44 $4F $02 $42 $C8 $47 $EC
	.db $00
.ends

.slot 2
.section "heatmanStage.maps" superfree
heatmanStage.maps:
heatmanStage.map.0:
	.db $00 $AE $01 $07 $01 $02 $03 $04 $05 $0A $10 $71 $06 $10 $07 $08
	.db $09 $18 $0A $0B $0C $02 $0D $0E $0A $0F $10 $11 $12 $10 $DE $D1
	.db $81 $10 $A2 $06 $3E $DF $40 $BF $C7 $9A $20 $34 $50 $85 $10 $48
	.db $87 $23 $40 $4E $08 $01 $F3 $43 $20 $30 $F4 $3E $40 $C2 $13 $14
	.db $03 $B6 $10 $8F $20 $48 $80 $55 $A1 $E0 $52 $9D $00 $A1 $80 $77
	.db $B4 $C0 $2F $90 $56 $60 $F5 $6A $00 $A5 $2E $80 $D5 $20 $BD $0A
	.db $40 $26 $15 $00 $5D $B4 $40 $6E $90 $29 $15 $20 $52 $15 $E0 $68
	.db $D0 $FE $85 $40 $10 $15 $BC $16 $65 $17 $02 $06 $6D $10 $1B $80
	.db $88 $15 $74 $56 $17 $A0 $F1 $18 $17 $5B $60 $68 $61 $60 $D1 $15
	.db $A1 $60 $40 $F4 $93 $00 $79 $15 $0B $CA $19 $40 $75 $A1 $70 $A1
	.db $60 $DE $A5 $A0 $4D $E1 $4F $C0 $B4 $38 $A0 $15 $D0 $20 $60 $FB
	.db $D1 $C0 $AA $94 $A0 $BA $C2 $1A $1B $1C $34 $3F $1D $1E $58 $70
	.db $F6 $60 $8D $10 $08 $0E $13 $F6 $90 $D0 $85 $10 $A8 $DE $8F $30
	.db $E8 $10 $55 $24 $C0 $21 $70 $7E $FF $FE $37 $42 $1F $04 $95 $10
	.db $A4 $A0 $51 $20 $43 $10 $05 $87 $08 $74 $7D $21 $8E $D0 $61 $10
	.db $ED $C5 $0D $1B $D5 $60 $96 $50 $3F $10 $F9 $A3 $9C $10 $DA $2F
	.db $89 $15 $10 $AD $1D $D0 $2C $8F $70 $93 $E0 $46 $22 $03 $E1 $1F
	.db $F5 $22 $30 $22 $96 $01 $C5 $21 $23 $05 $6D $20 $4B $70 $69 $33
	.db $36 $50 $56 $05 $20 $B4 $2B $30 $B7 $04 $01 $79 $0E $AA $41 $20
	.db $0A $E0 $E6 $00
heatmanStage.map.1:
	.db $00 $AF $01 $67 $22 $10 $09 $0A $0B $0C $80 $0D $0E $1C $13 $1F
	.db $05 $22 $52 $01 $10 $AA $CA $15 $40 $7F $94 $15 $A0 $FF $C6 $18
	.db $17 $03 $8C $10 $52 $15 $20 $0D $1D $1E $07 $02 $0B $30 $47 $10
	.db $90 $40 $7E $AD $70 $71 $21 $A1 $DB $70 $C4 $0B $3B $90 $60 $FC
	.db $15 $91 $50 $F7 $90 $15 $BE $43 $C0 $E9 $54 $70 $7F $70 $D0 $10
	.db $FE $43 $A0 $AD $49 $A0 $B4 $20 $08 $6F $70 $94 $30 $AF $D0 $10
	.db $E5 $55 $30 $00 $BB $90 $60 $BB $B4 $2F $10 $10 $07 $08 $BE $11
	.db $16 $20 $FB $3E $18 $21 $01 $FD $A2 $D0 $85 $10 $7F $C0 $0F $10
	.db $11 $12 $FD $FE $1C $08 $13 $14 $06 $04 $F1 $03 $1F $46 $20 $BF
	.db $A5 $2E $D0 $08 $1A $1B $1C $D2 $C4 $40 $85 $10 $DD $CB $37 $00
	.db $54 $37 $1D $22 $03 $08 $FE $C0 $00
heatmanStage.map.2:
	.db $01 $0E $10 $11 $12 $05 $14 $01 $7A $1A $02 $03 $04 $14 $1C $10
	.db $42 $06 $68 $2D $10 $68 $1A $A0 $16 $30 $0B $0C $02 $0D $0E $13
	.db $42 $22 $68 $41 $10 $65 $0F $6D $20 $0D $10 $A1 $0D $10 $B4 $C1
	.db $68 $10 $06 $8F $33 $15 $07 $8D $69 $20 $A1 $20 $60 $6D $15 $A1
	.db $20 $60 $68 $20 $A3 $60 $4C $20 $22 $A5 $01 $23 $20 $A1 $C0 $C8
	.db $10 $54 $E1 $4F $01 $B6 $B1 $54 $0A $70 $19 $53 $05 $12 $2B $01
	.db $10 $DE $10 $07 $08 $09 $BE $CA $24 $01 $14 $25 $10 $A3 $26 $88
	.db $27 $28 $29 $46 $2A $C1 $2B $2C $2A $2D $A1 $03 $40 $B7 $03 $A5
	.db $01 $5D $20 $A8 $0C $8F $10 $5D $29 $00 $B4 $21 $9D $00 $09 $20
	.db $C0 $2E $2F $6F $30 $20 $92 $74 $50 $80 $E0 $1F $31 $06 $53 $32
	.db $10 $D2 $50 $61 $10 $F4 $94 $41 $6F $10 $49 $81 $46 $40 $F4 $7F
	.db $20 $91 $80 $BB $42 $01 $D0 $30 $60 $00
.ends

.slot 2
.section "heatmanStage.transitions" superfree
heatmanStage.stageLoader:	
	.db :heatmanStage.tiles
	.db 165
	.dw heatmanStage.tiles

	.db :heatmanMusic
	.dw heatmanMusic	
	
	.db :heatmanStage.metaTiles
	.dw heatmanStage.metaTiles
	
	;collision table
	.db $80 $DC $02 $34 $07 $77 $01 $FA $0D $48 $12 $EC $12 $40 $D0 $28
	.db $01 $9A $18 $13 $0A $00 $00
	
	.db :heatmanStage.maps
	
heatmanStage.transition.0:
	.db LoadNewPaletteFlag | CheckpointFlag | EndingTransitionsFlag | LoadGameplayMapFlag
	
	;megaman checkpoint position
	.db $A4		
	
	;palette
	.db $00 $02 $3F $2b $07 $17 $13 $03 $2A $15 
	;paletteAnimation
	paletteAnimationSetUp 7, 3, 3	
	.db $2b $03 $07
	.db $07 $2b $03 
	.db $03 $07 $2b 
	.db PaletteNewAddressMark | 16
	.db $03 | PaletteEndingMark
	
	
	configureNextTransitions TransitB, heatmanStage.transition.1

	;new map to load
	.dw heatmanStage.map.0

	configureMapLimits OrientationFoward, OrientationHor, 0, 8 
		
heatmanStage.transition.0.back:
	.db EndingTransitionsFlag
	
	configureNextTransitions TransitB, heatmanStage.transition.1
	configureMapLimits OrientationBackward, OrientationHor, 0, 8 
				
heatmanStage.transition.1:
	.db BeginningTransitionsFlag | EndingTransitionsFlag | LoadGameplayMapFlag
	
	configureNextTransitions TransitT, heatmanStage.transition.0.back
	configureNextTransitions TransitB, heatmanStage.transition.2
	
	;new map to load
	.dw heatmanStage.map.0

	configureMapLimits OrientationFoward, OrientationHor, 8, 1 

heatmanStage.transition.2
	.db CheckpointFlag | BeginningTransitionsFlag | EndingTransitionsFlag | LoadGameplayMapFlag
	
	;megaman checkpoint position
	.db $74	
	
	configureNextTransitions TransitT, heatmanStage.transition.1
	configureNextTransitions TransitB, heatmanStage.transition.3
	
	;new map to load
	.dw heatmanStage.map.1
	
	configureMapLimits OrientationFoward, OrientationHor, 0, 11 

heatmanStage.transition.2.back
	.db EndingTransitionsFlag | LoadGameplayMapFlag
	
	configureNextTransitions TransitB, heatmanStage.transition.3
	
	;new map to load
	.dw heatmanStage.map.1
	
	configureMapLimits OrientationBackward, OrientationHor, 0, 11 
	
	
heatmanStage.transition.3
	.db EndingTransitionsFlag | BeginningTransitionsFlag | LoadGameplayMapFlag 
	
	configureNextTransitions TransitT, heatmanStage.transition.2.back
	configureNextTransitions TransitR, heatmanStage.transition.4
	
	;new map to load
	.dw heatmanStage.map.2
	
	configureMapLimits OrientationFoward, OrientationVert, 0, 2 

heatmanStage.transition.4
	.db EndingTransitionsFlag 
	
	configureNextTransitions TransitR, heatmanStage.transition.5
	configureMapLimits OrientationFoward, OrientationVert, 2, 1 
	
	
	
heatmanStage.transition.5:
	.db LoadNewPaletteFlag
heatmanPalette:
	.db PaletteNewAddressMark | 24
	.db $2F $13 $0B
	.db PaletteEndingMark | $1b
	
	configureMapLimits OrientationFoward, OrientationHor, 3, 1 
		
.ends
