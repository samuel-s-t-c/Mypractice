	.file	"ex54.c"
	.text
	.globl	fucnt2
	.type	fucnt2, @function
fucnt2:
.LFB0:
	.cfi_startproc
	pxor	%xmm2, %xmm2
	cvtsi2ss	%edi, %xmm2
	mulss	%xmm2, %xmm1
	cvtss2sd	%xmm1, %xmm1
	pxor	%xmm2, %xmm2
	cvtsi2sdq	%rsi, %xmm2
	divsd	%xmm2, %xmm0
	subsd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	ret
	.cfi_endproc
.LFE0:
	.size	fucnt2, .-fucnt2
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
