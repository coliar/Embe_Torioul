		AREA	Example,CODE,READONLY	  	;���������Example1 
		ENTRY				  				;��ʶ������� 
		CODE32				  				;����32λARMָ��
START 	MOV		R1,#0x01		  			; 
		MOV		R2,#0x04
		MOV		R3,#0x03
		MOV		R4,#0x04
		MOV		R5,#0x05
			    			
		LDR		R6,[R2]		    			;�Ĵ������Ѱַ
		LDR		R6,[R2,#4]
		STR		R3,[R7]
		LDR		R7,[R2,#0x0C]	    		;��ַ����ַѰַ ע���ֽڶ���R2��ֵҪ��4��������
			  	    						
		LDR		R0,=0x100000
		STMIA	R0,{R1-R3}					;��Ĵ���Ѱַ
		LDR		R0,=0x100000
		STMIB	R0,{R1-R3}					;��Ĵ���Ѱַ
		LDR		R0,=0x200008
		STMDA	R0,{R1-R3,R5}				;�鿽��Ѱַ
		LDR		R0,=0x210000
		LDMIA	R0,{R1-R5,R7}		
		MOV		R0,#0x0						;����ת��ָ�����һ���޷�����
		B		START			
		END			     					;�ļ�����
