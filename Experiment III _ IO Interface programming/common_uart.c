/*
 * common.c
 *
 *  Created on: 2017��8��17��
 *      Author: EES_AE_02
 */

#include "xparameters.h"
#include "xil_printf.h"
#include "sleep.h"
#include <stdio.h>
#include "xil_io.h"

#define uart_bas_addr  0x42c00000
#define uart_rxd_addr  0x42c00000//�������������ַ
#define uart_txd_addr  0x42c00004//�������������ַ
#define uart_stat_addr 0x42c00008 // ����״̬�Ĵ���
#define uart_ctrl_addr 0x42c0000c


int main()
{
	while(1)
    {	 /*��ȫ���룬�����ַ����ش��������յ��ַ�xʱ�˳�����*/						
	static int a;
	if((Xil_In8(uart_stst_addr))&0x01==1)//�жϴ���״̬�Ĵ��������λ�Ƿ�Ϊ1
{
	a=Xil_In8(uart_txd_addr, a);//��Ϊ1�����մ������ݣ�������һ������
	if(a=='x')//�����յ������ݻش�
        {
	    break;//�жϽ��յ��������Ƿ�λ��x�������ǣ�����whileѭ��
        }
}						
											                          

    }
    return 0;
}




