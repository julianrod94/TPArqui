#include <Handler.h>
#define READ 0
#define WRITE 1
#define SOUND 2

uint64_t handler(uint64_t syscallId, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6){
	switch (syscallId){
		case READ:
			break;
		case WRITE:
			break;
		case SOUND:
			/*int i=0;
			turnOnSound(5423);
			while(i<10000000){
				i++;
			}
			turnOffSound();*/

			break;
	}
	return 42;
}
