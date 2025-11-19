.data
myArray: .word 10, 20, 30, 40, 50
arraySize: .word 5

.text
.globl main
main:
    la $s0, myArray       # Load base address of myArray into $s0
    lw $s1, arraySize     # Load array size into $s1
    li $t0, 0             # Initialize sum to 0 in $t0
    li $t1, 0             # Initialize loop index to 0 in $t1

sum_loop:
    bge $t1, $s1, end_sum_loop # If index >= size, exit loop

    sll $t2, $t1, 2       # Calculate offset: index * 4 (for word size)
    add $t3, $s0, $t2     # Calculate address of current element
    lw $t4, 0($t3)        # Load element value into $t4

    add $t0, $t0, $t4     # Add element to sum

    addi $t1, $t1, 1      # Increment loop index
    j sum_loop            # Jump back to start of loop

end_sum_loop:
    # The sum is now in $t0
    # You can now print the sum or use it for other operations
    li $v0, 1             # syscall code for print integer
    move $a0, $t0         # move sum to $a0 for printing
    syscall

    li $v0, 10            # syscall code for exit
    syscall