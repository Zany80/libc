#pragma once

enum keycode_t{
	key1=1,key2,key3,key4,key5,key6,key7,key8,key9,key0,
	keyq,keyw,keye,keyr,keyt,keyy,keyu,keyi,keyo,keyp,
	keya,keys,keyd,keyf,keyg,keyh,keyj,keyk,keyl,keySEMICOLON,
	keyz,keyx,keyc,keyv,keyb,keyn,keym,keyCOMMA,keyPERIOD,keyFORWARDSLASH,
	keyEXCLAMATION=65,keyAT,keyPOUND,keyDOLLAR,keyPERCENT,keyEXPONENT,
	keyAND,keyASTERISK,keyLEFT_PARENTHESES,keyRIGHT_PARENTHESES,
	keyQ,keyW,keyE,keyR,keyT,keyY,keyU,keyI,keyO,keyP,
	keyA,keyS,keyD,keyF,keyG,keyH,keyJ,keyK,keyL,keyCOLON,
	keyZ,keyX,keyC,keyV,keyB,keyN,keyM,keyLEFTANGLE,keyRIGHTANGLE,keyQUESTION
};

typedef enum keycode_t keycode_t;

keycode_t pollInput();
keycode_t waitInput();

char *toAscii(keycode_t keycode);
