#include <stdio.h>

int a,b,c;

void main(){
    printf("a: 0x%p\nb: 0x%p\nc: 0x%p\n", &a, &b, &c);
    printf("a-b: %lg\na-c: %lg\nb-a: %lg\nb-c: %lg\nc-a: %lg\nc-b: %lg", (long)(&a-&b), (long)(&a-&c), (long)(&b-&a), (long)(&b-&c), (long)(&c-&a), (long)(&c-&b));
}