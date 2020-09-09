#include "stdio.h"

int isnum(char x)
{
    if(x>='0' && x<='9') 
        return 1;
    else
        return 0;
}
char c[10000000];
int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while(t--)
    {
        int cnt=1;
        
        scanf("%[^\n]", c);
        getchar();
        for(int i=1; c[i]; i++)
        {
            if(isnum(c[i-1]) && c[i]==' ')
                cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}