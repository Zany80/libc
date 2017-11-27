#include <output.h>

void cls(){
	putch(0);
	__asm
	push af
	push bc
	ld a, 5
	ld b, 0
	out (2), a
	pop bc
	pop af
	__endasm;
}

void putch(char c){
	__asm
	pop hl
	dec sp
	pop af
	push af
	inc sp
	push hl
	out (0), a
	__endasm;
	c;
}

void puts(char *str){
	//DEPRECATED - use text() instead
	while((*str)!=0)
		putch(*str++);
}

void text(char * str,char x,char y,char color,char size) {
	__asm
	pop af
	pop hl
	pop bc
	pop de
	push de
	push bc
	push hl
	push af
	ld a, 4
	out (2), a
	__endasm;
	str;x;y;color;size;
}
