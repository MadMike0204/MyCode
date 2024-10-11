    .data
length: .word 10                    # 数组长度
Array:  .word 1,7,2,4,7,1,5,2,4,5   # 数组初始化

    .text
    .globl main

# int swap(int& a, int& b) function
swap:
    ld $t0, 0($a0)          # $t0 = *a (加载 a 的值)
    ld $t1, 0($a1)          # $t1 = *b (加载 b 的值)
    sd $t1, 0($a0)          # *a = b (将 b 存储到 a 的地址)
    sd $t0, 0($a1)          # *b = a (将 a 存储到 b 的地址)
    jr $ra                  # 返回

# void Bubble_Sort() function
Bubble_Sort:
    daddi $t2, $zero, 1     # $t2 = 1, flag = 1 (初始化 flag)
while_flag:
    beq $t2, $zero, end_sort   # 如果 flag = 0，则结束排序
    daddi $t2, $zero, 0     # flag = 0 (重置 flag)

    daddi $t3, $zero, 0     # i = 0 (数组索引)
for_loop:
    ld $t4, Array($t3)      # $t4 = Array[i]
    ld $t5, Array+8($t3)    # $t5 = Array[i+1] (8 字节对齐，因 64 位)
    ble $t4, $t5, next      # 如果 Array[i] <= Array[i+1]，跳过交换

    daddi $t2, $zero, 1     # flag = 1 (设置 flag)
    daddi $a0, $t3, Array   # a = &Array[i]
    daddi $a1, $t3, Array+8 # b = &Array[i+1]
    jal swap                # 调用 swap 函数

next:
    daddi $t3, $t3, 8       # i++
    daddi $t6, $zero, length # $t6 = length
    dsubu $t6, $t6, 1       # length - 1
    bne $t3, $t6, for_loop  # 如果 i < length - 1，继续循环

    j while_flag           # 重新检查 flag

end_sort:
    jr $ra                  # 返回

# main function
main:
    # 打印排序前数组
    la $a0, before_message
    li $v0, 4               # 系统调用，打印字符串
    syscall

    daddi $t3, $zero, 0     # i = 0
print_before:
    ld $a0, Array($t3)      # $a0 = Array[i]
    li $v0, 1               # 系统调用，打印整数
    syscall
    daddi $t3, $t3, 8       # i++
    daddi $t6, $zero, length
    bne $t3, $t6, print_before

    # 调用冒泡排序
    jal Bubble_Sort

    # 打印排序后数组
    la $a0, after_message
    li $v0, 4               # 系统调用，打印字符串
    syscall

    daddi $t3, $zero, 0     # i = 0
print_after:
    ld $a0, Array($t3)      # $a0 = Array[i]
    li $v0, 1               # 系统调用，打印整数
    syscall
    daddi $t3, $t3, 8       # i++
    daddi $t6, $zero, length
    bne $t3, $t6, print_after

    li $v0, 10              # 退出程序
    syscall

# .data 段中的字符串
    .data
before_message: .asciiz "Before sort the array is:\n"
after_message:  .asciiz "After sort the array is:\n"
