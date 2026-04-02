#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
};

void main() {
    struct Person p1 = {"Kolyan", 25};

    FILE *f = fopen("task7.bin", "wb");
    fwrite(&p1, sizeof(struct Person), 1, f);
    fclose(f);

    struct Person p2;
    f = fopen("task7.bin", "rb");
    fread(&p2, sizeof(struct Person), 1, f);
    fclose(f);

    printf("Имя: %s, Возраст: %d\n", p2.name, p2.age);
}
