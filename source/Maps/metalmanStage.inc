.slot 2
.section "metalmanStage.tiles" superfree
metalmanStage.tiles:
	.incbin "imagens\metalmanstage.psgcompr" skip 2
.ends

.slot 2
.section "metalmanStage.metaTiles" free
metalmanStage.metaTiles:
	.dw $0111
	.db $00 $E0 $FF $AD $01 $9F $FE $DF $FD $D5 $FC $02 $C3 $F9 $03 $F7
	.db $97 $48 $3F $43 $E2 $F8 $15 $87 $F5 $03 $F3 $2A $04 $1F $F4 $B2
	.db $04 $F2 $35 $8E $F1 $03 $5F $A0 $47 $EF $21 $ED $79 $D4 $12 $D2
	.db $24 $E9 $43 $E7 $01 $E8 $F4 $3A $0F $E6 $01 $E7 $D1 $EA $10 $D5
	.db $01 $3F $E5 $46 $22 $CF $42 $E3 $AC $E2 $89 $E1 $0C $DF $FC $E0
	.db $8E $7E $DE $F9 $0A $AC $DE $89 $DD $0F $3F $D9 $36 $DC $09 $00
.ends

.slot 2
.section "metalmanStage.maps" free
metalmanStage.maps:
metalmanStage.map.0:
	.db $00 $C7 $03 $01 $02 $11 $03 $04 $05 $D5 $06 $DF $CE $16 $66 $07
	.db $03 $08 $1C $33 $09 $0A $28 $0B $9F $9D $16 $BC $0E $9C $0C $0D
	.db $BF $1B $05 $0E $21 $7B $13 $A2 $2F $0C $31 $03 $0B $DC $13 $34
	.db $5F $26 $26 $80 $6F $0B $13 $F9 $15 $0D $BF $05 $A0 $0E $6E $0B
	.db $5F $5F $E9 $01 $B6 $A6 $A1 $8C $3A $DB $5D $C2 $1B $40 $04 $0F
	.db $75 $72 $44 $89 $10 $94 $24 $03 $60 $90 $24 $8C $10 $80 $09 $A4
	.db $60 $CA $AB $05 $20 $3A $41 $16 $60 $BD $82 $AC $0D $10 $40 $BE
	.db $12 $D1 $4C $08 $AC $11 $CD $C3 $0B $12 $08 $6A $0E $A3 $10 $3C
	.db $1A $0B $50 $0F $0C $F3 $46 $62 $20 $FA $05 $51 $0B $09 $A2 $C0
	.db $62 $DA $20 $02 $3B $60 $42 $04 $10 $41 $0B $09 $84 $A2 $C8 $10
	.db $68 $06 $13 $B3 $ED $A8 $19 $B6 $FE $46 $13 $D1 $1C $6A $9A $22
	.db $0A $2F $1F $CF $EA $12 $6A $36 $A7 $06 $FD $52 $2B $13 $46 $50
	.db $45 $08 $18 $F4 $13 $AA $3D $2E $B3 $74 $10 $D1 $6C $75 $AC $5D
	.db $CA $20 $01 $3D $A2 $BA $52 $05 $10 $2A $08 $3D $D9 $CD $45 $12
	.db $A9 $21 $50 $AA $8D $84 $F2 $FB $4D $60 $A1 $63 $5D $A1 $60 $34
	.db $DD $28 $10 $0D $AE $6E $7D $0E $DC $86 $C4 $14 $15 $16 $8A $8F
	.db $3E $05 $E0 $86 $12 $17 $18 $19 $FE $1A $D1 $03 $80 $37 $03 $61
	.db $CA $20 $0D $1B $1C $04 $8A $36 $0E $09 $10 $20 $20 $35 $1D $1E
	.db $04 $5F $3C $A9 $20 $C8 $60 $68 $20 $52 $05 $10 $1A $22 $01 $1F
	.db $2F $F1 $34 $12 $52 $64 $02 $26 $72 $52 $8C $02 $84 $10 $86 $1E
	.db $DA $1E $68 $05 $0F $06 $36 $1E $7C $84 $31 $79 $0B $A4 $01 $8C
	.db $31 $56 $0B $60 $C8 $06 $5F $A1 $90 $68 $1E $6D $88 $08 $70 $13
	.db $57 $1F $01 $56 $30 $43 $30 $43 $1F $47 $30 $68 $BF $B0 $FB $FD
	.db $3D $70 $19 $40 $19 $4D $19 $40 $1D $AF $FE $B5 $40 $6E $71 $A6
	.db $69 $87 $40 $B4 $69 $3D $40 $19 $30 $4A $10 $52 $11 $8A $0B $20
	.db $6A $40 $5A $BE $10 $47 $06 $DD $29 $A7 $E8 $10 $72 $9C $51 $8C
	.db $94 $87 $20 $20 $0C $87 $20 $20 $0C $8F $20 $CA $71 $5A $1B $20
	.db $43 $A4 $82 $91 $40 $91 $42 $92 $29 $00 $A1 $84 $80 $CA $B3 $7A
	.db $3A $40 $3D $80 $4A $70 $52 $B4 $72 $87 $80 $34 $14 $66 $40 $84
	.db $A7 $71 $21 $80 $C2 $1B $1C $3C $23 $1D $1E $C9 $3C $C0 $8D $C0
	.db $29 $00 $D4 $8F $80 $3F $F5 $8F $34 $02 $9A $30 $69 $02 $BF $11
	.db $23 $1C $23 $3E $23 $1C $24 $40 $5B $56 $11 $E0 $8F $0B $1E $BD
	.db $46 $8D $0B $61 $5A $40 $26 $0B $B0 $F9 $0B $4E $40 $FB $23 $06
	.db $EC $03 $12 $9B $E0 $E4 $13 $7C $13 $9B $40 $E4 $13 $39 $12 $45
	.db $13 $CE $B0 $A5 $85 $22 $40 $A7 $85 $92 $13 $39 $C0 $12 $45 $13
	.db $67 $00 $34 $81 $34 $20 $39 $40 $04 $27 $39 $40 $33 $00 $90 $40
	.db $BA $42 $80 $A9 $09 $07 $28 $4D $12 $05 $0E $8A $C3 $6F $0E $92
	.db $C6 $6F $22 $A5 $00 $25 $BA $61 $94 $00 $DA $11 $3A $51 $A0 $95
	.db $12 $40 $7E $96 $BF $C5 $06 $09 $05 $10 $C5 $1C $3F $29 $0B $10
	.db $37 $1D $5A $10 $C9 $4B $40 $2B $79 $10 $30 $25 $2D $40 $1C $0D
	.db $10 $29 $60 $90 $10 $C9 $12 $CA $5E $26 $20 $11 $04 $94 $6F $6D
	.db $94 $A1 $41 $10 $6D $94 $0B $20 $29 $12 $87 $21 $20 $68 $B5 $68
	.db $20 $5A $19 $01 $10 $4A $10 $9A $E1 $9E $FF $E9 $4A $10 $25 $13
	.db $13 $4C $42 $AE $DC $89 $13 $44 $4C $D3 $AE $94 $CA $A2 $42 $D2
	.db $C6 $2B $D2 $4E $0B $64 $62 $51 $01 $E2 $27 $0B $32 $62 $13 $10
	.db $FC $32 $03 $71 $22 $A2 $50 $D9 $21 $6E $13 $23 $A7 $68 $7C $10
	.db $4C $30 $13 $91 $A7 $92 $0E $76 $2C $30 $5D $13 $60 $D4 $4C $A2
	.db $13 $EE $60 $8C $10 $5D $12 $60 $D1 $10 $96 $29 $06 $0A $B0 $58
	.db $06 $A2 $1A $9E $01 $D1 $40 $02 $A1 $1E $1D $1E $58 $27 $F7 $49
	.db $9E $80 $A6 $51 $A4 $64 $96 $34 $59 $0E $36 $19 $2C $05 $3E $51
	.db $0C $68 $CB $9A $46 $78 $80 $9C $CE $53 $48 $04 $9E $E4 $F2 $69
	.db $74 $99 $9E $C4 $0D $F2 $9F $48 $9E $E6 $7D $DE $06 $29 $20 $4D
	.db $7D $B8 $06 $52 $20 $9B $7D $74 $06 $99 $BE $CD $7D $CE $45 $62
	.db $A0 $40 $DD $7D $2A $0E $90 $A1 $9E $31 $B4 $7D $39 $80 $9A $02
	.db $20 $7D $1C $80 $D0 $05 $3E $6C $06 $00
metalmanStage.map.1:
	.db $1D $52 $1E $02 $84 $0C $02 $0A $1F $01 $59 $01 $C3 $38 $04 $02
	.db $85 $09 $0A $05 $0E $1E $06 $86 $12 $08 $07 $04 $DB $14 $1B $FA
	.db $05 $81 $06 $13 $0D $0C $B4 $04 $68 $26 $03 $03 $7B $13 $D0 $63
	.db $03 $D9 $1F $03 $B4 $20 $63 $36 $03 $67 $1B $09 $13 $0E $63 $9F
	.db $AA $03 $4C $80 $05 $37 $13 $04 $63 $FA $75 $20 $03 $C6 $CA $13
	.db $0A $63 $E1 $46 $75 $06 $81 $67 $13 $B2 $2C $50 $07 $8D $75 $06
	.db $B3 $9C $5A $13 $70 $33 $DB $27 $04 $41 $07 $90 $B7 $C0 $33 $2D
	.db $7B $1D $80 $9A $C0 $0D $0F $08 $3D $80 $9B $0E $60 $41 $C0 $0D
	.db $04 $3D $5F $80 $AA $C0 $86 $90 $8A $3D $0F $80 $D4 $C0 $8A $0C
	.db $C1 $48 $3F $A3 $C0 $34 $F6 $34 $02 $36 $C0 $20 $D0 $F6 $02 $D0
	.db $C0 $91 $F0 $90 $3D $37 $04 $7E $AA $F0 $52 $9B $20 $ED $24 $01
	.db $14 $60 $20 $CA $05 $10 $65 $0C $5F $27 $EA $8C $FF $4D $60 $06
	.db $30 $3E $86 $32 $86 $C0 $8A $21 $1B $30 $24 $5E $10 $5C $6E $54
	.db $11 $8F $12 $F5 $10 $68 $7C $0E $C8 $10 $48 $3E $C8 $10 $C8 $7E
	.db $EF $E2 $14 $15 $16 $94 $10 $C2 $61 $17 $18 $19 $B1 $0E $06 $A1
	.db $AC $20 $E4 $0B $84 $1F $3C $20 $0B $47 $0A $87 $06 $0E $F8 $79
	.db $12 $42 $84 $0E $9C $20 $4D $13 $14 $91 $20 $D0 $8C $90 $20 $E4
	.db $34 $AC $36 $20 $76 $87 $94 $22 $B0 $68 $0E $77 $10 $73 $68 $06
	.db $42 $10 $D3 $6A $42 $B6 $00 $7B $9B $05 $47 $42 $66 $41 $10 $22
	.db $91 $42 $10 $CD $11 $04 $4A $02 $2B $04 $10 $6D $50 $0E $10 $48
	.db $60 $7F $A5 $20 $B6 $AB $60 $55 $05 $50 $AB $04 $56 $24 $80 $A1
	.db $10 $46 $0E $EE $90 $B0 $D4 $16 $BE $E4 $94 $60 $54 $E0 $80 $E4
	.db $94 $C0 $77 $E0 $98 $E8 $20 $93 $0E $2D $0F $A9 $20 $60 $E8 $20
	.db $E8 $01 $59 $12 $5B $20 $57 $D0 $90 $10 $AC $21 $10 $22 $23 $24
	.db $B9 $4E $40 $2B $0C $A8 $29 $40 $4F $D3 $35 $70 $10 $40 $C2 $B4
	.db $8C $70 $10 $A7 $C2 $14 $0D $63 $94 $62 $A6 $9E $71 $25 $48 $23
	.db $00 $DA $42 $19 $10 $24 $D2 $47 $50 $BD $9F $26 $27 $AB $10 $CF
	.db $F0 $E4 $4A $3F $24 $10 $73 $6A $1C $08 $50 $53 $FA $05 $A8 $3F
	.db $10 $CD $E7 $17 $3F $4A $2C $4C $1C $09 $A4 $3F $D3 $21 $74 $22
	.db $5A $7E $08 $BA $6C $1B $7E $43 $A6 $2F $49 $7F $68 $7E $82 $E8
	.db $D1 $48 $7E $68 $10 $49 $28 $AE $7E $6D $28 $0D $1F $0D $7E $59
	.db $40 $B4 $3C $04 $39 $3F $FF $F4 $6D $0B $FC $68 $29 $70 $C8 $3F
	.db $72 $9A $E4 $14 $3F $D0 $DD $3F $F4 $C9 $1C $19 $7E $AB $62 $80
	.db $B6 $37 $06 $A4 $67 $AE $80 $CC $1A $21 $3C $24 $F1 $23 $40 $52
	.db $D9 $C8 $0C $48 $10 $5A $99 $C0 $11 $26 $6A $64 $39 $03 $8D $C0
	.db $0C $10 $0D $AA $86 $BA $C0 $CA $C0 $08 $20 $E3 $3C $53 $10 $37
	.db $01 $73 $45 $0E $36 $40 $03 $6E $08 $73 $9A $F9 $C5 $70 $2C $BF
	.db $4E $9B $F9 $C4 $DF $6E $49 $A0 $F7 $C8 $E8 $B7 $21 $20 $E9 $9C
	.db $C2 $D5 $41 $00 $D2 $51 $42 $20 $D6 $34 $1C $4D $24 $1A $03 $18
	.db $92 $03 $B1 $9B $8D $1B $1C $04 $4B $02 $69 $0D $4B $74 $41 $35
	.db $D2 $1D $F8 $29 $74 $68 $34 $10 $52 $EA $9C $16 $20 $F7 $29 $9C
	.db $42 $20 $90 $88 $5D $9C $4D $7E $26 $10 $14 $52 $E9 $9E $0A $62
	.db $35 $9B $53 $48 $81 $3D $A2 $10 $C4 $14 $94 $D0 $6F $56 $2D $59
	.db $28 $D0 $92 $34 $4C $25 $6E $C4 $E0 $99 $2D $92 $22 $11 $D9 $4A
	.db $A3 $60 $DC $12 $11 $36 $7E $07 $B3 $01 $B3 $FD $0D $73 $2E $A5
	.db $AA $34 $81 $B2 $08 $D0 $10 $D2 $CD $0B $14 $0C $27 $A4 $49 $C6
	.db $0B $83 $10 $41 $A3 $90 $2D $08 $92 $32 $FC $0A $C4 $84 $57 $0C
	.db $B0 $4C $C0 $D3 $52 $84 $8D $8C $4A $8C $41 $94 $28 $8C $DF $EC
	.db $11 $5B $52 $7F $C2 $CD $0E $8D $09 $80 $0A $2E $68 $8C $80 $4E
	.db $1C $24 $CE $72 $13 $80 $97 $3A $10 $53 $49 $FA $01 $A6 $77 $85
	.db $40 $A9 $6C $38 $53 $40 $95 $6C $71 $A5 $40 $B4 $DC $10 $FE $7F
	.db $B4 $5A $B4 $FD $1E $81 $27 $0E $05 $B3 $09 $4D $80 $ED $D3 $99
	.db $09 $D6 $9A $2F $8E $AC $35 $81 $B1 $03 $1A $4D $01 $19 $51 $22
	.db $2C $49 $30 $D1 $01 $4E $74 $A4 $64 $10 $E7 $A4 $46 $10 $46 $40
	.db $33 $28 $02 $29 $FC $51 $40 $81 $2A $2B $2C $2D $1A $03 $2A $2E
	.db $2F $2D $30 $47 $03 $40 $63 $F5 $31 $32 $69 $02 $0C $44 $0E $92
	.db $DE $D0 $68 $10 $69 $0C $32 $69 $0D $BB $68 $04 $10 $88 $AA $11
	.db $A6 $BB $D0 $68 $10 $48 $AA $8A $10 $7A $68 $40 $49 $BB $05 $BD
	.db $64 $40 $A7 $0B $46 $40 $4C $48 $A4 $64 $40 $D9 $48 $A3 $2A $40
	.db $B5 $62 $C9 $7B $1D $40 $23 $A7 $29 $04 $40 $49 $9B $60 $47 $68
	.db $40 $4B $64 $60 $39 $C0 $07 $20 $6A $C0 $7A $0D $20 $60 $1D $40
	.db $EA $CC $A0 $D5 $74 $00 $9A $F4 $0D $20 $70 $19 $40 $09 $01 $09
	.db $3E $08 $01 $12 $92 $40 $82 $3E $66 $CE $64 $03 $20 $13 $94 $40
	.db $10 $7E $C9 $90 $BE $6A $21 $40 $A0 $3E $99 $33 $36 $28 $21 $86
	.db $40 $6D $0E $1D $28 $A3 $21 $40 $14 $10 $22 $42 $40 $92 $26 $FE
	.db $60 $85 $40 $29 $69 $34 $60 $29 $40 $06 $10 $44 $85 $40 $B4 $E3
	.db $10 $BC $40 $A5 $24 $3A $10 $BC $40 $B5 $5A $48 $40 $14 $40 $B1
	.db $92 $34 $40 $29 $40 $0B $D0 $41 $40 $1B $01 $60 $00
.ends

.slot 2
.section "metalmanStage.transitions" superfree
metalmanStage.stageLoader:	
	.db :metalmanStage.tiles
	.db 167
	.dw metalmanStage.tiles

	.db :metalmanMusic
	.dw metalmanMusic	
	
	.db :metalmanStage.metaTiles
	.dw metalmanStage.metaTiles

	;collisionTable
	.db $80 $E3 $C3 $34 $03 $A0 $0E $26 $05 $0F $71 $C0 $E1 $57 $01 $E8
	.db $76 $D8 $33 $00

	
;	.db $01 $E3 $C3 $6F $03 $0C $14 $05 $90 $07 $68 $22 $13 $68 $01 $54
;	.db $D8 $31 $00
	
	.db :metalmanStage.maps
	
metalmanStage.transition.0:
	.db LoadNewPaletteFlag | CheckpointFlag | EndingTransitionsFlag | LoadGameplayMapFlag
	
	;megaman checkpoint position
	.db $a4		
	
	;palette
	.db $00 $2A $2F $1D $06 $02 
	;paletteAnimation
	paletteAnimationSetUp 4, 4, 5	
	.db $17 $02 $00 $02 $1B
	.db $2A $02 $00 $1B $02
	.db $2A $00 $02 $02 $1B
	.db $2A $00 $02 $1B $02
	;border color
	.db PaletteNewAddressMark | 16
	.db PaletteEndingMark
	
	configureNextTransitions TransitB, metalmanStage.transition.1

	;new map to load
	.dw metalmanStage.map.0

	configureMapLimits OrientationFoward, OrientationHor, 0, 10 
		
metalmanStage.transition.1
	.db EndingTransitionsFlag 
	
	configureNextTransitions TransitB, metalmanStage.transition.2
	configureMapLimits OrientationFoward, OrientationHor, 10, 1 

metalmanStage.transition.2
	.db CheckpointFlag | EndingTransitionsFlag | LoadGameplayMapFlag
	
	;megaman checkpoint position
	.db $74	
	
	configureNextTransitions TransitR, metalmanStage.transition.3
	
	;new map to load
	.dw metalmanStage.map.1
	
	configureMapLimits OrientationFoward, OrientationHor, 0, 9 

metalmanStage.transition.3
	.db EndingTransitionsFlag
	
	configureNextTransitions TransitR, metalmanStage.transition.4
	configureMapLimits OrientationFoward, OrientationHor, 9, 1 
	
metalmanStage.transition.4:
	.db LoadNewPaletteFlag
	
metalmanPalette:	
	.db PaletteNewAddressMark | 24
	.db $13 $0B
	.db PaletteEndingMark | $2F
	
	configureMapLimits OrientationFoward, OrientationHor, 10, 1 
		
.ends
