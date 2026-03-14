#include <stdio.h>

int a;

void main(){
    scanf("%d", &a);
    printf("%d\n", a & 1);
    printf("%d\n", a | 1);
    printf("%d\n", a ^ 1);
    printf("%d", ~a);
}