#include <stdio.h>

int a = 10;
float b = 3.14;
char c = 'A';

void main(){
    printf("a = %d, address = 0x%p\n b = %f, address = 0x%p\n c = %c, address = 0x%p", a, &a, b, &b, c, &c);
    return;
}