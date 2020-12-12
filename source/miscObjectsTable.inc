.ifndef __OBJECT_ATTRIBUTES_INC__
.define __OBJECT_ATTRIBUTES_INC__


.define miscObject.opening.windows 1
.define miscObject.opening.parapeito 2
.define miscObject.opening.arrow 3
.define miscObject.opening.megamanHead 4
.define miscObject.opening.megamanHeadExit 6
.define miscObject.opening.megamanBody 14
.define miscObject.opening.megamanBodyExit 15
.define miscObject.passwordEditor.general 18
.define miscObject.passwordEditor.cursor 19
.define miscObject.passwordEditor.ball 20
.define miscObject.stageSelection.cursor 21
.define miscObject.bosIntro.stars 22
.define miscObject.stageIntro.ready 25

.slot 2
.section "miscObjects" align $100 superfree
; Format:
;	Y's offset  X  TileNumber	
miscObjects:
	.dw miscObject.opening.windows.addr
	.dw miscObject.opening.parapeito.addr
	.dw miscObject.opening.arrow.addr
	.dw miscObject.opening.megamanHead.1.addr
	.dw miscObject.opening.megamanHead.2.addr
	.dw miscObject.opening.megamanHead.3.addr
	.dw miscObject.opening.megamanHead.4.addr
	.dw miscObject.opening.megamanHead.5.addr
	.dw miscObject.opening.megamanHead.6.addr
	.dw miscObject.opening.megamanHead.7.addr
	.dw miscObject.opening.megamanHead.8.addr
	.dw miscObject.opening.megamanHead.9.addr
	.dw miscObject.opening.megamanHead.10.addr
	.dw miscObject.opening.megamanBody.1.addr
	.dw miscObject.opening.megamanBody.2.addr
	.dw miscObject.opening.megamanBody.3.addr
	.dw miscObject.opening.megamanBody.4.addr
	
	.dw miscObject.passwordEditor.general.addr
	.dw miscObject.passwordEditor.cursor.addr
	.dw miscObject.passwordEditor.ball.addr
	
	.dw miscObject.stageSelection.cursor.addr
	
	.dw miscObject.bosIntro.farStar.addr
	.dw miscObject.bosIntro.averegeStar.addr
	.dw miscObject.bosIntro.nearStar.addr
	
	.dw miscObject.stageIntro.ready.addr
	
miscObject.opening.windows.addr:
	.db 12
	.db  0 $c2 (MegamanFrameTileCount + $00)
	.db  0 $c8 (MegamanFrameTileCount + $01)
	.db  0 $e2 (MegamanFrameTileCount + $00)
	.db  0 $e8 (MegamanFrameTileCount + $01)
	.db  8 $c2 (MegamanFrameTileCount + $03)
	.db  8 $c8 (MegamanFrameTileCount + $04)
	.db  8 $e2 (MegamanFrameTileCount + $03)
	.db  8 $e8 (MegamanFrameTileCount + $04)
	.db 16 $c2 (MegamanFrameTileCount + $06)
	.db 16 $c8 (MegamanFrameTileCount + $07)
	.db 16 $e2 (MegamanFrameTileCount + $06)
	.db 16 $e8 (MegamanFrameTileCount + $07)
	
miscObject.opening.parapeito.addr:
	.db  4
	.db  0 $98 (MegamanFrameTileCount + $02)  
	.db  8 $98 (MegamanFrameTileCount + $05) 
	.db 16 $98 (MegamanFrameTileCount + $05)  
	.db 24 $98 (MegamanFrameTileCount + $08)

miscObject.opening.arrow.addr
	.db  1
	.db  0 $00 (MegamanFrameTileCount + $0e)
miscObject.opening.megamanHead.1.addr:	
	.db  3
	.db  0 $cd (MegamanFrameTileCount + $0b) 
	.db  0 $d5 (MegamanFrameTileCount + $0c) 
	.db  8 $d2 (MegamanFrameTileCount + $0d)
miscObject.opening.megamanHead.2.addr:	
	.db  3
	.db  0 $cd (MegamanFrameTileCount + $09) 
	.db  0 $d5 (MegamanFrameTileCount + $0a) 
	.db  8 $d2 (MegamanFrameTileCount + $0d)
miscObject.opening.megamanHead.3.addr:	
	.db  4
	.db  6 $cf $02
	.db  0 $cd (MegamanFrameTileCount + $0f) 
	.db  0 $d5 (MegamanFrameTileCount + $0c) 
	.db  8 $d2 (MegamanFrameTileCount + $0d)
miscObject.opening.megamanHead.4.addr:	
	.db  4
	.db  6 $cf $02
	.db  0 $cd (MegamanFrameTileCount + $10) 
	.db  0 $d5 (MegamanFrameTileCount + $0c) 
	.db  8 $d2 (MegamanFrameTileCount + $0d)
miscObject.opening.megamanHead.5.addr:	
	.db  3
	.db  0 $cc (MegamanFrameTileCount + $11) 
	.db  0 $d4 (MegamanFrameTileCount + $12) 
	.db  8 $d2 (MegamanFrameTileCount + $0d)
miscObject.opening.megamanHead.6.addr:	
	.db  3
	.db  1 $d3 (MegamanFrameTileCount + $13) 
	.db  0 $cd $00 	 
	.db  8 $d2 (MegamanFrameTileCount + $0d)
miscObject.opening.megamanHead.7.addr:	
	.db  2
	.db  0 $cd $00 
	.db  0 $d5 $01
miscObject.opening.megamanHead.8.addr:	
	.db  3
	.db  3 $d2 (MegamanFrameTileCount + $14) 
	.db  0 $cd $00 
	.db  0 $d5 $01	
miscObject.opening.megamanHead.9.addr:	
	.db  3
	.db  1 $cd (MegamanFrameTileCount + $15) 
	.db  1 $d5 (MegamanFrameTileCount + $16) 
	.db  0 $cd $00 
miscObject.opening.megamanHead.10.addr:	
	.db  3
	.db  1 $cd (MegamanFrameTileCount + $17) 
	.db  0 $cd $00 
	.db  0 $d5 $01
miscObject.opening.megamanBody.1.addr:
	.db  6
	.db  8 $c8 $05  
	.db  8 $d0 $06
	.db  8 $d8 $07
	.db 16 $c8 $0b
	.db 16 $d0 $0c
	.db 16 $d8 $0d
miscObject.opening.megamanBody.2.addr:
	.db  3
	.db  0 $d0 $04
	.db  8 $d0 $04
	.db 16 $d0 $04
	
miscObject.opening.megamanBody.3.addr:
	.db  9
	.db  0 $c8 $08  
	.db  0 $d0 $09
	.db  0 $d8 $0a
	.db  8 $c8 $08  
	.db  8 $d0 $09
	.db  8 $d8 $0a
	.db 16 $c8 $0e
	.db 16 $d0 $0f
	.db 16 $d8 $10
miscObject.opening.megamanBody.4.addr:
	.db  4
	.db  8 $d0 $03
	.db 16 $c8 $0e
	.db 16 $d0 $0f
	.db 16 $d8 $10	

objects.startPassMenu.arrow.addr:
	.db  1
	.db  0 $58 (MegamanFrameTileCount + $0e)

miscObject.passwordEditor.general.addr:
	.db  12
	.db  68  48 $2a
	.db  84  48 $2b
	.db 100  48 $2c
	.db 116  48 $2d
	.db 132  48 $2e
	.db  47  68 $25
	.db  47  84 $26
	.db  47 100 $27
	.db  47 116 $28
	.db  47 132 $29
	.db 160 208 $24
	.db 180 208 $2f
	
miscObject.passwordEditor.cursor.addr:
	.db  4
	.db 64 65 $20
	.db 64 73 $21
	.db 72 65 $22
	.db 72 73 $23
miscObject.passwordEditor.ball.addr
	.db 1
	.db 68 69 $24

miscObject.stageSelection.cursor.addr:
	.db  4
	.db 24 41 0
	.db 24 79 0
	.db 62 41 0
	.db 62 79 0

miscObject.bosIntro.farStar.addr:
	.db  21
	.db  16  24 3
	.db  48  32 3
	.db  20  64 3
	.db  40 120 3
	.db  16 128 3
	.db  24 144 3
	.db  56 176 3
	.db  16 208 3
	.db  64 232 3
	.db  48 248 3
	.db 192  24 3
	.db 160  64 3
	.db 216  96 3
	.db 184 104 3
	.db 200 112 3
	.db 176 144 3
	.db 152 144 3
	.db 200 192 3
	.db 216 200 3
	.db 208 216 3
	.db 160 232 3
	
miscObject.bosIntro.averegeStar.addr:
	.db  13
	.db  24   0 4
	.db  32  16 4
	.db  48  72 4
	.db   8  88 4
	.db  24  88 4
	.db  72  88 4
	.db  32 176 4
	.db  56 216 4
	.db 192 208 4
	.db 176   8 4
	.db 184  48 4
	.db 168 128 4
	.db 152 192 4	
	
miscObject.bosIntro.nearStar.addr:
	.db   7
	.db  60  88 5
	.db  52 176 5
	.db  36 248 5
	.db 208  72 5
	.db 156  72 5
	.db 224 176 5
	.db 164 248 5
	
miscObject.stageIntro.ready.addr:
	.db 5
	.db $60 $6c $01
	.db $60 $74 $04
	.db $60 $7c $00
	.db $60 $84 $03
	.db $60 $8c $02
.ends	
.endif