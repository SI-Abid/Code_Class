#include "bits/stdc++.h"
#include "fstream"
#include "ctype.h"
using namespace std;

//------------------Structure----------------

typedef struct
{
    string pswd, dvsn;   // pswd = password, dvsn = division
} data;

typedef struct
{
    string que, optA, optB, optC, ans;
    bool used;
} quiz;

//---------------------Global varriables-------------------

const char *filename= "userdata.txt";
map <string, data> usr_pwd;
quiz prosno[50];

//------------------Prototypes---------------

void prompt();
void signup();
void login();
void LoadData();
void loadQuiz();

string ToLower(string);

//------------------Functions----------------

void LoadData()
{
    fstream file;
    file.open(filename, ios::in);
    if(file)
    {
        string uuid;
        while(file >> uuid)
        {
            file >> usr_pwd[uuid].pswd >> usr_pwd[uuid].dvsn;
        }
    }
    file.close();
}

void login()
{
    string usrname, passwd;
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
    string usrname, passwd1, passwd2;
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
    
    LineBreak:      // come here when pswd not matched

    cout << "Password: ";
    cin >> passwd1;
    cout << "Confirm password: ";
    cin >> passwd2;
    
    if (passwd1 == passwd2)
    {
        fstream file;
        file.open(filename, ios::out | ios::app);
        string div;
        cout << "Division: "; cin >> div;

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
    for(char &c:s)
    {
        c=tolower(c);
    }
    return s;
}

void loadQuiz()
{
    string line;
    fstream file;
    file.open("Trivia.txt", ios::in);

    if(file)
    for(int i=0; i<50; i++)
    {
        getline(file, prosno[i].que);
        getline(file, line);

        vector<string> options;
        string option;
        stringstream stream(line);
        
        while(getline(stream, option, ','))
        {
            options.push_back(option);
        }
        
        prosno[i].optA = options[0];
        prosno[i].optB = options[1];
        prosno[i].optC = options[2];
        prosno[i].ans = options[3];
        prosno[i].used = false;
    }
    file.close();
    // for(int i=0; i<50; i++)
    // {
    //     cout<<prosno[i].que<<endl<<prosno[i].optA<<" "<<prosno[i].optB<<" "<<prosno[i].optC<<endl;
    //     cout<<prosno[i].ans<<" "<<(prosno[i].used?"Used":"Unused")<<endl;
    // }
}