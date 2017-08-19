#include "motor.h"
  /**************************************************************************
���ߣ�ƽ��С��֮��
�ҵ��Ա�С�꣺http://shop114407458.taobao.com/
**************************************************************************/
void MiniBalance_Motor_Init(void)
{
	RCC->APB2ENR|=1<<3;       //PORTBʱ��ʹ��   
	RCC->APB2ENR|=1<<4;       //PORTCʱ��ʹ��  
	GPIOB->CRL&=0XFFFFFFF0;   //�������
	GPIOB->CRL|=0X00000002;   //�������
	GPIOB->ODR|=1<<0;  	
	
	GPIOC->CRL&=0XFF00FFFF;   //�������
	GPIOC->CRL|=0X00220000;   //�������
	GPIOC->ODR|=1<<4;  	
	GPIOC->ODR|=1<<5;  
}
void MiniBalance_PWM_Init(u16 arr,u16 psc)
{		 					 
	MiniBalance_Motor_Init();  //��ʼ�������������IO
	RCC->APB2ENR|=1<<13;       //ʹ��TIM8ʱ��    
	RCC->APB2ENR|=1<<4;        //PORTCʱ��ʹ��     
	GPIOC->CRH&=0XFFFFFFF0;    //PORTC8�������
	GPIOC->CRH|=0X0000000B;    //PORTC8�������
	
	GPIOC->CRL&=0X00FFFFFF;    //PORTC6 7�������
	GPIOC->CRL|=0XBB000000;    //PORTC6 7�������
	TIM8->ARR=arr;             //�趨�������Զ���װֵ 
	TIM8->PSC=psc;             //Ԥ��Ƶ������Ƶ
	TIM8->CCMR1|=6<<12;        //CH4 PWM1ģʽ	
	TIM8->CCMR2|=6<<4;         //CH1 PWM1ģʽ	
	TIM8->CCMR1|=6<<4;         //CH1 PWM1ģʽ	
	TIM8->CCMR1|=1<<11;        //CH4Ԥװ��ʹ��	 
	TIM8->CCMR1|=1<<3;         //CH1Ԥװ��ʹ��	  
	TIM8->CCMR2|=1<<3;         //CH1Ԥװ��ʹ��	  
	TIM8->CCER|=1<<8;         //CH4���ʹ��	   
	TIM8->CCER|=1<<4;         //CH4���ʹ��	   
	TIM8->CCER|=1<<0;          //CH1���ʹ��	
	TIM8->BDTR |= 1<<15;       //TIM1����Ҫ��仰�������PWM
	TIM8->CR1=0x8000;          //ARPEʹ�� 
	TIM8->CR1|=0x01;          //ʹ�ܶ�ʱ��1 			
	TIM8->CCR1=7200;
	TIM8->CCR2=7200;
	TIM8->CCR3=7200;
} 

