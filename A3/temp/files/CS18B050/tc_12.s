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
   movl	$0, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$-15, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$20, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$-5, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$40, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$0, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$60, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$15, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$80, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$25, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$100, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$35, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$120, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$45, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$140, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$60, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$160, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$70, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$180, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$80, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$200, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$90, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$220, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$100, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$240, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$115, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$260, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$125, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$280, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$135, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$300, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
    movl	$145, %esi 
 leaq	.LC0(%rip), %rdi 
  movl	$0, %eax 
 call printf@PLT  
  popq %rbp 
 ret 
  .size	main, .-main
