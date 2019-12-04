#include <malloc.h>
#include <unistd.h>
#include <errno.h>

/*  MEMORY SYSTEM MODEL */
#define MAX_HEAP 20*(1<<20)
static char *mem_heap, *mem_brk, *mem_max_addr;

void mem_init(void)
{
  mem_heap = (char *)malloc(MAX_HEAP);
  mem_brk = mem_heap;
  mem_max_addr = mem_heap + MAX_HEAP;
}

void *mem_sbrk(int incr)
{
  char *old_brk = mem_brk;
  if ((incr < 0) || ((mem_brk + incr) > mem_max_addr)) {
    errno = ENOMEM;
    fprintf(stderr, "ERROR: mem_sbrk failed. Ran out of memory...\n");
    return (void *)-1;
  }

  mem_brk +=incr;
  return (void *)old_brk;
}

void mem_deinit(void)
{
}

void *mem_heap_lo()
{
  return (void *)mem_heap;
}

void *mem_heap_hi()
{
  return (void *)(mem_brk - 1);
}

void mem_reset_brk()
{
  mem_brk = (char *)mem_heap;
}

size_t mem_heapsize()
{
  return (size_t)((void *)mem_brk - (void *)mem_heap);
}

size_t mem_pagesize()
{
  return (size_t)getpagesize();
}
