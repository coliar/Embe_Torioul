;�ļ�����TESTFILE.S 
;���ܣ���C�����е��û������
 
		AREA	Example1,CODE,READONLY	  ;���������Example1 
		CODE32				  ;����32λARMָ��

		IMPORT __main

		
		EXPORT strcopy
strcopy	
	;------------------------------------------
;�û��ʵ���ַ�������
	
	LDRB  R2,[R1],#1	     ;����Դ�ַ�����һ���ֽ�
	STRB  R2,[R0],#1              ;���������ֽڸ��Ƶ�Ŀ��ռ�
	
	CMP   R2,#0
	BNE   strcopy
	
	MOV   PC,LR
	;------------------------------------------
		
	END			     	   ;�ļ�����
