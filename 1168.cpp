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
	cin>>t;
	while(t--)
	{
		string time;
		cin>>time;
		int len = time.size();
		int ledcount=0;
		while(len>0)
		{
			char bit = time[len-1];
			switch(bit)
			{
				case '0': ledcount+=6; break;
				case '1': ledcount+=2; break;
				case '2': ledcount+=5; break;
				case '3': ledcount+=5; break;
				case '4': ledcount+=4; break;
				case '5': ledcount+=5; break;
				case '6': ledcount+=6; break;
				case '7': ledcount+=3; break;
				case '8': ledcount+=7; break;
				case '9': ledcount+=6; break;
			}
			time.pop_back();
			len = time.size();
		}
		cout<<ledcount<<" leds"<<endl;
	}
	return 0;
}
