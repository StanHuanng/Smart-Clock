//Key.c
#include "SC_it.h"
#include "SC_Init.h"
#include "sc32_conf.h"
#include "stdio.h"
#include "HeadFiles\SC_itExtern.h"
#include "SCDriver_List.h"
int Key_Num=0;
int Key_GetNum(void)
{
	int Temp;
	if (Key_Num)
	{
		Temp = Key_Num;
		Key_Num = 0;
		return Temp;//��Key_Num������һ״̬����0ʱ�����Key_Num������Key_Num��0
	}
	return 0;//��Key_Num==0ʱ�����0
}

int Key_GetState(void)
{
	if (GPIO_ReadDataBit(GPIOC, GPIO_Pin_0) == 0)
	{
		return 1;
	}
	if (GPIO_ReadDataBit(GPIOB, GPIO_Pin_11) == 0)
	{
		return 2;
	}
	if (GPIO_ReadDataBit(GPIOB, GPIO_Pin_10) == 0)
	{
		return 3;
	}
	return 0;
}

void Key_Tick(void)
{
	static int Count;
	static int CurrState, PrevState;	//���ڵİ���״̬��֮ǰ�İ���״̬
	
	Count ++;
	if (Count >= 20)
	{
		Count = 0;
		
		PrevState = CurrState;
		CurrState = Key_GetState();//��ǰ״̬��1��2��Ӧ����������0��ʾû�а�������
		
		if (CurrState == 0 && PrevState != 0)//�����ڰ���״̬Ϊ0��֮ǰ״̬��0
		{
			Key_Num = PrevState;
		}
	}
}
