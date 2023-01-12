/*************************************************************************************/
#ifndef EMB8618I_IOCONFIG_H 
#define EMB8618I_IOCONFIG_H 

/************************************************************************************/
//  EMB8618I 硬件版本
/************************************************************************************/
#define   HW_VERSION	104
/************************************************************************************/
// PWM使能定义
#define   PWM1_EN		1			// 1,使能,J11的2和3脚需短接; 0,关闭使能
#define   PWM2_EN		1			// 1,使能,J10的2和3脚需短接; 0,关闭使能
#define   PWM3_EN		1			// 1,使能,J12的2和3脚需短接; 0,关闭使能
#define   PWM4_EN		1			// 1,使能; 0,关闭使能

// FCLK使能定义
#define   FCLK1_EN		0			// 1,使能,J11的1和2脚需短接; 0,关闭使能
#define   FCLK2_EN		0			// 1,使能,J10的1和2脚需短接; 0,关闭使能
#define   FCLK3_EN		0			// 1,使能,J12的1和2脚需短接; 0,关闭使能
/************************************************************************************/
//  EMB8616I IO输入输出定义
/************************************************************************************/
// LED IO端口定义
#define IO_LED      GPIO_Pin_2   // PB2, 运行LED指示灯 

// ALARM IO端口定义
#define IO_ALARM    GPIO_Pin_15   // PB15, 蜂鸣器控制IO

// ADC IO端口定义(JP2)
#define IO_ADC2     GPIO_Pin_3   // PA3
#define IO_ADC3     GPIO_Pin_6	 // PA6
#define IO_ADC4     GPIO_Pin_0 	 // PB0
#define IO_ADC5     GPIO_Pin_1 	 // PB1
#define IO_ADC6     GPIO_Pin_0 	 // PC0
#define IO_ADC7     GPIO_Pin_2	 // PC2

// DAC输出IO端口定义(JP4)
#define IO_DAC1     GPIO_Pin_4   // PA4
#define IO_DAC2     GPIO_Pin_5   // PA5	  

// UART1~UART5 IO定义(JP14, JP15, JP5, JP6)
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

// UART3转成RS485 方向控制IO定义
#define IO_DIR3     GPIO_Pin_14	 // PB14, UART3转成RS485方向控制IO
// UART4转成RS485 方向 控制IO定义
#define IO_DIR4     GPIO_Pin_3	 // PD3, UART4转成RS485方向控制IO

// CAN1占用IO定义(JP14)
#define IO_CAN1RX   GPIO_Pin_0   // PD0 
#define IO_CAN1TX   GPIO_Pin_1	 // PD1

// EEPROM IO定义					   
#define IO_SCL 		GPIO_Pin_8	 // PB8
#define IO_SDA  	GPIO_Pin_9	 // PB9

// 脉冲FCLK输入(JP20, JP21, JP24)
// JP20  FCLK1 J11的1和2脚需短接
#if((FCLK1_EN==1)&&(PWM1_EN==0))
#define IO_FCLK1FA  GPIO_Pin_9	 // PE9,FA+, FA-
#define IO_FCLK1FB  GPIO_Pin_11	 // PE11,FB+, FB-
#endif
// JP21  FCLK2 J10的1和2脚需短接
#if((FCLK2_EN==1)&&(PWM2_EN==0))
#define IO_FCLK2FA  GPIO_Pin_6	 // PC6,FA+, FA-
#define IO_FCLK2FB  GPIO_Pin_7	 // PC7,FB+, FB-
#endif
// JP24  FCLK3 J12的1和2脚需短接
#if((FCLK3_EN==1)&&(PWM3_EN==0))
#define IO_FCLK3FA  GPIO_Pin_12	 // PD12,FA+, FA-
#define IO_FCLK3FB  GPIO_Pin_13	 // PD13,FB+, FB-
#endif

// PWM输出(JP7, JP8, JP11, JP12)
// JP7  PWM1 J11的2和3脚需短接
#if((PWM1_EN==1)&&(FCLK1_EN==0))
#define IO_PWM1PUL  GPIO_Pin_9	 // PE9,  PWM1输出IO
#define IO_PWM1DIR 	GPIO_Pin_11	 // PE11, 方向控制IO
#define IO_PWM1EN   GPIO_Pin_13	 // PE13,  使能IO
#define IO_PWM1FT   GPIO_Pin_8	 // PE8,  使能IO
#endif
// JP8  PWM2 J10的2和3脚需短接
#if((PWM2_EN==1)&&(FCLK2_EN==0))
#define IO_PWM2PUL  GPIO_Pin_6	 // PC6,  PWM2输出IO
#define IO_PWM2DIR 	GPIO_Pin_7	 // PC7,  方向控制IO
#define IO_PWM2EN   GPIO_Pin_8	 // PC8,  使能IO
#define IO_PWM2FT   GPIO_Pin_9	 // PC9,  使能IO
#endif
// JP11  PWM3 J12的2和3脚需短接
#if((PWM3_EN==1)&&(FCLK3_EN==0))
#define IO_PWM3PUL  GPIO_Pin_12	 // PD12,  PWM3输出IO
#define IO_PWM3DIR 	GPIO_Pin_13	 // PD13,  方向控制IO
#define IO_PWM3EN   GPIO_Pin_8	 // PC8,  使能IO
#define IO_PWM3FT   GPIO_Pin_9	 // PC9,  使能IO
#endif
// JP12  PWM4
#if(PWM4_EN==1)
#define IO_PWM4PUL  GPIO_Pin_12	 // PA0,  PWM4输出IO
#if(HW_VERSION>=104)
#define IO_PWM4DIR 	GPIO_Pin_10	 // PB10,  方向控制IO
#else
#define IO_PWM4DIR 	GPIO_Pin_3	 // PA3,  方向控制IO
#endif
#define IO_PWM4EN   GPIO_Pin_14	 // PE14,  使能IO
#define IO_PWM4FT   GPIO_Pin_12	 // PE12,  使能IO
#endif

// SPI IO配置
#define IO_SCLK     GPIO_Pin_3   // PB3	
#define IO_MISO     GPIO_Pin_4   // PB4
#define IO_MOSI     GPIO_Pin_5   // PB5

// SPI FLASH片选
#define IO_SPIFLASH_CS GPIO_Pin_15 // PA15

// 输入端口(JP9 JP10)
#define IO_DIN1     GPIO_Pin_0	 // PE0
#define IO_DIN2     GPIO_Pin_1	 // PE1
#define IO_DIN3     GPIO_Pin_2	 // PE2
#define IO_DIN4     GPIO_Pin_3	 // PE3
#define IO_DIN5     GPIO_Pin_4	 // PE4
#define IO_DIN6     GPIO_Pin_5	 // PE5
#define IO_DIN7     GPIO_Pin_6	 // PE6
#define IO_DIN8     GPIO_Pin_7	 // PE7

// 74HC595输出控制IO
#define IO_H595OE	GPIO_Pin_4	 // PD4
#define IO_H595LCK	GPIO_Pin_3	 // PC3

// LCD接口定义
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
// 文件结束
/***********************************************************************************/
