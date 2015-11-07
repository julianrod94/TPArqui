
int ipow(int base, int exp) {
    
    int result = 1;
    while (exp) {
        if (exp & 1) {
            result *= base;
        }
        exp >>= 1;
        base *= base;
    }
    
    return result;
}


int digits(int number) {

	int digits = 0;
	do {
        number /= 10;
        digits++;
    }
	while (number != 0);
	
	return digits;
}