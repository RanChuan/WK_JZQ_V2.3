#include "beep.h"
#include "malloc.h"




u8 BEEP_BUSY=0;//���������ڲ��ţ�




void BEEP_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	 //ʹ��GPIOB�˿�ʱ��
	void TIME3_Init(void);
	
	
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;				 //BEEP-->PB.8 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;	 //pc13ֻ����2M
 GPIO_Init(GPIOC, &GPIO_InitStructure);	 //���ݲ�����ʼ��GPIOB.8
	RCC_LSEConfig(RCC_LSE_OFF);
	
 GPIO_ResetBits(GPIOC,GPIO_Pin_13);//���0���رշ��������

	TIME3_Init( );
}



void TIME3_Init(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //ʱ��ʹ��
	
	//��ʱ��TIM3��ʼ��
	TIM_TimeBaseStructure.TIM_Period = 100-1; //10us
	TIM_TimeBaseStructure.TIM_Prescaler =72-1; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
 
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); //ʹ��ָ����TIM3�ж�,���������ж�

	//�ж����ȼ�NVIC����
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //�����ȼ�3��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���

	TIM_Cmd(TIM3, ENABLE);  //ʹ��TIMx		
}



//	װ��һ������
void Load_song(void)
{
	jianpu *j=mymalloc(sizeof(jianpu)*200);
	jianpu *jj=j;
	set_jianpu(jj,"6","1/1");
	jj++;
	set_jianpu(jj,"2","3/2");
	jj++;
	set_jianpu(jj,"1","1/2");
	jj++;
	set_jianpu(jj,"3","2/1");
	jj++;
	set_jianpu(jj,"0","1/2");
	jj++;
	set_jianpu(jj,"1","3/2");
	jj++;
	set_jianpu(jj,"2","1/2");
	jj++;
	set_jianpu(jj,"1","1/2");
	jj++;
	set_jianpu(jj,"2","1/2");
	jj++;
	set_jianpu(jj,"3","1/1");
	jj++;
	set_jianpu(jj,"6_","5/2");
	


	jj++;
	set_jianpu(jj,"6","1/1");
	jj++;
	set_jianpu(jj,"2","3/2");
	jj++;
	set_jianpu(jj,"1","1/2");
	jj++;
	set_jianpu(jj,"3","2/1");
	jj++;
	set_jianpu(jj,"0","1/2");
	jj++;
	set_jianpu(jj,"1","1/2");
	jj++;
	set_jianpu(jj,"2","1/1");
	jj++;
	set_jianpu(jj,"6","2/1");
	jj++;
	set_jianpu(jj,"2","1/1");
	jj++;
	set_jianpu(jj,"3","2/1");
	
	
	jj++;
	set_jianpu(jj,"6","1/1");
	jj++;
	set_jianpu(jj,"3","1/1");
	jj++;
	set_jianpu(jj,"2","1/2");
	jj++;
	set_jianpu(jj,"1","1/2");
	jj++;
	set_jianpu(jj,"2","2/1");
	jj++;
	set_jianpu(jj,"0","1/1");
	jj++;
	set_jianpu(jj,"1","1/1");
	jj++;
	set_jianpu(jj,"2","3/2");
	jj++;
	set_jianpu(jj,"3","1/1");
	jj++;
	set_jianpu(jj,"6_","5/2");


	jj++;
	set_jianpu(jj,"6","1/1");
	jj++;
	set_jianpu(jj,"3","1/1");
	jj++;
	set_jianpu(jj,"6","1/1");
	jj++;
	set_jianpu(jj,"7","1/1");
	jj++;
	set_jianpu(jj,"3","1/1");
	jj++;
	set_jianpu(jj,"7","1/1");
	jj++;
	set_jianpu(jj,"1~","1/1");
	jj++;
	set_jianpu(jj,"2~","2/1");
	jj++;
	set_jianpu(jj,"7","6/1");


	jj++;
	set_jianpu(jj,"3","1/2");
	jj++;
	set_jianpu(jj,"6","2/1");
	jj++;
	set_jianpu(jj,"3","1/1");
	jj++;
	set_jianpu(jj,"7","3/2");
	jj++;
	set_jianpu(jj,"0","1/2");
	jj++;
	set_jianpu(jj,"3","1/3");
	jj++;
	set_jianpu(jj,"2~","1/2");
	jj++;
	set_jianpu(jj,"1~","1/2");
	jj++;
	set_jianpu(jj,"7","1/2");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"5","1/2");
	jj++;
	set_jianpu(jj,"6","1/1");
	jj++;
	set_jianpu(jj,"3","1/2");
	jj++;
	set_jianpu(jj,"3","2/1");
	
	
	jj++;
	set_jianpu(jj,"3","1/2");
	jj++;
	set_jianpu(jj,"6","2/1");
	jj++;
	set_jianpu(jj,"3","1/2");
	jj++;
	set_jianpu(jj,"7","1/1");
	jj++;
	set_jianpu(jj,"6","1/1");
	jj++;
	set_jianpu(jj,"0","1/2");
	jj++;
	set_jianpu(jj,"3","1/2");
	jj++;
	set_jianpu(jj,"2","1/1");
	jj++;
	set_jianpu(jj,"1","1/1");
	jj++;
	set_jianpu(jj,"2","1/1");
	jj++;
	set_jianpu(jj,"3","3/1");
	
	
	jj++;
	set_jianpu(jj,"3","1/2");
	jj++;
	set_jianpu(jj,"6","2/1");
	jj++;
	set_jianpu(jj,"3","1/1");
	jj++;
	set_jianpu(jj,"7","3/2");
	jj++;
	set_jianpu(jj,"0","1/2");
	jj++;
	set_jianpu(jj,"3","1/2");
	jj++;
	set_jianpu(jj,"2~","1/2");
	jj++;
	set_jianpu(jj,"1~","1/2");
	jj++;
	set_jianpu(jj,"7","1/2");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"5","1/2");
	jj++;
	set_jianpu(jj,"6","1/1");
	jj++;
	set_jianpu(jj,"3","5/2");


	jj++;
	set_jianpu(jj,"3","1/2");
	jj++;
	set_jianpu(jj,"6","2/1");
	jj++;
	set_jianpu(jj,"3","1/2");
	jj++;
	set_jianpu(jj,"3~","1/1");
	jj++;
	set_jianpu(jj,"2~","3/2");
	jj++;
	set_jianpu(jj,"3~","1/2");
	jj++;
	set_jianpu(jj,"1~","2/1");
	jj++;
	set_jianpu(jj,"7","1/1");
	jj++;
	set_jianpu(jj,"6","6/1");

	jj++;
	jianpu_end(jj);

	
	Beep_Play(j);
	myfree(j);
}





void Load_song1(void)
{
	jianpu *j=mymalloc(sizeof(jianpu)*200);
	jianpu *jj=j;
	set_jianpu(jj,"6_","1/2");
	jj++;
	set_jianpu(jj,"1","1/1");
	jj++;
	set_jianpu(jj,"6_","1/2");
	jj++;
	set_jianpu(jj,"3","3/2");
	jj++;
	set_jianpu(jj,"2","1/1");
	jj++;
	set_jianpu(jj,"1","7/2");


	jj++;
	set_jianpu(jj,"7_","1/2");
	jj++;
	set_jianpu(jj,"6_","1/1");
	jj++;
	set_jianpu(jj,"7_","1/2");
	jj++;
	set_jianpu(jj,"2","3/2");
	jj++;
	set_jianpu(jj,"3","1/2");
	jj++;
	set_jianpu(jj,"1","1/2");
	jj++;
	set_jianpu(jj,"6_","7/2");


	jj++;
	set_jianpu(jj,"3","2/1");
	jj++;
	set_jianpu(jj,"6","3/2");
	jj++;
	set_jianpu(jj,"3","2/1");
	jj++;
	set_jianpu(jj,"6","1/1");
	jj++;
	set_jianpu(jj,"5","1/2");
	jj++;
	set_jianpu(jj,"4","1/2");
	jj++;
	set_jianpu(jj,"3","2/1");


	jj++;
	set_jianpu(jj,"1","3/2");
	jj++;
	set_jianpu(jj,"2","1/2");
	jj++;
	set_jianpu(jj,"3","1/1");
	jj++;
	set_jianpu(jj,"4","1/2");
	jj++;
	set_jianpu(jj,"3","1/2");
	jj++;
	set_jianpu(jj,"2","4/1");


	jj++;
	set_jianpu(jj,"6_","1/1");
	jj++;
	set_jianpu(jj,"3","1/1");
	jj++;
	set_jianpu(jj,"2","1/2");
	jj++;
	set_jianpu(jj,"3","1/2");
	jj++;
	set_jianpu(jj,"6_","1/1");
	jj++;
	set_jianpu(jj,"1","3/1");
	jj++;
	set_jianpu(jj,"3","1/1");


	jj++;
	set_jianpu(jj,"2","1/2");
	jj++;
	set_jianpu(jj,"7_","1/2");
	jj++;
	set_jianpu(jj,"0","1/2");
	jj++;
	set_jianpu(jj,"3","1/2");
	jj++;
	set_jianpu(jj,"2","1/2");
	jj++;
	set_jianpu(jj,"6_","1/2");
	jj++;
	set_jianpu(jj,"1","1/2");
	jj++;
	set_jianpu(jj,"2","1/2");
	jj++;
	set_jianpu(jj,"3","4/1");


	jj++;
	set_jianpu(jj,"3","2/1");
	jj++;
	set_jianpu(jj,"6","3/2");
	jj++;
	set_jianpu(jj,"3","1/2");
	jj++;
	set_jianpu(jj,"6","1/1");
	jj++;
	set_jianpu(jj,"5","1/2");
	jj++;
	set_jianpu(jj,"4","1/2");
	jj++;
	set_jianpu(jj,"3","2/1");


	jj++;
	set_jianpu(jj,"5","1/2");
	jj++;
	set_jianpu(jj,"2","1/2");
	jj++;
	set_jianpu(jj,"0","1/2");
	jj++;
	set_jianpu(jj,"4","1/2");
	jj++;
	set_jianpu(jj,"3","1/2");
	jj++;
	set_jianpu(jj,"2","1/2");
	jj++;
	set_jianpu(jj,"1","1/1");
	jj++;
	set_jianpu(jj,"2","3/1");
	jj++;
	set_jianpu(jj,"3","1/1");


	jj++;
	set_jianpu(jj,"2","1/2");
	jj++;
	set_jianpu(jj,"7_","1/2");
	jj++;
	set_jianpu(jj,"0","1/2");
	jj++;
	set_jianpu(jj,"3","1/2");
	jj++;
	set_jianpu(jj,"7_","1/2");
	jj++;
	set_jianpu(jj,"6_","1/2");
	jj++;
	set_jianpu(jj,"5_","1/1");
	jj++;
	set_jianpu(jj,"6_","3/1");
	jj++;
	set_jianpu(jj,"3","1/1");


	jj++;
	set_jianpu(jj,"5","3/1");
	jj++;
	set_jianpu(jj,"3","1/2");
	jj++;
	set_jianpu(jj,"5","1/2");
	jj++;
	set_jianpu(jj,"6","3/2");
	jj++;
	set_jianpu(jj,"1~","1/2");
	jj++;
	set_jianpu(jj,"7","1/2");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"5","1/1");
	jj++;
	set_jianpu(jj,"6","4/1");


	jj++;
	set_jianpu(jj,"1~","2/1");
	jj++;
	set_jianpu(jj,"7","3/2");
	jj++;
	set_jianpu(jj,"6","3/2");
	jj++;
	set_jianpu(jj,"5","5/2");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"3","4/1");


	jj++;
	set_jianpu(jj,"1~","2/1");
	jj++;
	set_jianpu(jj,"7","3/2");
	jj++;
	set_jianpu(jj,"6","3/2");
	jj++;
	set_jianpu(jj,"5","5/2");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"3","4/1");


	jj++;
	set_jianpu(jj,"6_","1/1");
	jj++;
	set_jianpu(jj,"1","1/1");
	jj++;
	set_jianpu(jj,"2","1/1");
	jj++;
	set_jianpu(jj,"3","3/2");
	jj++;
	set_jianpu(jj,"1","1/2");
	jj++;
	set_jianpu(jj,"3","1/1");
	jj++;
	set_jianpu(jj,"2","3/1");


	jj++;
	set_jianpu(jj,"2","1/2");
	jj++;
	set_jianpu(jj,"7_","1/2");
	jj++;
	set_jianpu(jj,"0","1/2");
	jj++;
	set_jianpu(jj,"3","1/2");
	jj++;
	set_jianpu(jj,"7_","1/2");
	jj++;
	set_jianpu(jj,"6_","1/2");
	jj++;
	set_jianpu(jj,"5_","1/1");
	jj++;
	set_jianpu(jj,"6_","4/1");


	jj++;
	set_jianpu(jj,"6_","1/2");
	jj++;
	set_jianpu(jj,"1","1/1");
	jj++;
	set_jianpu(jj,"2","1/2");
	jj++;
	set_jianpu(jj,"3","3/2");
	jj++;
	set_jianpu(jj,"1","1/2");
	jj++;
	set_jianpu(jj,"3","1/1");
	jj++;
	set_jianpu(jj,"2","3/1");
	

	jj++;
	set_jianpu(jj,"3","1/1");
	jj++;
	set_jianpu(jj,"5","2/1");
	jj++;
	set_jianpu(jj,"3","1/1");
	jj++;
	set_jianpu(jj,"7","3/2");
	jj++;
	set_jianpu(jj,"1","1/2");
	jj++;
	set_jianpu(jj,"7","1/2");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"5","1/1");
	jj++;
	set_jianpu(jj,"6","7/1");
	jj++;
	jianpu_end(jj);
	
	Beep_Play(j);
	myfree(j);
}


void Load_song2(void)
{
	jianpu *j=mymalloc(sizeof(jianpu)*200);
	jianpu *jj=j;
	
	/*
	set_jianpu(jj,"6_","2/2");
	jj++;
	set_jianpu(jj,"7_","1/4");
	jj++;
	set_jianpu(jj,"1","9/4");
	jj++;
	set_jianpu(jj,"2","3/4");
	jj++;
	set_jianpu(jj,"5_","3/4");
	jj++;
	set_jianpu(jj,"6_","1/4");
	jj++;
	set_jianpu(jj,"7_","1/4");
	jj++;
	set_jianpu(jj,"6_","4/2");
	jj++;

	set_jianpu(jj,"0","1/2");
	jj++;
	set_jianpu(jj,"6_","2/2");
	jj++;
	set_jianpu(jj,"7_","1/4");
	jj++;
	set_jianpu(jj,"1","9/4");
	jj++;
	set_jianpu(jj,"2","3/2");
	jj++;
	set_jianpu(jj,"1","1/2");
	jj++;
	set_jianpu(jj,"3","2/2");
	jj++;

	set_jianpu(jj,"0","1/2");
	jj++;
	set_jianpu(jj,"6_","1/2");
	jj++;
	set_jianpu(jj,"4","3/2");
	jj++;
	set_jianpu(jj,"1","1/2");
	jj++;
	set_jianpu(jj,"2","2/2");
	jj++;
	set_jianpu(jj,"0","1/2");
	jj++;
	set_jianpu(jj,"5_","1/2");
	jj++;
	set_jianpu(jj,"3","2/2");
	jj++;
	set_jianpu(jj,"2","1/2");
	jj++;
	set_jianpu(jj,"1","3/2");
	jj++;


	set_jianpu(jj,"0","1/4");
	jj++;
	set_jianpu(jj,"2","1/2");
	jj++;
	set_jianpu(jj,"1","1/4");
	jj++;
	set_jianpu(jj,"6_","1/4");
	jj++;
	set_jianpu(jj,"2","3/4");
	jj++;
	set_jianpu(jj,"0","1/4");
	jj++;
	set_jianpu(jj,"6_","1/4");
	jj++;
	set_jianpu(jj,"1","1/4");
	jj++;
	set_jianpu(jj,"6_","1/4");
	jj++;
	set_jianpu(jj,"7_","5/4");
	jj++;
	set_jianpu(jj,"1","1/2");
	jj++;
	set_jianpu(jj,"6_","9/4");
	jj++;
*/

//	set_jianpu(jj,"0","5/2");
//	jj++;
	set_jianpu(jj,"6_","2/2");
	jj++;
	set_jianpu(jj,"7_","1/4");
	jj++;
	set_jianpu(jj,"1","5/4");
	jj++;
	set_jianpu(jj,"0","1/2");
	jj++;
	set_jianpu(jj,"6_","1/4");
	jj++;
	set_jianpu(jj,"1","1/4");
	jj++;
	set_jianpu(jj,"7_","2/2");
	jj++;
	set_jianpu(jj,"5_","1/4");
	jj++;
	set_jianpu(jj,"7_","3/4");
	jj++;
	set_jianpu(jj,"6_","4/2");
	jj++;


	set_jianpu(jj,"0","1/2");
	jj++;
	set_jianpu(jj,"6_","2/2");
	jj++;
	set_jianpu(jj,"7_","1/4");
	jj++;
	set_jianpu(jj,"1","5/4");
	jj++;
	set_jianpu(jj,"0","1/2");
	jj++;


	set_jianpu(jj,"6_","1/4");
	jj++;
	set_jianpu(jj,"1","1/4");
	jj++;
	set_jianpu(jj,"2","2/2");
	jj++;
	set_jianpu(jj,"1","1/4");
	jj++;
	set_jianpu(jj,"2","3/4");
	jj++;
	set_jianpu(jj,"3","2/2");
	jj++;


	set_jianpu(jj,"0","1/2");
	jj++;
	set_jianpu(jj,"6_","1/2");
	jj++;
	set_jianpu(jj,"4","3/2");
	jj++;
	set_jianpu(jj,"1","1/2");
	jj++;
	set_jianpu(jj,"2","1/4");
	jj++;
	set_jianpu(jj,"1","1/4");
	jj++;
	set_jianpu(jj,"2","1/2");
	jj++;


	set_jianpu(jj,"0","1/2");
	jj++;
	set_jianpu(jj,"5_","1/2");
	jj++;
	set_jianpu(jj,"3","2/2");
	jj++;
	set_jianpu(jj,"2","3/4");
	jj++;
	set_jianpu(jj,"1","5/4");
	jj++;
	set_jianpu(jj,"0","1/4");
	jj++;


	set_jianpu(jj,"2","1/2");
	jj++;
	set_jianpu(jj,"1","1/4");
	jj++;
	set_jianpu(jj,"6_","1/4");
	jj++;
	set_jianpu(jj,"2","2/2");
	jj++;
	set_jianpu(jj,"6_","1/4");
	jj++;
	set_jianpu(jj,"1","1/4");
	jj++;
	set_jianpu(jj,"6_","1/4");
	jj++;
	set_jianpu(jj,"1","2/2");
	jj++;
	set_jianpu(jj,"2","1/4");
	jj++;
	set_jianpu(jj,"4","1/2");
	jj++;
	set_jianpu(jj,"3","8/4");
	jj++;
	set_jianpu(jj,"3","5/4");
	jj++;


	set_jianpu(jj,"0","1/2");//���Ʈ����ס������
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"3~","2/2");
	jj++;
	set_jianpu(jj,"2~","1/2");
	jj++;
	set_jianpu(jj,"1~","1/4");
	jj++;
	set_jianpu(jj,"6","1/4");
	jj++;
	set_jianpu(jj,"1~","1/4");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"1~","1/4");
	jj++;


	set_jianpu(jj,"0","1/4");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"1~","1/4");
	jj++;
	set_jianpu(jj,"7","2/2");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"5","1/4");
	jj++;
	set_jianpu(jj,"6","5/4");
	jj++;
	
	
	set_jianpu(jj,"0","1/2");//̧������˵�����
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"3~","2/2");
	jj++;
	set_jianpu(jj,"2~","1/2");
	jj++;
	set_jianpu(jj,"1~","1/4");
	jj++;
	set_jianpu(jj,"6","1/4");
	jj++;
	set_jianpu(jj,"1~","1/4");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"1~","1/4");
	jj++;
	

	set_jianpu(jj,"0","1/4");//
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"1~","1/4");
	jj++;
	set_jianpu(jj,"7","2/2");
	jj++;
	set_jianpu(jj,"5","1/4");
	jj++;
	set_jianpu(jj,"7","1/2");
	jj++;
	set_jianpu(jj,"6","5/4");
	jj++;


	set_jianpu(jj,"0","1/2");//������֬��ס��˼��
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"3~","2/2");
	jj++;
	set_jianpu(jj,"2~","1/2");
	jj++;
	set_jianpu(jj,"1~","1/4");
	jj++;
	set_jianpu(jj,"6","1/4");
	jj++;
	set_jianpu(jj,"1~","1/4");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"1~","1/4");
	jj++;
	
	set_jianpu(jj,"0","1/4");//
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"1~","1/4");
	jj++;
	set_jianpu(jj,"7","2/2");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"5","1/4");
	jj++;
	set_jianpu(jj,"3","5/4");
	jj++;


	set_jianpu(jj,"0","1/2");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"3~","3/4");
	jj++;
	set_jianpu(jj,"5~","1/2");
	jj++;
	set_jianpu(jj,"3~","1/2");
	jj++;
	set_jianpu(jj,"2~","1/2");
	jj++;
	set_jianpu(jj,"1~","1/2");
	jj++;
	set_jianpu(jj,"2~","1/4");
	jj++;
	set_jianpu(jj,"6","3/4");
	jj++;
	set_jianpu(jj,"2~","2/2");
	jj++;
	set_jianpu(jj,"1~","1/2");
	jj++;
	set_jianpu(jj,"7","3/4");
	jj++;
	set_jianpu(jj,"1~","1/2");
	jj++;
	set_jianpu(jj,"6","3/2");
	jj++;
	



	jianpu_end(jj);
	
	Beep_Play(j);
	myfree(j);
}





void Load_song3(void)
{
	jianpu *j=mymalloc(sizeof(jianpu)*300);
	jianpu *jj=j;
	
	set_jianpu(jj,"6","3/2");
	jj++;
	set_jianpu(jj,"3~","1/2");
	jj++;
	set_jianpu(jj,"7","2/2");
	jj++;
	set_jianpu(jj,"1~","1/2");
	jj++;
	set_jianpu(jj,"7","1/2");
	jj++;
	set_jianpu(jj,"6","2/2");
	jj++;
	set_jianpu(jj,"5","1/2");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"3","2/2");
	jj++;


	set_jianpu(jj,"0","1/2");
	jj++;
	set_jianpu(jj,"5","1/2");
	jj++;
	set_jianpu(jj,"6","3/2");
	jj++;
	set_jianpu(jj,"7","1/2");
	jj++;
	set_jianpu(jj,"1~","1/2");
	jj++;
	set_jianpu(jj,"2~","2/2");
	jj++;
	set_jianpu(jj,"3~","1/4");
	jj++;
	set_jianpu(jj,"5~","1/4");
	jj++;
	set_jianpu(jj,"2~","4/2");
	jj++;

	set_jianpu(jj,"0","4/2");
	jj++;
	set_jianpu(jj,"6","3/2");
	jj++;
	set_jianpu(jj,"3~","1/2");
	jj++;
	set_jianpu(jj,"7","2/2");
	jj++;
	set_jianpu(jj,"1~","1/2");
	jj++;
	set_jianpu(jj,"7","1/2");
	jj++;
	set_jianpu(jj,"6","2/2");
	jj++;
	set_jianpu(jj,"5","1/2");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"3","2/2");
	jj++;

	set_jianpu(jj,"0","1/2");
	jj++;
	set_jianpu(jj,"2","1/2");
	jj++;
	set_jianpu(jj,"3","1/2");
	jj++;
	set_jianpu(jj,"5","1/2");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"1~","1/2");
	jj++;
	set_jianpu(jj,"6","2/2");
	jj++;
	set_jianpu(jj,"5","2/2");
	jj++;
	set_jianpu(jj,"6","4/2");
	jj++;

	set_jianpu(jj,"0","2/2");
	jj++;
	set_jianpu(jj,"1~","1/2");
	jj++;
	set_jianpu(jj,"2~","1/2");
	jj++;
	set_jianpu(jj,"3~","1/2");
	jj++;
	set_jianpu(jj,"2~","1/2");
	jj++;
	set_jianpu(jj,"3~","1/2");
	jj++;
	set_jianpu(jj,"5~","3/2");
	jj++;
	set_jianpu(jj,"3~","1/2");
	jj++;
	set_jianpu(jj,"2~","1/2");
	jj++;
	set_jianpu(jj,"1~","2/2");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"5","1/2");
	jj++;
	set_jianpu(jj,"3","2/2");
	jj++;


	set_jianpu(jj,"1~","1/2");//����İ���������ڹ�����
	jj++;
	set_jianpu(jj,"2~","1/2");
	jj++;
	set_jianpu(jj,"3~","1/2");
	jj++;
	set_jianpu(jj,"2~","1/2");
	jj++;
	set_jianpu(jj,"3~","1/2");
	jj++;
	set_jianpu(jj,"5~","1/2");
	jj++;
	set_jianpu(jj,"3~","1/2");
	jj++;
	set_jianpu(jj,"2~","1/2");
	jj++;
	set_jianpu(jj,"1~","1/4");
	jj++;
	set_jianpu(jj,"6","3/4");
	jj++;
	set_jianpu(jj,"3~","4/2");
	jj++;


	set_jianpu(jj,"1~","1/2");
	jj++;
	set_jianpu(jj,"2~","1/2");
	jj++;
	set_jianpu(jj,"3~","1/2");
	jj++;
	set_jianpu(jj,"2~","1/2");
	jj++;
	set_jianpu(jj,"3~","1/2");
	jj++;
	set_jianpu(jj,"5~","3/2");
	jj++;
	set_jianpu(jj,"3~","1/2");
	jj++;
	set_jianpu(jj,"2~","1/2");
	jj++;
	set_jianpu(jj,"1~","1/2");
	jj++;
	set_jianpu(jj,"2~","1/4");
	jj++;
	set_jianpu(jj,"1~","1/4");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"5","1/2");
	jj++;
	set_jianpu(jj,"3","2/2");
	jj++;


	set_jianpu(jj,"0","1/2");
	jj++;
	set_jianpu(jj,"5","1/2");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"5","1/2");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"3~","1/2");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"5","1/2");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"5","1/2");
	jj++;
	set_jianpu(jj,"6","4/2");
	jj++;


	set_jianpu(jj,"0","2/2");
	jj++;
	set_jianpu(jj,"3~","1/2");
	jj++;
	set_jianpu(jj,"5~","1/2");
	jj++;
	set_jianpu(jj,"6~","1/2");
	jj++;
	set_jianpu(jj,"5~","1/2");
	jj++;
	set_jianpu(jj,"3~","1/2");
	jj++;
	set_jianpu(jj,"2~","2/2");
	jj++;
	set_jianpu(jj,"1~","1/2");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"2~","2/2");
	jj++;
	set_jianpu(jj,"5~","1/2");
	jj++;
	set_jianpu(jj,"3~","3/2");
	jj++;


	set_jianpu(jj,"0","1/2");//�ͻض�����������
	jj++;
	set_jianpu(jj,"3~","1/4");
	jj++;
	set_jianpu(jj,"5~","1/4");
	jj++;
	set_jianpu(jj,"6~","2/2");
	jj++;
	set_jianpu(jj,"5~","1/2");
	jj++;
	set_jianpu(jj,"3~","1/2");
	jj++;
	set_jianpu(jj,"2~","2/2");
	jj++;
	set_jianpu(jj,"3~","1/2");
	jj++;
	set_jianpu(jj,"5~","1/2");
	jj++;
	set_jianpu(jj,"3~","4/2");
	jj++;


	set_jianpu(jj,"0","2/2");
	jj++;
	set_jianpu(jj,"3~","1/2");
	jj++;
	set_jianpu(jj,"5~","1/2");
	jj++;
	set_jianpu(jj,"6~","2/2");
	jj++;
	set_jianpu(jj,"5~","1/2");
	jj++;
	set_jianpu(jj,"3~","1/2");
	jj++;
	set_jianpu(jj,"2~","2/2");
	jj++;
	set_jianpu(jj,"1~","2/2");
	jj++;
	set_jianpu(jj,"7","2/2");
	jj++;
	set_jianpu(jj,"5","2/2");
	jj++;
	set_jianpu(jj,"1~","2/2");
	jj++;


	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"5","1/2");
	jj++;
	set_jianpu(jj,"6","2/2");
	jj++;
	set_jianpu(jj,"0","1/2");
	jj++;
	set_jianpu(jj,"1~","1/2");
	jj++;
	set_jianpu(jj,"7","1/2");
	jj++;
	set_jianpu(jj,"1~","1/4");
	jj++;
	set_jianpu(jj,"7","1/4");
	jj++;
	set_jianpu(jj,"6","1/2");
	jj++;
	set_jianpu(jj,"5","1/2");
	jj++;
	set_jianpu(jj,"6","6/2");
	jj++;


	jianpu_end(jj);
	Beep_Play(j);
	myfree(j);
}






void Load_up(void)
{
	jianpu *j=mymalloc(sizeof(jianpu)*200);
	jianpu *jj=j;
	set_jianpu(jj,"1","1/2");
	jj++;
	set_jianpu(jj,"2","1/2");
	jj++;
	set_jianpu(jj,"3","1/2");
	jj++;
	set_jianpu(jj,"4","1/2");
	jj++;
	set_jianpu(jj,"5","1/1");
	jj++;
	jianpu_end(jj);
	Beep_Play(j);
	myfree(j);
}

void Load_down(void)
{
	jianpu *j=mymalloc(sizeof(jianpu)*200);
	jianpu *jj=j;
	set_jianpu(jj,"5","1/2");
	jj++;
	set_jianpu(jj,"4","1/2");
	jj++;
	set_jianpu(jj,"3","1/2");
	jj++;
	set_jianpu(jj,"2","1/2");
	jj++;
	set_jianpu(jj,"1","1/1");
	jj++;
	jianpu_end(jj);
	Beep_Play(j);
	myfree(j);
}


//���8��֮һ����������Ƶ��
u16 *sond=0;

//time,8��һ��ȫ����16������ȫ��
void set_jianpu(jianpu *j,char *tone_,char *time_)
{
	u8 i=0;
	while(tone_[i])
	{
		j->tone[i]=tone_[i];
		i++;
	}
	j->tone[i]=0;//�������ݽ�β
	i=0;
	while(time_[i])
	{
		j->time[i]=time_[i];
		i++;
	}
	j->time[i]=0;//�������ݽ�β
}

//��������
void jianpu_end(jianpu *j)
{
	j->time[0]=0;
	j->tone[0]=0;
}


void Beep_Play (jianpu *jianpu_)
{
	u16 i=0;
	u16 frequency[8]={0,2615/4,2935/4,3295/4,3490/4,3920/4,4400/4,4940/4};
	
	if (BEEP_BUSY==1) return;//���ڲ��ţ�����
	BEEP_BUSY=1;//����Ϊæ
	sond=mymalloc(300*2);
	if (sond==0) return;//û�з��䵽�ڴ棬�˳�
	while(jianpu_->tone[0])
	{
		sond[i*2]=frequency[jianpu_->tone[0]-'0'];
		if (jianpu_->tone[1]=='_')
		{
			sond[i*2]=sond[i*2]/2;
		}
		else if (jianpu_->tone[1]=='~')
		{
			sond[i*2]=sond[i*2]*2;
		}
		sond[i*2+1]=8/(jianpu_->time[2]-'0');
		sond[i*2+1]=sond[i*2+1]*(jianpu_->time[0]-'0');

		jianpu_++;
		i++;
	}
	sond[i*2+1]=0;//���ʱ��Ϊ0����ʱ����ֹͣ
	TIM_Cmd(TIM3,ENABLE); 
}



	
void Beep_Run(void)
{
	static u16 i=0;
	static u32 time =0;//��������
	static u32 sondtime=0;//��������ʱ��
	u32 temp=100000/sond[i*2];
	sondtime++;
	time++;
	if (temp)
	{
		if (sondtime>temp-5)//((temp)>25?(temp-10):(temp/2)))
			BEEP=1;
		else 
			BEEP=0;
	}
	else//֧�ּ�Ъ
	{
		BEEP=0;
	}
	if (sondtime>=100000/sond[i*2])
	{
		sondtime=0;
	}
	if (time>=sond[i*2+1]*10000)
	{
		i++;
		time=0;
		if (sond[i*2+1]==0)
		{
			i=0;
			time=0;
			sondtime=0;
			myfree(sond);
			BEEP=0;
			BEEP_BUSY=0;
			TIM_Cmd(TIM3, DISABLE);  //�رն�ʱ��	
		}
	}
}


#define LED111 PCout(7)
#define LED222 PCout(8)


void fff(void)
{
	static u32 a=0;
	static u32 b=0;
	static u32 c=0;
	static u32 d=0;
	a++;
	if (a==100)//Ƶ�ʿ���
	{
		a=0;
		LED111=1;
		LED222=1;
	}
//	else if (a==b)
//	{
//		LED111=0;
//		LED222=0;
//	}
	
	d++;
	static u8 t=0;
	if (d>=1000)//��������
	{
		d=0;
		if (t==0)
		{
			b++;
			if (b>=40)
			{
				t=1;
			}
		}
		if (t==1)
		{
			if (b>0)
				b--;
			else
			{
				
				t=0;
			}
		}
	}
}



void TIM3_IRQHandler(void)   //TIM4�ж�
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //���TIM3�����жϷ������
	{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //���TIMx�����жϱ�־ 
		//if (sond) Beep_Run( );   //ojjm�ж�
		fff();
	}
}

