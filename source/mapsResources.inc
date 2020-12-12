.ifndef __MAPS_RESOURCES_INC__
.define __MAPS_RESOURCES_INC__

.slot 2
.include "maps/OpeningMap.inc"

.slot 2
.include "maps/stageSelectionMap.inc"

.slot 2
.include "maps/blueGridMap.inc"

.macro paletteAnimationSetUp args framesPerFrames, colorsPerFrame, numFrames
	.db PaletteAnimationMark | framesPerFrames
	.db (colorsPerFrame << 4) | numFrames
.endm

;\1: orientation meaning foward or backward
;\2: orientation vertical/orizontal
;\3: map first subroom
;\4: number of subrooms
.macro configureMapLimits
	.if \4 == 1
		.db ($3f & (\3 + (>gameplayMap)))
	.else
		.if \1 == OrientationFoward
			.db (\2 | ($3f & (\3 + (>gameplayMap))))
			.db (\3 + (>gameplayMap) + \4 - 1)
		.else
			.db (\2 | ($3f & ((\3 + (>gameplayMap) + \4 - 1))))
			.db (\3 + (>gameplayMap))
		.endif
	.endif
.endm

;\1: flags indicating witch transition(s) address(es) should be defined
;\2, \3 and \4:	Transitions addresses
.macro configureNextTransitions
	.if \1 == TransitB
		.db  $3f & (\2 >> 8)
		.db \2 & $00ff
	.endif
	.if \1 == TransitT
		.db $40 | ($3f & (\2 >> 8))
		.db \2 & $00ff
	.endif
	.if \1 == TransitR
		.db $80 | ($3f & (\2 >> 8))
		.db \2 & $00ff
	.endif
	
	.if \1 == TransitBT
		.db $c0 | ($3f & (\2 >> 8))
		.db \2 & $00ff
	
		.db $c0 | ($3f & (\3 >> 8))
		.db \3 & $00ff
	.endif
	.if \1 == TransitBR
		.db $c0 | ($3f & (\2 >> 8))
		.db \2 & $00ff
	
		.db $80 | ($3f & (\3 >> 8))
		.db \3 & $00ff
	.endif
	.if \1 == TransitTR
		.db $c0 | ($3f & (\2 >> 8))
		.db \2 & $00ff
	
		.db $40 | ($3f & (\3 >> 8))
		.db \3 & $00ff
	.endif
	
	.if \1 == TransitBTR
		.db $c0 | ($3f & (\2 >> 8))
		.db \2 & $00ff
	
		.db $3f & (\3 >> 8)
		.db \3 & $00ff
	
		.db $3f & (\4 >> 8)
		.db \4 & $00ff
	.endif
.endm

.include "maps/bubblemanStage.inc"
.include "maps/metalmanStage.inc"
.include "maps/quickmanStage.inc"
.include "maps/airmanStage.inc"
.include "maps/woodmanStage.inc"
.include "maps/heatmanStage.inc"
.include "maps/flashmanStage.inc"
.include "maps/crashmanStage.inc"

.endif

