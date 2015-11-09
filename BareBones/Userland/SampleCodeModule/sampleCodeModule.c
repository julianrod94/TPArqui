#include <stdint.h>
#include "stdio.h"
#include "programs.h"
#include "interpreter.h"


char * v = (char*)0xB8000 + 79 * 2;

extern char bss;
extern char endOfBinary;

static char buffer[256]={0};


void * memset(void * destiny, int32_t c, uint64_t length);

int main() {
	
	//Clean BSS
	memset(&bss, 0, &endOfBinary - &bss);

	printf("\n");


	while(1){
		printf("$>");
		readLine(buffer,256);
		inputInterpreter(buffer);
		printf("\n");

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
