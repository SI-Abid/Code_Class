#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define be begin()
#define en end()
#define all(x) (x).begin(),(x).end()
#define out cout<<setprecision(20)

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int a[3][3], b[3][3];
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            cin>>a[i][j];

    b[0][0]= a[1][1]*a[2][2]-a[1][2]*a[2][1];
    b[0][1]=-a[1][0]*a[2][2]-a[1][2]*a[2][0];
    b[0][2]= a[1][0]*a[2][1]-a[1][1]*a[2][0];
    b[1][0]=-a[0][1]*a[2][2]-a[0][2]*a[2][1];
    b[1][1]= a[0][0]*a[2][2]-a[0][2]*a[2][0];
    b[1][2]=-a[0][0]*a[2][1]-a[0][1]*a[2][0];
    b[2][0]= a[0][1]*a[1][2]-a[0][2]*a[1][1];
    b[2][1]=-a[0][0]*a[1][2]-a[0][2]*a[1][0];
    b[2][2]= a[0][0]*a[1][1]-a[0][1]*a[1][0];

    for(int j=0; j<3; j++)
    {
        for(int i=0; i<3; i++)
            printf("%3d  ", b[i][j]);

        puts("");
    }
    return 0;
}
