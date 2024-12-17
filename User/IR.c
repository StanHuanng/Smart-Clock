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
		GPIO_ResetBits(GPIOA,GPIO_Pin_12);//PA12Ϊcontrol�ڣ�����Ϊ��������������ñ���a=0��ر�
	}
		if (a==1)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_12);//PA12Ϊcontrol�ڣ�����Ϊ��������������ñ���a=1����
	}
	int b=GPIO_ReadDataBit(GPIOA,GPIO_Pin_11);//PA12Ϊ�����
	return b;//��⵽�����ʱ�򷵻�0 ����	
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
