#include "stdio.h"
// convert the letter to upper case
// substract 32 from input character
int main()
{
    char c;

    printf("Enter a lower-case letter: ");
    scanf("%c",&c);
    
    printf("The upper-case equivalent is: %c\n",c-32);
    
    return 0;
}
