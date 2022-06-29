#ifndef BIG_INT_H_
#define BIG_INT_H_

#include <stdint.h>

typedef struct {
    size_t size;
    uint8_t* data;
    bool is_negative;
} BigInt;

/* =============== Creating and freeing ===============*/
BigInt* bi_new_from_string(char const * str);
BigInt* bi_new_with_size(size_t size);
BigInt* bi_new_from_big_int(BigInt const *a);
void bi_free(BigInt* a);

/* =============== Helpers ===============*/
void bi_print(BigInt const *a);
void bi_info(BigInt const *a);
int bi_cmp(void const *a, void const *b);
void reverseString(char* str); // ANSI C

/* =============== Converting ===============*/
char* bi_convert_to_string(BigInt const *a);
BigInt* bi_convert_to_big_int(char* str);

/* =============== Arithmetic operations ===============*/
BigInt* bi_add(BigInt *a, BigInt *b);
BigInt* bi_subtract(BigInt *a, BigInt *b);
BigInt* bi_multiply(BigInt const *a, BigInt const *b);
BigInt* bi_divide(BigInt const *a, BigInt const *b);



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