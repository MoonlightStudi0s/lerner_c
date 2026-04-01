#include <stdio.h>

int a;

void main(){
    scanf("%d", &a);
    for(int i=1; i<=a; i++){
        if(i%2 == 1){
            printf("%d ", i);
        }
    }
}