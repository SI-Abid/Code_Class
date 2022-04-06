#include<bits/stdc++.h>
using namespace std;
void sleep(unsigned long long t=100000000)
{
    while(t--);
}
int main()
{
    puts("OKAY");
    clock_t start=clock();
    char c='0';
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            putchar(c+i);
            sleep();
            fflush(stdout);
        }
        putchar('\r');
    }
    clock_t end=clock();
    puts("");
    printf("Time taken: %.2f seconds\n",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}