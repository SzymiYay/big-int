#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "../src/big_int.h"

int main() {

    

    printf("\n======= TEST 1 =======\n");

    BigInt* b1 = newBigIntFromString("12345");
    BigInt* b2 = newBigIntFromString("12345");

    printf("Create:\n");
    char* res1 = convertBigIntToString(b1);
    char* res2 = convertBigIntToString(b1);
    reverseString(res1);
    reverseString(res2);
    printf(strcmp(res1, "12345") ? "!!! WRONG !!!\n" : "[OK]\n");
    printf(strcmp(res2, "12345") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res1);
    free(res2);

    printf("Add:\n");
    char* res = convertBigIntToString(add(b1, b2));
    reverseString(res);
    printf(strcmp(res, "24690") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Subtract:\n");
    res = convertBigIntToString(subtract(b1, b2));
    reverseString(res);
    printf(strcmp(res, "0") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Multiply:\n");
    res = convertBigIntToString(multiply(b1, b2));
    reverseString(res);
    printf(strcmp(res, "152399025") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Compare:\n");
    printf(cmp(b1, b2) ? "!!! WRONG !!!\n" : "[OK]\n");

    freeBigInt(b1);
    freeBigInt(b2);



    

    printf("\n======= TEST 2 =======\n");

    b1 = newBigIntFromString("12345");
    b2 = newBigIntFromString("783465");

    printf("Create:\n");
    res1 = convertBigIntToString(b1);
    res2 = convertBigIntToString(b2);
    reverseString(res1);
    reverseString(res2);
    printf(strcmp(res1, "12345") ? "!!! WRONG !!!\n" : "[OK]\n");
    printf(strcmp(res2, "783465") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res1);
    free(res2);

    printf("Add:\n");
    res = convertBigIntToString(add(b1, b2));
    reverseString(res);
    printf(strcmp(res, "795810") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Subtract:\n");
    res = convertBigIntToString(subtract(b1, b2));
    for (int i = 0; i < strlen(res); ++i) {
        printf("%d ", res[i]);
    }
    reverseString(res);
    for (int i = 0; i < strlen(res); ++i) {
        printf("%d ", res[i]);
    }
    // Jest dobrze ale coś dziwnego wypisuje
    printf(strcmp(res, "-771120") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Multiply:\n");
    res = convertBigIntToString(multiply(b1, b2));
    reverseString(res);
    printf(strcmp(res, "9671875425") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Compare:\n");
    printf(cmp(b1, b2) == -1 ? "[OK]\n" : "!!! WRONG !!!\n");
    
    freeBigInt(b1);
    freeBigInt(b2);


    

    printf("\n======= TEST 3 =======\n");

    b1 = newBigIntFromString("734125096103596017857861235780615413425");
    b2 = newBigIntFromString("1234507861234587912349857618923576234");

    printf("Create:\n");
    res1 = convertBigIntToString(b1);
    res2 = convertBigIntToString(b2);
    reverseString(res1);
    reverseString(res2);
    printf(strcmp(res1, "734125096103596017857861235780615413425") ? "!!! WRONG !!!\n" : "[OK]\n");
    printf(strcmp(res2, "1234507861234587912349857618923576234") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res1);
    free(res2);

    printf("Add:\n");
    res = convertBigIntToString(add(b1, b2));
    reverseString(res);
    printf(strcmp(res, "735359603964830605770211093399538989659") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Subtract:\n");
    res = convertBigIntToString(subtract(b1, b2));
    reverseString(res);
    printf(strcmp(res, "732890588242361429945511378161691837191") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Multiply:\n");
    res = convertBigIntToString(multiply(b1, b2));
    reverseString(res);
    printf(strcmp(res, "906283202269486628112407259853980254964725772390690225151802555383414541450") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Compare:\n");
    printf(cmp(b1, b2) == 1 ? "[OK]\n" : "!!! WRONG !!!\n");

    freeBigInt(b1);
    freeBigInt(b2);


    printf("\n======= TEST 4 =======\n");

    b1 = newBigIntFromString("-734125096103596017857861235780615413425");
    b2 = newBigIntFromString("1234507861234587912349857618923576234");

    printf("Create:\n");
    res1 = convertBigIntToString(b1);
    res2 = convertBigIntToString(b2);
    reverseString(res1);
    reverseString(res2);
    printf(strcmp(res1, "-734125096103596017857861235780615413425") ? "!!! WRONG !!!\n" : "[OK]\n");
    printf(strcmp(res2, "1234507861234587912349857618923576234") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res1);
    free(res2);

    printf("Add:\n");
    res = convertBigIntToString(add(b1, b2));
    reverseString(res);
    printf(strcmp(res, "-732890588242361429945511378161691837191") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Subtract:\n");
    res = convertBigIntToString(subtract(b1, b2));
    reverseString(res);
    printf(strcmp(res, "-735359603964830605770211093399538989659") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Multiply:\n");
    res = convertBigIntToString(multiply(b1, b2));
    reverseString(res);
    printf(strcmp(res, "-906283202269486628112407259853980254964725772390690225151802555383414541450") ? "!!! WRONG !!!\n" : "[OK]\n");
    free(res);

    printf("Compare:\n");
    printf(cmp(b1, b2) == -1 ? "[OK]\n" : "!!! WRONG !!!\n");

    freeBigInt(b1);
    freeBigInt(b2);

    return 0;
}