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

    BigInt* a = malloc(sizeof(BigInt));

    if (a) {
        a->isNegative = false;

        if (str[0] == '-') {
            str++;
            a->isNegative = true;
        }

        str += strspn(str, "0");

        a->size = strlen(str);
        a->data = malloc(a->size * sizeof(uint8_t));

        for (int i = 0; i < a->size; ++i) {
            a->data[a->size - 1 - i] = str[i] - '0';
        }
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

void printBigInt(BigInt* const a) {
    if (a->isNegative) {
        printf("-");
    }
    for (int i = a->size - 1; i >= 0; --i) {
        printf("%c", a->data[i] + '0');
    }
    printf("\n");
}

void infoBigInt(BigInt* const a) {
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

int cmp(void* const a, void* const b) {
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
=============== Converting ===============
*/

char* convertBigIntToString(BigInt* a) {
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

BigInt* add(BigInt* const a, BigInt* const b) {

    size_t maxSize = a->size > b->size ? a->size : b->size;
    BigInt* c = newBigIntWithSize(maxSize + 1);


    if (!a->isNegative && b->isNegative) { // a + -b = b - a
        c = subtract(b, a);
    }

    else if (a->isNegative && !b->isNegative) { // -a + b = b - a
        c = subtract(b, a);
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

BigInt* subtract(BigInt* const a, BigInt* const b) {
    size_t maxSize = a->size > b->size ? a->size : b->size; // nie wiem jaki rozmiar tu powinien być
    BigInt* c = newBigIntWithSize(maxSize);


    if (!a->isNegative && b->isNegative) { // a - -b = a + b
        c->isNegative = false;
        c = add(a, b);
    }

    else if (a->isNegative && !b->isNegative) { // -a - b = -b + -a = -(a + b)
        c->isNegative = true;
        c = add(a, b);
    }

    else if (a->isNegative && b->isNegative) { // -a - -b = -a + b = b - a
        c = subtract(b, a);
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
        }
    }
    
    return c;
}

BigInt* multiply(BigInt* const a, BigInt* const b) {
    size_t maxSize = a->size + b->size;
    BigInt* c = newBigIntWithSize(maxSize + 1);

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


// BigInt* subtract(BigInt* const a, BigInt* const b) {
//     size_t maxSize = a->size > b->size ? a->size : b->size; // nie wiem jaki rozmiar tu powinien być
//     BigInt* c = newBigIntWithSize(maxSize);


    


//     int change = cmp(a, b); // inna nazwa powinna być

//     int carry = 0;
//     for (int i = 0; i < maxSize; ++i) {
//         int diff;
//         if (change == -1) {
//             diff = b->data[i] - a->data[i] - carry;
//         } else {
//             diff = a->data[i] - b->data[i] - carry;
//         }
        
//         if (diff < 0) {
//             diff += 10;
//             carry = 1;
//         } else {
//             carry = 0;
//         }
//         c->data[i] = diff;
//     }

//     if (change == -1) {
//          c->isNegative = true;
//     }

//     int k = c->size - 1;
//     while (c->size > 0 && c->data[k] == 0) {
//         c->size--;
//         k--;
//     }

//     if (c->size == 0) {
//         c->size = 1;
//         c->data[0] = 0;
//     }
   
//     return c;
// }

// BigInt* multiply(BigInt* const a, BigInt* const b) {
//     size_t maxSize = a->size + b->size;
//     BigInt* c = newBigIntWithSize(maxSize + 1);

//     for (int i = 0; i < maxSize; ++i) {
//         c->data[i] = 0;
//     }

//     int idx = 0;
//     int startIdx = 0;
//     for (int i = 0; i < a->size; ++i) {
//         int carry = 0;
//         idx = startIdx;
//         for (int j = 0; j < b->size; ++j) {
//             int product = a->data[i] * b->data[j] + carry;

//             carry = product / 10;
//             product %= 10;
//             c->data[idx] += product;

//             if (c->data[idx] > 9) {
//                 int helper = c->data[idx] / 10;
//                 c->data[idx] %= 10;
//                 c->data[idx + 1] += helper;
//             }
//             idx++;

//             if (j + 1 == b->size) {
//                 c->data[idx] += carry;
//             }
//         }
//         startIdx += 1;
//     }

//     int k = c->size - 1;
//     while (c->data[k] == 0) {
//         c->size--;
//         k--;
//     }

//     return c;
// }