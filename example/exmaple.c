#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "../src/big_int.h"

int main() {

    BigInt* a = newBigIntFromString("1237854691872354698172346589716234598716327896");
    BigInt* b = newBigIntFromString("-1342059804135670179486501673450164501647350105347");

    infoBigInt(a);
    infoBigInt(b);

    printBigInt(add(a, b));
    printBigInt(subtract(a, b));
    printBigInt(multiply(a, b));

    return 0;
}