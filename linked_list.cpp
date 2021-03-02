#include "bits/stdc++.h"
using namespace std;
struct Node{
    int data;
    Node *next;
};

struct LinkedList{
    Node *head;

    LinkedList();  /// constructor
    ~LinkedList(); /// destructor
    void display();
    void insertAtBeginning(int data);
    void insertAtEnd(int data);
    void insertAtLoc(int loc, int data);
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteFromLoc(int loc);
    void reverseDisplay();
};


LinkedList :: LinkedList()
{
    head = NULL;
}


LinkedList :: ~LinkedList()
{
    Node *temp;

    while(head != NULL)
    {
        temp = head->next;
        delete head;
        head = temp;
    }
}


void LinkedList :: display()
{
    cout << "The list is: ";
    if(head == NULL)
    {
        cout << "empty" << endl;
        return;
    }

    Node *t = head;
    while(t != NULL)
    {
        cout << t->data << " -> ";
        t = t->next;
    }
    cout << "NULL" << endl << endl;
}


void LinkedList :: insertAtBeginning(int data)
{
    Node *p = new Node;
    p->data = data;
    p->next = head;

    head = p;

    cout << data << " is inserted at the beginning." << endl;
}


void LinkedList :: insertAtEnd(int data)
{
    Node *p = new Node;
    p->data = data;
    p->next = NULL;

    Node *r = head;

    if(head == NULL)
    {
        head = p;
    }
    else
    {
        while(r->next != NULL)
        {
            r = r->next;
        }
        r->next = p;
    }

    cout << data << " is inserted at the end." << endl;
}


void LinkedList :: insertAtLoc(int loc, int data)
{
    if(loc == 1)
    {
        insertAtBeginning(data);
        return;
    }

    Node *p = new Node;
    p->data = data;

    Node *r = head; /// head is at loc#1
    for(int i=2; i<loc; i++)
    {
        r = r->next;
    }
    Node *s = r->next;
    r->next = p;
    p->next = s;

    cout << data << " is inserted at location " << loc << endl;
}


void LinkedList :: deleteFromBeginning()
{
    if(head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *p = head;
    head = head->next;

    int data = p->data;
    delete p;
    cout << data << " is deleted from the beginning." << endl;
}


void LinkedList :: deleteFromEnd()
{
    if(head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *n = head;
    if(n->next == NULL) /// the list contains only 1 node
    {
        int data = n->data;
        head = NULL;
        delete n;
        cout << data << " deleted from the end." << endl;
        return;
    }

    Node *s; /// previous node of n
    while(n->next != NULL)
    {
        s = n;
        n = n->next;
    }
    s->next = NULL;

    int data = n->data;
    delete n;
    cout << data << " is deleted from the end." << endl;
}


void LinkedList :: deleteFromLoc(int loc)
{
    if(loc == 1)
    {
        deleteFromBeginning();
        return;
    }

    Node *r = head;
    for(int i=2; i<loc; i++)
    {
        r = r->next;
    }
    Node *s = r->next;
    Node *t = s->next;
    r->next = t;

    int data = s->data;
    delete s;
    cout << data << " is deleted from location " << loc << endl;
}

int main()
{
    LinkedList myList;
    myList.display();

    srand( time(0) );
    for(int i=1; i<=5; i++)
        myList.insertAtEnd( rand() % 50 );
    myList.display();

    myList.insertAtBeginning(100);
    myList.display();

    myList.insertAtLoc(3, 75);
    myList.display();

    myList.deleteFromBeginning();
    myList.display();

    myList.deleteFromEnd();
    myList.display();

    // myList.deleteFromLoc(3);
    // myList.display();

    myList.reverseDisplay();

    return 0;
}