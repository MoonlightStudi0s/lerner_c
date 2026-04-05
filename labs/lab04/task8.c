#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
};

void main() {
    struct Person arr[] = {
        {"Masha", 18},
        {"Dasha", 22},
        {"Sasha", 30}
    };
    int size = 3;

    FILE *f = fopen("task8.bin", "wb");
    fwrite(arr, sizeof(struct Person), size, f);
    fclose(f);

    struct Person new_arr[3];
    f = fopen("task8.bin", "rb");
    fread(new_arr, sizeof(struct Person), size, f);
    fclose(f);

    for (int i = 0; i < size; i++) {
        printf("%s - %d лет\n", new_arr[i].name, new_arr[i].age);
    }
}
