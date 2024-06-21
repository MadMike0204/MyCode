         .ORIG  x3000
         ;初始化[C]
         LD R6, STACK         ; initialize the stack pointer
         LD R1, INTER         ; set up the keyboard interrupt vector table entry
         LD R2, START         ;把地址x1080改为x2000
         STR R2, R1,#0

         LD R3, IE     ; enable keyboard interrupts
         STI R3, KBSR  ;
         ;用户程序[A]
AGAIN    LEA R0, STR1         ; start of actual user program to print ICS checkerboard
         PUTS
         JSR DELAY
         LEA R0, STR2
         PUTS
         JSR DELAY
         BRnzp AGAIN
         HALT

STACK .FILL X4000
INTER .FILL X1080
IE    .FILL X4000;KBSR置位为1
START .FILL x2000
KBSR  .FILL XFE00
STR1  .STRINGZ "ICS    ICS     ICS     ICS     ICS     ICS\n"
STR2  .STRINGZ "   ICS     ICS     ICS     ICS     ICS    \n"

DELAY   	ST  R1, SaveR1
        	LD  R1, COUNT
REP         ADD R1,R1,#-1
	        BRp REP
       	    LD  R1, SaveR1
        	RET
COUNT   	.FILL #2500
SaveR1  	.BLKW 1
.END