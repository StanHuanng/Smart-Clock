//OLED.h
#ifndef _OLED_H_
#define	_OLED_H_

#include "sc32_conf.h"
void OLED_WriteCommand(int Command);
void OLED_WriteData(uint8_t Data);
void OLED_SetCursor(int Y, int X);
void OLED_ShowChar(int Line, int Column, char Char);
void OLED_ShowString(int Line, int Column, char *String);
int OLED_Pow(int X, int Y);
void OLED_ShowNum(int Line, int Column, int Number, int Length);
int OLED_Showtime(void);

#endif
