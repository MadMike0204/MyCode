.ORIG x3000

		LD R6 StaPtr	; ��ʼ����ջָ��


		LD R1 InPtr
		LD R2 InF
		STR R2 R1 #0	; ���ü����ж�(�жϳ�����ʼ��ַ�����ж�ָ��λ��


		LD R3 x_4000
		STI R3, KBSR	; ʹ��KBSR�ж�λ


LOOP	LEA R0 str1		; ��ӡ�ַ���1
		PUTS
		AND R0 R0 #0
		ADD R0 R0 #13	; Enter
		OUT
		AND R0 R0 #0
		LD R0 COUNT
DELAY1	ADD R0 R0 #-1
		BRp DELAY1

		LEA R0 str2	; ��ӡ�ַ���2
		PUTS
		AND R0 R0 #0
		ADD R0 R0 #13	; Enter
		OUT
		AND R0 R0 #0
		LD R0 COUNT
DELAY2	ADD R0 R0 #-1
		BRp DELAY2
		BRnzp LOOP

	HALT

InPtr	.FILL x180
InF	.FILL x2000
StaPtr	.FILL x3000
COUNT	.FILL #30000
str1	.STRINGZ "ICS   ICS   ICS   ICS   ICS   ICS"
str2	.STRINGZ "   ICS   ICS   ICS   ICS   ICS   "
KBSR	.FILL xFE00
x_4000	.FILL x4000

.END