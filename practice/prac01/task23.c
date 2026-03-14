#include <stdio.h>

int a,b;

void main(){
    scanf("%d %d", &a, &b);
    if(a>b){
        printf("a>b");
    }
    else if(a<b){
        printf("a<b");
    }
    else if(a==b){
        printf("a=b");
    }
}