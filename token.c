#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main()
{
    char *s;
    s = malloc(1000 * sizeof(char));
    scanf("%[^\n]", s);
    char *token = strtok(s, " ");
    while(token)
    {
        puts(token);
        token = strtok(NULL, " ");
    }
    return 0;
}