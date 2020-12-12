.ifndef __MAIN_ASM__
.define __MAIN_ASM__

.memorymap
defaultslot 0
slotsize $4000
slot 0 $0000

slotsize $4000
slot 1 $4000

slotsize $4000
slot 2 $8000

slotsize $2000
slot 3 $c000 ; Ram
.endme

.rombankmap
bankstotal 16
banksize $4000
banks 1

banksize $4000
banks 1

banksize $4000
banks 14
.endro

.sdsctag 0.5, "MegaMan 2", "Port", "gvx32"
.smstag

.include "constants.inc"
.include "musicResources.inc"
.include "textResources.inc"
.include "memory.inc"
.include "stageTiles.inc"
.include "paletteResources.inc"
.include "mapsResources.inc"
.include "bossesGraphics.inc"
.include "miscTiles.inc"
.include "opnBossObjectsTable.inc"
.include "miscObjectsTable.inc"
.include "objectAttributes.inc"
.include "imagens\megamanTiles.inc"
.include "weaponsResources.inc"

.include "PSGlib.asm"
.include "utilLib.asm"
.include "psgaindenDecompressor.asm"
.include "controls.asm"
.include "mapLoaders.asm"
.include "spriteHandler.asm"
.include "vBlankHandler.asm"
.include "aplib-z80.asm"
.include "weapons.asm"
.include "objects.asm"
.include "gameplayMapsEngine.asm" 
.include "megamanMechanics.asm"
.include "megamanTileLoaders.asm"
.include "intro.asm"
.include "titleScreen.asm"
.include "startMenu.asm"
.include "passwordEditor.asm"
.include "stageSelection.asm"
.include "bossIntroduction.asm"


.bank 0 slot 0

;Fixed VDP registers Data
.section "vdpConfigData" free
vdpConfigData:
	.db $ff, VdpNameTable
	.db $ff, VdpColorTable
	.db $ff, VdpPatternTable
	.db $ff, VdpSpriteAttrTable
	.db $00, VdpBackgroundColor
	.db $03, VdpSpritePattTable
.if FORCE_192 == 1
	.db 191, VdpLineInterruptNumber 
.else
	.db 223, VdpLineInterruptNumber 
.endif
.ends

;resolution dependent values for 192 and 224 heights.
/*.struct _resolutionDependencies
	extendedHeight db
	introTextScroll db
	objectToSpriteYOffset db
	invalidYPosition db
	lineToAvoidScrollArtifacs db
	openingFirstDepackedLine dw
	openingFirstVramLine dw
	openingScroll db
	nameTableBegining dw
	verticalScrollEnd db
	preLoadScrollDown dw
 	posLoadScrollDown dw
	preLoadScrollUp dw
 	posLoadScrollUp dw
.endst*/
.section "resolutionDependencies" free
resolutionDependencies192:
	.db 0
	.db 0
	.db -24
	.db $d0
    .dw	openingMapLinesEnd - (19*2)
	.dw VramWrite | $3e40
	.db 200
	.dw $3800 | VramWrite
	.db 224
	.dw $031A
	.dw $1901
	.dw $0101
	.dw $1B1C
resolutionDependencies224:
	.db 1
	.db 16
	.db -8
	.db 224
	.dw openingMapLinesEnd - (21*2)
  	.dw VramWrite | $3e80
	.db $f0
	.dw $3700 | VramWrite
	.db 0
	.dw $031C
	.dw $1D1F
	.dw $011F
	.dw $1F1E
.ends


;Tests if the PAD plugged in is a Genesis or a Master System Pad. 
.macro selectController
	ld a, Th.hi
	out ($3F), a
	
	push hl
	pop hl
	push hl
	pop hl
	
	ld a, Th.lo
	out ($3F), a
	
	push hl
	pop hl
	push hl
	pop hl
	
	in a, ($DC)
	and %00001100
	ld hl, readMasterSystemController
	jr nz, isMasterSystem
isMegaDrive:
		ld a, Th.hi
		out ($3F), a
		ld hl, readMegaDriveController
isMasterSystem:
		ld (readControlsFunction), hl
.endm

.section "outputRegisters" free 
outputRegisters:
	out (c), h
	out (c), d
	out (c), l
	out (c), e
	ret
.ends

;Tests if the 224 Extended resolution mode is avaliable
.macro selectResolution
	ld bc, (3 << 8) | VdpControlPort
	ld hl, ((M2Extended224 | M2FrameInterrupts) <<8) | (M1Mode4 | M1ExtendedHeightEnable) 
	ld de, (VdpMisc2 << 8) |	VdpMisc1
	call outputRegisters
	
-:			in a, (c)
		jp p, -
	djnz -
	in a, (VdpLineCounter)
	cp $d0
	ld h, M2Extended224
	ld ix, resolutionDependencies224 
.if FORCE_192 != 1	
	jr nc, +
.endif
		ld hl, M1Mode4
		ld ix, resolutionDependencies192 
+:
	ld (vdpMisc1Value), hl
	call outputRegisters
	push ix
	pop hl
	ld de, resolutionDependencies 
	fastLdir _sizeof__resolutionDependencies
.endm	

;Clear Ram
.macro clearMemory
	ld hl, $c000
	ld de, $c001
	ld bc, $dff0 - $c001
	ld (hl), l
	ldir
.endm



;Hardware initial tests, mapper initialization and main flow of the game
;Orignal label: Prg15_Lbl_f2d1
.section "main" free
main:
	di
	ld sp, $dff0
	im 1
	ld c, VdpControlPort
	ld hl, vdpConfigData
	fastOtir 14
	
	clearMemory
	
selectController:	
	selectController
	selectResolution
	
	xor a
	out (AudioControlPort), a
	ld (MapperSlot0), a
	inc a
	ld (MapperSlot1), a
	
	ld a, $ff
	ld (pauseButtonPressed), a
	ld (gravity.hi), a
	
	ld a, 3
	ld (numLifes), a
	ld a, JumpInstruction
	ld (jpMegamanCurrentMechanic), a
	ld a, RegularGravity
	ld (gravity), a
	
	ld hl, $ffff
	ld (megamanNextTilesLoader), hl
	
	ei
	
-:		
		call opening
		call titleScreen
		ld a, b
		or c
	jr z, -	
	
--:	
	call startMenu.load
	teste1:
	jr z, +
-:		call passwordEditor
		jr z, +
		call startMenu.scroll
	jr nz, -
-:
+:	call PSGStop
	call stageSelection
.if DEBUG == 0		
	call bossIntroduction
.endif	
	call gameplayMapsEngine.loadStage
	
	ld a, 28
	ld (megamanLife), a
	
	call megamanMechanics.bringDown	
	
mainLoop:
		;setDebugBorderColor c222
		ld a, (pressedKeys)
		rla ; put startKeyFlag in the carry flag
		jr c, toggleWeapons
toggleWeaponsEnd:		
		call jpMegamanCurrentMechanic
		call object.processTopHalfObjects
		call gameplayObjectsToSprites
		ld a, (transitionCheck)
		or a
		jp z, +
			call gameplayMapsEngine.checkTransitions
			or a
			jp nz, +
			
				ld a, :deathSfx
				ld hl, deathSfx
				call PSGPlay
				PSGCancelLoop
				
				xor a
				ld (objectTable.1.1.flags), a
				call gameplayObjectsToSprites
				
				ld b, 0
-:				push bc
				call prepareForVblank
				pop bc
				djnz -
			jp --
			
+:		
		;setDebugBorderColor $ff
		call prepareForVblank
	jp mainLoop

toggleWeapons:
	ld hl, objectTable.1.2.flags
	ld a, (hl);Active flag is bit 7 and, bit 7 will be 0 on reg a.
	or a
	jp m, toggleWeaponsEnd

	ld l, <objectTable.1.3.flags
	or (hl)
	jp m, toggleWeaponsEnd

	ld l, <objectTable.1.4.flags
	or (hl)
	jp m, toggleWeaponsEnd
	
	
	ld a, (selectedWeapon)
	xor %00000001
	ld (selectedWeapon), a
	jp nz, +
		mapPage2 :megamanBusterTiles
		decompress megamanBusterTiles, WeaponsTiles*32, 1
		
		ld a, :megamanPalette
		ld hl, megamanPalette
		ld (MapperSlot2), a
		call gameplayMapsEngine.loadPalette
	jp toggleWeaponsEnd
+:;metalmanWeapon
		mapPage2 :metalmanWeaponTiles
		decompress metalmanWeaponTiles, WeaponsTiles*32, 8
		
		ld a, :megamanMetalManPallete
		ld hl, megamanMetalManPallete
		ld (MapperSlot2), a
		call gameplayMapsEngine.loadPalette
	jp toggleWeaponsEnd
.ends

;Just a jumper to the main flow of the game
.org 0
.section "start" force
	jp main
.ends

;Just a jumper to the vBlankHandler
.org $0038
.section "vBlankVector" force
/*	
-:	
		in a, (VdpLineCounter)
		cp 223
	jp c, -
*/	
	nop
	setDebugBorderColor c131
	jp vBlankHandler
.ends

;Sets the flag that the pause button was pressed
.org $0066
.section "pauseButtonHandler" force
	push af
	ld a, $7f 
	ld (pauseButtonPressed), a
	pop af
	retn
.ends
