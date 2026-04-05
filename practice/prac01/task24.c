#include <stdio.h>

int a,b,c;

void main(){
    scanf("%d %d %d", &a, &b, &c);
    printf("%.1f", (float)(((a+b)*c)/2));
}