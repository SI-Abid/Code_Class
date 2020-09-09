/*
INPUT:
q
n
a[]
OUTPUT:
a[].sorted()
*/
#include <stdio.h>

void sort_ascend(int [], int);
void sort_descend(int [], int);

int main()
{
    int q, n, i;
    printf("1. Ascending order\n2. Descending order\n");
    scanf("%d", &q);
    if(q==1 || q==2)
    {
        printf("Number of item: ");
        scanf("%d", &n);
        int arr[n];
        
        printf("Enter your numbers\n");
        for(i=0; i<n; i++)
        {
            scanf("%d", &arr[i]);
        }

        if(q==1)
        {
            sort_ascend(arr, n);
        }
        else
        {
            sort_descend(arr, n);
        }

        printf("Sorted items:");
        for(i=0; i<n; i++)
        {
            printf(" %d", arr[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Wrong Option\n");
    }
    
    return 0;
}

void sort_ascend(int x[], int size)
{
    int i, j, tmp;
    for(i=0; i<size-1; i++)
    {
        for(j=0; j<size-i-1; j++)
        {
            if(x[j]>x[j+1])
            {
                tmp = x[j];
                x[j] = x[j+1];
                x[j+1] = tmp;
            }
        }
    }
}

void sort_descend(int x[], int size)
{
    int i, j, tmp;
    for(i=0; i<size-1; i++)
    {
        for(j=0; j<size-i-1; j++)
        {
            if(x[j]<x[j+1])
            {
                tmp = x[j];
                x[j] = x[j+1];
                x[j+1] = tmp;
            }
        }
    }
}