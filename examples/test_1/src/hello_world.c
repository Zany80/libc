#include <system.h>
#include <output.h>

char *title() __naked{
	__asm
	.asciiz "Hello, World"
	__endasm;
}

void main(){
	int i;
	puts((char*)title);
	for (i = 0; i != 10; i++) {
		putch( '0' + i );
	}
	halt();
}
