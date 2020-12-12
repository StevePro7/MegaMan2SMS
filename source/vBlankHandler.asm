.ifndef __VBLANK_HANDLER_ASM__
.define __VBLANK_HANDLER_ASM__

.bank 0 slot 0


;output the memory palette buffer to VRam
; c : VdpDataPort
.macro outputPalette ;Lbl_d0f5
	xor a
	out (VdpControlPort), a
	ld a, CramWrite.hi
	out (VdpControlPort), a

	fastOtir 32
.endm

;output the memory sprite table to VRam
; c : VdpDataPort
.macro outputSpriteTable
	
	setDebugBorderColor c223
	
	xor a
	out (VdpControlPort), a
	ld a, VramWrite.hi | VramSpriteTable.hi
	out (VdpControlPort), a
	
	ld hl, spriteTable
	fastOtir 64
	
	setDebugBorderColor c113
	
	ld a, VramSpriteTableBottom.lo
	out (VdpControlPort), a
	ld a, VramWrite.hi | VramSpriteTable.hi
	out (VdpControlPort), a
	
	ld l, <spriteTableBottom
	fastOtir 128
.endm

;generates a new random values
.macro updateRandomValue 
	ld a, r
	ld b, a
	rla
	ld c, a
	ld a, (frameCounter)
	rlca
	rlca
	rlca
	rlca
	xor c
	ld (random), a
.endm


;output raw data to the Vdp
;hl : vramRaw.destination
; c : VdpControlPort
.section "outputRawData" free
outputRawData:
	outi
	outi
	dec c ;ld c, VdpDataPort
	ld e, (hl)
	inc l
	ld d, (hl)
	inc l
	jumpDe
.ends


;original : Lbl_cff0
.section "vBlankHandler" free
vBlankHandler:
	push af
	push bc
	push de
	push hl
	in a, (VdpStatusPort)
	ld a, (waitingForVBlank)
	or a
	
	ld a, (MapperSlot2)
	push af
	jp z, runSoundEngine
		ld c, VdpDataPort
		xor a
		ld (waitingForVBlank), a
		outputSpriteTable
;	Temp

		setDebugBorderColor c322	

		ld hl, megamanNextTilesLoader
		ld a, (hl)
		inc l ; megamanCurrentTilesLoader
		cp (hl)
		jp z, megamanTileLoaderReturn 
			ld b, (hl) ; save the previos tile loader
			ld (hl), a	;put the previous as the current 
			ld l, a
			ld h, >megamanTileLoaderPointers.lo
			ld e, (hl)
			inc h; megamanTileLoaderPointers.hi
			ld d, (hl)
			ex de, hl
			jp (hl)
		
megamanTileLoaderReturn:		
		
		setDebugBorderColor $ff	
			
;check if there's a new stream of raw data to output	
 		ld hl, vramRaw.haveData
		ld a, (hl)
		dec a
		jp nz, +
			ld (hl), a
			inc l
			inc c ; ld vdpControlPort
			call outputRawData

+:			
		setDebugBorderColor c300	
	
		setDebugBorderColor $ff

		ld hl, palette.hasNewPalette
		ld a, (hl)
		dec a
		jp nz, +
			ld (hl), a
			inc l
			outputPalette
		
		
;update scrolls
+:		inc c ; ld vdpControlPort
		ld hl, verticalScroll + 1
		ld de, (VdpVerticalScroll << 8) | VdpHorizontalScroll
		outi
		out (c), d
		ld a, (hl)
		neg
		out (VdpControlPort), a
		out (c), e
;increment frame counter		
		ld hl, frameCounter
		inc (hl)	
;update misc registers of the Vdp		
		ld hl, vdpMisc1Value
		outi
		ld a, VdpMisc1
		out (VdpControlPort), a
		ld a, (hl)
		or M2DisplayEnabled		;ensure that the vdp will be enabled on the next frame
		ld (hl), a 
		out (VdpControlPort), a
		ld a, VdpMisc2
		out (VdpControlPort), a
		

runSoundEngine: ;Lbl_d08d:
	call PSGFrame
	
	ld a, :sfxs
	ld (MapperSlot2), a
	call PSGSFXFrame
	pop af
	ld (MapperSlot2), a

	updateRandomValue
	pop hl
	pop de
	pop bc
	pop af
	ei
	ret 
.ends



.macro animatePalette
	ld hl, paletteAnimation.framesPerFrame
	ld a, (hl)
	or a
	jr z, animatePalette.end	; it's more likely to not take the jump, at least when the in a CPU critical situation.
animatePalette:
	inc l	;paletteAnimation.frameCounter
	dec (hl)
	jp nz, animatePalette.end ;using jp because the jump is most likely to be taken
	ld (hl), a

	inc l;ld hl, paletteAnimation.entriesPerFrame
	ld c, (hl)
	ld b, 0
	
	inc l; paletteAnimation.bufferPosition
	ld e, (hl)
	ld d, >palette.buffer
	
	inc l; paletteAnimation.startOfNextFrame
	ld l, (hl); load paletteAnimation.buffer in the right position
	
	ldir
	ld a, (hl)
	inc a
	jr nz, +
		ld l, <paletteAnimation.buffer
+:	ld a, l
	ld (paletteAnimation.startOfNextFrame), a
	
	ld l, <palette.hasNewPalette
	ld (hl), 1
animatePalette.end:
.endm


;start waiting for vBlank. After the interrupt handler finishes, read the control ports.
.section "prepareForVblank" free
prepareForVblank: ; Lbl_c0ab
	animatePalette
	
	ld a, $01
	ld hl, waitingForVBlank
	ld (hl), a
-:	and (hl)
	jp nz, -
	
	ld hl, (readControlsFunction)
	jp (hl)
endControlReading:	
	ld hl, holdedKeys
	ld b, a
	ld a, (hl)
	ld (hl), b
	inc l ; ld hl, holdedKeysPrevious
	ld (hl), a
	inc l ; ld hl, pressedKeys
	xor b
	and b
	ld (hl), a
	ret 
.ends

.endif