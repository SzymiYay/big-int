#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "big_int.h"

int main() {

    BigInt* bi1 = newBigIntFromString("12345");
    // bi1 = convertStringToBigInt("23567");
    // printBigInt(bi1);
    infoBigInt(bi1);

    BigInt* bi2 = newBigIntFromString("783465");
    // bi2 = convertStringToBigInt("16245");
    // printBigInt(bi2);
    infoBigInt(bi2);

    printBigInt(add(bi1, bi2));
    printBigInt(subtract(bi1, bi2));
    printBigInt(multiply(bi1, bi2));
    printf("%d", cmp(bi1, bi2));

    freeBigInt(bi1);
    freeBigInt(bi2);

    return 0;
}