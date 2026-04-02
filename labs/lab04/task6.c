#include <stdio.h>

void main() {
    int arr[] = {10, 20, 30, 40, 666};
    int size = 5;

    FILE *f = fopen("task6.bin", "wb");
    fwrite(arr, sizeof(int), size, f);
    fclose(f);

    int new_arr[5];
    f = fopen("task6.bin", "rb");
    fread(new_arr, sizeof(int), size, f);
    fclose(f);

    for (int i = 0; i < size; i++) {
        printf("%d ", new_arr[i]);
    }
    printf("\n");
}
