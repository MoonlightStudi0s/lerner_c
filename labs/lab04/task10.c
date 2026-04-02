#include <stdio.h>

void main() {
    FILE *f = fopen("task10.txt", "w");
    fprintf(f, "Hello World! This file has some content.");
    fclose(f);

    f = fopen("task10.txt", "rb");
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fclose(f);

    printf("Размер файла: %ld байт\n", size);
}
