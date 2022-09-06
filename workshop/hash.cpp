#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Hash
{
    ll f, s, p1, p2, MOD;
    Hash()
    {
        f = s = 0;
        p1 = 131;
        p2 = 137;
        MOD = 1e18 + 7;
    }
    Hash(string str)
    {
        f = s = 0;
        p1 = 131;
        p2 = 137;
        MOD = 1e18 + 7;
        for (int i = 0; i < str.size(); i++)
        {
            f = (f * p1 + str[i]) % MOD;
            s = (s * p2 + str[i]) % MOD;
        }
    }
    Hash operator+(Hash h)
    {
        Hash res;
        res.f = (f + h.f) % MOD;
        res.s = (s + h.s) % MOD;
        return res;
    }
    Hash append(char c)
    {
        Hash res;
        res.f = (f * p1 + c) % MOD;
        res.s = (s * p2 + c) % MOD;
        return res;
    }
    Hash prepend(char c, size_t offset)
    {
        Hash res;
        res.f = (f + c * (ll)pow(p1, offset)) % MOD;
        res.s = (s + c * (ll)pow(p2, offset)) % MOD;
        return res;
    }
    bool operator==(Hash h)
    {
        return f == h.f && s == h.s;
    }
    bool operator!=(Hash h)
    {
        return f != h.f || s != h.s;
    }
    bool operator<(Hash h)
    {
        if (f == h.f)
            return s < h.s;
        return f < h.f;
    }
    bool operator>(Hash h)
    {
        if (f == h.f)
            return s > h.s;
        return f > h.f;
    }
};

ostream &operator<<(ostream &os, Hash h)
{
    os << h.f << " " << h.s;
    return os;
}

int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<Hash> h(n);
    for (int i = 0; i < n; i++)
    {
        h[i] = Hash(v[i]);
    }
    sort(h.begin(), h.end());
    for (int i = 0; i < n; i++)
    {
        cout << h[i] << endl;
    }
    return 0;
}