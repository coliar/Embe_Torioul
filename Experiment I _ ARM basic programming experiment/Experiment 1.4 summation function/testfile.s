;�ļ�����TESTFILE.S 
;���ܣ��ӻ�������е���C����

		IMPORT g
		
		AREA	Example1,CODE,READONLY	  	;���������Example1 
		CODE32				  	;����32λARMָ��
		ENTRY

START	
	;------------------------------------------
;ͨ������c����g����ʵ��1+2+3+10���������R8��
	
		MOV		R0,#1	
		MOV		R1,#2
		MOV		R3,#10
		BL		g
		MOV		R8,R0	
		B		START
	
	
	
	;------------------------------------------

		END			     					;�ļ�����

