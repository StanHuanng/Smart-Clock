//menu.c
#include "SC_Init.h"
#include "SC_it.h"
#include "SysFunVarDefine.h"

#include "Key.h"
#include "Buzzer.h"
 
int menu_state=5;
int menu_state0=0;
int menu_state1=0;
int menu_state2=0;
int snoozestate=1;

extern int music;
extern int sec,min,hour,day,month,year;

/****主菜单****/
int menu_main(void)
{


OLED_ShowString(2,3,"Clock");
OLED_ShowString(3,3,"Music");
OLED_ShowString(4,3,"Settings");

int menu_flag=1;
int key;

while(1)
{
OLED_ShowNum(1, 5, hour, 2);//当前时间
OLED_ShowString(1, 7, ":");
OLED_ShowNum(1, 8, min, 2);
OLED_ShowString(1, 10, ":");
OLED_ShowNum(1, 11, sec, 2);

	key=Key_GetState();
	OLED_clock();

	//返回键
	if(key==3)
	{
		menu_state=5;
		menu_state0=0;	
		OLED_Clear();
		return 5;
	}
	//向下键
	if(key==1)
	{
		menu_flag++;
		if(menu_flag==4)menu_flag=1;
	}
	//确认键
	if(key==2)
	{
	OLED_Clear();
	return menu_flag;
	}
	
	switch(menu_flag)
	{
		case 1:
		{
		OLED_ShowString(2,1,"*");
		OLED_ShowString(3,1," ");
		OLED_ShowString(4,1," ");
		}break;
		case 2:
		{
		OLED_ShowString(2,1," ");
		OLED_ShowString(3,1,"*");
		OLED_ShowString(4,1," ");
		}break;
		case 3:
		{
		OLED_ShowString(2,1," ");
		OLED_ShowString(3,1," ");
		OLED_ShowString(4,1,"*");
		}break;
		
	}
}
}
/****主菜单****/

/****一级菜单****/
int menu_clock(void)
{
int key;
int menu_flag1=1;

OLED_ShowString(2,3,"SetTime");
OLED_ShowString(3,3,"SnnozeFunction");
OLED_ShowString(4,3,"SetAlarmClock");
while(1){
OLED_ShowNum(1, 5, hour, 2);//当前时间
OLED_ShowString(1, 7, ":");
OLED_ShowNum(1, 8, min, 2);
OLED_ShowString(1, 10, ":");
OLED_ShowNum(1, 11, sec, 2);
	key=Key_GetState();
	OLED_clock();
	if(key==3)
	//返回键
	{
		OLED_Clear();
		menu_state=0;
		return 0;
	}

//向下键
	if(key==1)
	{
		menu_flag1++;
		if(menu_flag1==4)menu_flag1=1;
	}
//确认键
	if(key==2)
	{
	OLED_Clear();
	menu_state=5;
	return menu_flag1;
	}
	switch(menu_flag1)
	{
		case 1:
		{
		OLED_ShowString(2,1,"*");
		OLED_ShowString(3,1," ");
		OLED_ShowString(4,1," ");
		}break;
		case 2:
		{
		OLED_ShowString(2,1," ");
		OLED_ShowString(3,1,"*");
		OLED_ShowString(4,1," ");
		}break;
		case 3:
		{
		OLED_ShowString(2,1," ");
		OLED_ShowString(3,1," ");
		OLED_ShowString(4,1,"*");
		}break;
	}
	}
}

int menu_music(void)
{
int key;
int menu_flag2=1;

OLED_ShowString(2,3,"TongHua");
OLED_ShowString(3,3,"Canon");
OLED_ShowString(4,3,"Summer");
while(1){
OLED_ShowNum(1, 5, hour, 2);//当前时间
OLED_ShowString(1, 7, ":");
OLED_ShowNum(1, 8, min, 2);
OLED_ShowString(1, 10, ":");
OLED_ShowNum(1, 11, sec, 2);
	key=Key_GetState();
	OLED_clock();
	if(key==3)
	//返回键
	{
		OLED_Clear();
		menu_state=0;
		return 0;
	}

//向下键
	if(key==1)
	{
		menu_flag2++;
		if(menu_flag2==4)menu_flag2=1;
	}
//确认键
	if(key==2&&menu_flag2==1)
	{
	music=0;
	OLED_Clear();
	music_play();
	}
	if(key==2&&menu_flag2==2)
	{
	music=1;
	OLED_Clear();
	music_play();
	}
	if(key==2&&menu_flag2==3)
	{
	music=2;
	OLED_Clear();
	music_play();
	}
	switch(menu_flag2)
	{
		case 1:
		{
		OLED_ShowString(2,1,"*");
		OLED_ShowString(3,1," ");
		OLED_ShowString(4,1," ");
		}break;
		case 2:
		{
		OLED_ShowString(2,1," ");
		OLED_ShowString(3,1,"*");
		OLED_ShowString(4,1," ");
		}break;
		case 3:
		{
		OLED_ShowString(2,1," ");
		OLED_ShowString(3,1," ");
		OLED_ShowString(4,1,"*");
		}break;
	}
	}

}
int menu_setting(void)
{
int key;
int menu_flag3=1;

OLED_ShowString(2,3,"RGBsetting");
OLED_ShowString(3,3,"Vibrate");
OLED_ShowString(4,3,"AutoContrast");
while(1){
OLED_ShowNum(1, 5, hour, 2);//当前时间
OLED_ShowString(1, 7, ":");
OLED_ShowNum(1, 8, min, 2);
OLED_ShowString(1, 10, ":");
OLED_ShowNum(1, 11, sec, 2);
	key=Key_GetState();
	OLED_clock();
//返回键	
	if(key==3)
	{
		OLED_Clear();
		menu_state=0;
		return 0;
	}

//向下键
	if(key==1)
	{
		menu_flag3++;
		if(menu_flag3==4)menu_flag3=1;
	}
//确认键
	if(key==2)
	{
	OLED_Clear();
	
	return menu_flag3;	
	}
	switch(menu_flag3)
	{
		case 1:
		{
		OLED_ShowString(2,1,"*");
		OLED_ShowString(3,1," ");
		OLED_ShowString(4,1," ");
		}break;
		case 2:
		{
		OLED_ShowString(2,1," ");
		OLED_ShowString(3,1,"*");
		OLED_ShowString(4,1," ");
		}break;
		case 3:
		{
		OLED_ShowString(2,1," ");
		OLED_ShowString(3,1," ");
		OLED_ShowString(4,1,"*");
		}break;
	}
	}

}
/****一级菜单****/

/****二级菜单****/
int menu_SetTime(void)
{
int menu_flag5=1;
int key;


OLED_ShowString(1,3,"Settime");

OLED_ShowString(2,3,"+");
OLED_ShowString(2,4,"+");
OLED_ShowString(2,5,"+");
while(1)
{
OLED_ShowNum(2,4,hour,2);
OLED_ShowNum(3,4,min,2);
OLED_ShowNum(4,4,sec,2);

	key=Key_GetState();
	OLED_clock();
	//返回键	
	if(key==3)
	{
		OLED_Clear();
		menu_state=1;
		return 0;
	}
	//向下键
	if(key==1)
	{
		menu_flag5++;
		if(menu_flag5==4)menu_flag5=1;
	}
	//确认键
	if(key==2&&menu_flag5==1)
	{
	hour++;
	
	}
	if(key==2&&menu_flag5==2)
	{
	min++;

	}
	if(key==2&&menu_flag5==3)
	{
	sec++;
	
	}
	switch(menu_flag5)
	{
		case 1:
		{
		OLED_ShowString(2,1,"*");
		OLED_ShowString(3,1," ");
		OLED_ShowString(4,1," ");
		}break;
		case 2:
		{
		OLED_ShowString(2,1," ");
		OLED_ShowString(3,1,"*");
		OLED_ShowString(4,1," ");
		}break;
		case 3:
		{
		OLED_ShowString(2,1," ");
		OLED_ShowString(3,1," ");
		OLED_ShowString(4,1,"*");
		}break;
		
	}
}



}

int menu_Snooze(void)
{
int menu_flag6=1;
int key;


OLED_ShowString(1,3,"Snooze:");
OLED_ShowString(2,3,"ON");
OLED_ShowString(3,3,"OFF");


while(1)
{
	if(snoozestate==1){OLED_ShowString(1,10,"ON");}
	if(snoozestate==0){OLED_ShowString(1,10,"OFF");}
	
	key=Key_GetState();

	//返回键	
	if(key==3)
	{
		OLED_Clear();
		menu_state=1;
		return 0;
	}
	//向下键
	if(key==1)
	{
		menu_flag6++;
		if(menu_flag6==4)menu_flag6=1;
	}
	//确认键
	if(key==2&&menu_flag6==1)
	{
	snoozestate=1;
	
	}
	if(key==2&&menu_flag6==2)
	{
	snoozestate=0;
	}

	switch(menu_flag6)
	{
		case 1:
		{
		OLED_ShowString(2,1,"*");
		OLED_ShowString(3,1," ");
		OLED_ShowString(4,1," ");
		}break;
		case 2:
		{
		OLED_ShowString(2,1," ");
		OLED_ShowString(3,1,"*");
		OLED_ShowString(4,1," ");
		}break;
		
	}
}



}
int menu_rgb(void)
{
OLED_ShowNum(1, 5, hour, 2);//当前时间
OLED_ShowString(1, 7, ":");
OLED_ShowNum(1, 8, min, 2);
OLED_ShowString(1, 10, ":");	
OLED_ShowNum(1, 11, sec, 2);
OLED_ShowString(2,3,"Yellow");
OLED_ShowString(3,3,"Green");
OLED_ShowString(4,3,"Purple");

int menu_flag4=1;
int key;

while(1)
{
	key=Key_GetState();
	OLED_clock();
	//向下键
	if(key==1)
	{
		menu_flag4++;
		if(menu_flag4==4)menu_flag4=1;
	}
	//确认键
	if(key==2)
	{
	OLED_Clear();
	return menu_flag4;
	}
	
	switch(menu_flag4)
	{
		case 1:
		{
		OLED_ShowString(2,1,"*");
		OLED_ShowString(3,1," ");
		OLED_ShowString(4,1," ");
		}break;
		case 2:
		{
		OLED_ShowString(2,1," ");
		OLED_ShowString(3,1,"*");
		OLED_ShowString(4,1," ");
		}break;
		case 3:
		{
		OLED_ShowString(2,1," ");
		OLED_ShowString(3,1," ");
		OLED_ShowString(4,1,"*");
		}break;
		
	}
}
}
/****二级菜单****/