#include <system.h>
#include <output.h>

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

void memfill(char *dest,char val,int length){
	int i;
	for (i = 0; i < length; i++) {
		dest[i]=val;
	}
}

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

short _swapBanks(char bank,char index) __naked{
	__asm
	pop af
	pop de
	push de
	push af
	push af
	ld a, 3
	out (2), a
	pop af
	ret
	__endasm;
	bank;index;
}

void swapBanks(char bank, char index){
	if (_swapBanks(bank,index) != 0) {
		// Failed to swap banks!
		panic("RAM error!");
	}
}

void * getCaller() __naked {
	__asm
	pop af
	pop hl
	push hl
	push af
	ret
	__endasm;
}

unsigned char getPageFromAddress(int page){
	if (page >= 0xC000) {
		return 3;
	}
	else if (page >= 0x8000) {
		return 2;
	}
	else if (page >= 0x4000) {
		return 1;
	}
	else {
		return 0;
	}
}

function PAGED_CALL(function func,unsigned char page){
	int i;
	if (page > 3) {
		panic("Attempted to call a function on a non existent page!");
		return reset;
	}
	 i = (int)func;
	 i &= 0x3FFF;
	 i |= 0x4000 * page;
	 return (function)i;
}

void * PAGED_ADDRESS(int ptr){
	// MUST NOT HAVE TOO MANY LOCAL VARS OR CALLER IS THROWN OFF!
	void * caller = getCaller();
	{
		unsigned char page = getPageFromAddress((int)caller);
		if (page > 3) {
			panic("Attempted to access a non existent page!");
			return reset;
		}
		ptr &= 0x3FFF;
		ptr |= 0x4000 * page;
		return (void*)ptr;
	}
}

void panic(char *what){
	cls();
	puts(what);
	puts("\n\nTo ignore this error, right click anywhere in the emulator \n(Not recommended)");
	halt();
}
