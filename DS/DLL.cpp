#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int data;
    Node *prev, *next;
    Node(int x) //constructor
    {
        data=x;
    }
};

struct DL_List
{
    Node *head, *tail;
    DL_List();  //constructor
    ~DL_List(); //destructor
    int getLength();
    void display();
    void insertAtBeginning(int data);
    void insertAtEnd(int data);
    void insertAtLoc(int loc, int data);
    void insertAfterValue(int val, int data);
    void insertBeforeValue(int val, int data);
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteFromLoc(int loc);
    int findLoc(int data);

};

DL_List :: DL_List()
{
    head = tail = NULL;
}

int main()
{

}