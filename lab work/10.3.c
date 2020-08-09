/*
find the most frequent element in an array
*/
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main()
{
    srand(time(0));
    int a[50], freq[11]={0};
    int i;
    for(i=0;i<50;i++)
    {
        a[i] = rand() % 10;
        freq[a[i]]++;
        printf("%d ", a[i]);
    }
    puts("");

    puts("Element  Frequency");
    puts("==================");
    for(i=0;i<10;i++)
    {
        printf("%d\t %d\n",i, freq[i]);
    }
    int high = 0;
    for(i=0;i<10;i++)
    {
        if(freq[i]>freq[high])
        {
            high = i;
        }   
    }
    printf("Most frequent element is %d\n", high);
    return 0;
}