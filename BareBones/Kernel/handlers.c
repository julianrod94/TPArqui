#include <types.h>
#include <naiveConsole.h>
#include <interrupts.h>
#include <handlers.h>

static int ticks = 0;


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
	if(ticks % 10 == 0){
		ncPrint("tick");
	}
	ticks++;
}

void int09(){
	ncPrintDec(portRead());
}