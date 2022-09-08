#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int P = 131;
const ll MOD = 1e13 + 7;
vector<ll> p_pow(1000001);

void init()
{
    p_pow[0] = 1;
    for (int i = 1; i < 1000001; i++)
    {
        p_pow[i] = (p_pow[i - 1] * P) % MOD;
    }
}
// forward hash
ll getHash(ll &prev, char c)
{
    return (prev * P + c) % MOD;
}
// reverse hash
ll getHash(ll &prev, char c, size_t offset)
{
    return (prev + c * p_pow[offset]) % MOD;
}

pair<ll,ll> getHash(string s)
{
    ll f = 0;
    ll r = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        f = getHash(f, s[i]);
        r = getHash(r, s[i], i);
    }
    return {f,r};
}

int main()
{
    init();
    string s;
    cin >> s;
    auto hash = getHash(s);
    cout << hash.first << " " << hash.second << endl;
    return 0;
}