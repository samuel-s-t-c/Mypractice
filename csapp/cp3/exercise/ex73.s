	.file	"ex73.c"
	.text
	.globl	find_range_1
	.type	find_range_1, @function
find_range_1:
.LFB23:
	.cfi_startproc
	pxor	%xmm1, %xmm1
#APP
# 7 "ex73.c" 1
	vucomiss %xmm1, %xmm0
	jp .P
	je .E
	ja .A
	jb .B
	.B:
	movl $0, %eax
	jmp .DONE
	.E:
	movl $1, %eax
	jmp .DONE
	.A:
	movl $2, %eax
	jmp .DONE
	.P:
	movl $3, %eax
	.DONE:
# 0 "" 2
#NO_APP
	ret
	.cfi_endproc
.LFE23:
	.size	find_range_1, .-find_range_1
	.globl	find_range_3
	.type	find_range_3, @function
find_range_3:
.LFB24:
	.cfi_startproc
	pxor	%xmm1, %xmm1
#APP
# 34 "ex73.c" 1
	movl $0, %esi
	movl $1, %edi
	movl $2, %ecx
	movl $3, %edx
	vucomiss %xmm1, %xmm0
	cmovel %edi, %esi
	cmoval %ecx, %esi
	cmovpl %edx, %esi
# 0 "" 2
#NO_APP
	movl	%esi, %eax
	ret
	.cfi_endproc
.LFE24:
	.size	find_range_3, .-find_range_3
	.globl	find_range_2
	.type	find_range_2, @function
find_range_2:
.LFB25:
	.cfi_startproc
	pxor	%xmm1, %xmm1
	ucomiss	%xmm0, %xmm1
	ja	.L7
	ucomiss	%xmm1, %xmm0
	jp	.L10
	je	.L8
.L10:
	ucomiss	.LC1(%rip), %xmm0
	jbe	.L12
	movl	$2, %eax
	ret
.L7:
	movl	$0, %eax
	ret
.L8:
	movl	$1, %eax
	ret
.L12:
	movl	$3, %eax
	ret
	.cfi_endproc
.LFE25:
	.size	find_range_2, .-find_range_2
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC2:
	.string	"%.8x\n"
.LC3:
	.string	"my function: %d\n"
.LC4:
	.string	"normal: %d\n"
.LC5:
	.string	"OK!"
	.text
	.globl	main
	.type	main, @function
main:
.LFB26:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	subq	$16, %rsp
	.cfi_def_cfa_offset 48
	movl	$0, %ebx
.L16:
	movl	%ebx, 12(%rsp)
	movss	12(%rsp), %xmm1
	movaps	%xmm1, %xmm0
	call	find_range_3
	movl	%eax, %r12d
	movss	12(%rsp), %xmm0
	call	find_range_2
	movl	%eax, %ebp
	cmpl	%eax, %r12d
	jne	.L18
	addl	$1, %ebx
	jne	.L16
	leaq	.LC5(%rip), %rdi
	call	puts@PLT
	movl	$0, %eax
	jmp	.L13
.L18:
	movl	%ebx, %edx
	leaq	.LC2(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	%r12d, %edx
	leaq	.LC3(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	%ebp, %edx
	leaq	.LC4(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	$1, %eax
.L13:
	addq	$16, %rsp
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE26:
	.size	main, .-main
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC1:
	.long	0
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
