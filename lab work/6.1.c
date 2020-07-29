#include "stdio.h"
#define ll long long
// mini calculator
int main()
{
    int a, b, ans;
    char c;
    printf("Enter two number with an operator between them.\tE.G: 5+6\n\t>");
    scanf("%d %c %d", &a, &c, &b);

    switch (c)
    {
        case '+':   ans=a+b;   
                    printf("%d\n",ans);
                    break;

        case '-':   ans=a-b;   
                    printf("%d\n",ans);
                    break;

        case '*':   ans=a*b;
                    printf("%d\n",ans);
                    break;

        case '/':   ans=a/b;
                    printf("%d\n",ans);
                    break;

        default:    printf("Unable to calculate\n");
                    break;
    }
    
    return 0;
}