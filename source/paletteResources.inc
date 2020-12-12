.ifndef __PALETTE_RESOURCES__
.define __PALETTE_RESOURCES__

.define openingPalette.size 29

.define stageSelection.palette.size 15
.define BackgroundDinamicPalEntries 4
.define SpriteDinamicPalEntries 4

.slot 2
.section "palettes" superfree
megamanPalette:
	.db PaletteNewAddressMark | $11
	.db $3F $00 $1F $34
	.db $3C	| PaletteEndingMark

megamanMetalManPallete:	
	.db PaletteNewAddressMark | $14
	.db c210
	.db c321 | PaletteEndingMark

	
openingPalettesFade: ; Lbl_aa4f
	.db $00 $00 $00 $00 $00 $00 $00 $00 $00 $00 $02 $15 $00 $00 $00 $22  $00 $15 $00 $1F $34 $3C $00 $00 $00 $00 $1F $14 $00
	.db $00 $00 $00 $00 $00 $22 $15 $20 $15 $15 $05 $2a $15 $21 $15 $23  $00 $2a $00 $1F $34 $3C $00 $00 $15 $15 $1F $28 $20
openingPalette:                                                                 
	.db $00 $00 $00 $00 $00 $23 $14 $34 $21 $15 $1B $3f $22 $35 $2A $37  $00 $3F $00 $1F $34 $3C $00 $00 $15 $2A $1F $3C $34

titleScreenPalette:
	.db $00 $3f $04 $13 $39 $02
;.ends


;.slot 2
;.bank 1 slot 2
;.section "blueScreenGrid.palettes" superfree
blueGrid.backgroundPalette:	
	.db $01 $00 $3f $39 $3C $2B $34 $39 
blueGrid.backgroundPaletteEnd:
blueGrid.spritePalette:	
	.db $39 $3f $00 $3f $03
blueGrid.spritePaletteEnd:	
;.ends


;.slot 2
;.section "stageSelection.palette" superfree
stageSelection.palette:
	.db PaletteAnimationCancel
	.db	$34 $3F $00 $3C $1B $02 $13 $17 $2B $08 $2F $0E $07 
	.db PaletteNewAddressMark | 16
	.db	$34	| PaletteEndingMark
stageSelection.blinkPalette:	
	.db	$2a $3F $3F $3F $3F $2a $3F $2a $3F $2a $3F $3F $2a
	.db PaletteNewAddressMark | 16
	.db	$2a	| PaletteEndingMark
.ends


.endif