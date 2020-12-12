.slot 2
.section "flashmanStage.tiles" superfree
flashmanStage.tiles:
	.incbin "imagens\flashmanstage.psgcompr" skip 2
.ends

.slot 2
.section "flashmanStage.metaTiles" superfree
flashmanStage.metaTiles:
	.dw $011A
	.db $00 $A5 $01 $7E $21 $DC $FF $5F $1F $FB $D9 $FE $09 $FD $4A $02
	.db $EC $A4 $FC $FC $86 $43 $8C $23 $F9 $56 $44 $E9 $F7 $87 $64 $F6
	.db $48 $F5 $67 $F3 $E4 $F4 $2C $ED $CF $1D $EB $CD $F2 $11 $DA $AC
	.db $04 $00
.ends

.slot 2
.section "flashmanStage.maps" superfree
flashmanStage.maps:
flashmanStage.map.0:
	.db $00 $01 $01 $02 $03 $04 $05 $06 $07 $87 $0C $08 $09 $0A $2E $19
	.db $02 $0B $DF $84 $63 $0C $F2 $0D $87 $0B $0E $77 $0F $0A $02 $B2
	.db $20 $08 $13 $42 $4A $0F $70 $7E $10 $E4 $11 $65 $12 $02 $13 $63
	.db $20 $07 $CD $05 $3B $12 $14 $66 $20 $32 $0E $0A $0D $04 $06 $0A
	.db $08 $20 $C5 $15 $22 $50 $10 $B1 $20 $14 $48 $50 $07 $AC $20 $CA
	.db $1C $0C $10 $15 $13 $60 $CE $11 $54 $10 $2B $15 $20 $32 $BC $07
	.db $92 $10 $1A $20 $08 $99 $B4 $0D $16 $17 $8E $18 $20 $0A $54 $11
	.db $50 $01 $AC $20 $53 $0D $A0 $70 $42 $0B $99 $32 $07 $5B $C0 $2B
	.db $0B $90 $3A $AA $08 $FC $65 $01 $4D $0E $66 $90 $F0 $83 $28 $68
	.db $1A $52 $40 $48 $91 $20 $18 $D0 $1A $A0 $45 $40 $94 $24 $15 $18
	.db $6E $77 $D4 $80 $8E $18 $15 $81 $68 $44 $E6 $48 $28 $B8 $51 $92
	.db $A2 $D0 $A3 $8B $CB $B5 $66 $D0 $D1 $50 $14 $2D $0F $ED $4D $10
	.db $A2 $B6 $A3 $DA $97 $0C $1B $E0 $28 $B7 $0B $10 $85 $E0 $20 $B8
	.db $A6 $38 $D1 $E7 $A0 $9A $B6 $08 $30 $A0 $BF $49 $60 $9C $55 $0C
	.db $A0 $CA $08 $28 $12 $05 $51 $A8 $A0 $DA $10 $2E $88 $14 $94 $78
	.db $A5 $A0 $95 $15 $30 $7E $A6 $60 $CA $06 $15 $50 $BD $D3 $60 $65
	.db $46 $14 $5B $10 $6C $56 $5A $80 $72 $AB $30 $56 $2C $B3 $24 $0C
	.db $00 $E5 $0B $26 $B8 $87 $C7 $F1 $02 $19 $19 $8C $2B $F6 $10 $A6
	.db $80 $ED $37 $29 $50 $78 $07 $A4 $80 $C6 $B0 $0D $01 $4D $68 $12
	.db $F7 $88 $BE $57 $EB $43 $C0 $2B $15 $10 $1A $0A $A3 $08 $C0 $78
	.db $15 $08 $13 $68 $06 $A0 $6D $1B $09 $63 $27 $11 $68 $B5 $63 $49
	.db $39 $11 $07 $56 $1D $C7 $51 $0C $DE $22 $01 $2A $13 $0D $57 $0D
	.db $83 $29 $14 $60 $B2 $7B $07 $6C $01 $55 $15 $0D $9A $3B $13 $E0
	.db $B9 $80 $0C $56 $1D $33 $D0 $54 $FE $2A $01 $10 $45 $13 $A9 $41
	.db $F5 $48 $1D $36 $53 $E8 $AE $25 $81 $10 $01 $34 $60 $10 $AB $4D
	.db $29 $5B $14 $60 $34 $08 $32 $2D $01 $AD $16 $08 $16 $17 $3B $52
	.db $0B $50 $7A $AB $17 $29 $3B $0A $70 $34 $15 $2D $A0 $02 $60 $0B
	.db $92 $07 $2D $69 $39 $08 $E7 $0B $AC $10 $F3 $19 $59 $A0 $AA $21
	.db $30 $A6 $5A $89 $53 $10 $26 $46 $74 $A7 $8D $A1 $A0 $14 $08 $8D
	.db $A4 $26 $26 $6E $85 $8D $3E $D2 $D0 $D2 $24 $20 $64 $26 $12 $47
	.db $62 $20 $15 $92 $70 $44 $1D $85 $9D $15 $0E $80 $95 $5A $91 $C3
	.db $90 $04 $62 $CE $18 $17 $92 $26 $A5 $C0 $0D $CA $20 $24 $13 $A0
	.db $C5 $08 $66 $10 $A1 $49 $10 $A0 $28 $0C $94 $90 $96 $E2 $06 $91
	.db $30 $6D $95 $1D $01 $48 $90 $07 $A5 $10 $B5 $47 $94 $40 $35 $13
	.db $65 $36 $84 $40 $64 $C7 $4D $50 $0B $60 $1D $E0 $08 $2D $0E $D1
	.db $20 $E0 $DA $02 $14 $A0 $AE $47 $86 $C9 $52 $0D $70 $7A $99 $7D
	.db $44 $08 $94 $20 $99 $9D $65 $E6 $27 $50 $49 $9D $92 $66 $50 $59
	.db $AE $9D $82 $2D $CA $08 $13 $10 $D4 $8D $7A $A1 $3A $A4 $4C $6F
	.db $0D $A5 $A6 $38 $4D $3D $95 $0A $4C $FE $9B $02 $BC $98 $9A $0C
	.db $A5 $D6 $15 $12 $F7 $8D $10 $F4 $35 $2D $04 $50 $89 $27 $19 $1D
	.db $F3 $48 $6C $00 $E4 $24 $B3 $99 $00 $75 $80 $B7 $FC $4D $C9 $2E
	.db $40 $94 $1D $99 $A8 $14 $22 $80 $D2 $64 $91 $65 $E0 $1A $80 $B4
	.db $44 $C1 $CA $16 $0E $86 $68 $48 $CB $28 $0E $86 $72 $11 $DB $11
	.db $AA $5B $8C $B9 $E0 $14 $06 $F1 $93 $26 $13 $60 $BB $E0 $A4 $64
	.db $3E $D6 $D3 $24 $0E $90 $7A $3C $10 $56 $13 $80 $69 $84 $11 $02
	.db $0D $67 $40 $52 $0A $8A $08 $10 $E4 $13 $CA $C0 $41 $D9 $19 $17
	.db $27 $43 $69 $E0 $B9 $2D $08 $32 $A0 $DD $E1 $B4 $5A $8F $00 $2E
	.db $01 $4D $51 $07 $36 $00 $48 $93 $97 $1F $48 $A8 $B8 $EF $54 $50
	.db $69 $93 $33 $17 $43 $10 $9A $75 $E2 $07 $AA $42 $90 $C9 $36 $60
	.db $DA $03 $C0 $36 $10 $4D $14 $A0 $64 $5A $0D $B2 $F4 $50 $A1 $01
	.db $D2 $A0 $D9 $00 $F3 $68 $1B $83 $50 $21 $41 $E8 $8D $A5 $33 $31
	.db $49 $02 $57 $D2 $9D $60 $C2 $A8 $A2 $8D $23 $20 $2B $59 $26 $20
	.db $25 $16 $A0 $E1 $27 $27 $4A $64 $A0 $8D $86 $A1 $C0 $40 $CA $10
	.db $C9 $6E $40 $83 $2C $4B $A4 $2D $40 $A3 $58 $7C $A5 $93 $40 $42
	.db $67 $0F $9C $25 $1A $46 $88 $97 $BE $23 $CF $A4 $86 $A3 $BC $E8
	.db $CC $54 $D5 $47 $C9 $57 $2F $26 $19 $18 $6D $1E $2C $FE $D4 $16
	.db $7C $49 $1A $2B $B6 $D8 $29 $1A $14 $10 $C4 $01 $E2 $26 $70 $6B
	.db $05 $79 $16 $03 $69 $0E $6C $BA $13 $96 $1C $91 $47 $4D $80 $26
	.db $3C $6B $B0 $B2 $FD $93 $08 $25 $88 $19 $32 $0A $1C $9C $57 $0B
	.db $B7 $68 $6A $44 $EA $D3 $66 $06 $74 $A6 $A0 $D5 $20 $D3 $E5 $D5
	.db $FA $68 $D3 $13 $91 $34 $21 $D6 $48 $90 $95 $15 $F4 $F2 $14 $B6
	.db $10 $B8 $34 $AE $EC $9A $48 $84 $C0 $98 $7A $93 $E0 $2B $16 $29
	.db $35 $DA $16 $01 $CA $50 $13 $9E $69 $32 $31 $2A $D0 $98 $4F $14
	.db $23 $A5 $32 $98 $0B $94 $10 $D2 $48 $D9 $AE $DE $4C $77 $99 $A0
	.db $6A $5C $DA $1C $E4 $8A $5A $CA $38 $4C $96 $DC $68 $2B $01 $DA
	.db $25 $F8 $06 $14 $3C $C2 $90 $64 $46 $B6 $8B $10 $3E $CB $84 $97
	.db $49 $18 $2A $CB $15 $BA $5B $45 $10 $A3 $D4 $A3 $70 $F1 $19 $27
	.db $3C $68 $76 $D0 $72 $09 $5C $47 $09 $2A $73 $91 $7D $C8 $96 $26
	.db $FA $53 $13 $0D $01 $0D $24 $18 $29 $23 $05 $91 $28 $5F $01 $AC
	.db $06 $AC $F8 $D3 $C8 $D6 $48 $40 $D0 $BE $5A $A6 $86 $93 $D7 $C5
	.db $14 $75 $60 $A2 $B6 $8A $08 $60 $E5 $0A $2D $83 $54 $A4 $11 $B1
	.db $52 $44 $FB $09 $A5 $D0 $C4 $03 $8A $CC $65 $E5 $0B $6C $20 $0E
	.db $A5 $10 $48 $2B $A3 $17 $25 $AB $A0 $67 $33 $B4 $F9 $29 $7D $19
	.db $B9 $A5 $AC $BA $40 $CC $BC $D0 $49 $2A $A5 $D2 $90 $07 $47 $3D
	.db $BE $49 $00 $97 $28 $10 $0D $70 $07 $AF $FA $24 $D3 $5C $84 $B4
	.db $B3 $C0 $64 $0E $7C $0A $AD $10 $A5 $08 $40 $28 $3A $F8 $A2 $33
	.db $A7 $F0 $0B $75 $03 $3B $40 $93 $8A $00 $58 $73 $D7 $10 $00 $FD
	.db $4D $24 $E4 $2A $40 $21 $0F $62 $1B $1C $3A $18 $45 $0C $10 $B3
	.db $5F $CF $FB $30 $4A $A4 $3D $90 $22 $54 $58 $62 $F1 $13 $0C $E2
	.db $CD $94 $92 $15 $10 $27 $C9 $57 $00 $32 $03 $29 $15 $4F $C1 $90
	.db $14 $B8 $03 $AC $FD $AE $F5 $83 $9D $00 $00
flashmanStage.map.1:
	.db $18 $0E $17 $0D $04 $05 $26 $06 $07 $0D $EA $16 $F8 $09 $E1 $4F
	.db $01 $2B $0D $10 $64 $08 $18 $54 $02 $03 $56 $01 $17 $08 $0C $11
	.db $12 $44 $0B $0A $0F $02 $A1 $10 $8A $0E $09 $0F $4E $0C $10 $32
	.db $1D $CA $21 $0A $30 $C6 $07 $21 $87 $57 $1A $13 $21 $12 $57 $11
	.db $31 $15 $A0 $80 $10 $56 $10 $40 $23 $14 $10 $07 $A2 $01 $31 $13
	.db $5D $50 $08 $30 $15 $AC $40 $86 $50 $56 $14 $40 $23 $15 $21 $B0
	.db $68 $50 $FA $28 $B0 $80 $D1 $0B $48 $19 $0C $AC $40 $52 $0E $10
	.db $2B $10 $30 $20 $10 $87 $40 $11 $0A $88 $13 $51 $0D $A3 $21 $80
	.db $44 $08 $9F $40 $2B $0C $10 $D9 $10 $A3 $81 $B0 $48 $69 $14 $0F
	.db $02 $B5 $10 $39 $0F $F6 $C0 $23 $11 $12 $64 $10 $62 $0D $9F $40
	.db $1A $13 $60 $1E $40 $57 $15 $D0 $CA $14 $90 $F9 $01 $4D $40 $C2
	.db $47 $20 $20 $07 $48 $01 $20 $B4 $7D $80 $54 $10 $8A $40 $D9 $53
	.db $07 $4A $B7 $68 $A0 $4F $7B $48 $F2 $60 $B9 $1B $C0 $49 $50 $46
	.db $C0 $C8 $10 $FA $3C $40 $46 $13 $56 $F0 $90 $40 $F2 $01 $3E $56
	.db $0B $70 $CF $0E $35 $87 $A4 $99 $B9 $9D $53 $0C $E4 $80 $F2 $45
	.db $A0 $A4 $40 $49 $34 $A0 $AA $60 $14 $50 $89 $86 $15 $48 $40 $0B
	.db $86 $D2 $2C $29 $A9 $36 $20 $68 $CD $A0 $23 $67 $A9 $BD $94 $01
	.db $40 $E2 $07 $04 $0B $62 $08 $19 $13 $02 $0E $31 $0C $0C $15 $82
	.db $AA $70 $F7 $73 $24 $21 $0D $D0 $D3 $68 $BB $73 $3A $6D $0D $14
	.db $90 $76 $C9 $54 $AE $CD $92 $70 $A7 $F7 $22 $86 $49 $0D $40 $A6
	.db $1B $F3 $5A $C0 $6F $9B $32 $66 $40 $54 $AC $06 $A7 $30 $69 $B4
	.db $30 $9A $10 $91 $00 $6E $10 $E4 $12 $90 $65 $44 $29 $39 $05 $90
	.db $74 $8B $56 $A9 $15 $86 $17 $91 $4B $26 $15 $00 $72 $19 $C4 $14
	.db $23 $C0 $9E $D1 $09 $26 $01 $00 $FB $33 $8B $1E $02 $1F $B4 $CF
	.db $90 $05 $20 $21 $22 $23 $0B $10 $08 $AE $B8 $98 $E1 $24 $25 $1A
	.db $26 $23 $27 $03 $0D $A4 $1A $1C $A8 $0B $A4 $CF $B0 $4B $82 $C6
	.db $3A $FF $9A $66 $8A $CB $1D $12 $01 $29 $9F $A0 $41 $A4 $D0 $4E
	.db $AF $8D $12 $02 $23 $06 $41 $80 $B1 $4E $A4 $04 $06 $4D $FF $4D
	.db $5E $BC $DA $DC $3F $A5 $36 $5E $4E $AB $5F $8D $CA $CF $40 $1E
	.db $0B $91 $9F $69 $13 $4B $29 $4E $0A $50 $20 $DB $A6 $5E $D0 $4E
	.db $A4 $9B $21 $48 $B6 $EB $D0 $A0 $B2 $01 $3E $43 $0B $E2 $07 $9A
	.db $90 $1C $A0 $C9 $AE $07 $1E $CF $DA $7C $44 $19 $30 $07 $23 $00
	.db $14 $11 $14 $20 $8C $0B $6C $28 $60 $29 $02 $01 $16 $17 $0D $A6
	.db $C0 $15 $0E $2A $2B $01 $90 $C0 $CD $0A $3C $19 $01 $4C $00 $0D
	.db $AE $20 $C5 $75 $04 $05 $11 $C9 $20 $D2 $62 $17 $08 $B1 $20 $13
	.db $23 $EE $51 $0E $18 $20 $14 $D9 $9D $A1 $10 $4D $20 $04 $ED $50
	.db $10 $FE $43 $20 $0E $10 $02 $19 $2D $03 $84 $04 $FE $29 $60 $FA
	.db $91 $91 $07 $4B $60 $48 $F9 $8A $0D $60 $5A $E9 $40 $0B $5D $60
	.db $FE $46 $6A $85 $C0 $14 $08 $D1 $41 $52 $0B $C0 $69 $78 $9A $48
	.db $0C $C0 $30 $04 $96 $F0 $94 $10 $2F $98 $00
.ends



.slot 2
.section "flashmanStage.transitions" superfree
flashmanStage.stageLoader:	
	.db :flashmanStage.tiles
	.db 158
	.dw flashmanStage.tiles

	.db :flashmanMusic
	.dw flashmanMusic	
	
	.db :flashmanStage.metaTiles
	.dw flashmanStage.metaTiles
	
	;colision table
	.db $00 $53 $90 $01 $70 $A6 $06 $E1 $C2 $94 $11 $E0 $80 $AC $01 $E1
	.db $09 $80 $00
	
	.db :flashmanStage.maps
	
flashmanStage.transition.0:
	.db LoadNewPaletteFlag | CheckpointFlag | EndingTransitionsFlag | LoadGameplayMapFlag
	
	;megaman checkpoint position
	.db $94	
	
	;palette
	.db $00 $3F $20 $35 $2D
	paletteAnimationSetUp 32, 3, 6
	.db $39 $34 $39 $34 $3e $3c
	.db $39 $34 $3e $3c $39 $34 
	.db $3e $3c $39 $34 $39 $34
    ;border color
	.db PaletteNewAddressMark | 16
	.db PaletteEndingMark | $20
	
	configureNextTransitions TransitB, flashmanStage.transition.1
	
	;new map to load
	.dw flashmanStage.map.0
	
	configureMapLimits OrientationFoward, OrientationHor, 0, 7
	
flashmanStage.transition.1:
	.db EndingTransitionsFlag

	configureNextTransitions TransitB, flashmanStage.transition.2
	configureMapLimits OrientationFoward, OrientationVert, 7, 6 

flashmanStage.transition.2:
	.db CheckpointFlag | EndingTransitionsFlag | LoadGameplayMapFlag
	
	;megaman checkpoint position
	.db $74	
	
	configureNextTransitions TransitR, flashmanStage.transition.3
	
	;new map to load
	.dw flashmanStage.map.1
	
	configureMapLimits OrientationFoward, OrientationHor, 0, 5

flashmanStage.transition.3:
	.db EndingTransitionsFlag
	
	configureNextTransitions TransitR, flashmanStage.transition.4
	configureMapLimits OrientationFoward, OrientationHor, 5, 1

flashmanStage.transition.4:
	.db LoadNewPaletteFlag
	
flashmanPalette:
	.db PaletteNewAddressMark | 24
	.db $34 $2F
	.db $1F | PaletteEndingMark
	
	configureMapLimits OrientationFoward, OrientationHor, 6, 1
.ends


