	.text
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"%d\n"
.LC2:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$64, %rsp
	movl	$10, %eax
	movl	%eax, -20(%rbp)
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	scanf@PLT
	movl	$4, %eax
	movl	%eax, -12(%rbp)
	movl	-16(%rbp), %eax
	pushq	%rax
	movl	$10, %eax
	movl	%eax, %esi
	popq	%rax
	subl	%esi, %eax
	movl	%eax, -24(%rbp)
	movl	-16(%rbp), %eax
	pushq	%rax
	movl	$10, %eax
	movl	%eax, %esi
	popq	%rax
	subl	%esi, %eax
	sall	$2, %eax
	movl	%eax, -12(%rbp)
	movl	-24(%rbp), %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-12(%rbp), %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	leave
	ret
