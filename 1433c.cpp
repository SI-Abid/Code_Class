#include "bits/stdc++.h"
using namespace std;

int main()
{
    string s[8], piece="KQBNRP";
    int w[6]={0,9,3,3,5,1};
    int p1=0, p2=0;
    for(int i=0; i<8; i++)
    {
        cin>>s[i];
    }
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            for(int k=0; k<6; k++)
            {
                if(isupper(s[i][j]))
                {
                    if(s[i][j]==piece[k])
                    {
                        p2+=w[k];
                    }   
                }
                else
                {
                    if(s[i][j]^32==piece[k])
                    {
                        p1+=w[k];
                    }
                }
            }
        }
    }
    if(p1>p2)
    {
        puts("White");
    }
    else if(p1<p2)
    {
        puts("Black");
    }
    else
    {
        puts("Draw");
    }
    return 0;
}