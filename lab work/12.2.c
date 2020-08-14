#include "stdio.h"

void my_function();

int main()
{
    puts("Line 1");
    my_function();
    puts("Line 2");
    return 0;
}

void my_function()
{
    puts("Line 3");
}