.data
myArray: .word 10, 20, 30, 40, 50
arraySize: .word 5

.text
.globl main

main:
    la $a0, myArray       # Load base address of array as argument
    lw $a1, arraySize     # Load array size as argument
    
    jal sum_array_recursive  # Call recursive sum_array function
    
    # Result is now in $v0
    move $a0, $v0         # Move sum to $a0 for printing
    li $v0, 1             # syscall code for print integer
    syscall
    
    li $v0, 10            # syscall code for exit
    syscall

# Function: sum_array_recursive
# Purpose: Recursively calculate the sum of elements in an integer array
# Arguments:
#   $a0 - base address of the array
#   $a1 - size of the array (number of elements remaining)
# Returns:
#   $v0 - sum of all array elements
# Base case: if size == 0, return 0
# Recursive case: return array[0] + sum_array_recursive(array+1, size-1)
sum_array_recursive:
    # Save registers on stack
    addi $sp, $sp, -12    # Allocate space for 3 words
    sw $ra, 0($sp)        # Save return address
    sw $a0, 4($sp)        # Save array address
    sw $a1, 8($sp)        # Save array size
    
    # Base case: if size == 0, return 0
    bne $a1, $zero, recursive_case
    li $v0, 0             # Return 0
    j cleanup
    
recursive_case:
    # Load current element (first element of array)
    lw $t0, 0($a0)        # Load array[0] into $t0
    
    # Prepare arguments for recursive call
    addi $a0, $a0, 4      # Move to next element (array + 1)
    addi $a1, $a1, -1     # Decrease size by 1
    
    # Recursive call
    jal sum_array_recursive
    
    # Add current element to result from recursive call
    add $v0, $v0, $t0     # sum = recursive_sum + current_element
    
cleanup:
    # Restore registers from stack
    lw $ra, 0($sp)        # Restore return address
    lw $a0, 4($sp)        # Restore array address
    lw $a1, 8($sp)        # Restore array size
    addi $sp, $sp, 12     # Deallocate stack space
    
    jr $ra                # Return to caller