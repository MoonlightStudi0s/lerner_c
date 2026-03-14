#include <stdio.h>

int a,b,c;

void main(){
    scanf("%d %d %d", &a,&b,&c);
    int d = a + b + c;
    printf("%.2f", (float)d / 3);
}