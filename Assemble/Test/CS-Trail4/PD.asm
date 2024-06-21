
;PD子程序区--判断
	PD	ST R4,H1
		ST R3,L1
		ST R7,RS7
		LD R0,QIPAN1	;棋盘位置可能过远，在此预先存放棋盘地址于另一个地方
		ST R0,QIPAN2
		
		NOT R2,R2
		ADD R2,R2,#1	;R2字符取负数,在该子程序中保持不变
			
;以下为行判断
	HPD	LD R0,QIPAN2	
		LD R4,H1	;R4为行数	
		ADD R0,R0,R4	
		ADD R0,R0,#-1	;R0为该行第一个
		AND R5,R5,#0	;R5为同行不同列的限制
		ADD R5,R5,#6
		AND R4,R4,#0	;R4改为记录的是连续的相同符号有几个

	HPDXH	LDR R3,R0,#0	;此循环为行判断	;R3为棋盘中R0处存放的数据
		ADD R3,R2,R3
		BRz #2
		AND R4,R4,#0
		ADD R4,R4,#-1
		ADD R4,R4,#1
		ADD R6,R4,#-4	;是否存在四连
		BRz	WIN	
		ADD R0,R0,#6	;换该行的下一个
		ADD R5,R5,#-1	
		BRp HPDXH

		ADD R4,R4,#-4	;是否存在四连
		BRz WIN
;以下为列判断
	LPD	LD R0,QIPAN2
		ADD R0,R0,#-1
		LD R3,L1	;R3为列数
		ADD R0,R0,#6
		ADD R3,R3,#-1
		BRp #-3
		AND R4,R4,#0	;R4记录的是连续的相同符号有几个
		AND R5,R5,#0	;此时R0中为该列最后一个位置的地址,R5用于将R0控制于该列内

	LPDXH	LDR R3,R0,#0	;此循环为列判断，R3为棋盘的数据
		ADD R3,R3,R2
		BRz #2
		AND R4,R4,#0
		ADD R4,R4,#-1
		ADD R4,R4,#1
		ADD R6,R4,#-4	;是否存在四连
		BRz	WIN
		ADD R5,R5,#1	;该列，上移
		ADD R0,R0,#-1
		ADD R6,R5,#-6
		BRn LPDXH



;以下为主对角线判断
	ZDJPD	LD R3,L1	;R3为列，R4为行
		LD R4,H1
		NOT R4,R4	;行取反，与列相加，分为正负零三种
		ADD R4,R4,#1
		ADD R6,R3,R4	;行列的差值
		BRn	ZXIA
		BRz	ZZHONG
		BRp	ZSHANG	;上中下传到下面的R6为行列的差值，除了R1，R2，其他的都可随意更改
		
	ZXIA	ADD R4,R6,#3
		BRnz FDJPD	;行列差绝对值大于等于3就不用判断

		NOT R6,R6	;行列的差取绝对值
		ADD R6,R6,#1
		LD R0,QIPAN2
		ADD R0,R0,R6	;该主对角线的第一个数据地址
		LD R5,H1	;R5保证地址不越界？
		BRnzp	ZZJ
	
	ZSHANG	ADD R4,R6,#-3
		BRzp FDJPD	;行列差绝对值大于等于3就不用判断
		
		LD R0,QIPAN2;
		ADD R0,R0,#6	
		ADD R6,R6,#-1
		BRp #-3		;使R0为该主对角线的第一个数据地址
		LD R5,L1	;R5保证地址不越界
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
		ADD R6,R4,#-4	;是否存在四连
		BRz	WIN
		ADD R5,R5,#1
		ADD R0,R0,#7	;该主对角线下一个
		ADD R6,R5,#-6
		BRnz ZPDXH
		
		
;以下为副对角线判断		主对角线和副对角线之间的关系
	FDJPD	AND R5,R5,#0
		LD R3,L1
		LD R4,H1
		ADD R4,R4,R3	;R4为横纵坐标之和
		ADD R6,R4,#-7
		BRn FSHANG
		BRz FZHONG
		BRp FXIA

	FSHANG	ADD R6,R4,#-5
		BRn PDEXIT		;行列和大于9或者小于5就不用判断
		LD R0,QIPAN2
		ADD R0,R0,R4
		ADD R0,R0,#-2	;R0存副对角线首位
		ADD R5,R4,#-8	;R5用于保证不会越界
		NOT R5,R5
		ADD R5,R5,#1
		BRnzp FZJ
	
	FXIA	ADD R6,R4,#-9
		BRp PDEXIT	;行列和大于9或者小于5就不用判断
		LD R0,QIPAN2
		ADD R0,R0,#5
		ADD R6,R4,#-7
		ADD R0,R0,#6
		ADD R6,R6,#-1
		BRp #-3		;R0存副对角线首位
		ADD R5,R4,#-6	;R5用于保证不会越界
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
		ADD R6,R4,#-4	;是否存在四连
		BRz	WIN
		ADD R5,R5,#1
		ADD R0,R0,#5	;该副对角线下一个
		ADD R6,R5,#-6
		BRnz FPDXH

		AND R0,R0,#0
	
		
	PDEXIT	LD R7,RS7
		RET

	WIN	AND R0,R0,#0
		ADD R0,R0,#1
		BRnzp PDEXIT

;PD子程序数据区
	RS7	.FILL X0
	QIPAN2	.FILL X0
	L1	.FILL X0
	H1	.FILL X0