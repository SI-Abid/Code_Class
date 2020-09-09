#include "stdio.h"

int str_len(char []);
void str_cat(char [], char []);
void str_cpy(char [], char []);
int str_cmp(const char [], const char []);
void str_rev(char []);

int main()
{
    char mystr[100]="test string";
    int size=str_len(mystr);
    printf("Length of \"%s\" is %d\n", mystr, size);

    char a[11]="asdf", b[]="ghjkl";
    printf("%s + %s = ", a, b);
    str_cat(a, b);
    puts(a);

    char d[100], s[]="I am non-human";
    str_cpy(d, s);
    puts(d);

    char s1[]="asdfg", s2[]="adsdf";
    switch (str_cmp(s1, s2))
    {
    case 1:
        puts("First string is bigger than the second one");
        break;
    case -1:
        puts("Second string is bigger than the first one");
        break;
    default:
        puts("Both string are equal");
        break;
    }

    printf("Reverse of \"%s\" is = ", s);
    str_rev(s);
    puts(s);

    return 0;
}

int str_len(char x[])
{
    int i=0;

    while(x[i])     //break when '\0' is found in the string
        i++;

    return i;
}
//    a[] =  "sadia\0"   b[] =  "rashida\0"

void str_cat(char a[], char b[])
{
    int i=0;
    while(a[i])
        i++;

    for(int j=0; b[j]; i++,j++)     //break when '\0' found in b[]
        a[i]=b[j];
    
    a[i]='\0';
}
//      a[]=""   b[]="Sadia is smart"
void str_cpy(char dest[], char src[])
{
    int i;
    for(i=0; src[i]; i++)
    {
        dest[i]=src[i];
    }
    dest[i]=src[i];
}

int str_cmp(const char s1[], const char s2[])
{
    for(int i=0; s1[i] || s2[i]; i++)
    {
        if(s1[i]>s2[i])
        {
            return 1;
        }
        else if(s1[i]<s2[i])
        {
            return -1;
        }
        
    }
    return 0;
}

void str_rev(char x[])
{
    int len=str_len(x);
    for(int i=0; i<len/2; i++)
    {
        char tmp = x[i];
        x[i] = x[len-1-i];
        x[len-1-i] = tmp;
    }
}