#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "big_int.h"

/* 
=============== Arithmetic operations ===============
*/

/*
bi_Add two BigInt structures 

    Paramteres
    ----------
    a : BigInt const *
        pointer to const BigInt
    b : BigInt const *
        pointer to const BigInt

    Returns
    ----------
    c : BigInt*
        pointer to the BigInt structure
*/
BigInt* bi_add(BigInt *a, BigInt *b) {

    size_t maxSize = a->size > b->size ? a->size : b->size;
    BigInt* c;

    if (a->size == 1 && a->data[0] == 0) {
        c = bi_new_from_big_int(b);
        return c;
    }

    if (b->size == 1 && b->data[0] == 0) {
        c = bi_new_from_big_int(a);
        return c;
    }

    if (!a->is_negative && b->is_negative) { // a + -b = a - b
        b->is_negative = false;
        c = bi_subtract(a, b);
        b->is_negative = true;
    }

    else if (a->is_negative && !b->is_negative) { // -a + b = b - a
        a->is_negative = false;
        c = bi_subtract(b, a);
        a->is_negative = true;
    }

    else {
        c = bi_new_with_size(maxSize + 1);
        int carry = 0;
        for (unsigned int i = 0; i < maxSize; ++i) {
            int tmp = carry;

            if (i < a->size) {
                tmp += a->data[i];
            }
            if (i < b->size) {
                tmp += b->data[i];
            }

            carry = tmp / 10;
            c->data[i] = tmp % 10;
        }

        if (carry) {
            c->data[c->size - 1] = 1;
        } else {
            c->size--;
        }
    }

    int k = c->size - 1;
    while (c->data[k] == 0) {
        c->size--;
        k--;
    }
    
    if (a->is_negative && b->is_negative) {
        c->is_negative = true;
    }

    return c;
}


/*
bi_Subtract two BigInt structures 

    Paramteres
    ----------
    a : BigInt const *
        pointer to const BigInt
    b : BigInt const *
        pointer to const BigInt

    Returns
    ----------
    c : BigInt*
        pointer to the BigInt structure
*/
BigInt* bi_subtract(BigInt *a, BigInt *b) {
    size_t maxSize = a->size > b->size ? a->size : b->size; // nie wiem jaki rozmiar tu powinien być
    BigInt* c;

    if (a->size == 1 && a->data[0] == 0) {
        c = bi_new_from_big_int(b);
        return c;
    }

    if (b->size == 1 && b->data[0] == 0) {
        c = bi_new_from_big_int(a);
        return c;
    }

     
    int change = bi_cmp(a, b);

    if (!change) {
        c = bi_new_with_size(1);
        c->data[0] = 0;
        return c;
    }

    if (!a->is_negative && b->is_negative) { // a - -b = a + b
        b->is_negative = false;
        c = bi_add(a, b);
        b->is_negative = true;
    }

    else if (a->is_negative && !b->is_negative) { // -a - b = -b + -a = -(a + b)
        a->is_negative = false;
        c = bi_add(a, b);
        a->is_negative = true;
        c->is_negative = true;
    }

    else if (a->is_negative && b->is_negative) { // -a - -b = -a + b = b - a
        a->is_negative = false;
        b->is_negative = false;
        c = bi_subtract(b, a);
        a->is_negative = true;
        b->is_negative = true;
    }

    else if (change < 0) { // b > a, a - b = -(b - a)
        c = bi_subtract(b, a);
        c->is_negative = true;
    }

    else {
        c = bi_new_with_size(maxSize); // usunałem -1 i nie ma wycieku pamięci

        bool carry = false;
        for (unsigned int i = 0; i < a->size; ++i) {
            int res = carry ? -1 : 0;

            if (i < a->size) {
                res += a->data[i];
            }
            if (i < b->size) {
                res -= b->data[i];
            }

            if (res < 0) {
                carry = true;
                res += 10;
            } else {
                carry = false;
            }

            c->data[i] = res;
        }
    }

    int k = c->size - 1;
    while (c->data[k] == 0) {
        c->size--;
        k--;
    }

    return c;
}


/*
Multiply two BigInt structures 

    Paramteres
    ----------
    a : BigInt const *
        pointer to const BigInt
    b : BigInt const *
        pointer to const BigInt

    Returns
    ----------
    c : BigInt*
        pointer to the BigInt structure
*/
BigInt* bi_multiply(BigInt const *a, BigInt const *b) {
    size_t maxSize = a->size + b->size;
    BigInt* c = bi_new_with_size(maxSize + 1);
    
    if ((a->is_negative && !b->is_negative) || (!a->is_negative && b->is_negative)) {
        c->is_negative = true;
    }

    if ((a->size == 1 && a->data[0] == 0) || (b->size == 1 &&b->data[0] == 0)) {
        c->size = 1;
        c->data[0] = 0;
        c->is_negative = false;
        return c;
    }

    for (unsigned int i = 0; i < maxSize; ++i) {
        c->data[i] = 0;
    }

    int idx = 0;
    int startIdx = 0;
    for (int i = 0; i < a->size; ++i) {
        int carry = 0;
        idx = startIdx;
        for (unsigned int j = 0; j < b->size; ++j) {
            int product = a->data[i] * b->data[j] + carry;

            carry = product / 10;
            product %= 10;
            c->data[idx] += product;

            if (c->data[idx] > 9) {
                int helper = c->data[idx] / 10;
                c->data[idx] %= 10;
                c->data[idx + 1] += helper;
            }
            idx++;

            if (j + 1 == b->size) {
                c->data[idx] += carry;
            }
        }
        startIdx += 1;
    }

    int k = c->size - 1;
    while (c->data[k] == 0) {
        c->size--;
        k--;
    }

    return c;
}