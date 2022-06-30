#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "../include/big_int.h"

// #define SIZE 10000;

struct numbers {
    char a[100];
    char b[100];
    char res[100];
};
struct numbers nums[10000];

int main() {

    FILE *fp;
    fp = fopen("number_files/numbers.txt", "r");
    FILE *gp;
    gp = fopen("number_files/result.txt", "r");
    

    if (fp == NULL || gp == NULL) {
        printf("no such file");
        return 0;
    }

    char ch;
    int count = 0;
    do {
        ch = fgetc(fp);
        if (ch == '\n') {
            count++;
        }
    } while (ch != EOF);
    rewind(fp);

    for (int i = 0; i < count; ++i) {
        fscanf(fp, "%s %s\n", &nums[i].a, &nums[i].b);
        fscanf(gp, "%s\n", &nums[i].res);
    }

    for (int i = 0; i < 10000; ++i) {
        BigInt* b1 = bi_new_from_string(nums[i].a);
        BigInt* b2 = bi_new_from_string(nums[i].b);
        BigInt* b3 = bi_multiply(b1, b2);
        char* res = bi_convert_to_string(b3);
        reverseString(res);

        int result = strcmp(res, nums[i].res);
        printf(result ? "!!! WRONG !!!\n" : "[OK]\n");

        // assert(result == 0);
        if (result != 0) {
            BigInt* c = bi_convert_to_big_int(res);
            printf("\nLINE no. %d\n", i + 1);
            printf("========== BIG INT ==========\n");
            bi_print(b1);
            bi_print(b2);
            bi_print(c);

            printf("========== FILE ==========\n");
            printf("a = %s\n", nums[i].a);
            printf("b = %s\n", nums[i].b);
            printf("res = %s\n", nums[i].res);

            bi_free(c);
            break;
        }

        free(res);
        bi_free(b1);
        bi_free(b2);
        bi_free(b3);
    }

    fclose(fp);
    fclose(gp);

    return 0;
}