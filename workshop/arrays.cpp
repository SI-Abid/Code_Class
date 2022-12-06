#include <bits/stdc++.h>
using namespace std;

// Print from index 0 to len(cir) - 1
void printFullLinear(int *cirArry, int len)
{ // Easy

    // int size = sizeof(cirArry)/sizeof(cirArry[0]);
    cout << "size " << len << "\n";
    for (int i = 0; i < len; i++)
    {

        cout << cirArry[i % len] << " ";
    }
}

// Print from start index and total size elements
void printForward(int cirArry[])
{ // Easy
  // To Do
  // return ;
}

void printBackward(int cirArry[], int len)
{ // Easy
    for (int i = len - 1; i >= 0; i--)
    {

        cout << cirArry[i % len] << " ";
    }
}

// remove all zeros and return a new arry with no zeros
int *linearize(int cirArry[], int &len)
{
    int newLen = 0;
    for (int i = 0; i < len; i++)
    {
        if (cirArry[i])
            newLen++;
    }
    int *newArry= new int[newLen];
    for (int i = 0, j = 0; j < newLen; i++)
    {
        if (cirArry)
        {
            newArry[j] = cirArry[i];
            j++;
        }
    }
    len=newLen;
    return newArry;
}

// Do not change the Start index and return a resized new array
// initialize new cells with zeros
int *resizeStartUnchanged(int cirArry[], int newcapacity)
{
    int *newArry = new int[newcapacity];
    for (int i = 0; i < newcapacity; i++)
    {
        newArry[i] = 0;
    }
    for (int i = 0; i < newcapacity; i++)
    {
        newArry[i] = cirArry[i];
    }
    return newArry;
}

// This method will shift the values n index left and print the new array
void shiftLeft(int cirArry[], int n, int len)
{ // Hard

    int newarr[len];
    for (int i = n, j = 0; i < len + n; i++, j++)
    {

        cout << cirArry[i % len] << " ";
        newarr[j] = cirArry[i % len];
    }
}

// This method will shift the values n index right and print the new array
void shiftRight(int cirArry[])
{ // Medium
  // To Do
  // return ;
}

// This method will check the given array across the base array and if they are equivalent interms of values //return ; true, or else //return ; false
bool equivalent(int cirArry[], int cir_arr[])
{
    int len = sizeof(cirArry) / sizeof(cirArry[0]);
    int len2 = sizeof(cir_arr) / sizeof(cir_arr[0]);
    if (len != len2)
    {
        return false;
    }
    for (int i = 0; i < len; i++)
    {
        if (cirArry[i] != cir_arr[i])
        {
            return false;
        }
    }
    return true;
}

// the method take another circular array and returns a linear array containing the common elements between the two circular arrays.
void intersection(int cirArry[], int c2)
{
    int len = sizeof(cirArry) / sizeof(cirArry[0]);
    int len2 = sizeof(c2) / sizeof(c2[0]);
    int newlen = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (cirArry[i] == c2[j])
            {
                newlen++;
            }
        }
    }
    int *newArry = new int[newlen];
    for (int i = 0, j = 0; i < len; i++)
    {
        for (int k = 0; k < len2; k++)
        {
            if (cirArry[i] == c2[k])
            {
                newArry[j] = cirArry[i];
                j++;
            }
        }
    }
    printFullLinear(newArry, newlen);
}

int main()
{

    int start = 0;
    int len = 9;
    int cirArry[] = {43, 5, 65, 23, 0, 3, 5, 9, 9};
    printFullLinear(cirArry, len);
    cout << "\n";
    printBackward(cirArry, len);
    cout << "\n";
    cout << "\nshifted array ";
    shiftLeft(cirArry, 3, len);
    int newLen=len;
    int *newArry=linearize(cirArry,newLen);
    printFullLinear(newArry,newLen);
    int *newArry2=resizeStartUnchanged(cirArry,10);
    printFullLinear(newArry2,10);
    int cir_arr[] = {43, 5, 65, 23, 0, 3, 5, 9, 9};
    cout << equivalent(cirArry, cir_arr);
    int c2[] = {43, 5, 65, 23, 0, 3, 5, 9, 9};
    intersection(cirArry, c2);
    return 0;
}