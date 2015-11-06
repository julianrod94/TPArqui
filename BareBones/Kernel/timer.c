#include <timer.h>



static long ticks = 0;

void tick() {
	ticks++;
}

long getTicks(void) {
	return ticks;
}