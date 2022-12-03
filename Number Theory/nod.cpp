#include<bits/stdc++.h>
using namespace std;
vector<int> nod(int n)
{
    vector<int> res;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            if (i * i != n)
                res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}
signed main()
{
    for(auto x:nod(127))
        cout<<x<<' ';
    return 0;
}