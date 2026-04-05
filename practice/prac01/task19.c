#include <stdio.h>

int a;

void main(){
    scanf("%d", &a);
    for (size_t i = 1; i <= 10; i++)
    {
        printf("%d\n", a * i);
    }   
}