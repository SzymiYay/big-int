#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "big_int.h"

/* 
=============== Creating and freeing ===============
*/

/*
Allocate memory for new BigInt stucture and fill data with consecutive numbers
from given string.

    Paramteres
    ----------
    str : char*
        pointer to an array of chars

    Returns
    ----------
    a : BigInt*
        pointer to the BigInt structure
*/
BigInt* bi_new_from_string(char const * str) {

    BigInt* a = malloc(sizeof(BigInt));

    if (!a) {
        exit(0);
    }

    a->is_negative = false;

    if (str[0] == '-') {
        str++;
        a->is_negative = true;
    }

    if (strlen(str) != 1) {
        str += strspn(str, "0");
    }

    a->size = strlen(str);
    a->data = malloc(a->size * sizeof(uint8_t));

    for (unsigned int i = 0; i < a->size; ++i) {
        a->data[a->size - 1 - i] = str[i] - '0';
    }

    return a;
}


/*
Allocate memory for new BigInt stucture and fill data with consecutive numbers
from given string.

    Paramteres
    ----------
    size : size_t
        size of BigInt, number of elements in data

    Returns
    ----------
    a : BigInt*
        pointer to the BigInt structure
*/
BigInt* bi_new_with_size(size_t size) {
    BigInt* a = malloc(sizeof(BigInt));

    if (!a) {
        exit(0);
    }

    a->size = size;
    a->data = malloc(size * sizeof(uint8_t));
    a->is_negative = false;

    return a;
}

BigInt* bi_new_from_big_int(BigInt const * a) {
    BigInt* b = bi_new_with_size(a->size);

    if (!b) {
        exit(0);
    }

    for (unsigned int i = 0; i < a->size; ++i) {
        b->data[i] = a->data[i];
    }

    b->is_negative = a->is_negative;

    return b;
}


/*
Free allocated memory in data and whole structure.

    Paramteres
    ----------
    a : BigInt*
        pointer to the BigInt structure

    Returns
    ----------
    void
        nothing to return
*/
void bi_free(BigInt* a) {
    free(a->data);
    free(a);
}