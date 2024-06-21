;R0:输入输出内容
;R1:存储地址 LDI 和 STI
;R2:存储空格
;R3:  下限 
;R4:上限
;R5:计数器 
;R6:

.ORIG x3000          ;程序起始地址

    LEA R0, LOGIN_MSG
    PUTS
    ; 获取输入的ID
    LEA R1, x2000;将x2000储存起来，作为ID起始地址
    AND R4, R4, #0       ; 初始化长度计数器
    GETC                ; 从键盘获取一个字符
    ADD 
    OUT                 ; 回显字符