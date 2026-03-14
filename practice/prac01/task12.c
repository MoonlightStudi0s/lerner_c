#include <stdio.h>

int a,b,c;


void main(){
    scanf("%d %d %d", &a, &b, &c);
    if(a>b && a>c){
        printf("A(%d) - max\n", a);
    }
    else if (b>a && b>c)
    {
        printf("B(%d) - max\n", b);
    }
    else if (c>a && c>b)
    {
        printf("C(%d) - max", c);
    }
}