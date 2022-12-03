#include<bits/stdc++.h>
using namespace std;
void sieve(int n, vector<int> &primes)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] && (long long)i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if (is_prime[i])
            primes.push_back(i);
    }
}
void prime_facto_gcd(int n, int m)
{
    vector<int> primes;
    sieve(max(n, m), primes);
    vector<pair<int, int>> pf;
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++)
    {
        if (n % primes[i] == 0)
        {
            int cnt = 0;
            while (n % primes[i] == 0)
            {
                cnt++;
                n /= primes[i];
            }
            pf.push_back({primes[i], cnt});
        }
    }
    vector<pair<int, int>> pf2;
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= m; i++)
    {
        if (m % primes[i] == 0)
        {
            int cnt = 0;
            while (m % primes[i] == 0)
            {
                cnt++;
                m /= primes[i];
            }
            pf2.push_back({primes[i], cnt});
        }
    }
    if (n != 1)
        pf.push_back({n, 1});
    if (m != 1)
        pf2.push_back({m, 1});
    vector<pair<int, int>> res;
    int i = 0, j = 0;
    while (i < pf.size() && j < pf2.size())
    {
        if (pf[i].first == pf2[j].first)
        {
            res.push_back({pf[i].first, min(pf[i].second, pf2[j].second)});
            i++;
            j++;
        }
        else if (pf[i].first < pf2[j].first)
            i++;
        else
            j++;
    }
    int ans = 1;
    for (auto p : res)
    {
        for (int i = 0; i < p.second; i++)
            ans *= p.first;
    }
    cout << ans << endl;
}
signed main()
{
    prime_facto_gcd(16,20);
    return 0;
}