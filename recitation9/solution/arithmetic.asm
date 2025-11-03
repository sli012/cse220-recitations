.data
string1: .asciiz "Enter a number : "
endLine: .asciiz "\n"
string2: .asciiz "Addition result is  : "
string3: .asciiz "Substraction result is : "
string4: .asciiz "Result is : "

.text
main:

j EnteraNumber

EnteraNumber:
li $v0,4
la $a0,string1
syscall

li $v0,5
syscall
move $t0,$v0

li $v0,4
la $a0,string1    #cout<<Enter a number
syscall

li $v0,5
syscall
move $t1,$v0

# Check conditions
beq $t0,$t1, Addition      # If numbers are equal, do addition
bgt $t0,$t1, Substraction  # If first > second, do subtraction
j ReturnZero               # Otherwise, return 0

Addition:
add $t2,$t1,$t0
li $v0,4
la $a0,string2    #cout<<Addition result is 
syscall

li $v0,1
move $a0,$t2
syscall
j end_label

Substraction:
sub $t2,$t0,$t1
li $v0,4
la $a0,string3    #cout<<Substraction result is 
syscall

li $v0,1
move $a0,$t2
syscall
j end_label

ReturnZero:
li $t2, 0
li $v0,4
la $a0,string4    #cout<<Result is 
syscall

li $v0,1
move $a0,$t2
syscall
j end_label

end_label:
li $v0, 10        #exit
syscall