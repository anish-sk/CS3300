      .file	"a.c"
      .text
      .section  .rodata
.LC1:
      .string	"%d"
.LC0:
      .string	"%d\n"
      .text
      .globl	main
      .type	main, @function
main:
      .cfi_startproc
      pushq    %rbp
      .cfi_def_cfa_offset 16
      .cfi_offset 6, -16
      movq	%rsp, %rbp
      .cfi_def_cfa_register 6
      subq  $80, %rsp
      leaq -4(%rbp) , %rsi
      leaq .LC1(%rip) , %rdi
      movl $0 , %eax
      call scanf@PLT
      leaq -8(%rbp) , %rsi
      leaq .LC1(%rip) , %rdi
      movl $0 , %eax
      call scanf@PLT
      movl -4(%rbp) , %eax
      imull -8(%rbp) , %eax
      movl %eax , -40(%rbp)
      movl -40(%rbp) , %eax
      sall $3 , %eax
      movl %eax , -44(%rbp)
      movl -44(%rbp) , %eax
      movl %eax , -12(%rbp)
      movl $128 , %eax
      movl %eax , -36(%rbp)
      movl $2 , %eax
      movl %eax , -20(%rbp)
      movl $256 , %eax
      movl %eax , -16(%rbp)
      movl -12(%rbp) , %eax
      sall $8 , %eax
      movl %eax , -48(%rbp)
      movl -48(%rbp) , %eax
      movl %eax , -24(%rbp)
      movl -4(%rbp) , %eax
      imull -8(%rbp) , %eax
      movl %eax , -52(%rbp)
      movl -4(%rbp) , %eax
      addl -8(%rbp) , %eax
      movl %eax , -56(%rbp)
      movl -52(%rbp) , %eax
      addl -56(%rbp) , %eax
      movl %eax , -60(%rbp)
      movl -60(%rbp) , %eax
      movl %eax , -36(%rbp)
      movl -4(%rbp) , %eax
      addl -8(%rbp) , %eax
      movl %eax , -64(%rbp)
      movl -12(%rbp) , %eax
      sall $8 , %eax
      movl %eax , -68(%rbp)
      movl -64(%rbp) , %eax
      addl -68(%rbp) , %eax
      movl %eax , -72(%rbp)
      movl -72(%rbp) , %eax
      movl %eax , -28(%rbp)
      movl -4(%rbp) , %esi
      leaq .LC0(%rip) , %rdi
      movl $0 , %eax
      call printf@PLT
      movl -8(%rbp) , %esi
      leaq .LC0(%rip) , %rdi
      movl $0 , %eax
      call printf@PLT
      movl -12(%rbp) , %esi
      leaq .LC0(%rip) , %rdi
      movl $0 , %eax
      call printf@PLT
      movl -16(%rbp) , %esi
      leaq .LC0(%rip) , %rdi
      movl $0 , %eax
      call printf@PLT
      movl -20(%rbp) , %esi
      leaq .LC0(%rip) , %rdi
      movl $0 , %eax
      call printf@PLT
      movl -24(%rbp) , %esi
      leaq .LC0(%rip) , %rdi
      movl $0 , %eax
      call printf@PLT
      movl -36(%rbp) , %esi
      leaq .LC0(%rip) , %rdi
      movl $0 , %eax
      call printf@PLT
      movl $0 , %eax
      leave
      ret
      leave
      .cfi_def_cfa 7, 8
      ret
      .cfi_endproc
