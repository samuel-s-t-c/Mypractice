	.file	"ex50.c"
	.text
	.globl	switchv
	.type	switchv, @function
switchv:
.LFB23:
	.cfi_startproc
	cmpq	$2, %rdi
	je	.L7
	cmpq	$2, %rdi
	jle	.L8
	cmpq	$3, %rdi
	je	.L6
	cmpq	$5, %rdi
	je	.L7
.L2:
	movl	$3549, %eax
	ret
.L8:
	testq	%rdi, %rdi
	jne	.L2
	movl	$2730, %eax
	ret
.L6:
	movl	$3276, %eax
	ret
.L7:
	movl	$3003, %eax
	ret
	.cfi_endproc
.LFE23:
	.size	switchv, .-switchv
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"idx = %ld, val = 0x%lx\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movl	$0, %ebx
	jmp	.L10
.L11:
	leaq	-1(%rbx), %rbp
	movq	%rbp, %rdi
	call	switchv
	movq	%rax, %rcx
	movq	%rbp, %rdx
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	addq	$1, %rbx
.L10:
	cmpq	$7, %rbx
	jle	.L11
	movl	$0, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
