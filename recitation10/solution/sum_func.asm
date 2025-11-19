.data
myArray: .word 10, 20, 30, 40, 50
arraySize: .word 5

.text
.globl main

main:
    la $a0, myArray       # Load base address of array as argument
    lw $a1, arraySize     # Load array size as argument
    
    jal sum_array         # Call sum_array function
    
    # Result is now in $v0
    move $a0, $v0         # Move sum to $a0 for printing
    li $v0, 1             # syscall code for print integer
    syscall
    
    li $v0, 10            # syscall code for exit
    syscall

sum_array:
    li $v0, 0             # Initialize sum to 0 in $v0 (return value)
    li $t0, 0             # Initialize loop index to 0

sum_loop:
    bge $t0, $a1, end_sum_loop # If index >= size, exit loop
    
    sll $t1, $t0, 2       # Calculate offset: index * 4 (word size)
    add $t2, $a0, $t1     # Calculate address of current element
    lw $t3, 0($t2)        # Load element value into $t3
    
    add $v0, $v0, $t3     # Add element to sum
    
    addi $t0, $t0, 1      # Increment loop index
    j sum_loop            # Jump back to start of loop

end_sum_loop:
    jr $ra                # Return to caller