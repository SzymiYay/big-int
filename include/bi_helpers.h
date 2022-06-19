#ifndef BIG_INT_CREATE_H
#define BIG_INT_CREATE_H

#include <stdint.h>

/* =============== Creating and freeing ===============*/
BigInt* bi_new_from_string(char const * str);
BigInt* bi_new_with_size(size_t size);
BigInt* bi_new_from_big_int(BigInt const *a);
void bi_free(BigInt* a);

#endif BIG_INT_CREATE_H