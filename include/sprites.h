#pragma once

//512 sprites, laid out in 64 rows of 8

typedef struct {
	// Upper nybble is width, lower nybble is height.
	// Width and height are multiples of 8
	unsigned char size;
	char * data;
	int index;
} sprite_t;

void create_sprite(sprite_t *buffer,unsigned char size,char * sprite_data);

void uploadSprite(short index,char *sprite);
void uploadSprite16_16(short index,char *sprite,char transparent_color);
void uploadSprite32_32(short index,char *sprite,char transparent_color);
void drawSprite(short index,short x,short y);
void drawSprite16_16(short startIndex,short x,short y);
void drawSprite32_32(short startIndex,short x,short y);
void drawSprite16_8(short startIndex,short x,short y);

////void uploadSprite(sprite_t *s);
