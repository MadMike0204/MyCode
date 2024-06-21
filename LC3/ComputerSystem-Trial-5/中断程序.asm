      .ORIG  x2000
      ADD R6, R6, #-1;把数据压入栈中
      STR R0, R6, #0
      ADD R6, R6, #-1
      STR R1, R6, #0
      ADD R6, R6, #-1
      STR R2, R6, #0
      ADD R6, R6, #-1
      STR R3, R6, #0
      ADD R6, R6, #-1
      STR R4, R6, #0

      LD R4, STRING; IE:字符串首地址
LOOP1 LDI R1, KBSR; 1100 X X X
      BRzp LOOP1
      LDI R0, KBDR
      LD  R2,BREAK; 判断回车
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