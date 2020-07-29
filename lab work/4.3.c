//reverse the given number
#include <stdio.h>
int main()
{
    int num, rev=0, zero=0;
    printf("Enter a number: ");         // take input
    scanf("%d", &num);
    // while(num%10==0)                    //count the tailing zeros
    // {
    //     zero++;
    //     num/=10;
    // }
    while(num)                          //reverse the rest of the number
    {
        rev*=10;                        //left-shift digits of rev 
        rev+=num%10;                    //add last digit of num to rev
        num/=10;                        //delete last digit of num
    }
    printf("The reverse number is: ");
    // while(zero--)                       //print the zeros
    //     printf("0");
    
    printf("%d\n", rev);                //print the non-zero part
    return 0;
}