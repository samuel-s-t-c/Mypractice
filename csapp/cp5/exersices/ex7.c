#define IDENT 1
#define OP  *
typedef long data_t;
typedef struct {
  long len;
  data_t *data;
} vec_rec, *vec_ptr;

int get_vec_element(vec_ptr v, long index, data_t *dest)
{
  if (index < 0 || index >= v->len)
    return 0;
  *dest = v->data[index];
  return 1;
}

/* Return length of vector */
long vec_length(vec_ptr v)
{
  return v->len;
}
/* $end vec */


/* $begin get_vec_start */
data_t *get_vec_start(vec_ptr v)
{
  return v->data;
}
/* $end get_vec_start */
/* $begin combine5 */
/* 5 x 1 loop unrolling */
void combine5(vec_ptr v, data_t *dest)
{
  long i;
  long length = vec_length(v);
  long limit = length-4;
  data_t *data = get_vec_start(v);
  data_t acc = IDENT;

  /* Combine 2 elements at a time */
  for (i = 0; i < limit; i+=5) {
    /* $begin combine5-update */
    acc = (acc OP data[i]) OP data[i+1];
    acc = (acc OP data[i+2]) OP data[i+3];
    acc = acc OP data[i+4];
    /* $end combine5-update */
  }

  /* Finish any remaining elements */
  for (; i < length; i++) {
    acc = acc OP data[i];
  }
  *dest = acc;
}
/* $end combine5 */
