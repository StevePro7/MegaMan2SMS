.section "object" align $100 free
	.db <frames.object.0C

	.db >frames.object.0C

 $00
 $00
.ends

.section "objectsFramesAdresses.0" align $100 free
object.0C.framesList:
	.dw frames.object.0C.00
	.dw frames.object.0C.00.m
.ends

.section "objectsFrames.0" align $100 free
frames.object.0C.00:
	.db -17, -11, $30
	.db   0,  15, $50
	.db   8, -16, $31
	.db   0,   8, $41
	.db   0,   8, $51
	.db   3, -10, $2F
	.db   4,  18, $40
	.db   1, -24, $32
	.db   0,   8, $42
	.db   0,   8, $52
	.db   8, -15, $30;mirror
	.db $ff
frames.object.0C.00.m:
	.db -17, -11, $30;mirror
	.db   8,  -1, $32;mirror
	.db   0,   8, $42;mirror
	.db   0,   8, $52;mirror
	.db   1,   8, $40;mirror
	.db   4, -18, $2F;mirror
	.db   3,  -6, $31;mirror
	.db   0,   8, $41;mirror
	.db   0,   8, $51;mirror
	.db   8, -15, $30;mirror
	.db   0,  15, $50;mirror
	.db $ff
.ends

numWritedBytes: 76
numReadedBytes: 53
