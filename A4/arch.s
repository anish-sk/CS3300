     .file "a.c"
     .text
     .section .rodata
.LC1: 
    .string "%d"
.LC0: 
	.string "%d\n"
	.text
	.globl main
	.type main, @function
main:
    .cfi_startproc
    pushq    %rbp
    .cfi_def_cfa_offset 16
    .cfi_offset 6, -16
    movq	%rsp, %rbp
    .cfi_def_cfa_register 6
    subq $12, %rsp
	movl $3, %eax
	pushq %rax
	movl $2, %eax
	popq %rbx
	addl %ebx, %eax
	sall $3, %eax 
	movl $2, %eax
	pushq %rax
	movl $7, %eax
	popq %rbx
	subl %ebx, %eax
	pushq %rax
	movl $3, %eax
	popq %rbx
	addl %ebx, %eax
	pushq %rax
	movl $3, %eax
	pushq %rax
	movl $2, %eax
	popq %rbx
	addl %ebx, %eax
	popq %rbx
	imull %ebx, %eax
	movl %eax, -4(%rbp)
	leaq -8(%rbp), %rax 
	movq  %rax, %rsi
	leaq  .LC1(%rip), %rdi
	movl  $0, %eax
	call  scanf@PLT
	movl $5, %eax
	pushq %rax
	movl -8(%rbp), %eax
	popq %rbx
	addl %ebx, %eax
	sall $-1, %eax 
	movl $3, %eax
	pushq %rax
	movl $2, %eax
	popq %rbx
	addl %ebx, %eax
	pushq %rax
	movl $5, %eax
	pushq %rax
	movl -8(%rbp), %eax
	popq %rbx
	addl %ebx, %eax
	popq %rbx
	imull %ebx, %eax
	movl %eax, -8(%rbp)
	movl $10, %eax
	pushq %rax
	movl -8(%rbp), %eax
	popq %rbx
	addl %ebx, %eax
	movl %eax, -8(%rbp)
		movl -8(%rbp), %esi
		leaq .LC0(%rip), %rdi
		movl $0, %eax
		call printf@PLT
	movl $0, %eax
		movl $0, %eax
		leave
		ret
		leave
              .cfi_def_cfa 7, 8
		ret
              .cfi_endproc

