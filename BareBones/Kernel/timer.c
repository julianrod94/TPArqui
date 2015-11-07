#include <timer.h>



static long ticks = 0;

void tick(void) {
	ticks++;
}

long getTicks(void) {
	return ticks;
}