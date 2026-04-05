#include <stdio.h>

int a;

void main(){
    scanf("%d", &a);
    
    int seconds = a % 60;
    int minutes = (a % 3600) / 60;
    int hours = a / 3600;
    printf("%02d:%02d:%02d\n", hours, minutes, seconds);
}