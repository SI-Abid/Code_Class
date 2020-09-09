#include "stdio.h"
//get the length of a string
int str_len(char []);

int main()
{
    char s[100];
    printf("Enter a string: ");
    scanf("%[^\n]", s);
    printf("Your string length is: %d\n", str_len(s));
    return 0;
}

int str_len(char x[])
{
    int i=0;
    for(i=0; x[i]; i++);
    return i;
}