//RGB.c
#include "sc32_conf.h"
#include "stdio.h"
#include "HeadFiles\SC_itExtern.h"
#include "SCDriver_List.h"
#include "Key.h"

void RGB_SET(int R,int G,int B)
{
        PWM_SetDuty(PWM0,PWM_Channel_1,B);
        PWM_SetDuty(PWM0,PWM_Channel_2,G);
        PWM_SetDuty(PWM0,PWM_Channel_3,R);	
}

int RGB_mode=0;

void RGB_mode0(void)//常亮为黄光
{
	RGB_SET(200,500,800);
}

void RGB_mode1(void)//常亮为黄绿光
{
	RGB_SET(0,0,900);
}

void RGB_mode2(void)//常亮为白（少蓝）光
{
	//RGB_SET(300,500,700);
//	RGB_SET(500,500,500);//蓝
	RGB_SET(0,900,0);//更蓝
}
int RGB_Flag=0;
extern int KeyNum;
void RGB_mode3(void)
{
	if(RGB_Flag==0)
	{
		RGB_SET(200,500,800);
	}
	if(RGB_Flag==1)
	{
		RGB_SET(100,500,900);
	}
		if(RGB_Flag==2)
	{
		RGB_SET(300,500,700);
	}
		if(RGB_Flag==3)
	{
		RGB_SET(500,500,500);
	}
		if(RGB_Flag==4)
	{
		RGB_SET(800,500,300);
	}
	
}

void RGB_choosemode(void)//选择模式
{	
	PWM_Cmd(PWM0,ENABLE);

	if(RGB_mode==0)
	{
		RGB_mode0();
	}
	else if(RGB_mode==1)
	{
		RGB_mode1();
	}
		else if(RGB_mode==2)
	{
		RGB_mode2();
	}
		else 
	{
		RGB_mode3();
	}
	RGB_mode%=4;
}

void RGB_off(void)
{
	PWM_Cmd(PWM0,DISABLE);
}
