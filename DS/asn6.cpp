/****************************************************
*	Assignment-6									*
*	============									*
*													*
*	Prepared By: Group - NULL						*
*	1.					    						*
*	2. 												*
*	3.												*
*	4.												*
*													*
*	Date of Submission: 							*
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};


struct LinkedList{
    Node *head;
    int totalCount;

    LinkedList();  /// constructor
    ~LinkedList(); /// destructor
    void display();
    void insertAtBeginning(int data);
    void insertAtEnd(int data);
    void insertAtLoc(int loc, int data);
    void insertAfterValue(int val, int data);
    void insertBeforeValue(int val, int data);
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteFromLoc(int loc);
    void deleteList();
    void reverseList();
    void addList();
    int findLoc(int data);
    void replicate(int n);
    void deleteAllBut(int data);
    void printReverse();
};


LinkedList :: LinkedList()
{
    head = NULL;
    totalCount = 0;
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
    // cout << "The list is: ";
    // if(head == NULL)
    // {
    //     cout << "empty" << endl;
    //     return;
    // }

    Node *t = new Node;
    t = head;
    while(t != NULL)
    {
        cout << t->data << " -> ";
        t = t->next;
    }
    cout << "NULL" << endl << endl;
}

void LinkedList :: reverseList()
{
    if(head==NULL || head->next==NULL)
    {
        cout << "Nothing to reverse." << endl;
        return;
    }

    Node *p = new Node; /// previous pointer
    Node *c = new Node; /// current pointer
    Node *n = new Node; /// next pointer

    p = NULL;
    c = head;
    while(c != NULL)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    head = p;
    cout << "List is reversed." << endl;
}

void LinkedList :: insertAtBeginning(int data)
{
    Node *p = new Node;
    p->data = data;
    p->next = head;

    head = p;

    cout << data << " is inserted at the beginning." << endl;
    totalCount++;
}


void LinkedList :: insertAtEnd(int data)
{
    Node *p = new Node; /// node to be inserted
    Node *r = new Node; /// pointer to the current last node

    p->data = data;
    p->next = NULL;

    r = head;

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
    totalCount++;
}


void LinkedList :: insertAtLoc(int loc, int data)
{
    if(loc == 1)
    {
        insertAtBeginning(data);
        return;
    }
    if(loc == totalCount+1)
    {
        insertAtEnd(data);
        return;
    }
    if(loc<1 || loc>totalCount+1)
    {
        cout << "Invalid location specified. No data inserted." << endl;
        return;
    }

    Node *p = new Node; /// node to be inserted
    p->data = data;

    Node *r = new Node; /// node before loc
    Node *s = new Node; /// node after loc

    r = head; /// head is at loc#1
    for(int i=2; i<loc; i++)
    {
        r = r->next;
    }
    s = r->next;
    r->next = p;
    p->next = s;

    cout << data << " is inserted at location " << loc << endl;
    totalCount++;
}


void LinkedList :: insertAfterValue(int val, int data)
{
    bool isFound = false;
    Node *p = new Node; /// node to be inserted
    Node *r = new Node; /// node containg val
    Node *s = new Node; /// node after r

    r = head;
    while(r != NULL)
    {
        if(r->data == val)
        {
            isFound = true;
            break;
        }
        r = r->next;
    }

    if(isFound)
    {
        p->data = data;
        s = r->next;
        r->next = p;
        p->next = s;
        cout << data << " is inserted after " << val << "." << endl;
        totalCount++;
    }
    else
        cout << "Value not found. No data inserted." << endl;
}


void LinkedList :: insertBeforeValue(int val, int data)
{
    bool isFound = false;
    Node *p = new Node; /// node to be inserted
    Node *r = new Node; /// node containing val
    Node *s = new Node; /// node before r

    r = head;
    while(r != NULL)
    {
        if(r->data == val)
        {
            isFound = true;
            break;
        }
        s = r;
        r = r->next;
    }

    if(isFound)
    {
        if(r == head)
        {
            insertAtBeginning(data);
            return;
        }
        p->data = data;
        s->next = p;
        p->next = r;
        cout << data << " is inserted before " << val << "." << endl;
        totalCount++;
    }
    else
        cout << "Value not found. Not data inserted." << endl;
}


void LinkedList :: deleteFromBeginning()
{
    if(head == NULL)
    {
        cout << "Nothing to delete. List is empty." << endl;
        return;
    }

    Node *p = new Node;
    p = head;
    head = head->next;

    int data = p->data;
    delete p;
    cout << data << " is deleted from the beginning." << endl;
    totalCount--;
}


void LinkedList :: deleteFromEnd()
{
    if(head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *n = new Node;
    Node *prev = new Node;

    n = head;
    if(n->next == NULL)
    {
        int data = n->data;
        head = NULL;
        delete n;
        cout << data << " deleted from the end." << endl;
        totalCount--;
        return;
    }

    while(n->next != NULL)
    {
        prev = n;
        n = n->next;
    }
    prev->next = NULL;

    int data = n->data;
    delete n;
    cout << data << " is deleted from the end." << endl;
    totalCount--;
}


void LinkedList :: deleteFromLoc(int loc)
{
    if(loc == 1)
    {
        deleteFromBeginning();
        return;
    }
    if(loc == totalCount)
    {
        deleteFromEnd();
        return;
    }
    if(loc<1 || loc>totalCount)
    {
        cout << "Invalid location specified. No data deleted." << endl;
        return;
    }

    Node *r = new Node; /// node before s
    Node *s = new Node; /// node to be deleted
    Node *t = new Node; /// node after s

    r = head;
    for(int i=2; i<loc; i++)
    {
        r = r->next;
    }
    s = r->next;
    t = s->next;
    r->next = t;

    int data = s->data;
    delete s;
    cout << data << " is deleted from location " << loc << endl;
    totalCount--;
}


void LinkedList :: deleteList()
{
    Node *temp;

    while(head != NULL)
    {
        temp = head->next;
        delete head;
        head = temp;
    }

    cout << "List Deleted." << endl;
}

void LinkedList :: addList()
{
	Node *h = head;
    int sum=0;
    if(h == NULL)
    {
        puts("List is empty. Nothing to add.");
        return;
    }
    else if(h->next == NULL)
    {
        cout<<"Sum of List is "<<h->data<<endl;
        return;
    }
    while(h != NULL)
    {
        sum+=h->data;
        h=h->next;
    }
    cout<<"Sum of List is "<<sum<<endl;
    return;
}


int LinkedList :: findLoc(int data)
{
    Node *h = head;
    int loc = 1;

    while(h)
    {
        if(h->data == data)
            return loc;
        h = h->next;
        loc++;
    }
    return -1;

}

void reverse_print_recursion(Node *list) {
   if(list == NULL) {
      printf("NULL ");
      return;
   }
   
   reverse_print_recursion(list->next);
   printf("-> %d ",list->data);
   
}

void LinkedList :: printReverse()
{
    reverse_print_recursion(head);
}

void LinkedList :: replicate(int n)
{

}


void LinkedList :: deleteAllBut(int d)
{
    Node *temp, *newHead;
    bool stored=false;

    while(head != NULL)
    {
        temp = head->next;
        if(head->data!=d)
        {
            delete head;
        }                           // break point
        else if(!stored)
        {
            newHead = head;
            stored=true;
        }
        head = temp;
    }
    head = newHead;
    cout << "List Deleted except " <<d<<"."<< endl;
}


int main()
{
    LinkedList myList;
    int choice, val, loc, item;

    srand( time(0) );
    for(int i=1; i<=5; i++)
        myList.insertAtEnd( rand() % 50 );
    cout << endl << endl;

    while(1)
    {
        cout << "\t:: Singly Linked List Operations ::" << endl << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert at a specific location" << endl;
        cout << "4. Insert after a specific value" << endl;
        cout << "5. Insert before a specific value" << endl;
        cout << "6. Delete from the beginning" << endl;
        cout << "7. Delete from the end" << endl;
        cout << "8. Delete from a specific location" << endl;
        cout << "9. Delete the list" << endl;
        cout << "10. Reverse the list" << endl;
        cout << "11. Add all the elements of the list" << endl;
        cout << "12. Search for an item" << endl;
        cout << "13. Replicate the list" << endl;
        cout << "14. Remove all but a specific item" << endl;
        cout << "15. Print the list in reverse order" << endl;
        cout << "16. Exit" << endl << endl;
        myList.display();
        cout << "Enter your choice: ";
        cin >> choice;

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
            cout << "Enter the value: ";
            cin >> val;
            cout << "Enter the item: ";
            cin >> item;
            myList.insertAfterValue(val, item);
            break;
        case 5:
            cout << "Enter the value: ";
            cin >> val;
            cout << "Enter the item: ";
            cin >> item;
            myList.insertBeforeValue(val, item);
            break;
        case 6:
            myList.deleteFromBeginning();
            break;
        case 7:
            myList.deleteFromEnd();
            break;
        case 8:
            cout << "Enter location: ";
            cin >> loc;
            myList.deleteFromLoc(loc);
            break;
        case 9:
            myList.deleteList();
            break;
        case 10:
            myList.reverseList();
            break;
        case 11:
            myList.addList();
            break;
        case 12:
            cout << "Enter a value: ";
            cin >> val;
            loc = myList.findLoc(val);
            if(loc == -1) cout << "Item not found." << endl;
            else cout << "Item found at location " << loc << endl;
            break;
        case 13:
            cout << "How many times? ";
            int n; cin >> n;
            myList.replicate(n);
            break;
        case 14:
            cout << "Enter a value: ";
            cin >> val;
            myList.deleteAllBut(val);
            break;
        case 15:
            cout << "The list in reverse order: ";
            myList.printReverse();
            cout << endl;
            break;
        case 16:
            exit(0);
        }

        if(choice != 15) myList.display();
        cin.get();
        cout << "Press any key to continue ...";
        cin.get();
        // printf("\033c"); 	// for linux only
    }

    return 0;
}