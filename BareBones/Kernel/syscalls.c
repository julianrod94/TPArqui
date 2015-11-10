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

	uint32_t i = 0;
	char c;
	
	while (i < size) {
		c = getCharFromKbd();
		if (c != -1){
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
	
	uint32_t i = 0;
	char c;
	while (i < size ) {
		c = getCharFromKbd();
		if (c != -1){
			buffer[i++] = c;
			ncPrintChar(c);
		}
	}
	
	return;
}

static void readIfThereWasAKbdInt(uint64_t * result) {
	

	result[0] = (uint64_t)checkKbdInterrupt();
	return;
}


static void readNote(uint16_t * result) {
	
	uint16_t note;
	do {
		note = getNoteFromKbd();
	} while (note == -1);
	result[0] = note;
	return;
}



/* Read Ticks:
 * Read syscall by using timer as file descriptor
 * and 1 as aux arg 1
 */
static void readTicksfromTimer(uint64_t * result) {

	result[0] = getTicks();
	return;
}

/* Read Frequency:
 * Read syscall by using timer as file descriptor
 * and 2 as aux arg 1
 */
static void readFreqfromTimer(uint64_t * result) {

	result[0] = getFrequency();
	return;
}


/* Read Current Video Position:
 * Read syscall by using video as file descriptor
 * and 2 as aux arg 1
 */
static void readCurrentVideo(uint8_t ** buffer) {

	buffer[0] = (uint8_t *) getCurrentVideo();
	return;
}


static void printInVideo(uint8_t * buffer, uint64_t size) {

	uint32_t i = 0;

	while (i < size) {
		uint8_t c = buffer[i++];
		ncPrintChar(c);
	}
	return;
}

static void clear(void){
	ncClear();
}


static void printInSpk(uint16_t freq) {
	
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
				case 3:
					readNote((uint16_t *) buffer);
					break;
				case 4:
					readIfThereWasAKbdInt( (uint64_t *) buffer);
					break;
			}
			break;
	
		case STDOUT:
			switch (aux1) {
				case 1:
					readCurrentVideo((uint8_t **) buffer);
					break;
			}
			break;
		case TIMER:
			switch (aux1) {
				case 1: 
					readTicksfromTimer((uint64_t *) buffer);
					break;
				case 2:
					readFreqfromTimer((uint64_t *) buffer);
					break;
			}		
			break;
	}
	return;
}


void write(uint64_t fileDescriptor, uint64_t buffer, uint64_t size, uint64_t aux1, uint64_t aux2) {

	switch (fileDescriptor) {

		case STDOUT:
			printInVideo((uint8_t *) buffer, size);
			break;
		case SPK:
			printInSpk( (uint16_t) (((uint16_t *)buffer)[0]));
			break;
		case CLEAR:
			clear();
			break;
	}
	return;

}





