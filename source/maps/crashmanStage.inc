.slot 2
.section "crashmanStage.tiles" superfree
crashmanStage.tiles:
	.incbin "imagens\crashmanstage.psgcompr" skip 2
.ends

.slot 2
.section "crashmanStage.metaTiles" superfree
crashmanStage.metaTiles:
	.dw $012e
	.db $00 $A6 $01 $32 $FC $FF $04 $FE $3E $7E $FA $47 $FD $CF $EE $C8
	.db $FC $90 $FA $EC $E8 $FC $F9 $89 $E5 $F9 $E4 $F9 $F6 $F9 $F5 $13
	.db $E3 $F3 $F2 $F2 $F3 $19 $ED $12 $F1 $3E $7E $E2 $66 $D0 $59 $EE
	.db $05 $CF $38 $EC $CA $EB $02 $E7 $DB $E7 $C7 $E7 $D9 $E7 $C5 $E7
	.db $E7 $E6 $E6 $40 $39 $01 $E4 $3F $D3 $3F $BF $3F $CD $3F $CF $3F
	.db $CA $36 $B9 $11 $08 $68 $A8 $44 $02 $88 $D5 $01 $34 $50 $28 $02
	.db $D6 $DF $24 $99 $D7 $0D $D2 $A2 $10 $02 $CC $64 $D3 $61 $D1 $D9
	.db $05 $14 $CB $A1 $08 $02 $64 $CE $4C $CD $AD $CC $CD $05 $BE $39
	.db $9F $B4 $C9 $95 $C8 $02 $66 $EC $C7 $05 $7E $C2 $45 $C6 $BF $40
	.db $54 $02 $7D $89 $8E $F9 $C2 $1C $B4 $FC $C1 $FC $C0 $CA $39 $BE
	.db $02 $9F $BB $91 $BD $3F $BA $33 $B7 $15 $B5 $14 $11 $B9 $05 $A0
	.db $3F $B1 $37 $B8 $20 $8D $24 $03 $02 $AB $F3 $B6 $F3 $A9 $1A $35
	.db $B4 $05 $70 $15 $02 $51 $B3 $13 $B2 $F6 $00
.ends

.slot 2
.section "crashmanStage.maps" superfree
crashmanStage.maps:
crashmanStage.map.0:
	.db $00 $03 $01 $02 $03 $04 $05 $06 $99 $07 $08 $9E $10 $09 $BE $B8
	.db $0A $9C $0B $0C $33 $06 $06 $81 $0D $0E $9C $10 $0F $38 $7F $54
	.db $10 $01 $11 $A9 $06 $12 $0D $0A $01 $47 $10 $8A $13 $01 $E8 $20
	.db $53 $42 $BA $20 $8A $14 $14 $0A $0C $0A $12 $15 $15 $14 $90 $80
	.db $1A $0A $16 $77 $3B $35 $14 $1C $0F $0B $5B $E1 $04 $0C $44 $9A
	.db $34 $3B $45 $01 $03 $02 $1F $9A $D4 $17 $54 $A6 $80 $C8 $C5 $06
	.db $65 $17 $26 $40 $C4 $2A $04 $06 $64 $ED $49 $40 $06 $E1 $21 $51
	.db $03 $D9 $02 $16 $0F $8F $E5 $DB $64 $87 $AA $DA $36 $16 $0C $CE
	.db $58 $05 $12 $26 $00 $C4 $AC $00 $82 $2C $93 $00 $56 $C4 $00 $41
	.db $2C $A3 $CD $4B $3D $C1 $AB $44 $10 $43 $09 $16 $42 $44 $B9 $42
	.db $CD $8D $0F $9B $5A $18 $34 $05 $81 $39 $10 $19 $40 $4A $23 $41
	.db $40 $4A $18 $2B $15 $40 $12 $17 $39 $3C $12 $40 $06 $94 $10 $D0
	.db $80 $C8 $6A $20 $6C $73 $68 $80 $64 $10 $14 $17 $20 $D1 $40 $6E
	.db $21 $74 $40 $B4 $10 $F6 $EA $6F $07 $52 $5B $06 $3F $41 $80 $F6
	.db $B4 $0C $06 $26 $F8 $1D $D0 $81 $14 $45 $F8 $EF $51 $10 $02 $21
	.db $08 $A0 $10 $14 $8A $F8 $4A $08 $8A $02 $0B $BF $ED $39 $8D $4E
	.db $C5 $68 $38 $38 $12 $0B $3D $80 $06 $40 $40 $A5 $D4 $21 $40 $14
	.db $12 $E7 $B4 $22 $40 $16 $11 $0F $22 $80 $9A $B8 $24 $40 $05 $99
	.db $80 $BB $F0 $C9 $2F $D4 $80 $DF $74 $F0 $37 $5E $EA $2C $29 $C0
	.db $A9 $5F $6D $D8 $05 $14 $72 $50 $05 $94 $C0 $84 $40 $78 $09 $8C
	.db $CA $28 $0B $2F $68 $40 $D0 $12 $0F $D0 $D4 $40 $E6 $32 $D0 $D4
	.db $40 $AE $42 $FC $8A $12 $80 $EA $CE $72 $32 $80 $3B $BE $DF $EA
	.db $40 $68 $BE $52 $36 $40 $D0 $FD $40 $90 $20 $CD $05 $FC $08 $40
	.db $04 $A6 $6E $8C $40 $4D $12 $3C $D0 $40 $DE $53 $16 $2D $5C $05
	.db $40 $1C $94 $A6 $5C $5A $09 $40 $14 $4C $71 $12 $DB $38 $C4 $6D
	.db $48 $82 $04 $46 $67 $0A $55 $0B $AF $AB $C4 $00 $2B $E4 $BC $48
	.db $40 $A5 $74 $E4 $53 $08 $3D $9F $15 $D2 $18 $9F $BD $18 $19 $C9
	.db $02 $1A $B1 $E0 $0C $43 $60 $1B $32 $23 $1C $2C $1A $46 $D1 $CD
	.db $41 $1B $22 $F3 $68 $04 $0C $94 $36 $DD $4F $FF $48 $01 $1D $4D
	.db $1E $E0 $7F $A5 $10 $32 $40 $09 $98 $CC $18 $1C $68 $1F $05 $10
	.db $32 $DC $16 $28 $4F $36 $A3 $21 $48 $05 $0C $DE $4A $1F $1A $50
	.db $68 $40 $4D $10 $19 $30 $09 $40 $16 $6E $8A $85 $40 $3D $51 $20
	.db $F7 $46 $E1 $40 $29 $19 $51 $21 $40 $A1 $0F $21 $B3 $35 $80 $9E
	.db $A2 $68 $81 $10 $7A $0A $40 $00 $D2 $4B $02 $F2 $0B $9E $30 $FD
	.db $49 $F4 $52 $11 $1A $6E $02 $84 $20 $DC $D4 $A4 $30 $ED $C1 $0B
	.db $10 $65 $80 $16 $3D $10 $26 $4A $68 $7C $AD $A2 $44 $D1 $80 $E0
	.db $90 $22 $90 $B0 $90 $4E $90 $22 $90 $D0 $45 $80 $0D $1C $09 $12
	.db $95 $80 $12 $2C $DA $11 $39 $40 $1F $BF $3D $E8 $61 $80 $A1 $50
	.db $A1 $76 $28 $AE $D5 $04 $00 $A5 $CB $8A $48 $C2 $A5 $C5 $18 $6D
	.db $F0 $21 $02 $5E $20 $11 $01 $02 $E5 $98 $C0 $18 $A9 $50 $1A $76
	.db $80 $47 $72 $6B $0C $1A $80 $3A $10 $08 $90 $40 $C8 $20 $C8 $40
	.db $C8 $10 $C8 $40 $F4 $ED $EE $3C $21 $1D $1E $74 $43 $04 $D2 $9D
	.db $7D $27 $11 $48 $A0 $D2 $79 $E0 $A4 $80 $12 $D2 $02 $40 $20 $21
	.db $07 $22 $5D $02 $DE $CE $00 $F7 $4C $11 $23 $B3 $00 $A1 $0A $1F
	.db $22 $EE $D1 $53 $53 $1E $30 $DB $C1 $56 $72 $40 $99 $DC $20 $4B
	.db $11 $41 $C0 $BF $DC $D2 $11 $D9 $C0 $16 $EF $42 $20 $42 $99 $C0
	.db $0B $EF $47 $1F $40 $B3 $23 $FC $6D $A1 $1F $40 $E8 $80 $54 $7F
	.db $23 $8D $B4 $1F $3C $40 $21 $FF $1E $8A $16 $80 $F9 $0B $5F $C0
	.db $23 $04 $E4 $12 $7D $0B $40 $98 $40 $09 $24 $A5 $40 $A3 $C0 $68
	.db $A0 $A6 $A0 $FE $93 $B0 $CC $80 $13 $A5 $01 $A0 $40 $94 $54 $BA
	.db $75 $B8 $FA $82 $08 $E3 $6C $EC $B5 $54 $AE $0C $5C $B5 $10 $85
	.db $E4 $CA $00 $B6 $00
crashmanStage.map.1:
	.db $10 $AF $01 $D9 $13 $16 $0C $29 $09 $24 $36 $F4 $8D $30 $D0 $0F
	.db $0A $52 $04 $76 $D0 $01 $98 $26 $07 $08 $E9 $B7 $0A $37 $35 $02
	.db $43 $08 $16 $0D $0E $70 $0C $67 $01 $10 $05 $08 $4F $8F $0C $6C
	.db $02 $1D $03 $AC $08 $F3 $43 $06 $16 $46 $32 $08 $42 $50 $15 $22
	.db $20 $01 $91 $0F $15 $15 $25 $10 $A2 $14 $A4 $20 $15 $2D $08 $31
	.db $14 $A5 $10 $B4 $84 $28 $30 $15 $A7 $11 $20 $3E $87 $22 $21 $D3
	.db $6D $C8 $1A $10 $40 $64 $23 $D0 $08 $F5 $F7 $DF $FA $09 $B4 $06
	.db $A4 $00 $56 $13 $01 $D0 $F8 $B5 $29 $08 $1D $F8 $4A $08 $42 $F8
	.db $6A $34 $00 $F3 $52 $34 $00 $A4 $37 $60 $04 $16 $9B $76 $65 $48
	.db $0B $3D $10 $92 $86 $04 $78 $96 $16 $4C $12 $0C $BD $0B $30 $68
	.db $80 $B0 $DA $17 $40 $21 $20 $C8 $80 $55 $4D $80 $44 $0C $68 $40
	.db $05 $E1 $1E $38 $0F $47 $9A $44 $45 $E0 $D2 $19 $9C $02 $5A $7C
	.db $65 $B4 $16 $3D $20 $94 $B8 $16 $9C $ED $4A $B0 $8E $02 $27 $0C
	.db $16 $2E $18 $0C $0A $0B $52 $15 $20 $F4 $2C $AC $16 $AD $20 $20
	.db $BA $8C $80 $D0 $78 $40 $68 $7C $BA $3B $D3 $10 $6E $18 $1F $B6
	.db $2D $0A $9B $C0 $76 $39 $26 $27 $38 $28 $F4 $77 $29 $DD $10 $F6
	.db $12 $1B $F5 $B2 $0D $0B $2A $07 $2B $FD $11 $FA $B3 $95 $7D $49
	.db $43 $27 $6D $DC $16 $A2 $6C $24 $FF $09 $21 $46 $08 $40 $10 $E3
	.db $16 $57 $D0 $40 $40 $92 $1B $E0 $81 $A5 $3C $E0 $12 $D5 $D3 $13
	.db $43 $40 $6F $08 $9B $4E $43 $20 $80 $94 $51 $48 $AE $52 $C0 $42
	.db $80 $91 $D9 $24 $01 $C0 $43 $27 $2C $41 $04 $24 $19 $49 $A1 $CD
	.db $A4 $9B $10 $56 $8C $89 $48 $FE $8E $1F $7B $25 $EC $89 $06 $A0
	.db $08 $1C $C6 $85 $2A $27 $C8 $E7 $A0 $D1 $B2 $F3 $49 $40 $0A $C0
	.db $68 $7A $40 $21 $C0 $C8 $F8 $52 $13 $08 $42 $30 $F8 $90 $08 $DE
	.db $A9 $1C $48 $40 $CF $F4 $24 $F5 $2A $C0 $68 $D2 $E0 $EE $B4 $0A
	.db $D1 $38 $41 $AE $32 $9C $2C $02 $86 $14 $05 $38 $90 $EE $90 $E0
	.db $42 $B3 $4D $BC $93 $55 $A0 $2B $D3 $66 $BC $0A $E1 $D5 $02 $DE
	.db $64 $26 $8F $60 $28 $FE $CA $33 $0B $FA $49 $32 $4A $B3 $FC $46
	.db $0C $FE $68 $34 $F6 $48 $F8 $C8 $06 $34 $08 $2A $C0 $90 $1C $92
	.db $3D $10 $14 $1C $29 $10 $09 $38 $0E $80 $42 $38 $6D $D8 $37 $23
	.db $C0 $F4 $22 $F6 $0C $C5 $0D $A3 $F8 $20 $E0 $D0 $55 $E0 $B6 $7C
	.db $DA $0A $2E $12 $C0 $17 $E0 $23 $D8 $36 $30 $C1 $9B $40 $7B $41
	.db $40 $24 $07 $0C $0F $55 $0E $70 $A4 $08 $99 $05 $72 $BA $80 $1C
	.db $E0 $AC $80 $99 $00 $7A $12 $08 $45 $80 $23 $08 $20 $14 $D5 $EC
	.db $00 $B2 $2A $8A $6A $9C $B4 $FD $89 $80 $9F $52 $05 $DF $01 $64
	.db $DC $4E $D5 $ED $41 $38 $46 $D5 $42 $91 $8F $B2 $20 $16 $94 $5C
	.db $57 $10 $40 $42 $5C $49 $14 $69 $89 $9E $80 $68 $12 $04 $80 $DB
	.db $68 $21 $10 $40 $C8 $AB $A0 $10 $FF $59 $40 $9B $7D $0B $45 $68
	.db $39 $3A $24 $20 $1C $86 $40 $42 $2C $41 $1C $0A $40 $41 $2E $BA
	.db $10 $F4 $AC $40 $58 $10 $7A $9E $37 $0A $FA $9C $53 $DF $79 $AD
	.db $33 $20 $0A $80 $79 $33 $0C $0A $03 $16 $BE $48 $AD $1C $26 $C3
	.db $4A $1C $D1 $12 $23 $5E $68 $DE $24 $C4 $12 $5B $FD $95 $62 $24
	.db $12 $A8 $40 $11 $20 $40 $82 $83 $C2 $C3 $09 $40 $A5 $8B $2C $11
	.db $40 $83 $73 $AE $80 $51 $2C $40 $A9 $7C $00 $6F $90 $9F $51 $10
	.db $A6 $7D $A1 $2D $0B $4E $80 $6F $3D $94 $80 $DE $39 $7A $84 $4E
	.db $05 $0A $06 $0B $C0 $99 $2D $02 $2E $4D $9C $72 $7F $60 $10 $2F
	.db $30 $31 $32 $A6 $DC $E3 $48 $48 $2F $0C $33 $34 $32 $35 $03 $05
	.db $57 $16 $C8 $6E $F0 $34 $DC $DD $E6 $00 $53 $42 $14 $40 $48 $00
	.db $A6 $21 $D1 $70 $40 $DB $28 $41 $74 $38 $0E $40 $EE $73 $F7 $D6
	.db $36 $AD $00 $28 $36 $E0 $0B $A2 $38 $44 $AD $4F $02 $16 $3A $24
	.db $36 $1D $38 $6C $C6 $45 $24 $84 $AC $9A $00 $27 $0C $89 $40 $34
	.db $00 $5D $09 $A8 $4D $40 $A7 $EC $5E $04 $B3 $40 $49 $C1 $64 $16
	.db $5F $40 $F9 $04 $CF $5D $02 $E4 $04 $4D $80 $31 $A6 $61 $8D $05
	.db $02 $96 $7E $05 $ED $75 $4A $80 $00
.ends

.slot 2
.section "crashmanStage.transitions" superfree
crashmanStage.stageLoader:	
	.db :crashmanStage.tiles
	.db 138
	.dw crashmanStage.tiles

	.db :crashmanMusic
	.dw crashmanMusic	
	
	.db :crashmanStage.metaTiles
	.dw crashmanStage.metaTiles
	
	;colision table
	.db $80 $AD $01 $B8 $65 $06 $40 $50 $08 $01 $B4 $74 $0D $76 $25 $00
	
	.db :crashmanStage.maps
	
crashmanStage.transition.0:
	.db LoadNewPaletteFlag | CheckpointFlag | BeginningTransitionsFlag | LoadGameplayMapFlag
	
	;megaman checkpoint position
	.db $b4		
	
	;palette
	.db $34 $00 $0A $3F $2F $0B $35 $20
	.db PaletteNewAddressMark | 16
	.db $34 | PaletteEndingMark
	
	configureNextTransitions TransitT, crashmanStage.transition.1

	;new map to load
	.dw crashmanStage.map.0

	configureMapLimits OrientationBackward, OrientationVert, 0, 2 

crashmanStage.transition.0.back:
	.db BeginningTransitionsFlag

	configureNextTransitions TransitT, crashmanStage.transition.1
	configureMapLimits OrientationFoward, OrientationVert, 0, 2 

	
crashmanStage.transition.1
	.db BeginningTransitionsFlag | EndingTransitionsFlag 
	
	configureNextTransitions TransitB, crashmanStage.transition.0.back
	configureNextTransitions TransitT, crashmanStage.transition.2
	configureMapLimits OrientationFoward, OrientationHor, 2, 2 

crashmanStage.transition.1.back
	.db BeginningTransitionsFlag | EndingTransitionsFlag 
	
	configureNextTransitions TransitB, crashmanStage.transition.0.back
	configureNextTransitions TransitT, crashmanStage.transition.2
	configureMapLimits OrientationBackward, OrientationHor, 2, 2 

	
crashmanStage.transition.2
	.db BeginningTransitionsFlag | EndingTransitionsFlag
	
	configureNextTransitions TransitT, crashmanStage.transition.3
	configureNextTransitions TransitB, crashmanStage.transition.1.back
	configureMapLimits OrientationBackward, OrientationVert, 4, 3 

crashmanStage.transition.2.back
	.db BeginningTransitionsFlag | EndingTransitionsFlag
	
	configureNextTransitions TransitT, crashmanStage.transition.3
	configureNextTransitions TransitB, crashmanStage.transition.1.back
	configureMapLimits OrientationFoward, OrientationVert, 4, 3 
	
	
crashmanStage.transition.3
	.db BeginningTransitionsFlag | EndingTransitionsFlag
	
	configureNextTransitions TransitB, crashmanStage.transition.2.back
	configureNextTransitions TransitT, crashmanStage.transition.4
	configureMapLimits OrientationFoward, OrientationHor, 7, 2 

crashmanStage.transition.3.back
	.db BeginningTransitionsFlag | EndingTransitionsFlag | LoadGameplayMapFlag
	
	configureNextTransitions TransitB, crashmanStage.transition.2.back
	configureNextTransitions TransitT, crashmanStage.transition.4
	
	;new map to load
	.dw crashmanStage.map.0

	configureMapLimits OrientationBackward, OrientationHor, 7, 2 

crashmanStage.transition.4
	.db BeginningTransitionsFlag | EndingTransitionsFlag | LoadGameplayMapFlag
	
	configureNextTransitions TransitT, crashmanStage.transition.5
	configureNextTransitions TransitB, crashmanStage.transition.3.back
	
	;new map to load
	.dw crashmanStage.map.1
	
	configureMapLimits OrientationBackward, OrientationVert, 0, 2 	

crashmanStage.transition.4.back
	.db BeginningTransitionsFlag | EndingTransitionsFlag | LoadNewPaletteFlag
	
	;palette
	.db $34
	.db PaletteNewAddressMark | 16
	.db $34 | PaletteEndingMark
	
	configureNextTransitions TransitT, crashmanStage.transition.5
	configureNextTransitions TransitB, crashmanStage.transition.3.back
	
	configureMapLimits OrientationFoward, OrientationVert, 0, 2 		
	
crashmanStage.transition.5
	.db BeginningTransitionsFlag | EndingTransitionsFlag | LoadNewPaletteFlag
	
	;palette
	.db $20
	.db PaletteNewAddressMark | 16
	.db $20 | PaletteEndingMark
	
	configureNextTransitions TransitT, crashmanStage.transition.6
	configureNextTransitions TransitB, crashmanStage.transition.4.back
	configureMapLimits OrientationBackward, OrientationVert, 2, 1 		

crashmanStage.transition.6
	.db BeginningTransitionsFlag | EndingTransitionsFlag | LoadNewPaletteFlag
	
	;palette
	.db $00
	.db PaletteNewAddressMark | 16
	.db $00 | PaletteEndingMark
	
	configureNextTransitions TransitT, crashmanStage.transition.7
	configureNextTransitions TransitB, crashmanStage.transition.5
	configureMapLimits OrientationBackward, OrientationVert, 3, 1 	
	
crashmanStage.transition.7
	.db BeginningTransitionsFlag | EndingTransitionsFlag
	
	configureNextTransitions TransitT, crashmanStage.transition.8
	configureNextTransitions TransitB, crashmanStage.transition.6
	configureMapLimits OrientationBackward, OrientationVert, 4, 3
	
crashmanStage.transition.7.back
	.db BeginningTransitionsFlag | EndingTransitionsFlag
	
	configureNextTransitions TransitT, crashmanStage.transition.8
	configureNextTransitions TransitB, crashmanStage.transition.6
	configureMapLimits OrientationFoward, OrientationVert, 4, 3
	
crashmanStage.transition.8
	.db BeginningTransitionsFlag | EndingTransitionsFlag
	
	configureNextTransitions TransitB, crashmanStage.transition.7.back
	configureNextTransitions TransitR, crashmanStage.transition.9
	configureMapLimits OrientationFoward, OrientationHor, 7, 2 	

crashmanStage.transition.9
	.db EndingTransitionsFlag
	
	configureNextTransitions TransitR, crashmanStage.transition.10
	configureMapLimits OrientationBackward, OrientationVert, 9, 1 	
	
crashmanStage.transition.10:
	.db LoadNewPaletteFlag
	
crashmanPalette:	
	.db PaletteNewAddressMark | 24
	.db $03
	.db PaletteEndingMark | $2F
	
	configureMapLimits OrientationFoward, OrientationHor, 10, 1 
		
.ends
