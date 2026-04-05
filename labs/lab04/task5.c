#include <stdio.h>

void main() {
    char buf[200];
    printf("Напиши что-нибудь: ");
    fgets(buf, 200, stdin);

    FILE *f = fopen("task5.txt", "w");
    fputs(buf, f);
    fclose(f);

    f = fopen("task5.txt", "r");
    while (fgets(buf, 200, f) != NULL) {
        printf("В файле лежит: %s", buf);
    }
    fclose(f);
}
