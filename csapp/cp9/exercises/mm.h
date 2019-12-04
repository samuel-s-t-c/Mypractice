#ifndef MYMM
#define MYMM

#include "memlib.h"
int mm_init(void);
void *mm_alloc(size_t size);
void mm_free(void *ptr);

extern void *mm_realloc(void *ptr, size_t size);
extern void *mm_calloc (size_t nmemb, size_t size);
extern void mm_checkheap(int verbose);

#endif
