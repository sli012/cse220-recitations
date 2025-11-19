.data
    # No data needed for this simple recursive example

.text
.globl main

main:
    li $a0, 5
    jal factorial       #calculate factorial of 5

    move $a0, $v0
    li $v0, 1
    syscall

    li $v0, 10
    syscall #terminate
    


# Calculate 5!


factorial:
    addi $sp, $sp, -8       #allocate 8 bytes of memory
    sw $ra, 4($sp)
    sw $a0, 0($sp)

    #Check base condition
    ble $a0, 1, base-case
    
    addi $a0, $a0, -1       # Finds n-1
    jal factorial           #assume $v0 has factorial(n-1)
    
    lw $a0, 0($sp)          #load back n
    mul $v0, $a0, $v0       #find n * factorial(n-1)
    
    lw $ra, 4($sp)          #load original return address
    addi $sp, $sp, 8        #free memory
    jr $ra                  $return

    base_case
        li $v0, 1           #set return value
        lw $ra, 4($sp)      #load orig. return address
        addi $sp, $sp, 8    #free memory
        jr $ra              #Return