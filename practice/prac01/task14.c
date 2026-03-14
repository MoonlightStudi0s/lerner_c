#include <stdio.h>

int a;

void main(){
    scanf("%d", &a);
    switch (a)
    {
    case 1:
        printf("Понедельник");
        break;
    
    case 2:
        printf("Вторник");
        break;
    
    case 3:
        printf("Среда");
        break;

    case 4:
        printf("Четверг");
        break;

    case 5:
        printf("Пятница");
        break;

    case 6:
        printf("Суббота");
        break;

    case 7:
        printf("Воскресенье");
        break;
    
    default:
        break;
    }
}