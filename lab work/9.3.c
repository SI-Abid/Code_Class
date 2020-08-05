/*
find the largest number from an array - random number generated
*/
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define INF -2147483648
int main()
{
    srand(time(0));
    int ar[10];
    int i;
    printf("The array is :");
    for(i=0;i<10;i++)
    {
        ar[i]=rand()%100;
        printf(" %d",ar[i]);
    }
    int mx=INF;

    for(i=0;i<10;i++)
    {
        if(mx<ar[i])
            mx=ar[i];
    }
    printf("\nLargest number is %d\n", mx);
    return 0;
}