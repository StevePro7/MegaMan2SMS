.ifndef __CONSTANTS__
.define __CONSTANTS__


.define AudioControlPort $f2
.define VdpControlPort $bf
.define VdpStatusPort $bf
.define VdpDataPort $be
.define VdpLineCounter $7e

.define VdpMisc1 $80
.define VdpMisc2 $81
.define VdpNameTable $82
.define VdpColorTable $83
.define VdpPatternTable $84
.define VdpSpriteAttrTable $85
.define VdpSpritePattTable $86
.define VdpBackgroundColor $87
.define VdpHorizontalScroll $88
.define VdpVerticalScroll $89
.define VdpLineInterruptNumber $8A

.define M1VerticalScrollLock 1<<7
.define M1HorizontalScrollLock 1<<6
.define M1HideLeftColoum 1<<5
.define M1LineInterrupts 1<<4
.define M1ShiftSprites 1<<3
.define M1Mode4 1<<2
.define	M1ExtendedHeightEnable 1<<1
.define M1Synch 1

.define BitM1VerticalScrollLock 7
.define BitM1HorizontalScrollLock 6
.define BitM1HideLeftColoum 5
.define BitM1LineInterrupts 4
.define BitM1ShiftSprites 3
.define BitM1Mode4 2
.define	BitM1ExtendedHeightEnable 1
.define BitM1Synch 0

.define M2DisplayEnabled 1<<6
.define M2FrameInterrupts 1<<5
.define M2Extended224 1<<4
.define M2Extended240 1<<3
.define M2DoubleTiledSprites 1<<1
.define M2DoubleSizedSprites 1

.define BitM2DisplayEnabled 6
.define BitM2FrameInterrupts 5
.define BitM2Extended224 4
.define BitM2Extended240 3
.define BitM2DoubleTiledSprites 1
.define BitM2DoubleSizedSprites 0

.define CramWrite.hi $c0
.define CramWrite $c000
.define VramWrite.hi $40
.define VramWrite $4000
.define VramSpriteTable $3f00
.define VramSpriteTable.hi $3f
.define VramSpriteTableBottom.lo $80
.define VramRowCount 28
.define VramColumnCount 32

.define Th.hi $F5
.define Th.lo $D5

.define DEBUG 0
.define FORCE_192 0

;SACBRLDU
.define StartKey 1<<7
.define AKey 1<<6
.define CKey 1<<5
.define BKey 1<<4
.define RKey 1<<3
.define LKey 1<<2
.define DKey 1<<1
.define UKey 1

;SACBRLDU
.define BitStartKey 7
.define BitAKey 6
.define BitCKey 5
.define BitBKey 4
.define BitRKey 3
.define BitLKey 2
.define BitDKey 1
.define BitUKey 0

.define LoadColumnRight 0
.define LoadColumnLeft $ff



;SZ5H3VNC: flag register, just in case we need those flags on other register than f
.define SF 1 << 7
.define ZF 1 << 6
.define B5F 1 << 5
.define HCF 1 << 4
.define B3F 1 << 3
.define OPF 1 << 2
.define NF 1 << 1
.define CF 1 

;Bosses
.define BubbleMan 1
.define AirMan 1 << 1
.define QuickMan 1 << 2
.define HeatMan 1 << 3
.define WoodMan 1 << 4
.define MetalMan 1 << 5
.define FlashMan 1 << 6
.define CrashMan 1 << 7
 
;ItensToBosses
.define Item1Boss HeatMan
.define Item2Boss AirMan
.define Item3Boss FlashMan

;Name table entry flags
.define SpritePalette 1 << 3
.define SpritesBelow 1 << 4

.define MegamanFrameTileCount 17
.define MegamanMaxFrameSize MegamanFrameTileCount*32

.define MapperConfig $fffc
.define MapperSlot0 $fffd
.define MapperSlot1 $fffe
.define MapperSlot2 $ffff

.define SpaceTile $0198
.define JumpInstruction $c3


.define CheckpointFlag 1<<7
.define LoadNewPaletteFlag 1<<6
.define BeginningTransitionsFlag 1<<5
.define EndingTransitionsFlag 1<<4
.define LoadGameplayMapFlag 1<<3
.define LoagTilesFlag 1<<2
.define MegamanFreezedBit 1

.define TransitB %001
.define TransitT %010
.define TransitR %100
.define TransitBT %011
.define TransitBR %101
.define TransitTR %110
.define TransitBTR %111

;Orientations
.define OrientationVert %10000000
.define OrientationHor %01000000
.define OrientationFoward 0
.define OrientationBackward 1

.define PaletteNewAddressMark %01000000
.define PaletteEndingMark %11000000
.define PaletteAnimationMark %10000000
.define PaletteAnimationCancel %10000000
.define PaletteAnimationEndMark $ff

.define BottomTransitionPending 1
.define RightTransitionPending 2
.define TopTransitionPending 4

;mirrors:

.define m00 $00 
.define m01 $80 
.define m02 $40 
.define m03 $c0 
.define m04 $20 
.define m05 $a0 
.define m06 $60 
.define m07 $e0 
.define m08 $10 
.define m09 $90 
.define m0A $50 
.define m0B $d0 
.define m0C $30 
.define m0D $b0 
.define m0E $70 
.define m0F $f0

.define m10 $08 
.define m11 $88 
.define m12 $48 
.define m13 $c8 
.define m14 $28 
.define m15 $a8 
.define m16 $68 
.define m17 $e8 
.define m18 $18 
.define m19 $98 
.define m1A $58 
.define m1B $d8 
.define m1C $38 
.define m1D $b8 
.define m1E $78 
.define m1F $f8

.define m20 $04 
.define m21 $84 
.define m22 $44 
.define m23 $c4 
.define m24 $24 
.define m25 $a4 
.define m26 $64 
.define m27 $e4 
.define m28 $14 
.define m29 $94 
.define m2A $54 
.define m2B $d4 
.define m2C $34 
.define m2D $b4 
.define m2E $74 
.define m2F $f4

.define m30 $0c 
.define m31 $8c 
.define m32 $4c 
.define m33 $cc 
.define m34 $2c 
.define m35 $ac 
.define m36 $6c 
.define m37 $ec 
.define m38 $1c 
.define m39 $9C 
.define m3A $5c 
.define m3B $dc 
.define m3C $3c 
.define m3D $bc 
.define m3E $7c 
.define m3F $fc

.define m40 $02 
.define m41 $82 
.define m42 $42 
.define m43 $c2 
.define m44 $22 
.define m45 $a2 
.define m46 $62 
.define m47 $e2 
.define m48 $12 
.define m49 $92 
.define m4A $52 
.define m4B $d2 
.define m4C $32 
.define m4D $b2 
.define m4E $72 
.define m4F $f2

.define m50 $0a 
.define m51 $8a 
.define m52 $4a 
.define m53 $ca 
.define m54 $2a 
.define m55 $AA 
.define m56 $6a 
.define m57 $ea 
.define m58 $1a 
.define m59 $9a 
.define m5A $5a 
.define m5B $da 
.define m5C $3a 
.define m5D $ba 
.define m5E $7a 
.define m5F $fa

.define m60 $06 
.define m61 $86 
.define m62 $46 
.define m63 $c6 
.define m64 $26 
.define m65 $a6 
.define m66 $66 
.define m67 $e6 
.define m68 $16 
.define m69 $96 
.define m6A $56 
.define m6B $d6 
.define m6C $36 
.define m6D $b6 
.define m6E $76 
.define m6F $f6

.define m70 $0e 
.define m71 $8e 
.define m72 $4e 
.define m73 $ce 
.define m74 $2e 
.define m75 $ae 
.define m76 $6e 
.define m77 $ee 
.define m78 $1e 
.define m79 $9e 
.define m7A $5e 
.define m7B $de 
.define m7C $3e 
.define m7D $be 
.define m7E $7e 
.define m7F $fe

.define m80 $01 
.define m81 $81 
.define m82 $41 
.define m83 $c1 
.define m84 $21 
.define m85 $a1 
.define m86 $61 
.define m87 $e1 
.define m88 $11 
.define m89 $91 
.define m8A $51 
.define m8B $d1 
.define m8C $31 
.define m8D $b1 
.define m8E $71 
.define m8F $f1

.define m90 $09 
.define m91 $89 
.define m92 $49 
.define m93 $c9 
.define m94 $29 
.define m95 $A9 
.define m96 $69 
.define m97 $e9 
.define m98 $19 
.define m99 $99 
.define m9A $59 
.define m9B $d9 
.define m9C $39 
.define m9D $b9 
.define m9E $79 
.define m9F $f9

.define mA0 $05 
.define mA1 $85 
.define mA2 $45 
.define mA3 $c5 
.define mA4 $25 
.define mA5 $a5 
.define mA6 $65 
.define mA7 $e5 
.define mA8 $15 
.define mA9 $95 
.define mAA $55 
.define mAB $d5 
.define mAC $35 
.define mAD $b5 
.define mAE $75 
.define mAF $f5

.define mB0 $0d 
.define mB1 $8d 
.define mB2 $4d 
.define mB3 $cd 
.define mB4 $2d 
.define mB5 $ad 
.define mB6 $6d 
.define mB7 $ed 
.define mB8 $1d 
.define mB9 $9d 
.define mBA $5d 
.define mBB $dd 
.define mBC $3d 
.define mBD $bd 
.define mBE $7d 
.define mBF $fd

.define mC0 $03 
.define mC1 $83 
.define mC2 $43 
.define mC3 $c3 
.define mC4 $23 
.define mC5 $a3 
.define mC6 $63 
.define mC7 $e3 
.define mC8 $13 
.define mC9 $93 
.define mCA $53 
.define mCB $d3 
.define mCC $33 
.define mCD $b3 
.define mCE $73 
.define mCF $f3

.define mD0 $0b 
.define mD1 $8b 
.define mD2 $4b 
.define mD3 $cb 
.define mD4 $2b 
.define mD5 $ab 
.define mD6 $6b 
.define mD7 $eb 
.define mD8 $1b 
.define mD9 $9b 
.define mDA $5b 
.define mDB $db 
.define mDC $3b 
.define mDD $bb 
.define mDE $7b 
.define mDF $fb

.define mE0 $07 
.define mE1 $87 
.define mE2 $47 
.define mE3 $c7 
.define mE4 $27 
.define mE5 $a7 
.define mE6 $67 
.define mE7 $e7 
.define mE8 $17 
.define mE9 $97 
.define mEA $57 
.define mEB $d7 
.define mEC $37 
.define mED $b7 
.define mEE $77 
.define mEF $f7

.define mF0 $0f 
.define mF1 $8f 
.define mF2 $4f 
.define mF3 $cf 
.define mF4 $2f 
.define mF5 $af 
.define mF6 $6f 
.define mF7 $ef 
.define mF8 $1f 
.define mF9 $9f 
.define mFA $5f 
.define mFB $df 
.define mFC $3f 
.define mFD $bf 
.define mFE $7f 
.define mFF $ff

;colors

.define c000 $00
.define c100 $01
.define c200 $02
.define c300 $03
.define c010 $04
.define c110 $05
.define c210 $06
.define c310 $07
.define c020 $08
.define c120 $09
.define c220 $0a
.define c320 $0b
.define c030 $0c
.define c130 $0d
.define c230 $0e
.define c330 $0f
.define c001 $10
.define c101 $11
.define c201 $12
.define c301 $13
.define c011 $14
.define c111 $15
.define c211 $16
.define c311 $17
.define c021 $18
.define c121 $19
.define c221 $1a
.define c321 $1b
.define c031 $1c
.define c131 $1d
.define c231 $1e
.define c331 $1f
.define c002 $20
.define c102 $21
.define c202 $22
.define c302 $23
.define c012 $24
.define c112 $25
.define c212 $26
.define c312 $27
.define c022 $28
.define c122 $29
.define c222 $2a
.define c322 $2b
.define c032 $2c
.define c132 $2d
.define c232 $2e
.define c332 $2f
.define c003 $30
.define c103 $31
.define c203 $32
.define c303 $33
.define c013 $34
.define c113 $35
.define c213 $36
.define c313 $37
.define c023 $38
.define c123 $39
.define c223 $3a
.define c323 $3b
.define c033 $3c
.define c133 $3d
.define c233 $3e
.define c333 $3f


.endif