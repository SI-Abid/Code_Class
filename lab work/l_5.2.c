/*
Write a program to sort an array of 20 integers using the Bubble Sort algorithm.
*/
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void bubbleSort(int []);

int main()
{
    srand(time(0));
    int a[20];
    puts("Original array is:");
    for(int i=0; i<20; i++)
    {
        a[i] = rand()%100;
        printf("%d ", a[i]);
    }    

    bubbleSort(a);

    puts("\n\nSorted array is:");
    for(int i=0; i<20; i++)
    {
        printf("%d ", a[i]);
    }
    puts("");
    
    return 0;
}

void bubbleSort(int x[])
{
    for(int i=0; i<19; i++)
    {
        for(int j=0; j<20-i-1; j++)
        {
            if(x[j]>x[j+1])
            {
                int tmp = x[j];
                x[j] = x[j+1];
                x[j+1] = tmp;
            }
        }
    }
}