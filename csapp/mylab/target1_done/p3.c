void fun()
{
  asm(
      "movq $0x5561DCB8, %%rdi\n\t"
      "pushq $0x004018fa"
      :
      :
      : "rdi"
      );
}
