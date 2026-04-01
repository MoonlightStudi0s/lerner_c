#include <stdio.h>


int a;

void main(){
    scanf("%d", &a);
    int count = 0;
    for(int i=1; i<=a; i++){
        if(a%2==0){
            count++;
        }
    }
    printf("%d", count);
}