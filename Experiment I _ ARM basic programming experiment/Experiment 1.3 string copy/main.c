/****************************************
�ļ�����main.c
���ܣ�����ַ����Ŀ���

****************************************/
#include <stdio.h>

extern void strcopy(char *d ,char *s);

int main(void)
{
	char *srcstr = "aaaa";
	char dststr[] = "bbbb";
	
	//printf("Before copying:\n");				�������ʱ����printf���
	//printf(" %s %s\n",srcstr,dststr);
	
	strcopy(dststr,srcstr);
	
	//printf("After copying: \n");
	//printf(" %s\n  %s\n",srcstr,dststr);
	
	return (0);

}

