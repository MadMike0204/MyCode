.ORIG x3000

		LD R6 StaPtr	; 初始化堆栈指针


		LD R1 InPtr
		LD R2 InF
		STR R2 R1 #0	; 设置键盘中断(中断程序起始地址放入中断指针位置


		LD R3 x_4000
		STI R3, KBSR	; 使能KBSR中断位


LOOP	LEA R0 str1		; 打印字符串1
		PUTS
		AND R0 R0 #0
		ADD R0 R0 #13	; Enter
		OUT
		AND R0 R0 #0
		LD R0 COUNT
DELAY1	ADD R0 R0 #-1
		BRp DELAY1

		LEA R0 str2	; 打印字符串2
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