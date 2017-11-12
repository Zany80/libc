#include <system.h>

void halt() __naked{
	__asm
	halt
	ret
	__endasm;
}

void shutdown() __naked {
	__asm
	ld a, 1
	out (2), a
	__endasm;
}

void reset() __naked {
	__asm
	ld a, 0
	out (2), a
	__endasm;
}

void strcpy(char * dest, const char * src){
	char cont = 1;
	while(cont == 1){
		*dest = *src;
		if((*src) == 0)
			cont = 0;
		dest++;
		src++;
	}
}

void memcpy(char * dest, const char * src,int length){
	int i=0;
	for(;i<length;i++){
		*dest = *src;
		dest++;
		src++;
	}
}

void putch(char c);
int strlen(const char *s){
	int i = 0;
	char cont = 1;
	while(cont == 1){
		if((*s) == 0){
			cont = 0;
		}
		else {
			i++;
			s++;
		}
	}
	return i;
}

short swapBanks(char bank,char index) __naked{
	__asm
	pop af
	pop de
	push de
	push af
	push af
	ld a, 3
	out (2), a
	ret
	__endasm;
	bank;index;
}
