		AREA	Example,CODE,READONLY	  	;���������Example1 
		ENTRY				  				;��ʶ������� 
		CODE32				  				;����32λARMָ��
START 	MOV		R1,#0x04		  			 
		MOV		R2,#0x04
		SUBS	R3,R2,R1	    			
		
		MOVNE	R5,#0x200						
		ADDS	R7,R5,R2,LSL #0x4
		MOVS	R6,#8
		CMP		R1,R2
		
		MOV		R2,R2,ROR #4	    		
		SUB		R6,R5,R2,LSL #3				
		B			.
		END			     					;�ļ�����
