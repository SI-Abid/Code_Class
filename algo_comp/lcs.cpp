#include "bits/stdc++.h"
using namespace std;

#define all(x) x.begin(), x.end()

string lcs(vector<vector<int>> t, string a, string b)
{

    int n, m;
    n = a.size();
    m = b.size();

    string ans = "";
    while (n>0 && m>0)
    {
        if (a[n - 1] == b[m - 1])
        {
            ans += a[n - 1];
            n--;
            m--;
        }
        else if (t[n - 1][m] >= t[n][m - 1])
        {
            n--;
        }
        else
        {
            m--;
        }
    }
    reverse(all(ans));
    return ans;
}

vector<vector<int>> table(string a, string b)
{
    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        
        for (int j = 1; j <= m; j++)
        {
      
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
          
            }
            else if (dp[i - 1][j] >= dp[i][j - 1])
            {
                dp[i][j] = dp[i - 1][j];
        
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            
            }
        }
    }
    return dp;
}

int main()
{
    string a, b;
    cin >> a >> b;
  
    auto tab = table(a, b);
  
    // for (int i = 0; i <= a.size(); i++)
    // {
    //     for (int j = 0; j <= b.size(); j++)

    //         cout << tab[i][j] << " ";

    //     cout << endl;
    // }
    string ans = lcs(tab, a, b);
    cout << ans << endl;
    return 0;
}