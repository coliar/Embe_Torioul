	AREA	Example,CODE,READONLY	  	;���������Example1 
	ENTRY				  				;��ʶ������� 
	CODE32				  				;����32λARMָ��
START 	
	MOVS		R0,#0x04					;����Ѱַ
	MOVS		R1,#0x100
	MOVS		R2,#0x0
		
	LDR			R0,=0x12345678
		
	MOV		R5,R2						;�Ĵ���Ѱַ
	ADD		R7,R1,R2
	CMP		R1,R2

	MOV		R4,R0,ROR #1				;�Ĵ�����λѰַ		
	ADD		R3,R1,R0,LSL #2	  			 
	MOV		R3,R2,LSL #4	    		;�Ĵ�����λѰַ
	SUB		R6,R5,R2,LSL #3				;�Ĵ�����λѰַ
	B		START
	END			     					;�ļ�����

