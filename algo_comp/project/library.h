#include <bits/stdc++.h>
using namespace std;

class Board
{
private:
    int row = 1, col = 1, n;

public:

    int **data;
    vector<pair<int, int>> MAP;

    Board(int);
    ~Board();

    void makeBoard()
    {
        //generate a board of n square
        int nn=n*n, i;
        for (i = 0; i < n; i++)
        {
            if ((i ^ n) % 2)
            {
                col = 1;
                setF(nn - (n * i), n);
            }
            else
            {
                col = 1;
                setR(nn - (n * i), n);
            }
            row++;
        }
        // return data;
    }

    void setF(int n,int k)
    {
        if (k == 0)
            return;

        setF(n - 1, k - 1);
        data[row-1][col-1] = n;
        MAP[n] = {row, col};
        col++;
    }

    void setR(int n, int k)
    {
        if (k == 0)
            return;

        data[row-1][col-1] = n;
        MAP[n] = {row, col};
        col++;
        setR(n - 1, k - 1);
    }
    // map<int, pair<int, int>> getMap(int n)
    // {
    //     return this->MAP;
    // }
};

Board::Board(int x)
{
    n=x;
    MAP.resize(x*x+1);
    data = new int *[x];
    for (int k = 0; k < x; k++)
        data[k] = new int[x];
}

Board::~Board()
{
    for (int i = 0; i < n; i++)
        delete data[i];
    delete data;
}
