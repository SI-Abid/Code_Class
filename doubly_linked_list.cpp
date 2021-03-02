
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *prev, *next;
    Node(int x) { /// constructor
        data = x;
    }
};


struct DL_List{
    Node *head, *tail;

    DL_List();  /// constructor
    ~DL_List(); /// destructor
    int getLength();
    void display();
    void reverseDisplay();
    void insertAtBeginning(int data);
    void insertAtEnd(int data);
    void insertAtLoc(int loc, int data);
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteFromLoc(int loc);
    int findLoc(int data);
};


DL_List :: DL_List()
{
    head = tail = NULL;
}


DL_List :: ~DL_List()
{
    Node *p = head;
    while(p)
    {
        head = p->next;
        delete p;
        p = head;
    }
}


int DL_List :: getLength()
{
    int len = 0;

    Node *t = head;
    while(t)
    {
        len++;
        t = t->next;
    }

    return len;
}


void DL_List :: display()
{
    cout << "The list is: ";

    Node *t = head;
    while(t)
    {
        cout << t->data << " <-> ";
        t = t->next;
    }
    cout << "NULL" << endl;
}


void DL_List :: reverseDisplay()
{
    cout << "The list in reverse order: ";

    Node *t = tail;
    while(t)
    {
        cout << t->data << " <-> ";
        t = t->prev;
    }
    cout << "NULL" << endl;
}


void DL_List :: insertAtBeginning(int data)
{
    Node *n = new Node(data);

    if(head == NULL)
    {
        head = tail = n;
        n->prev = NULL;
        n->next = NULL;
    }
    else
    {
        n->next = head;
        head->prev = n;
        n->prev = NULL;
        head = n;
    }

    cout << data << " is inserted at the beginning." << endl;
}


void DL_List :: insertAtEnd(int data)
{
    Node *n = new Node(data);

    if(head == NULL)
    {
        head = tail = n;
        n->prev = NULL;
        n->next = NULL;
    }
    else
    {
        tail->next = n;
        n->prev = tail;
        n->next = NULL;
        tail = n;
    }

    cout << data << " is inserted at the end." << endl;
}


void DL_List :: insertAtLoc(int loc, int data)
{
    if(loc<1 || loc>getLength()+1)
    {
        cout << "Invalid location specified. Nothing inserted." << endl;
        return;
    }
    if(loc == 1)
    {
        insertAtBeginning(data);
        return;
    }
    if(loc == getLength()+1)
    {
        insertAtEnd(data);
        return;
    }

    Node *n = new Node(data);
    Node *t = head;         /// node before loc
    for(int i=2; i<loc; i++)
        t = t->next;

    Node *s = t->next;      /// node after loc
    t->next = n;
    n->prev = t;
    n->next = s;
    s->prev = n;

    cout << data << " is inserted at location " << loc << endl;
}


void DL_List :: deleteFromBeginning()
{
    if(head == NULL)
    {
        cout << "Nothing deleted, the list is empty." << endl;
        return;
    }

    int data;
    if(head == tail)
    {
        data = head->data;
        delete head;
        head = tail = NULL;
    }
    else
    {
        data = head->data;
        Node *t = head;
        head = t->next;
        head->prev = NULL;
        delete t;
    }

    cout << data << " is deleted from the beginning." << endl;
}


void DL_List :: deleteFromEnd()
{
    if(tail == NULL)
    {
        cout << "Nothing deleted, the list is empty." << endl;
        return;
    }

    int data;
    if(head == tail)
    {
        data = tail->data;
        delete tail;
        head = tail = NULL;
    }
    else
    {
        data = tail->data;
        Node *t = tail;
        tail = t->prev;
        tail->next = NULL;
        delete t;
    }

    cout << data << " is deleted from the end." << endl;
}


void DL_List :: deleteFromLoc(int loc)
{
    if(loc<1 || loc>getLength())
    {
        cout << "Invalid location specified. Nothing deleted." << endl;
        return;
    }
    if(loc == 1)
    {
        deleteFromBeginning();
        return;
    }
    if(loc == getLength())
    {
        deleteFromEnd();
        return;
    }

    Node *t = head;
    for(int i=2; i<=loc; i++)
        t = t->next;
    (t->prev)->next = t->next;
    (t->next)->prev = t->prev;

    int data = t->data;
    delete t;
    cout << data << " is deleted from location " << loc << endl;
}


int DL_List :: findLoc(int data)
{
    Node *t = head;
    int loc = 1;

    while(t)
    {
        if(t->data == data)
            return loc;
        t = t->next;
        loc++;
    }
    return -1;
}


int main()
{
    DL_List myList;
    int choice, val, loc, item;

    srand( time(0) );
    for(int i=1; i<=5; i++)
        myList.insertAtEnd( rand() % 50 );
    cout << endl << endl;

    while(1)
    {
        cout << "\t:: Doubly Linked List Operations ::" << endl << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert at a specific location" << endl;
        cout << "4. Delete from the beginning" << endl;
        cout << "5. Delete from the end" << endl;
        cout << "6. Delete from a specific location" << endl;
        cout << "7. Search an item" << endl;
        cout << "8. Print the list in reverse order" << endl;
        cout << "9. Exit" << endl << endl;
        myList.display();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
        case 1:
            cout << "Enter a value: ";
            cin >> val;
            myList.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter a value: ";
            cin >> val;
            myList.insertAtEnd(val);
            break;
        case 3:
            cout << "Enter a value: ";
            cin >> val;
            cout << "Enter location: ";
            cin >> loc;
            myList.insertAtLoc(loc, val);
            break;
        case 4:
            myList.deleteFromBeginning();
            break;
        case 5:
            myList.deleteFromEnd();
            break;
        case 6:
            cout << "Enter location: ";
            cin >> loc;
            myList.deleteFromLoc(loc);
            break;
        case 7:
            cout << "Enter a value: ";
            cin >> val;
            loc = myList.findLoc(val);
            if(loc == -1) cout << "Item not found." << endl;
            else cout << "Item found at location " << loc << endl;
            break;
        case 8:
            myList.reverseDisplay();
            break;
        case 9:
            exit(0);
        }

        if(choice != 8) myList.display();
        
        cin.get();
        cout << endl << "Press any key to continue ...";
        cin.get();
        printf("\033c"); 	// for linux only
    }

    return 0;
}