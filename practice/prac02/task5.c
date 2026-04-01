#include <stdio.h>

int a;

void main(){
    scanf("%d", &a);
    for(int i = 1; i<=a; i++){
        if(i%3 == 0){
            printf("Fizz");
        }
        else{
            printf("%d", i);
        }
    }
}