#include "syscallwrappers.h"
#include "syscaller.h"


void read(uint64_t fileDescriptor, uint64_t buffer, uint64_t size, uint64_t aux1, uint64_t aux2) {


	sysCaller(0, fileDescriptor, buffer, size, aux1, aux2);

}



void write(uint64_t fileDescriptor, uint64_t buffer, uint64_t size, uint64_t aux1, uint64_t aux2) {


}