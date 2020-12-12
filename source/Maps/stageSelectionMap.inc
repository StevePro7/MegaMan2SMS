.ifndef __BOSS_SELECTION_MAP_INC__
.define __BOSS_SELECTION_MAP_INC__

.slot 2
.section "stageSelectionMap" align $100 superfree
stageSelectionMap:
	.db <stageSelectionMap.column.0
	.db <stageSelectionMap.column.0
	.db <stageSelectionMap.column.0
	.db <stageSelectionMap.column.0
	.db <stageSelectionMap.column.0
	.db <stageSelectionMap.column.1
	.db <stageSelectionMap.column.2
	.db <stageSelectionMap.column.2
	.db <stageSelectionMap.column.3
	.db <stageSelectionMap.column.4
	.db <stageSelectionMap.column.5
	.db <stageSelectionMap.column.0
	.db <stageSelectionMap.column.0
	.db <stageSelectionMap.column.1
	.db <stageSelectionMap.column.2
	.db <stageSelectionMap.column.2
	.db <stageSelectionMap.column.3
	.db <stageSelectionMap.column.4
	.db <stageSelectionMap.column.5
	.db <stageSelectionMap.column.0
	.db <stageSelectionMap.column.0
	.db <stageSelectionMap.column.1
	.db <stageSelectionMap.column.2
	.db <stageSelectionMap.column.2
	.db <stageSelectionMap.column.3
	.db <stageSelectionMap.column.4
	.db <stageSelectionMap.column.5
	.db <stageSelectionMap.column.0
	.db <stageSelectionMap.column.0
	.db <stageSelectionMap.column.0
	.db <stageSelectionMap.column.0
stageSelectionMapLastColumn:	
	.db <stageSelectionMap.column.0
	
stageSelectionMap.columns:
stageSelectionMap.column.0:
	.db $98 $98 $0c $0e $98 $98 $98 $98 
stageSelectionMap.column.1:
	.db $07 $0a $0d $0f $0a $10 $98 $98
stageSelectionMap.column.2:
	.db $08 $02 $02 $02 $02 $11 $98 $98
stageSelectionMap.column.3:
	.db $08 $02 $02 $02 $02 $11 $98
	.asc "M"
stageSelectionMap.column.4:
	.db $08 $02 $02 $02 $02 $11 $98
	.asc "A"
stageSelectionMap.column.5:
	.db $09 $0b $0b $0b $0b $12 $98
	.asc "N"
	
.ends

.endif