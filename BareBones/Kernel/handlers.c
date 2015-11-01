#include <types.h>
#include <naiveConsole.h>
#include <interrupts.h>
#include <handlers.h>
#include <keyboard.h>


void irqDispatcher(dword irq, dword syscall){	
	switch(irq) {
		case 0:
			int08();
			break;
		case 1:
			int09();
			break;
	}
	return;
}


void int08(){
}

void int09(){
	myKeyboard();
}

