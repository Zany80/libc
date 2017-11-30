#include <system.h>
#include <output.h>

char *title() __naked{
	__asm
	.asciiz "Test1_111417_2017"
	__endasm;
}

int i=7;

void main(){
	int i;
	puts((char*)title);
	puts("I am a test program! Are you a test program?");
	halt();
}
