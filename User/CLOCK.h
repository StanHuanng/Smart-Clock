//CLOCK.h
#ifndef _CLOCK_H_
#define	_CLOCK_H_

#include "sc32_conf.h"

void OLED_clock(void);
void alarm_clock_set(int hour_set,int min_set,int sec_set);
void alarm_clock_start(void);
void snooze(void);
void Delay(unsigned int time);
#endif
