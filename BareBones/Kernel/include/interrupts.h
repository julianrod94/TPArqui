#ifndef INTERRUPTS_H
#define INTERRUPTS_H

void _irq00Handler();
void _irq01Handler();

//Wrappers de sti y cli
void _cli();
void _sti();

void setup_IDT_entry(uint16_t, uint16_t, uint64_t, uint8_t);

#endif
