#ifndef BIG_INT_HELPER_H
#define BIG_INT_HELPER_H

#include <stdint.h>

/* =============== Helpers ===============*/
void bi_print(BigInt const *a);
void bi_info(BigInt const *a);
int bi_cmp(void const *a, void const *b);
void reverseString(char* str); // ANSI C

#endif BIG_INT_HELPER_H