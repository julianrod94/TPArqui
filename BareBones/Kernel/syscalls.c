#include <syscalls.h>
#include <types.h>
#include <keyboard.h>
#include <naiveConsole.h>
#include <sound.h>
#include <timer.h>

/* 	FILE DESCRIPTORS:
 *	
 *	0: STD INPUT (Keyboard)
 *  1: STD OUTPUT (Video)
 *  2: SPEAKER
 *  3: TIMER TICK
 *
 */



void read(uint64_t fileDescriptor, uint64_t buffer, uint64_t size, uint64_t arg4, uint64_t arg5, uint64_t arg6) {

	switch fileDescriptor {

		case STDIN:
			readFromKbd((char *) buffer, (size_t)size);
			break;
		case TIMER:
			readfromTimer((long *) buffer);
			break;
		default:
	}
	return;
}


void write(uint64_t fileDescriptor, uint64_t buffer, uint64_t size, uint64_t aux1, uint64_t arg5, uint64_t arg6) {

	switch fileDescriptor {

		case STDOUT:
			printInVideo((char *) buffer, (size_t)size);
			break;
		case SPK:
			printInSpk((unsigned short) aux1);
			break;
		default:
	}
	return;

}



void readFromKbd(char * buffer, size_t size) {

	int i = 0;
	while (i < size) {
		buffer[i++] = readChar();
	}
	return;
}

void readfromTimer(long * result) {

	result[0] = getTicks();
	return;
}


void printInVideo(char * buffer, size_t size) {

	int i = 0;

	while (i < size) {
		char c = buffer[i++];
		if (c == '\n') {
			ncNewline();
		} else {
			ncPrintChar(c);
		}
	}
	return;
}


void printInSpk(unsigned short freq) {

	if (freq == 0) {
		turnOffSound();
	} else {
		turnOnSound(freq);
	}
	return;
}






