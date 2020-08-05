/*
Write a program to find the sum and average of 10 numbers
*/
#include "stdio.h"
#include "stdlib.h"
int main()
{
    int ar[10];
    int i;
    for(i=0;i<10;i++)
    {
        ar[i]= rand()%100;
    }
    int sum=0;
    for(i=0;i<10;i++)
    {
        sum+=ar[i];
    }
    double avg = sum/10.0;
    
    printf("Sum is %d\nAverage is %0.2lf\n", sum, avg);
    return 0;
}