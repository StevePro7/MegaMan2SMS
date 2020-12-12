.slot 2
.section "woodmanStage.tiles" superfree
woodmanStage.tiles:
	.incbin "imagens\woodmanstage.psgcompr" skip 2
.ends

.slot 2
.section "woodmanStage.metaTiles" superfree
woodmanStage.metaTiles:
	.dw $0136
	.db $00 $AF $01 $E7 $FF $17 $FE $35 $FD $6A $02 $B3 $BC $F3 $FC $3F
	.db $09 $FB $3F $B8 $21 $F8 $9F $ED $91 $F7 $3F $F6 $3F $B0 $22 $F0
	.db $7E $F3 $7E $F2 $3D $F1 $01 $6C $04 $1D $C9 $FC $EF $A5 $02 $9F
	.db $EB $9B $EE $09 $33 $54 $EC $0D $EA $3F $05 $E8 $3F $E9 $3F $E6
	.db $76 $87 $D6 $45 $E7 $B0 $C0 $00
.ends

.slot 2
.section "woodmanStage.maps" free
woodmanStage.maps:
woodmanStage.map.0:
	.db $00 $A8 $01 $01 $02 $E2 $03 $08 $04 $05 $06 $07 $38 $56 $11 $33
	.db $08 $21 $09 $70 $02 $8C $1C $0A $03 $0B $54 $0C $20 $B6 $20 $56
	.db $04 $20 $8D $0D $03 $1A $20 $CA $0E $40 $51 $0F $BF $03 $AB $02
	.db $20 $4D $DE $A3 $20 $80 $45 $0A $0A $90 $10 $20 $73 $65 $21 $82
	.db $0C $3C $20 $08 $8D $95 $0D $80 $E2 $0A $B6 $60 $D1 $20 $C0 $A4
	.db $68 $80 $11 $A5 $EF $A2 $1F $E6 $12 $AE $91 $86 $7F $E6 $12 $A5
	.db $61 $21 $20 $C2 $0A $03 $3C $D0 $A2 $60 $C8 $12 $E4 $08 $72 $12
	.db $BE $E0 $47 $12 $C8 $12 $F9 $12 $22 $80 $D1 $80 $AA $46 $C0 $24
	.db $13 $5F $48 $80 $4A $5F $CE $6A $14 $FF $53 $47 $3F $40 $2B $0A
	.db $1F $BA $49 $BE $E7 $3E $91 $E7 $3E $91 $DA $21 $14 $20 $87 $BE
	.db $34 $40 $29 $DF $A1 $C0 $40 $C8 $60 $FC $23 $02 $03 $C8 $40 $52
	.db $08 $BC $0F $21 $40 $EA $1D $68 $60 $5B $47 $21 $A0 $94 $5E $D5
	.db $C0 $46 $A0 $DA $43 $14 $A0 $D0 $FF $81 $B4 $37 $20 $24 $03 $69
	.db $A9 $21 $40 $4A $BE $C8 $81 $A1 $20 $65 $01 $3D $81 $5A $CF $26
	.db $09 $C0 $79 $10 $1F $69 $42 $3D $A0 $CD $02 $32 $20 $E7 $1B $3C
	.db $80 $D3 $E3 $7E $80 $11 $02 $03 $E6 $20 $9B $00 $C8 $E1 $23 $80
	.db $D3 $4D $C0 $E0 $AA $41 $A0 $1B $60 $2B $10 $C0 $E9 $95 $C0 $11
	.db $03 $F9 $C5 $03 $1E $4C $51 $8C $15 $03 $09 $8F $91 $07 $F4 $3B
	.db $20 $A0 $16 $17 $18 $A6 $01 $84 $16 $84 $10 $84 $90 $87 $20 $14
	.db $06 $40 $A4 $4A $11 $06 $60 $52 $0F $10 $F5 $60 $D0 $2F $D1 $60
	.db $DA $BF $34 $40 $85 $21 $20 $64 $E9 $E7 $47 $9F $40 $6D $19 $21
	.db $0A $40 $43 $9C $90 $40 $90 $10 $B5 $2A $00 $F4 $29 $5A $09 $01
	.db $14 $8E $67 $7B $4A $80 $F2 $12 $24 $16 $7F $85 $80 $34 $24 $69
	.db $A0 $0A $20 $90 $42 $F4 $34 $FD $2A $C0 $43 $FF $90 $20 $B4 $65
	.db $84 $79 $7E $5A $00 $42 $20 $57 $5E $95 $60 $A6 $81 $AD $A0 $B5
	.db $41 $6D $C0 $1E $20 $B6 $1C $8D $80 $ED $1F $1E $C0 $DA $43 $17
	.db $C0 $B5 $3D $6C $60 $06 $93 $80 $E8 $20 $D4 $AF $80 $B8 $D6 $62
	.db $9A $24 $BC $62 $85 $20 $C8 $A0 $FB $46 $3F $A0 $D0 $FE $F6 $80
	.db $AF $1E $21 $20 $73 $47 $7C $C0 $B5 $6D $3E $FB $FC $79 $0B $E0
	.db $D5 $1E $B6 $9C $8D $5E $22 $6E $8D $20 $F7 $97 $15 $65 $21 $CF
	.db $00 $F9 $DA $ED $00 $35 $02 $8F $05 $4D $BF $F6 $80 $93 $E1 $E4
	.db $07 $7D $72 $00 $E9 $22 $A0 $A9 $73 $60 $B7 $29 $6D $20 $7B $00
	.db $00
woodmanStage.map.1:
	.db $07 $AD $01 $91 $09 $F4 $3B $20 $0C $16 $17 $18 $02 $15 $8A $1A
	.db $17 $25 $10 $06 $6C $20 $06 $D0 $81 $20 $AF $47 $1E $7E $FF $1E
	.db $43 $20 $A9 $A1 $3D $20 $ED $3D $0B $20 $F7 $F6 $19 $02 $74 $1A
	.db $70 $1B $84 $83 $1E $FD $50 $10 $11 $9A $3F $33 $10 $BA $1C $28
	.db $1F $68 $10 $ED $3D $18 $10 $1D $AA $40 $3B $10 $43 $1F $20 $CE
	.db $1C $11 $E4 $27 $10 $EA $01 $CD $5E $0F $10 $7F $E1 $1A $68 $5D
	.db $10 $F6 $47 $1B $DE $11 $1B $F7 $94 $1B $7D $E9 $1B $1F $7B $47
	.db $1C $AD $0E $84 $43 $10 $9F $11 $1B $F2 $1D $3C $FF $C2 $3C $47
	.db $1C $F4 $3F $60 $A5 $64 $73 $6D $0F $A9 $21 $B0 $F2 $11 $10 $0F
	.db $C6 $BC $9E $E1 $C2 $3C $87 $10 $BD $A3 $1B $E8 $C0 $5B $ED $62
	.db $16 $1C $B5 $10 $E9 $09 $DC $3B $55 $42 $A2 $10 $48 $DA $D0 $11
	.db $90 $20 $91 $01 $47 $26 $2C $06 $E0 $D2 $67 $1C $A6 $20 $6D $21
	.db $0F $20 $FE $29 $15 $01 $6B $37 $E0 $E8 $20 $72 $C6 $6E $E7 $77
	.db $F0 $68 $27 $10 $E8 $88 $48 $1E $52 $CE $E0 $87 $10 $23 $20 $D5
	.db $A3 $F6 $35 $41 $DB $80 $57 $00 $AD $05 $4E $2A $80 $9C $51 $06
	.db $E6 $23 $8D $20 $34 $45 $69 $20 $A3 $45 $20 $4D $45 $1A $20 $68
	.db $23 $20 $D2 $0A $22 $00 $FE $AE $A0 $AD $E0 $52 $3D $20 $23 $60
	.db $C8 $80 $DB $EF $09 $3C $80 $D1 $20 $C0 $E4 $39 $20 $14 $BF $3A
	.db $20 $DA $3D $1E $20 $D0 $3D $20 $BD $5E $A0 $68 $40 $BE $F3 $47
	.db $80 $DE $91 $20 $F9 $23 $00 $E7 $0E $01 $01 $02 $03 $0B $C5 $0C
	.db $44 $68 $A3 $56 $33 $0A $20 $04 $8A $05 $92 $84 $19 $10 $0D $44
	.db $01 $6B $20 $42 $40 $CC $0F $03 $0E $AD $20 $34 $3E $26 $10 $81
	.db $8C $10 $E4 $10 $AD $20 $32 $83 $0C $9E $20 $46 $08 $8A $0D $80
	.db $F0 $0A $02 $8F $1A $0E $61 $1E $C0 $FF $54 $3F $29 $20 $06 $DE
	.db $5E $84 $7E $86 $40 $8A $EF $12 $1E $1C $60 $D0 $41 $60 $A4 $68
	.db $20 $0E $A5 $9E $23 $E0 $32 $C1 $08 $96 $20 $85 $7E $A0 $20 $52
	.db $0A $7E $DA $40 $3B $6E $46 $36 $60 $42 $5E $DA $40 $34 $7E $85
	.db $20 $E8 $7E $5A $19 $60 $08 $5A $40 $52 $7C $43 $40 $9A $7E $3D
	.db $60 $08 $03 $04 $F2 $08 $10 $60 $79 $10 $1B $45 $C0 $1A $60 $41
	.db $80 $1E $C0 $E3 $0F $8F $F8 $F3 $72 $DF $AD $C0 $21 $DF $23 $C0
	.db $48 $6E $21 $A0 $E6 $1E $02 $7F $1F $A5 $20 $82 $20 $21 $22 $23
	.db $34 $06 $20 $24 $25 $23 $26 $03 $4A $06 $79 $E0 $68 $20 $E5 $9B
	.db $C2 $46 $20 $EB $95 $00 $F9 $A5 $1E $3D $80 $25 $BE $00 $8A $41
	.db $59 $00 $C8 $40 $F2 $09 $1F $4D $C0 $E8 $20 $FE $D0 $23 $20 $EE
	.db $42 $A0 $AD $1A $01 $60 $00
woodmanStage.map.2:
	.db $07 $AD $01 $91 $09 $F6 $27 $14 $16 $17 $18 $01 $88 $15 $B4 $27
	.db $73 $10 $06 $42 $41 $1E $9A $21 $08 $40 $10 $72 $3D $20 $59 $15
	.db $54 $01 $2D $20 $0A $E0 $E4 $6F $20 $40 $4E $06 $A7 $20 $32 $E1
	.db $06 $9C $40 $84 $80 $56 $06 $20 $9A $F5 $34 $20 $D1 $45 $20 $A6
	.db $45 $8D $20 $34 $45 $69 $20 $A3 $45 $20 $48 $22 $2B $00 $FA $BA
	.db $A0 $1F $E0 $68 $20 $FE $8F $60 $23 $80 $6F $BC $24 $80 $F3 $47
	.db $20 $C0 $90 $20 $E4 $50 $BF $20 $EB $68 $3D $20 $7B $42 $3D $20
	.db $F5 $79 $A0 $A3 $40 $BE $CD $80 $1E $DE $47 $20 $E4 $8F $00 $9C
	.db $38 $07 $01 $02 $03 $0B $15 $0C $1C $68 $2A $01 $67 $0A $20 $04
	.db $15 $05 $24 $84 $32 $10 $0D $88 $01 $20 $D6 $85 $40 $99 $0F $03
	.db $0E $5A $20 $68 $3E $10 $4D $81 $19 $10 $C9 $10 $5A $20 $65 $83
	.db $0C $3C $20 $08 $8D $15 $0D $80 $E1 $0A $02 $1E $34 $0E $61 $3D
	.db $C0 $FE $A8 $3F $20 $52 $0D $DE $5E $09 $7E $0D $40 $14 $EF $24
	.db $1E $39 $60 $A1 $41 $60 $48 $20 $D1 $0E $4A $9E $46 $E0 $65 $C1
	.db $08 $2D $20 $0B $7E $40 $20 $0A $A5 $7E $B4 $40 $76 $6E $36 $8C
	.db $60 $85 $5E $B4 $40 $69 $7E $0B $20 $D0 $7E $B4 $32 $60 $08 $B4
	.db $40 $A4 $7C $87 $40 $34 $7E $7A $60 $11 $03 $04 $E4 $10 $10 $60
	.db $F2 $10 $36 $8A $C0 $34 $60 $82 $80 $3D $C0 $C7 $0F $1F $F1 $E6
	.db $DF $E5 $5A $C0 $42 $DF $46 $C0 $90 $6E $43 $A0 $CC $1E $02 $1F
	.db $FF $4B $20 $04 $20 $21 $22 $23 $68 $20 $0C $24 $25 $23 $26 $03
	.db $06 $94 $E0 $F1 $06 $63 $00 $96 $6D $C2 $1B $20 $AE $57 $00 $E6
	.db $1E $94 $80 $F4 $96 $00 $FA $29 $41 $67 $00 $23 $40 $C8 $1F $25
	.db $37 $C0 $A3 $20 $FB $43 $23 $20 $B9 $0A $A0 $B4 $69 $01 $80 $00
.ends


.slot 2
.section "woodmanStage.transitions" superfree
woodmanStage.stageLoader:	
	.db :woodmanStage.tiles
	.db 130
	.dw woodmanStage.tiles

	.db :woodmanMusic
	.dw woodmanMusic
	
	.db :woodmanStage.metaTiles
	.dw woodmanStage.metaTiles

	;collision table
	.db $00 $A9 $01 $80 $C7 $70 $06 $A5 $01 $1A $40 $1B $2F $11 $14 $01
	.db $DC $30 $00
	
	.db :woodmanStage.maps
	
woodmanStage.transition.0:
	.db LoadNewPaletteFlag | CheckpointFlag | EndingTransitionsFlag | LoadGameplayMapFlag
	
	;megaman checkpoint position
	.db $b4		
	
	;palette
	.db $00 $08 $02 $07 $0d $3D $1B $01 $06  
	.db $0b | PaletteEndingMark
	
	configureNextTransitions TransitB, woodmanStage.transition.1
	
	;new map to load
	.dw woodmanStage.map.0
	
	configureMapLimits OrientationFoward, OrientationHor, 0, 5

woodmanStage.transition.0.back:	;go back to the first map
	.db EndingTransitionsFlag
	
	configureNextTransitions TransitB, woodmanStage.transition.1
	configureMapLimits OrientationBackward, OrientationHor, 0, 5

	
woodmanStage.transition.1:
	.db BeginningTransitionsFlag | EndingTransitionsFlag  
	
	configureNextTransitions TransitT, woodmanStage.transition.0.back
	configureNextTransitions TransitR, woodmanStage.transition.4
	configureMapLimits OrientationFoward, OrientationVert, 5, 2
	

woodmanStage.transition.4:
	.db EndingTransitionsFlag
	
	configureNextTransitions TransitR, woodmanStage.transition.5
	configureMapLimits OrientationFoward, OrientationHor, 7, 1
	
woodmanStage.transition.5:
	.db EndingTransitionsFlag
	
	configureNextTransitions TransitR, woodmanStage.transition.6
	configureMapLimits OrientationFoward, OrientationHor, 8, 1

woodmanStage.transition.6:
	.db BeginningTransitionsFlag
	
	configureNextTransitions TransitT, woodmanStage.transition.7
	configureMapLimits OrientationFoward, OrientationHor, 9, 1

woodmanStage.transition.7:
	.db LoadGameplayMapFlag | BeginningTransitionsFlag | EndingTransitionsFlag
	
	configureNextTransitions TransitT, woodmanStage.transition.8
	configureNextTransitions TransitB, woodmanStage.transition.6
	
	;map to load
	.dw woodmanStage.map.0
	
	configureMapLimits OrientationFoward, OrientationHor, 10, 1

woodmanStage.transition.8:
	.db LoadGameplayMapFlag | BeginningTransitionsFlag | EndingTransitionsFlag
	
	configureNextTransitions TransitB, woodmanStage.transition.7
	configureNextTransitions TransitB, woodmanStage.transition.9
	
	;map to load
	.dw woodmanStage.map.1
	
	configureMapLimits OrientationFoward, OrientationHor, 0, 5

woodmanStage.transition.8.back:		;transition 8 backwards
	.db BeginningTransitionsFlag | EndingTransitionsFlag
	
	configureNextTransitions TransitB, woodmanStage.transition.7
	configureNextTransitions TransitB, woodmanStage.transition.9
	configureMapLimits OrientationBackward, OrientationHor, 0, 5	

woodmanStage.transition.9:
	.db BeginningTransitionsFlag | EndingTransitionsFlag
	
	configureNextTransitions TransitT, woodmanStage.transition.8.back
	configureNextTransitions TransitB, woodmanStage.transition.11
	
	configureMapLimits OrientationFoward, OrientationVert, 5, 3	

woodmanStage.transition.9.back: ;transiotion 9 backwars
	.db BeginningTransitionsFlag | EndingTransitionsFlag
	
	configureNextTransitions TransitT, woodmanStage.transition.8.back
	configureNextTransitions TransitB, woodmanStage.transition.11
	
	configureMapLimits OrientationBackward, OrientationVert, 5, 3	

	
woodmanStage.transition.11:
	.db BeginningTransitionsFlag | EndingTransitionsFlag
	
	configureNextTransitions TransitT, woodmanStage.transition.9.back
	configureNextTransitions TransitR, woodmanStage.transition.13
	
	configureMapLimits OrientationFoward, OrientationHor, 8, 3	

woodmanStage.transition.13:
	.db EndingTransitionsFlag
	
	configureNextTransitions TransitR, woodmanStage.transition.14
	configureMapLimits OrientationFoward, OrientationHor, 11, 1		
	
woodmanStage.transition.14:
	.db LoadNewPaletteFlag
	
woodmanPalette:	
	.db PaletteNewAddressMark | 24
	.db $1b $0e
	.db PaletteEndingMark | $06
	
	configureMapLimits OrientationFoward, OrientationHor, 12, 1	
.ends
