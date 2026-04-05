#include <stdio.h>

int a;

void main(){
    int b = 1;
    scanf("%d", &a);
    for(int i=0; i<=a; i++){
        if(i%3==0){
            b = b * i;
        }
    }
    printf("%d", b);
}