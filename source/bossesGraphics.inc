.ifndef __BOSSES_GRAPHICS_INC__
.define __BOSSES_GRAPHICS_INC__

.define BossText.size 9
.define BossTimers.size 3
.include "opnBossObjectsTable.inc"

.define bubblemanTilesCount 94*2
.define bubblemanTilesSize bubblemanTilesCount*32
.define bubblemanTilesBank 15
.slot 2
.section "bubbleman" superfree
bubblemanIntroData:
	.asc "BUBBLEMAN"
bubblemanBossTimers:
	.db 32, (bubbleman.anim + bubbleman.anim.numFrames), bubbleman.anim  
bubblemanTiles:	
	.incbin "imagens\bubbleman.m.psgcompr" skip 2
.ends

.define airmanTilesCount 71*2
.define airmanTilesSize airmanTilesCount*32
.define airmanTilesBank 15

.section "airman" superfree
airmanIntroData:
	.asc "  AIRMAN "
airmanBossTimers:
	.db 86, (airman.anim + airman.anim.numFrames), airman.anim  
airmanTiles:	
	.incbin "imagens\airman.m.psgcompr" skip 2
.ends

.define quickmanTilesCount 90*2
.define quickmanTilesSize quickmanTilesCount*32
.define quickmanTilesBank 14
.slot 2
.section "quickman" superfree
quickmanIntroData:
	.asc " QUICKMAN"
quickmanBossTimers:
	.db 52, (quickman.anim + quickman.anim.numFrames), quickman.anim
quickmanTiles:
	.incbin "imagens\quickman.m.psgcompr" skip 2 
.ends


.define heatmanTilesCount 93*2
.define heatmanTilesSize heatmanTilesCount*32
.section "heatman" superfree
heatmanIntroData:
	.asc " HEATMAN "
heatmanBossTimers:
	.db 128, (heatman.anim + heatman.anim.numFrames), heatman.anim
heatmanTiles:
	.incbin "imagens\heatman.m.psgcompr" skip 2 
.ends

.define woodmanTilesCount 93*2
.define woodmanTilesSize woodmanTilesCount*32
.define woodmanTilesBank 14

.slot 2
.section "woodman" superfree
woodmanIntroData:
	.asc " WOODMAN "
woodmanBossTimers:
	.db 32, (woodman.anim + woodman.anim.numFrames), woodman.anim
woodmanTiles:
	.incbin "imagens\woodman.m.psgcompr" skip 2 
.ends

.define metalmanTilesCount 90*2
.define metalmanTilesSize metalmanTilesCount*32
.define metalmanTilesBank 14

.slot 2
.section "metalman" superfree
metalmanIntroData:
	.asc " METALMAN"
metalmanBossTimers:
	.db 32, (metalman.anim + metalman.anim.numFrames), metalman.anim
metalmanTiles:
	.incbin "imagens\metalman.m.psgcompr" skip 2 
.ends

.define flashmanTilesCount 97*2
.define flashmanTilesSize flashmanTilesCount*32
.define flashmanTilesBank 14

.slot 2
.section "flashman" superfree
flashmanIntroData:
	.asc " FLASHMAN"
flashmanBossTimers:
	.db 63, (flashman.anim + flashman.anim.numFrames), flashman.anim
flashmanTiles:
	.incbin "imagens\flashman.m.psgcompr" skip 2 
.ends

.define crashmanTilesCount 83*2
.define crashmanTilesSize crashmanTilesCount*32
.define crashmanTilesBank 14

.slot 2
.section "crashman" superfree
crashmanIntroData:
	.asc " CRASHMAN"
crashmanBossTimers:
	.db 32, (crashman.anim + crashman.anim.numFrames), crashman.anim
crashmanTiles:
	.incbin "imagens\crashman.m.psgcompr" skip 2 
.ends

.endif