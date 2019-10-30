#include <stdio.h>
typedef enum {NEG, ZERO, POS, OTHER} range_t;

range_t find_range_1(float x)
{
  int result;
  asm(
      "vucomiss %[zero], %[x]\n\t"
      "jp .P\n\t"
      "je .E\n\t"
      "ja .A\n\t"
      "jb .B\n\t"
      ".B:\n\t"
      "movl $0, %[result]\n\t"
      "jmp .DONE\n\t"
      ".E:\n\t"
      "movl $1, %[result]\n\t"
      "jmp .DONE\n\t"
      ".A:\n\t"
      "movl $2, %[result]\n\t"
      "jmp .DONE\n\t"
      ".P:\n\t"
      "movl $3, %[result]\n\t"
      ".DONE:"
      : [x] "+x" (x), [result] "=r" (result)
      : [zero] "x" (0.0)
      );
  return result;
}

range_t find_range_3(float x)
{
  int result;
  asm(
      "movl $0, %[result]\n\t"
      "movl $1, %%edi\n\t"
      "movl $2, %%ecx\n\t"
      "movl $3, %%edx\n\t"
      "vucomiss %[zero], %[x]\n\t"
      "cmovel %%edi, %[result]\n\t"
      "cmoval %%ecx, %[result]\n\t"
      "cmovpl %%edx, %[result]"
      : [x] "+x" (x), [result] "=r" (result)
      : [zero] "x" (0.0)
      : "%eax", "%edi", "%ecx", "%edx"
      );
  return result;
}

range_t find_range_2(float x)
{
  int result;
  if (x < 0)
    result = NEG;
  else if (x == 0)
    result = ZERO;
  else if (x > 0)
    result = POS;
  else
    result = OTHER;
  return result;
}

int main()
{
  unsigned int x = 0;
  do {
    if (find_range_3(*((float *)&x)) != find_range_2(*((float *)&x))) {
      printf("%.8x\n", x);
      printf("my function: %d\n",find_range_3(*((float *)&x)));
      printf("normal: %d\n",find_range_2(*((float *)&x)));
      return 1;
    }
    ++x;
  } while (x != 0);
  printf("OK!\n");
  return 0;
}
