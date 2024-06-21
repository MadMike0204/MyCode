         .ORIG  x3000
         ;³õÊ¼»¯[C]
         LD R6, STACK         ; initialize the stack pointer
         LD R1, INTER         ; set up the keyboard interrupt vector table entry
         LD R2, START         ;°ÑµØÖ·x1080¸ÄÎªx2000
         STR R2, R1,#0

         LD R3, IE     ; enable keyboard interrupts
         STI R3, KBSR  ;
         ;ÓÃ»§³ÌÐò[A]
AGAIN    LEA R0, STR1         ; start of actual user program to print ICS checkerboard
         PUTS
         JSR DELAY
         LEA R0, STR2
         PUTS
         JSR DELAY
         BRnzp AGAIN
        
         HALT

STACK .FILL X4000
INTER .FILL X0180
IE    .FILL X4000;KBSRÖÃÎ»Îª1
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

      .ORIG  x2000
      ADD R6, R6, #-1;°ÑÊý¾ÝÑ¹ÈëÕ»ÖÐ
      STR R0, R6, #0
      ADD R6, R6, #-1
      STR R1, R6, #0
      ADD R6, R6, #-1
      STR R2, R6, #0
      ADD R6, R6, #-1
      STR R3, R6, #0
      ADD R6, R6, #-1
      STR R4, R6, #0

      LD R4, STRING; IE:×Ö·û´®Ê×µØÖ·
LOOP1 LDI R1, KBSR; 1100 X X X
      BRzp LOOP1
      LDI R0, KBDR
      LD  R2,BREAK; ÅÐ¶Ï»Ø³µ
      ADD R2, R2, R0
      BRz LOOP
      STR R0, R4, #0
      ADD R4, R4, #1
      BRnzp LOOP1
LOOP  AND R0, R0, #0
      ADD R0, R0, #10
      STR R0, R4, #0
NEXT1 AND R3, R3, #0
      ADD R3, R3, #10
LOOP3 LD R4, STRING
LOOP5 LDR R0, R4, #0
      ADD R4, R4, #1
LOOP4 LDI R1, DSR
      BRzp LOOP4
      LD R2, BREAK
      ADD R2, R2, R0
      BRZ NEXT3
      STI R0, DDR
      BRnzp LOOP5
NEXT3 ADD R3, R3, #-1
      BRp LOOP3
NEXT2 LDR R4, R6, #0
      ADD R6, R6, #1
      LDR R3, R6, #0
      ADD R6, R6, #1
      LDR R2, R6, #0
      ADD R6, R6, #1
      LDR R1, R6, #0
      ADD R6, R6, #1
      LDR R0, R6, #0
      ADD R6, R6, #1
      RTI


KBSR  .FILL XFE00
KBDR  .FILL XFE02
DSR   .FILL XFE04
DDR   .FILL XFE06
BREAK .FILL XFFF6; -X0A
STRING .FILL X4000
.END

