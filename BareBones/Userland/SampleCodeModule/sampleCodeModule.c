#include <stdint.h>
#include "stdio.h"
#include "music.h"


char * v = (char*)0xB8000 + 79 * 2;

extern char bss;
extern char endOfBinary;

static char* buffer;


void * memset(void * destiny, int32_t c, uint64_t length);

int main() {
	
	//Clean BSS
	memset(&bss, 0, &endOfBinary - &bss);
	
	printf("Hola");
	pianoPlay();
	while(1) {	
		char c = getchar();
		putchar(c);
	}

	//Test if BSS is properly set up
	if (var1 == 0 && var2 == 0)
		return 0xDEADC0DE;
	
	while(1){
		buffer = readLine();
		
	}
	return 0xDEADBEEF;
}

void * memset(void * destiation, int32_t c, uint64_t length) {
	uint8_t chr = (uint8_t)c;
	char * dst = (char*)destiation;

	while(length--)
		dst[length] = chr;

	return destiation;
}
