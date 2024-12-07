.data   
array:  .word   0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1

.text   
    daddi   r23,    r0,     array                               # 数组的地址加载
    daddi   r9,     r0,     16                                  # 数组长度
    daddi   r8,     r0,     0                                   # 计数器r8
loop:       dsll    r11,    r8,     3                           # 根据计数器得到偏移量
    dadd    r10,    r11,    r23                                 # 数组元素地址
    ld      r12,    0(r10)                                      # 取值
    daddi   r8,     r8,     1                                   # 计数器自增
    bne     r12,    r0,     loop                                # 元素若不为0的判断
    slt     r10,    r8,     r9                                  # 计数器是否小于数组长度
    bne     r10,    r0,     loop                                # 没有越界就继续遍历
    daddi   r17,    r0,     1                                   # 辅助(无意义)

    halt