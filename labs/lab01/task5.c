#include <stdio.h>

int a = 5;


void main(){
    int a = 5;
    printf("a++: %d\n a: %d\n\n", a++, a);
    a = 5;
    printf("++a: %d\n a: %d\n\n", ++a, a);
    a = 5;
    printf("a--: %d\n a: %d\n\n", a--, a);
    a = 5;
    printf("--a: %d\n a: %d", --a, a);
    return;
}