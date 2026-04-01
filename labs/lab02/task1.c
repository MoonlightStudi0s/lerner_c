#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float average;
};

void main() {
    struct Student s1;
    struct Student s2;

    strcpy(s1.name, "Vasya");
    s1.age = 20;
    s1.average = 4.5;

    printf("Student 1: %s, %d, %.2f\n", s1.name, s1.age, s1.average);

    printf("Enter name: ");
    scanf("%s", s2.name);
    printf("Enter age: ");
    scanf("%d", &s2.age);
    printf("Enter average: ");
    scanf("%f", &s2.average);

    printf("Student 2: %s, %d, %.2f\n", s2.name, s2.age, s2.average);
}