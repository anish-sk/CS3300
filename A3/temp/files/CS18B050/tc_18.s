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
   movl	$21, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$36, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$18, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$19, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$9, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$7, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$12, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$12, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$9, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$12, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$6, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
  popq %rbp 
 ret 
  .size	main, .-main
