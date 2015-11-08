#include <types.h>
#include <interrupts.h>
#include <handlers.h>

#define SIZE 256

/*typedef struct {
	char buffer[SIZE];
	int size;
} tKbdQueue;

static int kbdInit = 0;
static tKbdQueue kbdQueue;

tKbdQueue newKbdQueue() {

}*/

static uint64_t buffer[SIZE];
static int bufferSize = 0;
static int enqueueIdx = 0;
static int dequeueIdx = 0;

void keyboardISR(void) {

	if (bufferSize == SIZE) {
		return; // If the buffer is full, nothing should be saved
	}
	buffer[enqueueIdx++] = portRead();
	bufferSize++;
	if (enqueueIdx == SIZE) {
		enqueueIdx = 0;
	}
}


uint64_t dequeueKey(void) {

	if (bufferSize == 0) {
		return -1; // maybe we could just halt the machine
	}
	uint64_t result = buffer[dequeueIdx++];
	bufferSize--;
	if (dequeueIdx == SIZE) {
		dequeueIdx = 0;
	}
	return result;
}





