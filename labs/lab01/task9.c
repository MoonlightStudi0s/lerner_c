#include <stdio.h>
#include <math.h>

int x;

void main(){
    scanf("%d", &x);
    float a = (pow(x, 2)) + (2*x) + 1;
    printf("%.2f\n", a);

    float b = pow((x + 1), 2) - pow((x - 1), 2);
    printf("%.2f\n", b);
}