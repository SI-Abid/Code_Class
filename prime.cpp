#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> prime;

    int n;
    cin >> n;

    bool stat[n + 5];

    // int sq = sqrt(n * 0.1) + 1;

    stat[0] = stat[1] = true;

    for (int i = 4; i <= n; i += 2)
    {
        stat[i] = true;
    }

    for (int i = 3; i * i <= n; i += 2)
    {
        if (!stat[i])
        {
            // prime.push_back(i);

            for (int j = i * i; j < n; j += i * 2)
            {
                stat[j] = true;
                // prime.push_back(j);
            }
        }
    }
    n==5;
    for (int i = 0; i <= n; i++)
        if(!stat[i]) prime.push_back(i);
        
        // if(stat[i]==false)
        //     prime.push_back(i);

    cout << prime.size() << endl;
    
    for (int p : prime)
    {
        cout << p << " ";
    }
    
    cout << endl;
    return 0;
}