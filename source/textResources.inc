.ifndef __TEXT_RESOURCES_INC__
.define __TEXT_RESOURCES_INC__

.asciitable
map 'A' TO 'Z' = $99
map ' ' = $98
map '0' = $a7
map '1' TO '9' = $8f
map 'c' = $8e
map 'r' = $b3
map '.' = $b4
map ',' = $b5
map "'" = $b6
map '!' = $b7
.enda
.endif

.slot 2
.section "preOpeningText and openinigText" superfree
preOpeningText:
	.byte 4
	.byte 21 
	.word $39ce | VramWrite
	.asc  "c1988 CAPCOM CO.LTD"
	.byte 33
	.word $3a42 | VramWrite
	.asc  "TM AND c1989 CAPCOM U.S.A.,INC."
	.byte 13
	.word $3ad6 | VramWrite
	.asc  "LICENSED BY"
	.byte 29
	.word $3b48 | VramWrite
	.asc  "NINTENDO OF AMERICA. INC."
	
openingText: ; Prg13_Lbl_ad46
  .asc "   IN THE YEAR OF 200X,    "
  .asc "A SUPER ROBOT NAMED MEGAMAN"
  .asc "       WAS CREATED.        "
  .asc " DR.LIGHT CREATED MEGAMAN  "
  .asc " TO STOP THE EVIL DESIRES  "
  .asc "        OF DR.WILY.        "
  .asc " HOWEVER,AFTER HIS DEFEAT, "
  .asc "   DR.WILY CREATED EIGHT   "
  .asc "    OF HIS OWN ROBOTS      "
  .asc "   TO COUNTER MEGAMAN.     "
.ends


.section "blueGridScreensTexts" superfree
blueGrid.startPasswordText:
	.byte 2
	.byte 8
	.word $3a9a | VramWrite
	.word endSeqOuti - 8*4
	.asc "START   "
	
	.byte 8
	.word $3b1a | VramWrite
	.word endSeqOuti - 8*4
	.asc "PASSWORD"
	
blueGrid.passwordFailText:	
	.byte 2
	.byte 8
	.word $3a9a | VramWrite
	.word endSeqOuti - 8*4
	.asc "PASSWORD"
	
	.byte 7
	.word $3b1a | VramWrite
	.word endSeqOuti - 7*4
	.asc "ERROR !"
.ends

.section "stageSelection.text" superfree
stageSelection.text:
	.db 11
	.db 16
	.dw  VramWrite | $3812
	.asc " PRESS  START "
	.db 8
	.dw  VramWrite | $39ca
	.asc "BUBBLE"
	.db 5
	.dw  VramWrite | $39dc
	.asc "AIR"
	.db 7
	.dw  VramWrite | $39ea
	.asc "QUICK"
	.db 6
	.dw  VramWrite | $3bca
	.asc "HEAT"
	.db 4
	.dw  VramWrite | $3bdc
	.asc "Dr"
	.db 6
	.dw  VramWrite | $3bea
	.asc "WOOD"
	.db 6
	.dw  VramWrite | $3c1e
	.asc "WILY"
	.db 7
	.dw  VramWrite | $3dca
	.asc "METAL"
	.db 7
	.dw  VramWrite | $3dda
	.asc "FLASH"		
	.db 7
	.dw  VramWrite | $3dea
	.asc "CRASH"		
.ends

.endif