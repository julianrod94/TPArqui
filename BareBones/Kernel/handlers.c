#include <types.h>
#include <naiveConsole.h>
#include <interrupts.h>
#include <handlers.h>
#include <keyboard.h>
#include <sound.h>

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
	int i = 0;
	/*turnOnSound(5423);
	while(i<10000000){
		i++;
	}
	turnOffSound();*/
	makeSound();
	//myKeyboard();
}

