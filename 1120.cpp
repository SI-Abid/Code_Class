#include "bits/stdc++.h"
#define MP make_pair
#define PB push_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;
using ll = long long;
using uint = unsigned int;
using pii = pair<int, int>;
using vi = vector <int>;

void solve()
{
	char c;
	string s, out, ret;

	cin>>c>>s;
	
	if(c=='0')
		return;
		
	for(int i=0; i<(int)s.size(); i++)
	{
		if(s[i]!=c)
			out+=s[i];
	}
	
	int count=0;
	
	for(int i=0; out[i]=='0'; i++)
	{
		count++;
	}
	out.erase(0, count);
	
	out.empty()? cout<<"0" : cout<<out;
	cout<<endl;
	
	solve();
}

int main()
{
	solve();
	return 0;
}

