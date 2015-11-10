#include "syscallwrappers.h"
#include "time.h"
#include "music.h"



static uint16_t getNote() {

	uint16_t note;
	read(STDIN, (uint64_t)&note, 1, 3, 0);
	return note; 
	
}


static void playNote(uint16_t note) {
	write(SPK, (uint64_t)&note, 0, 0, 0);
}



void pianoPlay(void) {

	uint16_t note;
	while(1) {

		note = getNote();

		if (note == 1) {
			break;
		}
		playNote(note);
		sleep(56); /* minimum sleep time */
	}

}

void automaticPlay(tMusicNote musicNote) {
	
	uint16_t note = musicNote.note;
	long duration = musicNote.duration;
	playNote(note);
	sleep(duration);
	playNote(0);
}


