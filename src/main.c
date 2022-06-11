#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "big_int.h"

int main() {

    BigInt* bi1 = newBigIntFromString("234");
    bi1 = convertStringToBigInt("234");
    printBigInt(bi1);

    BigInt* bi2 = newBigIntFromString("567");
    bi2 = convertStringToBigInt("567");
    printBigInt(bi2);

    printBigInt(add(bi1, bi2));

    return 0;
}