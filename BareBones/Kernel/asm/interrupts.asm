GLOBAL _cli
GLOBAL _sti
GLOBAL _hlt
GLOBAL picMasterMask
GLOBAL picSlaveMask


GLOBAL _irq00Handler
GLOBAL _irq01Handler
GLOBAL _irq02Handler
GLOBAL _irq03Handler
GLOBAL _irq04Handler
GLOBAL _irq05Handler
GLOBAL portRead
GLOBAL syscallHandler
GLOBAL shutdown


EXTERN irqDispatcher
EXTERN readLineWrapper
EXTERN handler


%macro pushaq 0
    push rax      ;save current rax
    push rbx      ;save current rbx
    push rcx      ;save current rcx
    push rdx      ;save current rdx
    push rbp      ;save current rbp
    push rdi       ;save current rdi
    push rsi       ;save current rsi
    push r8        ;save current r8
    push r9        ;save current r9
    push r10      ;save current r10
    push r11      ;save current r11
    push r12      ;save current r12
    push r13      ;save current r13
    push r14      ;save current r14
    push r15      ;save current r15
%endmacro



%macro popaq 0
        pop r15
        pop r14
        pop r13
        pop r12
        pop r11
        pop r10
        pop r9
        pop r8
        pop rsi
        pop rdi
        pop rbp
        pop rdx
        pop rcx
        pop rbx
        pop rax
%endmacro




%macro irqHandlerMaster 1
	
	pushaq
	mov rdi, %1
	call irqDispatcher
	
	;signal pic
	mov al, 20h
	out 20h, al

	popaq

	iretq
%endmacro


_cli:
	cli
	ret


_sti:
	sti
	ret

_hlt:
    hlt
    ret

picMasterMask:
	mov rax, rdi
	out	0x21, al
	ret
    

picSlaveMask:
	mov rax, rdi  ; ax = mascara de 16 bits
   	out	0xA1,al
    ret

;8254 Timer (Timer Tick)
_irq00Handler:
	irqHandlerMaster 0
	
;Keyboard
_irq01Handler:
	irqHandlerMaster 1

;Cascade pic never called
_irq02Handler:
	irqHandlerMaster 2

;Serial Port 2 and 4
_irq03Handler:
	irqHandlerMaster 3
	
;Serial Port 1 and 3	
_irq04Handler:
	irqHandlerMaster 4
	
;USB
_irq05Handler:
	irqHandlerMaster 5


portRead:
	mov rdx, 0x60
	xor rax, rax
	in al, dx
	ret

syscallHandler:
	sti
	pushaq
    	call handler
	popaq   
	iretq

shutdown:
	cli
	hlt

