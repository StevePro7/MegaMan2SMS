.ifndef __CONTROLS_ASM__
.define __CONTROLS_ASM__

;Lbl_d0d7
;return:
; a: The status of the keys (SACBRLDU), 0:Key Umpressed.
.section "readMegaDriveController" free 
readMegaDriveController:
	; TH = 1 : ?1CBRLDU		3-button pad return value
	;Read the first pass of the Genesis control
	in a, ($DC)		
	or $c0
	ld b, a

	; TH = 0 : ?0SA00DU		3-button pad return value
	ld a, Th.lo
	out ($3F), a
	
	;Load the Pause button status
	ld hl, pauseButtonPressed
	ld a, (hl)
	and b
	ld b, a
	ld (hl), $ff

	;Read the second pass of the Genesis control
	in a, ($DC)
	rlca
	rlca
	or $3f
	and b
	cpl

	;Set TH hi for the next pass
	ld bc, (Th.hi << 8) | $3F
	out (c), b
	jp endControlReading
.ends

;return:
; a: The status of the keys (P021RLDU), 0:Key Umpressed.
.section "readMasterSystemController" free
readMasterSystemController:
	in a, ($DC)
	or $c0
	ld hl, pauseButtonPressed
	and (hl)
	ld (hl), $ff
	cpl
	jp endControlReading

.ends


.endif