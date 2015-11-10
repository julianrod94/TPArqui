#include <stdint.h>
#include "console.h"



char * v = (char*)0xB8000 + 79 * 2;

extern char bss;
extern char endOfBinary;


void * memset(void * destiny, int32_t c, uint64_t length);

int main() {
	
	//Clean BSS
	memset(&bss, 0, &endOfBinary - &bss);
	startShell();
	return 0;
}

void * memset(void * destiation, int32_t c, uint64_t length) {
	uint8_t chr = (uint8_t)c;
	char * dst = (char*)destiation;

	while(length--)
		dst[length] = chr;

	return destiation;
}
