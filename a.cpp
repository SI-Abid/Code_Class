#include "bits/stdc++.h"
#define pf(a,b) printf("%d %d\n",a,b)
using namespace std;
int main()
{
    int a;
    cin>>a;
    int b=a/2;
    pf(b,b);
    pf(b,-b);
    pf(-b,b);
    pf(-b,-b);
    return 0;
}