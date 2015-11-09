#include <timer.h>
#include <stdint.h>


static uint64_t ticks = 0;
static uint64_t fq = 18.222;

void timerISR(void) {
	ticks++;
}

uint64_t getTicks(void) {
	return ticks;
}

uint64_t getFrequency(void) {
	return fq;
}