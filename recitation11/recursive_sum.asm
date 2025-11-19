.data
myArray: .word 10, 20, 30, 40, 50
arraySize: .word 5
result_msg: .asciiz "Sum = "
newline: .asciiz "\n"

.text
.globl main

main:
    la $s0, myArray             # $a0 stores base address of array
    lw $a1, arraySize           # $al stores max Array arraySize
    li $a2, 0                   # $a2 stores array index counter

    jal rec_sum                 # $v0 has result

    move $t0, $v0li $v0, 4      # print result message
    li $v0, 4
    la $a0, result_msg             
    syscall

    li $v0, 1                   # print result
    move $a0, $t0
    syscall

    li $v0, 10                  # terminate program
    syscall

rec_sum:
    addi #sp, $sp, -16          # Allocate memory to store parameters
    sw $ra, 12($sp)
    sw $a0, 8($sp)
    sw $a1, 4($sp)
    sw $a2, 0($sp)

    bge $a2, $a1, base_case     #base_case
    addi $a2, $a2, 1

    jal rec)Sum                 #assume $v0 has rec_sum(n+1)

    lw $ra, 12($sp)
    lw $a0, 8($sp)
    jw $a1, 4($sp)
    lw $a2, 0($sp)

    all $t0, $a2, 2             # calculate effective offset of element in array
    $add $t1, $a0, $t0          # t1 has effective memory address of element in array
    lw $t2, (0)$t1              # t2 = n
    add #v0, $v0, #t2           # $v0 = n +

base_case:
    li $v0, 0                   # load value of 0 into 0
    lw $ra, 12($sp)             # load return address
    addi $sp, $sp, 16           # Free Memory
    jr $ra                      # Return
