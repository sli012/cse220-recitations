.data
    # No data needed for this simple recursive example

.text
.globl main
.globl factorial

main:
    li $a0, 5       # Load the number for which to calculate factorial (e.g., 5!) into argument register
    jal factorial   # Call the factorial function

    # The factorial result is returned in $v0
    # You can add code here to print the result or store it as needed

    li $v0, 10      # System call to exit
    syscall

factorial:
    # Save return address and argument on the stack
    addi $sp, $sp, -8   # Allocate space on stack (for $ra and $a0) - allocates 8 bytes of memory
    sw $ra, 4($sp)      # Save return address
    sw $a0, 0($sp)      # Save argument (n)

    # Base case: if n <= 1, return 1
    ble $a0, 1, base_case

    # Recursive step: factorial(n) = n * factorial(n-1)
    addi $a0, $a0, -1   # Decrement n for the recursive call
    jal factorial       # Recursive call

    # After recursive call returns, $v0 holds factorial(n-1)
    lw $a0, 0($sp)      # Restore original n
    mul $v0, $a0, $v0   # Multiply n by factorial(n-1)

    # Restore return address and pop stack
    lw $ra, 4($sp)
    addi $sp, $sp, 8
    jr $ra              # Return to caller

base_case:
    li $v0, 1           # Base case: factorial(0) = 1, factorial(1) = 1
    # Restore return address and pop stack
    lw $ra, 4($sp)
    addi $sp, $sp, 8
    jr $ra              # Return to caller