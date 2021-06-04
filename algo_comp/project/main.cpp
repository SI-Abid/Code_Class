#include "iostream"
#include "map"
#include "vector"
#include "stdlib.h"
#include "time.h"
#include "library.h"
#include "saiham.h"
#include "tangin.h"

using namespace std;

int score = 0;
// const char *name = "userdata.txt";
string title = "<~>-<~>-<~>-<~>-<~>-<~>-<~>-<~> LADDERS UP <~>-<~>-<~>-<~>-<~>-<~>-<~>-<~>";
void play();
void Menu();

int main()
{
    system("clear");
    loadData();
    loadQuiz();
    prompt();
    Menu();
    saveScore(score);
    return 0;
}

void Menu()
{
    string menu = "1: Play\n2: Highscore (X)\n3: Quit\nEnter your option: ";
    cout << menu;
    int opt;
    cin >> opt;
    switch (opt)
    {
    case 1:
        play();
        break;
    case 2:
        Highscore();
        break;
    case 3:
        return;
        break;
    default:
        cout << "Invalid option! Try again..." << endl;
        Menu();
        break;
    }
}

void play()
{
    srand(time(0));
    int n;
    n = getDifficulty();
    loadTraps(n);
    Board gameboard(n);
    gameboard.makeBoard();
    int **board = gameboard.data;

    int pos = 1, inc;

    while (pos < n * n)
    {

        system("clear"); // for linux
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
                if(pos==board[i][j])
                {
                    cout << "| X ";
                    if (isTrap[pos])
                    {
                        cout << "Oops! You have landed on a trap..." << endl;
                        score -= 5;
                    }
                    else if (pos^rand())
                    {
                        score += popQuiz();
                    }
                    else
                    {
                        score += 5;
                    }
                }
                else
                {
                    cout<<"|   ";
                }
            }
            cout << "|" << endl;
        }
        for (int k = 0; k <= 4 * n; k++)
        {
            cout << "-";
        }
        cout << endl;

        int move = 1;
        do
        {
            if (move > 10 || move < 1)
            {
                cout << "Invalid move. Try again..." << endl;
            }
            cout << "Enter how many cell you want to move forward(1-10): ";
            cin >> move;
        } while (move > 10 || move < 1);

        pos += move;
        // printf("\033");
    }
    cout << endl;
}