#include "syscallHandler.h"
#define READ 0
#define WRITE 1

uint64_t syscallHandler(uint64_t syscallId, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6){
	switch (syscallId){
		case READ:
			break;
		case WRITE:
			break;
	}
	return 42;
}
