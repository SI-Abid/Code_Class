#include "stdio.h"

int main()
{
    int d;
    printf("Enter a number: ");
    scanf("%d", &d);
    puts((d&1) ? "Odd" : "Even");
    return 0;
}