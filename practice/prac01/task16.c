#include <stdio.h>
#include <math.h>


int x;

void main(){
    scanf("%d", &x);
    if(x>0){
        printf("%.f", pow(x, 2));
    }
    else if (x==0)
    {
        printf("0");
    }
    else if (x<0)
    {
        printf("%d", x * -1);
    }
}