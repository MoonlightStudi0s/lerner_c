#include <stdio.h>

int a,b,c;

void main(){
    scanf("%d %d %d", &a, &b, &c);
    if(a+b==c){
        printf("Equal");
    }
    else{
        printf("Not equal");
    }
}