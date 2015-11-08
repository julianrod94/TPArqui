#include <interrupts.h>
#include <syscalls.h>
#include <kbdLogic.h>
#include <naiveConsole.h>
#include <sound.h>
#include <timer.h>


static void readFromKbd(char * buffer, uint64_t size) {

	int i = 0;
	char c;
	
	while (i < size) {
		c = getCharFromKbd();
		if (c == -1){
			_hlt();
		} else {
			buffer[i++] = c;
		}
	}
	return;
}

static void readfromTimer(long * result) {

	result[0] = getTicks();
	return;
}


static void printInVideo(char * buffer, uint64_t size) {

	int i = 0;

	while (i < size) {
		char c = buffer[i++];
		if (c == '\n') {
			ncNewline();
		}else if('\b'){
			ncBackSpace();
		}else if('\t'){
			ncTab();
		}else {
			ncPrintChar(c);
		}
	}
	return;
}


static void printInSpk(unsigned short freq) {

	if (freq == 0) {
		turnOffSound();
	} else {
		turnOnSound(freq);
	}
	return;
}




void read(uint64_t fileDescriptor, uint64_t buffer, uint64_t size, uint64_t aux1, uint64_t aux2) {

	switch (fileDescriptor) {

		case STDIN:
			readFromKbd((char *) buffer, size);
			break;
		case TIMER:
			readfromTimer((long *) buffer);
			break;
		default:
			;
	}
	return;
}


void write(uint64_t fileDescriptor, uint64_t buffer, uint64_t size, uint64_t aux1, uint64_t aux2) {

	switch (fileDescriptor) {

		case STDOUT:
			printInVideo((char *) buffer, size);
			break;
		case SPK:
			printInSpk((unsigned short) aux1);
			break;
		default:
			;
	}
	return;

}




