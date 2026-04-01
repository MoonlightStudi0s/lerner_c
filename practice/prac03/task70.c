#include <stdio.h>

int a,b;

int nod(int a, int b);

void main(){
    scanf("%d %d", &a, &b);
    for(int i = 1; i<=a; i++){
        if(nod(i,b)==1){
            printf("%d\t", i);
        }
    }
}



int nod(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}