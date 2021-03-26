.section    .rodata
.LC0: .string "%d\n"
.text
.global main
.type main, @function
main:
pushq %rbp
movq %rsp, %rbp
subq $4, %rsp
subq $4, %rsp
subq $4, %rsp
movl $42, -4(%rsp)
subq $4, %rsp
movl 0(%rsp), %eax
addq $4, %rsp
movl %eax, -4(%rbp)
movl $51, -4(%rsp)
subq $4, %rsp
movl 0(%rsp), %eax
addq $4, %rsp
movl %eax, -8(%rbp)
movl $99, -4(%rsp)
subq $4, %rsp
movl 0(%rsp), %eax
xor %edx, %edx
subl %eax, %edx
movl %edx, 0(%rsp)
movl 0(%rsp), %eax
addq $4, %rsp
movl %eax, -12(%rbp)
movl -8(%rbp), %eax
movl 8 (%rbp), %eax
movl -4(%rbp), %eax
movl 4 (%rbp), %eax
movl 4(%rsp), %edx
movl 0(%rsp), %eax
addq $4, %rsp
cmpl %eax, %edx
jle L0
xor %eax,%eax
movl %eax, 0(%rsp)
L0:
xor %eax,%eax
addl $1, %eax
movl %eax, 0(%rsp)
movl 0(%rsp), %eax
addq $4, %rsp
cmpl $0, %eax
je L1
movl -4(%rbp), %eax
movl %eax, %esi
leaq .LC0(%rip), %rdi
movl $0, %eax
call printf@PLT
movl $1, -4(%rsp)
subq $4, %rsp
movl 0(%rsp), %eax
addq $4, %rsp
movl %eax, -12(%rbp)
jmp L2
L1:
movl -8(%rbp), %eax
movl %eax, %esi
leaq .LC0(%rip), %rdi
movl $0, %eax
call printf@PLT
L2:
movl -12(%rbp), %eax
movl %eax, %esi
leaq .LC0(%rip), %rdi
movl $0, %eax
call printf@PLT
movl -12(%rbp), %eax
movl 12 (%rbp), %eax
movl 0(%rsp), %eax
addq $4, %rsp
cmpl $0, %eax
je L3
movl -8(%rbp), %eax
movl %eax, %esi
leaq .LC0(%rip), %rdi
movl $0, %eax
call printf@PLT
L3:
movl $0, -4(%rsp)
subq $4, %rsp
movl 0(%rsp), %eax
addq $4, %rsp
popq %rbp
ret
