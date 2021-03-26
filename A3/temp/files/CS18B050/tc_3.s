.file   " input.c " 
.text 
	.section	.rodata 
 .LC0: 
 .string	"%d\n" 
 .globl main
 .type main, @function 
main: 
 pushq %rbp 
 movq	%rsp, %rbp 
   movl	$6, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$5, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$4, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$3, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$2, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$1, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
  popq %rbp 
 ret 
  .size	main, .-main
