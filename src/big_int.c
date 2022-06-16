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
BigInt* newBigIntFromString(char* str) {

    BigInt* a = malloc(sizeof(BigInt));

    if (a) {
        a->isNegative = false;

        if (str[0] == '-') {
            str++;
            a->isNegative = true;
        }

        if (strlen(str) != 1) {
            str += strspn(str, "0");
        }

        a->size = strlen(str);
        a->data = malloc(a->size * sizeof(uint8_t));

        for (int i = 0; i < a->size; ++i) {
            a->data[a->size - 1 - i] = str[i] - '0';
        }
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
BigInt* newBigIntWithSize(size_t size) {
    BigInt* a = malloc(sizeof(a));

    if (a) {
        a->size = size;
        a->data = malloc(size * sizeof(int));
        a->isNegative = false;
    }

    return a;
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
void freeBigInt(BigInt* a) {
    if (a) {
        free(a->data);
        free(a);
    }
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
void printBigInt(BigInt const *a) {
    if (a->isNegative) {
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
* isNegative

    Paramteres
    ----------
    a : BigInt* const
        pointer to the const BigInt structure

    Returns
    ----------
    void
        nothing to return
*/
void infoBigInt(BigInt const *a) {
    printf("\n---------- INFO ----------\n");
    printf("number: ");
    for (int i = a->size - 1; i >= 0; --i) {
        printf("%c", a->data[i] + '0');
    }
    printf("\n");
    printf("size: %ld\n", a->size);
    printf("isNegative: ");
    printf(a->isNegative ? "true\n" : "false\n");
    printf("--------------------------\n\n");
}

/*
Compare two BigInt objects. 
1. Check which isNegative.
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
int cmp(void const *a, void const *b) {
    BigInt* bigIntA = (BigInt*)a;
    BigInt* bigIntB = (BigInt*)b;

    if (!bigIntA->isNegative && bigIntB->isNegative) {
        return 1;
    }
    if (bigIntA->isNegative && !bigIntB->isNegative) {
        return -1;
    }

    if (bigIntA->isNegative && bigIntB->isNegative) {
        if (bigIntA->size < bigIntB->size) {
            return 1;
        }
        if (bigIntA->size > bigIntB->size) {
            return -1;
        }
        for (int i = bigIntA->size - 1; i >= 0; --i) {
            if (bigIntA->data[i] < bigIntB->data[i]) {
                return 1;
            }
            if (bigIntA->data[i] > bigIntB->data[i]) {
                return -1;
            }
        }
        return 0;
    }

    if (bigIntA->size > bigIntB->size) {
        return 1;
    }
    if (bigIntA->size < bigIntB->size) {
        return -1;
    }
    for (int i = bigIntA->size - 1; i >= 0; --i) {
        if (bigIntA->data[i] > bigIntB->data[i]) {
            return 1;
        }
        if (bigIntA->data[i] < bigIntB->data[i]) {
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
        for (int i = 1; i < len / 2; ++i) {
            char temp = str[i];
            str[i] = str[len - 1 - i];
            str[len - 1 - i] = temp;
        }
    } else {
        int len = strlen(str);
        for (int i = 0; i < len / 2; ++i) {
            char temp = str[i];
            str[i] = str[len - 1 - i];
            str[len - 1 - i] = temp;
        }
    }
}

/*
Creates new structure and copy all elements from given

    Paramteres
    ----------
    a : BigInt const *
        pointer to the const BigInt

    Returns
    ----------
    b : BigInt *
        pointer to the BigInt
*/
BigInt* copy(BigInt const *a) {
    BigInt* b = newBigIntWithSize(a->size);
    b->isNegative = a->isNegative;
    for (int i = 0; i < a->size; ++i) {
        b->data[i] = a->data[i];
    }
    return b;
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
char* convertBigIntToString(BigInt const *a) {
    char* b_str;

    if (a->isNegative) {
        b_str = malloc(a->size + 2);

        b_str[0] = '-';
        for (int i = 1; i < a->size + 1; ++i) {
            b_str[i] = a->data[i - 1] + '0';
        }

        b_str[a->size + 1] = '\0';
    } else {
        b_str = malloc(a->size + 1);

        for (int i = 0; i < a->size; ++i) {
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
BigInt* convertStringToBigInt(char* str) {
    str += strspn(str, "0");
    BigInt* a = newBigIntFromString(str);

    // for (int i = 0; i < a->size; ++i) {
    //     a->data[a->size - 1 - i] = str[i] - '0';
    // }

    return a;
}



/* 
=============== Arithmetic operations ===============
*/

/*
Add two BigInt structures 

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
BigInt* add(BigInt *a, BigInt *b) {

    size_t maxSize = a->size > b->size ? a->size : b->size;
    BigInt* c = newBigIntWithSize(maxSize + 1);

    if (a->size == 1 && a->data[0] == 0) {
        c = copy(b);
        return c;
    }

    if (b->size == 1 && b->data[0] == 0) {
        c = copy(a);
        return c;
    }

    if (!a->isNegative && b->isNegative) { // a + -b = a - b
        b->isNegative = false;
        c = subtract(a, b);
        b->isNegative = true;
    }

    else if (a->isNegative && !b->isNegative) { // -a + b = b - a
        a->isNegative = false;
        c = subtract(b, a);
        a->isNegative = true;
    }

    else {
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
            c->data[c->size - 1] = 1;
        } else {
            c->size--;
        }
    }
    
    if (a->isNegative && b->isNegative) {
        c->isNegative = true;
    }

    return c;
}


/*
Subtract two BigInt structures 

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
BigInt* subtract(BigInt *a, BigInt *b) {
    size_t maxSize = a->size > b->size ? a->size : b->size; // nie wiem jaki rozmiar tu powinien być
    BigInt* c = newBigIntWithSize(maxSize + 1);

    if (a->size == 1 && a->data[0] == 0) {
        c = copy(b);
        return c;
    }

    if (b->size == 1 && b->data[0] == 0) {
        c = copy(a);
        return c;
    }


    if (!a->isNegative && b->isNegative) { // a - -b = a + b
        b->isNegative = false;
        c = add(a, b);
        b->isNegative = true;
    }

    else if (a->isNegative && !b->isNegative) { // -a - b = -b + -a = -(a + b)
        a->isNegative = false;
        c = add(a, b);
        a->isNegative = true;
        c->isNegative = true;
    }

    else if (a->isNegative && b->isNegative) { // -a - -b = -a + b = b - a
        a->isNegative = false;
        b->isNegative = false;
        c = subtract(b, a);
        a->isNegative = true;
        b->isNegative = true;
    }

    else {
        int change = cmp(a, b); // inna nazwa powinna być

        int carry = 0;
        for (int i = 0; i < maxSize; ++i) {
            int diff;
            if (change == -1) {
                diff = b->data[i] - a->data[i] - carry;
            } else {
                diff = a->data[i] - b->data[i] - carry;
            }
            
            if (diff < 0) {
                diff += 10;
                carry = 1;
            } else {
                carry = 0;
            }
            c->data[i] = diff;
        }

        if (change == -1) {
            c->isNegative = true;
        }

        int k = c->size - 1;
        while (c->size > 0 && c->data[k] == 0) {
            c->size--;
            k--;
        }

        if (c->size == 0) {
            c->size = 1;
            c->data[0] = 0;
            c->isNegative = false;
        }
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
BigInt* multiply(BigInt const *a, BigInt const *b) {
    size_t maxSize = a->size + b->size;
    BigInt* c = newBigIntWithSize(maxSize + 1);
    
    if ((a->isNegative && !b->isNegative) || (!a->isNegative && b->isNegative)) {
        c->isNegative = true;
    }

    if ((a->size == 1 && a->data[0] == 0) || (b->size == 1 &&b->data[0] == 0)) {
        c->size = 1;
        c->data[0] = 0;
        c->isNegative = false;
        return c;
    }

    for (int i = 0; i < maxSize; ++i) {
        c->data[i] = 0;
    }

    int idx = 0;
    int startIdx = 0;
    for (int i = 0; i < a->size; ++i) {
        int carry = 0;
        idx = startIdx;
        for (int j = 0; j < b->size; ++j) {
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
