#include <stdio.h>

void main() {
    FILE *f = fopen("task3.txt", "w");
    fputs("Первая строка\n", f);
    fputs("Вторая строка, да\n", f);
    fputs("Третья и последняя\n", f);
    fclose(f);

    f = fopen("task3.txt", "r");
    char buf[100];
    while (fgets(buf, 100, f) != NULL) {
        printf("%s", buf);
    }
    fclose(f);
}
