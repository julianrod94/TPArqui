#include <timer.h>



static long ticks = 0;
static double fq = 18.222;

void timerISR(void) {
	ticks++;
}

long getTicks(void) {
	return ticks;
}

long getFrequency() {
	return fq;
}