/*
    Checking Anagrams
    Group E7
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#define For(n)  for(i=0; i<n; i++)
#define SIZE 200

void alphacopy(char [], char []);
void Sort(char []);
int check_ana(char [], char[]);
char charswap(char);

int main()
{
    FILE *f1 = fopen("file1.txt", "r");
    FILE *f2 = fopen("file2.txt", "r");

    char c1[SIZE], c2[SIZE]; 
    int i=1;
    while(fgets(c1, SIZE, f1))
    {
        // printf("%d\n", i++);
        fgets(c2, SIZE, f2);

        int len1=strlen(c1), len2=strlen(c2);

        c1[len1-2]='\0';
        c2[len2-2]='\0';

        printf("\"%s\" and \"%s\" are ", c1, c2);
        if(check_ana(c1, c2))
        {
            puts("anagram.");
        }
        else
        {
            puts("not anagram.");
        }
        // puts(c1);
        // puts(c2);
        // puts("done");
    }

    return 0;
}

char charswap(char c)
{
    return c^32;
}

void Sort(char t[])
{
	int i, j, pos, min, size=strlen(t);
    char temp;
	for(i=0; i<size-1; i++)
    {
        for(j=0; j<size-i-1; j++)
        {
            if(t[j]>t[j+1])
            {
                temp=t[j];
                t[j]=t[j+1];
                t[j+1]=temp;
            }
        }
    }
    // puts("sort done");
}

int check_ana(char t1[], char t2[])
{
    int i, j;
    char a[SIZE], b[SIZE];
    
    alphacopy(a, t1);
    alphacopy(b, t2);
    
    for(i=0; a[i]; i++)
    {
        if(a[i]>='A' && a[i]<='Z')
        {
            a[i]=charswap(a[i]);
        }
    }
    for(i=0; b[i]; i++)
    {
        if(b[i]>='A' && b[i]<='Z')
        {
            b[i]=charswap(b[i]);
        }
    }
    Sort(a);
    Sort(b);
    
    if(strcmp(a, b)==0)
        return 1;
    
    return 0;
}

void alphacopy(char d[], char s[])
{
    int i, j;
    for(i=0, j=0; s[i]; i++)
    {
        if(isalpha(s[i]))
        {
            d[j]=s[i];
            j++;
        }
    }
    d[j]='\0';
}