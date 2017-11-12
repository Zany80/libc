#include <system.h>
#include <output.h>

char *title() __naked{
	__asm
	.asciiz "Hello, World"
	__endasm;
}

void main(){
	puts((char*)title);
	halt();
}
