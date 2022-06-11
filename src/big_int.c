#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "big_int.h"



/* 
=============== Creating and freeing ===============
*/

BigInt* newBigIntFromString(char* str) {
    BigInt* a = malloc(sizeof(a));

    if (a) {
        a->size = strlen(str);
        a->data = malloc(a->size * sizeof(int));
    }

    return a;
}

BigInt* newBigIntWithSize(size_t size) {
    BigInt* a = malloc(sizeof(a));

    if (a) {
        a->size = size;
        a->data = malloc(size * sizeof(int));
    }

    return a;
}

void freeBigInt(BigInt* a) {
    if (a) {
        free(a->data);
        free(a);
    }
}


/* 
=============== Helpers ===============
*/

void printBigInt(BigInt* a) {
    if (a->isNegative) {
        printf("-");
    }
    for (int i = a->size - 1; i >= 0; --i) {
        printf("%c", a->data[i] + '0');
    }
    printf("\n");
}



/* 
=============== Converting ===============
*/

char* convertBigIntToString(BigInt* a) {
    char* b_str = malloc(a->size + 1);

    for (int i = 0; i < a->size; ++i) {
        b_str[i] = a->data[i] + '0';
    }
    b_str[a->size] = '\0';

    return b_str;
}

BigInt* convertStringToBigInt(char* str) {
    str += strspn(str, "0");
    BigInt* a = newBigIntFromString(str);

    for (int i = 0; i < a->size; ++i) {
        a->data[a->size - 1 - i] = str[i] - '0';
    }

    return a;
}



/* 
=============== Arithmetic operations ===============
*/

BigInt* add(BigInt* a, BigInt* b) {

    size_t maxSize = a->size > b->size ? a->size : b->size;
    BigInt* c = newBigIntWithSize(maxSize + 1);

    int carry = 0;
    for (int i = 0; i < maxSize; ++i) {
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
        c->data[c->size] = 1;
    } else {
        c->size--;
    }

    return c;
}