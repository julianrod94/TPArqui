#include "syscallwrappers.h"

uint16_t getNote() {

	uint16_t note;
	read(STDIN, &note, 1, 1, 1);
	if (note > 128) {
		note = 0;	
	}
	return note; 
	
}


void playNote(uint16_t note) {
	
	write(SPK, &note, 0, 0, 0);
}