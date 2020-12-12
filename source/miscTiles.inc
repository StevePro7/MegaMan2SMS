.ifndef __MISC_TILES_ASM__
.define __MISC_TILES_ASM__

.define megamanSteadTempTilesCount 17
.section "megamanSteadTempTiles" superfree
megamanSteadTempTiles:
	.incbin "imagens\megamanSteadTemp.psgcompr" skip 2
.ends

.include "imagens/alphabet.indexes.inc"
.define alphabetTilesCount 42
.define alphabetTilesSize alphabetTilesCount*32
.define alphabetTiles.A alphabetTiles.11
.define alphabetTiles.R alphabetTiles.28
.define alphabetTiles.Y alphabetTiles.35
.define alphabetTilesBank 15
.section "alphabetTiles" superfree
alphabetTiles:
	.incbin "imagens\alphabet.psgcompr" skip 2
.ends

.define stageSelectionTilesCount 19
.define stageSelectionTilesSize stageSelectionTilesCount*32
.define bossFacesTilesCount 144
.define bossFacesTilesSize stageSelectionTilesCount*32
.section "stageSelectionTiles" superfree
stageSelectionTiles:
	.incbin "imagens\stageSelection.psgcompr" skip 2
bossFacesTiles:
	.incbin "imagens\bossFaces.psgcompr" skip 2
.ends

.include "imagens/openingSprites.indexes.inc"
.define openingSpritesTilesCount 24
.define openingSpritesTilesSize openingSpritesTilesCount*32
.define arrowTile openingSpritesTiles.14
.define openingTilesCount 268
.define openingTilesSize openingTilesCount*32
.define openingTilesBank 15
.section "openingTiles" superfree
openingTiles:
	.incbin "imagens\opening.psgcompr" skip 2
openingSpritesTiles:
	.incbin "imagens\openingSprites.psgcompr" skip 2
.ends

.define blueGridsTilesCount 18
.define blueGridsTilesSize blueGridsTilesCount*32
.section "blueGridsTiles" superfree
blueGridsTiles:
	.incbin "imagens\menu.psgcompr" skip 2
.ends

.define passwordMenuTilesCount 5
.define passwordMenuTilesSize passwordMenuTilesCount*32
.section "passwordMenuTiles" superfree
passwordMenuTiles:
	.incbin "imagens\passwordMenu.psgcompr" skip 2
.ends

.endif
