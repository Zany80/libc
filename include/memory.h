char* malloc(int size);
void free(char *memory);

#define PAGE(page_number) __asm                                                \
    _page##page_number: \\                                                     \
    .db "THISISVERYIMPORTANTDUDE!"          \\                                 \
	.block (0x4000 * 0x##page_number) - _page##page_number                     \
	__endasm;
