#ifndef HANDLERS_H
#define HANDLERS_H
#include <types.h>

void picMasterMask(); 
void picSlaveMask();
void irqDispatcher(dword irq, dword syscall);
void int08();
void int09();


#endif
