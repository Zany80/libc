#pragma once

void halt();
void reset();
void shutdown();
void strcpy(char * dest, const char * src);
int strlen(const char * str);
void swapBanks(char bank,char index);
void memcpy(char * dest, char * src,int length);
void memfill(char *dest,char val,int length);
void panic(char *what);
unsigned char getPageFromAddress(int address);

// Must be used at way beginning of function - make sure nothing is on stack
void * getCaller();

typedef void (*function)();

#define TITLE(x) void title() __naked {                                        \
	__asm                                                                      \
	.db x, 0                                                                   \
	__endasm;                                                                  \
}

function PAGED_CALL(function func,unsigned char page);
void * PAGED_ADDRESS(int address);
#define PAGED_POINTER(x) PAGED_ADDRESS((int)x)
