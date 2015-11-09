#include <stdint.h>

typedef struct {
	uint16_t note;
	long duration;
} tMusicNote;

void pianoPlay(void);

void automaticPlay(tMusicNote);
