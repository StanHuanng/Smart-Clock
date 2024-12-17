//Motor.c
#include "sc32_conf.h"
#include "stdio.h"
#include "HeadFiles\SC_itExtern.h"
#include "SCDriver_List.h"

int motor_flag=1;

void motor_vibrate(void)
{
        PWM_SetDuty(PWM0,PWM_Channel_0,800);

}
