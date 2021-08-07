#include<bits/stdc++.h>
using namespace std;

void print1()
{
    static int a = 0;
    a++;
    cout << a << endl;
}
void print2()
{
    int a = 0;
    a++;
    cout << a << endl;
}

int main()
{   
    for(int i=0; i<5; i++)
    {
        print1();
    }
    for (int i = 0; i < 5; i++)
    {
        print2();
    }
    
    return 0;
}

