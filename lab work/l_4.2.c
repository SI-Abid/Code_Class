/*
Write a program that will declare a 10-element integer array. The array will be filled up by
random integers in the range [0, 100]. Use the library functions rand() and srand()
defined in stdlib.h to perform the task. After that, determine the maximum element,
minimum element and the average of the numbers.
*/
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main()
{
    srand(time(0));

    int i, mini=99, maxi=0, a[10], sum=0;
    puts("The array is:");
    for(i=0; i<10; i++)
    {
        a[i] = rand()%100;
        sum+=a[i];
        printf("%2d ", a[i]);
    }
    puts("");
    for(i=0; i<10; i++)
    {
        if(a[i]>maxi)
        {
            maxi = a[i];
        }
        if(a[i]<mini);
        {
            mini = a[i];
        }
    }
    printf("Maximum: %d\n", maxi);
    printf("Minimum: %d\n", mini);
    printf("Average: %0.2lf\n", sum/10.0);
    return 0;
}