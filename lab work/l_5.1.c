/*
Write a program that will read the marks of 40 students in an array and determine the
frequency of grades. The marks will be in the range [25, 99].
*/
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main()
{
    srand(time(0));
    int a[40], grade[10] = {0};
    char ch[10][2] = {"A+", "A ", "A-", "B+", "B ", "B-", "C+", "C ", "D ", "F "};

    puts("The marks are:");
    for(int i=0; i<40; i++)
    {
        a[i] = rand() % 75 + 25;
        printf("%d\t", a[i]);
        if((i+1)%8==0)
            puts("");

        if(a[i]>=80)
            grade[0]++;
        else if(a[i]>=75 && a[i]<=79)
            grade[1]++;
        else if(a[i]>=70 && a[i]<=74)
            grade[2]++;
        else if(a[i]>=65 && a[i]<=69)
            grade[3]++;
        else if(a[i]>=60 && a[i]<=64)
            grade[4]++;
        else if(a[i]>=55 && a[i]<=59)
            grade[5]++;
        else if(a[i]>=50 && a[i]<=54)
            grade[6]++;
        else if(a[i]>=45 && a[i]<=49)
            grade[7]++;
        else if(a[i]>=40 && a[i]<=44)
            grade[8]++;
        else
            grade[9]++;    
    }
    puts("");
    puts("GRADE\tFREQUENCY");
    puts("=====\t=========");
    
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<2; j++)
        {
            printf("%c", ch[i][j]);
        }
        printf("\t%d\n", grade[i]);
    }

    return 0;
}