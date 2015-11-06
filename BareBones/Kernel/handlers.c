#include <types.h>
#include <naiveConsole.h>
#include <interrupts.h>
#include <handlers.h>
#include <keyboard.h>
#include <sound.h>
#include <timer.h>
#include <syscalls.h>



static void (*interrupts[2])(void);
static void (*syscalls[2]) (uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t);

interrupts[0] = int08
interrupts[1] = int09
syscalls[0] = read;
syscalls[1] = write;


void irqDispatcher(dword irq, dword syscall) {

	interrupts[irq]();
	return;
}


void int08(void){
	tick();
}

void int09(void){
	myKeyboard();
}



void handler(uint64_t syscallId, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6) {

	syscalls[syscallId](arg1, arg2, arg3, arg4, arg5, arg6);
	return;

}






