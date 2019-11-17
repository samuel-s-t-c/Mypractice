.L15:
  vmovsd 0(%rbp, %rcx, 8), %xmm1
  vmulsd (%rax, %rcx, 8), %xmm1, %xmm1
  vaddsd %xmm1, %xmm0, %xmm0
  addq $1, %rcx
  cmpq %rbx, %rcx
  jne .L15
