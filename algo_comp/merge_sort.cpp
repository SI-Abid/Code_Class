#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &l, vector<int> &r, vector<int> &a)
{
    int nl=l.size();
    int nr=r.size();
    int i, j, k;
    i=j=k=0;
    while (i<nl && j<nr)
    {
        if(l[i]<=r[j])
            a[k++]=l[i++];
        
        else
            a[k++]=r[j++];
        
    }
    while (i<nl)
        a[k++]=l[i++];

    while (j<nr)
        a[k++]=r[j++];
}

void m_sort(vector<int> &a)
{
    int size=a.size();
    if(size<2)
        return;
        
    int mid=size/2;
    vector<int> left, right;
    for(int i=0; i<mid; i++)
        left.push_back(a[i]);
    
    for(int i=mid; i<size; i++)
        right.push_back(a[i]);
    
    m_sort(left);
    m_sort(right);
    merge(left, right, a);
}
int main()
{
    
    vector<int>a;
    a.push_back(2);
    a.push_back(1);
    a.push_back(4);
    a.push_back(7);
    a.push_back(8);
    a.push_back(9);
    a.push_back(6);
    a.push_back(3);
    a.push_back(5);
    a.push_back(10);
    // m_sort(a);
    make_heap(a.begin(), a.end());

    for(auto x:a)
        cout<<x<<endl;

}