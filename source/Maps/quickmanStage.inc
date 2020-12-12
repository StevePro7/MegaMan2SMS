.slot 2
.section "quickmanStage.tiles" superfree
quickmanStage.tiles:
	.incbin "imagens\quickmanstage.psgcompr" skip 2
.ends

.slot 2
.section "quickmanStage.metaTiles" superfree
quickmanStage.metaTiles:
	.dw $0138
	.db $00 $A7 $01 $F9 $FF $0A $FC $ED $33 $01 $E9 $05 $FC $FB $CA $C2
	.db $C6 $25 $F9 $4F $08 $F7 $D8 $04 $C3 $03 $72 $C5 $7E $F5 $76 $DC
	.db $67 $F4 $09 $F3 $EC $04 $C7 $F8 $F1 $CF $09 $D0 $8F $EF $94 $02
	.db $0F $B7 $05 $EE $D0 $3B $B1 $3C $CE $37 $EC $64 $C1 $E2 $01 $EA
	.db $FA $94 $02 $1F $E7 $03 $E9 $A3 $C1 $E3 $01 $E8 $FA $14 $6C $AB
	.db $40 $09 $E6 $AF $02 $F9 $E5 $13 $E4 $F3 $A7 $F3 $A6 $F3 $A5 $F3
	.db $A4 $F6 $00
.ends

.slot 2
.section "quickmanStage.maps" superfree
quickmanStage.maps:
quickmanStage.map.0:
	.db $00 $E0 $01 $DC $06 $29 $06 $3D $44 $02 $A8 $01 $03 $04 $72 $05
	.db $83 $A6 $05 $20 $06 $07 $71 $08 $57 $09 $10 $6C $1F $06 $08 $53
	.db $0A $24 $62 $04 $0B $0C $06 $06 $22 $E3 $49 $24 $88 $04 $0D $0E
	.db $3F $D4 $11 $09 $AB $50 $46 $5E $22 $29 $09 $40 $A3 $22 $21 $10
	.db $B7 $9F $EA $03 $A1 $30 $20 $0B $D9 $09 $0D $0A $4C $8A $08 $D1
	.db $3C $21 $91 $01 $6D $90 $12 $A1 $A0 $24 $A1 $69 $36 $A5 $21 $E4
	.db $0F $51 $10 $01 $FE $2D $5B $0D $50 $90 $02 $10 $B2 $11 $9A $C4
	.db $14 $EA $E1 $5D $06 $1A $01 $21 $04 $42 $12 $02 $1A $38 $0C $13
	.db $14 $A6 $9A $8A $0E $0F $0C $D5 $96 $99 $21 $15 $A3 $1C $B6 $21
	.db $82 $32 $87 $15 $93 $2A $42 $08 $82 $63 $41 $16 $17 $29 $23 $0F
	.db $82 $68 $3F $48 $DE $12 $03 $34 $52 $15 $2F $04 $8A $09 $10 $A0
	.db $69 $FF $23 $65 $42 $10 $46 $FA $42 $3E $41 $10 $18 $FA $09 $A5
	.db $C2 $A3 $DC $48 $50 $48 $E2 $F2 $13 $16 $B5 $3F $20 $42 $01 $9A
	.db $2D $4E $00 $82 $9A $14 $36 $AC $9A $85 $20 $29 $9A $92 $03 $38
	.db $20 $10 $A4 $DD $49 $09 $06 $94 $E8 $8F $01 $14 $10 $A5 $23 $E8
	.db $05 $C5 $69 $20 $16 $10 $82 $AA $05 $19 $20 $16 $56 $41 $2C $AE
	.db $D0 $DE $E4 $E9 $10 $A4 $38 $C4 $05 $8D $3F $A4 $21 $38 $E4 $01
	.db $8C $60 $0A $52 $13 $30 $94 $80 $A4 $98 $00 $01 $91 $80 $6A $24
	.db $CC $41 $16 $93 $24 $45 $01 $3D $F6 $0D $0C $B4 $60 $BF $95 $8E
	.db $29 $28 $0F $10 $47 $20 $48 $9E $DA $02 $46 $0A $D2 $FF $66 $9E
	.db $02 $A6 $FA $D2 $0A $39 $A3 $49 $BD $1D $0C $FE $BA $C6 $9C $C6
	.db $93 $FE $AB $C6 $34 $C5 $8E $DF $68 $3C $A2 $4F $F6 $2C $00 $09
	.db $A6 $9E $86 $4F $D2 $3C $74 $00 $CA $30 $26 $09 $00 $72 $86 $20
	.db $0F $06 $49 $09 $B4 $D1 $A6 $47 $C0 $7F $B3 $B2 $BA $53 $10 $D1
	.db $20 $D0 $40 $DA $04 $96 $01 $88 $25 $05 $12 $A5 $E1 $A1 $E5 $93
	.db $05 $29 $DE $D6 $B2 $D3 $65 $08 $3F $D8 $91 $A4 $50 $E2 $04 $91
	.db $85 $45 $E1 $A0 $10 $E0 $84 $04 $AC $25 $8A $9E $1A $24 $6E $30
	.db $D0 $A1 $20 $91 $EA $9A $21 $16 $F2 $82 $65 $2A $8D $12 $5A $08
	.db $67 $20 $29 $4F $ED $40 $0A $30 $45 $11 $45 $DE $76 $01 $F8 $86
	.db $80 $84 $E6 $87 $D0 $20 $DE $8D $10 $26 $00 $A3 $F0 $65 $05 $34
	.db $1F $64 $FC $15 $2E $E0 $42 $FC $D0 $01 $23 $06 $34 $E5 $39 $01
	.db $63 $90 $95 $80 $9D $AC $E3 $53 $FD $4A $40 $09 $A6 $6E $D6 $14
	.db $49 $D0 $D3 $56 $ED $32 $3F $09 $88 $70 $45 $5B $69 $21 $E4 $32
	.db $20 $14 $10 $91 $20 $99 $18 $90 $19 $94 $60 $1A $84 $94 $3C $90
	.db $7B $F5 $50 $3C $0E $E4 $32 $80 $1B $88 $FA $88 $EF $F2 $65 $E0
	.db $35 $CA $64 $D0 $54 $08 $EF $8A $01 $10 $7A $32 $20 $33 $F6 $59
	.db $0D $2C $CA $02 $01 $DA $1C $6C $87 $8A $4B $96 $60 $A6 $E9 $B8
	.db $20 $5D $05 $1A $CD $1C $20 $4D $90 $A3 $D1 $DF $B4 $06 $CD $72
	.db $0B $10 $11 $05 $04 $95 $C0 $43 $10 $5C $6A $D3 $24 $F0 $1D $FF
	.db $E4 $30 $5A $6E $F0 $AF $40 $36 $21 $A0 $8E $79 $81 $6D $11 $25
	.db $D0 $36 $F0 $DA $C1 $CF $EC $92 $04 $8E $0C $43 $F8 $59 $0A $A6
	.db $09 $8D $FC $12 $03 $CA $E0 $64 $08 $07 $B6 $B2 $41 $F4 $27 $E0
	.db $25 $07 $9A $E2 $45 $0E $A5 $32 $F2 $09 $8E $32 $A0 $5B $12 $B8
	.db $5D $F8 $C9 $07 $CC $02 $BB $18 $B4 $23 $4A $30 $04 $20 $C9 $28
	.db $EC $20 $72 $51 $C2 $21 $10 $AC $62 $E8 $50 $EB $33 $13 $FD $32
	.db $40 $1D $8D $0B $09 $18 $60 $1D $FD $4C $01 $06 $A4 $30 $52 $1D
	.db $1D $7F $AC $60 $4E $1D $36 $37 $88 $8A $10 $BB $9E $ED $CA $62
	.db $55 $9E $27 $EF $59 $32 $D0 $C0 $B5 $98 $32 $05 $A5 $C0 $B4 $41
	.db $66 $30 $5E $86 $3E $D6 $60 $29 $30 $A3 $3D $10 $AC $CE $52 $32
	.db $40 $09 $4E $62 $00 $1E $60 $EB $1C $01 $85 $25 $BB $22 $53 $20
	.db $EF $90 $10 $51 $DE $44 $F0 $2D $10 $54 $B6 $6D $A2 $14 $E2 $6C
	.db $A2 $05 $96 $7A $52 $1C $10 $AC $62 $8C $10 $7D $1D $94 $62 $5A
	.db $0A $50 $32 $2E $62 $5A $BA $52 $A8 $7E $10 $5A $BB $DE $DD $2D
	.db $80 $A9 $1C $00 $6A $B2 $C8 $2E $23 $30 $A1 $B0 $34 $5D $39 $20
	.db $4E $00 $52 $E2 $9D $29 $50 $CF $F2 $2D $32 $0E $E0 $68 $41 $C0
	.db $DB $43 $85 $E0 $D0 $22 $46 $E0 $9A $45 $9E $10 $94 $34 $C8 $60
	.db $E9 $4E $80 $8A $30 $BA $52 $53 $62 $A9 $74 $49 $67 $F6 $21 $C2
	.db $E8 $20 $5A $3F $10 $29 $00 $48 $50 $DE $8F $60 $C8 $80 $75 $22
	.db $BE $8D $80 $B4 $DD $6D $80 $A1 $5D $50 $ED $21 $0F $50 $42 $10
	.db $68 $12 $10 $FC $8E $40 $8B $5E $46 $40 $70 $91 $30 $AD $1F $60
	.db $90 $40 $D1 $30 $92 $8C $7F $13 $F2 $05 $B3 $04 $E8 $10 $5E $4A
	.db $16 $2C $84 $01 $9C $D6 $53 $D5 $39 $90 $68 $02 $A4 $2A $10 $60
	.db $00
quickmanStage.map.1:
	.db $06 $A4 $01 $78 $07 $28 $09 $14 $07 $F1 $59 $0F $1A $10 $7F $8E
	.db $FD $FE $3D $64 $1A $0A $1B $13 $ED $14 $1A $23 $68 $3A $33 $F2
	.db $0D $22 $2C $1E $4F $2B $07 $1C $91 $09 $88 $07 $53 $7C $09 $FB
	.db $4F $10 $7F $A5 $BF $A1 $10 $A2 $01 $8F $10 $20 $01 $81 $0C $06
	.db $4A $FA $42 $10 $68 $1F $10 $CF $71 $43 $88 $90 $1A $46 $10 $91
	.db $20 $90 $DE $46 $31 $42 $CE $E6 $3B $8D $10 $3E $C7 $F2 $1A $34
	.db $A5 $2E $4F $50 $C8 $1A $E8 $B0 $48 $8C $73 $FD $69 $A0 $A3 $36
	.db $C0 $BC $D7 $BB $68 $02 $C0 $EF $95 $0F $DA $B5 $34 $40 $FF $1B
	.db $53 $EB $E8 $0F $2B $10 $17 $9A $67 $09 $05 $15 $3C $2A $09 $53
	.db $04 $10 $ED $C2 $31 $1B $27 $FC $6A $41 $0A $D2 $0D $D8 $21 $D6
	.db $3B $EC $74 $8F $BB $42 $20 $45 $E7 $0F $10 $57 $20 $45 $08 $A3
	.db $C1 $F1 $B5 $04 $3D $05 $0F $10 $7F $85 $E4 $1A $7D $EB $DC $2A
	.db $23 $1A $EA $45 $5D $A8 $40 $D2 $02 $6D $02 $C3 $43 $02 $95 $99
	.db $47 $04 $BF $02 $D2 $11 $D1 $20 $DF $A6 $EC $C8 $10 $C9 $3B $FA
	.db $BD $65 $30 $29 $F9 $1D $40 $22 $F8 $9A $21 $BB $F4 $FD $74 $65
	.db $13 $3A $39 $4B $FE $6D $EA $A1 $11 $DB $CD $36 $54 $27 $91 $49
	.db $EF $F4 $24 $E5 $10 $C3 $05 $8A $07 $FE $D2 $44 $98 $51 $10 $01
	.db $21 $37 $EE $93 $05 $2A $08 $01 $C4 $E8 $15 $C6 $16 $05 $04 $0B
	.db $DE $09 $2A $A4 $F9 $B4 $17 $30 $24 $10 $79 $20 $1F $30 $91 $10
	.db $9E $3E $43 $E4 $37 $EF $ED $10 $4B $28 $7F $A5 $10 $29 $58 $48
	.db $10 $4F $B6 $3D $61 $A9 $40 $2A $68 $10 $52 $32 $43 $14 $40 $85
	.db $EF $13 $09 $79 $D8 $F0 $0A $13 $80 $0F $17 $AD $14 $34 $48 $3F
	.db $10 $23 $07 $ED $22 $0E $30 $DA $F8 $1E $10 $AD $C5 $A1 $10 $5B
	.db $FD $D9 $F7 $DA $89 $0B $12 $0C $93 $1C $46 $1C $CF $74 $2A $12
	.db $02 $01 $85 $DF $23 $8F $48 $10 $D2 $14 $20 $93 $C0 $A3 $20 $BC
	.db $70 $90 $86 $D0 $C5 $10 $A6 $C4 $8A $60 $13 $FF $43 $08 $10 $59
	.db $00 $B3 $05 $94 $79 $A3 $80 $20 $7B $68 $21 $C1 $30 $D3 $51 $23
	.db $5B $59 $5F $09 $20 $EE $95 $80 $A1 $10 $C8 $F6 $C8 $06 $CC $02
	.db $02 $87 $9A $03 $21 $47 $E0 $26 $80 $7A $BA $49 $09 $10 $1B $BE
	.db $F9 $0B $0C $62 $A0 $92 $37 $8E $D2 $0D $0E $C5 $A0 $24 $6E $6D
	.db $5D $A1 $44 $20 $21 $10 $36 $22 $44 $87 $10 $34 $80 $64 $30 $3D
	.db $40 $0B $30 $65 $E1 $08 $39 $50 $BF $06 $F1 $AC $70 $7B $1D $A4
	.db $01 $8C $30 $8F $10 $21 $60 $3F $D2 $40 $D1 $60 $43 $20 $D0 $22
	.db $43 $20 $9A $04 $34 $D0 $D1 $3C $90 $E4 $2A $E0 $53 $10 $14 $0F
	.db $11 $B0 $E4 $05 $11 $0A $03 $74 $40 $CD $48 $D6 $BC $D0 $D0 $20
	.db $F0 $E4 $8D $88 $0F $20 $68 $3F $70 $C4 $16 $B6 $57 $46 $60 $76
	.db $96 $07 $C8 $60 $CD $06 $07 $F2 $FA $30 $5B $51 $41 $02 $16 $50
	.db $BD $8C $10 $82 $01 $3E $10 $85 $30 $A3 $60 $44 $1D $7C $14 $AD
	.db $A0 $21 $80 $2E $70 $52 $32 $20 $32 $10 $32 $20 $3E $30 $9A $1E
	.db $8F $C0 $34 $3D $3D $50 $A1 $9D $50 $6F $F5 $20 $B2 $07 $95 $30
	.db $24 $B0 $72 $C2 $4F $39 $5E $1E $9F $02 $1F $A6 $4C $5B $05 $02
	.db $20 $21 $22 $23 $38 $6E $20 $0D $24 $25 $23 $26 $03 $18 $10 $27
	.db $E3 $66 $CA $6F $0C $54 $01 $D1 $10 $EA $A5 $34 $00 $35 $10 $64
	.db $3E $94 $AD $CF $F0 $5C $73 $A4 $B5 $20 $28 $06 $B4 $51 $10 $0E
	.db $DA $06 $42 $30 $34 $10 $D0 $3E $30 $F6 $3E $8D $10 $24 $4F $A1
	.db $30 $5A $17 $40 $5B $43 $42 $B0 $A5 $DA $30 $59 $B0 $42 $01 $D0
	.db $61 $60 $00
.ends

.slot 2
.section "quickmanStage.transitions" superfree
quickmanStage.stageLoader:	
	.db :quickmanStage.tiles
	.db 128
	.dw quickmanStage.tiles

	.db :quickmanMusic
	.dw quickmanMusic
	
	.db :quickmanStage.metaTiles
	.dw quickmanStage.metaTiles

	;collision table
	.db $80 $AB $01 $84 $11 $05 $70 $A4 $0E $D1 $2B $09 $B7 $0C $00
	
	.db :quickmanStage.maps
	
quickmanStage.transition.0:
	.db LoadNewPaletteFlag | CheckpointFlag | EndingTransitionsFlag | LoadGameplayMapFlag
	
	;megaman checkpoint position
	.db $94		
	
	;palette
	.db $00 $14 $3a $02 $39 $03 $0f
	.db PaletteNewAddressMark | 16
	.db $01 | PaletteEndingMark
	configureNextTransitions TransitB, quickmanStage.transition.1

	;new map to load
	.dw quickmanStage.map.0
	
	configureMapLimits OrientationFoward, OrientationVert, 0, 7 
	
quickmanStage.transition.1:
	.db EndingTransitionsFlag
	
	configureNextTransitions TransitB, quickmanStage.transition.2
	configureMapLimits OrientationFoward, OrientationHor, 7, 5 
	
quickmanStage.transition.2:
	.db EndingTransitionsFlag | LoadGameplayMapFlag
	
	configureNextTransitions TransitB, quickmanStage.transition.3
	
	;new map to load
	.dw quickmanStage.map.1
	
	configureMapLimits OrientationFoward, OrientationVert, 0, 7 

quickmanStage.transition.3:
	.db EndingTransitionsFlag
	
	configureNextTransitions TransitR, quickmanStage.transition.4
	configureMapLimits OrientationFoward, OrientationHor, 7, 3 

quickmanStage.transition.4:
	.db CheckpointFlag | EndingTransitionsFlag
	
	;megaman checkpoint position
	.db $94		
		
	configureNextTransitions TransitR, quickmanStage.transition.5
	configureMapLimits OrientationFoward, OrientationVert, 10, 1 
	
quickmanStage.transition.5:
	.db LoadNewPaletteFlag
	
quickmanPalette:
	.db PaletteNewAddressMark | 24
	.db $1b $2F $13 
	.db $13 | PaletteEndingMark

	configureMapLimits OrientationFoward, OrientationVert, 11, 1 
.ends