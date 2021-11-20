#include "stdio.h"
#include "math.h"

void update(int *a,int *b) {
    // Complete this function
    int t=(*a);
    (*a)+=(*b);
    (*b)=fabs((*b)-t);
}

void swap(int *x, int *y) {
    // Complete this function
    int t=(*x);
    (*x)=(*y);
    (*y)=t;
}

int main() 
{
    int a, b;
    a = 3;
    b = 5;
    printf("Before: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After: a = %d, b = %d\n", a, b);

    return 0;
}