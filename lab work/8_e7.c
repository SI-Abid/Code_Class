/**
	Assignment - 8: Number Base Converter
	=====================================
	This program will convert a binary number to decimal and vice versa.

	Prepared By: (Group - e7)
	------------------------
	1. Saiham Islam Abid
	2. Sadia Rashida
	3. Farhana Akther Munni
	4.

	Date of Submission: Sept 10, 2020
	-------------------

**/

#include <stdio.h>
#include <math.h>

void decimal_to_binary();
void binary_to_decimal();
int str_len(char []);

char bin[1000000000];

int main()
{
	int choice;

	printf("\tWelcome to Number Base Converter\n");
	printf("\t================================\n");

	do{
		printf("\n\n1. Decimal to Binary\n");
		printf("2. Binary to Decimal\n");
		printf("3. Exit\n");
		printf("\n\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				decimal_to_binary();
				break;
			case 2:
				binary_to_decimal();
				break;
			default:
				return 0;
		}

	} while(1);

	return 0;
}

void decimal_to_binary()
{
	int n, i;
    printf("Enter a Decimal number: ");
    scanf("%d", &n);

    // store the bits  in the bin[] array
    for(i=0; n; i++)
    {
        bin[i] = (n%2)+'0';
        n /= 2;
    }
    printf("The Binary value of your given number is: ");
    // print the bits in reverse order
    while(i--)
    {
        printf("%c", bin[i]);
    }  
}
// 11000101   ~197 
void binary_to_decimal()
{
	printf("Enter you Binary number: ");
    scanf("%s", bin);
    
    int n=0, len=str_len(bin);
    for(int i=0; i<len; i++)
    {
        n+= (bin[i]-'0') * pow(2, len-1-i);    // x*2^n
    }
    printf("The Decimal value of your given number is: %d", n);
}

int str_len(char x[])
{
    int i=0;
    while(x[i])     //break when '\0' is found in the string
        i++;

    return i;
}