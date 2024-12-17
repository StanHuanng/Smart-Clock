//CLOCK.c

#include "SC_it.h"
#include "SC_Init.h"
#include "sc32_conf.h"
#include "stdio.h"
#include "HeadFiles\SC_itExtern.h"
#include "SCDriver_List.h"
#include "OLED.h"
#include "Buzzer.h"
#include "Motor.h"


int year=2024;
int month=12;
int day=13;
int hour=10;
int min=30;
int sec=0;

extern int menu_state;
extern int menu_state0;
extern int menu_state1;
extern int menu_state2;
extern int snoozestate;

void OLED_clock(void)
{

    if (sec >= 60) {
        sec = 0;
        min++;
    }
    
    if (min >= 60) {
        min = 0;
        hour++;
    }
    
    if (hour >= 24) {
        hour = 0;
        day++;
    }
    
    // �����º��յ����
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day > 31) {
            day = 1;
            month++;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            day = 1;
            month++;
        }
    } else if (month == 2) {
        // ��������
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (day > 29) {
                day = 1;
                month++;
            }
        } else {
            // ƽ��2��
            if (day > 28) {
                day = 1;
                month++;
            }
        }
    }

    // ����·ݴ���12�����1�������������
    if (month > 12) 
		{
        month = 1;
        year++;
    }
		
}

int hour_set=10;
int min_set=30;
int sec_set=20;
void alarm_clock_set(int newhour_set,int newmin_set,int newsec_set)
{
	hour_set=newhour_set;
	min_set=newmin_set;
	sec_set=newsec_set;
	
}

extern int a ;
void alarm_clock_start(void)//���趨ʱ��͵�ǰʱ��һ����ʱ������
{
int key;
key=Key_GetState();
	if(hour_set==hour && min_set == min)
	{
		OLED_Clear();
		OLED_ShowString(3,4,"Clock!");
		Buzzer_ON();
		motor_vibrate();
		music_play();
	int menu_state=5;
	int menu_state0=5;
	int menu_state1=0;
	int menu_state2=0;	
	}
	if(snoozestate == 1 && (key == 1 || key == 2 || key == 3))
	{
	 Buzzer_OFF();
     min_set+=5;  
     if (min_set >= 60) 
	{
     min_set -= 60;
     hour_set++;//Ŀǰ���ӳ���60 Сʱ�������1
  }
     hour_set %= 24;
	}
}
extern int KeyNum;
void snooze(void)//̰˯���ܣ��������º�����Ӻ�������
{    
        Buzzer_OFF();
        min_set+=5;  
     if (min_set >= 60) 
	{
     min_set -= 60;
     hour_set++;//Ŀǰ���ӳ���60 Сʱ�������1
  }
     hour_set %= 24;
}

////��ʱ����
void Delay(unsigned int time)
{
    
    unsigned int i=0;
    unsigned int j=0;
    for(i=0; i<100; i++)
        for(;time>0;time--)
            for(j=0; j<100; j++)
            ;
    
}
