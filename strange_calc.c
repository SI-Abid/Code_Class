#include "stdio.h"
#include "string.h"

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int a, b;
        char* s;
        scanf("%d %s %d", &a, s, &b);
        
        if(!strcmp(s,"ADD\0"))
        {
            printf("%d", a+b);
        }
        else if(!strcmp(s, "SUB\0"))
        {
            printf("%d", a-b);
        }
        else if(!strcmp(s, "MUL\0"))
        {
            printf("%d", a*b);
        }
        else if(!strcmp(s, "DIV\0"))
        {
            printf("%d", a/b);
        }
        else if(!strcmp(s, "OR\0"))
        {
            printf("%d", a|b);
        }
        else if(!strcmp(s, "AND\0"))
        {
            printf("%d", a&b);
        }
        else if(!strcmp(s, "XOR\0"))
        {
            printf("%d", a^b);
        }
        puts("");
    }
    return 0;
}