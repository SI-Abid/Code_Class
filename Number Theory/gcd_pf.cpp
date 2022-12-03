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
    if (n != 1)
        pf.push_back({n, 1});
    int res = 1;
    for (auto p : pf)
    {
        if (p.second >= 1 && m % p.first == 0)
            res *= p.first;
    }
    cout << res;
}
signed main()
{
    prime_facto_gcd(140,70);
    return 0;
}