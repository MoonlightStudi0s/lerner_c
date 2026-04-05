#include <stdio.h>

void main() {
    FILE *f = fopen("task2.txt", "w");
    putc('A', f);
    putc('B', f);
    putc('C', f);
    putc('\n', f);
    fclose(f);

    f = fopen("task2.txt", "r");
    int ch;
    while ((ch = getc(f)) != EOF) {
        putchar(ch);
    }
    fclose(f);
}
