;SET子程序区
	SET	ST R0,SR1	;R0装的是输入的字符
		ST R7,RRR7
		LD R0,QIPAN0	;棋盘位置可能过远，在此预先存放棋盘地址于另一个地方
		ST  R0,QIPAN1

		AND R2,R2,#0	;将需要填的字符放入R2
		LD R2,ZMO	;X4F是字符'O'
		AND R6,R1,#1
		BRz #1
		ADD R2,R2,#9	;'O'+9=X
		ST R2,CFZF	;将存放的字符存起来备用
		
		LD R3,NN1	;R3放X-30 ,R0中放的是输入字符的ASCII
		LD R0,SR1	;R0放输入的字符
		ADD R3,R3,R0	;执行完该句后，R3中放的1~6；是列
		ST R3,NLIE	

		LD R0,QIPAN1	;R0放的棋盘首地址
	CHENG	ADD R0,R0,#6	;该小循环是将R0加载为所在列的末行
		ADD R3,R3,#-1
		BRp		CHENG
	
		LD R3,SIGN	;SIGN是-的ASCII
		AND R5,R5,#0
		ADD R5,R5,#7	;R5为放入棋子的所在行

	HANG	ADD R0,R0,#-1	;该段是为了找到棋子所在行并将棋子放入	
		ADD R5,R5,#-1	
		LDR R4,R0,#0	;R4放的R0处的ASCII
		ADD R6,R4,R3	
		BRp HANG
		STR R2,R0,#0
		ST R5,NHANG
		
		LD R2,CFZF
		LD R3,NLIE
		LD R4,NHANG
		LD R7,RRR7
		RET
;SET的数据:
	QIPAN1	.FILL X0	;棋盘的地址
	SR1	.FILL X0
	NN1	.FILL X-30	;数字1的ASCII
	CFZF	.FILL X0
	NLIE 	.FILL X0	;列
	NHANG	.FILL X7	;行
	SIGN	.FILL X-2D	;符号-
	ZMO	.FILL X4F
	RRR7	.FILL X0