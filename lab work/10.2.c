/*
2nd largest number
*/
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main()
{
    int a[10];
    int i, big1=-51, big2=-51;
    srand(time(0));

    for(i=0;i<10;i++)
    {
        a[i] = rand() % 100 - 49;
        printf("%d ", a[i]);
    }
    puts("");

    for(i=0; i<10;i++)
    {
        if(a[i]>big1)
        {
            big2 = big1;
            big1 = a[i];
        }
        else if(a[i]>big2)
        {
            big2=a[i];
        }
    }

    printf("1st lagest is %d\n2nd largest is %d\n", big1, big2);
    return 0;
}