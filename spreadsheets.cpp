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

int n;
char alph[26];
void char_gen()
{
	char c='A';
	for (int i = 0; i < 26; i++)
	{
		alph[i]=c+i;
	}
}
int main()
{
	char_gen();					//generate the alphabets
	cin>>n;
	string names[n][n];			//declaring a n*n array of names
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int size = max(((int)(rand()*1000)%10),5);
			string s="";
			while(size--)
			{
				int indx = (int)(rand()*1000)%26;		//generate a word
				s+=alph[indx];
			}
			names[i][j]=s;					//push it in the array
		}
	}
	int count=n;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			cout<<names[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
