#include <stdio.h>
// take two number from user
// Then add those numbers
int main()
{
    int a, b;
    scanf("%d %d", &a, &b); // & is used for input
    int result = a + b;
    printf("%d\n", result); // \n is for a newline
    return 0;
}