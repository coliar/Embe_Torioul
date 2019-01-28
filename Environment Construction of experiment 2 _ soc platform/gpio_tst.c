/*
 * gpio_tst.c
 *
 *  Created on: 2018��1��25��
 *      Author: Administrator
 *      Function:8��LEDʵ����ˮ�ƣ����ϲ�������һ�����뿪��ʱ����ˮ�����е����һ��LD7ʱֹͣ
 */



#include"xparameters.h"
#include"xgpio.h"
#include"xil_printf.h"//���������Ҫ�õ�
#include"xil_cache.h"

#define GPIO_BITWIDTH 8
#define GPIO_LED_DEVICE_ID 0
#define GPIO_SW_DEVICE_ID 1
#define LED_DELAY 10000000  //�򵥵���ʱ�����궨��
#define LED_MAX_BLINK 0x1 //��˸����
#define LED_CHANNEL 1
#define printf xil_printf

XGpio GpioOutput;
XGpio GpioInput;
u32 flag=0;
u32 DataRead;

int Gpio_led(u16 Deviceid,u32 Gpio_Width)
{
	volatile int delay;
	u32 Ledbit;
	u32 Ledloop;
	int status;
	status=XGpio_Initialize(&GpioOutput,Deviceid);
	if(status !=XST_SUCCESS)
	{
		return XST_FAILURE;
	}
	XGpio_SetDataDirection(&GpioOutput,LED_CHANNEL,0x0);
	for(Ledbit =0x0;Ledbit < Gpio_Width;Ledbit++)
	{
		for(Ledloop=0x0;Ledloop<LED_MAX_BLINK;Ledloop++)
		{
			XGpio_DiscreteWrite(&GpioOutput,LED_CHANNEL,1<<Ledbit);
			for(delay=0;delay<LED_DELAY;delay++);
			XGpio_DiscreteClear(&GpioOutput,LED_CHANNEL,0x00);
			for(delay=0;delay<LED_DELAY;delay++);
		}
	}
	return XST_SUCCESS;
}

u32 Gpio_sw(u16 Deviceid,u32 *DataRead)
{
	int Status;
    Status = XGpio_Initialize(&GpioInput, Deviceid);
	if (Status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}
	XGpio_SetDataDirection(&GpioInput, LED_CHANNEL, 0xFFFFFFFF);
	*DataRead = XGpio_DiscreteRead(&GpioInput, LED_CHANNEL);

	u32 data;
	data=*DataRead;
    return data;
}

int main()
{
	while(1)
	{
		flag =Gpio_sw(GPIO_SW_DEVICE_ID, &DataRead);
	    if(flag == 0)
	    {
			u32 status;
		    status = Gpio_led(GPIO_LED_DEVICE_ID,GPIO_BITWIDTH);
		    if(status==0)
		    {
		    	printf("SUCCESS.\r\n");
		    }
		    else
			    printf("FAIL.\r\n");
	    }
	    else
	    {
	    	u32 Ledbit;
		    for(Ledbit =0x0;Ledbit < GPIO_BITWIDTH;Ledbit++)
		    	XGpio_DiscreteClear(&GpioOutput,LED_CHANNEL,0x00);
	    }
	}
}

