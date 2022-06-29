#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "../include/big_int.h"



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

    printf("XDDDDDDDDDD create %d\n", a->size);

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
    printf("XDDDDDDDDDD 1. multiply %ld\n", c->size);
    
    if ((a->is_negative && !b->is_negative) || (!a->is_negative && b->is_negative)) {
        c->is_negative = true;
    }

    if ((a->size == 1 && a->data[0] == 0) || (b->size == 1 && b->data[0] == 0)) {
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
    printf("\n======================================\n");
    for (int i = 0; i < c->size; ++i) {
        printf("%d ", c->data[i]);
    }
    printf("\n======================================\n");

    int k = c->size - 1;
    while (c->data[k] == 0) {
        c->size--;
        k--;
    }

    printf("======================================\n");
    for (int i = 0; i < c->size; ++i) {
        printf("%d ", c->data[i]);
    }
    printf("\n======================================\n");

    printf("XDDDDDDDDDD 2. multiply %ld\n", c->size);

    return c;
}
