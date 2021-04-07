#include "bits/stdc++.h"
using namespace std;

#define INF 100000000

struct coin_change //structure is used to keep overall coin count
{
    int coin_used, sum;  // number of coin used
    map<int, int> coins; // list of diferent coin that used
    bool solved;         // if there exist a solution
};

coin_change Greedy(vector<int> v, int cap)
{
    int sum = 0, cnt = 0;
    coin_change out;
    map<int, int> coins;
    sort(v.rbegin(), v.rend()); //sorting the coin's array in decreasing order

    for (int x : v) // loop through all the coins
    {
        while (x <= cap) // keep taking coin till theres enough space
        {
            coins[x]++;
            cnt++;
            cap -= x;
            sum += x;
        }
    }

    out.coin_used = cnt;
    out.coins = coins;
    out.solved = (cap == 0);
    out.sum = sum;
    return out;
}

coin_change DP(vector<int> w, int cap)
{
    int cc = w.size(), sum = 0;
    int table[cc + 1][cap + 1]; // declaring an 2D array of size cc+1 * cap*1

    map<int, int> coins;
    coin_change ret;

    for (int i = 0; i < cap + 1; i++)
    {
        table[0][i] = INF; // intiating all value of first row to INFINITY
    }
    for (int i = 0; i < cc + 1; i++)
    {
        table[i][0] = 0; //intiating all value of first column to 0
    }
    for (int i = 1; i < cc + 1; i++)
    {
        for (int j = 1; j < cap + 1; j++)
        {
            if (w[i - 1] > j) // if coin is greater than bag size
            {
                table[i][j] = table[i - 1][j]; // value = top cell
            }
            else //else value = minimum of top cell and coin's amount left cell
            {
                table[i][j] = min(table[i - 1][j], 1 + table[i][j - w[i - 1]]);
            }
        }
    }
    ret.coin_used = table[cc][cap];

    int i = cc, j = cap;
    while (table[i][j] != 0)
    {
        if (table[i][j] == table[i - 1][j])
        {
            i--;
        }
        else
        {
            coins[w[i - 1]]++;
            sum += w[i - 1];
            j -= w[i - 1];
        }
    }
    ret.coins = coins;
    ret.sum = sum;
    ret.solved = true;
    return ret;
}

string parse(map<int, int> m) // parsing the coin counts into a string format
{
    string o = "";
    map<int, int>::reverse_iterator x;
    for (x = m.rbegin(); x != m.rend(); x++) // iterating the map from last to first
    {
        o += to_string(x->first);
        if (x->second > 1) // only if coin count is greater than 1, we take it as factor
        {
            o += "*" + to_string(x->second);
        }
        o += "+";
    }
    o.pop_back(); // erasing the last '+' character which is not necessary
    return o;
}

int main()
{
    int limit, type, tmp;
    vector<int> coins;

    cout << "Coin limit: ";
    cin >> limit;

    cout << "Coin type: ";
    cin >> type;
    coins.resize(type); //setting vector size

    cout << "Coins: ";
    for (int i = 0; i < type; i++)
    {
        cin >> coins[i];
    }

    auto gd = Greedy(coins, limit); // calling the Greedy function for greedy approach
    auto dp = DP(coins, limit);     // calling the DP function for dynamic approach

    cout << "Greedy need minimum " << gd.coin_used << " coins. ";
    cout << parse(gd.coins) << " = " << gd.sum << endl;
    cout << "DP need minimum " << dp.coin_used << " coins. ";
    cout << parse(dp.coins) << " = " << dp.sum << endl;

    if (gd.coin_used == dp.coin_used)
    {
        cout << "Greedy & DP both are optimal." << endl;
    }
    else if (!gd.solved)
    {
        cout << "Greedy was unable to solve but DP has one." << endl;
    }
    else
    {
        cout << "Greedy couldn't give the optimal solution but DP did." << endl;
    }

    return 0;
}
