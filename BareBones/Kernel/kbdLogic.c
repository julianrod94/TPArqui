#include <stdint.h>
#include <keyboard.h>
#include <naiveConsole.h>

#define NUMBER 1
#define LETTER 2
#define SYMBOL 3
#define OTHER 0


static unsigned char kbdTable[128] = {
    0, /* No key for scan code 0 */ 
    27, '1', '2', '3', '4', '5', '6', '7', '8',	'9', '0', '-', '=', '\b',
    '\t', 'q', 'w', 'e', 'r',	't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
    0, /* 29   - Control */
    
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
    0,	/* Left shift */
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',
    0,	/* Right shift */
    0,  /*PrtScr */
    0,	/* Alt */
    ' ',/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    0,	/* Up Arrow */
    0,	/* Page Up */
    0,
    0,	/* Left Arrow */
    0,
    0,	/* Right Arrow */
    0,
    0,	/* 79 - End key*/
    0,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    0,	/* F11 Key */
    0,	/* F12 Key */
    0,	/* All other keys are undefined */
};


static unsigned char shiftedKbdTable[128] = {
    0,  /* No key for scan code 0 */
    27, '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '\b',
    '\t', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n',
    0,  /* 29   - Control */
    'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '\"', '~',
    0,  /* Left shift */
    '\\', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?',
    0,  /* Right shift */
    0,  /*PrtScr*/
    0,  /* Alt */
    ' ',/* Space bar */
    0,  /* Caps lock */
    0,  /* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,  /* < ... F10 */
    0,  /* 69 - Num lock*/
    0,  /* Scroll Lock */
    0,  /* Home key */
    0,  /* Up Arrow */
    0,  /* Page Up */
    0,
    0,  /* Left Arrow */
    0,
    0,  /* Right Arrow */
    0,
    0,  /* 79 - End key*/
    0,  /* Down Arrow */
    0,  /* Page Down */
    0,  /* Insert Key */
    0,  /* Delete Key */
    0,   0,   0,
    0,  /* F11 Key */
    0,  /* F12 Key */
    0,  /* All other keys are undefined */
};


static int analizeScanCode(uint64_t code) {

    
    if (code >= 2 && code <= 12) {
        return NUMBER;
    }
    if ( (code >= 16 && code <= 25) || (code >= 30 && code <= 38) || (code >= 44 && code <= 50) ) {
        return LETTER;
    }
    if (code == 1 || code == 12 || code == 13 || code == 14 || code == 15
        || code == 26 || code == 27 || code == 28 || code == 39 || code == 40
        || code == 41 || code == 51 || code == 52 || code == 53 || code == 57) {
        return SYMBOL;
    }
    return OTHER;
}


char getCharFromKbd() {

    uint8_t code = dequeueKey();
    int flag = analizeScanCode(code);
    char result = -1;
	int shift, capsLock, numLock;
	shift = isShifted();
	capsLock = isCapsLockOn();
	numLock = isNumLockOn();


    switch(flag) {

        case NUMBER: {
            int symbols = ((shift != 0)? 1 : 0) - capsLock; /* XOR operation */
            if (symbols) {
                result = shiftedKbdTable[code];
            } else {
                result = kbdTable[code];
            }
            break;
        }
        case LETTER: {
            int maysuc = ((shift != 0)? 1 : 0) - capsLock; /* XOR operation */
            if (maysuc) {
                result = shiftedKbdTable[code];
            } else {
                result = kbdTable[code];
            }
            break;
        }
        case SYMBOL: {
            if (shift) {
                result = shiftedKbdTable[code];
            } else {
                result = kbdTable[code];
            }
            break;
        }
    }
    return result;
}




