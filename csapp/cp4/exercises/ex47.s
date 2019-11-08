	.file	"ex47.c"
	.text
	.globl	bubble_p
	.type	bubble_p, @function
bubble_p:
.LFB0:
	.cfi_startproc
	leaq	-8(%rdi,%rsi,8), %rsi
	jmp	.L2
.L3:
	addq	$8, %rax
.L5:
	cmpq	%rsi, %rax
	jnb	.L7
	movq	8(%rax), %rdx
	movq	(%rax), %rcx
	cmpq	%rcx, %rdx
	jge	.L3
	movq	%rcx, 8(%rax)
	movq	%rdx, (%rax)
	jmp	.L3
.L7:
	subq	$8, %rsi
.L2:
	cmpq	%rdi, %rsi
	je	.L8
	movq	%rdi, %rax
	jmp	.L5
.L8:
	rep ret
	.cfi_endproc
.LFE0:
	.size	bubble_p, .-bubble_p
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	subq	$72, %rsp
	.cfi_def_cfa_offset 80
	movq	%fs:40, %rax
	movq	%rax, 56(%rsp)
	xorl	%eax, %eax
	movq	$8, (%rsp)
	movq	$9, 8(%rsp)
	movq	$4, 16(%rsp)
	movq	$2, 24(%rsp)
	movq	$3, 32(%rsp)
	movq	$5, 40(%rsp)
	movq	$7, 48(%rsp)
	movq	%rsp, %rdi
	movl	$7, %esi
	call	bubble_p
	movq	56(%rsp), %rdx
	xorq	%fs:40, %rdx
	jne	.L12
	movl	$0, %eax
	addq	$72, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L12:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
