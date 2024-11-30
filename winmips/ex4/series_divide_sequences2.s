.data
a:    .word     12
b:    .word     3
c:    .word     15
d:    .word     5
e:    .word     1
f:    .word     2
g:    .word     3
h:    .word     4
i:    .word     5
j:    .word     6

.text
start:
; 依次加载数据
ld r16,a(r0)
ld r17,b(r0)
ld r18,c(r0)
ld r19,d(r0)
ld r20,e(r0)
ld r21,f(r0)
ld r22,g(r0)
ld r23,h(r0)
ld r24,i(r0)
ld r25,j(r0)

; 第一次除法计算（隐藏延迟）
ddiv r16,r16,r17
daddi r20,r20,1   ; 与 ddiv 无关，填充周期
daddi r21,r21,1   ; 填充周期
daddi r22,r22,1   ; 填充周期
sd r20,e(r0)      ; 存储部分计算结果
sd r21,f(r0)      ; 存储部分计算结果
nop               ; 确保没有 RAW 冒险

; 第二次除法计算（继续填充延迟）
ddiv r18,r18,r19
daddi r23,r23,1   ; 填充周期
daddi r24,r24,1   ; 填充周期
daddi r25,r25,1   ; 填充周期
sd r23,g(r0)      ; 存储部分计算结果
sd r24,h(r0)      ; 存储部分计算结果

; 存储除法结果
sd r16,a(r0)      ; 存储第一个 ddiv 结果
sd r17,b(r0)      ; 存储第一个 ddiv 操作数
sd r18,c(r0)      ; 存储第二个 ddiv 结果
sd r19,d(r0)      ; 存储第二个 ddiv 操作数

; 存储剩余数据
sd r25,i(r0)      ; 存储剩余结果

halt
