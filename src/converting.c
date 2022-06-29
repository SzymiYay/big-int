#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "big_int.h"

/* 
=============== Converting ===============
*/

/*
Convert BigInt structure to string

    Paramteres
    ----------
    a : BigInt*
        pointer to /BigInt

    Returns
    ----------
    b_str : char*
        pointer to an array of chars - numbers from BigInt->data as chars

*/
char* bi_convert_to_string(BigInt const *a) {
    char* b_str;

    if (a->is_negative) {
        b_str = malloc(a->size + 2);

        b_str[0] = '-';
        for (unsigned int i = 1; i < a->size + 1; ++i) {
            b_str[i] = a->data[i - 1] + '0';
        }

        b_str[a->size + 1] = '\0';
    } else {
        b_str = malloc(a->size + 1);

        for (unsigned int i = 0; i < a->size; ++i) {
            b_str[i] = a->data[i] + '0';
        }

        b_str[a->size] = '\0';
    }

    return b_str;
}

/*
Convert string to BigInt structure

    Paramteres
    ----------
    str : char*
        pointer to an array of chars

    Returns
    ----------
    a : BigInt*
        pointer to the BigInt structure
*/
BigInt* bi_convert_to_big_int(char* str) {
    str += strspn(str, "0");
    BigInt* a = bi_new_from_string(str);

    // for (int i = 0; i < a->size; ++i) {
    //     a->data[a->size - 1 - i] = str[i] - '0';
    // }

    return a;
}