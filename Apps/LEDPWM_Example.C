#include "LEDPWM_Example.h"

static volatile uint8_t LEDPWM_Flag = 0;//自定义LEDPWM标志位

void LEDPWM_Example(void)
{
  if(LEDPWM_Flag == 1)//自定义LEDPWM标志位置起
  {
    LEDPWM_Flag = 0;//自定义LEDPWM标志位清零
  }
}

void LEDPWM_Example_LEDPWMHandler(void)
{
  /* 判断LEDPWM中断是否置起 */
  if(LEDPWM_GetFlagStatus(LEDPWM_Flag_LEDPWMIF) == SET)//LEDPWM中断置起
  {
    LEDPWM_ClearFlag(LEDPWM_Flag_LEDPWMIF);//清除LEDPWM中断
    LEDPWM_Flag = 1;//自定义LEDPWM标志位置起
  }
}

