#include <stdarg.h>

void putchar(char c) {

}

void printf(char * fmt, ...) {

	va_list ap;
    int i, j, flag = 0; // Manages the format string parse
    char result[256]; // local buffer

    for (i = 0 ; fmt[i] != 0 ; i++) {
        
        if (flag) {
        	switch (fmt[i]) {
                
                case 'd': {
                    int num, figures;
                    num va_arg(ap, int);
                    figures = digits(num);
                    
                    while (figures) {
                        
                        result[j++] = (char) ((num % ipow(10, figures)) / ipow(10, figures - 1)) + '0';
                        figures--;
                        if (j == 256) {
                        	write(1, result, 256, 0, 0);
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
                        	write(1, result, 256, 0, 0);
                        	j = 0;
                        }
                    }
                    break;
                }
                default:
                    exit(1);
            }
            flag = 0;
            
        } else {
            if (fmt[i] == '%') {
                flag = 1;
            } else {
                result[j++] = fmt[i];
                if (j == 256) {
                	write(1, result, 256, 0, 0);
                	j = 0;
                }
            }
        }
    }
    va_end(ap);

    write(1, result, j % 256, 0, 0);

}