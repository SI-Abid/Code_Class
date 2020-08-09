/*
Write a program that will declare a 10-element integer array. Fill the array with integers
taken from the user and show the sum of the integers.
*/
#include "stdio.h"

int main()
{
    int a[10], sum=0;
    for(int i=0; i<10; i++)
    {
        printf("Enter a[ %d ]: ", i);
        scanf("%d", &a[i]);
        sum+=a[i];
    }

    printf("The sum is: %d\n", sum);
    return 0;
}