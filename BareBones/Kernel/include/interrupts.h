#include <stdint.h>

#ifndef INTERRUPTS_H
#define INTERRUPTS_H

void _irq00Handler(void);
void _irq01Handler(void);

//Wrappers de sti, cli y hlt
void _cli(void);
void _sti(void);
void _hlt(void);

void setup_IDT_entry(uint16_t, uint16_t, uint64_t, uint8_t);

char portRead(void);
void shutdown(void);

#endif
