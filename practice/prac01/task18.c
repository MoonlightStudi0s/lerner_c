#include <stdio.h>

int a;

void main(){
    scanf("%d", &a);
    printf("%d", a + __INT_MAX__);
}