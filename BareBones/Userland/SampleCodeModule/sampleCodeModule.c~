#include <stdint.h>
#include "stdio.h"
#include "string.h"



char * v = (char*)0xB8000 + 79 * 2;

extern char bss;
extern char endOfBinary;

static int var1 = 0;
static int var2 = 0;


void * memset(void * destiny, int32_t c, uint64_t length);

int main() {
	
	//Clean BSS
	memset(&bss, 0, &endOfBinary - &bss);
	char buffer[100];
	int i = 0, flag = 0;
	printf("Hola\nIngrese texto: ");
	readLine(buffer, 100);
	printf("\n\nUsted ingreso %s\n", buffer);
	while(1);

	//Test if BSS is properly set up
	if (var1 == 0 && var2 == 0)
		return 0xDEADC0DE;
	
	while(1){
		
		
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
