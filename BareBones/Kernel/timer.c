#include <timer.h>



static long ticks = 0;

void timerISR(void) {
	ticks++;
}

long getTicks(void) {
	return ticks;
}