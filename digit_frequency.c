#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int isnum(char c)
{
    return (c>='0' && c<='9')?1:0;
}

int main()
{
    char s[1000];
    int num[10]={0};
    // s=malloc(1000*sizeof(char));
    scanf("%s", s);
    for(int i=0; s[i]; i++)
    {
        if(isnum(s[i]))
        {
            num[s[i]-'0']++;
        }
    }
    for(int i=0; i<10; i++)
    {
        printf("%d ", num[i]);
    }
    return 0;
}