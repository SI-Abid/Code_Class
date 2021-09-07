#include<stdio.h>
int main()
{
    int ar[100];
    int i=0;
    while(scanf("%d",&ar[i++])==1);
    
    int max1,max2,max3;
    max1=max2=max3=1<<31;

    for (int in = 0; in < i; in++)
    {
        if (ar[in]>max1)
        {
            max3=max2;
            max2=max1;
            max1=ar[in];
        }
        else if(ar[in]>max2)
        {
            max3=max2;
            max2=ar[in];
        }
        else if(ar[in]>max3)
        {
            max3=ar[in];
        }
    }
    
    printf("%d %d %d\n",max1,max2,max3);

    return 0;
}