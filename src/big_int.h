#include <stdint.h>

#ifndef BIG_INT_H_
#define BIG_INT_H_

typedef struct {
    size_t size;
    uint8_t* data;
    bool isNegative;
} BigInt;

/* =============== Creating and freeing ===============*/
BigInt* newBigInt(char* str);
BigInt* newBigIntWithSize(size_t size);
void freeBigInt(BigInt* a);

/* =============== Helpers ===============*/
void printBigInt(BigInt* a);
int cmp(void* a, void* b);

/* =============== Converting ===============*/
char* convertBigIntToString(BigInt* a);
BigInt* convertStringToBigInt(char* str);

/* =============== Arithmetic operations ===============*/
BigInt* add(BigInt* a, BigInt* b);
BigInt* subtract(BigInt* a, BigInt* b);
BigInt* multiply(BigInt* a, BigInt* b);
BigInt* divide(BigInt* a, BigInt* b);


void reverseString(char* str);
int valueFromDecimal(char c);
char valueToDecimal(int num);
int convertFromAnyBaseToDecimal(int base, char* number);
char* convertFromDecimalToAnyBase(int baseTo, char* number);
char* convert(int baseFrom, int baseTo, char* number);

// char* add(char* a , char* b, int base);
// char* subtract(char* a, char* b, int base);
// char* multiply(char* a, char* b, int base);
// char* divide(char* a, char* b, int base);


// int valueFromDecimal(char c) {
//     if (c >= '0' && c <= '9') {
//         return (int)c - '0';
//     } else {
//         return (int)c - 'A' + 10;
//     }
// }

// int convertFromAnyBaseToDecimal(int base, char* number) {
//     int len = strlen(number);
//     int power = 1;
//     int res = 0;
    
//     for (int i = len - 1; i >= 0; --i) {
        
//         if (valueFromDecimal(number[i]) >= base) {
//             printf("Invalid number");
//             return -1;
//         }

//         res += valueFromDecimal(number[i]) * power;
//         power *= base;
//     }
//     return res;
// }

// char valueToDecimal(int num) {
//     if (num >= 0 && num <= 9) {
//         return (char)(num + '0');
//     } else {
//         return (char)(num - 10 + 'A');
//     }
// }

// void reverseString(char* str) {
//     int len = strlen(str);
//     for (int i = 0; i < len / 2; ++i) {
//         char temp = str[i];
//         str[i] = str[len - 1 - i];
//         str[len - 1 - i] = temp;
//     }
// }

// char* convertFromDecimalToAnyBase(int baseTo, char* number) {
//     char* res = malloc(100 * sizeof(char));
//     int index = 0;
//     int num = atoi(number);

//     while (num > 0) {
//         res[index++] = valueToDecimal(num % baseTo);
//         num /= baseTo;
//     }
//     res[index] = '\0';

//     reverseString(res);

//     return res;
// }

// char* convert(int baseFrom, int baseTo, char* number) {
//     int num;
//     if (baseFrom != 10) {
//         num = convertFromAnyBaseToDecimal(baseFrom, number);
//     } else {
//         num = atoi(number);
//     }

//     char* res = malloc(100 * sizeof(char));
//     sprintf(res, "%d", num);

//     return convertFromDecimalToAnyBase(baseTo, res);
// }


// char* add(char* a , char* b, int base) {
//     char* res = malloc(1000 * sizeof(char));
//     if (base != 10) {
//         int a_int = convertFromAnyBaseToDecimal(base, a);
//         int b_int = convertFromAnyBaseToDecimal(base, b);
//         int result = a_int + b_int;
//         sprintf(res, "%d", result);
//         return convertFromDecimalToAnyBase(base, res);
//     } else {
//         int a_int = atoi(a);
//         int b_int = atoi(b);
//         int result = a_int + b_int;
//         sprintf(res, "%d", result);
//         return res;
//     }
// }

// char* subtract(char* a, char* b, int base) {
//     char* res = malloc(1000 * sizeof(char));
//     if (base != 10) {
//         int a_int = convertFromAnyBaseToDecimal(base, a);
//         int b_int = convertFromAnyBaseToDecimal(base, b);
//         int result = a_int - b_int;
//         sprintf(res, "%d", result);
//         return convertFromDecimalToAnyBase(base, res);
//     } else {
//         int a_int = atoi(a);
//         int b_int = atoi(b);
//         int result = a_int - b_int;
//         sprintf(res, "%d", result);
//         return res;
//     }
// }

// char* multiply(char* a, char* b, int base) {
//     char* res = malloc(1000 * sizeof(char));
//     if (base != 10) {
//         int a_int = convertFromAnyBaseToDecimal(base, a);
//         int b_int = convertFromAnyBaseToDecimal(base, b);
//         int result = a_int * b_int;
//         sprintf(res, "%d", result);
//         return convertFromDecimalToAnyBase(base, res);
//     } else {
//         int a_int = atoi(a);
//         int b_int = atoi(b);
//         int result = a_int * b_int;
//         sprintf(res, "%d", result);
//         return res;
//     }
// }

// char* divide(char* a, char* b, int base) {
//     char* res = malloc(1000 * sizeof(char));
//     if (base != 10) {
//         int a_int = convertFromAnyBaseToDecimal(base, a);
//         int b_int = convertFromAnyBaseToDecimal(base, b);

//         if (b_int == 0) {
//             return "Cannot divide by zero";
//         }

//         int result = a_int / b_int;
//         sprintf(res, "%d", result);
//         return convertFromDecimalToAnyBase(base, res);
//     } else {
//         int a_int = atoi(a);
//         int b_int = atoi(b);

//         if (b_int == 0) {
//             return "Cannot divide by zero";
//         }

//         int result = a_int / b_int;
//         sprintf(res, "%d", result);
//         return res;
//     }
// }

#endif // BIG_INT_H_