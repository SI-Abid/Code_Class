// sum of digits

#include<stdio.h>

int main()
{
    int num, sum=0, digit;
    printf("Enter a number: ");
    scanf("%d",&num);
    while(num>0)
    {
        digit = num % 10;      //
        sum += digit;
        num /= 10;              // 123 --> 12
    }
    printf("Sum of digit: %d\n", sum);
    return 0;
}
/*
12345 ==> 15
 1 + 2 + 3 + 4 + 5 = 15
*/