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
   movl	$16, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$16, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$11, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$16, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$10, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$10, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$15, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$14, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$15, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$17, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$8, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
  popq %rbp 
 ret 
  .size	main, .-main
