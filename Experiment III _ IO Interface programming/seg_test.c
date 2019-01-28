/*
 * seg_test.c
 *
 *  Created on: 2018��1��29��
 *      Author: Administrator
 */


#include"xparameters.h"
#include"xgpio.h"
#include"xil_cache.h"

//�豸ID
#define GPIO_SEG_W_DEVICE_ID 1
#define GPIO_SW_DEVICE_ID 2
#define GPIO_SEG_D_DEVICE_ID 0
//ͨ����
#define SEG_CHANNEL 1

//ָ���豸��ָ��
XGpio GpioOutput0; //λѡ��Ӧ�Ĵ���
XGpio GpioOutput1; //��ѡ��Ӧ�Ĵ���
XGpio GpioInput;//������Ӧ�Ĵ���

u32 flag=0;
u32 DataRead;

int Gpio_w_seg(u16 Deviceid)λѡ
{
	int w;
	int status;
	/*�벹ȫ���룬��w��ֵ*/
	w=0x00          ;��Ҫд��InstancePtrָ��Ĵ�����ֵ
	status=XGpio_Initialize(&GpioOutput0,Deviceid);ʵ��X_GPIO�豸�ĳ�ʼ��
		if(status !=XST_SUCCESS)	;������ɹ�����ʾʧ��
		{
			return XST_FAILURE;
		}
	XGpio_SetDataDirection(&GpioOutput0,SEG_CHANNEL,0x0);ͨ�������ݷ�����趨��1orO��
    XGpio_DiscreteWrite(&GpioOutput0,SEG_CHANNEL,w);��ȡGPIO��ֵ

	return XST_SUCCESS;
}

int Gpio_d_seg(u16 Deviceid,u32 data)����ĸ�����ܵĶ�ѡ
{

	u32 a;
	int status;
	status=XGpio_Initialize(&GpioOutput1,Deviceid);
		if(status !=XST_SUCCESS)
		{
			return XST_FAILURE;
		}
	/*����GPIOΪ���*/

XGpio_SetDataDirection(&GpioOutput0,SEG_CHANNEL,0x0);

	switch(data)
	{
	    case 0 :a=0x3f;
	            break;
	    /*��ȫ���´��룬����dataΪ1~9ʱ��Ӧ�������ֵ*/
	    case 1 :a=0x06;
	            break;
	    case 2 :a=0x5b;
	            break;
	    case 3 :a=0x4f;
	            break;
	    case 4 :a=0x66;
	            break;
	    case 5 :a=0x6d;
	            break;
	    case 6 :a=0x7d;
	            break;
	    case 7 :a=0x07;
	            break;
	    case 8 :a=0x7f;
	            break;
	    case 9 :a=0x6f;
	            break;
	  

	}
    /*������ܼĴ�����д��ֵ*/

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
	/*��ȫ���룬��ȡ�����ذ�����ֵ*/
DataRead=XGpio_DiscreteWrite(&GpioOutput,SEG_CHANNEL);��ȡInstancePtrָ��ָ��ļĴ�����ֵ���ض�ȡ����ֵ
u32 data;
data=DataRead;
return data;

}

void main()
{
	while(1)
	{
		flag =Gpio_sw(GPIO_SW_DEVICE_ID,&DataRead);
		Gpio_w_seg(GPIO_SEG_W_DEVICE_ID);
	    if(flag < 10)
	    {
		     Gpio_d_seg(GPIO_SEG_D_DEVICE_ID,flag);

	   }
	   else
	   {
		   /*��ȫ���룬ʹ����ܲ���ʾ*/
XGpio_Initialize(&GpioOutput0,GPIO_SEG_W_DEVICE_ID);
XGpio_SetDataDirection(&GpioOutput0,SEG_CHANNEL,0x0);
XGpio_DiscreteWrite(&GpioOutput0,SEG_CHANNEL,0x0000);
	    }
	}
}

