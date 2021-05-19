#include "bits/stdc++.h"
#include "library.h"
#include "fstream"
using namespace std;

// const int n=10;
const char *filename = "data.txt";
map<string, string> usr_pwd;
fstream file;

void play();
void prompt();
void login();
void signup();

int main()
{
    string uuid;
    file.open(filename, ios::in);
    if (file)
    {
        while (file >> uuid)
        {
            file >> usr_pwd[uuid];
        }
    }
    file.close();

    prompt();
    // auto gm = gameboard.MAP;
    // for (int i = 1; i < gm.size(); i++)
    // {
    //     printf("%2d = (%d, %d)\n", i, gm[i].first, gm[i].second);
    // }
    // gameboard.
    return 0;
}

void login()
{
    string usrname, passwd;
    cout << "Username: ";
    cin >> usrname;
    cout << "Password: ";
    cin >> passwd;
    if (usr_pwd[usrname] == passwd)
    {
        cout << "Login success!" << endl;
        play();
    }
    else
    {
        cout << "Wrong password! Try again" << endl;
        prompt();
    }
}

void signup()
{
    string usrname, passwd1, passwd2;
    int lt;
    cout << "Username: ";
    cin >> usrname;
    if (usr_pwd.find(usrname) != usr_pwd.end())
    {
        cout << "Username already exist. press 1 to login or press 2 to try again..." << endl;
        cin >> lt;
        lt == 1 ? login() : signup();
    }
    cout << "Password: ";
    cin >> passwd1;
    cout << "Confirm password: ";
    cin >> passwd2;
    if (passwd1 == passwd2)
    {
        file.open(filename, ios::app);
        file << usrname << endl
             << passwd1 << endl;
        file.close();
        cout << "Registered successfully!" << endl;
        play();
    }
    else
    {
        cout << "Password doesn't match! Try again..." << endl;
        signup();
    }
}

void prompt()
{
    int ch;
    cout << "Enter your choice (1-login 2-register):";
    cin >> ch;
    switch (ch)
    {
    case 1:
        login();
        break;
    case 2:
        signup();
        break;
    default:
        cout << "Invalid Input. Try again..." << endl;
        prompt();
        break;
    }
}

void play()
{
    cout<<"Enter size: ";
    int n;
    cin >> n;
    Board gameboard(n);
    gameboard.makeBoard();
    int **board = gameboard.data;

    int pos = 1, inc;
    while (pos < n * n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k <= 4 * n; k++)
                printf("-");
            cout << endl;
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == pos)
                    printf("| X ");
                else
                    printf("|   ");
            }
            cout << "|" << endl;
        }
        for (int k = 0; k <= 4 * n; k++)
            printf("-");
        cout << endl
             << "How many cell you want to move forward: ";
        cin >> inc;
        pos += inc;
        // printf("\033");
        // system("cls");       // for windows
        system("clear"); // for linux
    }
    cout << endl;
}