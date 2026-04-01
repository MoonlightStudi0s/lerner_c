#include <stdio.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Person {
    char name[50];
    struct Date birth;
};

void main() {
    struct Person p1;
    struct Person p2;

    strcpy(p1.name, "John");
    p1.birth.day = 15;
    p1.birth.month = 5;
    p1.birth.year = 1995;

    strcpy(p2.name, "Jane");
    p2.birth.day = 22;
    p2.birth.month = 8;
    p2.birth.year = 2003;

    if (p1.birth.year > 2000) printf("%s born after 2000\n", p1.name);
    if (p2.birth.year > 2000) printf("%s born after 2000\n", p2.name);
}