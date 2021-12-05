#include <bits/stdc++.h>
using namespace std;

class str : public string
{
public:
    str() : string() {}
    str(string s) : string(s) {}
    str(const char *s) : string(s) {}

    str operator+(const str &s)
    {
        return str(*this) += s;
    }

    str operator=(const str &s)
    {
        return str(*this) = s;
    }

    void replace(const str &s, const str &r)
    {
        replace(s.begin(), s.end(), r);
    }

    vector<str> split(const str &s)
    {
        vector<str> v;
        int i = 0, j = 0;
        while (i < size())
        {
            j = find(s, i);
            if (j == -1)
                j = size();
            v.push_back(substr(i, j - i));
            i = j + s.size();
        }
        return v;
    }

    vector<str> split()
    {
        return split(str(" "));
    }

};

int main()
{
    str s;
    getline(cin, s);
    cout<<s.size()<<endl;
    for (auto i : s.split("ab"))
        cout << i << endl;
    s.replace("ab", "cd");
    cout<<s<<endl;
    return 0;
}