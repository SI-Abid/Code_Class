/*
take 2 number as a b and print their
sum, difference, product and quotient
*/
#include "stdio.h"
int main()
{
    int a, b, d;
    
    printf("Enter 1st number: ");
    scanf("%d",&a);
    
    printf("Enter 2nd number: ");
    scanf("%d",&b);
    
    printf("Sum: %d\n", a+b);
    printf("Product: %d\n", a*b);
    
    d=a-b;
    if(d<0) d=-d;

    printf("Difference: %d\n", d);
    printf("Quotient: %d\n", a/b);
    
    return 0;
}