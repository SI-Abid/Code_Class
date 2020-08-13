#include <stdio.h>
#include <stdlib.h>		// rand(), srand()
#include <time.h>		// time()

int main ()
 
{
    srand(time(0));
    
    int a=10;
	while(a--)
		printf("a");
	puts("asd");
	a=10;
	puts("bfd");
	while(a--)
		printf("a");
	a=10;
	while (a--)
		printf("\b");
	
    return 0;
}
