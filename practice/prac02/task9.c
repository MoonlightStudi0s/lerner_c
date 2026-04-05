#include <stdio.h>

int a;

void main(){
    scanf("%d", &a);
    for(int i=0; i<=a;  i++){
        if(i%4!=0){
            printf("%d;\t", i);
        }
    }
}