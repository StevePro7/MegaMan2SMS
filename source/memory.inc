.ifndef __MEMORY__
.define __MEMORY__

.struct _resolutionDependencies
	extendedHeight db
	introTextScroll db
	objectToSpriteYOffset db
	invalidYPosition db
	openingFirstDepackedLine dw
	openingFirstVramLine dw
	openingScroll db
	nameTableBegining dw
	verticalScrollEnd db
	preLoadScrollDown dw
 	posLoadScrollDown dw
	preLoadScrollUp dw
 	posLoadScrollUp dw
.endst

.struct aPLibMemoryStruct
bits     db
byte     db ; not directly referenced, assumed to come after bits
LWM      db
R0       dw
.endst

.enum $c000
	metaTiles dsb 2048
.ende

.enum $c800
	verticalScroll dw
	visualHScroll dw
	hScroll dw
	columnToLoad db
	gravityMinusOne db
	gravity db
	gravity.hi db
	
	;psgainden decompressor values	
	tileDecompVramPtr dw
	tileDecompBuffer dsb 32
	
	waitingForVBlank db
	frameCounter db
	random db
	generalFlags db
	spHolder dw
	megamanNextTilesLoader db
	megamanCurrentTilesLoader db
	
	;game status
	difficult db
	numEtanks db
	numLifes db
	megamanLife db
	bossesBeaten db
	currentBoss db
	itens db
	megamanFireingPose db
	selectedWeapon db
	onAirArmPart dw
	onAirArmPart.m dw
	onLadderArmPart dw
	onLadderArmPart.m dw
	
	bubblemanWeaponLeft db
	airmanWeaponLeft db
	quickmanWeaponLeft db
	heatmanWeaponLeft db
	woodmanWeaponLeft db
	metalmanWeaponLeft db
	flashmanWeaponLeft db
	crashmanWeaponLeft db
	item1WeaponLeft db
	item2WeaponLeft db
	item3WeaponLeft db
	/*
	;mapsEngine
	verticalScroll dw
	visualHScroll dw
	hScroll dw
	columnToLoad db
	gravityMinusOne db
	gravity db
	gravity.hi db*/
	
	
	transitionCheck db
	beginningTransitions.bottom dw
	beginningTransitions.top dw
	beginningTransitions.right dw
	endingTransitions.bottom dw
	endingTransitions.top dw
	endingTransitions.right dw
	
	stage.bank db
	stage.loader dw
	stage.compressedMapsBank db
	
	limits.orientation db
	limits.beginning db
	limits.ending db
	
	checkpoint.transition dw
	checkpoint.megamanStartPosition db
	
	;megaman specifics
	jpMegamanCurrentMechanic db
	megamanCurrentMechanic dw
	
	moveableUnderTileType db
	platformSpeed dw
 	slipOnAirSpeedLeft db
	slipOnAirSpeedRight db
	
	;controls
	holdedKeys db
	holdedKeysPrevious db
	pressedKeys db
	pauseButtonPressed db
	readControlsFunction dw  
	
	;vdp misc registers values
	vdpMisc1Value db
	vdpMisc2Value db
	
	resolutionDependencies instanceOf _resolutionDependencies
	
	aPLibMemory instanceOf aPLibMemoryStruct
	;PSG Stuff
	; fundamental vars
	PSGMusicBank			   db
	PSGMusicStatus             db    ; are we playing a background music?
	PSGMusicStart              dw    ; the pointer to the beginning of music
	PSGMusicPointer            dw    ; the pointer to the current
	PSGMusicLoopPoint          dw    ; the pointer to the loop begin
	PSGMusicSkipFrames         db    ; the frames we need to skip
	PSGLoopFlag                db    ; the tune should loop or not (flag)
	PSGMusicLastLatch          db    ; the last PSG music latch
	; decompression vars
	PSGMusicSubstringLen       db    ; lenght of the substring we are playing
	PSGMusicSubstringRetAddr   dw    ; return to this address when substring is over
	; ******* SFX *************
	; command buffering for channels 2-3
	PSGSFXCurrentPlayingPriority db
	PSGChan2Volume             db       ; the volume for channel 2
	PSGChan3Volume             db       ; the volume for channel 3
	PSGChan2LowTone            db       ; the low tone bits for channels 2
	PSGChan3LowTone            db       ; the low tone bits for channels 3
	PSGChan2HighTone           db       ; the high tone bits for channel 2
	; flags for channels 2-3 access
	PSGChannel2SFX             db       ; !0 means channel 2 is allocated to SFX
	PSGChannel3SFX             db       ; !0 means channel 3 is allocated to SFX
	; fundamental vars for SFX
	PSGSFXStatus               db       ; are we playing a SFX?
	PSGSFXStart                dw       ; the pointer to the beginning of SFX
	PSGSFXPointer              dw       ; the pointer to the current address
	PSGSFXSkipFrames           db       ; the frames we need to skip
	PSGSFXLoopFlag             db       ; the SFX should loop or not (flag)
	; decompression vars for SFX
	PSGSFXSubstringLen         db       ; lenght of the substring we are playing
	PSGSFXSubstringRetAddr     dw       ; return to this address when substring is over
.ende

.enum $c900
	palette.hasNewPalette db 
	palette.buffer dsb 32
	
	paletteAnimation.framesPerFrame db
	paletteAnimation.frameCounter db
	paletteAnimation.entriesPerFrame db
	paletteAnimation.bufferPosition db
	paletteAnimation.startOfNextFrame db
	paletteAnimation.buffer db
	
.ende

.enum $c955	
	tempVars2 db
.ende
.define column.columnAddress tempVars2
.define column.buffer tempVars2

.enum $ca00	
	tempVars db
.ende

.enum $cb00
	vramRaw.haveData db
	vramRaw.destination dw
	vramRaw.fastOtirCall dw
	vramRaw.buffer dsb 250
.ende


.enum $cc00
	spriteTable dsb 64
	spriteBottomStack dsb 64
	spriteTableBottom dsb 128
.ende


.struct miscObject
	frame db
	frameTimer db
	x db
	yFraction db
	y dw
	ySpeed dw
.endst

.struct object.1
	flags db
	frame db
	y dw
	x dw
	x.higher db
	dummy db
.endst

.struct object.2
	id db
	frameTimer db
	ySpeed dw
	xSpeed dw
	health db
	dummy db
.endst

.enum $cd00
	miscObjectTable instanceOf miscObject 32
.ende

.define objectTable $cd00
.define objectTable.size 512
.enum $cd00
	objectTable.1 instanceOf object.1 32
	objectTable.2 instanceOf object.2 32
.ende

.enum $cf00
	collisionPropertiesTable dsb 256
.ende

.define gameplayMap.size 3584
.enum $d000
	gameplayMap dsb gameplayMap.size
.ende

.define metaTilesTemp gameplayMap
.endif