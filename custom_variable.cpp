#include "bits/stdc++.h"
using namespace std;
struct student
{
    int id;
    int batch;
    string name;
    string major;
};
int main()
{
    student st;
    st.id = 2012020207;
    st.name = "Saiham Islam Abid";
    st.batch = 53;
    st.major = "CSE";
    cout<<st.name<<" "<<st.id<<" "<<st.batch<<" "<<st.major<<endl;
    return 0;
}