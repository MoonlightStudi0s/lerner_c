#include <stdio.h>

int a;

void main(){
    scanf("%d", &a);
    if(a%2 == 0 && a%3 == 0){
        printf("%d\n%d", a / 2, a / 3);
    }
    else{
        printf("Error");
    }
}