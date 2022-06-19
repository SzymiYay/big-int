#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "../src/big_int.h"

int main() {

    

    printf("\n======= TEST 1 =======\n");
    printf("| First: positive | Second: positive |\n");
    printf("| The same size |\n");
    printf("======================\n");

    BigInt* b1 = bi_new_from_string("12345");
    BigInt* b2 = bi_new_from_string("12345");

    printf("Create:\n");
    char* res1 = bi_convert_to_string(b1);
    char* res2 = bi_convert_to_string(b1);
    reverseString(res1);
    reverseString(res2);
    printf(strcmp(res1, "12345") ? "!!! WRONG !!!\n" : "[OK]\n");
    printf(strcmp(res2, "12345") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res1);
    free(res2);

    printf("Add:\n");
    char* res = bi_convert_to_string(bi_add(b1, b2));
    reverseString(res);
    printf(strcmp(res, "24690") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Subtract:\n");
    res = bi_convert_to_string(bi_subtract(b1, b2));
    reverseString(res);
    printf(strcmp(res, "0") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Multiply:\n");
    res = bi_convert_to_string(bi_multiply(b1, b2));
    reverseString(res);
    printf(strcmp(res, "152399025") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Compare:\n");
    printf(bi_cmp(b1, b2) ? "!!! WRONG !!!\n" : "[OK]\n");

    bi_free(b1);
    bi_free(b2);



    

    printf("\n======= TEST 2 =======\n");
    printf("| First: positive | Second: positive |\n");
    printf("| Second bigger than first |\n");
    printf("======================\n");

    b1 = bi_new_from_string("12345");
    b2 = bi_new_from_string("783465");

    printf("Create:\n");
    res1 = bi_convert_to_string(b1);
    res2 = bi_convert_to_string(b2);
    reverseString(res1);
    reverseString(res2);
    printf(strcmp(res1, "12345") ? "!!! WRONG !!!\n" : "[OK]\n");
    printf(strcmp(res2, "783465") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res1);
    free(res2);

    printf("Add:\n");
    res = bi_convert_to_string(bi_add(b1, b2));
    reverseString(res);
    printf(strcmp(res, "795810") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Subtract:\n");
    BigInt* d = bi_subtract(b1, b2);
    res = bi_convert_to_string(bi_subtract(b1, b2));
    reverseString(res);
    // Jest dobrze ale coś dziwnego wypisuje
    printf(strcmp(res, "-771120") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Multiply:\n");
    res = bi_convert_to_string(bi_multiply(b1, b2));
    reverseString(res);
    printf(strcmp(res, "9671875425") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Compare:\n");
    printf(bi_cmp(b1, b2) == -1 ? "[OK]\n" : "!!! WRONG !!!\n");
    
    bi_free(b1);
    bi_free(b2);


    

    printf("\n======= TEST 3 =======\n");
    printf("| First: positive | Second: positive |\n");
    printf("| Really big |\n");
    printf("======================\n");

    b1 = bi_new_from_string("734125096103596017857861235780615413425");
    b2 = bi_new_from_string("1234507861234587912349857618923576234");

    printf("Create:\n");
    res1 = bi_convert_to_string(b1);
    res2 = bi_convert_to_string(b2);
    reverseString(res1);
    reverseString(res2);
    printf(strcmp(res1, "734125096103596017857861235780615413425") ? "!!! WRONG !!!\n" : "[OK]\n");
    printf(strcmp(res2, "1234507861234587912349857618923576234") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res1);
    free(res2);

    printf("Add:\n");
    res = bi_convert_to_string(bi_add(b1, b2));
    reverseString(res);
    printf(strcmp(res, "735359603964830605770211093399538989659") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Subtract:\n");
    res = bi_convert_to_string(bi_subtract(b1, b2));
    reverseString(res);
    printf(strcmp(res, "732890588242361429945511378161691837191") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Multiply:\n");
    res = bi_convert_to_string(bi_multiply(b1, b2));
    reverseString(res);
    printf(strcmp(res, "906283202269486628112407259853980254964725772390690225151802555383414541450") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Compare:\n");
    printf(bi_cmp(b1, b2) == 1 ? "[OK]\n" : "!!! WRONG !!!\n");

    bi_free(b1);
    bi_free(b2);


    printf("\n======= TEST 4 =======\n");
    printf("| First: negative | Second: positive |\n");
    printf("| Really big |\n");
    printf("======================\n");

    b1 = bi_new_from_string("-734125096103596017857861235780615413425");
    b2 = bi_new_from_string("1234507861234587912349857618923576234");

    printf("Create:\n");
    res1 = bi_convert_to_string(b1);
    res2 = bi_convert_to_string(b2);
    reverseString(res1);
    reverseString(res2);
    printf(strcmp(res1, "-734125096103596017857861235780615413425") ? "!!! WRONG !!!\n" : "[OK]\n");
    printf(strcmp(res2, "1234507861234587912349857618923576234") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res1);
    free(res2);

    printf("Add:\n");
    BigInt* c = bi_add(b1, b2);
    res = bi_convert_to_string(c);
    reverseString(res);
    printf(strcmp(res, "-732890588242361429945511378161691837191") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Subtract:\n");
    res = bi_convert_to_string(bi_subtract(b1, b2));
    reverseString(res);
    printf(strcmp(res, "-735359603964830605770211093399538989659") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Multiply:\n");
    res = bi_convert_to_string(bi_multiply(b1, b2));
    reverseString(res);
    printf(strcmp(res, "-906283202269486628112407259853980254964725772390690225151802555383414541450") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Compare:\n");
    printf(bi_cmp(b1, b2) == -1 ? "[OK]\n" : "!!! WRONG !!!\n");

    bi_free(b1);
    bi_free(b2);




    printf("\n======= TEST 5 =======\n");
    printf("| First: negative | Second: negative |\n");
    printf("| Second bigger than first |\n");
    printf("======================\n");

    b1 = bi_new_from_string("-12345");
    b2 = bi_new_from_string("-54321");

    printf("Create:\n");
    res1 = bi_convert_to_string(b1);
    res2 = bi_convert_to_string(b2);
    reverseString(res1);
    reverseString(res2);
    printf(strcmp(res1, "-12345") ? "!!! WRONG !!!\n" : "[OK]\n");
    printf(strcmp(res2, "-54321") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res1);
    free(res2);

    printf("Add:\n");
    res = bi_convert_to_string(bi_add(b1, b2));
    reverseString(res);
    printf(strcmp(res, "-66666") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Subtract:\n");
    res = bi_convert_to_string(bi_subtract(b1, b2));
    reverseString(res);
    printf(strcmp(res, "41976") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Multiply:\n");
    res = bi_convert_to_string(bi_multiply(b1, b2));
    reverseString(res);
    printf(strcmp(res, "670592745") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Compare:\n");
    printf(bi_cmp(b1, b2) == 1 ? "[OK]\n" : "!!! WRONG !!!\n");

    bi_free(b1);
    bi_free(b2);


    printf("\n======= TEST 6 =======\n");
    printf("| First: positive | Second: zero |\n");
    printf("| Really big and zero |\n");
    printf("======================\n");

    b1 = bi_new_from_string("130459870193486509856078951345");
    b2 = bi_new_from_string("0");

    printf("Create:\n");
    res1 = bi_convert_to_string(b1);
    res2 = bi_convert_to_string(b2);
    reverseString(res1);
    reverseString(res2);
    printf(strcmp(res1, "130459870193486509856078951345") ? "!!! WRONG !!!\n" : "[OK]\n");
    printf(strcmp(res2, "0") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res1);
    free(res2);

    printf("Add:\n");
    res = bi_convert_to_string(bi_add(b1, b2));
    reverseString(res);
    printf(strcmp(res, "130459870193486509856078951345") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Subtract:\n");
    res = bi_convert_to_string(bi_subtract(b1, b2));
    reverseString(res);
    printf(strcmp(res, "130459870193486509856078951345") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Multiply:\n");
    res = bi_convert_to_string(bi_multiply(b1, b2));
    reverseString(res);
    printf(strcmp(res, "0") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Compare:\n");
    printf(bi_cmp(b1, b2) == 1 ? "[OK]\n" : "!!! WRONG !!!\n");

    bi_free(b1);
    bi_free(b2);



    printf("\n======= TEST 7 =======\n");
    printf("| First: zero | Second: negative |\n");
    printf("| Really big and zero |\n");
    printf("======================\n");

    b1 = bi_new_from_string("0");
    b2 = bi_new_from_string("-1340567910459367818723465");

    printf("Create:\n");
    res1 = bi_convert_to_string(b1);
    res2 = bi_convert_to_string(b2);
    reverseString(res1);
    reverseString(res2);
    printf(strcmp(res1, "0") ? "!!! WRONG !!!\n" : "[OK]\n");
    printf(strcmp(res2, "-1340567910459367818723465") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res1);
    free(res2);

    printf("Add:\n");
    res = bi_convert_to_string(bi_add(b1, b2));
    reverseString(res);
    printf(strcmp(res, "-1340567910459367818723465") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Subtract:\n");
    res = bi_convert_to_string(bi_subtract(b1, b2));
    reverseString(res);
    printf(strcmp(res, "-1340567910459367818723465") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Multiply:\n");
    res = bi_convert_to_string(bi_multiply(b1, b2));
    reverseString(res);
    printf(strcmp(res, "0") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Compare:\n");
    printf(bi_cmp(b1, b2) == 1 ? "[OK]\n" : "!!! WRONG !!!\n");

    bi_free(b1);
    bi_free(b2);



    printf("\n======= TEST 7 =======\n");
    printf("| First: zero | Second: zero |\n");
    printf("| Two zeros |\n");
    printf("======================\n");

    b1 = bi_new_from_string("0");
    b2 = bi_new_from_string("0");

    printf("Create:\n");
    res1 = bi_convert_to_string(b1);
    res2 = bi_convert_to_string(b2);
    reverseString(res1);
    reverseString(res2);
    printf(strcmp(res1, "0") ? "!!! WRONG !!!\n" : "[OK]\n");
    printf(strcmp(res2, "0") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res1);
    free(res2);

    printf("Add:\n");
    res = bi_convert_to_string(bi_add(b1, b2));
    reverseString(res);
    printf(strcmp(res, "0") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Subtract:\n");
    res = bi_convert_to_string(bi_subtract(b1, b2));
    reverseString(res);
    printf(strcmp(res, "0") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Multiply:\n");
    res = bi_convert_to_string(bi_multiply(b1, b2));
    reverseString(res);
    printf(strcmp(res, "0") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Compare:\n");
    printf(bi_cmp(b1, b2) == 0 ? "[OK]\n" : "!!! WRONG !!!\n");

    bi_free(b1);
    bi_free(b2);



    printf("\n======= TEST 8 =======\n");
    printf("| First: incorrect positive | Second: incorrect negative|\n");
    printf("| Positive with leading zeros, negative with leading zeros |\n");
    printf("======================\n");

    b1 = bi_new_from_string("000000112387945611234");
    b2 = bi_new_from_string("-000001297863518923745612345");

    printf("Create:\n");
    res1 = bi_convert_to_string(b1);
    res2 = bi_convert_to_string(b2);
    reverseString(res1);
    reverseString(res2);
    printf(strcmp(res1, "112387945611234") ? "!!! WRONG !!!\n" : "[OK]\n");
    printf(strcmp(res2, "-1297863518923745612345") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res1);
    free(res2);

    printf("Add:\n");
    res = bi_convert_to_string(bi_add(b1, b2));
    reverseString(res);
    printf(strcmp(res, "-1297863406535800001111") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Subtract:\n");
    res = bi_convert_to_string(bi_subtract(b1, b2));
    reverseString(res);
    printf(strcmp(res, "1297863631311691223579") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Multiply:\n");
    res = bi_convert_to_string(bi_multiply(b1, b2));
    reverseString(res);
    printf(strcmp(res, "-145864214575606691200057906641083730") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Compare:\n");
    printf(bi_cmp(b1, b2) == 1 ? "[OK]\n" : "!!! WRONG !!!\n");

    bi_free(b1);
    bi_free(b2);

    return 0;
}