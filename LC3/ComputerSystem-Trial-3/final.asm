.ORIG	x3000
;预处理
PREPARE
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
    TRAP    x21         ;将R0中的字符输出到控制台
    LD      R4, NEGSPACE   ;加载空格用于判断
    ADD     R4, R4, R0  ;判断是不是空格
    BRz     LOAD_3
    STR     R0, R1, #0  ;将读入字符写入地址
    ADD     R2, R2, #1  ;自增,记录ID长度
    ADD     R1, R1, #1  ;指针自增   
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
READ_PW_ENCRYPTION
    TRAP    x20         ;读入字符
    TRAP    x21
    LD      R4, NEGSPACE
    ADD     R4, R4, R0
    BRz     LENGTH
    ADD     R0, R0, #-12 ;字符偏移
    STR     R0, R1, #0  ;读入的字符写入地址
    ADD     R3, R3, #1  ;自增,记录Password长度
    ADD     R1, R1, #1  ;指针自增
    BRnzp   READ_PW_ENCRYPTION
LENGTH
    ADD     R0, R2, #-4
    BRn    LOAD_FINAL_2
    ADD     R0, R2, #-10
    BRp     LOAD_FINAL_2
    ADD     R0, R3, #-6
    BRn    LOAD_FINAL_2
    ADD     R0, R3, #-10
    BRp     LOAD_FINAL_2

FIND
    LEA     R6, SITE            ; 装载二级扫描指针
    LEA     R5, ID              ; 装载ID指针

COMPARE_ID
    LDR     R0, R6, #0          ; 装载一级扫描指针
    BRz     UPDATE              ; 如果当前字符为0，则更新二级指针
    LDR     R1, R5, #0          ; 装载当前ID字符
    NOT     R1, R1              ; 取反
    ADD     R1, R1, #1          ; 补码求负数
    ADD     R1, R1, R0          ; 比较当前字符

    BRnp    UPDATE              ; 如果不匹配则更新二级指针

    ADD     R6, R6, #1          ; 更新一级指针
    ADD     R5, R5, #1          ; 更新ID指针
    BRnzp   COMPARE_ID          ; 继续比较下一个字符

UPDATE
    ADD     R6, R6, #1          ; 二级指针自增
    LD      R5, ID              ; 重置ID指针

    ; 比对ID成功后，进行密码比对
    ; 假设ID匹配后R6指向ID末尾下一个字符的位置，
    ; 调整指针到对应的密码位置

    ADD     R6, R6, #1          ; 移动到下一个密码位置
    LEA     R5, PW              ; 装载密码指针

COMPARE_PW
    LDR     R0, R6, #0          ; 装载密码中的字符
    BRz     LOAD_FINAL_1        ; 如果当前字符为0，则表示登录成功
    LDR     R1, R5, #0          ; 装载输入的密码字符
    NOT     R1, R1              ; 取反6 
    ADD     R1, R1, #1          ; 补码求负数
    ADD     R1, R1, R0          ; 比较当前字符

    BRnp    LOAD_FINAL_2        ; 如果不匹配则登录失败

    ADD     R6, R6, #1          ; 更新密码指针
    ADD     R5, R5, #1          ; 更新输入的密码指针
    BRnzp   COMPARE_PW          ; 继续比较下一个字符
LOAD_FINAL_1
    LEA     R1, PASS
    LEA     R4, ID
LOGINSUCCESS_1
    LDR     R0, R4, #0
    BRz     LOGINSUCCESS_2
    TRAP    x21
    ADD     R4, R4, #1
    BRnzp   LOGINSUCCESS_1
LOGINSUCCESS_2
    LDR     R0, R1, #0
    BRz     MAMBAOUT
    TRAP    x21
    ADD     R1, R1, #1
    BRnzp   LOGINSUCCESS_2
LOAD_FINAL_2
    LEA     R1,FAIL
LOGINFAIL
    LDR     R0, R1, #0
    BRz     MAMBAOUT   
    TRAP    x21
    ADD     R1, R1, #1
    BRnzp   LOGINFAIL
MAMBAOUT
    HALT

IDI             .STRINGZ	"Login ID: "
PWI             .STRINGZ	"Password: "
FAIL            .STRINGZ	"Invalid UserID/Password. Your login failed." 
PASS            .STRINGZ	", you have successfully logged in."
ID              .BLKW       11
PW              .BLKW       11
NEGSPACE        .FILL       #-10
SITE            .FILL	    x4000
.END