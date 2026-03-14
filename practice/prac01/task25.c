#include <stdio.h>

float a,b;
char c;

void main(){
    printf("Введите два числа: ");
    scanf("%f %f", &a, &b);
    printf("Введите операцию: ");
    scanf("%c", &c);
    switch (c)
    {
    case '+':
        printf("%f", a + b);
        break;
    
    case '-':
        printf("%f", a - b);
        break;

    case '*':
        printf("%f", a * b);
        break;

    case '/':
        printf("%f", a / b);
        break;

    default:
        break;
    }
}