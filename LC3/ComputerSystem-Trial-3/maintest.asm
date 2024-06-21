.ORIG	x3000

;预处理
    AND     R2, R2, #0  ;清空R2,用于记录ID长度
    AND     R3, R3, #0  ;清空R3,用于记录PW长度
LOAD_1
    LEA     R1, IDI
PRINT_1
    LDR     R0, R1 ,#0
    BRz     LOAD_2
    TRAP    x21
    ADD     R1,R1,#1
    BRnzp   PRINT_1
LOAD_2
    LEA     R1, ID      ;将ID首地址加载到R0
READ_ID
    TRAP    x20         ;读入字符
    STR     R0, R1, #0  ;将读入字符写入地址
    TRAP    x21         ;将R0中的字符输出到控制台
    ADD     R2, R2, #1  ;自增,记录ID长度
    ADD     R1, R1, #1  ;指针自增   
    ADD     R0, R0, #-10;判断是否是enter“ASCII = 10”
    BRz     LOAD_3
    BRnzp   READ_ID
LOAD_3
    LEA     R1, PWI     
PRINT_2
    LDR     R0, R1, #0
    BRz     LOAD_4
    TRAP    x21
    ADD     R1, R1, #1
    BRnzp   PRINT_2
LOAD_4                  ;将Password首地址加载到R0
    LEA     R1, PW
READ_PW
    TRAP    x20         ;读入字符
    STR     R0, R1, #0  ;读入的字符写入地址
    TRAP    x21         ;回显字符
    ADD     R3, R3, #1  ;自增,记录Password长度
    ADD     R1, R1, #1  ;指针自增
    ADD     R0, R0, #-10;判断是否是enter
    BRz     PROCESS
    BRnzp   READ_PW
PROCESS

    HALT
IDI     .STRINGZ	"Login ID: "
PWI     .STRINGZ	"Password: "
PASS    .STRINGZ	"Invalid UserID/Password. Your login failed." 
FAIL    .STRINGZ	", you have successfully logged in."
ID      .BLKW       11
PW      .BLKW       11



.END