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
; 依次读取数据
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

; 两次除法连续进行
ddiv r16,r16,r17 
ddiv r18,r18,r19 

; 依次相加
daddi r20,r20,1
daddi r21,r21,1
daddi r22,r22,1
daddi r23,r23,1
daddi r24,r24,1
daddi r25,r25,1
; 依次存储结果
sd r16,a(r0)
sd r17,b(r0)
sd r18,c(r0)
sd r19,d(r0)
sd r20,e(r0)
sd r21,f(r0)
sd r22,g(r0)
sd r23,h(r0)
sd r24,i(r0)
sd r25,j(r0)

halt
