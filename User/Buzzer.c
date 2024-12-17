//Buzzer.c
#include "SC_it.h"
#include "SC_Init.h"
#include "sc32_conf.h"
#include "stdio.h"
#include "HeadFiles\SC_itExtern.h"
#include "SCDriver_List.h"
void Buzzer_ON(void)
{
	TIM_Cmd(TIM2,ENABLE);
}
void Buzzer_OFF(void)
{
	TIM_Cmd(TIM2,DISABLE);
}

int tonghua_f[51]={  //童话的频率（音调）
	30,1836,917,1031,   1092,1092,1031,1092,   1092,1031,   1091,1031,1091,1226,1376, //我愿变  成童话里 你爱 的那个天使15
	1376,1092,917,      817,817,817,            917,1226,1226,1031,1092,30   ,           //张开双  手变成   翅膀守护你27
	30,	1376,1092,917,  817,817,817, 917,      1226,1226,1031,    1092, 1031,1092,1226,1376,//你要相 信相信我 们会像 童话故事里43
	1226,1092,       1635,1635,1376,    1376,1456,1376//幸福 和快乐 是结 局51
};

int tonghua_t[51]={
	50,50,50,50,    100,50,25,125 ,   50,50,   50,50,50,25,125,//我愿变  成童话里 你爱 的那个天使
	50,50,50,    100,50,50,    50,50,50,25,   125,100, //张开双  手变成   翅膀守护你
	50, 50,50,50,  100,50,25,75,   50,50,50,   50,50,50,25,125 ,
	50,50,  100,50,50,  100,100, 400
};

int jucilang_f[66]={ 
	917,687,612,545,  612,687,687,   30,917,687,612,545,  612,687,612,545, 545 ,  //17
	917,687,612,545,  612,687,687,   30,917,687,612,545,  612,687,612,545, 545,545,514,//36
	458,458,458,458,  458,545,687, 30,545,514,   458,458,458,458,   458,545,687,//53
	30,687,612,  				45,545,545,545,  545,408,612,545,687,  612//66
};

int jucilang_t[66]={
	25,25,25,25,  50,25,125,   100,25,25,25,25, 50,25,75,50,100,
	25,25,25,25,  50,25,125,   100,25,25,25,25, 50,25,75,50, 100,50,50,
	50,25,75,50,  50,25,50,  50,25,25,      50,25,75,50,   50,25,25,
	50,25,25,    50,25,75,50,   50,50,25,25,50, 100
};

int canon_f[112]={ 
	458,545,514,  	458,545,514,   	  458,917,817,728,     	687,612,545,514,  //14
	545,687,612,  	545,1092,1031,  	917,817,917,1031,    	917,1092,1031,917,//28
	1031,817,917, 	1031,1092,1226, 	1092,1226,1376,1226, 	1092,1031,917,817,//
	1031,817,917, 	817,728,687, 				917,817,728,687, 		612,545,514,458,
	545,687,612, 		545,612,687, 			612,728,687,612, 		 	545,612,687,728,
	687,817,728, 		687,1376,1226,  	1092, 1031,1092,1226,  1092,687,728,687,
	817,687,728,		817,917,1031,			917,1031,1092,1031,		917,817,728,687,
	817,687,728,		687,728,817,		728,687,612,						728,687,817,728//14*8=112   这句少了个音，待补
};

uint16_t canon_t[112]={ 
	50,25,25,  50,25,25, 25,25,25,25,  25,25,25,25,
	50,25,25,  50,25,25, 25,25,25,25,  25,25,25,25,
	50,25,25,  50,25,25, 25,25,25,25,  25,25,25,25,
	50,25,25,  50,25,25, 25,25,25,25,  25,25,25,25,	
	50,25,25,  50,25,25, 25,25,25,25,  25,25,25,25,
	50,25,25,  50,25,25, 25,25,25,25,  25,25,25,25,
	50,25,25,  50,25,25, 25,25,25,25,  25,25,25,25,
	50,25,25,  50,25,25, 25,25,25,25,  25,25,25,25
};

void Sound_SetHZ(int a)//设置频率来得到对应音符
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_WorkMode = TIM_WorkMode_Timer;
	TIM_TimeBaseInitStruct.TIM_Prescaler = TIM_PRESCALER_1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Preload = a;
	TIM_TimeBaseInitStruct.TIM_EXENX = TIM_EXENX_Disable;
	TIM_TIMBaseInit(TIM2, &TIM_TimeBaseInitStruct);
}

void play_note(int a,int b)
{
	Sound_SetHZ(32*a);
	Delay(100*b);
	Sound_SetHZ(20);
	Delay(5);
}

int note_num = 112;  // 音符数量
int music_f[112]; // 存储选择的乐曲频率
int music_t[112]; // 存储选择的乐曲时长'
int music; // 当前乐曲索引，0为童话，1为菊次郎，2为卡农

void choose_music(void)
{
	if(music ==0)//第一首歌童话
	{
		for(uint16_t i=0;i<51;i++)
		{
		note_num=51;	
		music_f[i]=tonghua_f[i];
		music_t[i]=tonghua_t[i];
		}
	}
	else if(music ==1)//菊次郎
	{
		for(uint16_t i=0;i<66;i++)
		{
		note_num=66;	
		music_f[i]=jucilang_f[i];
		music_t[i]=jucilang_t[i];
		}
	} 
	else if(music ==2)//卡农
	{
		for(uint8_t i=0;i<112;i++)
		{
		note_num=112;	
		music_f[i]=canon_f[i];
		music_t[i]=canon_t[i];
		}
	}	
}

void music_play(void)
{
	for(int i=0;i<note_num;i++)
	{
	switch (music_f[i])
    {
    	case 2747:OLED_ShowString(2,6,"-C");
    		break;
    	case 2448:OLED_ShowString(2,6,"-D");
    		break;
     	case 2181:OLED_ShowString(2,6,"-E");
    		break;
    	case 2062:OLED_ShowString(2,6,"-F");
    		break;
    	case 1836:OLED_ShowString(2,6,"-G");
    		break;
    	case 1635:OLED_ShowString(2,6,"-A");
    		break;
    	case 1456:OLED_ShowString(2,6,"-B");
    		break;
		case 1376:OLED_ShowString(2,6," C");
    		break;
    	case 1226:OLED_ShowString(2,6," D");
    		break;
     	case 1092:OLED_ShowString(2,6," E");
    		break;
    	case 1031:OLED_ShowString(2,6," F");
    		break;
    	case 917:OLED_ShowString(2,6," G");
    		break;
    	case 817:OLED_ShowString(2,6," A");
    		break;
    	case 728:OLED_ShowString(2,6," B");
    		break;
		case 687:OLED_ShowString(2,6,"+C ");
    		break;
    	case 612:OLED_ShowString(2,6,"+D ");
    		break;
     	case 545:OLED_ShowString(2,6,"+E ");
    		break;
    	case 514:OLED_ShowString(2,6,"+F ");
    		break;
    	case 458:OLED_ShowString(2,6,"+G ");
    		break;
    	case 408:OLED_ShowString(2,6,"+A ");
    		break;
    	case 363:OLED_ShowString(2,6,"+B ");
    		break;
		default:
    		break;
    }		

		play_note(music_f[i]/2,music_t[i]/25*60);
	}
}
