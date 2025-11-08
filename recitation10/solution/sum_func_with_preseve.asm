.data
myArray: .word 10, 20, 30, 40, 50
arraySize: .word 5

.text
.globl main

# NOTE: the only difference here is we use $s0, so we have to preseve it.
# THIS IS INTENTIONAL to show preserving registers, if you don't want to go through the hassle of preserving anything, you can use the other registers :3


main:
    la $a0, myArray       # Load base address of array as argument
    lw $s0, arraySize     # Load array size into $s0
    
    jal sum_array         # Call sum_array function
    
    # Result is now in $v0
    move $a0, $v0         # Move sum to $a0 for printing
    li $v0, 1             # syscall code for print integer
    syscall
    
    li $v0, 10            # syscall code for exit
    syscall

sum_array:
    # Save $s0 and $ra on the stack
    addi $sp, $sp, -8     # Allocate 8 bytes on stack
    sw $s0, 4($sp)        # Save $s0 at offset 4
    sw $ra, 0($sp)        # Save $ra at offset 0
    
    li $v0, 0             # Initialize sum to 0 in $v0 (return value)
    li $t0, 0             # Initialize loop index to 0

sum_loop:
    bge $t0, $s0, end_sum_loop # If index >= size, exit loop
    
    sll $t1, $t0, 2       # Calculate offset: index * 4 (word size)
    add $t2, $a0, $t1     # Calculate address of current element
    lw $t3, 0($t2)        # Load element value into $t3
    
    add $v0, $v0, $t3     # Add element to sum
    
    addi $t0, $t0, 1      # Increment loop index
    j sum_loop            # Jump back to start of loop

end_sum_loop:
    # Restore $s0 and $ra from the stack
    lw $ra, 0($sp)        # Restore $ra
    lw $s0, 4($sp)        # Restore $s0
    addi $sp, $sp, 8      # Deallocate stack space
    
    jr $ra                # Return to caller