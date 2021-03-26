
./san:     file format elf64-x86-64


Disassembly of section .init:

00000000000004f0 <_init>:
 4f0:	48 83 ec 08          	sub    $0x8,%rsp
 4f4:	48 8b 05 ed 0a 20 00 	mov    0x200aed(%rip),%rax        # 200fe8 <__gmon_start__>
 4fb:	48 85 c0             	test   %rax,%rax
 4fe:	74 02                	je     502 <_init+0x12>
 500:	ff d0                	callq  *%rax
 502:	48 83 c4 08          	add    $0x8,%rsp
 506:	c3                   	retq   

Disassembly of section .plt:

0000000000000510 <.plt>:
 510:	ff 35 aa 0a 20 00    	pushq  0x200aaa(%rip)        # 200fc0 <_GLOBAL_OFFSET_TABLE_+0x8>
 516:	ff 25 ac 0a 20 00    	jmpq   *0x200aac(%rip)        # 200fc8 <_GLOBAL_OFFSET_TABLE_+0x10>
 51c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000000520 <printf@plt>:
 520:	ff 25 aa 0a 20 00    	jmpq   *0x200aaa(%rip)        # 200fd0 <printf@GLIBC_2.2.5>
 526:	68 00 00 00 00       	pushq  $0x0
 52b:	e9 e0 ff ff ff       	jmpq   510 <.plt>

Disassembly of section .plt.got:

0000000000000530 <__cxa_finalize@plt>:
 530:	ff 25 c2 0a 20 00    	jmpq   *0x200ac2(%rip)        # 200ff8 <__cxa_finalize@GLIBC_2.2.5>
 536:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

0000000000000540 <_start>:
 540:	31 ed                	xor    %ebp,%ebp
 542:	49 89 d1             	mov    %rdx,%r9
 545:	5e                   	pop    %rsi
 546:	48 89 e2             	mov    %rsp,%rdx
 549:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
 54d:	50                   	push   %rax
 54e:	54                   	push   %rsp
 54f:	4c 8d 05 6a 02 00 00 	lea    0x26a(%rip),%r8        # 7c0 <__libc_csu_fini>
 556:	48 8d 0d f3 01 00 00 	lea    0x1f3(%rip),%rcx        # 750 <__libc_csu_init>
 55d:	48 8d 3d c1 00 00 00 	lea    0xc1(%rip),%rdi        # 625 <main>
 564:	ff 15 76 0a 20 00    	callq  *0x200a76(%rip)        # 200fe0 <__libc_start_main@GLIBC_2.2.5>
 56a:	f4                   	hlt    
 56b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000000570 <deregister_tm_clones>:
 570:	48 8d 3d 99 0a 20 00 	lea    0x200a99(%rip),%rdi        # 201010 <__TMC_END__>
 577:	48 8d 05 92 0a 20 00 	lea    0x200a92(%rip),%rax        # 201010 <__TMC_END__>
 57e:	48 39 f8             	cmp    %rdi,%rax
 581:	74 15                	je     598 <deregister_tm_clones+0x28>
 583:	48 8b 05 4e 0a 20 00 	mov    0x200a4e(%rip),%rax        # 200fd8 <_ITM_deregisterTMCloneTable>
 58a:	48 85 c0             	test   %rax,%rax
 58d:	74 09                	je     598 <deregister_tm_clones+0x28>
 58f:	ff e0                	jmpq   *%rax
 591:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
 598:	c3                   	retq   
 599:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000005a0 <register_tm_clones>:
 5a0:	48 8d 3d 69 0a 20 00 	lea    0x200a69(%rip),%rdi        # 201010 <__TMC_END__>
 5a7:	48 8d 35 62 0a 20 00 	lea    0x200a62(%rip),%rsi        # 201010 <__TMC_END__>
 5ae:	48 29 fe             	sub    %rdi,%rsi
 5b1:	48 89 f0             	mov    %rsi,%rax
 5b4:	48 c1 ee 3f          	shr    $0x3f,%rsi
 5b8:	48 c1 f8 03          	sar    $0x3,%rax
 5bc:	48 01 c6             	add    %rax,%rsi
 5bf:	48 d1 fe             	sar    %rsi
 5c2:	74 14                	je     5d8 <register_tm_clones+0x38>
 5c4:	48 8b 05 25 0a 20 00 	mov    0x200a25(%rip),%rax        # 200ff0 <_ITM_registerTMCloneTable>
 5cb:	48 85 c0             	test   %rax,%rax
 5ce:	74 08                	je     5d8 <register_tm_clones+0x38>
 5d0:	ff e0                	jmpq   *%rax
 5d2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
 5d8:	c3                   	retq   
 5d9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000005e0 <__do_global_dtors_aux>:
 5e0:	80 3d 29 0a 20 00 00 	cmpb   $0x0,0x200a29(%rip)        # 201010 <__TMC_END__>
 5e7:	75 2f                	jne    618 <__do_global_dtors_aux+0x38>
 5e9:	55                   	push   %rbp
 5ea:	48 83 3d 06 0a 20 00 	cmpq   $0x0,0x200a06(%rip)        # 200ff8 <__cxa_finalize@GLIBC_2.2.5>
 5f1:	00 
 5f2:	48 89 e5             	mov    %rsp,%rbp
 5f5:	74 0c                	je     603 <__do_global_dtors_aux+0x23>
 5f7:	48 8b 3d 0a 0a 20 00 	mov    0x200a0a(%rip),%rdi        # 201008 <__dso_handle>
 5fe:	e8 2d ff ff ff       	callq  530 <__cxa_finalize@plt>
 603:	e8 68 ff ff ff       	callq  570 <deregister_tm_clones>
 608:	c6 05 01 0a 20 00 01 	movb   $0x1,0x200a01(%rip)        # 201010 <__TMC_END__>
 60f:	5d                   	pop    %rbp
 610:	c3                   	retq   
 611:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
 618:	c3                   	retq   
 619:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000000620 <frame_dummy>:
 620:	e9 7b ff ff ff       	jmpq   5a0 <register_tm_clones>

0000000000000625 <main>:
.LC0: .string "%d\n"
.text
.global main
.type main, @function
main:
pushq %rbp
 625:	55                   	push   %rbp
movq %rsp, %rbp
 626:	48 89 e5             	mov    %rsp,%rbp
subq $4, %rsp
 629:	48 83 ec 04          	sub    $0x4,%rsp
subq $4, %rsp
 62d:	48 83 ec 04          	sub    $0x4,%rsp
subq $4, %rsp
 631:	48 83 ec 04          	sub    $0x4,%rsp
movl $42, -4(%rsp)
 635:	c7 44 24 fc 2a 00 00 	movl   $0x2a,-0x4(%rsp)
 63c:	00 
subq $4, %rsp
 63d:	48 83 ec 04          	sub    $0x4,%rsp
movl 0(%rsp), %eax
 641:	8b 04 24             	mov    (%rsp),%eax
addq $4, %rsp
 644:	48 83 c4 04          	add    $0x4,%rsp
movl %eax, -4(%rbp)
 648:	89 45 fc             	mov    %eax,-0x4(%rbp)
movl $51, -4(%rsp)
 64b:	c7 44 24 fc 33 00 00 	movl   $0x33,-0x4(%rsp)
 652:	00 
subq $4, %rsp
 653:	48 83 ec 04          	sub    $0x4,%rsp
movl 0(%rsp), %eax
 657:	8b 04 24             	mov    (%rsp),%eax
addq $4, %rsp
 65a:	48 83 c4 04          	add    $0x4,%rsp
movl %eax, -8(%rbp)
 65e:	89 45 f8             	mov    %eax,-0x8(%rbp)
movl $99, -4(%rsp)
 661:	c7 44 24 fc 63 00 00 	movl   $0x63,-0x4(%rsp)
 668:	00 
subq $4, %rsp
 669:	48 83 ec 04          	sub    $0x4,%rsp
movl 0(%rsp), %eax
 66d:	8b 04 24             	mov    (%rsp),%eax
xor %edx, %edx
 670:	31 d2                	xor    %edx,%edx
subl %eax, %edx
 672:	29 c2                	sub    %eax,%edx
movl %edx, 0(%rsp)
 674:	89 14 24             	mov    %edx,(%rsp)
movl 0(%rsp), %eax
 677:	8b 04 24             	mov    (%rsp),%eax
addq $4, %rsp
 67a:	48 83 c4 04          	add    $0x4,%rsp
movl %eax, -12(%rbp)
 67e:	89 45 f4             	mov    %eax,-0xc(%rbp)
movl -8(%rbp), %eax
 681:	8b 45 f8             	mov    -0x8(%rbp),%eax
movl 8 (%rbp), %eax
 684:	8b 45 08             	mov    0x8(%rbp),%eax
movl -4(%rbp), %eax
 687:	8b 45 fc             	mov    -0x4(%rbp),%eax
movl 4 (%rbp), %eax
 68a:	8b 45 04             	mov    0x4(%rbp),%eax
movl 4(%rsp), %edx
 68d:	8b 54 24 04          	mov    0x4(%rsp),%edx
movl 0(%rsp), %eax
 691:	8b 04 24             	mov    (%rsp),%eax
addq $4, %rsp
 694:	48 83 c4 04          	add    $0x4,%rsp
cmpl %eax, %edx
 698:	39 c2                	cmp    %eax,%edx
jle L0
 69a:	7e 05                	jle    6a1 <L0>
xor %eax,%eax
 69c:	31 c0                	xor    %eax,%eax
movl %eax, 0(%rsp)
 69e:	89 04 24             	mov    %eax,(%rsp)

00000000000006a1 <L0>:
L0:
xor %eax,%eax
 6a1:	31 c0                	xor    %eax,%eax
addl $1, %eax
 6a3:	83 c0 01             	add    $0x1,%eax
movl %eax, 0(%rsp)
 6a6:	89 04 24             	mov    %eax,(%rsp)
movl 0(%rsp), %eax
 6a9:	8b 04 24             	mov    (%rsp),%eax
addq $4, %rsp
 6ac:	48 83 c4 04          	add    $0x4,%rsp
cmpl $0, %eax
 6b0:	83 f8 00             	cmp    $0x0,%eax
je L1
 6b3:	74 2e                	je     6e3 <L1>
movl -4(%rbp), %eax
 6b5:	8b 45 fc             	mov    -0x4(%rbp),%eax
movl %eax, %esi
 6b8:	89 c6                	mov    %eax,%esi
leaq .LC0(%rip), %rdi
 6ba:	48 8d 3d 13 01 00 00 	lea    0x113(%rip),%rdi        # 7d4 <_IO_stdin_used+0x4>
movl $0, %eax
 6c1:	b8 00 00 00 00       	mov    $0x0,%eax
call printf@PLT
 6c6:	e8 55 fe ff ff       	callq  520 <printf@plt>
movl $1, -4(%rsp)
 6cb:	c7 44 24 fc 01 00 00 	movl   $0x1,-0x4(%rsp)
 6d2:	00 
subq $4, %rsp
 6d3:	48 83 ec 04          	sub    $0x4,%rsp
movl 0(%rsp), %eax
 6d7:	8b 04 24             	mov    (%rsp),%eax
addq $4, %rsp
 6da:	48 83 c4 04          	add    $0x4,%rsp
movl %eax, -12(%rbp)
 6de:	89 45 f4             	mov    %eax,-0xc(%rbp)
jmp L2
 6e1:	eb 16                	jmp    6f9 <L2>

00000000000006e3 <L1>:
L1:
movl -8(%rbp), %eax
 6e3:	8b 45 f8             	mov    -0x8(%rbp),%eax
movl %eax, %esi
 6e6:	89 c6                	mov    %eax,%esi
leaq .LC0(%rip), %rdi
 6e8:	48 8d 3d e5 00 00 00 	lea    0xe5(%rip),%rdi        # 7d4 <_IO_stdin_used+0x4>
movl $0, %eax
 6ef:	b8 00 00 00 00       	mov    $0x0,%eax
call printf@PLT
 6f4:	e8 27 fe ff ff       	callq  520 <printf@plt>

00000000000006f9 <L2>:
L2:
movl -12(%rbp), %eax
 6f9:	8b 45 f4             	mov    -0xc(%rbp),%eax
movl %eax, %esi
 6fc:	89 c6                	mov    %eax,%esi
leaq .LC0(%rip), %rdi
 6fe:	48 8d 3d cf 00 00 00 	lea    0xcf(%rip),%rdi        # 7d4 <_IO_stdin_used+0x4>
movl $0, %eax
 705:	b8 00 00 00 00       	mov    $0x0,%eax
call printf@PLT
 70a:	e8 11 fe ff ff       	callq  520 <printf@plt>
movl -12(%rbp), %eax
 70f:	8b 45 f4             	mov    -0xc(%rbp),%eax
movl 12 (%rbp), %eax
 712:	8b 45 0c             	mov    0xc(%rbp),%eax
movl 0(%rsp), %eax
 715:	8b 04 24             	mov    (%rsp),%eax
addq $4, %rsp
 718:	48 83 c4 04          	add    $0x4,%rsp
cmpl $0, %eax
 71c:	83 f8 00             	cmp    $0x0,%eax
je L3
 71f:	74 16                	je     737 <L3>
movl -8(%rbp), %eax
 721:	8b 45 f8             	mov    -0x8(%rbp),%eax
movl %eax, %esi
 724:	89 c6                	mov    %eax,%esi
leaq .LC0(%rip), %rdi
 726:	48 8d 3d a7 00 00 00 	lea    0xa7(%rip),%rdi        # 7d4 <_IO_stdin_used+0x4>
movl $0, %eax
 72d:	b8 00 00 00 00       	mov    $0x0,%eax
call printf@PLT
 732:	e8 e9 fd ff ff       	callq  520 <printf@plt>

0000000000000737 <L3>:
L3:
movl $0, -4(%rsp)
 737:	c7 44 24 fc 00 00 00 	movl   $0x0,-0x4(%rsp)
 73e:	00 
subq $4, %rsp
 73f:	48 83 ec 04          	sub    $0x4,%rsp
movl 0(%rsp), %eax
 743:	8b 04 24             	mov    (%rsp),%eax
addq $4, %rsp
 746:	48 83 c4 04          	add    $0x4,%rsp
popq %rbp
 74a:	5d                   	pop    %rbp
ret
 74b:	c3                   	retq   
 74c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000000750 <__libc_csu_init>:
 750:	41 57                	push   %r15
 752:	41 56                	push   %r14
 754:	49 89 d7             	mov    %rdx,%r15
 757:	41 55                	push   %r13
 759:	41 54                	push   %r12
 75b:	4c 8d 25 56 06 20 00 	lea    0x200656(%rip),%r12        # 200db8 <__frame_dummy_init_array_entry>
 762:	55                   	push   %rbp
 763:	48 8d 2d 56 06 20 00 	lea    0x200656(%rip),%rbp        # 200dc0 <__init_array_end>
 76a:	53                   	push   %rbx
 76b:	41 89 fd             	mov    %edi,%r13d
 76e:	49 89 f6             	mov    %rsi,%r14
 771:	4c 29 e5             	sub    %r12,%rbp
 774:	48 83 ec 08          	sub    $0x8,%rsp
 778:	48 c1 fd 03          	sar    $0x3,%rbp
 77c:	e8 6f fd ff ff       	callq  4f0 <_init>
 781:	48 85 ed             	test   %rbp,%rbp
 784:	74 20                	je     7a6 <__libc_csu_init+0x56>
 786:	31 db                	xor    %ebx,%ebx
 788:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
 78f:	00 
 790:	4c 89 fa             	mov    %r15,%rdx
 793:	4c 89 f6             	mov    %r14,%rsi
 796:	44 89 ef             	mov    %r13d,%edi
 799:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
 79d:	48 83 c3 01          	add    $0x1,%rbx
 7a1:	48 39 dd             	cmp    %rbx,%rbp
 7a4:	75 ea                	jne    790 <__libc_csu_init+0x40>
 7a6:	48 83 c4 08          	add    $0x8,%rsp
 7aa:	5b                   	pop    %rbx
 7ab:	5d                   	pop    %rbp
 7ac:	41 5c                	pop    %r12
 7ae:	41 5d                	pop    %r13
 7b0:	41 5e                	pop    %r14
 7b2:	41 5f                	pop    %r15
 7b4:	c3                   	retq   
 7b5:	90                   	nop
 7b6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 7bd:	00 00 00 

00000000000007c0 <__libc_csu_fini>:
 7c0:	f3 c3                	repz retq 

Disassembly of section .fini:

00000000000007c4 <_fini>:
 7c4:	48 83 ec 08          	sub    $0x8,%rsp
 7c8:	48 83 c4 08          	add    $0x8,%rsp
 7cc:	c3                   	retq   
