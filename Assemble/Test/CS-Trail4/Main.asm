
.ORIG X3000
		AND R1,R1,#0
		ADD R1,R1,#15
		ADD R1,R1,#15
		ADD R1,R1,#6	
	;R1置为36	
	;R1作为计数寄存器
	;第一次输出空的棋盘
		LEA R3,QIPAN
		AND R5,R5,#0	
		ADD R5,R5,#6	
	WXH1				;外循环
		AND R4,R4,#0	
		ADD R4,R4,#6
	NXH1				;内循环
		LDR R0,R3,#0
		OUT
		ADD R3,R3,#1
		AND R0,R0,#0
		ADD R4,R4,#-1
		BRp #3
		ADD R0,R0,X0D
		OUT
		BRnzp HUANH1
		LD R0,SPACE1
		OUT
		BRnzp NXH1
	HUANH1	ADD R5,R5,#-1
		BRp WXH1
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;接下来的部分就是1和2轮流输入的部分

	LOOP	
		JSR	CIN	;其中R1作为计数入口,R0返回输入的字符

		JSR	SET	;R1作为计数入口 
				;R2返回字符O或者X ,R3返回列,R4返回行(1~6)
					
		JSR	PD	;R1为计数入口，R2为字符O或X的反，R3，R4为行列号入口
				;R0返回是否游戏结束;(1结束，0继续

		JSR	COUT	;输出棋盘，并依据上一个子程序PD返回的R0的值判断是否要输出玩家获胜的相关信息
				;如果在该子程序中输出过玩家赢了的信息，那么R0返回-1，否则R0返回0
		
		ADD R0,R0,#1	;主程序可以依据COUT子程序返回的R0中的值判断是否游戏结束
		BRz TOHALT	

		ADD R1,R1,#-1
		BRp	LOOP
		BRz  DIE

	TOHALT	HALT
		
	DIE	LEA R0,TIE	;平局判定
		PUTS
		BRnzp TOHALT

;主函数数据区:
	SPACE1	.FILL X20
	QIPAN	.BLKW 36,X2D
	TIE	.STRINGZ "Tie Game."

;CIN子程序区:
	CIN	ST R7,RR7
		LEA R0,QIPAN	;提前准备棋盘地址
		ST R0,QIPAN0	

	CINWORD	LEA R0,P1	;输出提示语句	
		AND R6,R1,#1	;R1是从主程序拿到的循环次数，没有进行更改
		BRz #1
		LEA R0,P2
		PUTS		

		GETC		;输入并显示
		OUT		
		ST R0,SR	;SR中放的输入的字符
		AND R0,R0,#0	;换行操作
		ADD R0,R0,XA
		OUT
		
		LD R0,SR	;R0中为输入的字符,判断输入是否合法
		LD R2,N1	
		ADD R6, R2,R0	;R6是通用的辅助判断寄存器
		BRn WRO
		LD R2,N6
		ADD R6,R2,R0
		BRp WRO

		;判断输入的那一列是不是满了
		LD R6,N0
		LD R0,SR
		ADD R6,R6,R0
		
		ADD R6,R6,#-1
		BRz ON
		ADD R6,R6,#-1
		BRz TW
		ADD R6,R6,#-1
		BRz TH
		ADD R6,R6,#-1
		BRz FO
		ADD R6,R6,#-1
		BRz FI
		ADD R6,R6,#-1
		BRz SI
		BRnzp ZSFH
	
	ON	LD R6,ONE
		ADD R6,R6,#1
		ST R6,ONE
		ADD R6,R6,#-7
		BRzp WRO
		BRnzp ZSFH
	TW	LD R6,TWO
		ADD R6,R6,#1
		ST R6,TWO
		ADD R6,R6,#-7
		BRzp WRO
		BRnzp ZSFH
	TH	LD R6,THREE
		ADD R6,R6,#1
		ST R6,THREE
		ADD R6,R6,#-7
		BRzp WRO
		BRnzp ZSFH
	FO	LD R6,FOUR
		ADD R6,R6,#1
		ST R6,FOUR
		ADD R6,R6,#-7
		BRzp WRO
		BRnzp ZSFH
	FI	LD R6,FIVE
		ADD R6,R6,#1
		ST R6,FIVE
		ADD R6,R6,#-7
		BRzp WRO
		BRnzp ZSFH
	SI	LD R6,SIX
		ADD R6,R6,#1
		ST R6,SIX
		ADD R6,R6,#-7
		BRzp WRO

		;着手返回
	ZSFH	LD R0,SR
		LD R7,RR7
		RET		

	WRO	LEA R0,WR	;如果输入错误
		PUTS
		AND R0,R0,#0	;换行操作
		ADD R0,R0,XA
		OUT		
		BRnzp	CINWORD	

;CIN的数据区：
	QIPAN0	.FILL X0
	N0	.FILL X-30
	N1	.FILL X-31	;1
	N6	.FILL X-36	;6
	ONE	.FILL X0
	TWO	.FILL X0
	THREE	.FILL X0
	FOUR	.FILL X0
	FIVE	.FILL X0
	SIX	.FILL X0
	SR	.FILL X0
	RR7	.FILL X0
	P1	.STRINGZ "Player 1, choose a column:"
	P2	.STRINGZ "player 2, choose a column:"
	WR	.STRINGZ "Invalid move. Try again."
		

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

;PD子程序区
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

	;COUT子程序
		
		COUT	ST R0,WHO
			ST R7,RSJ7
			ST R2,WINER
			LD R3,QIPAN2
			ST R3,QIPAN3
			
			AND R5,R5,#0	;置零

		WXH	AND R4,R4,#0	
			ADD R4,R4,#6	;存入6
			LD R3,QIPAN3
			ADD R3,R5,R3    ;棋盘增量
			
		NXH	LDR R0,R3,#0
			OUT
			ADD R3,R3,#6

			AND R0,R0,#0
			ADD R4,R4,#-1
			BRp #3
			ADD R0,R0,XA ;换行
			OUT
			BRnzp HUANH
			LD R0,SP ;输出空格
			OUT
			BRnzp NXH
		HUANH	
			ADD R5,R5,#1
			ADD R6,R5,#-6	 ;如果到比6小，继续,否则认为输出棋盘完毕
			BRn WXH
			LD R0,WHO   	 ;没有人赢是0，有人赢是1
			ADD R0,R0,#-1
			BRz	GAMEOVER	 ;没有人赢，认为继续，返回-1；有人赢，返回0，认为结束
			
			AND R0,R0,#0
		BACK	LD R7,RSJ7
			RET

	GAMEOVER	LD R3,WINER
			LD R2,PLAYER1
			LEA R0,WIN1
			ADD R6,R2,R3	
			BRz #1
			LEA R0,WIN2
			PUTS
			
			AND R0,R0,#0
			ADD R0,R0,#-1
			BRnzp BACK
;COUT数据区
	WHO	.FILL X0
	RSJ7	.FILL X0
	SP	.FILL X20
	QIPAN3	.FILL X0
	PLAYER1	.FILL X4F
	WINER	.FILL X0	;存放或许会赢的玩家的字符
	WIN1	.STRINGZ "Player 1 Wins."
	WIN2	.STRINGZ "Player 2 Wins."
		.END