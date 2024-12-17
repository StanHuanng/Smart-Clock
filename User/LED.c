//LED.c
#include "SC_it.h"
#include "SC_Init.h"
#include "sc32_conf.h"
#include "stdio.h"
#include "HeadFiles\SC_itExtern.h"
#include "SCDriver_List.h"

void LED1_ON(void)
{
	PC_BIT(10) = 0;	
}
void LED1_OFF(void)
{
	PC_BIT(10) = 1;	
}

void LED2_ON(void)
{
	PC_BIT(5) = 0;	
}
void LED2_OFF(void)
{
	PC_BIT(5) = 1;	
}

void LED3_ON(void)
{
	PC_BIT(4) = 0;	
}
void LED3_OFF(void)
{
	PC_BIT(4) = 1;	
}
void LED4_ON(void)
{
	PC_BIT(11) = 0;	
}
void LED4_OFF(void)
{
	PC_BIT(11) = 1;	
}
void LED5_ON(void)
{
	PA_BIT(7)  = 0;	
}
void LED5_OFF(void)
{
	PA_BIT(7)  = 1;	
}
void LED6_ON(void)
{
	PA_BIT(8) = 0;	
}
void LED6_OFF(void)
{
	PA_BIT(8) = 1;	
}
