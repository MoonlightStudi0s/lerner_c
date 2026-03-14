#include <stdio.h>

int a;

void main(){
    scanf("%d", &a);
    if(a>=90 && a<=100){
        printf("Отлично");
    }
    else if(a>=75 && a<=89){
        printf("Хорошо");
    }
    else if(a>=60 && a<=74){
        printf("Удовлетворительно");
    }
    else if (a<60)
    {
        printf("Неудовлетворительно");
    }
}