//Buzzer.h

#ifndef _BUZZER_H_
#define	_BUZZER_H_

#include "sc32_conf.h"

void Buzzer_ON(void);
void Buzzer_OFF(void);
void Sound_SetHZ(int a);
void play_note(int a,int b);
void choose_music(void);
void music_play(void);

#endif
