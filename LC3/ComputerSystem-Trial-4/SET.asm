;SET�ӳ�����
	SET	ST R0,SR1	;R0װ����������ַ�
		ST R7,RRR7
		LD R0,QIPAN0	;����λ�ÿ��ܹ�Զ���ڴ�Ԥ�ȴ�����̵�ַ����һ���ط�
		ST  R0,QIPAN1

		AND R2,R2,#0	;����Ҫ����ַ�����R2
		LD R2,ZMO	;X4F���ַ�'O'
		AND R6,R1,#1
		BRz #1
		ADD R2,R2,#9	;'O'+9=X
		ST R2,CFZF	;����ŵ��ַ�����������
		
		LD R3,NN1	;R3��X-30 ,R0�зŵ��������ַ���ASCII
		LD R0,SR1	;R0��������ַ�
		ADD R3,R3,R0	;ִ����þ��R3�зŵ�1~6������
		ST R3,NLIE	

		LD R0,QIPAN1	;R0�ŵ������׵�ַ
	CHENG	ADD R0,R0,#6	;��Сѭ���ǽ�R0����Ϊ�����е�ĩ��
		ADD R3,R3,#-1
		BRp		CHENG
	
		LD R3,SIGN	;SIGN��-��ASCII
		AND R5,R5,#0
		ADD R5,R5,#7	;R5Ϊ�������ӵ�������

	HANG	ADD R0,R0,#-1	;�ö���Ϊ���ҵ����������в������ӷ���	
		ADD R5,R5,#-1	
		LDR R4,R0,#0	;R4�ŵ�R0����ASCII
		ADD R6,R4,R3	
		BRp HANG
		STR R2,R0,#0
		ST R5,NHANG
		
		LD R2,CFZF
		LD R3,NLIE
		LD R4,NHANG
		LD R7,RRR7
		RET
;SET������:
	QIPAN1	.FILL X0	;���̵ĵ�ַ
	SR1	.FILL X0
	NN1	.FILL X-30	;����1��ASCII
	CFZF	.FILL X0
	NLIE 	.FILL X0	;��
	NHANG	.FILL X7	;��
	SIGN	.FILL X-2D	;����-
	ZMO	.FILL X4F
	RRR7	.FILL X0