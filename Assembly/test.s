	.file	"test.c"
	.globl	a1
	.data
	.align 4
	.type	a1, @object
	.size	a1, 4
a1:
	.long	1
	.globl	a2
	.align 4
	.type	a2, @object
	.size	a2, 4
a2:
	.long	1
	.globl	a3
	.align 4
	.type	a3, @object
	.size	a3, 4
a3:
	.long	1
	.globl	a4
	.align 4
	.type	a4, @object
	.size	a4, 4
a4:
	.long	1
	.globl	a5
	.align 4
	.type	a5, @object
	.size	a5, 4
a5:
	.long	1
	.globl	a6
	.align 4
	.type	a6, @object
	.size	a6, 4
a6:
	.long	1
	.globl	a7
	.align 4
	.type	a7, @object
	.size	a7, 4
a7:
	.long	1
	.globl	a8
	.align 4
	.type	a8, @object
	.size	a8, 4
a8:
	.long	1
	.text
	.globl	sum
	.type	sum, @function
sum:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	cmpl	$1, %eax
	je	.L3
	cmpl	$2, %eax
	je	.L4
	jmp	.L2
.L3:
	movl	$1, -4(%rbp)
.L4:
	movl	$2, -4(%rbp)
.L2:
	movl	$3, -4(%rbp)
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	sum, .-sum
	.globl	loop1
	.type	loop1, @function
loop1:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
.L7:
	cmpl	$1, -4(%rbp)
	jg	.L7
	subl	$1, -8(%rbp)
	subl	$1, -4(%rbp)
	movl	-8(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	loop1, .-loop1
	.globl	test1
	.type	test1, @function
test1:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	%ecx, -32(%rbp)
	movl	%r8d, -36(%rbp)
	movl	%r9d, -40(%rbp)
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	test1, .-test1
	.globl	call_test1
	.type	call_test1, @function
call_test1:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	a8(%rip), %r8d
	movl	a7(%rip), %edi
	movl	a6(%rip), %r9d
	movl	a5(%rip), %r10d
	movl	a4(%rip), %ecx
	movl	a3(%rip), %edx
	movl	a2(%rip), %esi
	movl	a1(%rip), %eax
	movl	%r8d, 8(%rsp)
	movl	%edi, (%rsp)
	movl	%r10d, %r8d
	movl	%eax, %edi
	call	test1
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	call_test1, .-call_test1
	.globl	compare
	.type	compare, @function
compare:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$10, -4(%rbp)
	movl	$20, -8(%rbp)
	movb	$51, -9(%rbp)
	movb	$52, -10(%rbp)
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jle	.L13
	jmp	.L12
.L13:
	movzbl	-9(%rbp), %eax
	cmpb	-10(%rbp), %al
	jle	.L12
	nop
.L12:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	compare, .-compare
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$0, %eax
	call	call_test1
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-36)"
	.section	.note.GNU-stack,"",@progbits
