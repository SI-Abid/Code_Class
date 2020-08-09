/*
reverse an array
*/
#include "stdio.h"

int main()
{
    int arr[]={10,20,30,40,50,60};
    int len = sizeof(arr) / sizeof(arr[0]);
    int t;
    for(int i=0;i<len/2;i++)
    {
        t = arr[i];
        arr[i] = arr[len-i-1];
        arr[len-i-1] = t;
    }
    for(int i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    puts("");
    return 0;
}