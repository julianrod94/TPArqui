#ifndef INTERRUPTS_H
#define INTERRUPTS_H

void _irq00Handler();
void _irq01Handler();

//Wrappers de sti, cli y hlt
void _cli();
void _sti();
void _htl();

void setup_IDT_entry(uint16_t, uint16_t, uint64_t, uint8_t);

char portRead();

#endif
