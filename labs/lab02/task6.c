#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

struct Mixed {
    union Data value;
    int type; // 0=int, 1=float, 2=char
};

void main() {
    union Data u;
    u.i = 42;
    printf("As int: %d\n", u.i);
    printf("As float (garbage): %f\n", u.f);

    u.f = 3.14;
    printf("As float: %f\n", u.f);
    printf("As int (garbage): %d\n", u.i);

    struct Mixed m;
    m.value.i = 100;
    m.type = 0;
    if (m.type == 0) printf("Stored int: %d\n", m.value.i);
}