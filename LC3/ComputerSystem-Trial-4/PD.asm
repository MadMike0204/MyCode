
;PD�ӳ�����
	PD	ST R4,H1
		ST R3,L1
		ST R7,RS7
		LD R0,QIPAN1	;����λ�ÿ��ܹ�Զ���ڴ�Ԥ�ȴ�����̵�ַ����һ���ط�
		ST R0,QIPAN2
		
		NOT R2,R2
		ADD R2,R2,#1	;R2�ַ�ȡ��,�ڸ��ӳ����б��ֲ���
			
;����Ϊ���ж�
	HPD	LD R0,QIPAN2	
		LD R4,H1	;R4Ϊ����	
		ADD R0,R0,R4	
		ADD R0,R0,#-1	;R0Ϊ���е�һ��
		AND R5,R5,#0	;R5Ϊͬ�в�ͬ�е�����
		ADD R5,R5,#6
		AND R4,R4,#0	;R4��Ϊ��¼������������ͬ�����м���

	HPDXH	LDR R3,R0,#0	;��ѭ��Ϊ���ж�	;R3Ϊ������R0����ŵ�����
		ADD R3,R2,R3
		BRz #2
		AND R4,R4,#0
		ADD R4,R4,#-1
		ADD R4,R4,#1
		ADD R6,R4,#-4	;�Ƿ��������
		BRz	WIN	
		ADD R0,R0,#6	;�����е���һ��
		ADD R5,R5,#-1	
		BRp HPDXH

		ADD R4,R4,#-4	;�Ƿ��������
		BRz WIN
;����Ϊ���ж�
	LPD	LD R0,QIPAN2
		ADD R0,R0,#-1
		LD R3,L1	;R3Ϊ����
		ADD R0,R0,#6
		ADD R3,R3,#-1
		BRp #-3
		AND R4,R4,#0	;R4��¼������������ͬ�����м���
		AND R5,R5,#0	;��ʱR0��Ϊ�������һ��λ�õĵ�ַ,R5���ڽ�R0�����ڸ�����

	LPDXH	LDR R3,R0,#0	;��ѭ��Ϊ���жϣ�R3Ϊ���̵�����
		ADD R3,R3,R2
		BRz #2
		AND R4,R4,#0
		ADD R4,R4,#-1
		ADD R4,R4,#1
		ADD R6,R4,#-4	;�Ƿ��������
		BRz	WIN
		ADD R5,R5,#1	;���У�����
		ADD R0,R0,#-1
		ADD R6,R5,#-6
		BRn LPDXH



;����Ϊ���Խ����ж�
	ZDJPD	LD R3,L1	;R3Ϊ�У�R4Ϊ��
		LD R4,H1
		NOT R4,R4	;��ȡ����������ӣ���Ϊ����������
		ADD R4,R4,#1
		ADD R6,R3,R4	;���еĲ�ֵ
		BRn	ZXIA
		BRz	ZZHONG
		BRp	ZSHANG	;�����´��������R6Ϊ���еĲ�ֵ������R1��R2�������Ķ����������
		
	ZXIA	ADD R4,R6,#3
		BRnz FDJPD	;���в����ֵ���ڵ���3�Ͳ����ж�

		NOT R6,R6	;���еĲ�ȡ����ֵ
		ADD R6,R6,#1
		LD R0,QIPAN2
		ADD R0,R0,R6	;�����Խ��ߵĵ�һ�����ݵ�ַ
		LD R5,H1	;R5��֤��ַ��Խ�磿
		BRnzp	ZZJ
	
	ZSHANG	ADD R4,R6,#-3
		BRzp FDJPD	;���в����ֵ���ڵ���3�Ͳ����ж�
		
		LD R0,QIPAN2;
		ADD R0,R0,#6	
		ADD R6,R6,#-1
		BRp #-3		;ʹR0Ϊ�����Խ��ߵĵ�һ�����ݵ�ַ
		LD R5,L1	;R5��֤��ַ��Խ��
		BRnzp	ZZJ
	
	ZZHONG	LD R0,QIPAN2
		AND R5,R5,#0
		BRnzp	ZZJ

	ZZJ	AND R4,R4,#0
	ZPDXH	LDR R3,R0,#0
		ADD R3,R3,R2
		BRz #2
		AND R4,R4,#0
		ADD R4,R4,#-1
		ADD R4,R4,#1
		ADD R6,R4,#-4	;�Ƿ��������
		BRz	WIN
		ADD R5,R5,#1
		ADD R0,R0,#7	;�����Խ�����һ��
		ADD R6,R5,#-6
		BRnz ZPDXH
		
		
;����Ϊ���Խ����ж�		���Խ��ߺ͸��Խ���֮��Ĺ�ϵ
	FDJPD	AND R5,R5,#0
		LD R3,L1
		LD R4,H1
		ADD R4,R4,R3	;R4Ϊ��������֮��
		ADD R6,R4,#-7
		BRn FSHANG
		BRz FZHONG
		BRp FXIA

	FSHANG	ADD R6,R4,#-5
		BRn PDEXIT		;���кʹ���9����С��5�Ͳ����ж�
		LD R0,QIPAN2
		ADD R0,R0,R4
		ADD R0,R0,#-2	;R0�渱�Խ�����λ
		ADD R5,R4,#-8	;R5���ڱ�֤����Խ��
		NOT R5,R5
		ADD R5,R5,#1
		BRnzp FZJ
	
	FXIA	ADD R6,R4,#-9
		BRp PDEXIT	;���кʹ���9����С��5�Ͳ����ж�
		LD R0,QIPAN2
		ADD R0,R0,#5
		ADD R6,R4,#-7
		ADD R0,R0,#6
		ADD R6,R6,#-1
		BRp #-3		;R0�渱�Խ�����λ
		ADD R5,R4,#-6	;R5���ڱ�֤����Խ��
		BRnzp FZJ
		
	FZHONG	LD R0,QIPAN2
		ADD R0,R0,#5
		ADD R5,R5,#1
		BRnzp FZJ

	FZJ	AND R4,R4,#0
	FPDXH	LDR R3,R0,#0
		ADD R3,R3,R2
		BRz #2
		AND R4,R4,#0
		ADD R4,R4,#-1
		ADD R4,R4,#1
		ADD R6,R4,#-4	;�Ƿ��������
		BRz	WIN
		ADD R5,R5,#1
		ADD R0,R0,#5	;�ø��Խ�����һ��
		ADD R6,R5,#-6
		BRnz FPDXH

		AND R0,R0,#0
	
		
	PDEXIT	LD R7,RS7
		RET

	WIN	AND R0,R0,#0
		ADD R0,R0,#1
		BRnzp PDEXIT

;PD�ӳ���������
	RS7	.FILL X0
	QIPAN2	.FILL X0
	L1	.FILL X0
	H1	.FILL X0