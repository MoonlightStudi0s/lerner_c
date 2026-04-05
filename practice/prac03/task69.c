#include <stdio.h>

int a;

int factorial(int number);
int isittrue(int number);

void main(){
    scanf("%d", &a);
    for(int i = 1; i<=a; i++){
        if(isittrue(i) != 0){
            printf("%d\n", isittrue(i));
        }
    }
}


int factorial(int number){
    int itog = 1;
    for(int i = 2; i<=number; i++){
        itog *= i; 
    }
    return itog;
}

int isittrue(int number){
    int num = number;
    int sum = 0;
    while (number>0)
    {
        int digit = number%10;
        sum += factorial(digit);
        number /= 10;
    }
    return (sum == num) ? num : 0;
}