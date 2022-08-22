#include <bits/stdc++.h>
#include "boost/variant.hpp"
using namespace std;

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p)
{
    return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "[\n\t";
    for (int i = 0; i < v.size(); i++)
    {
        os << v[i];
        if (i != v.size() - 1)
            os << ",\n\t";
    }
    return os << "\n\t]";
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &m)
{
    os << "{\n\t";
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it != m.begin())
            os << ",\n\t";
        os << it->first << ": " << it->second;
    }
    return os << "\n\t}";
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

// overload for boost::variant
template <typename... Ts>
ostream &operator<<(ostream &os, const boost::variant<Ts...> &v)
{
    return boost::apply_visitor(
        [&os](const auto &x) { return os << x; }, v);
}


int main()
{
    // map<string, vector<map<string, string>>> json;

    // json["document"].push_back(map<string, string>());
    // json["document"].back()["_id"] = "61c35218ce48a66af062e2f4";
    // json["document"].back()["username"]="root";
    // json["document"].back()["password"]="toor";
    // json["document"].back()["fullname"]="Admin Root";
    // json["document"].back()["email"]="admin@sa.org";

    // json["document"].push_back(map<string, string>());
    // json["document"].back()["_id"] = "61d4f4ed3d4ed041fe1faf1a";
    // json["document"].back()["username"]="saiham";
    // json["document"].back()["password"]="*123";
    // json["document"].back()["fullname"]="Saiham Islam";
    // json["document"].back()["email"]="siabid5324@gmail.com";

    // json["document"].push_back(map<string, string>());
    // json["document"].back()["_id"] = "61df128b7ba6e428f4394516";
    // json["document"].back()["username"]="habiba";
    // json["document"].back()["password"]="1234";
    // json["document"].back()["fullname"]="Habiba Khanom";
    // json["document"].back()["email"]="hkhanom@gmail.com";
    /*
    .
    .
    .
    */
    // cout << json << endl;

    map<string, vector<map<string, boost::variant<string, vector<map<string, boost::variant<string, bool>>>>>>> json;

    json["document"].push_back(map<string, boost::variant<string, vector<map<string, boost::variant<string, bool>>>>>());
    json["document"].back()["_id"] = "61eee42ff834f99b2282ee42";
    json["document"].back()["username"] = "tousif";
    json["document"].back()["assingment_list"] = vector<map<string, boost::variant<string, bool>>>();
    
    cout << json << endl;

    // json["document"].back()["assingment_list"].push_back(map<string, boost::variant<string, bool>>());
    // json["document"].back()["assingment_list"].back()["title"] = "Sort Cloth";
    // json["document"].back()["assingment_list"].back()["description"] = "aso sobai mile kapor gusai\ngood luck with kapor gusano";
    // json["document"].back()["assingment_list"].back()["deadline"] = "2019-01-01";
    // json["document"].back()["assingment_list"].back()["finished"] = true;
    
    // json["document"].back()["assingment_list"].push_back(map<string, boost::variant<string, bool>>());
    // json["document"].back()["assingment_list"].back()["title"] = "Workout";
    // json["document"].back()["assingment_list"].back()["description"] = "workout to become stronger\nlet's go";
    // json["document"].back()["assingment_list"].back()["deadline"] = "2019-01-01";
    // json["document"].back()["assingment_list"].back()["finished"] = false;

    // json["document"].push_back(map<string, boost::variant<string, vector<map<string, boost::variant<string, bool>>>>>());
    // json["document"].back()["_id"] = "61f014cd6e972119d1408454";
    // json["document"].back()["username"] = "abid";
    // json["document"].back()["assingment_list"] = vector<map<string, boost::variant<string, bool>>>();

    // json["document"].back()["assingment_list"].push_back(map<string, boost::variant<string, bool>>());
    // json["document"].back()["assingment_list"].back()["title"] = "WINDOW_C";
    // json["document"].back()["assingment_list"].back()["description"] = "close window operation triggerd";
    // json["document"].back()["assingment_list"].back()["deadline"] = "2019-01-01";
    // json["document"].back()["assingment_list"].back()["finished"] = false;

    // json["document"].back()["assingment_list"].push_back(map<string, boost::variant<string, bool>>());
    // json["document"].back()["assingment_list"].back()["title"] = "new assingment";
    // json["document"].back()["assingment_list"].back()["description"] = "hello world";
    // json["document"].back()["assingment_list"].back()["deadline"] = "2019-01-01";
    // json["document"].back()["assingment_list"].back()["finished"] = true;





    return 0;
}