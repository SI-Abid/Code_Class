#include "iostream"
#include "algorithm"
#include "utility"
#include "map"
#include "vector"
#include "fstream"
#include "sstream"
#include "ctype.h"
#include "stdlib.h"
#include "time.h"
#include "cstring"

using namespace std;

//------------------Structure----------------

typedef struct
{
    string pswd, dvsn; // pswd = password, dvsn = division
} data;

typedef struct
{
    string que, optA, optB, optC;
    char ans;
    bool used;
} quiz;

//---------------------Global varriables----------------

const char *userdata = "Data/userdata.txt";
string division[8] = {"dhaka", "khulna", "barisal", "chittagong", "mymensingh", "rajshahi", "rangpur", "sylhet"};
map<string, data> usr_pwd;
quiz prosno[50];
vector<bool> isTrap;
string usrname, prefix = "Data/", suffix = ".txt";

//----------------------Prototypes----------------------

void prompt();
void signup();
void login();
void loadData();
void loadQuiz();
int popQuiz();
void loadTraps(int);
void loadScore();
void saveScore();
void Highscore();
int random(int, int);
string ToLower(string);

//----------------------Functions-----------------------

void loadData()
{
    fstream file;
    file.open(userdata, ios::in);
    if (file)
    {
        string uuid;
        while (file >> uuid)
        {
            file >> usr_pwd[uuid].pswd >> usr_pwd[uuid].dvsn;
        }
    }
    file.close();
}

void login()
{
    string passwd;
    system("clear");
    puts("-------Login-------");

    cout << "Username: ";
    cin >> usrname;

    cout << "Password: ";
    cin >> passwd;

    if (usr_pwd[usrname].pswd == passwd)
    {
        cout << "Login success!" << endl;
        return;
    }
    else
    {
        system("clear");
        cout << "Wrong password! Try again" << endl;
        prompt();
    }
}

void signup()
{
    string passwd1, passwd2;
    int lt;

    system("clear");
    puts("------Register------");

    cout << "Username: ";
    cin >> usrname;

    if (usr_pwd.find(usrname) != usr_pwd.end())
    {
        system("clear");
        cout << "Username already exist. press 1 to login or press 2 to try again..." << endl;
        cin >> lt;
        lt == 1 ? login() : signup();
        return;
    }

LineBreak: // come here when pswd not matched

    cout << "Password: ";
    cin >> passwd1;
    cout << "Confirm password: ";
    cin >> passwd2;

    if (passwd1 == passwd2)
    {
        fstream file;
        file.open(userdata, ios::out | ios::app);
        string div;
        cout << "Division: ";
        cin >> div;

        file << usrname << " " << passwd1 << " " << ToLower(div) << endl;

        cout << "Registered successfully!" << endl;
        file.close();
    }

    else
    {
        cout << "Password doesn't match! Try again..." << endl;
        goto LineBreak;
    }
    return;
}

void prompt()
{
    int ch;
    string menu = "1: login\n2: register\n3: Quit\nEnter your choice: ";

    cout << menu;
    cin >> ch;

    switch (ch)
    {
    case 1:
        login();
        break;
    case 2:
        signup();
        break;
    case 3:
        exit(0);
        break;
    default:
        cout << "Invalid Input. Try again..." << endl;
        prompt();
        break;
    }
}

string ToLower(string s)
{
    for (char &c : s)
    {
        c = tolower(c);
    }
    return s;
}

void loadQuiz()
{
    string line;
    fstream file;
    file.open("Data/Trivia.txt", ios::in);

    if (file)
        for (int i = 0; i < 50; i++)
        {
            getline(file, prosno[i].que);
            getline(file, line);

            vector<string> options;
            string option;
            stringstream stream(line);

            while (getline(stream, option, ','))
            {
                options.push_back(option);
            }

            prosno[i].optA = options[0];
            prosno[i].optB = options[1];
            prosno[i].optC = options[2];
            prosno[i].ans = options[3][0];
            prosno[i].used = false;
        }
    file.close();
}

void loadTraps(int size)
{
    isTrap.resize(size * size);
    srand(time(0));
    int opacity;
    switch (size)
    {
    case 9:
        opacity = 20;
        break;

    case 13:
        opacity = 15;
        break;

    case 18:
        opacity = 10;
        break;
    }
    for (int i = 0; i < size * size; i++)
    {
        isTrap[i] = ((rand() % opacity) * rand() % opacity ? 0 : 1);
    }
}

void saveScore(int score)
{
    string div = prefix + usr_pwd[usrname].dvsn + suffix;

    fstream file;
    file.open(div.c_str(), ios::out | ios::app);

    if (file)
    {
        file << usrname << " " << score << endl;
    }
    file.close();
}

int random(int minN, int maxN)
{
    return (rand() % (maxN - minN)) + minN;
}

int popQuiz()
{
    cout << "~~~~~~~~Stop! You have stumbled upon a trivia. Time to test your IQ~~~~~~~~" << endl;
    int r = random(0, 49);
    cout << prosno[r].que << endl;
    cout << "(A) " << prosno[r].optA << "(B) " << prosno[r].optB << "(C) " << prosno[r].optC << endl;
    cout << "Your answer(a/b/c): " << endl;
    char c;
    cin >> c;
    prosno[r].used = true;
    return tolower(c) == prosno[r].ans ? 10 : -10;
}

bool compare(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

void Highscore()
{
    string div = prefix + usr_pwd[usrname].dvsn + suffix;
    vector<pair<string, int>> all_score;

    fstream fin;
    fin.open(div.c_str(), ios::in);

    if (fin)
    {
        string name, score;
        while (fin >> name)
        {
            fin >> score;
            all_score.push_back(make_pair(name, score));
        }
    }
    sort(all_score.begin(), all_score.end(), compare);
    cout << "--------------Leaderboard--------------" << endl;
    for (auto x : all_score)
    {
        cout << x.first << " " << x.second << endl;
    }
}