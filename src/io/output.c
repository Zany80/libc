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
	while((*str)!=0)
		putch(*str++);
}
