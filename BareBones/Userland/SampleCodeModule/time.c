#include "syscallwrappers.h"
#include "math.h"
#include "stdio.h"


void sleep(long millisecods) {
	uint64_t fq;
	uint64_t tick, finalTick;
	read(TIMER, (uint64_t)&fq, 1, 2, 0); /* Frequency might be changed during execution of kernel */
	
	read(TIMER, (uint64_t)&tick, 1, 1, 0); /* Reads initial tick */
	finalTick = tick + (long)((double)millisecods * ((double)fq/1000));
	while(tick < finalTick) {
		read(TIMER, (uint64_t)&tick, 1, 1, 0); /* Reads tick */
	}
	return;
}
