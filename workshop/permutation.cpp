#include <bits/stdc++.h>
using namespace std;

template <typename Os, typename V>
Os &operator<<(Os &os, V const &v)
{
    os << "{ ";
    for (auto const &e : v)
        os << e << ' ';
    return os << "}";
}

int main()
{
    vector<int> v{5, 1, 3, 4, 2};
    int cnt = 0;
    do
    {
        cout << v << endl;
        cnt++;
    } while (next_permutation(v.begin(), v.end()));
    cout << cnt << endl;
    return 0;
}