/*************************************************************************************/
#ifndef EMB8618I_IOCONFIG_H 
#define EMB8618I_IOCONFIG_H 

/************************************************************************************/
//  EMB8618I Ӳ���汾
/************************************************************************************/
#define   HW_VERSION	104
/************************************************************************************/
// PWMʹ�ܶ���
#define   PWM1_EN		1			// 1,ʹ��,J11��2��3����̽�; 0,�ر�ʹ��
#define   PWM2_EN		1			// 1,ʹ��,J10��2��3����̽�; 0,�ر�ʹ��
#define   PWM3_EN		1			// 1,ʹ��,J12��2��3����̽�; 0,�ر�ʹ��
#define   PWM4_EN		1			// 1,ʹ��; 0,�ر�ʹ��

// FCLKʹ�ܶ���
#define   FCLK1_EN		0			// 1,ʹ��,J11��1��2����̽�; 0,�ر�ʹ��
#define   FCLK2_EN		0			// 1,ʹ��,J10��1��2����̽�; 0,�ر�ʹ��
#define   FCLK3_EN		0			// 1,ʹ��,J12��1��2����̽�; 0,�ر�ʹ��
/************************************************************************************/
//  EMB8616I IO�����������
/************************************************************************************/
// LED IO�˿ڶ���
#define IO_LED      GPIO_Pin_2   // PB2, ����LEDָʾ�� 

// ALARM IO�˿ڶ���
#define IO_ALARM    GPIO_Pin_15   // PB15, ����������IO

// ADC IO�˿ڶ���(JP2)
#define IO_ADC2     GPIO_Pin_3   // PA3
#define IO_ADC3     GPIO_Pin_6	 // PA6
#define IO_ADC4     GPIO_Pin_0 	 // PB0
#define IO_ADC5     GPIO_Pin_1 	 // PB1
#define IO_ADC6     GPIO_Pin_0 	 // PC0
#define IO_ADC7     GPIO_Pin_2	 // PC2

// DAC���IO�˿ڶ���(JP4)
#define IO_DAC1     GPIO_Pin_4   // PA4
#define IO_DAC2     GPIO_Pin_5   // PA5	  

// UART1~UART5 IO����(JP14, JP15, JP5, JP6)
// JP15: RS232-1,RS233-2
#define IO_TXD1     GPIO_Pin_6	 // PB6
#define IO_RXD1     GPIO_Pin_7	 // PB7
#define IO_TXD2     GPIO_Pin_5	 // PD5
#define IO_RXD2     GPIO_Pin_6	 // PD6
// JP14  RS485
#define IO_TXD3     GPIO_Pin_8	 // PD8
#define IO_RXD3     GPIO_Pin_9	 // PD9
// JP15  RS485
#define IO_TXD4     GPIO_Pin_10	 // PC10
#define IO_RXD4     GPIO_Pin_11	 // PC11
// JP19  TTL
#define IO_TXD5     GPIO_Pin_12	 // PC12
#define IO_RXD5     GPIO_Pin_2	 // PD2

// UART3ת��RS485 �������IO����
#define IO_DIR3     GPIO_Pin_14	 // PB14, UART3ת��RS485�������IO
// UART4ת��RS485 ���� ����IO����
#define IO_DIR4     GPIO_Pin_3	 // PD3, UART4ת��RS485�������IO

// CAN1ռ��IO����(JP14)
#define IO_CAN1RX   GPIO_Pin_0   // PD0 
#define IO_CAN1TX   GPIO_Pin_1	 // PD1

// EEPROM IO����					   
#define IO_SCL 		GPIO_Pin_8	 // PB8
#define IO_SDA  	GPIO_Pin_9	 // PB9

// ����FCLK����(JP20, JP21, JP24)
// JP20  FCLK1 J11��1��2����̽�
#if((FCLK1_EN==1)&&(PWM1_EN==0))
#define IO_FCLK1FA  GPIO_Pin_9	 // PE9,FA+, FA-
#define IO_FCLK1FB  GPIO_Pin_11	 // PE11,FB+, FB-
#endif
// JP21  FCLK2 J10��1��2����̽�
#if((FCLK2_EN==1)&&(PWM2_EN==0))
#define IO_FCLK2FA  GPIO_Pin_6	 // PC6,FA+, FA-
#define IO_FCLK2FB  GPIO_Pin_7	 // PC7,FB+, FB-
#endif
// JP24  FCLK3 J12��1��2����̽�
#if((FCLK3_EN==1)&&(PWM3_EN==0))
#define IO_FCLK3FA  GPIO_Pin_12	 // PD12,FA+, FA-
#define IO_FCLK3FB  GPIO_Pin_13	 // PD13,FB+, FB-
#endif

// PWM���(JP7, JP8, JP11, JP12)
// JP7  PWM1 J11��2��3����̽�
#if((PWM1_EN==1)&&(FCLK1_EN==0))
#define IO_PWM1PUL  GPIO_Pin_9	 // PE9,  PWM1���IO
#define IO_PWM1DIR 	GPIO_Pin_11	 // PE11, �������IO
#define IO_PWM1EN   GPIO_Pin_13	 // PE13,  ʹ��IO
#define IO_PWM1FT   GPIO_Pin_8	 // PE8,  ʹ��IO
#endif
// JP8  PWM2 J10��2��3����̽�
#if((PWM2_EN==1)&&(FCLK2_EN==0))
#define IO_PWM2PUL  GPIO_Pin_6	 // PC6,  PWM2���IO
#define IO_PWM2DIR 	GPIO_Pin_7	 // PC7,  �������IO
#define IO_PWM2EN   GPIO_Pin_8	 // PC8,  ʹ��IO
#define IO_PWM2FT   GPIO_Pin_9	 // PC9,  ʹ��IO
#endif
// JP11  PWM3 J12��2��3����̽�
#if((PWM3_EN==1)&&(FCLK3_EN==0))
#define IO_PWM3PUL  GPIO_Pin_12	 // PD12,  PWM3���IO
#define IO_PWM3DIR 	GPIO_Pin_13	 // PD13,  �������IO
#define IO_PWM3EN   GPIO_Pin_8	 // PC8,  ʹ��IO
#define IO_PWM3FT   GPIO_Pin_9	 // PC9,  ʹ��IO
#endif
// JP12  PWM4
#if(PWM4_EN==1)
#define IO_PWM4PUL  GPIO_Pin_12	 // PA0,  PWM4���IO
#if(HW_VERSION>=104)
#define IO_PWM4DIR 	GPIO_Pin_10	 // PB10,  �������IO
#else
#define IO_PWM4DIR 	GPIO_Pin_3	 // PA3,  �������IO
#endif
#define IO_PWM4EN   GPIO_Pin_14	 // PE14,  ʹ��IO
#define IO_PWM4FT   GPIO_Pin_12	 // PE12,  ʹ��IO
#endif

// SPI IO����
#define IO_SCLK     GPIO_Pin_3   // PB3	
#define IO_MISO     GPIO_Pin_4   // PB4
#define IO_MOSI     GPIO_Pin_5   // PB5

// SPI FLASHƬѡ
#define IO_SPIFLASH_CS GPIO_Pin_15 // PA15

// ����˿�(JP9 JP10)
#define IO_DIN1     GPIO_Pin_0	 // PE0
#define IO_DIN2     GPIO_Pin_1	 // PE1
#define IO_DIN3     GPIO_Pin_2	 // PE2
#define IO_DIN4     GPIO_Pin_3	 // PE3
#define IO_DIN5     GPIO_Pin_4	 // PE4
#define IO_DIN6     GPIO_Pin_5	 // PE5
#define IO_DIN7     GPIO_Pin_6	 // PE6
#define IO_DIN8     GPIO_Pin_7	 // PE7

// 74HC595�������IO
#define IO_H595OE	GPIO_Pin_4	 // PD4
#define IO_H595LCK	GPIO_Pin_3	 // PC3

// LCD�ӿڶ���
#define IO_LCDRS   GPIO_Pin_9	 // PA9
#define IO_LCDE    GPIO_Pin_11	 // PA11
#define IO_LCDRW   GPIO_Pin_12	 // PA12
#define IO_LCDCS1  GPIO_Pin_11	 // PD11
#define IO_LCDCS2  GPIO_Pin_10	 // PD10
#if (HW_VERSION>=104)  
#define IO_LCDPWR  GPIO_Pin_15	 // PE15
#endif

#if (HW_VERSION<=102)   
#define IO_KEYSCL  GPIO_Pin_10	 // PB10
#define IO_KEYSDA  GPIO_Pin_15	 // PE15
#endif
#define IO_KEYINT  GPIO_Pin_10	 // PE10
#endif

/***********************************************************************************/
// �ļ�����
/***********************************************************************************/
