#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "big_int.h"

/* 
=============== Helpers ===============
*/

/*
Prints BigInt data as a number

    Paramteres
    ----------
    a : BigInt* const
        pointer to the const BigInt structure

    Returns
    ----------
    void
        nothing to return
*/
void bi_print(BigInt const *a) {
    if (a->is_negative) {
        printf("-");
    }
    for (int i = a->size - 1; i >= 0; --i) {
        printf("%c", a->data[i] + '0');
    }
    printf("\n");
}

/*
Prints all information about BigInt.
* number
* size
* is_negative

    Paramteres
    ----------
    a : BigInt* const
        pointer to the const BigInt structure

    Returns
    ----------
    void
        nothing to return
*/
void bi_info(BigInt const *a) {
    printf("\n---------- INFO ----------\n");
    printf("number: ");
    for (int i = a->size - 1; i >= 0; --i) {
        printf("%c", a->data[i] + '0');
    }
    printf("\n");
    printf("size: %ld\n", a->size);
    printf("is_negative: ");
    printf(a->is_negative ? "true\n" : "false\n");
    printf("--------------------------\n\n");
}

/*
Compare two BigInt objects. 
1. Check which is_negative.
2. Check the size or go from last digit and compare every element

    Paramteres
    ----------
    a : void* const
        pointer to const void
    b : void* const
        pointer to const void

    Returns
    ----------
    int
         1  if a > b
        -1  if b < a
         0  if a == b
*/
int bi_cmp(void const *a, void const *b) {
    BigInt* bi_A = (BigInt*)a;
    BigInt* bi_B = (BigInt*)b;

    if (!bi_A->is_negative && bi_B->is_negative) {
        return 1;
    }
    if (bi_A->is_negative && !bi_B->is_negative) {
        return -1;
    }

    if (bi_A->is_negative && bi_B->is_negative) {
        if (bi_A->size < bi_B->size) {
            return 1;
        }
        if (bi_A->size > bi_B->size) {
            return -1;
        }
        for (unsigned int i = bi_A->size - 1; i >= 0; --i) {
            if (bi_A->data[i] < bi_B->data[i]) {
                return 1;
            }
            if (bi_A->data[i] > bi_B->data[i]) {
                return -1;
            }
        }
        return 0;
    }

    if (bi_A->size > bi_B->size) {
        return 1;
    }
    if (bi_A->size < bi_B->size) {
        return -1;
    }
    for (int i = bi_A->size - 1; i >= 0; --i) {
        if (bi_A->data[i] > bi_B->data[i]) {
            return 1;
        }
        if (bi_A->data[i] < bi_B->data[i]) {
            return -1;
        }
    }
    return 0;
}

/*
Reverse string 

    Paramteres
    ----------
    str : char*
        pointer to an array of chars

    Returns
    ----------
    void
        nothing to return
*/
void reverseString(char* str) {
    if (str[0] == 45) {
        int len = strlen(str) + 1;
        for (unsigned int i = 1; i < len / 2; ++i) {
            char temp = str[i];
            str[i] = str[len - 1 - i];
            str[len - 1 - i] = temp;
        }
    } else {
        int len = strlen(str);
        for (unsigned int i = 0; i < len / 2; ++i) {
            char temp = str[i];
            str[i] = str[len - 1 - i];
            str[len - 1 - i] = temp;
        }
    }
}