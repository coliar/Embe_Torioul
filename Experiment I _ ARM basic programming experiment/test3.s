		AREA	Example,CODE,READONLY	  	;���������Example1 
		ENTRY				  				;��ʶ������� 
		CODE32				  				;����32λARMָ��
START 	MOV		SP,#0x300000
		MOV		R1,#0x11
		MOV		R2,#0x22
		MOV		R3,#0x33
		MOV		R4,#0x44
		MOV		R5,#0x55
		STMFA	R13!,{R2-R5}        		;���Ĵ���R2��R5���ݴ����ջ
		MOV		R2,#0X77
		LDMFA	R13!,{R2-R5}
		MOV		SP,#0x400000
		STMEA	R13!,{R1-R5}        		;���Ĵ���R1��R5���ݴ����ջ
		
		MOV		SP,#0x5400000
		STMFD	R13!,{R2-R5}        		;���Ĵ���R2��R5���ݴ����ջ
		
		MOV		SP,#0x600000
		STMED	R13!,{R2-R4}        		;���Ĵ���R2��R4���ݴ����ջ	   
		MOV		R0,#0  
		B			START   					
		END			     					;�ļ�����
