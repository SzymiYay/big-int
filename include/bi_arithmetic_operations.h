#ifndef BIG_INT_ARTIHMETIC_H
#define BIG_INT_ARITHMETIC_H

#include <stdint.h>

/* =============== Arithmetic operations ===============*/
BigInt* bi_add(BigInt *a, BigInt *b);
BigInt* bi_subtract(BigInt *a, BigInt *b);
BigInt* bi_multiply(BigInt const *a, BigInt const *b);
BigInt* bi_divide(BigInt const *a, BigInt const *b);

#endif BIG_INT_ARITHMETIC_H