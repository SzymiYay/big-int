#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "big_int.h"

int main() {

    BigInt* bi1 = newBigIntFromString("12345");
    infoBigInt(bi1);

    BigInt* bi2 = newBigIntFromString("783465");
    infoBigInt(bi2);

    // BigInt* c = add(bi1, bi2);
    // char* res = convertBigIntToString(c);
    // reverseString(res);
    // for (int i = 0; i < c->size + 1; ++i) {
    //     printf("%d ", res[i] - '0');
    // }
    // infoBigInt(c);
    // printBigInt(c);

    printBigInt(add(bi1, bi2));
    printBigInt(subtract(bi1, bi2));
    printBigInt(multiply(bi1, bi2));
    printf("%d", cmp(bi1, bi2));

    // char* res = convertBigIntToString(add(bi1, bi2));
    // reverseString(res);
    // printf("\n%d\n", strcmp(res, "-732890588242361429945511378161691837191"));

    freeBigInt(bi1);
    freeBigInt(bi2);

    return 0;
}