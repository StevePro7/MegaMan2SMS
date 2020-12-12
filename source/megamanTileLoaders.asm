
;c: VdpDataPort



.macro setDefaultMegamanTilesAddress
	ld a, 5*32
	out (VdpControlPort), a
	ld a, VramWrite.hi
	out (VdpControlPort), a 
.endm

.org $500
.section "tileLoaderPointers.lo" force
megamanTileLoaderPointers.lo:
megamanStead.0.loaderPointer:
	.db <megamanStead.0.loader
megamanStead.0.m.loaderPointer:
	.db <megamanStead.0.m.loader
	
megamanSliding.0.loaderPointer:
megamanStartRunning.0.loaderPointer:
	.db <megamanSliding.0.loader
megamanSliding.0.m.loaderPointer:
megamanStartRunning.0.m.loaderPointer:
	.db <megamanSliding.0.m.loader
	
megamanRunning.00.loaderPointer:
megamanRunning.02.loaderPointer:
	.db <megamanRunning.00.loader
megamanRunning.00.m.loaderPointer:
megamanRunning.02.m.loaderPointer:
	.db <megamanRunning.00.m.loader
megamanRunning.01.loaderPointer:
	.db <megamanRunning.01.loader
megamanRunning.01.m.loaderPointer:
	.db <megamanRunning.01.m.loader
megamanRunning.03.loaderPointer:
	.db <megamanRunning.03.loader
megamanRunning.03.m.loaderPointer:
	.db <megamanRunning.03.m.loader
	
megamanOnLadder.00.loaderPointer:
	.db <megamanOnLadder.00.loader
megamanOnLadder.00.m.loaderPointer:
	.db <megamanOnLadder.00.m.loader
	
megamanOnAir.00.loaderPointer:
	.db <megamanOnAir.00.loader
megamanOnAir.00.m.loaderPointer:
	.db <megamanOnAir.00.m.loader
	
megamanShootingStead.0.m.loaderPointer:	
	.db <megamanShootingStead.0.m.loader
megamanShootingStead.0.loaderPointer:	
	.db <megamanShootingStead.0.loader
	
megamanShootingOnAir.00.loaderPointer:	
	.db <megamanShootingOnAir.00.loader
megamanShootingOnAir.00.m.loaderPointer:
	.db <megamanShootingOnAir.00.m.loader
	
megamanShootingRunning.03.loaderPointer:	
	.db <megamanShootingRunning.03.loader
megamanShootingRunning.03.m.loaderPointer:	
	.db <megamanShootingRunning.03.m.loader
megamanShootingRunning.00.m.loaderPointer:
megamanShootingRunning.02.m.loaderPointer:
	.db <megamanShootingRunning.00.m.loader
megamanShootingRunning.00.loaderPointer:
megamanShootingRunning.02.loaderPointer:	
	.db <megamanShootingRunning.00.loader
megamanShootingRunning.01.m.loaderPointer:
	.db <megamanShootingRunning.01.m.loader
megamanShootingRunning.01.loaderPointer:
	.db <megamanShootingRunning.01.loader
	
megamanThrowingStead.0.m.loaderPointer:
	.db <megamanThrowingStead.0.m.loader
megamanThrowingStead.0.loaderPointer:	
	.db <megamanThrowingStead.0.loader
	
megamanThrowingOnAir.00.m.loaderPointer:
	.db <megamanThrowingOnAir.00.m.loader
megamanThrowingOnAir.00.loaderPointer:
	.db <megamanThrowingOnAir.00.loader
	
megamanShootingOnLadder.00.m.loaderPointer:
	.db <megamanShootingOnLadder.00.m.loader
megamanShootingOnLadder.01.m.loaderPointer:
	.db <megamanShootingOnLadder.01.m.loader
megamanShootingOnLadder.01.loaderPointer:
	.db <megamanShootingOnLadder.01.loader
megamanShootingOnLadder.00.loaderPointer:
	.db <megamanShootingOnLadder.00.loader
	
megamanThrowingOnLadder.00.m.loaderPointer:
	.db <megamanThrowingOnLadder.00.m.loader
megamanThrowingOnLadder.01.m.loaderPointer:
	.db <megamanThrowingOnLadder.01.m.loader
megamanThrowingOnLadder.01.loaderPointer:
	.db <megamanThrowingOnLadder.01.loader
megamanThrowingOnLadder.00.loaderPointer:
	.db <megamanThrowingOnLadder.00.loader	
.ends

.org $600
.section "tileLoaderPointers.hi" force
megamanTileLoaderPointers.hi:
	.db >megamanStead.0.loader
	.db >megamanStead.0.m.loader
	.db >megamanSliding.0.loader
	.db >megamanSliding.0.m.loader
	.db >megamanRunning.00.loader
	.db >megamanRunning.00.m.loader
	.db >megamanRunning.01.loader
	.db >megamanRunning.01.m.loader
	.db >megamanRunning.03.loader
	.db >megamanRunning.03.m.loader
	.db >megamanOnLadder.00.loader
	.db >megamanOnLadder.00.m.loader
	.db >megamanOnAir.00.loader
	.db >megamanOnAir.00.m.loader
	.db >megamanShootingStead.0.m.loader	
	.db >megamanShootingStead.0.loader
	.db >megamanShootingOnAir.00.loader
	.db >megamanShootingOnAir.00.m.loader
	.db >megamanShootingRunning.03.loader
	.db >megamanShootingRunning.03.m.loader
	.db >megamanShootingRunning.02.m.loader
	.db >megamanShootingRunning.00.loader
	.db >megamanShootingRunning.01.m.loader
	.db >megamanShootingRunning.01.loader
	.db >megamanThrowingStead.0.m.loader
	.db >megamanThrowingStead.0.loader
	.db >megamanThrowingOnAir.00.m.loader
	.db >megamanThrowingOnAir.00.loader
	.db >megamanShootingOnLadder.00.m.loader
	.db >megamanShootingOnLadder.01.m.loader
	.db >megamanShootingOnLadder.01.loader
	.db >megamanShootingOnLadder.00.loader
	.db >megamanThrowingOnLadder.00.m.loader
	.db >megamanThrowingOnLadder.01.m.loader
	.db >megamanThrowingOnLadder.01.loader
	.db >megamanThrowingOnLadder.00.loader	
.ends

.bank 1 slot 1
.section "tile loaders" free
megamanStead.0.loader:
	setDefaultMegamanTilesAddress 
	ld hl, megamanStead.0.tiles
	ld de, +
	jp outputMegamanTiles.5
+:
	ld hl, megamanStead.0.1.tiles
	ld de, +
	jp outputMegamanTiles.1
+:
	ld hl, megamanStead.0.2.tiles
	ld de, +
	jp outputMegamanTiles.1
+:
	ld hl, megamanStead.0.3.tiles
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.1

megamanStead.0.m.loader:
	setDefaultMegamanTilesAddress	
	ld hl, megamanStead.0.1.m.tiles
	ld de, +
	jp outputMegamanTiles.1
+:
	ld hl, megamanStead.0.2.m.tiles
	ld de, +
	jp outputMegamanTiles.1
+:
	ld hl, megamanStead.0.3.m.tiles
	ld de, +
	jp outputMegamanTiles.1
+:
	ld hl, megamanStead.0.m.tiles
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.5

megamanShootingStead.0.loader:
	setDefaultMegamanTilesAddress	
	ld hl, megamanSteadShoting.0.tiles
	ld de, +
	jp outputMegamanTiles.5
+:
	ld hl, megamanTile.06
	ld de, +
	jp outputMegamanTiles.1
+:
	ld hl, megamanSteadShoting.1.tiles
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.3	
	
megamanThrowingStead.0.loader:
	setDefaultMegamanTilesAddress	
	ld hl, megamanSteadShoting.0.tiles
	ld de, +
	jp outputMegamanTiles.5
+:
	ld hl, megamanTile.06
	ld de, +
	jp outputMegamanTiles.1
+:
	ld hl, megamanSteadShoting.1.tiles
	ld de, +
	jp outputMegamanTiles.1		
+:	
	ld hl, megamanTile.11F
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.2		

megamanThrowingStead.0.m.loader:
	setDefaultMegamanTilesAddress	
	ld hl, megamanTile.11E
	ld de, +
	jp outputMegamanTiles.2
+:
	ld hl, megamanTile.104
	ld de, +
	jp outputMegamanTiles.1
+:
	ld hl, megamanTile.05
	ld de, +
	jp outputMegamanTiles.1
+:
	ld hl, megamanSteadShoting.1.m.tiles
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.5

	
	
megamanShootingStead.0.m.loader:
	setDefaultMegamanTilesAddress	
	ld hl, megamanSteadShoting.0.m.tiles
	ld de, +
	jp outputMegamanTiles.3
+:
	ld hl, megamanTile.05
	ld de, +
	jp outputMegamanTiles.1
+:
	ld hl, megamanSteadShoting.1.m.tiles
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.5

megamanSliding.0.loader:
megamanStartRunning.0.loader:
	setDefaultMegamanTilesAddress
	ld hl, megamanSliding.0.1.tiles
	ld de, +
	jp outputMegamanTiles.4
+:
	ld hl, megamanSliding.0.tiles
	ld de, +
	jp outputMegamanTiles.1
+:
	ld hl, megamanSliding.0.2.tiles
	ld de, +
	jp outputMegamanTiles.1
+:
	ld hl, megamanSliding.0.3.tiles
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.2

megamanSliding.0.m.loader:
megamanStartRunning.0.m.loader:
	setDefaultMegamanTilesAddress
	ld hl, megamanSliding.0.m.tiles
	ld de, +
	jp outputMegamanTiles.2
+:
	ld hl, megamanSliding.0.1.m.tiles
	ld de, +
	jp outputMegamanTiles.1
+:
	ld hl, megamanSliding.0.2.m.tiles
	ld de, +
	jp outputMegamanTiles.1
+
	ld hl, megamanSliding.0.3.m.tiles
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.4
	
megamanRunning.00.loader:
megamanRunning.02.loader:
	setDefaultMegamanTilesAddress
	ld hl, megamanRunning.00.tiles
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.6

megamanShootingRunning.00.loader:
megamanShootingRunning.02.loader:
	setDefaultMegamanTilesAddress
	ld hl, megamanRunning.00.tiles
	ld de, +
	jp outputMegamanTiles.5
+:	
	ld hl, megamanTile.117
	ld de, +
	jp outputMegamanTiles.2
+:
	ld hl, megamanTile.108
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.1

	
megamanRunning.00.m.loader:
megamanRunning.02.m.loader:
	setDefaultMegamanTilesAddress
	ld hl, megamanRunning.00.m.tiles
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.6

megamanShootingRunning.00.m.loader:
megamanShootingRunning.02.m.loader:
	setDefaultMegamanTilesAddress
	ld hl, megamanTile.100
	ld de, +
	jp outputMegamanTiles.1
+:
	ld hl, megamanTile.116
	ld de, +
	jp outputMegamanTiles.1
+:	
	ld hl, megamanTile.118
	ld de, +
	jp outputMegamanTiles.1
+:	
	ld hl, megamanTile.05
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.5
	
megamanRunning.01.loader:
	setDefaultMegamanTilesAddress
	ld hl, megamanRunning.01.tiles
	ld de, +
	jp outputMegamanTiles.7
+:
	ld hl, megamanRunning.01.1.tiles
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.1

	
megamanShootingRunning.01.loader:
	setDefaultMegamanTilesAddress
	ld hl, megamanTile.3C
	ld de, +
	jp outputMegamanTiles.3
+	
	ld hl, megamanTile.11B
	ld de, +
	jp outputMegamanTiles.2
+
	ld hl, megamanTile.3E
	ld de, +
	jp outputMegamanTiles.1
+:
	ld hl, megamanRunning.01.1.tiles
	ld de, +
	jp outputMegamanTiles.1	
+	
	ld hl, megamanTile.108
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.1
	
megamanRunning.01.m.loader:
	setDefaultMegamanTilesAddress
	ld hl, megamanRunning.01.1.m.tiles
	ld de, +
	jp outputMegamanTiles.1
+:
	ld hl, megamanRunning.01.m.tiles
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.7

megamanShootingRunning.01.m.loader:
	setDefaultMegamanTilesAddress
	ld hl, megamanTile.100
	ld de, +
	jp outputMegamanTiles.1
+:
	ld hl, megamanRunning.01.1.m.tiles
	ld de, +
	jp outputMegamanTiles.1
+:
	ld hl, megamanRunning.01.m.tiles
	ld de, +
	jp outputMegamanTiles.1
+:
	ld hl, megamanTile.11A
	ld de, +
	jp outputMegamanTiles.2
+:
	ld hl, megamanTile.23
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.3

	
megamanRunning.03.loader:
	setDefaultMegamanTilesAddress
	ld hl, megamanRunning.03.1.tiles
	ld de, +
	jp outputMegamanTiles.1
+:	
	ld hl, megamanRunning.03.tiles
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.7	

megamanShootingRunning.03.loader:
	setDefaultMegamanTilesAddress
	ld hl, megamanRunning.03.1.tiles
	ld de, +
	jp outputMegamanTiles.1
+:	
	ld hl, megamanRunning.03.tiles
	ld de, + 
	jp outputMegamanTiles.5
+:	
	ld hl, megamanTile.113
	ld de, +
	jp outputMegamanTiles.2
+:	
	ld hl, megamanTile.108
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.1
	
megamanRunning.03.m.loader:
	setDefaultMegamanTilesAddress
	ld hl, megamanRunning.03.m.tiles
	ld de, +
	jp outputMegamanTiles.7
+:	
	ld hl, megamanRunning.03.1.m.tiles
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.1		
	
megamanShootingRunning.03.m.loader:
	setDefaultMegamanTilesAddress
	ld hl, megamanTile.100
	ld de, +
	jp outputMegamanTiles.1
+:
	ld hl, megamanTile.112
	ld de, +
	jp outputMegamanTiles.2
+:
	ld hl, megamanTile.1F
	ld de, +
	jp outputMegamanTiles.5
+:	
	ld hl, megamanRunning.03.1.m.tiles
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.1			

megamanOnLadder.00.loader:
	setDefaultMegamanTilesAddress
	ld hl, megamanOnLadder.00.tiles
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.7

megamanThrowingOnLadder.00.loader:
	ld b, $ff & (<megamanTile.133 + ($ff & 24*7))
	jp +
megamanShootingOnLadder.00.loader:
	ld b, $ff & (<megamanTile.108 + ($ff & 24*7))
+:
	setDefaultMegamanTilesAddress
	ld hl, megamanTile.12F
	ld de, +
	jp outputMegamanTiles.2
+:	
	ld hl, megamanTile.64
	ld de, +
	jp outputMegamanTiles.2
+:
	ld hl, megamanTile.125
	ld de, +
	jp outputMegamanTiles.1
+:
	ld hl, megamanTile.12D
	ld de, +
	jp outputMegamanTiles.1
+:	
	ld hl, megamanTile.62
	ld de, +
	jp outputMegamanTiles.1	
+:
	ld h, >megamanTile.108
	ld l, b
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.1	
	
megamanThrowingOnLadder.01.loader:
	ld b, $ff & (<megamanTile.133 + ($ff & 24*7))
	jp +
megamanShootingOnLadder.01.loader:
	ld b, $ff & (<megamanTile.108 + ($ff & 24*7))
+:		
	setDefaultMegamanTilesAddress
	ld hl, megamanTile.129
	ld de, +
	jp outputMegamanTiles.2
+:	
	ld hl, megamanTile.61
	ld de, +
	jp outputMegamanTiles.1
+:	
	ld hl, megamanTile.125
	ld de, +
	jp outputMegamanTiles.2
+:	
	ld hl, megamanTile.63
	ld de, +
	jp outputMegamanTiles.2	
+:
	ld h, >megamanTile.108
	ld l, b
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.1

megamanThrowingOnLadder.01.m.loader:	
	setDefaultMegamanTilesAddress
	ld hl, megamanTile.132
	ld de, +
	jp outputMegamanTiles.1
megamanShootingOnLadder.01.m.loader:
	setDefaultMegamanTilesAddress
	ld hl, megamanTile.100
	ld de, +
	jp outputMegamanTiles.1
+:	
	ld hl, megamanTile.124
	ld de, +
	jp outputMegamanTiles.1
+:	
	ld hl, megamanTile.12C
	ld de, +
	jp outputMegamanTiles.1
+:	
	ld hl, megamanTile.61
	ld de, +
	jp outputMegamanTiles.1
+:	
	ld hl, megamanTile.12E
	ld de, +
	jp outputMegamanTiles.2
+:	
	ld hl, megamanTile.63
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.2
	
megamanThrowingOnLadder.00.m.loader:
	setDefaultMegamanTilesAddress
	ld hl, megamanTile.132
	ld de, +
	jp outputMegamanTiles.1	
megamanShootingOnLadder.00.m.loader:
	setDefaultMegamanTilesAddress
	ld hl, megamanTile.100
	ld de, +
	jp outputMegamanTiles.1
+:	
	ld hl, megamanTile.124
	ld de, +
	jp outputMegamanTiles.2
+:	
	ld hl, megamanTile.64
	ld de, +
	jp outputMegamanTiles.2
+:
	ld hl, megamanTile.128
	ld de, +
	jp outputMegamanTiles.2
+:	
	ld hl, megamanTile.62
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.1
	
megamanOnLadder.00.m.loader:
	setDefaultMegamanTilesAddress
	ld hl, megamanOnLadder.00.m.tiles
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.7
	
megamanOnAir.00.loader:
	setDefaultMegamanTilesAddress
	ld hl, megamanOnAir.00.1.tiles
	ld de, +
	jp outputMegamanTiles.1
+:	
	ld hl, megamanOnAir.00.tiles
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.8

megamanThrowingOnAir.00.m.loader:		
	setDefaultMegamanTilesAddress
	ld hl, megamanTile.122
	ld de, +
	jp outputMegamanTiles.1
megamanShootingOnAir.00.m.loader:	
	setDefaultMegamanTilesAddress
	ld hl, megamanTile.100
	ld de, +
	jp outputMegamanTiles.1
+:	
	ld hl, megamanTile.55
	ld de, +
	jp outputMegamanTiles.1
+:	
	ld hl, megamanTile.110
	ld de, +
	jp outputMegamanTiles.1
+:	
	ld hl, megamanTile.05
	ld de, +
	jp outputMegamanTiles.1
+:	
	ld hl, megamanTile.57
	ld de, +
	jp outputMegamanTiles.4
+:	
	ld hl, megamanOnAir.00.1.m.tiles
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.1

megamanThrowingOnAir.00.loader:
	ld b, $ff & (<megamanTile.123 + ($ff & 24*8))
	jp +
megamanShootingOnAir.00.loader:
	ld b, $ff & (<megamanTile.108 + ($ff & 24*8))
+:	
	setDefaultMegamanTilesAddress
	ld hl, megamanOnAir.00.1.tiles
	ld de, +
	jp outputMegamanTiles.1
+:	
	ld hl, megamanOnAir.00.tiles
	ld de, +
	jp outputMegamanTiles.4
+
	ld hl, megamanTile.06
	ld de, +
	jp outputMegamanTiles.1
+:	
	ld hl, megamanTile.111
	ld de, +
	jp outputMegamanTiles.1
+:	
	ld hl, megamanTile.56
	ld de, +
	jp outputMegamanTiles.1
+:	
	ld h, >megamanTile.108
	ld l, b
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.1
	
megamanOnAir.00.m.loader:
	setDefaultMegamanTilesAddress
	ld hl, megamanOnAir.00.m.tiles
	ld de, +
	jp outputMegamanTiles.8
+:	
	ld hl, megamanOnAir.00.1.m.tiles
	ld de, megamanTileLoaderReturn
	jp outputMegamanTiles.1

.ends

.macro outputMegamanTile
.rept 8	
	outi
	outi
	outi
	in a, (VdpDataPort)
.endr	
.endm

;de: jump back address
;hl: address of the first tile
.section "outputMegamanTiles" free
outputMegamanTiles.8:
	outputMegamanTile
outputMegamanTiles.7:
	outputMegamanTile
outputMegamanTiles.6:
	outputMegamanTile
outputMegamanTiles.5:
	outputMegamanTile
outputMegamanTiles.4:
	outputMegamanTile
outputMegamanTiles.3:
	outputMegamanTile
outputMegamanTiles.2:
	outputMegamanTile
outputMegamanTiles.1:
	outputMegamanTile
outputMegamanTiles.end:
	ex de, hl
	jp (hl)
.ends
