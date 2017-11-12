#include <input.h>
#include <output.h>
#include <system.h>

keycode_t pollInput() __naked{
	__asm
	in a, (1)
	ld l, a
	ret
	__endasm;
}

keycode_t waitInput(){
	keycode_t code;
	while((code=pollInput())==0);
	return code;
}

char isNumeric(keycode_t keycode){
	return (keycode>=1&&keycode<=10)?1:0;
}

char isLetter(keycode_t keycode){
	return (keycode>=keyq && keycode<=keyp) || (keycode>=keya && keycode<=keyl)
		|| (keycode>=keyz && keycode<=keym);
}

char * get_buf() __naked{
	__asm
	ld hl, .buf
	ret
	.buf: .block 16
	__endasm;
}

char *toAscii(keycode_t keycode){
	const char * codes=" 1234567890qwertyuiopasdfghjkl;zxcvbnm,./";
	char * c = get_buf();
	if (keycode>strlen(codes)){
		strcpy(c,"Unknown key");
	}
	else {
		c[1] = codes[keycode];
		c[2] = c[0] = '\'';`
		c[3] = 0;
	}
	return c;
}
