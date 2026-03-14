#include <stdio.h>

void main() {
    int a, b;

    scanf("%d %d", &a, &b);
    
    printf("Сумма: %d\n", a + b);
    printf("Разность: %d\n", a - b);
    printf("Произведение: %d\n", a * b);
    printf("Целочисленное деление: %d\n", a / b);
}