/*
find the second largest number
*/
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the amount of number:");
    scanf("%d", &n);
    int arr[n];
    printf("Input %d non-negative numbers\n", n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int big1=-1, big2=-1;
    for(int i=0; i<n; i++)
    {
        if(arr[i]>big1)
        {
            big2 = big1;
            big1 = arr[i];
        }
        else if(arr[i]>big2)
        {
            big2=arr[i];
        }
    }
    printf("Second largest number is %d\n", big2);
    return 0;
}