#include <bits/stdc++.h>
using namespace std;

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p)
{
    return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "[";
    for (int i = 0; i < v.size(); i++)
    {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    return os << "]";
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &m)
{
    os << "{";
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it != m.begin())
            os << ", ";
        os << it->first << ": " << it->second;
    }
    return os << "}";
}

template <typename T>
ostream &operator<<(ostream &os, const set<T> &s)
{
    os << "{";
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (it != s.begin())
            os << ", ";
        os << *it;
    }
    return os << "}";
}

bool comp(pair<char, int> a, pair<char, int> b)
{
    return a.second < b.second;
}

int main()
{
    pair<int, int> pp = make_pair(1, 2);
    cout << pp << endl;

    pair<string, pair<char, int>> p = {"hello", {'a', 1}};
    cout << p << endl;

    vector<pair<char, int>> v = {{'a', 1}, {'b', 2}};
    cout << v << endl;
    v.push_back({'c', 0});
    cout << v << endl;

    map<char, pair<int, int>> m = {{'a', {1, 2}}, {'d', {3, 4}}};
    cout << m << endl;
    m['c'] = {5, 6};
    cout << m << endl;

    set<char> s = {'a', 'b', 'c', 'd'};
    cout << s << endl;
    s.insert('0');
    cout << s << endl;

    for (auto [k, v] : m)
        cout << k << ": " << v << endl;

    string text = "my name is khan my father name is khan";
    // split text by space
    vector<string> words;

    while (text.find(" ") != string::npos)
    {
        words.push_back(text.substr(0, text.find(" ")));
        text = text.substr(text.find(" ") + 1);
    }
    words.push_back(text);
    cout << words << endl;

    map<string, int> word_count;
    for (auto word : words)
    {
        word_count[word]++;
    }
    cout << word_count << endl;

    vector<pair<char, int>> v1 = {{'a', 1}, {'b', 2}, {'c', 3}};
    cout << v1 << endl;
    v1.push_back({'d', 4});
    v1.push_back({'a', 5});
    v1.push_back({'b', 2});
    cout << v1 << endl;

    set<pair<char, int>> s1 = {{'a', 1}, {'b', 2}, {'c', 3}};
    cout << s1 << endl;
    s1.insert({'d', 4});
    s1.insert({'a', 5});
    s1.insert({'b', 2});
    cout << s1 << endl;

    map<string, vector<pair<char, int>>> m1;
    m1["hello"] = {{'a', 1}, {'b', 2}, {'c', 3}};
    m1["world"] = {{'d', 4}, {'a', 5}, {'b', 2}};
    cout << m1 << endl;
    m1.at("hello").push_back({'e', 6});
    m1.at("world").push_back({'f', 7});
    cout << m1 << endl;

    // delete from map
    m1.erase("hello");
    cout << m1 << endl;

    // delete from set
    s1.erase({'a', 5});
    cout << s1 << endl;

    // delete from vector
    v1.erase(v1.begin() + 1);
    cout << v1 << endl;

    // search in map
    if (m1.find("hello") != m1.end())
        cout << "hello is found" << endl;
    else
        cout << "hello is not found" << endl;

    // search in set
    if (s1.find({'a', 5}) != s1.end())
        cout << "a:5 is found" << endl;
    else
        cout << "a:5 is not found" << endl;

    // search in vector
    if (find(words.begin(), words.end(), "name") != words.end())
        cout << "name is found" << endl;
    else
        cout << "name is not found" << endl;

    // sort(v.begin(), v.end(), [](const pair<char, int> &a, const pair<char, int> &b) {
    //     return a.second < b.second;
    // });
    sort(v.begin(), v.end(), comp);
    
    cout << v << endl;

    sort(v.begin(), v.end(), greater<pair<char, int>>());

    cout << v << endl;

    return 0;
}