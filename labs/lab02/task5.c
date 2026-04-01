#include <stdio.h>

enum Day { MON, TUE, WED, THU, FRI, SAT, SUN };

struct Event {
    char name[30];
    enum Day weekday;
};

void main() {
    enum Day today = WED;
    struct Event e = {"Meeting", FRI};

    switch (today) {
        case MON: printf("It's Monday\n"); break;
        case TUE: printf("It's Tuesday\n"); break;
        case WED: printf("It's Wednesday\n"); break;
        case THU: printf("It's Thursday\n"); break;
        case FRI: printf("It's Friday\n"); break;
        case SAT: printf("It's Saturday\n"); break;
        case SUN: printf("It's Sunday\n"); break;
    }

    printf("Event: %s on day %d\n", e.name, e.weekday);
}