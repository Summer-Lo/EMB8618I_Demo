/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/main.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */  

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "EMB8618I_IOConfig.h"
#include "user_vars.h"
#include <stdio.h>
#include <string.h>

/************************************************************************************/
// ������ȫ�ֱ�������
/************************************************************************************/

/************************************************************************************/

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

PUTCHAR_PROTOTYPE
{
  /* Write a character to the USART */
   USART_SendData(USART1, ch);					    
   while(USART_GetFlagStatus(USART1, USART_FLAG_TC)==RESET);      //�ж��Ƿ�����ɡ�
   
   return ch;
}
 /***********************************************************************************
* Function: Delay_us;
*
* Description: ��ʱ����,��λ΢��;
* 
* Input:  nCount: 
*
* Output: none;
*          		
* Return: none;
*
* Note:   none;
************************************************************************************/
void Delay_us(__IO uint32_t nCount)
{
    uint32_t Time;
	Time = nCount*1000/126;
	while(--Time);
}

 /***********************************************************************************
* Function: Delay_ms;
*
* Description: ��ʱ����,��λ����;
* 
* Input:  nCount: 
*
* Output: none;
*          		
* Return: none;
*
* Note:   none;
************************************************************************************/
void Delay_ms(__IO uint32_t nCount)
{
	uint32_t Time;
	Time = nCount*1000000/126;
	while(--Time);
}
/***********************************************************************************
* Function: NVIC_Configuration;
*
* Description: NVIC��ʼ������;
* 
* Input:  none;
*
* Output: none;
*          		
* Return: none;
*
* Note:   none;
************************************************************************************/
void NVIC_Configuration(void)
{
//    NVIC_InitTypeDef NVIC_InitStructure;

//	/* Configure the NVIC Preemption Priority Bits */  
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);		   
//	
//	// ����USART1�ж�
//	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;			     	
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);
}

 /***********************************************************************************
* Function: GPIO_RemapConfig;
*
* Description: GPIO��ӳ������;
* 
* Input:  none;
*
* Output: none;
*          		
* Return: none;
*
* Note:   none;
************************************************************************************/
void GPIO_RemapConfig(void)
{
	GPIO_PinRemapConfig(GPIO_Remap_USART1, ENABLE);								// USART1��ӳ��	
	GPIO_PinRemapConfig(GPIO_Remap_SPI1, ENABLE);								// SPI1��ӳ��
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);					// ��ֹJTAG	
}

 /***********************************************************************************
* Function: RCC_Configuration;
*
* Description: RCCʱ������;
* 
* Input:  none;
*
* Output: none;
*          		
* Return: none;
*
* Note:   none;
************************************************************************************/
void RCC_Configuration(void)
{   
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_AFIO,  ENABLE);  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,  ENABLE);  	// ʹ��SPI1ʱ��
	
}
 /***********************************************************************************
* Function: GPIO_Configuration;
*
* Description: GPIO��ʼ������;
* 
* Input:  none;
*
* Output: none;
*          		
* Return: none;
*
* Note:   none;
************************************************************************************/
void GPIO_Configuration(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
 
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB| \
	RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOE, ENABLE);	

    GPIO_InitStructure.GPIO_Pin = IO_LED;				    // LED(RUN) ����Ϊͨ���������  
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		// �������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// ��ת�ٶ�Ϊ50MHz
    GPIO_Init(GPIOB, &GPIO_InitStructure);					 
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;     	// �����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// ��ת�ٶ�50MHZ
	GPIO_InitStructure.GPIO_Pin = IO_TXD1;	         	    // USART1  TX
	GPIO_Init(GPIOB, &GPIO_InitStructure);	

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 	// ��������
	GPIO_InitStructure.GPIO_Pin = IO_RXD1;	           		// USART1 RX
	GPIO_Init(GPIOB, &GPIO_InitStructure);		
	
	GPIO_InitStructure.GPIO_Pin = IO_SCLK | IO_MOSI | IO_MISO;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;								// ����Ϊ�����������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_SetBits(GPIOB, IO_SCLK);
	GPIO_SetBits(GPIOB, IO_MOSI);
	
	// DIN1-DIN8
    GPIO_InitStructure.GPIO_Pin = IO_DIN1|IO_DIN2|IO_DIN3|IO_DIN4|IO_DIN5|IO_DIN6|IO_DIN7|IO_DIN8;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;						// ���ø�������
    GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = IO_H595OE;				      
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
    GPIO_Init(GPIOD, &GPIO_InitStructure);
	GPIO_SetBits(GPIOD,IO_H595OE);												// �ر�595���ʹ��
	
	GPIO_InitStructure.GPIO_Pin = IO_H595LCK;				      
    GPIO_Init(GPIOC, &GPIO_InitStructure);
	

}

 /***********************************************************************************
* Function: USART_Configuration;
*
* Description: USART��ʼ������;
* 
* Input:  USARTx: USART1-USAET3,UART4,UART5;
*
* Output: none;
*          		
* Return: none;
*
* Note:   none;
************************************************************************************/
void USART_Configuration(USART_TypeDef* USARTx)
{
    USART_InitTypeDef USART_InitStructure;
	
	USART_InitStructure.USART_BaudRate = 115200;					//������115200
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;		//����λ8λ
    USART_InitStructure.USART_StopBits = USART_StopBits_1;			//ֹͣλ1λ
    USART_InitStructure.USART_Parity = USART_Parity_No;				//��У��λ
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;   //��Ӳ������
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
    USART_Init(USARTx, &USART_InitStructure);						//���ô��ڲ�������
  
    USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE);                  //ʹ�ܽ����ж�
    //USART_ITConfig(USARTx, USART_IT_TXE, ENABLE);					//ʹ�ܷ��ͻ�����ж�
    //USART_ITConfig(USARTx, USART_IT_TC, ENABLE);					//ʹ�ܷ�������ж�
    USART_Cmd(USARTx, ENABLE);	 // ʹ��USARTx 	
 }

/***********************************************************************************
* Function: Led_Ctrl;
*
* Description: Led�������;
* 
* Input:  Cmd,  Led��������: LED_ON, LED��;
*				LED_OFF, LED�ر�;
*				LED_NEG, LEDȡ��;	
*
* Output: none;
*          		
* Return: none;
*
* Note:   none;
************************************************************************************/
void Led_Ctrl(uint8_t Cmd)
{
	switch (Cmd)
	{
		case LED_ON:												
			GPIO_SetBits(GPIOB, IO_LED);		 						
			break;		
		case LED_OFF:
			GPIO_ResetBits(GPIOB, IO_LED);		 	 
			break;	
		case LED_NEG:
			if (GPIO_ReadOutputDataBit(GPIOB, IO_LED) == Bit_SET)		// �ж����IO�Ƿ�Ϊ�ߵ�ƽ
			{
				GPIO_ResetBits(GPIOB, IO_LED);		 	
			}
			else
			{
				GPIO_SetBits(GPIOB, IO_LED);		 	  
			}
			break;
		default:
			break;
	}
}
 void SPI1_Init(void)
{
	SPI_InitTypeDef  SPI_InitStructure;
	
	SPI_Cmd(SPI1, DISABLE);														// ��ֹSPI1

	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;		  	// ����SPI�������˫�������ģʽ:SPI����Ϊ˫��˫��ȫ˫��
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;								// ����SPI����ģʽ:����Ϊ��SPI
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;							// ����SPI�����ݴ�С:SPI���ͽ���8λ֡�ṹ
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;									// ѡ���˴���ʱ�ӵ���̬:ʱ�����ո�
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;								// ���ݲ����ڵڶ���ʱ����
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;				   					// NSS�ź���Ӳ����NSS�ܽţ����������ʹ��SSIλ������:�ڲ�NSS�ź���SSIλ����
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32; 		// ���岨����Ԥ��Ƶ��ֵ:������Ԥ��ƵֵΪ32
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;							// ָ�����ݴ����MSBλ����LSBλ��ʼ:���ݴ����MSBλ��ʼ
	SPI_InitStructure.SPI_CRCPolynomial = 7;			   						// CRCֵ����Ķ���ʽ
	SPI_Init(SPI1, &SPI_InitStructure);			   								// ����SPI_InitStruct��ָ���Ĳ�����ʼ������SPIx�Ĵ���
	
	SPI_Cmd(SPI1, ENABLE);														// ʹ��SPI1
}
 
/***********************************************************************************
* Function: SPI_ReadWriteByte;
*
* Description: SPI1����һ������, �����ض�ȡ��������;
*           
* Input:  data: ���͵�����;
*
* Output: none;
*          		
* Return: ���ؽ��յ�������;
*
* Note:   none;
*      		
************************************************************************************/
uint16_t SPI_ReadWriteByte(uint8_t data)
{
	uint8_t retry = 0;   
	/* Loop while DR register in not emplty */
    while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET)
   	{
		retry++;
  		if(retry>200) return 0;
	}
    /* Send byte through the SPI1 peripheral */
    SPI_I2S_SendData(SPI1, data);

   retry = 0; 
   while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET)
   {
   	    retry++;
		if(retry>200) return 0;
   }     
   /* Return the byte read from the SPI bus */
   return SPI_I2S_ReceiveData(SPI1);
}


/***********************************************************************************
* Function: DOUT_Write;
*
* Description: ��������е�����;
*           
* Input:  none;
*
* Output: none;
*          		
* Return: ���ؽ��յ�������;
*
* Note:  none;

************************************************************************************/
void DOUT_Write(uint8_t val)							// Function used for control DOUT (val == address)
{
	SPI_ReadWriteByte(val);			// SPIд����ֵ
	// ��λ�������IO
	GPIO_ResetBits(GPIOC,IO_H595LCK);
	Delay_us(1);
	GPIO_SetBits(GPIOC,IO_H595LCK);
}

/***********************************************************************************
* Function: DOUT_Test;
*
* Description: ������Ժ���;
*           
* Input:  none;
*
* Output: none;
*          		
* Return: none;
*
* Note:   none;
*      		
************************************************************************************/
void DOUT_Test(void)
{
	static uint8_t DoutVal = 0x02;
	
	DOUT_Write(DoutVal);								
	DoutVal ^= 0x02;							// ȡ��
}

/***********************************************************************************
* Function: DIN_Test;
*
* Description: ������Ժ���;
*           
* Input:  none;
*
* Output: none;
*          		
* Return: none;
*
* Note:   none;
*      		
************************************************************************************/
//******************************GPIO INPUT TESTING******************************
void DIN_Test(void)
{
    static uint8_t DIValue = 0;
	uint8_t val;

//  DIN1
	val = GPIO_ReadInputDataBit(GPIOE, IO_DIN1);
	if (val)
	{
	    if ((DIValue&0x01)==0)		// Detect DI1
		{ 
			DIValue |= 0x01;
			DOUT_Write(0x36);					// Turn ON LED (D01&D04) [Summer]
			printf("DI1 = 0\r\n");
		}
	}
	else
	{
		if (DIValue&0x01)
		{
			DIValue &= ~0x01;
			DOUT_Write(0x3F);					// Turn OFF LED (D01&D04) [Summer]
			printf("DI1 = 1\r\n");
		}
	}

//  DIN2
	val = GPIO_ReadInputDataBit(GPIOE, IO_DIN2);
	if (val)
	{
	    if ((DIValue&0x02)==0)		// Detect DI2
		{ 
			DIValue |= 0x02;
			printf("DI2 = 0\r\n");
		}
	}
	else
	{
		if (DIValue&0x02)
		{
			DIValue &= ~0x02;
			printf("DI2 = 1\r\n");
		}
	}

//  DIN3
	val = GPIO_ReadInputDataBit(GPIOE, IO_DIN3);
	if (val)
	{
	    if ((DIValue&0x04)==0)		// Detect DI3
		{ 
			DIValue |= 0x04;
			DOUT_Write(0x2D);				// Turn ON LED (D02&D05) [Summer]
			printf("DI3 = 0\r\n");
		}
	}
	else
	{
		if (DIValue&0x04)
		{
			DIValue &= ~0x04;
			DOUT_Write(0x3F);				// Turn OFF LED (D02&D05) [Summer]
			printf("DI3 = 1, ON\r\n");
		}
	}

//  DIN4
	val = GPIO_ReadInputDataBit(GPIOE, IO_DIN4);
	if (val)
	{
	    if ((DIValue&0x08)==0)		// Detect DI4
		{ 
			DIValue |= 0x08;
			printf("DI4 = 0\r\n");
		}
	}
	else
	{
		if (DIValue&0x08)
		{
			DIValue &= ~0x08;
			printf("DI4 = 1\r\n");
		}
	}

//  DIN5
	val = GPIO_ReadInputDataBit(GPIOE, IO_DIN5);
	if (val)
	{
	    if ((DIValue&0x10)==0)		// Detect DI5
		{ 
			DIValue |= 0x10;
			DOUT_Write(0x1B);					// Turn ON LED (D03&D06) [Summer]
			printf("DI5 = 0\r\n");
		}
	}
	else
	{
		if (DIValue&0x10)
		{
			DIValue &= ~0x10;
			DOUT_Write(0x3F);					// Turn OFF LED (D03&D06) [Summer]
			printf("DI5 = 1\r\n");
		}
	}

//  DIN6
	val = GPIO_ReadInputDataBit(GPIOE, IO_DIN6);
	if (val)
	{
	    if ((DIValue&0x20)==0)		// Detect DI6
		{ 
			DIValue |= 0x20;
			printf("DI6 = 0\r\n");
		}
	}
	else
	{
		if (DIValue&0x20)
		{
			DIValue &= ~0x20;
			printf("DI6 = 1\r\n");
		}
	}

//  DIN7
	val = GPIO_ReadInputDataBit(GPIOE, IO_DIN7);
	if (val)
	{
	    if ((DIValue&0x40)==0)		// Detect DI7
		{ 
			DIValue |= 0x40;
			DOUT_Write(0x00);					// Turn ON ALL LED  [Summer]
			printf("DI7 = 0\r\n");
		}
	}
	else
	{
		if (DIValue&0x40)
		{
			DIValue &= ~0x40;
			DOUT_Write(0x3F);					// Turn OFF ALL LED [Summer]
			printf("DI7 = 1\r\n");
		}
	}

//  DIN8
	val = GPIO_ReadInputDataBit(GPIOE, IO_DIN8);
	if (val)
	{
	    if ((DIValue&0x80)==0)		// Detect DI8
		{ 
			DIValue |= 0x80;
			printf("DI8 = 0\r\n");
		}
	}
	else
	{
		if (DIValue&0x80)
		{
			DIValue &= ~0x80;
			printf("DI8 = 1\r\n");
		}
	}	

}

int main(void)
{	
	uint32_t cnt = 0;
	static uint8_t GPIOon = 0xFF;
	static uint8_t GPIOoff = 0x00;
	static uint16_t GPIOTest = 0x02;
	int count = 0;
	
	RCC_Configuration();						// RCC����	
	GPIO_Configuration();						// GPIO����	
	GPIO_RemapConfig();							// GPIO��ӳ��
	NVIC_Configuration();						// NVIC����

	USART_Configuration(USART1);				// USART1��ʼ��
	SPI1_Init();							    // SPI1��ʼ��
	GPIO_ResetBits(GPIOD,IO_H595OE);			// ʹ��595���
	GPIO_ResetBits(GPIOC,IO_H595LCK);
	//GPIO_SetBits(GPIOD,GPIO_Pin_All);
	//GPIO_WriteBit(GPIOD,GPIO_Pin_4,0);
	//DOUT_Write(GPIOTest);
	DOUT_Write(0x3F);					// Turn OFF LED (D01-D06) [Summer]
	while (1)
	{		
		Delay_ms(20);							// ��ʱ20ms
		//DIN_Test();								// �������
		/**********************GPIO Output Testing**********************
		cnt++;	
		
		if ((cnt%50)==0)						// ÿ��1��
		{
			Led_Ctrl(LED_NEG);					// ��תLED�� Controlling onboard "RUN" LED
			
			if(count%4 == 0){
				//DOUT_Write(0x36);					// Turn ON LED (D01&D04) [Summer]	
				DOUT_Write(0x36);					// Turn ON LED (D01&D04) [Summer]					
				count++;
			}
			else if(count%4 == 1){
				//DOUT_Write(0x2D);				// Turn ON LED (D02&D05) [Summer]
				DOUT_Write(0x2D);				// Turn ON LED (D02&D05) [Summer]
				count++;
			}
			else if(count%4 == 2){
				//DOUT_Write(0x1B);					// Turn ON LED (D03&D06) [Summer]
				DOUT_Write(0x1B);					// Turn ON LED (D03&D06) [Summer]
				count++;
			}
			else if(count%4 == 3){
				DOUT_Write(0x3F);				// Turn OFF ALL LED [Summer]
				count++;
			}
			
			//DOUT_Write(GPIOon);
		}
		if ((cnt%150)==0)						// ÿ��3��
		{
			//DOUT_Test();						// �������
			
			//DOUT_Write(GPIOoff);
		}
		*/
		
	}
	
}


#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
