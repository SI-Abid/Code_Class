#include "stdio.h"

char swapCase(char);

int main()
{
    char s[100];
    printf("Enter a string: ");
    scanf("%[^\n]", s);
    s[0] = swapCase(s[0]);
    for(int i=1; s[i]; i++)
    {
        if(s[i]==' ')
            s[i+1]=swapCase(s[i+1]);
    }
    puts(s);
}

char swapCase(char x)
{
    return x^1<<5;
}