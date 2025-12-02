.data
inputStr: .asciiz "racecar"


.text
.globl main

main:

	# $a0 = left address = address of inputStr = &inputStr[0]
	# $a1
	
	# length is 7 
	
	# inputStr + length - 1
	# inputStr + 6 = &inputStr[-1]
	
	la $a0, inputStr
	la $a1, inputStr
	addi $a1, $a1, 6
	
	# $a0 has left address
	# $a1 has right address
	
	
	jal isPalindrome
	
	
	# after the check $v0 
	# $v0 holds either 0 or 1
	# 1 means they are palindrome
	# 0 means they are not
	
	move $a0, $v0
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall
	



isPalindrome:

	# 1. preserve $ra and $arguments
	# 2. check base case
	# 3. perform recursive step
	# 4. unwind
	
	# preserve $ra, $a0, $a1
	
	addi $sp, $sp, -12
	sw $ra, 0($sp)
	sw $a0, 4($sp)
	sw $a1, 8($sp)
	

	# base case 1: if left char != right char; return 0
	# base case 2: if left addr >= right address; return 1
	
	# check base case 1
	# read left character into $t0
	# read right character into $t1
	lb $t0, 0($a0) # inputStr[0]
	lb $t1, 0($a1) # inputStr[-1]
	
	bne $t0, $t1, base_case1
	
	# base case 2: if left addr >= right address; return 1
	
	bge $a0, $a1, base_case2
	
	
	# 3. perform recursive step
	
	# leftAddr + 1, rightAddr - 1
	
	addi $a0, $a0, 1
	addi $a1, $a1, -1
	
	jal isPalindrome
	
	# 4. unwind
	
	# restore registers
	
	lw $ra, 0($sp)
	lw $a0, 4($sp)
	lw $a1, 8($sp)
	addi $sp, $sp, 12
	jr $ra
	
	



base_case1:
li $v0, 0
jr $ra

base_case2:
li $v0, 1
jr $ra


	
