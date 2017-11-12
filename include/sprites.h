#pragma once

typedef struct {
	// Upper nybble is width, lower nybble is height.
	unsigned char size;
	char * data;
} sprite_t;

void uploadSprite(short index,char *sprite);
void uploadSprite16_16(short index,char *sprite,char transparent_color);
void uploadSprite32_32(short index,char *sprite,char transparent_color);
void drawSprite(short index,short x,short y);
void drawSprite16_16(short startIndex,short x,short y);
void drawSprite32_32(short startIndex,short x,short y);
void drawSprite16_8(short startIndex,short x,short y);

////void uploadSprite(sprite_t *s);
