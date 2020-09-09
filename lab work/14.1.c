#include "stdio.h"    

int main()
{
    char s[100];
    printf("Enter your fullname: ");
    scanf("%[^\n]", s);
    printf("Welcome %s\n", s);
    return 0;
}