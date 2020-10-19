#include "stdio.h"

int main()
{
    char days[7][10] = {"Saturday\0", "Sunday\0", "Monday\0", "Tuesday\0", "Wednesday\0", "Thursday\0", "Friday\0"};
    int n;
    scanf("%d", &n);
    printf("%s\n", days[(n-1)%7]);
    return 0;
}