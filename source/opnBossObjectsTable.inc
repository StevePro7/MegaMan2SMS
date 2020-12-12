.ifndef __BOSS_ATTRIBUTES_INC__
.define __BOSS_ATTRIBUTES_INC__

.define bubbleman.anim 1
.define bubbleman.anim.numFrames 5
.define airman.anim 6
.define airman.anim.numFrames 17
.define quickman.anim 23
.define quickman.anim.numFrames 10
.define heatman.anim 33
.define heatman.anim.numFrames 24
.define woodman.anim 57
.define woodman.anim.numFrames 9
.define metalman.anim 66
.define metalman.anim.numFrames 6
.define flashman.anim 72
.define flashman.anim.numFrames 8
.define crashman.anim 80
.define crashman.anim.numFrames 5

.slot 2
.section "opnBossObjectsTable" align $100 superfree
opnBossObjectsTable:
	.dw bubbleman.0.addr
	.dw bubbleman.0.addr
	.dw bubbleman.0.addr
	.dw bubbleman.1.addr
	.dw bubbleman.2.addr
	.dw airman.0.addr
	.dw airman.1.addr
	.dw airman.1.addr
	.dw airman.2.addr
	.dw airman.3.addr
	.dw airman.2.addr
	.dw airman.3.addr
	.dw airman.2.addr
	.dw airman.3.addr
	.dw airman.1.addr
	.dw airman.2.addr
	.dw airman.3.addr
	.dw airman.2.addr
	.dw airman.3.addr
	.dw airman.2.addr
	.dw airman.3.addr
	.dw airman.1.addr
	.dw quickman.0.addr
	.dw quickman.1.addr
	.dw quickman.2.addr
	.dw quickman.3.addr
	.dw quickman.4.addr
	.dw quickman.5.addr
	.dw quickman.6.addr
	.dw quickman.7.addr
	.dw quickman.8.addr
	.dw quickman.3.addr
	.dw heatman.0.addr
	.dw heatman.1.addr
	.dw heatman.1.addr
	.dw heatman.2.addr
	.dw heatman.2.addr
	.dw heatman.3.addr
	.dw heatman.4.addr
	.dw heatman.5.addr
	.dw heatman.4.addr
	.dw heatman.5.addr
	.dw heatman.4.addr
	.dw heatman.5.addr
	.dw heatman.4.addr
	.dw heatman.5.addr
	.dw heatman.4.addr
	.dw heatman.5.addr
	.dw heatman.4.addr
	.dw heatman.5.addr
	.dw heatman.4.addr
	.dw heatman.5.addr
	.dw heatman.4.addr
	.dw heatman.5.addr
	.dw heatman.4.addr
	.dw heatman.3.addr
	.dw woodman.0.addr
	.dw woodman.1.addr
	.dw woodman.2.addr
	.dw woodman.3.addr
	.dw woodman.2.addr
	.dw woodman.3.addr
	.dw woodman.2.addr
	.dw woodman.3.addr
	.dw woodman.1.addr
	.dw metalman.0.addr
	.dw metalman.1.addr
	.dw metalman.1.addr
	.dw metalman.1.addr
	.dw metalman.2.addr
	.dw metalman.3.addr
	.dw flashman.0.addr
	.dw flashman.1.addr
	.dw flashman.2.addr
	.dw flashman.3.addr
	.dw flashman.4.addr
	.dw flashman.5.addr
	.dw flashman.6.addr
	.dw flashman.3.addr
	.dw crashman.0.addr
	.dw crashman.1.addr
	.dw crashman.1.addr
	.dw crashman.2.addr
	.dw crashman.3.addr	
bubbleman.0.addr:
	.db 10
	.db $e0 $f8 $14
	.db $e8 $f7 $16
	.db $e8 $ff $18
	.db $f0 $f0 $1A
	.db $f0 $f8 $1C
	.db $f0 $00 $1E
	.db $f8 $f0 $20
	.db $f8 $f8 $22
	.db $f8 $00 $24
	.db $f8 $08 $26
bubbleman.1.addr:	
	.db 12
	.db $e0 $f2 $28
	.db $e0 $fa $2A
	.db $e8 $f0 $2c
	.db $e8 $f8 $2E
	.db $e8 $00 $30
	.db $f0 $f0 $32
	.db $f0 $f8 $34
	.db $f0 $00 $36
	.db $f8 $f0 $38
	.db $f8 $f8 $3A
	.db $f8 $00 $3C
	.db $f8 $08 $3E
bubbleman.2.addr:	
	.db 12
	.db $e0 $f8 $40
	.db $e8 $f3 $42
	.db $e8 $fb $44
	.db $e8 $03 $46
	.db $f0 $f0 $48
	.db $f0 $f8 $4A
	.db $f0 $00 $4C
	.db $f0 $08 $4E
	.db $f8 $f0 $50
	.db $f8 $f8 $52
	.db $f8 $00 $54
	.db $f8 $08 $26
airman.0.addr:
	.db 18
	.db $e0 $f6 $34
	.db $e0 $fe $36
	.db $e0 $06 $38
	.db $e0 $0e $3A
	.db $e8 $f0 $3C
	.db $e8 $f8 $3E
	.db $e8 $00 $40
	.db $e8 $08 $42
	.db $e8 $10 $44
	.db $f0 $f0 $5E
	.db $f0 $f8 $60
	.db $f0 $00 $4A
	.db $f0 $08 $62
	.db $f8 $f5 $64
	.db $f8 $fd $66
	.db $f8 $05 $68
	.db $00 $f8 $6A
	.db $ff $07 $6A
airman.1.addr:
	.db 16
	.db $e0 $f0 $14
	.db $e0 $f8 $16
	.db $e0 $00 $18
	.db $e0 $08 $1A
	.db $e8 $f0 $1C
	.db $e8 $f8 $1E
	.db $e8 $00 $20
	.db $e8 $08 $22
	.db $f0 $f0 $24
	.db $f0 $f8 $26
	.db $f0 $00 $28
	.db $f0 $08 $2A
	.db $f8 $f0 $2c
	.db $f8 $f8 $2E
	.db $f8 $00 $30
	.db $f8 $08 $32
airman.2.addr:
	.db 17
	.db $e0 $f6 $34
	.db $e0 $fe $36
	.db $e0 $06 $38
	.db $e0 $0e $3A
	.db $e8 $f0 $3C
	.db $e8 $f8 $3E
	.db $e8 $00 $40
	.db $e8 $08 $42
	.db $e8 $10 $44
	.db $f0 $f0 $46
	.db $f0 $f8 $48
	.db $f0 $00 $4A
	.db $f0 $08 $4C
	.db $f8 $f0 $4E
	.db $f8 $f8 $50
	.db $f8 $00 $52
	.db $f8 $08 $54
airman.3.addr:
	.db 17
	.db $e0 $f6 $34
	.db $e0 $fe $36
	.db $e0 $06 $38
	.db $e0 $0e $3A
	.db $e8 $f0 $3C
	.db $e8 $f8 $56
	.db $e8 $00 $58
	.db $e8 $08 $42
	.db $e8 $10 $44
	.db $f0 $f0 $46
	.db $f0 $f8 $5A
	.db $f0 $00 $5C
	.db $f0 $08 $4C
	.db $f8 $f0 $4E
	.db $f8 $f8 $50
	.db $f8 $00 $52
	.db $f8 $08 $54
quickman.0.addr:
	.db 11
	.db $e0 $f3 $26
	.db $e0 $03 $28
	.db $e8 $f2 $14
	.db $e8 $fa $16
	.db $e8 $02 $18
	.db $f0 $f4 $1A
	.db $f0 $fc $1C
	.db $f0 $04 $1E
	.db $f8 $f4 $20
	.db $f8 $fc $22
	.db $00 $fd $24
quickman.1.addr:
	.db 11
	.db $e0 $f4 $26
	.db $e0 $04 $28
	.db $e8 $f4 $2A
	.db $e8 $fc $2c
	.db $e8 $04 $2E
	.db $f0 $f4 $30
	.db $f0 $fc $32
	.db $f0 $04 $34
	.db $f8 $f4 $36
	.db $f8 $fc $38
	.db $f8 $04 $3A
quickman.2.addr:
	.db 11
	.db $e0 $f0 $26
	.db $e0 $00 $28
	.db $e8 $ec $52
	.db $e8 $f4 $54
	.db $e8 $fc $56
	.db $f0 $f4 $58
	.db $f0 $fc $5A
	.db $f0 $04 $5C
	.db $f8 $f4 $5E
	.db $f8 $fc $60
	.db $f8 $04 $62
quickman.3.addr:
	.db 11
	.db $e0 $04 $3C
	.db $e8 $f4 $3E
	.db $e8 $fc $40
	.db $e8 $04 $42
	.db $f0 $f4 $44
	.db $f0 $fc $46
	.db $f0 $04 $48
	.db $f8 $ec $4A
	.db $f8 $f4 $4C
	.db $f8 $fc $4E
	.db $f8 $04 $50
quickman.4.addr:
	.db 11
	.db $e0 $04 $3C
	.db $e8 $f4 $64
	.db $e8 $fc $40
	.db $e8 $04 $42
	.db $f0 $f4 $44
	.db $f0 $fc $46
	.db $f0 $04 $48
	.db $f8 $ec $4A
	.db $f8 $f4 $4C
	.db $f8 $fc $4E
	.db $f8 $04 $50
quickman.5.addr: ; Lbl_8a4e
	.db 11
	.db $e0 $04 $3C
	.db $e8 $f4 $3E
	.db $e8 $fc $68
	.db $e8 $04 $42
	.db $f0 $f4 $44
	.db $f0 $fc $46
	.db $f0 $04 $48
	.db $f8 $ec $4A
	.db $f8 $f4 $4C
	.db $f8 $fc $4E
	.db $f8 $04 $50
quickman.6.addr: 
	.db 11
	.db $e0 $04 $66
	.db $e8 $f4 $3E
	.db $e8 $fc $6A
	.db $e8 $04 $42
	.db $f0 $f4 $44
	.db $f0 $fc $46
	.db $f0 $04 $48
	.db $f8 $ec $4A
	.db $f8 $f4 $4C
	.db $f8 $fc $4E
	.db $f8 $04 $50
quickman.7.addr: 
	.db 12,
	.db $e0 $04 $6C
	.db $e8 $f4 $3E
	.db $e8 $fc $40
	.db $e8 $04 $42
	.db $e8 $04 $6E
	.db $f0 $f4 $44
	.db $f0 $fc $46
	.db $f0 $04 $48
	.db $f8 $ec $4A
	.db $f8 $f4 $4C
	.db $f8 $fc $4E
	.db $f8 $04 $50
quickman.8.addr: 
	.db 11
	.db $e0 $04 $70
	.db $e8 $f4 $3E
	.db $e8 $fc $40
	.db $e8 $04 $42
	.db $f0 $f4 $44
	.db $f0 $fc $46
	.db $f0 $04 $48
	.db $f8 $ec $4A
	.db $f8 $f4 $4C
	.db $f8 $fc $4E
	.db $f8 $04 $50
heatman.0.addr:
	.db 10
	.db $e0 $f8 $8A
	.db $e0 $00 $8C
	.db $e8 $f4 $8E
	.db $e8 $fc $92
	.db $e8 $04 $94
	.db $f0 $f4 $96
	.db $f0 $fc $98
	.db $f0 $04 $9A
	.db $f8 $f7 $9C
	.db $f8 $04 $9E
heatman.1.addr:	
	.db 10
	.db $e8 $f8 $40
	.db $e8 $00 $42
	.db $f0 $f0 $44
	.db $f0 $f8 $46
	.db $f0 $00 $48
	.db $f0 $08 $45	;Espelhado
	.db $f8 $f0 $4A
	.db $f8 $f8 $4C
	.db $f8 $00 $4E
	.db $f8 $08 $50
heatman.2.addr:
	.db 11
	.db $e0 $fa $2E
	.db $e0 $04 $2E
	.db $e8 $f4 $30
	.db $e8 $fc $32
	.db $e8 $04 $52
	.db $f0 $f4 $34
	.db $f0 $fc $36
	.db $f0 $04 $38
	.db $f8 $f4 $3A
	.db $f8 $fc $3C
	.db $f8 $04 $3E
heatman.3.addr:
	.db 13
	.db $e0 $fa $14
	.db $e8 $f0 $16
	.db $e8 $f8 $18
	.db $e8 $00 $1A
	.db $e8 $08 $1C
	.db $f0 $f0 $1E
	.db $f0 $f8 $20
	.db $f0 $00 $22
	.db $f0 $08 $24
	.db $f8 $f0 $26
	.db $f8 $f8 $28
	.db $f8 $00 $2A
	.db $f8 $08 $2c

heatman.4.addr:	
	.db 16
	.db $e0 $f0 $54
	.db $e0 $f8 $56
	.db $e0 $00 $58
	.db $e0 $08 $5A
	.db $e8 $f0 $5C
	.db $e8 $f8 $18
	.db $e8 $00 $5E
	.db $e8 $08 $60
	.db $f0 $f0 $62
	.db $f0 $f8 $20
	.db $f0 $00 $22
	.db $f0 $08 $64
	.db $f8 $f0 $66
	.db $f8 $f8 $68
	.db $f8 $00 $6A
	.db $f8 $08 $6C
	                
heatman.5.addr:       
	.db 16          
	.db $e0 $f0 $6E
	.db $e0 $f8 $70
	.db $e0 $00 $72
	.db $e0 $08 $74
	.db $e8 $f0 $76
	.db $e8 $f8 $18
	.db $e8 $00 $78
	.db $e8 $08 $7A
	.db $f0 $f0 $7C
	.db $f0 $f8 $20
	.db $f0 $00 $22
	.db $f0 $08 $64
	.db $f8 $f0 $66
	.db $f8 $f8 $68
	.db $f8 $00 $6A
	.db $f8 $08 $6C

woodman.0.addr:
	.db 16 
	.db $e0 $f8 $14 
	.db $e0 $00 $16 
	.db $e0 $08 $6c 
	.db $e8 $f0 $6e 
	.db $e8 $f8 $70 
	.db $e8 $00 $1e 
	.db $e8 $08 $72 
	.db $f0 $f0 $74 
	.db $f0 $f8 $76 
	.db $f0 $00 $78 
	.db $f0 $08 $7a 
	.db $f8 $f0 $7c 
	.db $f8 $f8 $7e 
	.db $f8 $00 $7f 
	.db $f8 $08 $80 
	.db $e0 $f0 $6a 
woodman.1.addr:	
	.db 15
	.db $e0 $f8 $14
	.db $e0 $00 $16
	.db $e0 $08 $18
	.db $e8 $f0 $1a
	.db $e8 $f8 $1c
	.db $e8 $00 $1e
	.db $e8 $08 $20
	.db $f0 $f0 $22
	.db $f0 $f8 $24
	.db $f0 $00 $26
	.db $f0 $08 $28
	.db $f8 $f0 $2a
	.db $f8 $f8 $2c
	.db $f8 $00 $2d
	.db $f8 $08 $2e
woodman.2.addr:	
	.db $0f 
	.db $e0 $f8 $30
	.db $e0 $00 $32
	.db $e0 $08 $34
	.db $e8 $f0 $36
	.db $e8 $f8 $38
	.db $e8 $00 $3a
	.db $e8 $08 $3c
	.db $f0 $f5 $3e
	.db $f0 $fd $40
	.db $f0 $05 $42
	.db $f8 $f0 $44
	.db $f8 $f8 $46
	.db $f8 $00 $48
	.db $f8 $08 $4a

woodman.3.addr:	
	.db $11
	.db $e0 $f8 $30
	.db $e0 $00 $32
	.db $e0 $08 $34
	.db $e8 $f0 $4c
	.db $e8 $f8 $4e
	.db $e8 $00 $50
	.db $e8 $08 $52
	.db $f0 $f0 $54
	.db $f0 $f8 $56
	.db $f0 $00 $58
	.db $f0 $08 $5a
	.db $f8 $f0 $44
	.db $f8 $f8 $46
	.db $f8 $00 $48
	.db $f8 $08 $4a
metalman.0.addr:
	.db 9
	.db $e8 $f8 $14
	.db $e8 $00 $48
	.db $f0 $f4 $4a
	.db $f0 $fc $4c
	.db $f0 $04 $4e
	.db $f8 $f4 $50
	.db $f8 $fc $52
	.db $f8 $04 $54
	.db $00 $fa $56	
metalman.1.addr:
	.db 8
	.db $e8 $f8 $14
	.db $e8 $00 $16
	.db $f0 $f4 $18
	.db $f0 $fc $1a
	.db $f0 $04 $1c
	.db $f8 $f4 $1e
	.db $f8 $fc $20
	.db $f8 $04 $22	
metalman.2.addr:
	.db 10,
	.db $e8 $f4 $24
	.db $e8 $fc $26
	.db $e8 $04 $28
	.db $f0 $f1 $2a
	.db $f0 $f9 $2c
	.db $f0 $01 $2e
	.db $f8 $ec $30
	.db $f8 $f4 $32
	.db $f8 $fc $34
	.db $f8 $04 $36
metalman.3.addr:
	.db 8 
	.db $e8 $f4 $38
	.db $e8 $fc $3a
	.db $e8 $04 $3c
	.db $f0 $f9 $3e
	.db $f0 $01 $40
	.db $f8 $f4 $42
	.db $f8 $fc $44
	.db $f8 $04 $46	
flashman.0.addr:	
	.db 13
	.db $e0 $f1 $2c
	.db $e0 $fe $14
	.db $e8 $f0 $2e
	.db $e8 $f8 $30
	.db $e8 $00 $32
	.db $e8 $08 $34
	.db $f0 $f8 $7e
	.db $f0 $00 $80
	.db $f0 $08 $82
	.db $f8 $f8 $84
	.db $f8 $00 $86
	.db $00 $f8 $88
	.db $00 $00 $8a
flashman.1.addr:	
	.db 12 
	.db $e0 $fc $14
	.db $e8 $f6 $16
	.db $e8 $fe $18
	.db $e8 $06 $1a
	.db $f0 $f0 $1c
	.db $f0 $f8 $1e
	.db $f0 $00 $20
	.db $f0 $08 $22
	.db $f8 $f0 $24
	.db $f8 $f8 $26
	.db $f8 $00 $28
	.db $f8 $08 $2a
flashman.2.addr:	
	.db 13 
	.db $e0 $f1 $2c
	.db $e0 $fe $14
	.db $e8 $f0 $2e
	.db $e8 $f8 $30
	.db $e8 $00 $32
	.db $e8 $08 $34
	.db $f0 $f8 $36
	.db $f0 $00 $38
	.db $f0 $08 $3a
	.db $f8 $f0 $3c
	.db $f8 $f8 $3e
	.db $f8 $00 $40
	.db $f8 $08 $42
flashman.3.addr:
	.db 12
	.db $e8 $f0 $44
	.db $e8 $f8 $46
	.db $e8 $00 $48
	.db $e8 $08 $4a
	.db $f0 $f0 $4c
	.db $f0 $f8 $4e
	.db $f0 $00 $50
	.db $f0 $08 $52
	.db $f8 $f0 $54
	.db $f8 $f8 $56
	.db $f8 $00 $58
	.db $f8 $08 $5a
flashman.4.addr:
	.db 12
	.db $e8 $f0 $44
	.db $e8 $f8 $46
	.db $e8 $00 $5c
	.db $e8 $08 $4a
	.db $f0 $f0 $4c
	.db $f0 $f8 $4e
	.db $f0 $00 $50
	.db $f0 $08 $52
	.db $f8 $f0 $54
	.db $f8 $f8 $56
	.db $f8 $00 $58
	.db $f8 $08 $5a
flashman.5.addr:
	.db 12
	.db $e8 $f0 $44
	.db $e8 $f8 $46
	.db $e8 $00 $48
	.db $e8 $08 $4a
	.db $f0 $f0 $4c
	.db $f0 $f8 $92
	.db $f0 $00 $94
	.db $f0 $08 $52
	.db $f8 $f0 $54
	.db $f8 $f8 $5e
	.db $f8 $00 $60
	.db $f8 $08 $5a
flashman.6.addr:
	.db 12
	.db $e8 $f0 $88
	.db $e8 $f8 $8a
	.db $e8 $00 $8c
	.db $e8 $08 $8e
	.db $f0 $f0 $90
	.db $f0 $f8 $4e
	.db $f0 $00 $50
	.db $f0 $08 $96
	.db $f8 $f0 $98
	.db $f8 $f8 $62
	.db $f8 $00 $64
	.db $f8 $08 $9a
crashman.0.addr:
	.db 13
	.db $e8 $ee $40
	.db $e8 $f6 $42
	.db $e8 $fe $44
	.db $e8 $06 $46
	.db $f0 $ee $48
	.db $f0 $f6 $4a
	.db $f0 $fe $4c
	.db $f0 $06 $4e
	.db $f8 $f8 $58
	.db $f8 $00 $5a
	.db $f8 $08 $5c
	.db $00 $f8 $5e
	.db $00 $00 $60
crashman.1.addr:	
	.db 10,
	.db $e8 $f8 $14
	.db $e8 $00 $16
	.db $f0 $f0 $18
	.db $f0 $f8 $1a
	.db $f0 $00 $1c
	.db $f0 $08 $1e
	.db $f8 $f0 $20
	.db $f8 $f8 $22
	.db $f8 $00 $24
	.db $f8 $08 $26
crashman.2.addr:	
	.db 12
	.db $e0 $f0 $28
	.db $e0 $f8 $2a
	.db $e8 $f0 $2c
	.db $e8 $f8 $2e
	.db $e8 $00 $30
	.db $f0 $f0 $32
	.db $f0 $f8 $34
	.db $f0 $00 $36
	.db $f8 $f0 $38
	.db $f8 $f8 $3a
	.db $f8 $00 $3c
	.db $f8 $08 $3e
crashman.3.addr:	
	.db 12  
	.db $e8 $f0 $40
	.db $e8 $f8 $42
	.db $e8 $00 $44
	.db $e8 $08 $46
	.db $f0 $f0 $48
	.db $f0 $f8 $4a
	.db $f0 $00 $4c
	.db $f0 $08 $4e
	.db $f8 $f0 $50
	.db $f8 $f8 $52
	.db $f8 $00 $54
	.db $f8 $08 $56		
.ends

.endif