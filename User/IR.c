//IR.c
#include "SC_it.h"
#include "SC_Init.h"
#include "sc32_conf.h"
#include "stdio.h"
#include "HeadFiles\SC_itExtern.h"
#include "SCDriver_List.h"
#include "RGB.h"
int IR_output(int a)
{
	if (a==0)
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_12);//PA12为control口，设置为推挽输出，若设置变量a=0则关闭
	}
		if (a==1)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_12);//PA12为control口，设置为推挽输出，若设置变量a=1则开启
	}
	int b=GPIO_ReadDataBit(GPIOA,GPIO_Pin_11);//PA12为输入口
	return b;//检测到物体的时候返回0 灯亮	
}

void RGB_ctrl(int a)
{
	if (a==1)
	{
	 RGB_off();
	}
	if(a==0)
	{
		RGB_choosemode();
	}
}
