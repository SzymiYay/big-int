#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "big_int.h"

int main() {

    BigInt* bi1 = bi_new_from_string("12345");
    bi_info(bi1);

    BigInt* bi2 = bi_new_from_string("783465");
    bi_info(bi2);

    // BigInt* c = bi_subtract(bi1, bi2);
    // bi_info(c);
    // char* res = bi_convert_to_string(c);
    // for (int i = 0; i < strlen(res); ++i) {
    //     printf("%d ", res[i] - '0');
    // }
    // reverseString(res);
    // for (int i = 0; i < strlen(res); ++i) {
    //     printf("%d ", res[i] - '0');
    // }
    
    // bi_print(c);

    BigInt* a = bi_add(bi1, bi2);
    BigInt* b = bi_subtract(bi1, bi2);
    // BigInt* c = bi_multiply(bi1, bi2);
    // BigInt* d = bi_cmp(bi1, bi2);

    bi_print(a);
    bi_print(b);
    // bi_print(c);
    bi_info(a);
    bi_info(b);
    // bi_info(c);
    // printf("%d", d);

    // char* res = convertBigIntToString(bi_add(bi1, bi2));
    // reverseString(res);
    // printf("\n%d\n", strbi_cmp(res, "-732890588242361429945511378161691837191"));

    bi_free(bi1);
    bi_free(bi2);

    bi_free(a);
    bi_free(b);
    // bi_free(c);
    // bi_free(d);

    return 0;
}