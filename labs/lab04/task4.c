#include <stdio.h>

void main() {
    FILE *f = fopen("task4.txt", "w");
    fprintf(f, "%s %d %.2f\n", "Vasya", 20, 4.5);
    fprintf(f, "%s %d %.2f\n", "Petya", 19, 3.8);
    fclose(f);

    f = fopen("task4.txt", "r");
    char name[50];
    int age;
    float avg;
    while (fscanf(f, "%s %d %f", name, &age, &avg) == 3) {
        printf("name=%s age=%d avg=%.2f\n", name, age, avg);
    }
    fclose(f);
}
