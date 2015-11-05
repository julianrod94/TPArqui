#include <stdint.h>
#include "asm.h"
#define TRUE 1
#define FALSE 0
#define READ 0
// #define READ 0
// extern uint64_t sysCaller(uint64_t syscallId, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6);
void scanf(char* buffer);
void inputInterpreter(char* message);
uint64_t stringCompare(char* str1, char* str2);