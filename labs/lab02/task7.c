#include <stdio.h>
#include <string.h>

enum Course { FIRST = 1, SECOND, THIRD, FOURTH };

struct Student {
    char name[50];
    int age;
    enum Course course;
    float average;
};

struct Student group[100];
int count = 0;

void add(char *name, int age, enum Course course, float avg) {
    strcpy(group[count].name, name);
    group[count].age = age;
    group[count].course = course;
    group[count].average = avg;
    count++;
}

void print_all() {
    for (int i = 0; i < count; i++) {
        printf("%s | age %d | course %d | avg %.2f\n",
               group[i].name, group[i].age, group[i].course, group[i].average);
    }
}

void search_by_name(char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(group[i].name, name) == 0) {
            printf("Found: %s, age %d\n", group[i].name, group[i].age);
            return;
        }
    }
    printf("Not found\n");
}

void sort_by_avg() {
    struct Student temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (group[i].average < group[j].average) {
                temp = group[i];
                group[i] = group[j];
                group[j] = temp;
            }
        }
    }
}

void main() {
    add("Alice", 20, SECOND, 4.7);
    add("Bob", 21, THIRD, 3.8);
    add("Charlie", 19, FIRST, 4.9);

    printf("Before sort:\n");
    print_all();

    sort_by_avg();

    printf("\nAfter sort (by avg):\n");
    print_all();

    printf("\nSearch for Bob:\n");
    search_by_name("Bob");
}