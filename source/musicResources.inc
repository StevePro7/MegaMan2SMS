.ifndef __MUSIC_RESOURCES_INC__
.define __MUSIC_RESOURCES_INC__


.slot 2
/*.section "wilyStage1Music" superfree
wilyStage1Music:	
	.incbin "songs\wilyStage1.psg"
.ends
*/


.slot 2
.section "mainMenuMusic" superfree
mainMenuMusic:	
	.incbin "songs\mainmenu.psg"
.ends

.slot 2
.section "bubblemanMusic" superfree
bubblemanMusic:	
	.incbin "songs\bubbleman.psg"
.ends

.slot 2
.section "mandrillMusic" superfree
mandrillMusic:	
	.incbin "songs\mandrill.psg"
.ends

.slot 2
.section "quickmanMusic" superfree
quickmanMusic:	
	.incbin "songs\quickman.psg"
.ends

.slot 2
.section "heatmanMusic" superfree
heatmanMusic:	
	.incbin "songs\heatman.psg"
.ends

.slot 2
.section "woodmanMusic" superfree
woodmanMusic:	
	.incbin "songs\woodman.psg"
.ends

.slot 2
.section "metalmanMusic" superfree
metalmanMusic:	
	.incbin "songs\metalman.psg"
.ends

.slot 2
.section "flashmanMusic" superfree
flashmanMusic:	
	.incbin "songs\flashman.psg"
.ends

.slot 2
.section "crashmanMusic" superfree
crashmanMusic:	
	.incbin "songs\crashman.psg"
.ends

.slot 2
.section "openingMusic" superfree
openingMusic:	
	.incbin "songs\opening.psg"
.ends

.slot 2
.section "stageSelectMusic" superfree
stageSelectMusic:	
	.incbin "songs\stageSelect2.psg"
.ends

.slot 2
.section "bossIntroductionMusic" superfree
bossIntroductionMusic:	
	.incbin "songs\bossIntroduction.psg"
.ends

.slot 2
.section "titleMusic" superfree
titleMusic:	
	.incbin "songs\title.psg"
.ends


.section "sfx as music"
deathSfx:
	.incbin "sfx\death.psg"
	
teleportOutSfx:
	.incbin "sfx\teleport_out.psg"
.ends


.macro defineSfxHeader args priority, channel2, channel3
	.db priority << 2 | channel3 << 1 | channel2
.endm

.bank 1 slot 1
.section "sfx" free
sfxs:


teleportInSfx: ; played as music	
	defineSfxHeader 2, 1, 0
	.incbin "sfx\teleport_in.psg"	
	
busterSfx:	
	defineSfxHeader 2, 1, 0
	.incbin "sfx\buster.psg"

stepSfx:	
	defineSfxHeader 1, 1, 0
	.incbin "sfx\step.psg"
	
cursorSfx:
	defineSfxHeader 1, 1, 0
	.incbin "sfx\cursor.psg"

upSfx:	
	defineSfxHeader 2, 1, 0
	.incbin "sfx\up.psg"

metalBladeSfx:	
	defineSfxHeader 2, 1, 1
	.incbin "sfx\metalBlade.psg"	
	
.ends
.endif