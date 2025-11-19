########## Evaluates Ax^2 + Bx + C ##########
# Values of x, A, B, C are entered by user


.data
promptX: .asciiz "Enter x: "
promptA: .asciiz "Enter A: "
promptB: .asciiz "Enter B: "
promptC: .asciiz "Enter C: "
ans:  .asciiz "Answer: "
endl: .asciiz "\n"

.text
.globl main
main:
