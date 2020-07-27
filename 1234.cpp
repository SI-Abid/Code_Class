#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef vector<string> vs;
typedef vector<int> vi;
typedef set<char> sc;
typedef pair<int, int> pii;

#define mp 			make_pair
#define pb 			push_back
#define pi 			3.1415926535897932384626433832795
#define MOD 		1000000007
#define For(n) 	    for(int i=0; i<n; i++)
#define Revl(n) 	for(int i=n; i>=0; i--)
#define FOR(p,k)	for(int i=p; i<k; i++)
#define Sort(x)		sort(x.begin(), x.end())
#define Revs(x)		reverse(x.begin(), x.end())
#define mem(a,b)	memset(a, b, sizeof(a))
#define two(i)		((ll)1<<i)

int main()
{
    // freopen("in.txt", "r", stdin);
    string s;
    int cnt;
    while(getline(cin, s))
    {
        cnt=0;
        for(int i=0; i<s.size(); i++)
        {
            if(isalpha(s[i]))
            {
                (cnt&1)? s[i]=tolower(s[i]) : s[i]=toupper(s[i]);
                cnt++;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}