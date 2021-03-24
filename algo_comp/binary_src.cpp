#include<iostream>
using namespace std;

int binary_search(int *a, int l, int r, int n)
{
    if(l>r)
        return -1;
    
    int mid=(l+r)/2;
    if(a[mid]==n)
    {
        return mid;
    }
    if(a[mid]>n)
    {
        return binary_search(a, l, mid-1, n);
    }
    else
    {
        return binary_search(a, mid+1, r, n);
    }
}

int main()
{
    int ar[30]={1,2,3,4,5,6,7,8,9,11,12,13,15,16,17,18,21,22,23,25,26,28,29,32,33,34,35,36,38,39};
    int pos;
    
    for(int x: ar)
        cout<<x<<" ";
    cout<<endl;
    
    pos=binary_search(ar, 0, 30, 17);
    if(pos==-1)
    {
        cout<<"Item not found"<<endl;
    }
    else
    {
        cout<<"Index of 17: "<<pos<<endl;
    }
    return 0;
}