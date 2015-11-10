#include <types.h>
#include <interrupts.h>
#include <keyboard.h>
#include <timer.h>
#include <syscalls.h>



static void (*interrupts[2])(void);
static void (*syscalls[2]) (uint64_t, uint64_t, uint64_t, uint64_t, uint64_t);



static void int08(void){
	timerISR();
}

static void int09(void){
	keyboardISR();
}


void irqDispatcher(dword irq, dword syscall) {
	
	interrupts[0] = int08;
	interrupts[1] = int09;

	interrupts[irq]();
	return;
}



void handler(uint64_t syscallId, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5) {

	syscalls[0] = read;
	syscalls[1] = write;
	syscalls[syscallId](arg1, arg2, arg3, arg4, arg5);
	return;

}






