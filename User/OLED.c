#include "SC_Init.h"
#include "SC_it.h"
#include "SysFunVarDefine.h"
#include "Key.h"

extern int sec,min,hour,day,month,year;
extern int hour_set,min_set,sec_set;
extern int menu_state0;
extern int menu_state;

int OLED_Showtime(void)
{
	OLED_ShowNum(1, 1, year, 4);//当前日期
	OLED_ShowString(1, 5, "/");
	OLED_ShowNum(1, 6, month, 2);	
	OLED_ShowString(1, 8, "/");	
	OLED_ShowNum(1, 9, day, 2);	
	
	OLED_ShowString(2, 1, "Now ");
	OLED_ShowNum(2, 5, hour, 2);//当前时间
	OLED_ShowString(2, 7, ":");
	OLED_ShowNum(2, 8, min, 2);
	OLED_ShowString(2, 10, ":");	
	OLED_ShowNum(2, 11, sec, 2);
	
	OLED_ShowString(3, 1, "Set ");
	OLED_ShowNum(3, 5, hour_set, 2);//设定闹钟时间
	OLED_ShowString(3, 7, ":");
	OLED_ShowNum(3, 8, min_set, 2);
	OLED_ShowString(3, 10, ":");	
	OLED_ShowNum(3, 11, sec_set, 2);	
	int key;
	key=Key_GetState();

	if(key==2)
	{
	OLED_Clear();
	menu_state0=1;
	menu_state=0;
	return 0;
	}
	

}
