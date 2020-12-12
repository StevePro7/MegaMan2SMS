.slot 2
.section "airmanStage.tiles" superfree
airmanStage.tiles:
	.incbin "imagens\airmanstage.psgcompr" skip 2
.ends

.slot 2
.section "airmanStage.metaTiles" superfree
airmanStage.metaTiles:
	.dw $1126
	.db $00 $E0 $FF $E2 $FE $E6 $FD $A5 $02 $9F $FC $9F $FB $91 $FA $BC
	.db $E7 $FC $F9 $8D $9F $DF $90 $F8 $C3 $F3 $01 $F7 $F4 $20 $DA $05
	.db $F6 $FD $00 $DF $03 $DD $E5 $43 $04 $D0 $E3 $E1 $D3 $E2 $E3 $E0
	.db $F3 $EE $C5 $2E $02 $A3 $EC $F2 $ED $3E $19 $EB $01 $EC $2D $EA
	.db $DB $7E $05 $8D $1F $E8 $9F $E9 $9F $CD $88 $C4 $01 $1F $E6 $9D
	.db $C8 $BC $45 $9B $0C $E2 $20 $3B $25 $E0 $51 $02 $EA $A7 $BE $C7
	.db $CA $10 $19 $A0 $05 $9C $14 $28 $08 $D3 $42 $FF $3B $D1 $52 $02
	.db $3F $B2 $67 $24 $CF $CA $02 $C7 $65 $E7 $CE $C7 $63 $E4 $CD $2B
	.db $B2 $CC $24 $CB $33 $3A $F3 $CA $F6 $00
.ends

.slot 2
.section "airmanStage.maps" superfree
airmanStage.maps:
airmanStage.map.0:
	.db $00 $C4 $02 $01 $02 $4E $03 $AE $04 $11 $CA $05 $10 $44 $06 $29
	.db $13 $20 $07 $29 $06 $08 $0F $6F $CC $09 $06 $0A $A4 $10 $43 $0B
	.db $2B $03 $20 $95 $0C $10 $9A $22 $14 $2F $D0 $21 $11 $9A $1E $16
	.db $10 $D0 $E7 $0F $D0 $60 $65 $02 $06 $28 $10 $09 $84 $43 $0A $8A
	.db $03 $2F $48 $9D $21 $10 $6D $5E $0A $11 $46 $60 $68 $23 $60 $7A
	.db $14 $A1 $8C $60 $85 $A1 $34 $C0 $76 $31 $40 $85 $01 $14 $08 $C1
	.db $B4 $34 $01 $70 $B2 $0D $0E $0F $29 $10 $11 $10 $22 $2F $05 $12
	.db $13 $14 $15 $16 $24 $10 $40 $2F $17 $18 $19 $1A $1B $AA $10 $30
	.db $E1 $1C $1D $14 $1E $1F $20 $09 $47 $F0 $03 $21 $22 $23 $24 $25
	.db $FD $2A $01 $8A $04 $CE $7A $1A $B2 $36 $10 $56 $0A $2F $9F $F8
	.db $56 $10 $89 $08 $16 $20 $8C $B1 $48 $0A $20 $B4 $62 $B1 $08 $45
	.db $20 $A3 $B1 $92 $08 $29 $00 $0A $B1 $52 $00 $90 $B1 $A5 $7D $20
	.db $EE $17 $20 $20 $46 $03 $F2 $01 $BC $B1 $FF $23 $4D $D0 $A0 $89
	.db $0B $1E $4D $52 $04 $3E $52 $4D $D5 $B0 $24 $01 $4D $D3 $56 $41
	.db $4D $DA $40 $95 $00 $AB $20 $DB $56 $DF $4F $9B $1F $57 $40 $FD
	.db $D1 $2F $B7 $09 $34 $4E $85 $20 $23 $B2 $21 $20 $48 $B2 $CA $5E
	.db $72 $3A $B2 $3A $11 $14 $B2 $4C $08 $C2 $F7 $FB $3E $12 $A5 $30
	.db $35 $40 $7D $50 $4A $80 $F7 $F8 $75 $3E $57 $80 $D1 $20 $AA $68
	.db $1E $A0 $DB $FC $CE $A0 $C9 $03 $3F $80 $3F $C6 $A9 $1B $20 $A6
	.db $22 $91 $20 $54 $DF $22 $EB $01 $F4 $9B $90 $D3 $EA $05 $B6 $F0
	.db $70 $04 $E1 $1B $2B $06 $10 $64 $0A $79 $FF $84 $78 $08 $8F $A3
	.db $20 $6F $FC $23 $6D $DA $1A $10 $23 $06 $EE $E8 $08 $F9 $04 $1F
	.db $23 $06 $E8 $80 $56 $8A $11 $1F $E0 $4D $63 $4B $B0 $C8 $05 $D9
	.db $01 $72 $C1 $48 $70 $BD $0B $10 $23 $05 $EE $08 $05 $FA $6D $10
	.db $28 $83 $9B $10 $68 $A3 $A1 $73 $E4 $06 $B6 $E0 $91 $92 $DF $E5
	.db $96 $80 $D2 $80 $9B $C0 $25 $04 $BC $70 $D1 $80 $20 $F7 $FF $F1
	.db $E4 $A6 $E0 $88 $0A $F3 $FF $08 $DB $46 $7C $10 $88 $06 $DA $4A
	.db $4E $1C $10 $49 $26 $A0 $E2 $0A $4F $E0 $34 $96 $68 $10 $06 $8F
	.db $91 $0A $F2 $08 $3E $EC $08 $8F $BB $A3 $27 $E2 $03 $08 $3C $4D
	.db $07 $10 $F2 $09 $4F $6D $91 $03 $DA $23 $73 $30 $C4 $05 $9B $00
	.db $52 $C0 $8A $03 $B5 $71 $0C $22 $40 $90 $31 $E2 $09 $9E $A6 $4E
	.db $0B $6D $F0 $AB $62 $A0 $4E $12 $8F $52 $42 $42 $89 $03 $34 $08
	.db $4D $01 $00 $A7 $0E $1F $E1 $6D $22 $0F $60 $68 $03 $60 $7A $2B
	.db $41 $9E $12 $FF $68 $40 $E4 $74 $5F $8B $60 $38 $04 $70 $8D $96
	.db $06 $9E $20 $38 $0A $46 $D5 $F0 $E3 $05 $FC $2E $E4 $53 $0F $DA
	.db $DF $47 $43 $3F $08 $FF $8D $A6 $F0 $7C $9E $6E $FA $45 $24 $94
	.db $01 $11 $E4 $86 $24 $9A $A7 $3E $3F $6D $02 $0D $36 $8F $8B $03
	.db $3E $C0 $46 $03 $52 $9E $D0 $10 $CA $01 $20 $54 $FF $58 $50 $0A
	.db $93 $A0 $3E $49 $24 $B6 $C4 $56 $03 $E6 $DA $41 $36 $F5 $4C $0C
	.db $6E $F6 $00
airmanStage.map.1:
	.db $00 $E0 $01 $67 $02 $03 $0A $08 $52 $36 $0F $E0 $0B $89 $04 $0E
	.db $70 $64 $0C $21 $06 $39 $17 $2F $44 $08 $2D $A3 $1E $11 $4F $F1
	.db $8A $0A $10 $D1 $04 $C2 $3C $56 $06 $40 $FC $05 $8F $B8 $23 $05
	.db $C8 $C1 $CC $02 $27 $AD $C1 $B1 $02 $03 $08 $5A $20 $68 $67 $20
	.db $7A $3A $11 $30 $E1 $0D $0E $0A $0F $10 $11 $08 $0F $EE $A0 $12
	.db $13 $14 $15 $16 $53 $04 $A0 $80 $17 $18 $19 $1A $1B $42 $06 $DD
	.db $81 $1C $1D $1E $1F $20 $A3 $84 $10 $81 $21 $22 $23 $24 $25 $49
	.db $B7 $FE $9C $01 $56 $06 $10 $DA $63 $14 $6E $8C $E8 $85 $6E $21
	.db $31 $21 $6E $48 $31 $48 $6E $5B $43 $03 $6E $D0 $01 $BB $CF $03
	.db $F1 $8F $05 $F1 $8F $07 $F1 $95 $70 $DF $95 $09 $10 $9A $22 $1E
	.db $30 $A7 $61 $A3 $10 $11 $0C $F2 $0B $B6 $30 $53 $0C $60 $DA $41
	.db $16 $60 $56 $0A $20 $2B $03 $0F $94 $01 $70 $A4 $29 $0F $FA $17
	.db $93 $04 $3D $50 $02 $30 $06 $B6 $10 $4C $04 $3F $E4 $29 $20 $A1
	.db $FC $F0 $C4 $08 $CF $1F $26 $09 $95 $51 $0B $23 $20 $90 $20 $E2
	.db $03 $36 $D0 $1D $20 $F2 $07 $65 $62 $92 $01 $69 $3E $22 $20 $56
	.db $3E $91 $82 $56 $1C $92 $28 $20 $07 $A7 $E2 $AB $7C $4D $41 $1B
	.db $30 $6A $22 $C0 $54 $87 $10 $C4 $07 $9F $E0 $23 $09 $E4 $03 $2C
	.db $0B $8F $9F $0C $E3 $C7 $05 $F8 $F9 $05 $1F $70 $47 $0B $9A $84
	.db $4D $40 $B4 $63 $8E $40 $41 $E1 $5B $C4 $6A $1E $A4 $D3 $58 $1E
	.db $84 $E2 $03 $CF $B2 $94 $07 $20 $A4 $8B $40 $58 $36 $92 $68 $40
	.db $06 $BB $01 $CE $E8 $04 $FA $08 $20 $C0 $D1 $04 $77 $32 $C8 $06
	.db $DE $A7 $F2 $90 $0B $E2 $0A $B9 $2F $09 $5F $A0 $2B $03 $80 $5A
	.db $3E $FE $FF $22 $90 $D5 $1C $B6 $21 $D2 $DB $79 $40 $05 $11 $69
	.db $DE $63 $B0 $8A $09 $60 $EA $DE $D9 $08 $32 $70 $A9 $F9 $08 $1E
	.db $48 $5C $FE $7F $8F $A1 $01 $DC $8F $44 $C8 $84 $5F $C5 $03 $7E
	.db $7E $D0 $4E $FB $90 $60 $EE $8A $03 $10 $D5 $D9 $28 $94 $02 $29
	.db $10 $E0 $2A $2B $2C $46 $2D $C1 $2E $2F $2D $30 $A1 $03 $40 $4F
	.db $5E $E9 $06 $48 $10 $F5 $D2 $9B $00 $BD $64 $0E $64 $20 $55 $01
	.db $57 $B4 $08 $10 $05 $FB $82 $05 $3E $E0 $05 $8F $B8 $23 $0B $E4
	.db $0C $7C $05 $8F $B8 $23 $0B $E4 $0C $78 $01 $AF $40 $C4 $05 $7D
	.db $A3 $A2 $10 $64 $0C $7C $31 $F5 $5D $01 $80 $00
.ends

.slot 2
.section "airmanStage.transitions" superfree
airmanStage.stageLoader:	
	.db :airmanStage.tiles
	.db 146
	.dw airmanStage.tiles

	.db :mandrillMusic
	.dw mandrillMusic

	.db :airmanStage.metaTiles
	.dw airmanStage.metaTiles
	
	;colision table
	.db $00 $CA $02 $80 $04 $A2 $06 $85 $01 $53 $60 $48 $00
	
	.db :airmanStage.maps
	
airmanStage.transition.0:
	.db LoadNewPaletteFlag | CheckpointFlag | EndingTransitionsFlag | LoadGameplayMapFlag
	
	;megaman checkpoint position
	.db $74	
	
	;palette
	.db $39 $3F $00 $13 
	paletteAnimationSetUp 17, 4, 2	
	.db $3e $39
	.db $3f $3e
	.db $3f $3f
	.db $3f $3e
	;border color
	.db PaletteNewAddressMark | 13
	.db $3f $13 $00 
	.db $39 | PaletteEndingMark
	
	configureNextTransitions TransitB, airmanStage.transition.1

	;new map to load
	.dw airmanStage.map.0

	configureMapLimits OrientationFoward, OrientationHor, 0, 10 
	
airmanStage.transition.1
	.db EndingTransitionsFlag 
	
	configureNextTransitions TransitB, airmanStage.transition.2
	configureMapLimits OrientationFoward, OrientationHor, 10, 1 

airmanStage.transition.2
	.db CheckpointFlag | EndingTransitionsFlag | LoadGameplayMapFlag
	
	;megaman checkpoint position
	.db $74	
	
	configureNextTransitions TransitR, airmanStage.transition.3
	
	;new map to load
	.dw airmanStage.map.1
	
	configureMapLimits OrientationFoward, OrientationHor, 0, 9 

airmanStage.transition.3
	.db EndingTransitionsFlag
	
	configureNextTransitions TransitR, airmanStage.transition.4
	configureMapLimits OrientationFoward, OrientationHor, 9, 1 

airmanStage.transition.4:
	.db LoadNewPaletteFlag
	
airmanPalette:	
	.db PaletteNewAddressMark | 24
	.db $34
	.db PaletteEndingMark | $1b
	
	configureMapLimits OrientationFoward, OrientationHor, 10, 1 
.ends

