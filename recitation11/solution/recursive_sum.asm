.data
myArray: .word 10, 20, 30, 40, 50
arraySize: .word 5
result_msg: .asciiz "Sum = "
newline: .asciiz "\n"

.text
.globl main

main:
    # Load array address and size
    la $a0, myArray
    lw $a1, arraySize
    li $a2, 0               # Start at index 0
    
    # Call recursive_sum_index(arr, length, index)
    jal recursive_sum_index
    
    # Print result
    move $t0, $v0           # Save result
    li $v0, 4               # Print string syscall
    la $a0, result_msg
    syscall
    
    li $v0, 1               # Print integer syscall
    move $a0, $t0
    syscall
    
    li $v0, 4               # Print newline
    la $a0, newline
    syscall
    
    # Exit program
    li $v0, 10
    syscall

recursive_sum_index:
    # $a0 = arr (base pointer to array)
    # $a1 = length (total length of array)
    # $a2 = index (current index)
    # Returns: $v0 = sum from arr[index] to arr[length-1]
    
    # Allocate stack space
    addi $sp, $sp, -16
    sw $ra, 12($sp)         # Save return address
    sw $a0, 8($sp)          # Save array pointer
    sw $a1, 4($sp)          # Save length
    sw $a2, 0($sp)          # Save index
    
    # Base case: if index >= length, return 0
    bge $a2, $a1, base_case
    
    # Prepare for recursive call with index+1
    addi $a2, $a2, 1        # index++
    
    jal recursive_sum_index # Recursive call
    
    # $v0 now contains sum of arr[index+1..length-1]
    # $t0 contains arr[index]
    lw $ra, 12($sp)
    lw $a0, 8($sp)
    lw $a1, 4($sp)
    lw $a2, 0($sp)
    
    # Calculate address of arr[index]
    sll $t1, $a2, 2         # $t1 = index * 4 (word offset)
    add $t1, $a0, $t1       # $t1 = arr + (index * 4)
    lw $t0, 0($t1)          # $t0 = arr[index]
    
    add $v0, $t0, $v0       # sum = arr[index] + recursive_sum(index+1)
    
    # Restore and return
    addi $sp, $sp, 16
    jr $ra
    
base_case:
    li $v0, 0               # Return 0
    lw $ra, 12($sp)
    addi $sp, $sp, 16
    jr $ra