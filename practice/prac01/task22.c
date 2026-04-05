#include <stdio.h>

float a;

void main(){
    scanf("%f", &a);
    printf("%.2fF\n", (float)(a * (9/5) + 32));
    printf("%.2fK", (float)(a + 273));
}