.ifndef __BLUE_GRID_MAP_INC__
.define __BLUE_GRID_MAP_INC__

.slot 2
.section "menuSections" align $100 superfree
columnOrientation.left:
blueGridMetaTiles:
windowLeft.left:
	.db $02 $05
	.db $05 $05
	.db $0f $01
windowMiddle.left:
	.db $03 $98
	.db $98 $98
	.db $10 $12	
windowRight.left:
	.db $04 $06
	.db $06 $06
	.db $11 $12
tableBegin.left:
	.db $09 $0b
	.db $09 $0b
	.db $0a $98
tableEnd.left:
	.db $0b $0b
	.db $0b $0b
	.db $0c $98
columnOrientation.right:	
blueGridMetaTiles.end:	
windowLeft.right:
	.db $03 $98
	.db $98 $98
	.db $10 $0d
windowMiddle.right:
	.db $03 $98
	.db $98 $98
	.db $10 $12		
windowRight.right:
	.db $01 $07
	.db $08 $08
	.db $08 $0e
tableBegin.right:
	.db $0a $98
	.db $0a $98
	.db $0a $98
tableEnd.right:
	.db $98 $98
	.db $98 $98
	.db $98 $98

startPasswordMenuMap:
	.db 1 1 1 1 1
	.db 2, <windowLeft.left, 4 | (3 << 4)
	.db 2, <windowMiddle.left, 4 | (3 << 4)
	.db 2, <windowMiddle.left, 4 | (3 << 4)
	.db 2, <windowMiddle.left, 4 | (3 << 4)
	.db 2, <windowMiddle.left, 4 | (3 << 4)
	.db 2, <windowMiddle.left, 4 | (3 << 4)
	.db 2, <windowRight.left, 4 | (3 << 4)
	.db 1 1 1 1
startPasswordMenuMapEnd:
	
passwordHitMap:
	.db 1 1 1 1 1
	.db 2, <windowLeft.left, 4 | (4 << 4)
	.db 2, <windowMiddle.left, 4 | (4 << 4)
	.db 2, <windowMiddle.left, 4 | (4 << 4)
	.db 2, <windowMiddle.left, 4 | (4 << 4)
	.db 2, <windowMiddle.left, 4 | (4 << 4)
	.db 2, <windowRight.left, 4 | (4 << 4)
	.db 1 1 1 1 1
passwordHitMapEnd:

passwordMenuMap:
	.db 1 1 
	.db 2, <windowLeft.left, 1 | (8 << 4)
	.db 2, <windowMiddle.left, 1 | (8 << 4)
	.db 3, <windowMiddle.left, 1 | (8 << 4)
	.db	   <tableBegin.left,   3 | (5 << 4)
	.db 3, <windowMiddle.left, 1 | (8 << 4)
	.db	   <tableBegin.left,   3 | (5 << 4)
	.db 3, <windowMiddle.left, 1 | (8 << 4)
	.db	   <tableBegin.left,   3 | (5 << 4)
	.db 3, <windowMiddle.left, 1 | (8 << 4)
	.db	   <tableBegin.left,   3 | (5 << 4)
	.db 3, <windowMiddle.left, 1 | (8 << 4)
	.db	   <tableBegin.left,   3 | (5 << 4)
	.db 3, <windowMiddle.left, 1 | (8 << 4)
	.db	   <tableEnd.left,     3 | (5 << 4)
	.db 2, <windowRight.left, 1 | (8 << 4)
	.db 1
	.db 2, <windowLeft.left, 8 | (3 << 4)
	.db 2, <windowMiddle.left, 8 | (3 << 4)
	.db 2, <windowRight.left, 8 | (3 << 4)
	.db 1
.ends
.endif