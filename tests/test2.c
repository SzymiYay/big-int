#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *file;
    file = fopen("numbers.txt", "r");
    char singleLine[150];

    while (!feof(file)) {
        fgets(singleLine);
        puts(singleLine);
    }

    fclose(file);

    return 0;
}