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
		return Temp;//当Key_Num（即上一状态）非0时，输出Key_Num并且让Key_Num置0
	}
	return 0;//当Key_Num==0时，输出0
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
	static int CurrState, PrevState;	//现在的按键状态和之前的按键状态
	
	Count ++;
	if (Count >= 20)
	{
		Count = 0;
		
		PrevState = CurrState;
		CurrState = Key_GetState();//当前状态，1和2对应两个按键，0表示没有按键按下
		
		if (CurrState == 0 && PrevState != 0)//当现在按键状态为0而之前状态非0
		{
			Key_Num = PrevState;
		}
	}
}
