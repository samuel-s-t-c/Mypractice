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
