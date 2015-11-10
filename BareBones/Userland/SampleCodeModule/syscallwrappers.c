#include <stdint.h>

static uint64_t sysCaller(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6) {

	__asm__ ("int $0x80");
	return 0;
}


void read(uint64_t fileDescriptor, uint64_t buffer, uint64_t size, uint64_t aux1, uint64_t aux2) {


	sysCaller(0, fileDescriptor, buffer, size, aux1, aux2);

}



void write(uint64_t fileDescriptor, uint64_t buffer, uint64_t size, uint64_t aux1, uint64_t aux2) {

	sysCaller(1, fileDescriptor, buffer, size, aux1, aux2);
}
