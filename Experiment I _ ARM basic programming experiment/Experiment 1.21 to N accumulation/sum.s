;���ܣ�����1+2+3+4+...+N
;˵����N>=0,��N=0ʱ���Ϊ0����N=1ʱ���Ϊ1

N EQU 100   ;����N��ֵ100
	AREA Examples,CODE,READONLY   ;���������Examples3
	ENTRY   ;��ʶ������� 
	
	CODE32
ARM_CODE

	LDR SP,=0X30003F00    ;���ö�ջָ��
	ADR R0,THUMB_CODE+1    ;
	BX R0       ;��ת���л�������״̬
	LTORG       ;�������ֳ�

	CODE16
THUMB_CODE

	LDR R0,=N      ;�����ӳ���SUM_N����ڲ���
	BL SUM_N      ;�����ӳ���SUM_N
	B THUMB_CODE 

;SUM_N
;���ܣ�����1+2+3+......+N
;��ڲ�����R0 N��ֵ
;���ڲ�����R0 ���н�� 
;ռ����Դ��R0
;˵������N=0ʱ���Ϊ0����N=1ʱ���Ϊ1
;��������������Ϊ0

SUM_N
	PUSH {R1-R7,LR}    ;�Ĵ�����ջ����
	MOVS R2,R0     ;��n��ֵ���Ƶ�R2,��Ӱ����Ӧ������־
	BEQ SUM_END     ;��N=0,�򷵻�
	CMP R2,#1
	BEQ SUM_END     ;��N=1,�򷵻�
	MOV R1,#1     ;��ʼ��������R1=1
	MOV R0,#0     ;��ʼ��������R0=1
SUN_L1
	;------------------------------------------
;�û��ʵ���㷨���Ĳ���
	ADD R0,R1
	BVS SUM_END
	ADD R1,#1
	B SUN_L1
SUM_ERR
	MOV R0,#0
	
	
	
	
	;------------------------------------------

SUM_END 
	MOV R8,R0		 ;�����������R8��
	POP {R1-R7,PC}   ;�Ĵ�����ջ������
        
	END
