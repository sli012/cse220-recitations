.data
prompt: .asciiz "Enter 2 numbers:\n"
result: .asciiz "Sum: "

.text
.globl main

main:
    # Print prompt
    la $a0, prompt
    li $v0, 4
    syscall
    
    jal read_and_sum      # Call function that uses stack array
    
    # save the result in $s0
    move $s0, $v0
    
    # Print result message
    la $a0, result
    li $v0, 4
    syscall
    
    # Print sum
    move $a0, $s0
    li $v0, 1
    syscall
    
    # Exit
    li $v0, 10
    syscall

read_and_sum:
    # Set up stack frame
    addi $sp, $sp, -16    # Allocate 16 bytes: 4 for $ra + 4 for $fp + 8 for array
    sw $ra, 12($sp)       # Save return address at top
    sw $fp, 8($sp)        # Save old frame pointer
    move $fp, $sp         # Set frame pointer to current stack pointer
    
    # Array layout (stored AFTER saved registers):
    # $fp+0:  array[0]
    # $fp+4:  array[1]
    # $fp+8:  saved $fp
    # $fp+12: saved $ra
    
    # Read 2 integers into stack array
    li $t0, 0             # Loop counter
read_loop:
    bge $t0, 2, end_read  # If counter >= 2, exit loop
    
    # Read integer
    li $v0, 5
    syscall
    
    # Store in array: address = $fp + (counter * 4)
    sll $t1, $t0, 2       # Multiply counter by 4
    add $t2, $fp, $t1     # Calculate address
    sw $v0, 0($t2)        # Store input value
    
    addi $t0, $t0, 1      # Increment counter
    j read_loop

end_read:
    # Calculate sum of array elements
    li $v0, 0             # Initialize sum to 0
    li $t0, 0             # Reset loop counter
sum_loop:
    bge $t0, 2, end_sum   # If counter >= 2, exit loop
    
    # Load element: address = $fp + (counter * 4)
    sll $t1, $t0, 2       # Multiply counter by 4
    add $t2, $fp, $t1     # Calculate address
    lw $t3, 0($t2)        # Load array element
    
    add $v0, $v0, $t3     # Add to sum
    
    addi $t0, $t0, 1      # Increment counter
    j sum_loop

end_sum:
    # Restore frame and return
    lw $fp, 8($sp)        # Restore old frame pointer
    lw $ra, 12($sp)       # Restore return address
    addi $sp, $sp, 16     # Deallocate stack space
    
    jr $ra                # Return with sum in $v0