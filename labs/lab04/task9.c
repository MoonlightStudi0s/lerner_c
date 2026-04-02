#include <stdio.h>

void main() {
    FILE *f = fopen("task9.txt", "w");
    fprintf(f, "0123456789ABCDEF");
    fclose(f);

    f = fopen("task9.txt", "r");
    fseek(f, 5, SEEK_SET);
    int ch;
    while ((ch = getc(f)) != EOF) {
        putchar(ch);
    }
    fclose(f);
    printf("\n");
}
