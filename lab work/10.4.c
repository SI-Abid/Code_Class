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
void bubbleSort(int arr[])
{
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
    printf("Sorted Array:");
    for(int i=0;i<10;i++)
    {
        printf(" %2d",arr[i]);
    }
    puts("");
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
    bubbleSort(arr);
    //print the array   
    return 0;
}