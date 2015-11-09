#include "syscallwrappers.h"

uint16_t getNote() {

	uint16_t note;
	read(STDIN, (uint64_t)&note, 1, 3, 0);
	if (note > 128) {
		note = 0;	
	}
	return note; 
	
}


void playNote(uint16_t note) {
	
	write(SPK, (uint64_t)&note, 0, 0, 0);
}
