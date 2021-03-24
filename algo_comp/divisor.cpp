#include <bits/stdc++.h>
using namespace std;

const int mx = 1e8 + 10;
bool status[mx];
int ar[100000];

void sieve()
{

    int sq = sqrt(mx * 0.1) + 1;
    status[1] = 1;
    ar[0] = 2;
    int x = 1;

    for (int i = 4; i <= mx; i += 2)
    {
        status[i] = 1;
    }
    for (int i = 3; i <= sq; i++)
    {
        if (status[i] == 0)
        {
            ar[x++] = i;

            for (int j = i * i; j < mx; j += i * 2)
            {
                status[j] = 1;
            }
        }
    }
}

int main()
{
    sieve();

    int n = 14, nod = 1;
    int sq = sqrt(n * 0.1) + 1;
    for (int i = 0; ar[i] <= sq; i++)
    {
        int c = 0;
        while (n % ar[i] == 0)
        {
            n /= ar[i];
            c++;
        }
        nod *= (c + 1);
    }
    if (n > 1)
    {
        nod *= 2;
    }

    cout << nod << endl;
    return 0;
}

// 2 3 5 7 11 13 

// 1 2 7 14
//14/2 
//96/2 => 48 => 24 => 12 => 6 >3
//2 2 2 2 2 3