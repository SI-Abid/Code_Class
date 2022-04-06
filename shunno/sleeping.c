#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    printf("Hello World!\n");
    int i, j, count = 10;
    char c = '-';
    for (i = 0; i < count; i++)
    {
        for (j = 0; j < count / 2; j++)
        {
            printf(" %c", c);
            fflush(stdout);
        }
        c ^= '-' ^ '=';
        sleep(1);
        printf("\r");
    }
    puts("");
    return 0;
}