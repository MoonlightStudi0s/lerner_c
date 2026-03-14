#include <stdio.h>

int a;

void main(){
    scanf("%d", &a);
    if(a%2==0 && a%3==0 && a%5==0){
        printf("Делится");
    }
    else{
        printf("Error");
    }
}