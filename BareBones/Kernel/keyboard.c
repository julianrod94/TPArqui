#include <types.h>
#include <interrupts.h>
#include <handlers.h>
#include <stdint.h>
#include <naiveConsole.h>

#define SIZE 256

static uint64_t buffer[SIZE];
static uint8_t bufferSize = 0;
static int enqueueIdx = 0;
static int dequeueIdx = 0;


static int numLock = 1;     /* num lock is on by default */
static int capsLock = 0;    /* caps lock is off by default */
static int shift = 0;

void keyboardISR(void) {

	uint8_t scanCode;

    if (bufferSize == SIZE) {
        return; // If the buffer is full, nothing should be saved
    }
	scanCode = portRead();
	
	if (scanCode == 42 || scanCode == 54) {	
		shift += scanCode;

	} else if (scanCode == 170 || scanCode == 182) {
		shift -= (scanCode - 128);

	} else if (scanCode == 58) {
		capsLock = !capsLock;
	} else if (scanCode == 69) {
        numLock = !numLock;
    }

    buffer[enqueueIdx++] = scanCode;
    bufferSize++;
    if (enqueueIdx == SIZE) {
        enqueueIdx = 0;
    }
}


uint64_t dequeueKey(void) {
    if (bufferSize == 0) {
        return -1;
    }
	
    uint64_t result = buffer[dequeueIdx++];
    bufferSize--;
    if (dequeueIdx == SIZE) {
        dequeueIdx = 0;
    }
    return result;
}

uint8_t peekKey(void) {
	
	
	if (bufferSize == 0) {
		return -1; 
	}
	return buffer[dequeueIdx];
}

int isShifted(void) {
	
	return shift;
}

int isCapsLockOn(void) {

	return capsLock;
}

int isNumLockOn(void) {

	return numLock;
}


