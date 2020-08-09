/*
sort an array
*/
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int *getRandomArray()
{
    srand(time(0));
    static int a[10];
    for(int i=0; i<10; i++)
    {
        a[i]=rand()%100;
    }
    return a;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int *arr;
    //get a randomly generated array
    arr = getRandomArray();
    printf("Random Array:");
    for(int i=0;i<10;i++)
    {
        printf(" %2d",arr[i]);
    }
    puts("");
    //Sort the array
    for(int i=0; i<10; i++)
    {
        for(int j=0;j<9-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
    //print the array   
    printf("Sorted Array:");
    for(int i=0;i<10;i++)
    {
        printf(" %2d",arr[i]);
    }
    puts("");
    return 0;
}