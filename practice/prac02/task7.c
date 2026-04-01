#include <stdio.h>
#include <math.h>

int a;

void main(){
    scanf("%d", &a);
    for(int i = 0; i<=a; i++){
        int b = pow(2, i);
        if(b>50){
            printf("%d;\t", b);
        }
    }
}