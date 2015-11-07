#include "syscallwrappers.h"
#include "syscaller.h"


void read(uint64_t fileDescriptor, uint64_t buffer, uint64_t size, uint64_t aux1, uint64_t aux2, uint64_t aux3) {


	sysCaller(0, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t);

}



void write(uint64_t fileDescriptor, uint64_t buffer, uint64_t size, uint64_t aux1, uint64_t aux2, uint64_t aux3) {


}