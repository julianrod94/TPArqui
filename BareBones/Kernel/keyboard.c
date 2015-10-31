#include <types.h>
#include <naiveConsole.h>
#include <interrupts.h>
#include <handlers.h>
#include <keyboard.h>

static unsigned char kbdus[128] =
	{
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '-', '=', '\b',	/* Backspace */
  '\t',			/* Tab */
  'q', 'w', 'e', 'r',	/* 19 */
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',	/* Enter key */
    0,			/* 29   - Control */
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
 '\'', '`',   0,		/* Left shift */
 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
  'm', ',', '.', '/',   0,				/* Right shift */
  '*',
    0,	/* Alt */
  ' ',	/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    0,	/* Up Arrow */
    0,	/* Page Up */
  '-',
    0,	/* Left Arrow */
    0,
    0,	/* Right Arrow */
  '+',
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


static uint64_t blockMayus = 0;
static uint64_t leftShift = 0;
static uint64_t rightShift = 0;
static char shiftChars[10] = {'!','"','#','$','%','&','/','(',')','='};
static char buffer[256]={0};
static uint64_t enQueueIndex = 0;
static uint64_t deQueueIndex = 0;

void myKeyboard(){
	uint64_t num = portRead();
	char c = kbdus[num];

	if(num >= 128)	// Si se va de la tabla no quiero que imprima
		c = 0;

	uint64_t mayus = isMayus(num);

	if(c != 0){		// Si esta en la tabla y no es 0, imprime
		if(mayus && isAlpha(c)){
			c = c + ('A'-'a');
		}
		if(isNum(c) && shifted()){
			c = shiftChars[c - '0' - 1];
		}
		if(enQueueIndex + 1 != deQueueIndex){	
			buffer[enQueueIndex] = c;
			enQueueIndex++;	
			ncPrintChar(c);
		}
	}
}

uint64_t isAlpha(char c){
	if(c >= 'a' && c <= 'z'){
		return 1;
	}
	return 0;
}

uint64_t isNum(char c){
	if(c >= '0' && c <= '9'){
		return 1;
	}
	return 0;
}

uint64_t isMayus(uint64_t num){
	if(num == 58)		//Prendo blockMayus
		blockMayus = 1 - blockMayus;
	else if(num == 42)	//Prendo leftShift
		leftShift = 1;
	else if(num == 170)	//Apago leftShift
		leftShift = 0;
	else if(num == 54)	//Prendo rightShift
		rightShift = 1;
	else if(num == 182)	//Apago rightShift
		rightShift = 0;

	return (blockMayus + leftShift + rightShift)%2;
}

uint64_t shifted(){
	return (leftShift + rightShift) % 2;
}