#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "../include/big_int.h"

int main() {

    BigInt* bi1 = bi_new_from_string("152513812818262558893");
    bi_info(bi1);

    BigInt* bi2 = bi_new_from_string("-3171625935665497546223");
    bi_info(bi2);

    BigInt* a = bi_add(bi1, bi2);
    BigInt* b = bi_subtract(bi1, bi2);
    BigInt* c = bi_multiply(bi1, bi2);
    int d = bi_cmp(bi1, bi2);

    bi_print(a);
    bi_print(b);
    bi_print(c);
    bi_info(a);
    bi_info(b);
    bi_info(c);
    printf("%d", d);

    bi_free(bi1);
    bi_free(bi2);

    bi_free(a);
    bi_free(b);
    bi_free(c);


    return 0;
}