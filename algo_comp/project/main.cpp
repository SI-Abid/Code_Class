#include "bits/stdc++.h"
#include "library.h"
using namespace std;

// const int n=10;

int main()
{
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
            for (int k = 0; k < 5 * n; k++)
                printf("-");
            cout << endl;
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == pos)
                    printf("| X |");
                else
                    printf("|   |");
            }
            cout << endl;
        }
        for (int k = 0; k < 5 * n; k++)
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
    auto gm = gameboard.MAP;
    for (int i = 1; i < gm.size(); i++)
    {
        printf("%2d = (%d, %d)\n", i, gm[i].first, gm[i].second);
    }
    // gameboard.
    return 0;
}