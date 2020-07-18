#include "bits/stdc++.h"
#define mp make_pair
#define pb push_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;
using ll = long long;
using uint = unsigned int;
using pii = pair<int, int>;
using vi = vector <int>;

int main()
{
	int t;
	cin >> t;
	cin.ignore();
	while(t--)
	{
		string s;
		
		getline(cin, s);
		int len = s.size();
		for(int i=0; i<len; i++)
		{
			if(isalpha(s[i]))
			{
				s[i]+=3;
			}
		}
		reverse(s.begin(), s.end());
		for(int i=len/2; i<len; i++)
		{
			s[i]--;
		}
		cout<<s<<endl;
	}
	return 0;
}

