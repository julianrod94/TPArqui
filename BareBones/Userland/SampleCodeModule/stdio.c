#include <stdint.h>
#include "syscallwrappers.h"
#include <stdarg.h>
#include "math.h"
#include "stdio.h"

#define SYMBOL_ERROR "\n\nError! Simbolo no reconocido. Abortando...\n"
#define BUFFER_SIZE 1024

static char internalBuffer[BUFFER_SIZE];
static int enqueueIdx = 0;
static int dequeueIdx = 0;
static int buffSize = 0;
static int enterPressed = 0;
static int countRead = 0;


static char readKbdBuffer(void) {
	
	char c;
    read(STDIN, (uint64_t)&c, 1, 1, 0);
    if (!(c == '\b' && !buffSize)){
        putchar(c);
    }
	return c;

}

static void enqueueChar(char c) {
	
	if (buffSize == BUFFER_SIZE) {
		return;
	}
	if (c == '\b') {
		if (buffSize > 0) {
			enqueueIdx--;
			buffSize--;
			if (enqueueIdx < 0) {
				enqueueIdx = BUFFER_SIZE - 1;
			}
		}
		return;
	}
	internalBuffer[enqueueIdx++] = c;
	buffSize++;
	if (enqueueIdx == BUFFER_SIZE) {
		enqueueIdx = 0;
	}
}

static char dequeueChar(void) {
	
	char result = 0;
	if (buffSize > 0) {
		result = internalBuffer[dequeueIdx++];
		buffSize--;
		if (dequeueIdx == BUFFER_SIZE) {
			dequeueIdx = 0;
			
		}
	}
	return result;
}

// static char peekChar(void) {
	
// 	if (buffSize == 0) {
// 		return 0;
// 	}
// 	return internalBuffer[dequeueIdx];
// }


char getchar(void) {
	
	char c, result;
	if (!enterPressed) {
        do {
            c = readKbdBuffer();
            enqueueChar(c);
        } while(c != '\n' && buffSize < BUFFER_SIZE);
		enterPressed = 1;
	}
	result = dequeueChar();
	if (result == '\n') {	
        countRead = 0;
		enterPressed = 0;
	}
	
	return result;
}

void readLine(char * buffer, int size) {

    char c;
    int i;
    while ( (c = getchar()) != '\n' && i < size - 1 ) {
        buffer[i++] = c;
    }
    buffer[i] = 0;
    return;
}

void putchar(char c) {

	write(1, (uint64_t)&c, 1, 0, 0);
}

void printf(char * fmt, ...) {

	va_list ap;
    int i, j = 0, flag = 0; // Manages the format string parse
    char result[256]; // local buffer
	
	va_start(ap, fmt);
    for (i = 0 ; fmt[i] != 0 ; i++) {
        if (flag) {
        	switch (fmt[i]) {
                
                case 'd': {
                    int num, figures;
                    num = va_arg(ap, int);
                    figures = decimalDigits(num);
                    
                    while (figures) {
                        
                        result[j++] = (char) ((num % ipow(10, figures)) / ipow(10, figures - 1)) + '0';
                        figures--;
                        if (j == 256) {
                        	write(1, (uint64_t)result, 256, 0, 0);
                        	j = 0;
                        }

                    }
                    break;
                }

                case 's': {
                    char * aux;
                    aux = va_arg(ap, char *);
                    int k = 0;
                    while (aux[k] != 0) {

                        result[j++] = aux[k++];
                        if (j == 256) {
                        	write(1, (uint64_t)result, 256, 0, 0);
                        	j = 0;
                        }
                    }
                    break;
                }
                default: {
                	const char * error = SYMBOL_ERROR;
                	write(1, (uint64_t)error, sizeof(SYMBOL_ERROR), 0, 0);
                	break;
                }
                    
            }
            flag = 0;
            
        } else {
            if (fmt[i] == '%') {
                flag = 1;
            } else {
                result[j++] = fmt[i];
                if (j == 256) {
                	write(1, (uint64_t)result, 256, 0, 0);
                	j = 0;
                }
            }
        }
    }
    va_end(ap);
    write(1, (uint64_t)result, (uint64_t) (j % 256) , 0, 0);
}

uint64_t askIfThereWasInput(void) {
    
    uint64_t result;
    read(STDIN, (uint64_t)&result, 1, 4, 0);
	if (result) {		
		char c;
	    read(STDIN, (uint64_t)&c, 1, 2, 0);
	}
    return result;
}

void clearShell(void){
    write(3,0,0,0,0);
}


