
.ORIG X3000
		AND R1,R1,#0
		ADD R1,R1,#15
		ADD R1,R1,#15
		ADD R1,R1,#6	
	;R1置为36	
	;R1作为计数寄存器
	;第一次输出空的棋盘
		LEA R3,QIPAN
		AND R5,R5,#0	;R5 置零
		ADD R5,R5,#6	;R5 填入6
	WXH1				;外循环
		AND R4,R4,#0	;R4 置零
		ADD R4,R4,#6	;R4 填入6
	NXH1				;内循环
		LDR R0,R3,#0	;读取到R3地址的内容'-'字符
		OUT
		ADD R3,R3,#1    ;指针自增
		AND R0,R0,#0	;R0 置零
		ADD R4,R4,#-1	;R4 减一
		BRp #3			;如果是R4还是正数，输出空格 否则--↓
		ADD R0,R0,X0D	;R0 填入换行并输出 进行一次外循环，再次进入下一次内循环
		OUT				
		BRnzp HUANH1
		LD R0,SPACE1      ;空格
		OUT
		BRnzp NXH1      ;继续循环
	HUANH1	ADD R5,R5,#-1 ;换行
		BRp WXH1
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;1和2轮流输入部分

	LOOP	
		JSR	CIN	;其中R1作为计数入口,R0返回输入的字符

		JSR	SET	;R1作为计数入口 
				;R2返回字符O或者X ,R3返回列,R4返回行(1~6)
					
		JSR	PD	;R1为计数入口，R2为字符O或X的反，R3，R4为行列号入口
				;R0返回是否游戏结束;(1结束，0继续

		JSR	COUT;输出棋盘，并依据上一个子程序PD返回的R0的值判断是否要输出玩家获胜的相关信息
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
		BRz #1			;最低位是0则为偶数，最低位是1则为奇数，R1与x0001相与，如果最低位是1，R6为1，否则R6为0
		LEA R0,P2		;是偶数则跳过，输出P1，否则输出P2
		PUTS		

		GETC		;输入并显示
		OUT		
		ST R0,SR	;SR中放的输入的字符
		AND R0,R0,#0	;置零
		ADD R0,R0,XA	;输出换行符
		OUT
;;;;非法字符
		LD R0,SR	;R0中为输入的字符,判断输入是否合法
		LD R2,N1	;输入字符加上-ASCII，如果是负数，跳转到输入错误WRO
		ADD R6, R2,R0	;R6是通用的辅助判断寄存器
		BRn WRO
		LD R2,N6
		ADD R6,R2,R0
		BRp WRO
;;;;非法选择
		;判断输入的那一列是不是满了
		LD R6,N0;存入负三十指针
		LD R0,SR;存入输入字符
		ADD R6,R6,R0;处理为纯数字x000M(m:1~6)

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
		BRnzp ZSFH;;返回
;;;;选中之后，对应的列Set1
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
		RET		;;返回到函数入口后，执行下一个函数

	WRO	LEA R0,WR	;如果输入错误
		PUTS
		AND R0,R0,#0	;换行操作
		ADD R0,R0,XA
		OUT		
		BRnzp	CINWORD	

;CIN的数据区：
	QIPAN0	.FILL X0
	N0	.FILL X-30
	N1	.FILL X-31	;1 负ASCII
	N6	.FILL X-36	;6 负ASCII
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
		ST R0,QIPAN1	;存在QIPAN1,新声明一个LABEL

		AND R2,R2,#0	;将需要填的字符放入R2
		LD R2,ZMO		;X4F是字符'O'
		AND R6,R1,#1	;玩家1存'O',玩家2存'X'
		BRz #1
		ADD R2,R2,#9	;'O'+9=X
		ST R2,CFZF	;将存放的字符存起来备用
		
		LD R3,NN1	;R3放X-30 ,R0中放的是输入字符的ASCII
		LD R0,SR1	;R0放输入的字符
		ADD R3,R3,R0	;执行完该句后，R3中放的1~6；是列
		ST R3,LINE	

		LD R0,QIPAN1	;R0放的棋盘首地址
	CHENG	ADD R0,R0,#6	;该小循环是将R0加载为所在列的末行，持续对输入的R3自减，持续乘6，因为地址间隔为6
		ADD R3,R3,#-1
		BRp		CHENG
		LD R3,SIGN	;SIGN是'-'的负值ASCII
		AND R5,R5,#0
		ADD R5,R5,#7	;R5为放入棋子的所在行

	HANG	ADD R0,R0,#-1	;该段是为了找到棋子所在行并将棋子放入	
		ADD R5,R5,#-1	
		LDR R4,R0,#0	;R4放的R0处的ASCII
		ADD R6,R4,R3	;比较把R0地址指向的棋盘内容与R3相加，如果为1就继续自减，如果为0就寻找到了
		BRp HANG
		STR R2,R0,#0
		ST R5,NHANG
		
		LD R2,CFZF
		LD R3,LINE
		LD R4,NHANG
		LD R7,RRR7 ;
		RET;返回主程序
;SET的数据:
	QIPAN1	.FILL X0	;棋盘的地址
	SR1	.FILL X0
	NN1	.FILL X-30	;数字1的ASCII
	CFZF	.FILL X0
	LINE 	.FILL X0	;列
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
		ADD R2,R2,#1	;R2字符取反,在该子程序中保持不变s
			
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
		
		AND R5,R5,#0	

	WXH	AND R4,R4,#0	
		ADD R4,R4,#6
		LD R3,QIPAN3
		ADD R3,R5,R3
		
	NXH	LDR R0,R3,#0
		OUT
		ADD R3,R3,#6

		AND R0,R0,#0
		ADD R4,R4,#-1
		BRp #3
		ADD R0,R0,XA
		OUT
		BRnzp HUANH
		LD R0,SP
		OUT
		BRnzp NXH
	HUANH	ADD R5,R5,#1
		ADD R6,R5,#-6
		BRn WXH

		LD R0,WHO
		ADD R0,R0,#-1
		BRz	GAMEOVER
		
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