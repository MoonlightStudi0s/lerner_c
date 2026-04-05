#include <stdio.h>

int a;

void main(){
    scanf("%d", &a);
    int sum = 0;
    for(int i=1; i<=a; i++){
        if(i%2==1){
            sum = sum + i;
        }
    }
    printf("%d", sum);
}