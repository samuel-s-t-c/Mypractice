	.file	"switch_eg.c"
	.text
	.globl	switch_eg
	.type	switch_eg, @function
switch_eg:
.LFB0:
	.cfi_startproc
	subq	$100, %rsi            // n -= 100
	cmpq	$6, %rsi              // compare n : 6
	ja	.L8                     // if n > 6  goto L8
	leaq	.L4(%rip), %rcx       // rcx = rip + L4
	movslq	(%rcx,%rsi,4), %rax // rax = 4*n + rcx;
	addq	%rcx, %rax            // rax += rcx;  rax: 4n + 2(rip + L4)
	jmp	*%rax                   // goto (%rax);
	.section	.rodata
	.align 4
	.align 4
.L4:
	.long	.L3-.L4
	.long	.L8-.L4
	.long	.L5-.L4
	.long	.L6-.L4
	.long	.L7-.L4
	.long	.L8-.L4
	.long	.L7-.L4
	.text
.L3:                          // case 100:
	leaq	(%rdi,%rdi,2), %rax   // rax = 3x;
	leaq	(%rdi,%rax,4), %rdi   // x = 13x;
	jmp	.L2                     // goto end;
.L5:                          // case 102;
	addq	$10, %rdi             // x += 10;
.L6:                          // case 103;
	addq	$11, %rdi             // x += 11;
.L2:
	movq	%rdi, (%rdx)          // *dest = x;
	ret                         // return;
.L7:                          // case 104 106;
	imulq	%rdi, %rdi            // x *= x;
	jmp	.L2                     // goto end;
.L8:                          // case default;
	movl	$0, %edi              // x = 0;
	jmp	.L2                     // goto end;
	.cfi_endproc
.LFE0:
	.size	switch_eg, .-switch_eg
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
