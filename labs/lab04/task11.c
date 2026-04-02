#include <stdio.h>

void main() {
    FILE *f = fopen("task11.txt", "w");
    fprintf(f, "Короткий текст");
    fclose(f);

    f = fopen("task11.txt", "r");
    int ch;
    while (1) {
        ch = getc(f);
        if (feof(f)) {
            printf("\nДошли до конца, красава\n");
            break;
        }
        if (ferror(f)) {
            printf("Ошибка при чтении, блин\n");
            break;
        }
        putchar(ch);
    }
    fclose(f);
}
