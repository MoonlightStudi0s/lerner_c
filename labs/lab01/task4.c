#include <stdio.h>

int num1;
int num2;

void main(){
    scanf("%d %d", &num1, &num2);
    printf("%d %% %d = %d", num1, num2, num1 % num2);
    return;
}