#include <stdint.h>

#ifndef TYPES_H
#define TYPES_H

typedef unsigned char byte;
typedef short int word;
typedef int dword;

/*IDT_ENTRY*/
typedef struct IDT_entry{
  uint16_t offset_l;
  uint16_t selector;
  uint8_t zero;
  uint8_t type_attr;
  uint16_t offset_m;
  uint32_t offset_h;
  uint32_t zero2;
}IDT_entry;


/* IDTR  */
typedef struct {
  word  limit;
  dword base;
} IDTR;
#endif
