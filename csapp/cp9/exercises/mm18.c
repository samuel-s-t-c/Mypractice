#include <stdio.h>
#include "mm.h"

#define WSIZE 4
#define DSIZE 8
#define CHUNKSIZE (1<<12)

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define PACK(size, alloc, prev_alloc) ((size) | (alloc) | (prev_alloc << 1))
#define GET(p) (*(unsigned int *)(p))
#define PUT(p, val) (*(unsigned int *)(p) = (val))
#define GET_SIZE(p) (GET(p) & ~0x7)
#define GET_ALLOC(p) (GET(p) & 0x1)
#define PREV_ALLOC(p) (GET(p) & 0x2)
#define HDRP(bp) ((char *)bp - WSIZE)
#define FTRP(bp) ((char *)bp + GET_SIZE(HDRP(bp)) - DSIZE)
#define NEXT_BLKP(bp) ((char *)bp + GET_SIZE(HDRP(bp)))
#define PREV_BLKP(bp) ((char *)bp - GET_SIZE(((char *)bp - DSIZE)))

static void *extend_heap(size_t words);
static void place(void *bp, size_t asize);
static void *find_fit(size_t asize);
static void *coalesce(void *bp);
static void printblock(void *bp);
static void checkheap(int verbose);
static void checkblock(void *bp);

static char *heap_listp = 0;
static char *rover;

int mm_init(void)
{
  if ((heap_listp = mem_sbrk(4*WSIZE)) == (void *)-1)
    return -1;

  PUT(heap_listp, 0);
  PUT(heap_listp + (1*WSIZE), PACK(DSIZE, 1, 1));
  PUT(heap_listp + (2*WSIZE), PACK(DSIZE, 1, 1));
  PUT(heap_listp + (3*WSIZE), PACK(0, 1, 1));
  heap_listp += (2*WSIZE);

  rover = heap_listp;

  if (extend_heap(CHUNKSIZE/WSIZE) == NULL)
    return -1;
  return 0;
}

static void *extend_heap(size_t words)
{
  char *bp;
  size_t size;

  size = (words % 2) ? (words + 1) * WSIZE : words * WSIZE;
  if ((long)(bp = mem_sbrk(size)) == -1)
    return NULL;

  size_t prevbit = PREV_ALLOC(HDRP(bp));
  PUT(HDRP(bp), PACK(size, 0, prevbit));
  PUT(FTRP(bp), PACK(size, 0, prevbit));
  PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1, 0));

  return coalesce(bp);
}

void mm_free(void *bp)
{
  size_t size = GET_SIZE(HDRP(bp));
  size_t prev_alloc = PREV_ALLOC(HDRP(bp));
  char *nbp = NEXT_BLKP(bp);

  PUT(HDRP(bp), PACK(size, 0, prev_alloc));
  PUT(FTRP(bp), PACK(size, 0, prev_alloc));

  if (GET_ALLOC(nbp))
    PUT(HDRP(nbp), PACK(GET_SIZE(HDRP(nbp)), 1, 0));
  else {
    PUT(HDRP(nbp), PACK(GET_SIZE(HDRP(nbp)), 0, 0));
    PUT(FTRP(nbp), PACK(GET_SIZE(HDRP(nbp)), 0, 0));
  }

  coalesce(bp);
}

static void *coalesce(void *bp)
{
  size_t prev_alloc = PREV_ALLOC(HDRP(bp));
  size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
  size_t size = GET_SIZE(HDRP(bp));

  if (prev_alloc && next_alloc) {
    return bp;
  } else if (prev_alloc && !next_alloc) {
    size += GET_SIZE(HDRP(NEXT_BLKP(bp)));
    PUT(HDRP(bp), PACK(size, 0, 1));
    PUT(FTRP(bp), PACK(size, 0, 1));
  } else if (!prev_alloc && next_alloc) {
    size += GET_SIZE(HDRP(PREV_BLKP(bp)));
    prev_alloc = PREV_ALLOC(HDRP(PREV_BLKP(bp)));
    PUT(FTRP(bp), PACK(size, 0, prev_alloc));
    PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0, prev_alloc));
    bp = PREV_BLKP(bp);
  } else {
    size += GET_SIZE(HDRP(PREV_BLKP(bp))) +
            GET_SIZE(FTRP(NEXT_BLKP(bp)));
    prev_alloc = PREV_ALLOC(HDRP(PREV_BLKP(bp)));
    PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0, prev_alloc));
    PUT(FTRP(NEXT_BLKP(bp)), PACK(size, 0, prev_alloc));
    bp = PREV_BLKP(bp);
  }

  if ((rover > (char *)bp) && (rover < NEXT_BLKP(bp)))
    rover = bp;

  return bp;
}

void *mm_alloc(size_t size)
{
  size_t asize;
  size_t extendsize;
  char *bp;

  if (size == 0)
    return NULL;

  asize = (DSIZE * (size + (WSIZE) + (DSIZE - 1))/ DSIZE);

  if ((bp = find_fit(asize)) != NULL) {
    place(bp, asize);
    return bp;
  }

  extendsize = MAX(asize, CHUNKSIZE);
  if ((bp = extend_heap(extendsize/WSIZE)) == NULL)
    return NULL;
  place(bp, asize);
  return bp;
}

static void *find_fit(size_t asize)
{
  char *oldrover = rover;

  for (;GET_SIZE(HDRP(rover)) > 0; rover = NEXT_BLKP(rover))
    if (!GET_ALLOC(HDRP(rover)) && (asize <= GET_SIZE(HDRP(rover))))
      return rover;

  for (rover = heap_listp; rover < oldrover; rover = NEXT_BLKP(rover))
    if (!GET_ALLOC(HDRP(rover)) && (asize <= GET_SIZE(HDRP(rover))))
      return rover;

  return NULL;
}

static void place(void *bp, size_t asize)
{
  size_t csize = GET_SIZE(HDRP(bp));
  size_t prev_alloc = PREV_ALLOC(HDRP(bp));

  if ((csize - asize) >= (2*DSIZE)) {
    PUT(HDRP(bp), PACK(asize, 1, prev_alloc));
    bp = NEXT_BLKP(bp);
    PUT(HDRP(bp), PACK(csize - asize, 0, 1));
    PUT(FTRP(bp), PACK(csize - asize, 0, 1));
  } else {
    PUT(HDRP(bp), PACK(csize, 1, prev_alloc));
    bp = NEXT_BLKP(bp);
    if (GET_ALLOC(HDRP(bp)))
      PUT(HDRP(bp), PACK(GET_SIZE(HDRP(bp)), 1, 1));
    else {
      PUT(HDRP(bp), PACK(GET_SIZE(HDRP(bp)), 0, 1));
      PUT(FTRP(bp), PACK(GET_SIZE(HDRP(bp)), 0, 1));
    }
  }
}

static void checkblock(void *bp)
{
  if ((size_t)bp % 8)
    printf("Error: %p is not doubleword aligned\n", bp);
  if (GET(HDRP(bp)) != GET(FTRP(bp)))
    printf("Error: header does not match footer\n");
}

static void printblock(void *bp)
{
  size_t hsize, halloc, fsize, falloc;

  checkheap(0);
  hsize = GET_SIZE(HDRP(bp));
  halloc = GET_ALLOC(HDRP(bp));
  fsize = GET_SIZE(FTRP(bp));
  falloc = GET_ALLOC(FTRP(bp));

  if (hsize == 0) {
    printf("%p: EOL\n", bp);
    return;
  }

  printf("%p: header: [%ld:%c] footer: [%ld:%c]\n", bp,
         hsize, (halloc ? 'a' : 'f'),
         fsize, (falloc ? 'a' : 'f'));
}

void checkheap(int verbose)
{
  char *bp = heap_listp;

  if (verbose)
    printf("Heap (%p):\n", heap_listp);

  if ((GET_SIZE(HDRP(heap_listp)) != DSIZE) || !GET_ALLOC(HDRP(heap_listp)))
    printf("Bad prologue header\n");
  checkblock(heap_listp);

  for (bp = heap_listp; GET_SIZE(HDRP(bp)) > 0; bp = NEXT_BLKP(bp)) {
    if (verbose)
      printblock(bp);
    checkblock(bp);
  }

  if (verbose)
    printblock(bp);
  if ((GET_SIZE(HDRP(bp)) != 0) || !(GET_ALLOC(HDRP(bp))))
    printf("Bad epilogue header\n");
}
