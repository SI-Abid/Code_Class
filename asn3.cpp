/****************************************************
*	Assignment-3									*
*	============									*
*													*
*	Prepared By:									*
*	1.												*
*	2. 												*
*	3.												*
*	4.												*
*													*
*	Date of Submission: 							*
*****************************************************/

#include <bits/stdc++.h>
using namespace std;


const int n = 56;


struct Student{
    string name, id;
    int marks;
} s[n];


void struct_sort();
bool compare_ids(Student a, Student b);
bool compare_marks(Student a, Student b);

int main()
{
    int i;
    string t;

    freopen("input.txt", "r", stdin);

    for(i=0; i<n; i++)
    {
        getline(cin, s[i].id);
        getline(cin, s[i].name);
        getline(cin, t);
        s[i].marks = atoi(t.c_str());
    }

    struct_sort();

    for(i=0; i<n; i++)
    {
        cout << setw(15); cout << left << s[i].id;
        cout << setw(30); cout << s[i].name;
        cout << setw(5);  cout << s[i].marks << endl;
    }

    return 0;
}

void struct_sort()
{
    sort(s, s+n, compare_marks);
    
    for(int i=0; i<n-1;)
    {
        int t, st, en;
        st=i;
        t=s[i].marks;
        while(t==s[i].marks)
        {
            i++;
        }
        en=i;
        sort(s+st, s+en, compare_ids);
    }

}

bool compare_marks(Student a, Student b)
{
	return (a.marks > b.marks);
}

bool compare_ids(Student a, Student b)
{
	return (a.id < b.id);
}
