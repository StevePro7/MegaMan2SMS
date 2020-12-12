.ifndef __OPENINGMAP_INC__
.define __OPENINGMAP_INC__

.define Rep 0
.define Seq %10000000
.slot 2
.section "openingMap" superfree
openingLine.0:
	.db (Rep | (31 << 2) | $01), $98

openingLine.1:
	.db (Rep | (09 << 2) | $01), $98
	.db (Seq | (11 << 2) | $00), $82
	.db (Rep | (09 << 2) | $01), $98

openingLine.2:
	.db (Rep | (08 << 2) | $01), $98
	.db (Seq | (13 << 2) | $00), $8e
	.db (Rep | (08 << 2) | $01), $98

openingLine.3:
	.db (Rep | (07 << 2) | $01), $98
	.db (Seq | (15 << 2) | $00), $9C
	.db (Rep | (07 << 2) | $01), $98

	openingLine.4:
	.db (Rep | (06 << 2) | $01), $98
	.db (Seq | (04 << 2) | $00), $ac
	.db (Seq | (00 << 2) | $00), $ad
	.db (Seq | (01 << 2) | $00), $b1
	.db (Seq | (00 << 2) | $00), $ad
	.db (Seq | (02 << 2) | $00), $b3
	.db (Seq | (00 << 2) | $00), $ad
	.db (Seq | (03 << 2) | $00), $b6
	.db (Seq | (00 << 2) | $02), $ac
	.db (Rep | (06 << 2) | $01), $98

	openingLine.5:
	.db (Rep | (05 << 2) | $01), $98
	.db (Seq | (19 << 2) | $00), $ba
	.db (Rep | (05 << 2) | $01), $98

	openingLine.6:
	.db (Rep | (04 << 2) | $01), $98
	.db (Seq | (14 << 2) | $00), $ce
	.db (Seq | (00 << 2) | $00), $d7
	.db (Seq | (03 << 2) | $00), $dd
	.db (Seq | (00 << 2) | $00), $d7
	.db (Seq | (00 << 2) | $02), $ce
	.db (Rep | (04 << 2) | $01), $98

	openingLine.7:
	.db (Rep | (03 << 2) | $01), $98
	.db (Seq | (17 << 2) | $00), $e1
	.db (Seq | (00 << 2) | $01), $98
	.db (Seq | (03 << 2) | $00), $f3
	.db (Seq | (00 << 2) | $02), $e1
	.db (Rep | (03 << 2) | $01), $98

	openingLine.8:
	.db (Rep | (13 << 2) | $01), $98
	.db (Seq | (01 << 2) | $00), $f7
	.db (Seq | (00 << 2) | $02), $f8
	.db (Seq | (00 << 2) | $02), $f7
	.db (Rep | (13 << 2) | $01), $98

	openingLine.9:
	.db (Rep | (13 << 2) | $01), $98
	.db (Seq | (01 << 2) | $00), $f9
	.db (Seq | (00 << 2) | $02), $fa
	.db (Seq | (00 << 2) | $02), $f9
	.db (Rep | (05 << 2) | $01), $98
	.db (Seq | (01 << 2) | $00), $fb
	.db (Rep | (05 << 2) | $00), $fc

	openingLine.10:
	.db (Rep | (12 << 2) | $01), $98
	.db (Seq | (02 << 2) | $00), $fd
	.db (Seq | (00 << 2) | $02), $ff
	.db (Seq | (00 << 2) | $02), $fe
	.db (Seq | (00 << 2) | $02), $fd
	.db (Rep | (04 << 2) | $01), $98
	.db (Seq | (01 << 2) | $01), $00
	.db (Rep | (05 << 2) | $01), $01

	openingLine.11:
	.db (Rep | (12 << 2) | $01), $98
	.db (Seq | (01 << 2) | $01), $02
	.db (Rep | (02 << 2) | $01), $03
	.db (Seq | (00 << 2) | $03), $02
	.db (Rep | (04 << 2) | $01), $98
	.db (Seq | (01 << 2) | $01), $00
	.db (Rep | (01 << 2) | $01), $01
	.db (Seq | (01 << 2) | $01), $04
	.db (Rep | (01 << 2) | $01), $01

	openingLine.12:
	.db (Rep | (19 << 2) | $01), $98
	.db (Seq | (01 << 2) | $01), $06
	.db (Rep | (01 << 2) | $01), $98
	.db (Seq | (01 << 2) | $01), $00
	.db (Rep | (01 << 2) | $01), $01
	.db (Seq | (01 << 2) | $01), $08
	.db (Rep | (01 << 2) | $01), $01

	openingLine.13:
	.db (Rep | (19 << 2) | $01), $98
	.db (Seq | (02 << 2) | $01), $0a
	.db (Rep | (08 << 2) | $01), $0c

	openingLine.14:
	.db (Rep | (07 << 2) | $01), $98
	.db (Seq | (01 << 2) | $01), $a6
	.db (Seq | (00 << 2) | $01), $AA
	.db (Seq | (00 << 2) | $01), $a5
	.db (Seq | (00 << 2) | $01), $99
	.db (Seq | (00 << 2) | $01), $a4
	.db (Rep | (05 << 2) | $01), $98
	.db (Seq | (01 << 2) | $01), $0a
	.db (Rep | (09 << 2) | $01), $0d

	openingLine.15:
	.db (Rep | (19 << 2) | $01), $98
	.db $00

	openingLine.16:
	.db (Rep | (07 << 2) | $01), $98
	.db (Seq | (00 << 2) | $01), $9C
	.db (Seq | (00 << 2) | $01), $a1
	.db (Rep | (01 << 2) | $01), $9e
	.db (Seq | (00 << 2) | $01), $a1
	.db (Seq | (00 << 2) | $01), $9b
	.db (Seq | (00 << 2) | $01), $ad
	.db (Seq | (00 << 2) | $01), $a4
	.db (Seq | (00 << 2) | $01), $ac
	.db (Rep | (02 << 2) | $01), $98
	.db $00

	openingLine.17:
	.db (Rep | (05 << 2) | $01), $98
	.db (Seq | (00 << 2) | $01), $a8
	.db (Seq | (00 << 2) | $01), $AA
	.db (Seq | (00 << 2) | $01), $9d
	.db (Rep | (01 << 2) | $01), $ab
	.db (Seq | (00 << 2) | $01), $98
	.db (Seq | (01 << 2) | $01), $ab
	.db (Seq | (00 << 2) | $01), $99
	.db (Seq | (00 << 2) | $01), $AA
	.db (Seq | (00 << 2) | $01), $ac
	.db (Rep | (02 << 2) | $01), $98
	.db $00

	openingLine.18:
	.db (Rep | (19 << 2) | $01), $10
	.db $00

	openingLine.19:
	.db (Rep | (19 << 2) | $01), $11
	.db $00

	openingLine.20:
	.db (Rep | (19 << 2) | $01), $12
	.db $00

	openingLine.21:
	.db (Rep | (07 << 2) | $01), $13
	.db (Seq | (03 << 2) | $01), $14
	.db (Rep | (07 << 2) | $01), $13
	.db $00

	openingLine.22:
	.db (Seq | (03 << 2) | $01), $18
	.db (Seq | (05 << 2) | $01), $18
	.db (Seq | (01 << 2) | $01), $1c
	.db (Seq | (03 << 2) | $01), $18
	.db (Seq | (03 << 2) | $01), $18
	.db $00

	openingLine.23:
	.db (Seq | (03 << 2) | $01), $1e
	.db (Seq | (05 << 2) | $01), $1e
	.db (Seq | (01 << 2) | $01), $22
	.db (Seq | (03 << 2) | $01), $1e
	.db (Seq | (03 << 2) | $01), $1e
	.db $00

	openingLine.24:
	.db (Seq | (03 << 2) | $01), $24
	.db (Seq | (01 << 2) | $01), $24
	.db (Seq | (03 << 2) | $01), $28
	.db (Seq | (01 << 2) | $01), $2a
	.db (Seq | (01 << 2) | $01), $28
	.db (Seq | (03 << 2) | $01), $24
	.db (Seq | (01 << 2) | $01), $24
	.db $00

	openingLine.25:
	.db (Seq | (03 << 2) | $01), $2c
	.db (Seq | (01 << 2) | $01), $2c
	.db (Rep | (07 << 2) | $01), $98
	.db (Seq | (03 << 2) | $01), $2c
	.db (Seq | (01 << 2) | $01), $2c
	.db $00

	openingLine.26:
	.db (Seq | (05 << 2) | $01), $30
	.db (Rep | (01 << 2) | $01), $98
	.db (Seq | (01 << 2) | $01), $2a
	.db (Seq | (01 << 2) | $01), $28
	.db (Seq | (01 << 2) | $01), $26
	.db (Seq | (05 << 2) | $01), $30
	.db $00

	openingLine.27:
	.db (Seq | (05 << 2) | $01), $36
	.db (Rep | (05 << 2) | $01), $98
	.db (Seq | (01 << 2) | $01), $2e
	.db (Seq | (05 << 2) | $01), $36
	.db $00

	openingLine.28:
	.db (Seq | (01 << 2) | $01), $32
	.db (Seq | (01 << 2) | $01), $24
	.db (Seq | (01 << 2) | $01), $28
	.db (Seq | (05 << 2) | $01), $30
	.db (Seq | (03 << 2) | $01), $30
	.db (Seq | (01 << 2) | $01), $24
	.db (Seq | (01 << 2) | $01), $24
	.db $00

	openingLine.29:
	.db (Seq | (01 << 2) | $01), $38
	.db (Seq | (01 << 2) | $01), $2c
	.db (Rep | (01 << 2) | $01), $98
	.db (Seq | (05 << 2) | $01), $36
	.db (Seq | (03 << 2) | $01), $36
	.db (Seq | (01 << 2) | $01), $2c
	.db (Seq | (01 << 2) | $01), $2c
	.db $00

	openingLine.30:
	.db (Seq | (01 << 2) | $01), $26
	.db (Rep | (01 << 2) | $01), $98
	.db (Seq | (01 << 2) | $01), $2a
	.db (Seq | (01 << 2) | $01), $28
	.db (Seq | (01 << 2) | $01), $28
	.db (Seq | (03 << 2) | $01), $26
	.db (Seq | (01 << 2) | $01), $26
	.db (Rep | (01 << 2) | $01), $98
	.db (Seq | (01 << 2) | $01), $3c
	.db $00

	openingLine.31:
	.db (Seq | (01 << 2) | $01), $2e
	.db (Rep | (07 << 2) | $01), $98
	.db (Seq | (01 << 2) | $01), $2e
	.db (Rep | (01 << 2) | $01), $98
	.db (Seq | (01 << 2) | $01), $2e
	.db (Rep | (01 << 2) | $01), $98
	.db (Seq | (01 << 2) | $01), $3e
	.db $00

	openingLine.32:
	.db (Seq | (05 << 2) | $01), $40
	.db (Rep | (01 << 2) | $01), $98
	.db (Seq | (03 << 2) | $01), $30
	.db (Rep | (01 << 2) | $01), $98
	.db (Seq | (01 << 2) | $01), $42
	.db (Rep | (01 << 2) | $01), $98
	.db (Seq | (01 << 2) | $01), $46
	.db $00

	openingLine.33:
	.db (Seq | (07 << 2) | $01), $48
	.db (Seq | (03 << 2) | $01), $36
	.db (Seq | (01 << 2) | $01), $4e
	.db (Seq | (01 << 2) | $01), $4a
	.db (Seq | (03 << 2) | $01), $4e
	.db $00

	openingLine.34:
	.db (Seq | (05 << 2) | $01), $52
	.db (Seq | (01 << 2) | $01), $40
	.db (Seq | (01 << 2) | $01), $28
	.db (Seq | (01 << 2) | $01), $28
	.db (Seq | (01 << 2) | $01), $40
	.db (Seq | (01 << 2) | $01), $54
	.db (Seq | (01 << 2) | $01), $40
	.db (Seq | (01 << 2) | $01), $46
	.db $00

	openingLine.35:
	.db (Seq | (05 << 2) | $01), $58
	.db (Seq | (01 << 2) | $01), $48
	.db (Rep | (03 << 2) | $01), $98
	.db (Seq | (01 << 2) | $01), $48
	.db (Seq | (01 << 2) | $01), $5a
	.db (Seq | (01 << 2) | $01), $48
	.db (Seq | (01 << 2) | $01), $50
	.db $00

	openingLine.36:
	.db (Seq | (03 << 2) | $01), $52
	.db (Seq | (01 << 2) | $01), $26
	.db (Seq | (01 << 2) | $01), $2a
	.db (Rep | (01 << 2) | $01), $98
	.db (Seq | (01 << 2) | $01), $44
	.db (Seq | (03 << 2) | $01), $52
	.db (Seq | (03 << 2) | $01), $24
	.db $00

	openingLine.37:
	.db (Seq | (03 << 2) | $01), $58
	.db (Seq | (01 << 2) | $01), $2e
	.db (Rep | (03 << 2) | $01), $98
	.db (Seq | (01 << 2) | $01), $4c
	.db (Seq | (03 << 2) | $01), $58
	.db (Seq | (03 << 2) | $01), $2c
	.db $00

	openingLine.38:
	.db (Seq | (03 << 2) | $01), $5e
	.db (Seq | (01 << 2) | $01), $2a
	.db (Rep | (01 << 2) | $01), $98
	.db (Seq | (01 << 2) | $01), $2a
	.db (Seq | (01 << 2) | $01), $28
	.db (Seq | (03 << 2) | $01), $24
	.db (Seq | (03 << 2) | $01), $62
	.db $00

	openingLine.39:
	.db (Seq | (03 << 2) | $01), $66
	.db (Rep | (07 << 2) | $01), $98
	.db (Seq | (03 << 2) | $01), $2c
	.db (Seq | (03 << 2) | $01), $6a
	.db $00

	openingLine.40:
	.db (Seq | (03 << 2) | $01), $6e
	.db (Seq | (03 << 2) | $01), $5e
	.db (Rep | (01 << 2) | $01), $98
	.db (Seq | (01 << 2) | $01), $2a
	.db (Seq | (03 << 2) | $01), $5e
	.db (Seq | (03 << 2) | $01), $72
	.db $00

	openingLine.41:
	.db (Seq | (03 << 2) | $01), $76
	.db (Seq | (03 << 2) | $01), $66
	.db (Rep | (03 << 2) | $01), $98
	.db (Seq | (03 << 2) | $01), $66
	.db (Seq | (03 << 2) | $01), $7a
	.db $00

	openingLine.42:
	.db (Seq | (03 << 2) | $01), $7e
	.db (Seq | (01 << 2) | $01), $6e
	.db (Seq | (01 << 2) | $01), $82
	.db (Seq | (01 << 2) | $01), $2a
	.db (Seq | (01 << 2) | $01), $28
	.db (Seq | (01 << 2) | $01), $70
	.db (Seq | (01 << 2) | $01), $82
	.db (Seq | (01 << 2) | $01), $72
	.db (Seq | (01 << 2) | $01), $7e
	.db $00

	openingLine.43:
	.db (Seq | (03 << 2) | $01), $84
	.db (Seq | (01 << 2) | $01), $76
	.db (Seq | (01 << 2) | $01), $88
	.db (Rep | (03 << 2) | $01), $98
	.db (Seq | (01 << 2) | $01), $78
	.db (Seq | (01 << 2) | $01), $88
	.db (Seq | (01 << 2) | $01), $7a
	.db (Seq | (01 << 2) | $01), $84
	.db $00

	openingLine.44:
	.db (Seq | (01 << 2) | $01), $8a
	.db (Seq | (01 << 2) | $01), $80
	.db (Seq | (01 << 2) | $01), $6e
	.db (Seq | (01 << 2) | $01), $82
	.db (Rep | (03 << 2) | $01), $98
	.db (Seq | (03 << 2) | $01), $80
	.db (Seq | (01 << 2) | $01), $72
	.db (Seq | (01 << 2) | $01), $8a
	.db $00

	openingLine.45:
	.db (Seq | (01 << 2) | $01), $8c
	.db (Seq | (01 << 2) | $01), $86
	.db (Seq | (01 << 2) | $01), $76
	.db (Seq | (01 << 2) | $01), $88
	.db (Seq | (01 << 2) | $01), $4e
	.db (Seq | (01 << 2) | $01), $4e
	.db (Seq | (03 << 2) | $01), $86
	.db (Seq | (01 << 2) | $01), $7a
	.db (Seq | (01 << 2) | $01), $8c
	.db $00

openingMapLines:
.dw openingLine.0
.dw openingLine.0
.dw openingLine.0
.dw openingLine.0
.dw openingLine.1
.dw openingLine.2
.dw openingLine.3
.dw openingLine.4
.dw openingLine.5
.dw openingLine.6
.dw openingLine.7
.dw openingLine.0
.dw openingLine.8
.dw openingLine.9
.dw openingLine.10
.dw openingLine.11
.dw openingLine.12
.dw openingLine.13
.dw openingLine.14
.dw openingLine.15
.dw openingLine.16
.dw openingLine.15
.dw openingLine.15
.dw openingLine.17
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.15
.dw openingLine.18
.dw openingLine.19
.dw openingLine.20
.dw openingLine.21
.dw openingLine.22
.dw openingLine.23
.dw openingLine.24
.dw openingLine.25
.dw openingLine.26
.dw openingLine.27
.dw openingLine.28
.dw openingLine.29
.dw openingLine.30
.dw openingLine.31
.dw openingLine.32
.dw openingLine.33
.dw openingLine.34
.dw openingLine.35
.dw openingLine.36
.dw openingLine.37
.dw openingLine.38
.dw openingLine.39
.dw openingLine.40
.dw openingLine.41
.dw openingLine.42
.dw openingLine.43
.dw openingLine.44
.dw openingLine.45
openingMapLinesEnd:
.dw openingLine.0
.dw openingLine.0
.dw openingLine.0
.dw openingLine.0
.dw openingLine.0
.dw openingLine.0
.dw openingLine.0
.dw openingLine.0
.dw openingLine.0
.ends
.endif