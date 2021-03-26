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
      subq  $64, %rsp
      movl $10 , %eax
      movl %eax , -4(%rbp)
      leaq -8(%rbp) , %rsi
      leaq .LC1(%rip) , %rdi
      movl $0 , %eax
      call scanf@PLT
      movl $10 , %eax
      addl -8(%rbp) , %eax
      movl %eax , -16(%rbp)
      movl -16(%rbp) , %eax
      imull -16(%rbp) , %eax
      movl %eax , -24(%rbp)
      movl -24(%rbp) , %eax
      movl %eax , -12(%rbp)
      movl $1 , %eax
      movl -8(%rbp) , %ebx
      cmpl %eax , %ebx
      sete %al
      movzbl %al , %eax
      movl %eax , -28(%rbp)
      movl -28(%rbp) , %eax
      cmpl $0 , %eax
      je .L1
      leaq -4(%rbp) , %rsi
      leaq .LC1(%rip) , %rdi
      movl $0 , %eax
      call scanf@PLT
      movl -4(%rbp) , %eax
      addl -8(%rbp) , %eax
      movl %eax , -32(%rbp)
      movl -4(%rbp) , %eax
      addl -8(%rbp) , %eax
      movl %eax , -36(%rbp)
      movl -32(%rbp) , %eax
      imull -36(%rbp) , %eax
      movl %eax , -40(%rbp)
      movl -40(%rbp) , %eax
      movl %eax , -8(%rbp)
      movl -4(%rbp) , %esi
      leaq .LC0(%rip) , %rdi
      movl $0 , %eax
      call printf@PLT
      movl -8(%rbp) , %esi
      leaq .LC0(%rip) , %rdi
      movl $0 , %eax
      call printf@PLT
      jmp .L2
.L1:
      movl $10 , %eax
      addl -8(%rbp) , %eax
      movl %eax , -44(%rbp)
      movl $10 , %eax
      addl -8(%rbp) , %eax
      movl %eax , -48(%rbp)
      movl -44(%rbp) , %eax
      imull -48(%rbp) , %eax
      movl %eax , -52(%rbp)
      movl -52(%rbp) , %eax
      movl %eax , -8(%rbp)
      movl -4(%rbp) , %esi
      leaq .LC0(%rip) , %rdi
      movl $0 , %eax
      call printf@PLT
      movl -8(%rbp) , %esi
      leaq .LC0(%rip) , %rdi
      movl $0 , %eax
      call printf@PLT
.L2:
      movl $0 , %eax
      leave
      ret
      leave
      .cfi_def_cfa 7, 8
      ret
      .cfi_endproc
