.db "ZENITH"
.dw _title
.dw start

start:
	jp _main
	
.area _CODE
.area page1
.block 0x4000 - .
