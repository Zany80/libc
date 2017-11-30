void uploadSprite(short index,char *sprite,char transparent_color){
	__asm
	pop af
	pop de
	pop hl
	push hl
	push de
	push af
	ld a, 6
	out (2), a
	__endasm;
	index;sprite;transparent_color;
}

void uploadSprite16_16(short index,char *sprite,char transparent_color){
	uploadSprite(index,sprite,transparent_color);
	uploadSprite(index+1,sprite+32,transparent_color);
	uploadSprite(index+2,sprite+64,transparent_color);
	uploadSprite(index+3,sprite+96,transparent_color);
}

void uploadSprite32_32(short index,char *sprite,char transparent_color){
	uploadSprite16_16(index,sprite,transparent_color);
	uploadSprite16_16(index+4,sprite+128,transparent_color);
	uploadSprite16_16(index+8,sprite+256,transparent_color);
	uploadSprite16_16(index+12,sprite+384,transparent_color);
}

void drawSprite(short index,short x,short y){
	__asm
	pop af
	pop hl
	pop bc
	pop de
	push de
	push bc
	push hl
	push af
	ld a, 7
	out (2), a
	__endasm;
	index;x;y;
}

void drawSprite16_16(short start_index,short x,short y){
	drawSprite(start_index,x,y);
	drawSprite(start_index+1,x+8,y);
	drawSprite(start_index+2,x,y+8);
	drawSprite(start_index+3,x+8,y+8);
}


void drawSprite32_32(short start_index,short x,short y){
	drawSprite16_16(start_index,x,y);
	drawSprite16_16(start_index+4,x+16,y);
	drawSprite16_16(start_index+8,x,y+16);
	drawSprite16_16(start_index+12,x+16,y+16);
}

void drawSprite16_8(short start_index,short x,short y){
	drawSprite(start_index,x,y);
	drawSprite(start_index+1,x+8,y);
}
