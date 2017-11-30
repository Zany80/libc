char* malloc(int size);
void free(char *memory);

#define PAGE(page_number) __asm                                        \
	.area page##page_number                                            \
	__endasm;
