#include<stdio.h>

int print(int a, int b, int c)
{
	int d=a+b+c;
	return d;
}


int main()
{
	int ans=print(10,20,50);
	printf("%d\n", ans);
	return 0;

}



