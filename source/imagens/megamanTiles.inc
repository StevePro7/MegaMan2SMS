
.section "megamanTilesAligned" align $100 free 
megamanSteadShoting.1.tiles:
; Tile index $10C
.db  m00 m02 m01  m01 m02 m01 
.db  m03 m04 m03  m01 m08 m07
.db  m00 m08 m07  m00 m1C m03
.db  m00 m20 m1F  m00 m3F m00
;index $109
.db  m05 m0B m00  m07 m3D m00
.db  m32 m0F m30  m3D m03 m3C
.db  m3E m01 m3E  m01 m3E m01
.db  m00 m01 m00  m00 m00 m00
megamanTile.108:
;index $108
.db  m00 m00 m00  m00 m1E m00
.db  m00 m71 m0E  m5C mA1 m5E 
.db  m00 mA1 m5E  m00 m71 m0E 
.db  m00 m1E m00  m00 m00 m00
megamanTile.123:
.db  m00 m38 m00  m00 m54 m28
.db  m00 m4F m30  m00 m21 m1E
.db  m00 m21 m1E  m00 m21 m1E
.db  m00 m4F m30  m00 m30 m00
megamanTile.133:
.db  m00 m60 m00  m00 m90 m60
.db  m00 m4F m30  m01 m40 m3F
.db  m01 m40 m3F  m01 m40 m3F
.db  m00 m3F m00  m00 m00 m00
.ends

.section "megamanTiles" free
megamanTiles:
megamanStead.0.tiles:
megamanSliding.0.1.tiles:
;index $18       
.db  m00 m80 m00  m00 mC0 m00
.db  mC0 m30 mC0  mE0 m08 mF0
.db  mC0 m08 mF0  m40 m84 m78
.db  m00 mE4 m18  m00 mC4 m38
megamanStead.0.2.m.tiles:
;index $1C       
.db  m00 mC4 m38  m00 mB8 m00
.db  m80 m40 m80  m00 m20 mC0
.db  m00 m30 mC0  m00 m0C mF0
.db  m00 m02 mFC  m00 mFE m00
;index $08       
.db  m00 m80 m00  m00 mE0 m00
.db  m00 m10 mE0  m00 m08 mF0
.db  m00 m08 mF0  m08 m04 mF8
.db  mC8 m44 m38  mE8 m24 m18
;index $16       
.db  m4E mF2 m01  mFE m46 m01
.db  m84 mFD m02  m7D mFE m01
.db  m83 m7C m83  m7F m80 m7F
.db  m7F m80 m7F  m7F m80 m7F
;index $1E       
.db  m00 m80 m7F  m00 m80 m7F
.db  mE1 m00 mFF  mF7 m08 mF7
.db  m22 m14 mE3  m00 m22 mC1
.db  m00 m22 mC1  m00 mE3 m00
;index $06
;index $1b
;index $14       


megamanSliding.0.tiles:
megamanStartRunning.0.tiles:
;index $18       
	;index $1C       
	;index $08       
	;index $16 
;index $48       
.db  m00 m80 m7F  m00 m80 m7F
.db  mE1 m00 mFF  m77 m08 mF7
.db  m02 m1C mE3  m00 m0A mF1
.db  m00 m0A mF1  m00 mFB m00
;index $06 
megamanSliding.0.3.tiles:
;index $46       
.db  m00 m11 m0E  m00 m0E m00
.db  m00 m01 m00  m00 m01 m00
.db  m00 m01 m00  m00 m06 m01
.db  m00 m08 m07  m00 m0F m00
megamanStead.0.3.tiles:
;index $14       
.db  m01 m02 m00  m01 m03 m00
.db  m00 m07 m00  m03 m08 m07
.db  m01 m08 m07  m01 m10 m0F
.db  m00 m13 m0C  m00 m11 m0E


megamanRunning.00.tiles:
megamanRunning.02.tiles:
;index $26    
.db  m00 m00 m00  m00 m80 m00
.db  m00 m40 m80  m00 m20 mC0
.db  m00 m20 mC0  m20 m10 mE0
.db  m20 m10 mE0  mA0 m98 m60
;index $36       
.db  m98 mA4 m58  m9C mA2 m5C
.db  m3E m41 mBE  m6E m91 m6E
.db  mC0 m22 mDC  m00 mC2 m3C
.db  m00 m24 mD8  m00 m08 mF0
;index $44       
.db  m00 m90 m60  m80 m60 m80
.db  mC0 m30 mC0  m00 m08 mF0
.db  m00 m04 mF8  m00 mC4 m38
.db  m00 m08 mF0  m00 mF0 m00
megamanSliding.0.2.tiles:
megamanStead.0.1.tiles:
megamanTile.06:
;index $06
.db  m00 m0E m00  m0C m13 m0C
.db  m18 m24 m1B  m00 m78 m07
.db  m30 m88 m77  m00 mB0 m4F
.db  m4F m81 m30  m53 mBC m00
;index $42       
.db  m04 m0A m05  m05 m0A m05
.db  m01 m06 m01  m00 m02 m01
.db  m00 m01 m00  m00 m01 m00
.db  m00 m02 m01  m00 m03 m00
;index $34       
.db  m53 mBC m00  m7F mD1 m00
.db  m21 m7F m00  m1F m3F m00
.db  m00 m3F m00  m0F m50 m2F
.db  m06 m49 m36  m00 m3D m02


megamanRunning.01.tiles:
;index $32       
.db  m00 m00 m00  m00 m00 m00
.db  m00 mC0 m00  m00 m20 mC0
.db  m00 m10 mE0  m00 m10 mE0
.db  m00 m10 mE0  m00 mE0 m00
megamanTile.3C:
megamanRunning.03.1.tiles:
;index $3C       
.db  m00 m90 m60  m00 m08 mF0
.db  m00 m04 mF8  m00 m24 mD8
.db  m00 m78 m80  m00 m80 m00
.db  m00 m00 m00  m00 m00 m00
;index $24       
.db  m00 m00 m00  m00 m00 m00
.db  m00 m80 m00  m00 mE0 m00
.db  m00 m10 mE0  m00 m08 mF0
.db  m00 m08 mF0  m08 m04 mF8
;index $40       
.db  m90 m23 mDC  m02 mC1 m3E
.db  m87 m00 mFF  mC7 m38 mC7
.db  m02 m44 m83  m00 m43 m80
.db  m00 m20 mC0  m00 mE0 m00
;index $30       
.db  mC8 m44 m38  mE8 m27 m18
.db  mE7 m28 m17  mEE m70 m0F
.db  m76 mC8 m37  mF8 m87 m78
.db  mF8 m05 mF8  mC8 m12 mEC
;index $2E       
.db  m13 m20 m0C  m14 m2F m00
.db  m14 m2F m00  m1F m34 m00
.db  m08 m1F m00  m07 m3F m00
.db  m00 m47 m38  m00 m40 m3F
megamanTile.3E:
;index $3E       
.db  m00 m40 m3F  m00 m3F m00
.db  m03 m04 m03  m01 m08 m07
.db  m00 m08 m07  m00 m1C m03
.db  m00 m20 m1F  m00 m3F m00
;index $20     

megamanRunning.03.tiles
;index $3c
;index $2C       
.db  m60 m98 m60  m60 m94 m68
.db  mC0 m22 mDC  mC0 m21 mDE
.db  m80 m51 m8E  m80 m51 m8E
.db  m00 m4E m80  m00 m58 m80
;index $22       
.db  m00 m00 m00  m00 m00 m00
.db  m00 m80 m00  m00 mE0 m00
.db  m00 m10 mE0  m00 m08 mF0
.db  m00 m08 mF0  m08 m07 mF8
;index $3A       
.db  m00 m03 mFC  mE0 m06 mF9
.db  mE2 m0C mF3  mCE m30 mCF
.db  m06 m28 mC7  m00 m27 mC0
.db  m00 m10 mE0  m00 mF0 m00
;index $2A       
.db  m79 m08 m87  m9D mE4 m03
.db  m9C mE5 m02  mFC m8D m02
.db  m09 mFA m05  mFB mFC m03
.db  m07 mF8 m07  m7C m80 m7F
megamanRunning.01.1.tiles:
megamanTile.20:
;index $20       
.db  m00 m00 m00  m00 m00 m00
.db  m00 m03 m00  m03 m04 m03
.db  m06 m09 m06  m00 m1E m01
.db  m0C m22 m1D  m00 m2C m13
;index $38       
.db  m11 m8A m71  m00 m71 m00
.db  m01 m02 m01  m01 m04 m03
.db  m00 m04 m03  m00 m0E m01
.db  m00 m10 m0F  m00 m1F m00
;index $28       
.db  m02 m04 m01  m02 m05 m00
.db  m02 m75 m00  m03 m8E m70
.db  m01 m8B m70  m02 m8D m72
.db  m07 m40 m3F  m03 m20 m1F

megamanOnLadder.00.tiles:
;index $5C       
.db  m00 m00 m00  m00 m00 m00
.db  m00 m00 m00  m00 mE0 m00
.db  m00 m30 mC0  m00 m10 mE0
.db  m00 m08 mF0  m10 m08 mF0
;index $60       
.db  m10 m0E mF0  m10 m09 mF6
.db  m00 m19 mE6  m18 m21 mDE
.db  m3C mC1 m3E  mFE m01 mFE
.db  mEE m11 mEE  mE6 m19 mE6
megamanTile.64:     
.db  m00 m0E mF0  m00 m08 mF0
.db  m10 m08 mF0  m70 m88 m70
.db  m70 m84 m78  m60 m84 m78
.db  m00 m44 m38  m00 m84 m78
;index $66       
.db  m00 m84 m78  m00 m84 m78
.db  m00 m44 m38  m00 m24 m18
.db  m00 m18 m00  m00 m00 m00
.db  m00 m00 m00  m00 m00 m00
;index $5A       
.db  m00 m38 m00  m00 m44 m38
.db  m00 m47 m38  m03 m8C m73
.db  m03 m90 m6F  m03 m80 m7F
.db  m43 mA0 m5F  m43 mA0 m5F
;index $5E       
.db  m43 mA0 m5F  m40 mA0 m5F
.db  m20 m50 m2F  m30 m48 m37
.db  m18 m27 m18  m0F m10 m0F
.db  m0F m30 m0F  m33 m40 m3F
megamanTile.62:      
.db  m70 m88 m77  m78 m84 m7B
.db  m00 m82 m7D  m00 m41 m3E
.db  m00 m21 m1E  m00 m22 m1C
.db  m00 m24 m18  m00 m18 m00


megamanOnAir.00.tiles:
;index $49      
;index $4E       
.db  m00 m80 m00  m00 mE0 m00
.db  m00 m10 mE0  m00 m09 mF0
.db  m00 m09 mF0  m08 m06 mF9
.db  mC8 m44 m3B  mE8 m24 m1B
;index $54       
.db  mE4 m28 m17  mE6 m69 m16
.db  mCC mD2 m2C  m58 mE4 m18
.db  mB8 mC4 m38  mF0 m08 mF0
.db  mF0 m08 mF0  mF0 m08 mF0
;index $50       
.db  m00 m88 m70  m00 m88 m70
.db  m00 m88 m70  m00 m88 m70
.db  m00 m88 m70  m00 m70 m00
.db  m00 m00 m00  m00 m00 m00
;index $58       
.db  m00 m01 mFE  m00 m01 mFE
.db  m86 m01 mFE  m1E mE1 m1E
.db  m0E m11 m0E  m06 m11 m0E
.db  m00 m11 m0E  m00 m21 m1E
;index $4C
.db  m00 m03 m00  m03 m04 m03
.db  m06 m09 m06  m00 m9E m01
.db  m0C mA2 m1D  m00 m6C m93
.db  m13 m20 mCC  m54 m2F mC0
megamanTile.52:
;index $52       
.db  mD4 m2F mC0  m5F mB4 m40
.db  m28 m5F m20  m10 m2F m10
.db  m18 m27 m18  m0F m10 m0F
.db  m0F m10 m0F  m0F m70 m0F
megamanTile.56:
;index $56       
.db  m0E m10 m0F  m07 m20 m1F
.db  m03 m20 m1F  m00 m21 m1E
.db  m00 m42 m3C  m00 m82 m7C
.db  m00 m86 m78  m00 m78 m00
megamanOnAir.00.1.m.tiles:
;index $4A       
.db  m00 m06 m00  m00 m09 m06
.db  m00 m10 m0F  m00 m11 m0E
.db  m00 m09 m06  m00 m04 m03
.db  m00 m02 m01  m00 m01 m00

megamanSteadShoting.0.tiles:
; Tile index $10E
.db  m00 m00 m00  m00 m00 m00
.db  m00 m80 m00  m00 m40 m80
.db  m00 m30 mC0  m00 m0C mF0
.db  m00 m02 mFC  m00 mFE m00
; Tile index $10B
.db  mF0 m08 mF0  mF0 m04 mF8 
.db  m40 m84 m78  m00 m44 mB8
.db  m00 m48 mB0  m00 m10 mE0
.db  m00 m20 mC0  m00 mC0 m00
; Tile index $10F
.db  m00 m00 m00  m00 m80 m00 
.db  m00 m40 m80  m00 m20 mC0 
.db  m00 m20 mC0  m20 m10 mE0 
.db  m20 m1C mE0  mAC m93 m6C 
; Tile index $10D
.db  m00 m02 mFC  m02 m01 mFE
.db  m87 m00 mFF  mCF m30 mCF
.db  m06 m48 m87  m00 m44 m83
.db  m00 m22 mC1  m00 mE3 m00
; Tile index $10A
.db  m39 mCA m05  mF9 m1A m05
.db  m13 mF4 m0B  mF6 mF9 m06
.db  m0C mF2 m0D  mFC m02 mFD
.db  mFE m01 mFE  m7C m80 m7F
;index $06


;Tile index $111
megamanTile.111:
.db  m14 mEF m00  mDF m34 mC0
.db  mE8 m1F mE0  mF0 m0F mF0
.db  m18 mE7 m18  m0F m10 m0F
.db  m0F m10 m0F  m0F m70 m0F

;Tile index $113
megamanTile.113:
.db  m13 m20 m0C  m14 m2F m00
.db  m14 mEF m00  mDF m34 mC0
.db  mE8 m1F mE0  mF7 m0F mF0
.db  m00 mF7 m08  m03 m04 m03

;Tile index $115
megamanTile.115:
.db  m01 m02 m01  m00 m01 m00
.db  m01 m02 m01  m01 m04 m03
.db  m00 m04 m03  m00 m0E m01
.db  m00 m10 m0F  m00 m1F m00

megamanTile.117:
.db  m53 mBC m00  m7F mD1 m00  
.db  mA1 m7F m80  mDF m3F mC0  
.db  m00 mFF m00  m0F m10 m0F  
.db  m06 m09 m06  m00 m0D m02 
megamanTile.116:
.db  $00 $03 $00  $03 $00 $03
.db  $03 $00 $03  $03 $00 $03 
.db  $00 $03 $00  $00 $00 $00
.db  $00 $00 $00  $00 $00 $00

megamanTile.11B:
.db  mC8 m44 m38  mE8 m24 m18 
.db  mE0 m28 m10  mE0 m70 m00 
.db  mF0 mC8 m30  m78 m04 mF8 
.db  mF8 m04 mF8  mC8 m12 mEC 
megamanTile.11D:
.db  m13 m20 m0C  m14 m2F m00 
.db  m14 mEF m00  mDF m34 mC0 
.db  mE8 m1F mE0  mC7 m3F mC0 
.db  m00 mC7 m38  m00 m40 m3F 

megamanTile.11F:
.db  m05 m0B m00  m07 m0D m00
.db  m02 m0F m00  m0D m13 m0C
.db  m1E m21 m1E  m3F m40 m3F
.db  m18 m87 m78  m00 m88 m70
megamanTile.121:
.db  m00 m42 m3C  m00 m44 m38
.db  m00 m84 m78  m00 m94 m68
.db  m00 mA8 m40  m00 m40 m00
.db  m00 m00 m00  m00 m00 m00

megamanTile.125:
.db  m00 m00 m00  m00 m03 m00
.db  m03 m0C m03  m08 m10 m0F
.db  m10 m20 m1F  m00 m20 m1F
.db  m0F m21 m10  m13 m3C m00
megamanTile.127:
.db  m13 m3C m00  m1F mF1 m00
.db  mE1 m1F mE0  mFE m06 mF9
.db  mFF m00 mFF  m1F mE0 m1F
.db  m0F m10 m0F  m0F m10 m0F

megamanTile.129:
.db  m00 m1C m00  m00 mE2 m1C
.db  mE0 m12 mEC  m10 m09 mF6
.db  m00 m05 mFA  m00 m05 mFA
.db  m22 m05 mFA  mF2 m85 m7A
megamanTile.12B:
.db  mF2 m85 m7A  mA2 m85 m7A
.db  m04 m0A mF4  m0C m12 mEC
.db  mF8 m04 mF8  mF0 m08 mF0
.db  mF0 m0C mF0  mCC m02 mFC

megamanTile.12D:
.db  m13 m3C m00  m1F mF1 m00
.db  mE1 m1F mE0  mFE m06 mF9
.db  mFF m00 mFF  m1F mE0 m1F
.db  m0F m30 m0F  m33 m40 m3F
megamanTile.12F:
.db  m00 m00 m00  m00 mE0 m00
.db  mE0 m10 mE0  m10 m08 mF0
.db  m00 m04 mF8  m00 m04 mF8
.db  m20 m04 mF8  mF0 m84 m78
megamanTile.131:
.db  mF0 m86 m78  mA0 m85 m7A
.db  m00 m09 mF6  m08 m11 mEE
.db  mFC m01 mFE  mFE m01 mFE
.db  mEE m11 mEE  mE6 m19 mE6


megamanStead.0.m.tiles:
;index $13       
;index $1C
;index $05
;index $1D       
.db  $00 $80 $7F  $00 $80 $7F
.db  $E1 $00 $FF  $F7 $08 $F7
.db  $22 $14 $E3  $00 $22 $C1
.db  $00 $22 $C1  $00 $E3 $00
megamanSliding.0.3.m.tiles:
;index $15       
.db  $4E $F2 $01  $FE $46 $01
.db  $84 $FD $02  $7D $FE $01
.db  $83 $7C $83  $7F $80 $7F
.db  $7F $80 $7F  $7F $80 $7F
megamanTile.07:
;index $07       
.db  $00 $80 $00  $00 $E0 $00
.db  $00 $10 $E0  $00 $08 $F0
.db  $00 $08 $F0  $08 $04 $F8
.db  $C8 $44 $38  $E8 $24 $18
megamanStead.0.2.tiles:
;index $1B       
.db  $00 $C4 $38  $00 $B8 $00
.db  $80 $40 $80  $00 $20 $C0
.db  $00 $30 $C0  $00 $0C $F0
.db  $00 $02 $FC  $00 $FE $00
;index $17       
.db  $00 $80 $00  $00 $C0 $00
.db  $C0 $30 $C0  $E0 $08 $F0
.db  $C0 $08 $F0  $40 $84 $78
.db  $00 $E4 $18  $00 $C4 $38


megamanStartRunning.0.m.tiles:
megamanSliding.0.m.tiles:
megamanStead.0.1.m.tiles:
;index $13       
.db  $01 $02 $00  $01 $03 $00
.db  $00 $07 $00  $03 $08 $07
.db  $01 $08 $07  $01 $10 $0F
.db  $00 $13 $0C  $00 $11 $0E
megamanSliding.0.4.m.tiles:
;index $45       
.db  $00 $11 $0E  $00 $0E $00
.db  $00 $01 $00  $00 $01 $00
.db  $00 $01 $00  $00 $06 $01
.db  $00 $08 $07  $00 $0F $00
;index $05
megamanSliding.0.2.m.tiles:
;index $47       
.db  $00 $80 $7F  $00 $80 $7F
.db  $E1 $00 $FF  $77 $08 $F7
.db  $02 $1C $E3  $00 $0A $F1
.db  $00 $0A $F1  $00 $FB $00
;index $15       
	;index $07       
	;index $1B       
	;index $17       

megamanRunning.00.m.tiles:
megamanRunning.02.m.tiles:
;index $33       
.db  $53 $BC $00  $7F $D1 $00
.db  $21 $7F $00  $1F $3F $00
.db  $00 $3F $00  $0F $50 $2F
.db  $06 $49 $36  $00 $3D $02
megamanSliding.0.1.m.tiles:
megamanStead.0.3.m.tiles:
megamanTile.05:
;index $05
.db  $00 $0E $00  $0C $13 $0C
.db  $18 $24 $1B  $00 $78 $07
.db  $30 $88 $77  $00 $B0 $4F
.db  $4F $81 $30  $53 $BC $00
;index $41       
.db  $04 $0A $05  $05 $0A $05
.db  $01 $06 $01  $00 $02 $01
.db  $00 $01 $00  $00 $01 $00
.db  $00 $02 $01  $00 $03 $00
;index $25    
.db  $00 $00 $00  $00 $80 $00
.db  $00 $40 $80  $00 $20 $C0
.db  $00 $20 $C0  $20 $10 $E0
.db  $20 $10 $E0  $A0 $98 $60
;index $43       
.db  $00 $90 $60  $80 $60 $80
.db  $C0 $30 $C0  $00 $08 $F0
.db  $00 $04 $F8  $00 $C4 $38
.db  $00 $08 $F0  $00 $F0 $00
;index $35       
.db  $98 $A4 $58  $9C $A2 $5C
.db  $3E $41 $BE  $6E $91 $6E
.db  $C0 $22 $DC  $00 $C2 $3C
.db  $00 $24 $D8  $00 $08 $F0


megamanRunning.01.m.tiles:
;index $1F
;index $3D       
.db  $00 $40 $3F  $00 $3F $00
.db  $03 $04 $03  $01 $08 $07
.db  $00 $08 $07  $00 $1C $03
.db  $00 $20 $1F  $00 $3F $00
;index $2D       
.db  $13 $20 $0C  $14 $2F $00
.db  $14 $2F $00  $1F $34 $00
.db  $08 $1F $00  $07 $3F $00
.db  $00 $47 $38  $00 $40 $3F
;index $2F       
.db  $C8 $44 $38  $E8 $27 $18
.db  $E7 $28 $17  $EE $70 $0F
.db  $76 $C8 $37  $F8 $87 $78
.db  $F8 $05 $F8  $C8 $12 $EC
megamanTile.23:
;index $23       
.db  $00 $00 $00  $00 $00 $00
.db  $00 $80 $00  $00 $E0 $00
.db  $00 $10 $E0  $00 $08 $F0
.db  $00 $08 $F0  $08 $04 $F8
;index $3F       
.db  $90 $23 $DC  $02 $C1 $3E
.db  $87 $00 $FF  $C7 $38 $C7
.db  $02 $44 $83  $00 $43 $80
.db  $00 $20 $C0  $00 $E0 $00
megamanRunning.03.1.m.tiles:
;index $3B       
.db  $00 $90 $60  $00 $08 $F0
.db  $00 $04 $F8  $00 $24 $D8
.db  $00 $78 $80  $00 $80 $00
.db  $00 $00 $00  $00 $00 $00
;index $31       
.db  $00 $00 $00  $00 $00 $00
.db  $00 $C0 $00  $00 $20 $C0
.db  $00 $10 $E0  $00 $10 $E0
.db  $00 $10 $E0  $00 $E0 $00

  
megamanRunning.03.m.tiles
;index $27       
.db  $02 $04 $01  $02 $05 $00
.db  $02 $75 $00  $03 $8E $70
.db  $01 $8B $70  $02 $8D $72
.db  $07 $40 $3F  $03 $20 $1F
;index $37       
.db  $11 $8A $71  $00 $71 $00
.db  $01 $02 $01  $01 $04 $03
.db  $00 $04 $03  $00 $0E $01
.db  $00 $10 $0F  $00 $1F $00
megamanRunning.01.1.m.tiles:
megamanTile.1F:
;index $1f       
.db  $00 $00 $00  $00 $00 $00
.db  $00 $03 $00  $03 $04 $03
.db  $06 $09 $06  $00 $1E $01
.db  $0C $22 $1D  $00 $2C $13
megamanTile.29:
;index $29       
.db  $79 $08 $87  $9D $E4 $03
.db  $9C $E5 $02  $FC $8D $02
.db  $09 $FA $05  $FB $FC $03
.db  $07 $F8 $07  $7C $80 $7F
;index $21       
.db  $00 $00 $00  $00 $00 $00
.db  $00 $80 $00  $00 $E0 $00
.db  $00 $10 $E0  $00 $08 $F0
.db  $00 $08 $F0  $08 $07 $F8
;index $39       
.db  $00 $03 $FC  $E0 $06 $F9
.db  $E2 $0C $F3  $CE $30 $CF
.db  $06 $28 $C7  $00 $27 $C0
.db  $00 $10 $E0  $00 $F0 $00
;index $2B       
.db  $60 $98 $60  $60 $94 $68
.db  $C0 $22 $DC  $C0 $21 $DE
.db  $80 $51 $8E  $80 $51 $8E
.db  $00 $4E $80  $00 $58 $80
;index $3B

megamanOnLadder.00.m.tiles:
;index $59
.db  $00 $38 $00  $00 $44 $38
.db  $00 $47 $38  $03 $8C $73
.db  $03 $90 $6F  $03 $80 $7F
.db  $43 $A0 $5F  $43 $A0 $5F
;index $5D
.db  $43 $A0 $5F  $40 $A0 $5F
.db  $20 $50 $2F  $30 $48 $37
.db  $18 $27 $18  $0F $10 $0F
.db  $0F $30 $0F  $33 $40 $3F
megamanTile.61:
.db  $70 $88 $77  $78 $84 $7B
.db  $00 $82 $7D  $00 $41 $3E
.db  $00 $21 $1E  $00 $22 $1C
.db  $00 $24 $18  $00 $18 $00
;index $5B       
.db  $00 $00 $00  $00 $00 $00
.db  $00 $00 $00  $00 $E0 $00
.db  $00 $30 $C0  $00 $10 $E0
.db  $00 $08 $F0  $10 $08 $F0
;index $5F       
.db  $10 $0E $F0  $10 $09 $F6
.db  $00 $19 $E6  $18 $21 $DE
.db  $3C $C1 $3E  $FE $01 $FE
.db  $EE $11 $EE  $E6 $19 $E6
megamanTile.63:
.db  $00 $0E $F0  $00 $08 $F0
.db  $10 $08 $F0  $70 $88 $70
.db  $70 $84 $78  $60 $84 $78
.db  $00 $44 $38  $00 $84 $78
;index $65       
.db  $00 $84 $78  $00 $84 $78
.db  $00 $44 $38  $00 $24 $18
.db  $00 $18 $00  $00 $00 $00
.db  $00 $00 $00  $00 $00 $00

megamanOnAir.00.m.tiles:
megamanOnAir.00.1.tiles:
;index ;49
.db  $00 $06 $00  $00 $09 $06
.db  $00 $10 $0F  $00 $11 $0E
.db  $00 $09 $06  $00 $04 $03
.db  $00 $02 $01  $00 $01 $00
megamanTile.55:
;index $55       
.db  $0E $10 $0F  $07 $20 $1F
.db  $03 $20 $1F  $00 $21 $1E
.db  $00 $42 $3C  $00 $82 $7C
.db  $00 $86 $78  $00 $78 $00
;index $4B
.db  $00 $03 $00  $03 $04 $03
.db  $06 $09 $06  $00 $9E $01
.db  $0C $A2 $1D  $00 $6C $93
.db  $13 $20 $CC  $54 $2F $C0
megamanTile.51:
;index $51       
.db  $D4 $2F $C0  $5F $B4 $40
.db  $28 $5F $20  $10 $2F $10
.db  $18 $27 $18  $0F $10 $0F
.db  $0F $10 $0F  $0F $70 $0F
megamanTile.57:
;index $57       
.db  $00 $01 $FE  $00 $01 $FE
.db  $86 $01 $FE  $1E $E1 $1E
.db  $0E $11 $0E  $06 $11 $0E
.db  $00 $11 $0E  $00 $21 $1E
;index $4f       
.db  $00 $88 $70  $00 $88 $70
.db  $00 $88 $70  $00 $88 $70
.db  $00 $88 $70  $00 $70 $00
.db  $00 $00 $00  $00 $00 $00
;index $4D       
.db  $00 $80 $00  $00 $E0 $00
.db  $00 $10 $E0  $00 $09 $F0
.db  $00 $09 $F0  $08 $06 $F9
.db  $C8 $44 $3B  $E8 $24 $1B
;index $53       
.db  $E4 $28 $17  $E6 $69 $16
.db  $CC $D2 $2C  $58 $E4 $18
.db  $B8 $C4 $38  $F0 $08 $F0
.db  $F0 $08 $F0  $F0 $08 $F0
;index $4A

megamanSteadShoting.0.m.tiles:
megamanTile.100:
;index $100
.db  $00 $00 $00  $00 $1E $00
.db  $00 $71 $0E  $5C $A1 $5E 
.db  $00 $A1 $5E  $00 $71 $0E 
.db  $00 $1E $00  $00 $00 $00
;index $101
.db  $05 $0B $00  $07 $3D $00
.db  $32 $0F $30  $3D $03 $3C
.db  $3E $01 $3E  $01 $3E $01
.db  $00 $01 $00  $00 $00 $00
megamanTile.104:
.db  $00 $02 $01  $01 $02 $01 
.db  $03 $04 $03  $01 $08 $07
.db  $00 $08 $07  $00 $1C $03
.db  $00 $20 $1F  $00 $3F $00
;index $05
megamanSteadShoting.1.m.tiles:
; Tile index $102
.db  $39 $CA $05  $F9 $1A $05
.db  $13 $F4 $0B  $F6 $F9 $06
.db  $0C $F2 $0D  $FC $02 $FD
.db  $FE $01 $FE  $7C $80 $7F
; Tile index $105
.db  $00 $02 $FC  $02 $01 $FE
.db  $87 $00 $FF  $CF $30 $CF
.db  $06 $48 $87  $00 $44 $83
.db  $00 $22 $C1  $00 $E3 $00
; Tile index $107
.db  $00 $00 $00  $00 $80 $00 
.db  $00 $40 $80  $00 $20 $C0 
.db  $00 $20 $C0  $20 $10 $E0 
.db  $20 $1C $E0  $AC $93 $6C 
; Tile index $103
.db  $F0 $08 $F0  $F0 $04 $F8 
.db  $40 $84 $78  $00 $44 $B8
.db  $00 $48 $B0  $00 $10 $E0
.db  $00 $20 $C0  $00 $C0 $00
; Tile index $106
.db  $00 $00 $00  $00 $00 $00
.db  $00 $80 $00  $00 $40 $80
.db  $00 $30 $C0  $00 $0C $F0
.db  $00 $02 $FC  $00 $FE $00

megamanTile.110:
.db  $14 $EF $00  $DF $34 $C0
.db  $E8 $1F $E0  $F0 $0F $F0
.db  $18 $E7 $18  $0F $10 $0F
.db  $0F $10 $0F  $0F $70 $0F
megamanTile.112:
.db  $13 $20 $0C  $14 $2F $00
.db  $14 $EF $00  $DF $34 $C0
.db  $E8 $1F $E0  $F7 $0F $F0
.db  $00 $F7 $08  $03 $04 $03
megamanTile.114:
.db  $01 $02 $01  $00 $01 $00
.db  $01 $02 $01  $01 $04 $03
.db  $00 $04 $03  $00 $0E $01
.db  $00 $10 $0F  $00 $1F $00
megamanTile.118:
.db  $53 $BC $00  $7F $D1 $00  
.db  $A1 $7F $80  $DF $3F $C0  
.db  $00 $FF $00  $0F $10 $0F  
.db  $06 $09 $06  $00 $0D $02 

megamanTile.11A:
.db  $13 $20 $0C  $14 $2F $00 
.db  $14 $EF $00  $DF $34 $C0 
.db  $E8 $1F $E0  $C7 $3F $C0 
.db  $00 $C7 $38  $00 $40 $3F 
megamanTile.11C:
.db  $C8 $44 $38  $E8 $24 $18 
.db  $E0 $28 $10  $E0 $70 $00 
.db  $F0 $C8 $30  $78 $04 $F8 
.db  $F8 $04 $F8  $C8 $12 $EC 

megamanTile.11E:
.db  $00 $42 $3C  $00 $44 $38
.db  $00 $84 $78  $00 $94 $68
.db  $00 $A8 $40  $00 $40 $00
.db  $00 $00 $00  $00 $00 $00
megamanTile.120:
.db  $05 $0B $00  $07 $0D $00
.db  $02 $0F $00  $0D $13 $0C
.db  $1E $21 $1E  $3F $40 $3F
.db  $18 $87 $78  $00 $88 $70
megamanTile.122:
.db  $00 $38 $00  $00 $54 $28
.db  $00 $4F $30  $00 $21 $1E
.db  $00 $21 $1E  $00 $21 $1E
.db  $00 $4F $30  $00 $30 $00

megamanTile.124:
.db  $00 $00 $00  $00 $03 $00
.db  $03 $0C $03  $08 $10 $0F
.db  $10 $20 $1F  $00 $20 $1F
.db  $0F $21 $10  $13 $3C $00
megamanTile.126:
.db  $13 $3C $00  $1F $F1 $00
.db  $E1 $1F $E0  $FE $06 $F9
.db  $FF $00 $FF  $1F $E0 $1F
.db  $0F $10 $0F  $0F $10 $0F

megamanTile.128:
.db  $00 $1C $00  $00 $E2 $1C
.db  $E0 $12 $EC  $10 $09 $F6
.db  $00 $05 $FA  $00 $05 $FA
.db  $22 $05 $FA  $F2 $85 $7A
megamanTile.12A:
.db  $F2 $85 $7A  $A2 $85 $7A
.db  $04 $0A $F4  $0C $12 $EC
.db  $F8 $04 $F8  $F0 $08 $F0
.db  $F0 $0C $F0  $CC $02 $FC

megamanTile.12C:
.db  $13 $3C $00  $1F $F1 $00
.db  $E1 $1F $E0  $FE $06 $F9
.db  $FF $00 $FF  $1F $E0 $1F
.db  $0F $30 $0F  $33 $40 $3F
megamanTile.12E:
.db  $00 $00 $00  $00 $E0 $00
.db  $E0 $10 $E0  $10 $08 $F0
.db  $00 $04 $F8  $00 $04 $F8
.db  $20 $04 $F8  $F0 $84 $78
megamanTile.130:
.db  $F0 $86 $78  $A0 $85 $7A
.db  $00 $09 $F6  $08 $11 $EE
.db  $FC $01 $FE  $FE $01 $FE
.db  $EE $11 $EE  $E6 $19 $E6

megamanTile.132:
.db  $00 $60 $00  $00 $90 $60
.db  $00 $4F $30  $01 $40 $3F
.db  $01 $40 $3F  $01 $40 $3F
.db  $00 $3F $00  $00 $00 $00



.ends
