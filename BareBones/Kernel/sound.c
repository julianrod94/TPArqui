#include "sound.h"
#include "interrupts.h"

static int frecTable[128] =
	{
    0,  27, 0, 0, 0, 0, 0, 0, 0, 0,	/* 9 */
  0, 0, 0, 0, 0,	/* Backspace */
  0,			/* Tab */
  	0/*q*/, 9121, 8609, 8126,	/* 19 */
  7670, 7239, 6833, 6449, 6087, 5746, 0, 0, 0,	/* Enter key */
    0,			/* 29   - Control */
  5423, 5119, 4831, 4560, 4304, 4063, 3834, 3619, 3416, 0,	/* 39 */
 	0, 0,   0,		/* Left shift */
 	0, 3224, 3043, 2873, 2711, 2559, 2415,			/* 49 */
  2280 /*m*/, 0, 0, 0,   0,				/* Right shift */
  	0,
    0,	/* Alt */
  	0,	/* Space bar */
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

void soundHandler(uint64_t mode, uint64_t frequency) {

	if (mode == 0) {

		if (frequency < 0 || frequency > 65535) {
			return;
		}
		turnOnSound(frequency);
	}
	else {
		turnOffSound();
	}
}

uint64_t soundOn = 0;
static uint64_t vibrato = 0;
uint64_t lastFrec = 0;

void makeSound(){

	uint64_t num = portRead();

	uint64_t frec = frecTable[num];

	if(num >= 128)
		frec = 0;

	if(num == 42 || num == 54){
		vibrato = 1;
		return;
	}
	if(num == 170 || num == 182){
		vibrato = 0;
		return;
	}

	if(frec != 0){
		if(vibrato){
			frec = getVibrato(frec,num);
		}
		if(frec != lastFrec && soundOn){
			bend(lastFrec,frec);
		}
		else
			turnOnSound(frec);
		soundOn = 1;
		lastFrec = frec;
	
	}
	else{
		if(soundOn == 1){
			turnOffSound();
		}
		soundOn = 0;
	}

}

uint64_t getVibrato(uint64_t frec, uint64_t num){
	if(frec == 2280){	// Si es la nota mas aguda
		frec = 2200;
	}else if(frec == 5746){
		frec = (5746+5423)/2;
	}else if(frec == 3416){
		frec = (3416+3224)/2;
	}
	else
		frec = (frecTable[num] + frecTable[num+1])/2;
	return frec;
}

void bend(uint64_t from, uint64_t to){
	int j=0;
	
	while(from != to){
		j = 0;
		turnOnSound(from);
		while(j<5000){
			j++;
		}
		if(from > to)
			from--;
		else
			from++;
	}
}
