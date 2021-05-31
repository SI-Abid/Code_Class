#include "bits/stdc++.h"
#include "library.h"
#include "saiham.h"
#include "tangin.h"
#include "akter.h"
#include "sakhawat.h"

using namespace std;

// const int n=10;
// const char *name = "userdata.txt";
string title = "<~>-<~>-<~>-<~>-<~>-<~>-<~>-<~> LADDERS UP <~>-<~>-<~>-<~>-<~>-<~>-<~>-<~>";
void play();
void Menu();

int main()
{
    system("clear");
    
    // LoadData();
    // prompt();
    // // LoadData();

    // // for(auto X : usr_pwd)
    // // {
    // //     cout << X.first << " " << X.second.pswd<<" "<<X.second.dvsn<<endl;
    // // }

    // Menu();
    loadQuiz();
    return 0;
}

void Menu()
{
    string menu = "1: Play\n2: Highscore (X)\n3: Quit\nEnter your option: ";
    cout << menu;
    int opt;
    cin >> opt;
    switch(opt)
    {
        case 1:
            play();
            break;
        case 2:
            Highscore();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Invalid option! Try again..." << endl;
            Menu();
            break;
    }
}

void play()
{
    int n;
    n = getDifficulty();
    vector<bool> isTrap = traps(n);
    Board gameboard(n);
    gameboard.makeBoard();
    int **board = gameboard.data;

    int pos = 1, inc;

    while (pos < n * n)
    {
        
        system("clear");        // for linux
        // system("cls");       // for windows
        cout << title << endl;

        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k <= 4 * n; k++)
            {
                printf("-");
            }
            cout << endl;
            
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == pos)
                    printf("| X ");
                else if(isTrap[board[i][j]])
                    printf("| 0 ");
                else
                    printf("|   ");
            }
            cout << "|" << endl;
        }
        for (int k = 0; k <= 4 * n; k++)
        {
            printf("-");
        }
        cout << endl
             << "How many cell you want to move forward: ";
        cin >> inc;
        pos += inc;

        // printf("\033");
    }
    cout << endl;
}
