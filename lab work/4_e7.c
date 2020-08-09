/*
given the value of a,b,c of a quadric equation ax^2+bx+c=0
determine x1 and x2
formula: x= (-b+-root(b*b-4ac))/2a
*/
#include "stdio.h"
#include "math.h"

int main()
{
    int a, b, c, d;
    double r, i, r2;
    printf("\t\tEquation Solver V1.1\n");
    printf("\t\t====================\n\n\n");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("c: ");
    scanf("%d", &c);
    printf("\n\n");

    if(a==0)
    {
        puts("Given equation is linear");
        return 0;
    }

    //equation format maker
    printf("Equation: ");
    if(a<0)     printf("- %d", -a);
    else        printf("%d", a);

    printf("x^2 ");

    if(b<0)     printf("- %d", -b);
    else        printf("+ %d", b);

    printf("x ");

    if(c<0)     printf("- %d", -c);
    else        printf("+ %d ",c);

    printf(" = 0\n\n\n");

    //result
    printf("Solution:\n");
    d = b*b-(4*a*c);
    r = 0.5*(-b)/a;
    if(d<0)
    {
        i = sqrt(-d)/(2*a); 
        printf("x1 = %0.2lf + %0.2lfi\n", r, i);
        printf("x2 = %0.2lf - %0.2lfi\n", r, i);
    }
    else
    {
        r2 = sqrt(d)/(2*a);
        printf("x1 = %0.2lf\n", r+r2);
        printf("x2 = %0.2lf\n", r-r2);
    }
    printf("\n");
    return 0;
}
