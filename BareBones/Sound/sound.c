include "sound.h"

void soundHandler(uint64_t mode, uint64_t frequency) {

	if (mode == 0) {

		if (frequency < 0 || frequency > 65535) {
			return;
		}
		turnOnSound(frequency);
	}
	else {
		turnOffSound();
	}
}