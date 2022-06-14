#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "big_int.h"

int main() {

    BigInt* bi1 = newBigIntFromString("534");
    bi1 = convertStringToBigInt("534");
    printBigInt(bi1);

    BigInt* bi2 = newBigIntFromString("534");
    bi2 = convertStringToBigInt("534");
    printBigInt(bi2);

    printBigInt(add(bi1, bi2));
    printBigInt(subtract(bi2, bi1));
    printf("%d", cmp(bi1, bi2));

    return 0;
}