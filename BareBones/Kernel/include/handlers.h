#ifndef HANDLERS_H
#define HANDLERS_H
#include <types.h>
#define READ 0
#define WRITE 1
#define SOUND 2

void picMasterMask(); 
void picSlaveMask();
void irqDispatcher(dword irq, dword syscall);
void int08();
void int09();

void handler(uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t);


#endif
