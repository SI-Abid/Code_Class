#include "bits/stdc++.h"
using namespace std;

int main()
{
    int Data[100], k=1, loc, maxm;
    int n;
    
    cin>>n;
    
    for(int i=0; i<n; i++)                                                                                  
    {
        cin>>Data[i];
    }
    
    maxm=Data[0];
    
    while(k<n)
    {
        if(maxm<Data[k])
        {
            loc=k, maxm=Data[k];
        }
        k++;
    }

    cout<<"Maximum number is "<<maxm<<" and Location is "<<loc+1<<endl;
    return 0;
}