#include "bits/stdc++.h"
#include "fstream"
#include "stdlib.h"
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define be begin()
#define en end()
#define all(x) (x).begin(), (x).end()
#define out cout << setprecision(20)

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;

map<string, string> pass;

void loadUserData();
void login();
void signup();
string genPass();
void examInfo();

int main()
{
    loadUserData();
    login();
    examInfo();
    return 0;
}

void loadUserData()
{
    fstream file;
    file.open("data.txt", ios::in);

    if(file)
    {
        string usrnm, pswd;
        while (file >> usrnm)
        {
            file >> pass[usrnm];
        }
    }
    file.close();
}

string genPass()
{
    string ps = "";
    const string validChar = "qwertyuioplkjhgfdsazxcvbnm,./{}';[]=-+*<>?0987654321";
    cout << "How long you want the password to be(3-30): ";
    int len;
    cin >> len;
    for (int i = 0; i < len; i++)
    {
        ps += validChar[rand() % validChar.size()];
    }
    return ps;
}

void login()
{
    string username, password;
    cout << "Enter Username: ";
    cin >> username;
    if (pass.find(username) == pass.end())
    {
        cout << "Username doesn't exist! Please register..." << endl;
        signup();
        return;
    }
    cout << "Enter Password: ";
    cin >> password;
    if (pass[username] == password)
    {
        cout << "Login success..." << endl;
        return;
    }
    else
    {
        cout << "Wrong Password! Try again..." << endl;
        login();
    }
}

void examInfo()
{
    string data;
    fstream file;

    file.open("StudentA.txt", ios::app);

    cout << "Student Name: ";
    cin.ignore();
    getline(cin, data);
    file << "Name: " << data << endl;

    cout << "Assingment date: ";
    getline(cin, data);
    file << "Assingment date: " << data << endl;

    cout << "Exam date: ";
    getline(cin, data);
    file << "Exam date: " << data << endl
         << endl;

    file.close();
}

void signup()
{
    string username, password;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Get a random password or enter new one (1/2): ";
    int op;
    cin >> op;
    if (op == 1)
    {
        password = genPass();
    }
    else
    {
        cout << "Enter Password: ";
        cin >> password;
    }

    fstream file;
    file.open("data.txt", ios::app);

    if (file)
    {
        file << username << " " << password << endl;
    }
    file.close();
}