#include <interrupts.h>
#include <syscalls.h>
#include <kbdLogic.h>
#include <naiveConsole.h>
#include <sound.h>
#include <timer.h>


/* Read from keyboard with no print
 * Read syscall by using keyboard (stdin) as file descriptor
 * and 1 as aux arg1
 */
static void readFromKbdNoPrint(char * buffer, uint64_t size) {

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


/* Read from keyboard with print
 * Read syscall by using keyboard (stdin) as file descriptor
 * and 2 as aux arg1
 */
static void readFromKbdPrint(char * buffer, uint64_t size) {

	int i = 0;
	char c;
	
	while (i < size) {
		c = getCharFromKbd();
		if (c == -1){
			_hlt();
		} else {
			buffer[i++] = c;
			ncPrintChar(c);
		}
	}
	return;
}



/* Read Ticks:
 * Read syscall by using timer as file descriptor
 * and 1 as aux arg 1
 */
static void readTicksfromTimer(long * result) {

	result[0] = getTicks();
	return;
}

/* Read Frequency:
 * Read syscall by using timer as file descriptor
 * and 2 as aux arg 1
 */
static void readFreqfromTimer(double * result) {

	result[0] = getFrequency();
	return;
}


/* Read Current Video Position:
 * Read syscall by using video as file descriptor
 * and 2 as aux arg 1
 */
static void readCurrentVideo(uint8_t * buffer) {

	buffer[0] = getCurrentVideo();
	return;
}


static void printInVideo(char * buffer, uint64_t size) {

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
			switch (aux1) {
				case 1:
					readFromKbdNoPrint((char *) buffer, size);
					break;
				case 2:
					readFromKbdPrint((char *) buffer, size);
					break;
			}
			break;
	
		case STDOUT:
			switch (aux1) {
				case 1:
					readCurrentVideo((uint8_t) buffer);
					break;
			}
			break;
		case TIMER:
			switch (aux1) {
				case 1: 
					readTicksfromTimer((long *) buffer);
					break;
				case 2:
					readFreqfromTimer((double *) buffer);
					break;
			}		
			break;
	}
	return;
}


void write(uint64_t fileDescriptor, uint64_t buffer, uint64_t size, uint64_t aux1, uint64_t aux2) {

	switch (fileDescriptor) {

		case STDOUT:
			printInVideo((char *) buffer, size);
			break;
		case SPK:
			printInSpk((unsigned short) (((uint16_t *)buffer)[0]);
			break;
		default:
			;
	}
	return;

}




