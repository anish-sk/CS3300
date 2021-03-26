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
    movl	$30, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$42, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$52, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$60, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$66, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$70, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$72, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$72, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$70, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$66, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$60, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$52, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$42, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$30, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$16, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$16, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$30, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$42, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$52, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$60, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$66, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$70, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$16, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$72, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$70, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$66, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$60, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$52, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$42, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$30, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$72, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$0, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
  popq %rbp 
 ret 
  .size	main, .-main
