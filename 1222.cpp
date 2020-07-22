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
#define FOR(i,p,k)	for(int i=p; i<k; i++)
#define Sort(x)		sort(x.begin(), x.end())
#define Revs(x)		reverse(s.begin(), x.end())
#define mem(a,b)	memset(a, b, sizeof(a))
#define two(i)		((ll)1<<i)

int main()
{
    int n, l, c;
    while(cin>>n>>l>>c)
    {
        string word;
        int cc=0, lc=1, pc=1, wl=1;
        while(n--)
        {
            cin>>word;
            // cout<<i<<endl;
            wl=word.size();
            if(cc+wl+(cc!=0) <=c)
                cc+=wl+(cc!=0);         //count the words len with space
            else
            {
                cc=wl;
                lc++;
                
            }
            if(lc>l)
            {
                pc++;
                lc=1;
            }
            // else
            // {
            //     cc++;       //count the spaces
            // }
            
        }
        cout<<pc<<endl;
    }
    return 0;
}