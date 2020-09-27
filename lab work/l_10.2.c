#include "stdio.h"

int main()
{
    short int a, mask=0x8000;
    printf("Enter a number: ");
    scanf("%hd", &a);
    puts((a&mask)?"Negative":"Positive");
    return 0;
}