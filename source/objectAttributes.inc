
.define MegamanMaterializeTilesCount 6*2
.section "megamanMaterializeTiles" superfree
megamanMaterializeTiles:
	.incbin "imagens\megamanMaterializeTiles.m.psgcompr" skip 2
.ends


.define ObjectActiveFlag 1<<7
.define ObjectMirrorFlag 1<<6
.define ObjectGravitySensibleFlag 1<<2
.define BitObjectGravitySensibleFlag 2
.define BitObjectMirrorFlag 6
.define WeaponsTiles 17 



;\1 value to be defined
.macro dwBigEndian
	.db >\1
	.db <\1
.endm

;\1 value to be defined
.macro dwBigEndianPlusOne
	.db $ff & (1 + (>\1))
	.db <\1
.endm

.bank 15 slot 2
.orga $8000
.section "objectAttrFrameTimers" force
objectAttrAddresses:
objectAttrFrameTimers:
;megaman
	.db $7f	;megamanStead
	.db MegamanStartRunningFrameTimer ;megamanStartRunning
	.db MegamanSlidingFrameTimer ;megamanSliding
	.db 2   ;megamanDroppingDown
	.db MegamanLandingFrameTimer
	.db 6   ;megamanRunning
	.db $7f	;megamanOnAir
	.db $08 ;megamanOnLadder
;weapons
	.db $7f ;megamanBuster
	.db 6	;metalmanBuster
.ends

.orga $8100
.section "objectAttrFrames" force
objectAttrFrames:
;megaman
	.db 0*2   ;megamanStead 
	.db 0*2   ;megamanStartRunning
	.db 0*2   ;megamanSliding
	.db 4*2	  ;megamanDroppingDown
	.db 0*2   ;megamanLanding
	.db 3*2   ;megamanRunning
	.db 0*2	  ;megamanOnAir
	.db 1*2	  ;megamanOnLadder
;weapons
	.db 0*2   ;megamanBuster
	.db 1*2	  ;metalmanBuster
.ends 
	
.orga $8200
.section "objectAttrAddresses.lo" force
objectAttrAddresses.lo:
;megaman
objectAttr.megamanStead:
	.db (<frames.megamanStead) >> 1
objectAttr.megamanStartRunning:
	.db (<frames.megamanStartRunning) >> 1
objectAttr.megamanSliding:
	.db (<frames.megamanSliding) >> 1
objectAttr.megamanDroppingDown:
	.db (<frames.megamanDroppingDown) >>1
objectAttr.megamanLanding:
	.db (<frames.megamanLanding) >> 1
objectAttr.megamanRunning: 
	.db (<frames.megamanRunning) >> 1
objectAttr.megamanOnAir:
	.db (<frames.megamanOnAir) >> 1
objectAttr.megamanOnLadder:
	.db (<frames.megamanOnLadder) >> 1
;weapons
objectAttr.megamanBuster:
	.db (<frames.megamanBuster) >> 1
objectAttr.metalmanBuster:
	.db (<frames.metalmanBuster) >> 1
.ends

.orga $8300	
.section "objectAttrAddresses.hi" force
;megaman
	.db >frames.megamanStead 
	.db >frames.megamanStartRunning
	.db >frames.megamanSliding
	.db >frames.megamanDroppingDown
	.db >frames.megamanLanding
	.db >frames.megamanRunning
	.db >frames.megamanOnAir
	.db >frames.megamanOnLadder
;weapons
	.db >frames.megamanBuster
	.db >frames.metalmanBuster
.ends

.orga $8400
.section "megamanGameplayFrameAdresses" force
frames.megamanStartRunning:
frames.megamanSliding:
	dwBigEndian frames.megamanStartRunning.0
	dwBigEndian frames.megamanStartRunning.0.m
frames.megamanStead:
	dwBigEndian frames.megamanStead.0
	dwBigEndian frames.megamanStead.0.m
frames.megamanRunning:
	dwBigEndian frames.megamanRunning.00
	dwBigEndian frames.megamanRunning.00.m
frames.megamanLanding:
	dwBigEndian frames.megamanRunning.01
	dwBigEndian frames.megamanRunning.01.m
	dwBigEndian frames.megamanRunning.02
	dwBigEndian frames.megamanRunning.02.m
	dwBigEndian frames.megamanRunning.03
	dwBigEndian frames.megamanRunning.03.m
frames.megamanOnAir:
	dwBigEndian frames.megamanOnAir.00
	dwBigEndian frames.megamanOnAir.00.m
frames.megamanOnLadder:
	dwBigEndian frames.megamanOnLadder.00
	dwBigEndian frames.megamanOnLadder.00
	dwBigEndian frames.megamanOnLadder.00.m
	dwBigEndian frames.megamanOnLadder.00.m
.ends

.orga $8500
.section "megamanShootingGameplayFrameAdresses" force
frames.megamanShootingStartRunning:
frames.megamanShootingSliding:
	dwBigEndian frames.megamanShootingStead.0
	dwBigEndian frames.megamanShootingStead.0.m
frames.megamanShootingStead:
	dwBigEndian frames.megamanShootingStead.0
	dwBigEndian frames.megamanShootingStead.0.m
frames.megamanShootingRunning:
	dwBigEndian frames.megamanShootingRunning.00
	dwBigEndian frames.megamanShootingRunning.00.m
frames.megamanShootingLanding:
	dwBigEndian frames.megamanShootingRunning.01
	dwBigEndian frames.megamanShootingRunning.01.m
	
	dwBigEndian frames.megamanShootingRunning.02
	dwBigEndian frames.megamanShootingRunning.02.m
	
	dwBigEndian frames.megamanShootingRunning.03
	dwBigEndian frames.megamanShootingRunning.03.m
frames.megamanShootingOnAir:
	dwBigEndian frames.megamanShootingOnAir.00
	dwBigEndian frames.megamanShootingOnAir.00.m
frames.megamanShootingOnLadder:
	dwBigEndian frames.megamanShootingOnLadder.00
	dwBigEndian frames.megamanShootingOnLadder.00.m
	dwBigEndian frames.megamanShootingOnLadder.01
	dwBigEndian frames.megamanShootingOnLadder.01.m
.ends

.orga $8600
.section "megamanThrowingGameplayFrameAdresses" force
frames.megamanThrowingStartRunning:
frames.megamanThrowingSliding:
	dwBigEndian frames.megamanThrowingStead.0
	dwBigEndian frames.megamanThrowingStead.0.m
frames.megamanThrowingStead:
	dwBigEndian frames.megamanThrowingStead.0
	dwBigEndian frames.megamanThrowingStead.0.m
frames.megamanThrowingRunning:
	dwBigEndian frames.megamanThrowingStead.0
	dwBigEndian frames.megamanThrowingStead.0.m
frames.megamanThrowingLanding:
	dwBigEndian frames.megamanThrowingStead.0
	dwBigEndian frames.megamanThrowingStead.0.m
	dwBigEndian frames.megamanThrowingStead.0
	dwBigEndian frames.megamanThrowingStead.0.m
	dwBigEndian frames.megamanThrowingStead.0
	dwBigEndian frames.megamanThrowingStead.0.m
frames.megamanThrowingOnAir:
	dwBigEndian frames.megamanThrowingOnAir.00
	dwBigEndian frames.megamanThrowingOnAir.00.m
frames.megamanThrowingOnLadder:
	dwBigEndian frames.megamanThrowingOnLadder.00
	dwBigEndian frames.megamanThrowingOnLadder.00.m
	dwBigEndian frames.megamanThrowingOnLadder.01
	dwBigEndian frames.megamanThrowingOnLadder.01.m
.ends



.section "objectFramesAddresses" align $4 free	
frames.megamanDroppingDown:
	dwBigEndian frames.megamanDroppingDown.0
	dwBigEndian 0;frames.megamanDroppingDown.0.m
	dwBigEndian frames.megamanDroppingDown.1
	dwBigEndian 0;frames.megamanDroppingDown.1.m
	dwBigEndian frames.megamanDroppingDown.2
	dwBigEndian 0;frames.megamanDroppingDown.2.m
	dwBigEndian frames.megamanDroppingDown.3
	dwBigEndian 0;frames.megamanDroppingDown.3.m
	dwBigEndian frames.megamanDroppingDown.4
	dwBigEndian 0;frames.megamanDroppingDown.4.m	
	
frames.megamanBuster:
	dwBigEndian frames.megamanBuster.00
	dwBigEndian frames.megamanBuster.00
frames.metalmanBuster:
	dwBigEndian frames.metalmanBuster.00
	dwBigEndian frames.metalmanBuster.01
	dwBigEndian frames.metalmanBuster.01
	dwBigEndian frames.metalmanBuster.00
.ends

;triplets following the orther x,y,pattern.
;the coordinates are cumulative, the first x coordinade is the only one that can be negative
;since the sprite is ordered by the x's. Also, the first coordinate must be subtracted of one
;to transform some tests from "carry or zero", to just carry.
.orga $8700
.section "objectFrames0" force
frames.megamanDroppingDown.0:
frames.megamanDroppingDown.1:
frames.megamanDroppingDown.2:         
	.db -5, -20, $06               
	.db  0, $08, $06               
	.db  0, $08, $06               
	.db  0, $08, $06               
	.db $ff                    
frames.megamanDroppingDown.3:         
	.db -13, -12, $07 
	.db   0,   8, $07 
	.db   0,   8, $0f 
	.db   8, -24, $0d 
	.db   0,   8, $09 
	.db   0,   8, $09 
	.db   0,   8, $0b 
	.db   8, -16, $08 
	.db   0,   8, $08 
	.db   0,   8, $10 
	.db $ff                    
frames.megamanDroppingDown.4:         
	.db -13,   4, $0f               
	.db   8,  -8, $0d               
	.db   0,   8, $0c               
	.db   8,   0, $10               
	.db $ff

frames.megamanStead.0:
	.db <megamanStead.0.loaderPointer
	.db -13,  -4, ;$18
	.db   0,   8, ;$1c
	.db   4, -16, ;$08
	.db   4,   8, ;$16
	.db   0,   8, ;$1e
	.db   2, -16, ;$06
	.db   5,  16, ;$1b
	.db   1,  -8, ;$14
	.db $ff
	
frames.megamanStead.0.m:
	.db <megamanStead.0.m.loaderPointer
	.db -13,  -4, ;$13
	.db   1,   8, ;$1c
	.db   5, -16, ;$05
	.db   2,  16, ;$1d
	.db   0,  -8, ;$15
	.db   4,  -8, ;$07
	.db   4,  16, ;$1b
	.db   0,  -8, ;$17
	.db $ff

frames.megamanShootingStead.0:	
	.db <megamanShootingStead.0.loaderPointer
	.db -13,   4, ;$10E
	.db   2,  -8, ;$10B
	.db   4,  -8, ;$10F
	.db   2,  16, ;$10D
	.db   2,  -8, ;$10A
	.db   4,  -8, ;$06
	.db   2,  16, ;$10C
	.db   2,  -8, ;$109
	.db   6,  -1, ;$108
	.db $ff	
	
frames.megamanThrowingStead.0:	
	.db <megamanThrowingStead.0.loaderPointer
	.db -13,   4, ;$10E
	.db   2,  -8, ;$10B
	.db   4,  -8, ;$10F
	.db   2,  16, ;$10D
	.db   2,  -8, ;$10A
	.db   4,  -8, ;$06
	.db   2,  16, ;$10C
	.db   2,  -8, ;$109
	.db   2,   8, ;$108
	.db $ff		

frames.megamanShootingStead.0.m:	
	.db <megamanShootingStead.0.m.loaderPointer
	.db -21,  -5, ;$100
	.db   6,   1, ;$101
	.db   2,   8, ;$104
	.db   2, -16, ;$05
	.db   4,   8, ;$102
	.db   2,   8, ;$105
	.db   2, -16, ;$107
	.db   4,   8, ;$103
	.db   2,   8, ;$106
	.db $ff	
	
frames.megamanThrowingStead.0.m:	
	.db <megamanThrowingStead.0.m.loaderPointer
	.db -17,   4, ;$11E
	.db   2,  -8, ;$120
	.db   2,   8, ;$104
	.db   2, -16, ;$05
	.db   4,   8, ;$102
	.db   2,   8, ;$105
	.db   2, -16, ;$107
	.db   4,   8, ;$103
	.db   2,   8, ;$106
	.db $ff	

	
frames.megamanStartRunning.0:
frames.megamanSliding.0:
	.db <megamanSliding.0.loaderPointer
	.db -13,  -4, ;$18
	.db   0,   8, ;$1c
	.db   4, -16, ;$08
	.db   4,   8, ;$16
	.db   0,   8, ;$48
	.db   2, -16, ;$06
	.db   6,  16, ;$46
	.db   0,  -8, ;$14
	.db $ff

frames.megamanStartRunning.0.m:
frames.megamanSliding.0.m:
	.db <megamanSliding.0.m.loaderPointer
	.db -13,  -4, ;$13
	.db   0,   8, ;$45
	.db   6, -16, ;$05
	.db   2,  16, ;$47
	.db   0,  -8, ;$15
	.db   4,  -8, ;$07
	.db   4,  16, ;$1b
	.db   0,  -8, ;$17
	.db $ff

frames.megamanRunning.03:
	.db <megamanRunning.03.loaderPointer
	.db -16,   4, ;$3c
	.db   2,  -8, ;$2c
	.db   5,  -8, ;$22
	.db   0,  16, ;$3a
	.db   3,  -8, ;$2a
	.db   5,  -8, ;$20
	.db   0,  16, ;$38
	.db   3,  -8, ;$28
	.db $ff


	
.ends

.orga $8800
.section "objectFrames1" force
frames.megamanShootingRunning.03:
	.db <megamanShootingRunning.03.loaderPointer
	.db -16,   4, ;$3c
	.db   2,  -8, ;$2c
	.db   5,  -8, ;$22
	.db   0,  16, ;$3a
	.db   3,  -8, ;$2a
	.db   5,  -8, ;$20
	.db   0,   8, ;$113
	.db   0,   8, ;$115
	.db   8,  -8, ;$108
	.db $ff	
	
frames.megamanRunning.03.m:
	.db <megamanRunning.03.m.loaderPointer
	.db -12,  -4, ;$27
	.db   3,   8, ;$37
	.db   0, -16, ;$1f
	.db   5,   8, ;$29
	.db   3,  -8, ;$21
	.db   0,  16, ;$39
	.db   5,  -8, ;$2b
	.db   2,   8, ;$3b
	.db $ff

frames.megamanShootingRunning.03.m:
	.db <megamanShootingRunning.03.m.loaderPointer
	.db -17,  -4, ;$100
	.db   8,   0, ;$112
	.db   0,   8, ;$114
	.db   0, -16, ;$37
	.db   5,   8, ;$29
	.db   3,  -8, ;$21
	.db   0,  16, ;$39
	.db   5,  -8, ;$2b
	.db   2,   8, ;$3b
	.db $ff	

frames.megamanRunning.01:
	.db <megamanRunning.01.loaderPointer
	.db -17,  -4, ;$32
	.db   0,   8, ;$3c
	.db   8, -16, ;$24
	.db   0,  16, ;$40
	.db   0,  -8, ;$30
	.db   8,   0, ;$2e
	.db   0,   8, ;$3e
	.db   0, -16, ;$20
	.db $ff

frames.megamanShootingRunning.01:
	.db <megamanShootingRunning.01.loaderPointer
	.db -17,   4, ;$3c
	.db   8, -16, ;$24
	.db   0,  16, ;$40
	.db   0,  -8, ;$11B
	.db   8,   0, ;$11D
	.db   0,   8, ;$3e
	.db   0, -16, ;$20
	.db   8,   8, ;$108
	.db $ff	
	
	
frames.megamanRunning.01.m:
	.db <megamanRunning.01.m.loaderPointer
	.db  -9, -12, ;$1f
	.db   0,  16, ;$3d
	.db   0,  -8, ;$2d
	.db   8,   0, ;$2f
	.db   0,  -8, ;$23
	.db   0,  16, ;$3f
	.db   8,   0, ;$3b
	.db   0,  -8, ;$31
	.db $ff
	
frames.megamanShootingRunning.01.m:
	.db <megamanShootingRunning.01.m.loaderPointer
	.db -17,  -4, ;$100	
	.db   8,  -8, ;$1f
	.db   0,  16, ;$3d
	.db   0,  -8, ;$11A
	.db   8,   0, ;$11C
	.db   0,  -8, ;$23
	.db   0,  16, ;$3f
	.db   8,   0, ;$3b
	.db $ff	
	
frames.megamanRunning.00:
frames.megamanRunning.02:
	.db <megamanRunning.00.loaderPointer
	.db -11, -12, ;$26
	.db   0,   8, ;$36
	.db   0,   8, ;$44
	.db   8, -16, ;$06
	.db   0,  16, ;$42
	.db   0,  -8, ;$34
	.db $ff

frames.megamanShootingRunning.00:
frames.megamanShootingRunning.02:
	.db <megamanShootingRunning.00.loaderPointer
	.db -11, -12, ;$26
	.db   0,   8, ;$36
	.db   0,   8, ;$44
	.db   8, -16, ;$06
	.db   0,  16, ;$42
	.db   0,  -8, ;$117
	.db   2,   0, ;$116
	.db   8,  -2, ;$108
	.db $ff	
.ends	

.orga $8900
.section "objectFrames2" force	
frames.megamanRunning.00.m:
frames.megamanRunning.02.m:
	.db <megamanRunning.00.m.loaderPointer
	.db  -7,  -4, ;$33
	.db   0,  -8, ;$05
	.db   0,  16, ;$41
	.db   8, -16, ;$25
	.db   0,  16, ;$43
	.db   0,  -8, ;$35
	.db $ff
	
frames.megamanShootingRunning.00.m:
frames.megamanShootingRunning.02.m:
	.db <megamanShootingRunning.00.m.loaderPointer
	.db -17,  -6, ;$100
	.db   2,   2, ;$116
	.db   8,   0, ;$118
	.db   0,  -8, ;$05
	.db   0,  16, ;$41
	.db   8, -16, ;$25
	.db   0,  16, ;$43
	.db   0,  -8, ;$35
	.db $ff

frames.megamanOnAir.00:
	.db <megamanOnAir.00.loaderPointer
	.db -17, -11, ;$49
	.db   8,  -1, ;$4e
	.db   0,   8, ;$54
	.db   1,  16, ;$50
	.db   2,  -8, ;$58
	.db   5, -16, ;$4c
	.db   0,   8, ;$52
	.db   3,   8, ;$56
	.db   5, -15, ;$4a
	.db $ff
	
frames.megamanShootingOnAir.00:
	.db <megamanShootingOnAir.00.loaderPointer
	.db -17, -11, ;$49
	.db   8,  -1, ;$4e
	.db   0,   8, ;$54
	.db   1,  16, ;$50
	.db   2,  -8, ;$58
	.db   3, -16, ;$06
	.db   2,   8, ;$111
	.db   3,   8, ;$56
	.db   5, -10, ;$108
	.db $ff	

frames.megamanThrowingOnAir.00:
	.db <megamanThrowingOnAir.00.loaderPointer
	.db -17, -11, ;$49
	.db   8,  -1, ;$4e
	.db   0,   8, ;$54
	.db   1,  16, ;$50
	.db   2,  -8, ;$58
	.db   3, -16, ;$06
	.db   2,   8, ;$111
	.db   3,   8, ;$56
	.db   5, -10, ;$123
	.db $ff		
	
frames.megamanShootingOnAir.00.m:
	.db <megamanShootingOnAir.00.m.loaderPointer
	.db -17,  -6, ;$100
	.db   5,  10, ;$55
	.db   3,  -8, ;$111
	.db   2,  -8, ;$05
	.db   3,  16, ;$57
	.db   2,   8, ;$4f
	.db   1, -24, ;$4d
	.db   0,   8, ;$53
	.db   8,  -7, ;$4a
	.db $ff
	
frames.megamanThrowingOnAir.00.m:
	.db <megamanThrowingOnAir.00.m.loaderPointer
	.db -17,  -6, ;$122
	.db   5,  10, ;$55
	.db   3,  -8, ;$111
	.db   2,  -8, ;$05
	.db   3,  16, ;$57
	.db   2,   8, ;$4f
	.db   1, -24, ;$4d
	.db   0,   8, ;$53
	.db   8,  -7, ;$4a
	.db $ff	
	
frames.megamanOnAir.00.m:
	.db <megamanOnAir.00.m.loaderPointer
	.db -17, -11, ;$49
	.db   5,  15, ;$55
	.db   3, -16, ;$4b
	.db   0,   8, ;$51
	.db   5,   8, ;$57
	.db   2,   8, ;$4f
	.db   1, -24, ;$4d
	.db   0,   8, ;$53
	.db   8,  -7, ;$4a
	.db $ff

.ends	

.orga $8A00
.section "objectFrames3" force		
	
frames.megamanOnLadder.00:
	.db <megamanOnLadder.00.loaderPointer
	.db  -9, -12, ;$5C
	.db   0,   8, ;$60
	.db   0,   8, ;$64
	.db   0,   8, ;$66
	.db   8, -24, ;$5A
	.db   0,   8, ;$5E
	.db   0,   8, ;$62
	.db $ff
	
frames.megamanOnLadder.00.m:
	.db <megamanOnLadder.00.m.loaderPointer
	.db  -9, -12, ;$59
	.db   0,   8, ;$5D
	.db   0,   8, ;$61
	.db   8, -16, ;$5B
	.db   0,   8, ;$5F
	.db   0,   8, ;$63
	.db   0,   8, ;$65
	.db $ff		
	
frames.megamanShootingOnLadder.00:
	.db <megamanShootingOnLadder.00.loaderPointer
	.db  -9, -12, ;$12F
	.db   0,   8, ;$131
	.db   0,   8, ;$64
	.db   0,   8, ;$66
	.db   8, -24, ;$12D
	.db   0,   8, ;$125
	.db   0,   8, ;$62
	.db   8,  -9, ;$108
	.db $ff	

frames.megamanShootingOnLadder.01:
	.db <megamanShootingOnLadder.01.loaderPointer
	.db  -9, -12, ;$129
	.db   0,   8, ;$12B
	.db   0,   8, ;$61
	.db   8, -16, ;$125
	.db   0,   8, ;$127
	.db   0,   8, ;$63
	.db   0,   8, ;$65
	.db   8, -17, ;$108
	.db $ff		
	
frames.megamanShootingOnLadder.01.m:
	.db <megamanShootingOnLadder.01.m.loaderPointer
	.db -17,  -5, ;$100
	.db   8,  -7, ;$124
	.db   0,   8, ;$12C
	.db   0,   8, ;$61
	.db   8, -16, ;$12E
	.db   0,   8, ;$130
	.db   0,   8, ;$63
	.db   0,   8, ;$65
	.db $ff		
	
frames.megamanShootingOnLadder.00.m:
	.db <megamanShootingOnLadder.00.m.loaderPointer
	.db -17,  -5, ;$100
	.db   8,  -7, ;$124
	.db   0,   8, ;$126
	.db   0,   8, ;$64
	.db   0,   8, ;$66
	.db   8, -24, ;$128
	.db   0,   8, ;$12A
	.db   0,   8, ;$62
	.db $ff	
	
	
;thwowing:	

frames.megamanThrowingOnLadder.00:
	.db <megamanThrowingOnLadder.00.loaderPointer
	.db  -9, -12, ;$12F
	.db   0,   8, ;$131
	.db   0,   8, ;$64
	.db   0,   8, ;$66
	.db   8, -24, ;$12D
	.db   0,   8, ;$125
	.db   0,   8, ;$62
	.db   8,  -9, ;$133
	.db $ff	

frames.megamanThrowingOnLadder.01:
	.db <megamanThrowingOnLadder.01.loaderPointer
	.db  -9, -12, ;$129
	.db   0,   8, ;$12B
	.db   0,   8, ;$61
	.db   8, -16, ;$125
	.db   0,   8, ;$127
	.db   0,   8, ;$63
	.db   0,   8, ;$65
	.db   8, -17, ;$133
	.db $ff		
	
frames.megamanThrowingOnLadder.01.m:
	.db <megamanThrowingOnLadder.01.m.loaderPointer
	.db -17,  -5, ;$132
	.db   8,  -7, ;$124
	.db   0,   8, ;$12C
	.db   0,   8, ;$61
	.db   8, -16, ;$12E
	.db   0,   8, ;$130
	.db   0,   8, ;$63
	.db   0,   8, ;$65
	.db $ff		
	
frames.megamanThrowingOnLadder.00.m:
	.db <megamanThrowingOnLadder.00.m.loaderPointer
	.db -17,  -5, ;$132
	.db   8,  -7, ;$124
	.db   0,   8, ;$126
	.db   0,   8, ;$64
	.db   0,   8, ;$66
	.db   8, -24, ;$128
	.db   0,   8, ;$12A
	.db   0,   8, ;$62
	.db $ff		
	
	
	
frames.megamanBuster.00
	.db -4, -4, WeaponsTiles
	.db $ff
frames.metalmanBuster.00
	.db -8, -8, WeaponsTiles
	.db  0,  8, WeaponsTiles + 4
	.db  8, -8, WeaponsTiles + 1
	.db  0,  8, WeaponsTiles + 5
	.db $ff
frames.metalmanBuster.01
	.db -8, -8, WeaponsTiles + 2
	.db  0,  8, WeaponsTiles + 6
	.db  8, -8, WeaponsTiles + 3
	.db  0,  8, WeaponsTiles + 7
	.db $ff
.ends	

.orga $8B00
.section "dummyEnd" force	
	.db $ff
.ends