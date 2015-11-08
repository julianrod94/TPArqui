#ifndef KEYBOARD_H
#define KEYBOARD_H

uint64_t dequeueKey(void);

void myKeyboard();
uint64_t isAlpha(char);
uint64_t isNum(char);
uint64_t isMayus(uint64_t);
uint64_t shifted();
char readChar(void);

#endif
