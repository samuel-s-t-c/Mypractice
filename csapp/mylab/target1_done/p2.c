void func()
{
  asm(
      "movq $0x59b997fa, %%rdi\n\t"
      "pushq $0x004017ec"
      :::"rdi"
      );
}
