void halt();
void reset();
void shutdown();
void strcpy(char * dest, const char * src);
int strlen(const char * str);
void swapBanks(char bank,char index);
void memcpy(char * dest, char * src,int length);
void memfill(char *dest,char val,int length);
void panic(char *what);

#define TITLE(x) void title() __naked {                                        \
	__asm                                                                      \
	.db x, 0                                                                   \
	__endasm;                                                                  \
}
