#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float average;
};

void main() {
    struct Student group[5];
    int i, max_index = 0;

    strcpy(group[0].name, "Anna");
    group[0].age = 19;
    group[0].average = 4.8;

    strcpy(group[1].name, "Bob");
    group[1].age = 21;
    group[1].average = 3.9;

    strcpy(group[2].name, "Cid");
    group[2].age = 20;
    group[2].average = 4.2;

    strcpy(group[3].name, "Dan");
    group[3].age = 22;
    group[3].average = 5.0;

    strcpy(group[4].name, "Eva");
    group[4].age = 18;
    group[4].average = 4.0;

    for (i = 0; i < 5; i++) {
        printf("%s | %d | %.2f\n", group[i].name, group[i].age, group[i].average);
        if (group[i].average > group[max_index].average) max_index = i;
    }

    printf("Top student: %s with %.2f\n", group[max_index].name, group[max_index].average);
}