#include <naiveConsole.h>

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base);

static char buffer[64] = { '0' };
static uint8_t * const video = (uint8_t*)0xB8000;
static uint8_t * currentVideo = (uint8_t*)0xB8000;
static const uint32_t width = 80;
static const uint32_t height = 25 ;
static uint64_t position = 0;

uint8_t * getCurrentVideo() {
	return currentVideo;
}


void ncPrint(const char * string)
{
	int i;

	for (i = 0; string[i] != 0; i++)
		ncPrintChar(string[i]);
}

void ncPrintChar(char character) {

	if(currentVideo - video >= width * height * 2){
		shiftLines();
		currentVideo -= width * 2;
		do {
			ncPrintChar(' ');
		} while((uint64_t)(currentVideo - video) % (width * 2) != 0);
		currentVideo -= width * 2;
	}

	if (character == '\b') {
		currentVideo -= 2;
		*currentVideo = ' ';
		position--;
	} else if (character == '\t') {
		currentVideo += 2*4;
	} else if (character == '\n') {
		ncNewline();
	} 
	else {
		*currentVideo = character;
		currentVideo += 2;
		position = (video - currentVideo)/2;
	}
}

void ncNewline() {
	do {
		ncPrintChar(' ');
	} while((uint64_t)(currentVideo - video) % (width * 2) != 0);

	if(currentVideo - video == width * height * 2){

		shiftLines();
		currentVideo -= width*2;

		do {
			ncPrintChar(' ');
		} while((uint64_t)(currentVideo - video) % (width * 2) != 0);

		currentVideo -= width * 2;
	}

}

void ncPrintDec(uint64_t value)
{
	ncPrintBase(value, 10);
}

void ncPrintHex(uint64_t value)
{
	ncPrintBase(value, 16);
}

void ncPrintBin(uint64_t value)
{
	ncPrintBase(value, 2);
}

void ncPrintBase(uint64_t value, uint32_t base)
{
    uintToBase(value, buffer, base);
    ncPrint(buffer);
}

void ncBackSpace(){
	currentVideo -= 2;
	ncPrintChar(' ');
	currentVideo -= 2;
}

void ncClear()
{
	int i;

	for (i = 0; i < height * width; i++)
		video[i * 2] = ' ';
	currentVideo = video;
}

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base)
{
	char *p = buffer;
	char *p1, *p2;
	uint32_t digits = 0;

	//Calculate characters for each digit
	do
	{
		uint32_t remainder = value % base;
		*p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
		digits++;
	}
	while (value /= base);

	// Terminate string in buffer.
	*p = 0;

	//Reverse string in buffer.
	p1 = buffer;
	p2 = p - 1;
	while (p1 < p2)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}

	return digits;
}

void shiftLines(){
	
	int i;
	for(i = width * 2; i < width * height * 2; i+=2){
		video[i - (width * 2)] = video[i];
	}
}
