#include "syscallwrappers.h"
#include "math.h"


void sleep(long millisecods) {
	double fq;
	long tick, finalTick;
	read(TIMER, &fq, 1, 2, 0); /* Frequency might be changed during execution of kernel */
	
	read(TIMER, &tick, 1, 1, 0); /* Reads first tick */
	totalTicks = tick + (long)((double)millisecods * (fq/1000));
	while(tick < totalTicks) {
		totalTicks = tick + (long)((double)millisecods * (fq/1000));
	}

}