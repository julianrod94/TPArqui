#include <stdint.h>
#include "syscallwrappers.h"
#include <stdarg.h>
#include "math.h"

#define SYMBOL_ERROR "\n\nError! Simbolo no reconocido. Abortando...\n"

char getchar(void) {

	char c;
    do {
        read(0, (uint64_t)&c, 1, 2, 0);
    } while (c == '\b' || c == '\t');
	return c;
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

char* readLine(){
    char buffer[256];
    int i=0;
    char c=0;
    do {
        read(0, (uint64_t)&c, 1, 1, 0);

        if(c != '\b' && c!='\t' && c!='\n'){

            buffer[i++] = c;
        }
        if(c == '\n'){
            buffer[i]=0;
            return buffer;
        }
        if(c == '\b'){
            i--;
        }
    } while (i<255 && c!='\n');
    if(i==255){
        buffer[255] = 0;
    }
    return buffer;
}
