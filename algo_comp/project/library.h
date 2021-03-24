#include <bits/stdc++.h>

int **data;
int row=0, col=0;
map<int, pair<int,int>> MAP;

void printF(int n, int k)
{
    if (k == 0)
        return;

    printF(n - 1, k - 1);
    data[row][col]=n;
    MAP[n]={row,col};
    col++;
}

void printR(int n, int k)
{
    if (k == 0)
        return;

    data[row][col]=n;
    MAP[n]={row,col};
    col++;
    printR(n - 1, k - 1);
}

int** makeBoard(int n)
{
    //generate a board of n square
    data = new *int[n];
    for(int k=0; k<n; k++)
        data[k]= new int[n];

    int nn = n * n, i;
    for (i = 0; i < n; i++)
    {
        if ((i ^ n) % 2)
        {
            col=0;
            printF(nn - (n * i), n);
    
        }
        else
        {
            col=0;
            printR(nn - (n * i), n);
        
        }
        row++;
    }
    return data;
}

map<int, pair<int,int>> getMap(int n)
{
    return MAP;
}