.data  
array:      .word 9, 6, 8, 5, 7, 4, 3, 2, 1, 0  
STR1:       .asciiz "2022192009's Shell Sort \nbefore sort the array is: \n"  
STR2:       .asciiz "after sort the array is: \n"  
CONTROL:    .word32 0x10000  
DATA:       .word32 0x10008  
            .space 64  
sp:         .word32 0   

.text  
main:  
    ld r1, CONTROL(r0)   
    ld r2, DATA(r0)	  
    daddi r0, r0, 0  
    daddi r3, r0, STR1  
    daddi r4, r0, 4  
    sd r3, 0(r2)  
    sd r4, 0(r1)  
    daddi r3, r0, 0  

print1:  
    ld r4, array(r3)  
    sd r4, 0(r2)   
    daddi r5, r0, 2    
    sd r5, 0(r1)  
    daddi r3, r3, 8  
    daddi r4, r3, -80   
    beqz r4, print_end1  
    j print1  
	  
print_end1:  
    daddi r0, r0, 0  
    daddi r3, r0, STR2  
    daddi r4, r0, 4  
    sd r3, 0(r2)  
    sd r4, 0(r1)  
	  
    daddi $sp, r0, sp  
    daddi r5, r0, array   
    daddi r6, r0, 10  
    jal shell_sort  
   
swap:  
    dsll r6, r6, 3  
    dadd r11, r6, r5   
    ld r12, 0(r11)  
    ld r13, 8(r11)  
    sd r12, 8(r11)  
    sd r13, 0(r11)  
    jr $ra  
	  
shell_sort:  
    daddi $sp, $sp, -32  
    sd $ra, 0($sp)   
    sd r8, 8($sp)  
    sd r9, 16($sp)  
    sd r10, 24($sp)  

    daddi r8, r0, 5  
	  
outer_loop:  
    daddi r9, r0, 0

inner_loop:  
    dadd r10, r9, r8 
    slt r14, r10, r6
    bnez r14, end_inner_loop
 
    ld r11, array(r9)  
    ld r12, array(r10)
    slt r14, r11, r12
    beqz r14, no_swap
    jal swap

no_swap:  
    daddi r9, r9, 1  
    j inner_loop  

end_inner_loop:  
    daddi r8, r8, -1
    bnez r8, outer_loop

    ld $ra, 0($sp)  
    ld r8, 8($sp)  
    ld r9, 16($sp)  
    ld r10, 24($sp)  
    daddi $sp, $sp, 32  
    daddi r3, r0, 0  

print2:  
    ld r4, array(r3)  
    sd r4, 0(r2)  
    daddi r5, r0, 2    
    sd r5, 0(r1)  
    daddi r3, r3, 8  
    daddi r4, r3, -80  
    beqz r4, tohalt  
    j print2  

tohalt:  
    halt