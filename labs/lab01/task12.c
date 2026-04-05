#include <stdio.h>

int a;

void main(){
    scanf("%d", &a);
    printf("сотни: %d\n", a / 100);
    printf("десятки: %d\n", (a / 10) % 10);
    printf("единицы: %d", a % 10);
    return;
}