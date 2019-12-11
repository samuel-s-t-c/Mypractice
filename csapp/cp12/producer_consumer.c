#include "csapp.h"
#include "sbuf.h"

#define N 15

void *producer(void *vargp);
void *consumer(void *vargp);
sbuf_t sp;

int main()
{
  sbuf_init(&sp, N);
  pthread_t tid;
  Pthread_create(&tid, NULL, producer, NULL);
  Pthread_create(&tid, NULL, consumer, NULL);
  Pthread_exit(NULL);
}

void *producer(void *vargp)
{
  for(int i = 0; i < N; i++)
    sbuf_insert(&sp, i);
  return NULL;
}

void *consumer(void *vargp)
{
  int item;
  for (int i = 0; i < N; i++) {
    item = sbuf_remove(&sp);
    printf("[%d]th item: %d\n", i, item);
  }
  return NULL;
}

int n_write, n_read;
sem_t mutex1, mutex2, mutex3, w, r;

void *writer(void *vargp)
{
  P(&mutex1);
  n_write++;
  if (n_write == 1)
    P(&r);
  V(&mutex1);

  P(&w);
  //writing
  V(&w);

  P(&mutex1);
  n_write--;
  if (n_write == 0)
    V(&r);
  V(&mutex1);
  return NULL;
}

void *reader(void *vargp)
{
  P(&mutex3);
  P(&r);
  P(&mutex2);
  n_read++;
  if (n_read == 1)
    P(&w);
  V(&mutex2);
  V(&r);
  V(&mutex3);

  //reading

  P(&mutex2);
  n_read--;
  if (n_read == 0)
    V(&w);
  V(&mutex2);
  return NULL;
}
