/*
playing card pyramid
           /\
          /__\
         /\  /\
        /__\/__\
*/
#include "stdio.h"

int main()
{
    int a,b,c,d,n,m,f,i,level;
    printf("Size: ");
    scanf("%d",&n);
    printf("Level: ");
    scanf("%d", &level);
    for(d=1;d<=level;d++) // layers
    {
        for(i=1;i<=n;i++)   //rows in each layer
        {
            c=(level-d)*n;
            while(c--)
            {
                printf(" ");        //block spaces
            }

            a=d;
            while(a--)              //repeat each lines
            {
                m=n-i;
                while(m--)
                {
                    printf(" ");
                }
                
                printf("/");
                f=(i-1)*2;
            
                if(i==n)
                {
                    while(f--)
                    {
                        printf("_");
                    }
                }
                else 
                {
                    while(f--)
                    {
                        printf(" ");
                    }
                }
                printf("\\");

                m=n-i;
                while(m--)
                {
                    printf(" ");
                }

            }
            puts("");   // print newline
        }
    }
    return 0;
}

/*
size: 5 level: 3   leading spaces per layer = (level-layer)*size
##########0000/\0000 '\n'
##########000/--\000
##########00/----\00
##########0/------\0
##########/________\
#####0000/\00001111/\1111
#####000/--\000111/--\111
#####00/----\0011/----\11
#####0/------\01/------\1
#####/________\/________\
0000/\00001111/\11111111/\1111
000/--\000111/--\111111/--\111
00/----\0011/----\1111/----\11
0/------\01/------\11/------\1
/________\/________\/________\

*/