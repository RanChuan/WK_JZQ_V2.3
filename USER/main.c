#include "delay.h"
#include "sys.h"
#include "includes.h" 



#include "my_rf.h"
#include "my_light.h"
#include "my_messeg.h"
#include "my_key.h"
#include "my_lcd.h"
#include "my_w5500.h"
#include "malloc.h" 
#include "my_autocontrol.h"
#include "my_cfg.h"

#include "beep.h"
#include "mmc_sd.h"
#include "fats.h"

#include "file.h"








							//�����ջ��ʼ�����������Ӳ���жϣ����Խ���Щֵ�Ĵ�
u32 my_keytack[128];
u32 my_lcdtack[256];
u32 rf_looptack[256];
u32 my_lighttack[128];
u32 my_rf_handtack[128];
u32 my_rf_dealtack[64];
u32 my_w5500tack[256];
u32 my_autotack[128];
u32 my_cfgtack[64];
u32 my_iottack[128];
int main(void)
{	
	
	SysPowerOn();
//	sys_cfg_init();
	
	
	CreateTask (my_key, 				0, &my_keytack[127],				1)	;					
	CreateTask (my_lcd, 			0, &my_lcdtack[255],			2)	;	 				
	CreateTask (my_rf_loop, 		0, &rf_looptack[255],			3)	;					
	CreateTask (my_light, 			0, &my_lighttack[127],		4)	;		
	CreateTask (my_rf_hand, 		0, &my_rf_handtack[127],	5)	;		
	CreateTask (my_rf_deal, 		0, &my_rf_dealtack[63],		6)	;		
	CreateTask (my_w5500, 			0, &my_w5500tack[255],		7)	;		
	CreateTask (my_autocontrol, 0, &my_autotack[127],			8)	;		
	CreateTask (my_cfg, 				0, &my_cfgtack[63],			9)	;		
//	CreateTask (my_iot, 				0, &my_iottack[127],		 10)	;		
	OSStart ( );

} 

 
 



 