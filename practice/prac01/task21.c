#include <stdio.h>
#include <ctype.h>

char a;

void main(){
    scanf("%c", &a);
    if(isdigit(a)){
        printf("%c - цифра", a);
    }
    else if (isalpha(a))
    {
        printf("%c - буква", a);
    }
    else{
        printf("%c - другой символ", a);
    }
}