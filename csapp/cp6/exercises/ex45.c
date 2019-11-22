#include <assert.h>

// my cpu is core i7 haswell
// so, I have 32KB L1 d-data, 256KB L2 cache and 8MB L3cache that the block size is 64B;
// basic version
void transpose(int *dst, int *src, int dim)
{
  int i, j;
  for (i = 0; i < dim; i++)
    for (j = 0; j < dim; j++)
      dst[j*dim +i] = src[i*dim +j];
}

//
void transpose4x4(int *dst, int *src, int dim)
{
  int i, j;
  for (i = 0; i < dim-1; i+=2) {
    for (j = 0; j < dim-1; j+=2) {
      dst[j*dim + i] = src[i*dim + j];
      dst[j*dim + i + 1] = src[(i+1)*dim + j];
      dst[(j+1)*dim +(i+1)] = src[(i+1)*dim + j + 1];
      dst[(j+1)*dim +i] = src[i*dim + j + 1];
    }
    for (; j < dim; j++)
      dst[j*dim + i] = src[i*dim + j];
  }
  for (; i < dim; i++)
    for (j = 0; j < dim; j++)
      dst[j*dim + i] = src[i*dim + j];
}

void transpose9x9(int *dst, int *src, int dim)
{
  int i, j;
  for (i = 0; i < dim-2; i+=3) {
    for (j = 0; j < dim-2; j+=3) {
      dst[j*dim + i] = src[i*dim + j];
      dst[j*dim + i + 1] = src[(i+1)*dim + j];
      dst[j*dim + i + 2] = src[(i+2)*dim + j];
      dst[(j+1)*dim +i] = src[i*dim + j + 1];
      dst[(j+1)*dim +(i+1)] = src[(i+1)*dim + j + 1];
      dst[(j+1)*dim +(i+2)] = src[(i+2)*dim + j + 1];
      dst[(j+2)*dim +i] = src[i*dim + j + 2];
      dst[(j+2)*dim +(i+1)] = src[(i+1)*dim + j + 2];
      dst[(j+2)*dim +(i+2)] = src[(i+2)*dim + j + 2];
    }
    for (; j < dim; j++)
      dst[j*dim + i] = src[i*dim + j];
  }
  for (; i < dim; i++)
    for (j = 0; j < dim; j++)
      dst[j*dim + i] = src[i*dim + j];
}

void transpose16x16(int *dst, int *src, int dim)
{
  int i, j;
  for (i = 0; i < dim-3; i+=4) {
    for (j = 0; j < dim-3; j+=4) {
      dst[j*dim + i] = src[i*dim + j];
      dst[j*dim + i + 1] = src[(i+1)*dim + j];
      dst[j*dim + i + 2] = src[(i+2)*dim + j];
      dst[j*dim + i + 3] = src[(i+3)*dim + j];
      dst[(j+1)*dim +i] = src[i*dim + j + 1];
      dst[(j+1)*dim +(i+1)] = src[(i+1)*dim + j + 1];
      dst[(j+1)*dim +(i+2)] = src[(i+2)*dim + j + 1];
      dst[(j+1)*dim +(i+3)] = src[(i+3)*dim + j + 1];
      dst[(j+2)*dim +i] = src[i*dim + j + 2];
      dst[(j+2)*dim +(i+1)] = src[(i+1)*dim + j + 2];
      dst[(j+2)*dim +(i+2)] = src[(i+2)*dim + j + 2];
      dst[(j+2)*dim +(i+3)] = src[(i+3)*dim + j + 2];
      dst[(j+3)*dim +i] = src[i*dim + j + 3];
      dst[(j+3)*dim +(i+1)] = src[(i+1)*dim + j + 3];
      dst[(j+3)*dim +(i+2)] = src[(i+2)*dim + j + 3];
      dst[(j+3)*dim +(i+3)] = src[(i+3)*dim + j + 3];
    }
    for (; j < dim; j++)
      dst[j*dim + i] = src[i*dim + j];
  }
  for (; i < dim; i++)
    for (j = 0; j < dim; j++)
      dst[j*dim + i] = src[i*dim + j];
}

void transpose256(int *dst, int *src, int dim)
{
  int i, j;
  for (i = 0; i < dim-15; i+=16) {
    for (j = 0; j < dim-15; j+=16) {
      dst[j*dim + i] = src[i*dim + j];
      dst[j*dim + i + 1] = src[(i+1)*dim + j];
      dst[j*dim + i + 2] = src[(i+2)*dim + j];
      dst[j*dim + i + 3] = src[(i+3)*dim + j];
      dst[j*dim + i + 4] = src[(i+4)*dim + j];
      dst[j*dim + i + 5] = src[(i+5)*dim + j];
      dst[j*dim + i + 6] = src[(i+6)*dim + j];
      dst[j*dim + i + 7] = src[(i+7)*dim + j];
      dst[j*dim + i + 8] = src[(i+8)*dim + j];
      dst[j*dim + i + 9] = src[(i+9)*dim + j];
      dst[j*dim + i + 10] = src[(i+10)*dim + j];
      dst[j*dim + i + 11] = src[(i+11)*dim + j];
      dst[j*dim + i + 12] = src[(i+12)*dim + j];
      dst[j*dim + i + 13] = src[(i+13)*dim + j];
      dst[j*dim + i + 14] = src[(i+14)*dim + j];
      dst[j*dim + i + 15] = src[(i+15)*dim + j];
      dst[(j+1)*dim + i] = src[i*dim + (j+1)];
      dst[(j+1)*dim + i + 1] = src[(i+1)*dim + (j+1)];
      dst[(j+1)*dim + i + 2] = src[(i+2)*dim + (j+1)];
      dst[(j+1)*dim + i + 3] = src[(i+3)*dim + (j+1)];
      dst[(j+1)*dim + i + 4] = src[(i+4)*dim + (j+1)];
      dst[(j+1)*dim + i + 5] = src[(i+5)*dim + (j+1)];
      dst[(j+1)*dim + i + 6] = src[(i+6)*dim + (j+1)];
      dst[(j+1)*dim + i + 7] = src[(i+7)*dim + (j+1)];
      dst[(j+1)*dim + i + 8] = src[(i+8)*dim + (j+1)];
      dst[(j+1)*dim + i + 9] = src[(i+9)*dim + (j+1)];
      dst[(j+1)*dim + i + 10] = src[(i+10)*dim + (j+1)];
      dst[(j+1)*dim + i + 11] = src[(i+11)*dim + (j+1)];
      dst[(j+1)*dim + i + 12] = src[(i+12)*dim + (j+1)];
      dst[(j+1)*dim + i + 13] = src[(i+13)*dim + (j+1)];
      dst[(j+1)*dim + i + 14] = src[(i+14)*dim + (j+1)];
      dst[(j+1)*dim + i + 15] = src[(i+15)*dim + (j+1)];
      dst[(j+2)*dim + i] = src[i*dim + (j+2)];
      dst[(j+2)*dim + i + 1] = src[(i+1)*dim + (j+2)];
      dst[(j+2)*dim + i + 2] = src[(i+2)*dim + (j+2)];
      dst[(j+2)*dim + i + 3] = src[(i+3)*dim + (j+2)];
      dst[(j+2)*dim + i + 4] = src[(i+4)*dim + (j+2)];
      dst[(j+2)*dim + i + 5] = src[(i+5)*dim + (j+2)];
      dst[(j+2)*dim + i + 6] = src[(i+6)*dim + (j+2)];
      dst[(j+2)*dim + i + 7] = src[(i+7)*dim + (j+2)];
      dst[(j+2)*dim + i + 8] = src[(i+8)*dim + (j+2)];
      dst[(j+2)*dim + i + 9] = src[(i+9)*dim + (j+2)];
      dst[(j+2)*dim + i + 10] = src[(i+10)*dim + (j+2)];
      dst[(j+2)*dim + i + 11] = src[(i+11)*dim + (j+2)];
      dst[(j+2)*dim + i + 12] = src[(i+12)*dim + (j+2)];
      dst[(j+2)*dim + i + 13] = src[(i+13)*dim + (j+2)];
      dst[(j+2)*dim + i + 14] = src[(i+14)*dim + (j+2)];
      dst[(j+2)*dim + i + 15] = src[(i+15)*dim + (j+2)];
      dst[(j+3)*dim + i] = src[i*dim + (j+3)];
      dst[(j+3)*dim + i + 1] = src[(i+1)*dim + (j+3)];
      dst[(j+3)*dim + i + 2] = src[(i+2)*dim + (j+3)];
      dst[(j+3)*dim + i + 3] = src[(i+3)*dim + (j+3)];
      dst[(j+3)*dim + i + 4] = src[(i+4)*dim + (j+3)];
      dst[(j+3)*dim + i + 5] = src[(i+5)*dim + (j+3)];
      dst[(j+3)*dim + i + 6] = src[(i+6)*dim + (j+3)];
      dst[(j+3)*dim + i + 7] = src[(i+7)*dim + (j+3)];
      dst[(j+3)*dim + i + 8] = src[(i+8)*dim + (j+3)];
      dst[(j+3)*dim + i + 9] = src[(i+9)*dim + (j+3)];
      dst[(j+3)*dim + i + 10] = src[(i+10)*dim + (j+3)];
      dst[(j+3)*dim + i + 11] = src[(i+11)*dim + (j+3)];
      dst[(j+3)*dim + i + 12] = src[(i+12)*dim + (j+3)];
      dst[(j+3)*dim + i + 13] = src[(i+13)*dim + (j+3)];
      dst[(j+3)*dim + i + 14] = src[(i+14)*dim + (j+3)];
      dst[(j+3)*dim + i + 15] = src[(i+15)*dim + (j+3)];
      dst[(j+4)*dim + i] = src[i*dim + (j+4)];
      dst[(j+4)*dim + i + 1] = src[(i+1)*dim + (j+4)];
      dst[(j+4)*dim + i + 2] = src[(i+2)*dim + (j+4)];
      dst[(j+4)*dim + i + 3] = src[(i+3)*dim + (j+4)];
      dst[(j+4)*dim + i + 4] = src[(i+4)*dim + (j+4)];
      dst[(j+4)*dim + i + 5] = src[(i+5)*dim + (j+4)];
      dst[(j+4)*dim + i + 6] = src[(i+6)*dim + (j+4)];
      dst[(j+4)*dim + i + 7] = src[(i+7)*dim + (j+4)];
      dst[(j+4)*dim + i + 8] = src[(i+8)*dim + (j+4)];
      dst[(j+4)*dim + i + 9] = src[(i+9)*dim + (j+4)];
      dst[(j+4)*dim + i + 10] = src[(i+10)*dim + (j+4)];
      dst[(j+4)*dim + i + 11] = src[(i+11)*dim + (j+4)];
      dst[(j+4)*dim + i + 12] = src[(i+12)*dim + (j+4)];
      dst[(j+4)*dim + i + 13] = src[(i+13)*dim + (j+4)];
      dst[(j+4)*dim + i + 14] = src[(i+14)*dim + (j+4)];
      dst[(j+4)*dim + i + 15] = src[(i+15)*dim + (j+4)];
      dst[(j+5)*dim + i] = src[i*dim + (j+5)];
      dst[(j+5)*dim + i + 1] = src[(i+1)*dim + (j+5)];
      dst[(j+5)*dim + i + 2] = src[(i+2)*dim + (j+5)];
      dst[(j+5)*dim + i + 3] = src[(i+3)*dim + (j+5)];
      dst[(j+5)*dim + i + 4] = src[(i+4)*dim + (j+5)];
      dst[(j+5)*dim + i + 5] = src[(i+5)*dim + (j+5)];
      dst[(j+5)*dim + i + 6] = src[(i+6)*dim + (j+5)];
      dst[(j+5)*dim + i + 7] = src[(i+7)*dim + (j+5)];
      dst[(j+5)*dim + i + 8] = src[(i+8)*dim + (j+5)];
      dst[(j+5)*dim + i + 9] = src[(i+9)*dim + (j+5)];
      dst[(j+5)*dim + i + 10] = src[(i+10)*dim + (j+5)];
      dst[(j+5)*dim + i + 11] = src[(i+11)*dim + (j+5)];
      dst[(j+5)*dim + i + 12] = src[(i+12)*dim + (j+5)];
      dst[(j+5)*dim + i + 13] = src[(i+13)*dim + (j+5)];
      dst[(j+5)*dim + i + 14] = src[(i+14)*dim + (j+5)];
      dst[(j+5)*dim + i + 15] = src[(i+15)*dim + (j+5)];
      dst[(j+6)*dim + i] = src[i*dim + (j+6)];
      dst[(j+6)*dim + i + 1] = src[(i+1)*dim + (j+6)];
      dst[(j+6)*dim + i + 2] = src[(i+2)*dim + (j+6)];
      dst[(j+6)*dim + i + 3] = src[(i+3)*dim + (j+6)];
      dst[(j+6)*dim + i + 4] = src[(i+4)*dim + (j+6)];
      dst[(j+6)*dim + i + 5] = src[(i+5)*dim + (j+6)];
      dst[(j+6)*dim + i + 6] = src[(i+6)*dim + (j+6)];
      dst[(j+6)*dim + i + 7] = src[(i+7)*dim + (j+6)];
      dst[(j+6)*dim + i + 8] = src[(i+8)*dim + (j+6)];
      dst[(j+6)*dim + i + 9] = src[(i+9)*dim + (j+6)];
      dst[(j+6)*dim + i + 10] = src[(i+10)*dim + (j+6)];
      dst[(j+6)*dim + i + 11] = src[(i+11)*dim + (j+6)];
      dst[(j+6)*dim + i + 12] = src[(i+12)*dim + (j+6)];
      dst[(j+6)*dim + i + 13] = src[(i+13)*dim + (j+6)];
      dst[(j+6)*dim + i + 14] = src[(i+14)*dim + (j+6)];
      dst[(j+6)*dim + i + 15] = src[(i+15)*dim + (j+6)];
      dst[(j+7)*dim + i] = src[i*dim + (j+7)];
      dst[(j+7)*dim + i + 1] = src[(i+1)*dim + (j+7)];
      dst[(j+7)*dim + i + 2] = src[(i+2)*dim + (j+7)];
      dst[(j+7)*dim + i + 3] = src[(i+3)*dim + (j+7)];
      dst[(j+7)*dim + i + 4] = src[(i+4)*dim + (j+7)];
      dst[(j+7)*dim + i + 5] = src[(i+5)*dim + (j+7)];
      dst[(j+7)*dim + i + 6] = src[(i+6)*dim + (j+7)];
      dst[(j+7)*dim + i + 7] = src[(i+7)*dim + (j+7)];
      dst[(j+7)*dim + i + 8] = src[(i+8)*dim + (j+7)];
      dst[(j+7)*dim + i + 9] = src[(i+9)*dim + (j+7)];
      dst[(j+7)*dim + i + 10] = src[(i+10)*dim + (j+7)];
      dst[(j+7)*dim + i + 11] = src[(i+11)*dim + (j+7)];
      dst[(j+7)*dim + i + 12] = src[(i+12)*dim + (j+7)];
      dst[(j+7)*dim + i + 13] = src[(i+13)*dim + (j+7)];
      dst[(j+7)*dim + i + 14] = src[(i+14)*dim + (j+7)];
      dst[(j+7)*dim + i + 15] = src[(i+15)*dim + (j+7)];
      dst[(j+8)*dim + i] = src[i*dim + (j+8)];
      dst[(j+8)*dim + i + 1] = src[(i+1)*dim + (j+8)];
      dst[(j+8)*dim + i + 2] = src[(i+2)*dim + (j+8)];
      dst[(j+8)*dim + i + 3] = src[(i+3)*dim + (j+8)];
      dst[(j+8)*dim + i + 4] = src[(i+4)*dim + (j+8)];
      dst[(j+8)*dim + i + 5] = src[(i+5)*dim + (j+8)];
      dst[(j+8)*dim + i + 6] = src[(i+6)*dim + (j+8)];
      dst[(j+8)*dim + i + 7] = src[(i+7)*dim + (j+8)];
      dst[(j+8)*dim + i + 8] = src[(i+8)*dim + (j+8)];
      dst[(j+8)*dim + i + 9] = src[(i+9)*dim + (j+8)];
      dst[(j+8)*dim + i + 10] = src[(i+10)*dim + (j+8)];
      dst[(j+8)*dim + i + 11] = src[(i+11)*dim + (j+8)];
      dst[(j+8)*dim + i + 12] = src[(i+12)*dim + (j+8)];
      dst[(j+8)*dim + i + 13] = src[(i+13)*dim + (j+8)];
      dst[(j+8)*dim + i + 14] = src[(i+14)*dim + (j+8)];
      dst[(j+8)*dim + i + 15] = src[(i+15)*dim + (j+8)];
      dst[(j+9)*dim + i] = src[i*dim + (j+9)];
      dst[(j+9)*dim + i + 1] = src[(i+1)*dim + (j+9)];
      dst[(j+9)*dim + i + 2] = src[(i+2)*dim + (j+9)];
      dst[(j+9)*dim + i + 3] = src[(i+3)*dim + (j+9)];
      dst[(j+9)*dim + i + 4] = src[(i+4)*dim + (j+9)];
      dst[(j+9)*dim + i + 5] = src[(i+5)*dim + (j+9)];
      dst[(j+9)*dim + i + 6] = src[(i+6)*dim + (j+9)];
      dst[(j+9)*dim + i + 7] = src[(i+7)*dim + (j+9)];
      dst[(j+9)*dim + i + 8] = src[(i+8)*dim + (j+9)];
      dst[(j+9)*dim + i + 9] = src[(i+9)*dim + (j+9)];
      dst[(j+9)*dim + i + 10] = src[(i+10)*dim + (j+9)];
      dst[(j+9)*dim + i + 11] = src[(i+11)*dim + (j+9)];
      dst[(j+9)*dim + i + 12] = src[(i+12)*dim + (j+9)];
      dst[(j+9)*dim + i + 13] = src[(i+13)*dim + (j+9)];
      dst[(j+9)*dim + i + 14] = src[(i+14)*dim + (j+9)];
      dst[(j+9)*dim + i + 15] = src[(i+15)*dim + (j+9)];
      dst[(j+10)*dim + i] = src[i*dim + (j+10)];
      dst[(j+10)*dim + i + 1] = src[(i+1)*dim + (j+10)];
      dst[(j+10)*dim + i + 2] = src[(i+2)*dim + (j+10)];
      dst[(j+10)*dim + i + 3] = src[(i+3)*dim + (j+10)];
      dst[(j+10)*dim + i + 4] = src[(i+4)*dim + (j+10)];
      dst[(j+10)*dim + i + 5] = src[(i+5)*dim + (j+10)];
      dst[(j+10)*dim + i + 6] = src[(i+6)*dim + (j+10)];
      dst[(j+10)*dim + i + 7] = src[(i+7)*dim + (j+10)];
      dst[(j+10)*dim + i + 8] = src[(i+8)*dim + (j+10)];
      dst[(j+10)*dim + i + 9] = src[(i+9)*dim + (j+10)];
      dst[(j+10)*dim + i + 10] = src[(i+10)*dim + (j+10)];
      dst[(j+10)*dim + i + 11] = src[(i+11)*dim + (j+10)];
      dst[(j+10)*dim + i + 12] = src[(i+12)*dim + (j+10)];
      dst[(j+10)*dim + i + 13] = src[(i+13)*dim + (j+10)];
      dst[(j+10)*dim + i + 14] = src[(i+14)*dim + (j+10)];
      dst[(j+10)*dim + i + 15] = src[(i+15)*dim + (j+10)];
      dst[(j+11)*dim + i] = src[i*dim + (j+11)];
      dst[(j+11)*dim + i + 1] = src[(i+1)*dim + (j+11)];
      dst[(j+11)*dim + i + 2] = src[(i+2)*dim + (j+11)];
      dst[(j+11)*dim + i + 3] = src[(i+3)*dim + (j+11)];
      dst[(j+11)*dim + i + 4] = src[(i+4)*dim + (j+11)];
      dst[(j+11)*dim + i + 5] = src[(i+5)*dim + (j+11)];
      dst[(j+11)*dim + i + 6] = src[(i+6)*dim + (j+11)];
      dst[(j+11)*dim + i + 7] = src[(i+7)*dim + (j+11)];
      dst[(j+11)*dim + i + 8] = src[(i+8)*dim + (j+11)];
      dst[(j+11)*dim + i + 9] = src[(i+9)*dim + (j+11)];
      dst[(j+11)*dim + i + 10] = src[(i+10)*dim + (j+11)];
      dst[(j+11)*dim + i + 11] = src[(i+11)*dim + (j+11)];
      dst[(j+11)*dim + i + 12] = src[(i+12)*dim + (j+11)];
      dst[(j+11)*dim + i + 13] = src[(i+13)*dim + (j+11)];
      dst[(j+11)*dim + i + 14] = src[(i+14)*dim + (j+11)];
      dst[(j+11)*dim + i + 15] = src[(i+15)*dim + (j+11)];
      dst[(j+12)*dim + i] = src[i*dim + (j+12)];
      dst[(j+12)*dim + i + 1] = src[(i+1)*dim + (j+12)];
      dst[(j+12)*dim + i + 2] = src[(i+2)*dim + (j+12)];
      dst[(j+12)*dim + i + 3] = src[(i+3)*dim + (j+12)];
      dst[(j+12)*dim + i + 4] = src[(i+4)*dim + (j+12)];
      dst[(j+12)*dim + i + 5] = src[(i+5)*dim + (j+12)];
      dst[(j+12)*dim + i + 6] = src[(i+6)*dim + (j+12)];
      dst[(j+12)*dim + i + 7] = src[(i+7)*dim + (j+12)];
      dst[(j+12)*dim + i + 8] = src[(i+8)*dim + (j+12)];
      dst[(j+12)*dim + i + 9] = src[(i+9)*dim + (j+12)];
      dst[(j+12)*dim + i + 10] = src[(i+10)*dim + (j+12)];
      dst[(j+12)*dim + i + 11] = src[(i+11)*dim + (j+12)];
      dst[(j+12)*dim + i + 12] = src[(i+12)*dim + (j+12)];
      dst[(j+12)*dim + i + 13] = src[(i+13)*dim + (j+12)];
      dst[(j+12)*dim + i + 14] = src[(i+14)*dim + (j+12)];
      dst[(j+12)*dim + i + 15] = src[(i+15)*dim + (j+12)];
      dst[(j+13)*dim + i] = src[i*dim + (j+13)];
      dst[(j+13)*dim + i + 1] = src[(i+1)*dim + (j+13)];
      dst[(j+13)*dim + i + 2] = src[(i+2)*dim + (j+13)];
      dst[(j+13)*dim + i + 3] = src[(i+3)*dim + (j+13)];
      dst[(j+13)*dim + i + 4] = src[(i+4)*dim + (j+13)];
      dst[(j+13)*dim + i + 5] = src[(i+5)*dim + (j+13)];
      dst[(j+13)*dim + i + 6] = src[(i+6)*dim + (j+13)];
      dst[(j+13)*dim + i + 7] = src[(i+7)*dim + (j+13)];
      dst[(j+13)*dim + i + 8] = src[(i+8)*dim + (j+13)];
      dst[(j+13)*dim + i + 9] = src[(i+9)*dim + (j+13)];
      dst[(j+13)*dim + i + 10] = src[(i+10)*dim + (j+13)];
      dst[(j+13)*dim + i + 11] = src[(i+11)*dim + (j+13)];
      dst[(j+13)*dim + i + 12] = src[(i+12)*dim + (j+13)];
      dst[(j+13)*dim + i + 13] = src[(i+13)*dim + (j+13)];
      dst[(j+13)*dim + i + 14] = src[(i+14)*dim + (j+13)];
      dst[(j+13)*dim + i + 15] = src[(i+15)*dim + (j+13)];
      dst[(j+14)*dim + i] = src[i*dim + (j+14)];
      dst[(j+14)*dim + i + 1] = src[(i+1)*dim + (j+14)];
      dst[(j+14)*dim + i + 2] = src[(i+2)*dim + (j+14)];
      dst[(j+14)*dim + i + 3] = src[(i+3)*dim + (j+14)];
      dst[(j+14)*dim + i + 4] = src[(i+4)*dim + (j+14)];
      dst[(j+14)*dim + i + 5] = src[(i+5)*dim + (j+14)];
      dst[(j+14)*dim + i + 6] = src[(i+6)*dim + (j+14)];
      dst[(j+14)*dim + i + 7] = src[(i+7)*dim + (j+14)];
      dst[(j+14)*dim + i + 8] = src[(i+8)*dim + (j+14)];
      dst[(j+14)*dim + i + 9] = src[(i+9)*dim + (j+14)];
      dst[(j+14)*dim + i + 10] = src[(i+10)*dim + (j+14)];
      dst[(j+14)*dim + i + 11] = src[(i+11)*dim + (j+14)];
      dst[(j+14)*dim + i + 12] = src[(i+12)*dim + (j+14)];
      dst[(j+14)*dim + i + 13] = src[(i+13)*dim + (j+14)];
      dst[(j+14)*dim + i + 14] = src[(i+14)*dim + (j+14)];
      dst[(j+14)*dim + i + 15] = src[(i+15)*dim + (j+14)];
      dst[(j+15)*dim + i] = src[i*dim + (j+15)];
      dst[(j+15)*dim + i + 1] = src[(i+1)*dim + (j+15)];
      dst[(j+15)*dim + i + 2] = src[(i+2)*dim + (j+15)];
      dst[(j+15)*dim + i + 3] = src[(i+3)*dim + (j+15)];
      dst[(j+15)*dim + i + 4] = src[(i+4)*dim + (j+15)];
      dst[(j+15)*dim + i + 5] = src[(i+5)*dim + (j+15)];
      dst[(j+15)*dim + i + 6] = src[(i+6)*dim + (j+15)];
      dst[(j+15)*dim + i + 7] = src[(i+7)*dim + (j+15)];
      dst[(j+15)*dim + i + 8] = src[(i+8)*dim + (j+15)];
      dst[(j+15)*dim + i + 9] = src[(i+9)*dim + (j+15)];
      dst[(j+15)*dim + i + 10] = src[(i+10)*dim + (j+15)];
      dst[(j+15)*dim + i + 11] = src[(i+11)*dim + (j+15)];
      dst[(j+15)*dim + i + 12] = src[(i+12)*dim + (j+15)];
      dst[(j+15)*dim + i + 13] = src[(i+13)*dim + (j+15)];
      dst[(j+15)*dim + i + 14] = src[(i+14)*dim + (j+15)];
      dst[(j+15)*dim + i + 15] = src[(i+15)*dim + (j+15)];
    }
    for (; j < dim; j++)
      dst[j*dim + i] = src[i*dim + j];
  }
  for (; i < dim; i++)
    for (j = 0; j < dim; j++)
      dst[j*dim + i] = src[i*dim + j];
}

#define SIZE 80
int main()
{
  int i,j;
  int dst1[SIZE][SIZE];
  int dst2[SIZE][SIZE];
  int src[SIZE][SIZE];
  for (i = 0; i < SIZE; i++)
    for (j = 0; j < SIZE; j++)
      src[i][j] = i;
  transpose((int *)dst1, (int *)src, SIZE);
  transpose4x4((int *)dst2, (int *)src, SIZE);
  transpose9x9((int *)dst2, (int *)src, SIZE);
  transpose16x16((int *)dst2, (int *)src, SIZE);
  transpose256((int *)dst2, (int *)src, SIZE);
  for (i = 0; i < SIZE; i++)
    for (j = 0; j < SIZE; j++)
      assert(dst1[i][j] == dst2[i][j]);
}
