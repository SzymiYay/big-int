#ifndef BIG_INT_CONVERTING_H
#define BIG_INT_CONVERTING_H

#include <stdint.h>

/* =============== Converting ===============*/
char* bi_convert_to_string(BigInt const *a);
BigInt* bi_convert_to_big_int(char* str);

#endif BIG_INT_CONVERTING_H