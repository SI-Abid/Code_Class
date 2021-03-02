#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

struct Linked_List
{
    int size;
    Node *head;

    Linked_List();
    ~Linked_List();

    void Insert(int data);
    void Delete(int pos);
    void Traverse();
};

Linked_List :: Linked_List()
{
    size=0;
    head = NULL;
}

Linked_List :: ~Linked_List()
{
    Node *t;

    while(head != NULL)
    {
        t = head->next;
        delete head;
        head = t;
    }
}

Linked_List Create_list()       //creating a list with 5 element: 10 20 30 40 50
{
    Linked_List list;

    for(int i=10; i<=50; i+=10)
    {
        list.Insert(i);
    }

    return list;
}

void Linked_List :: Insert(int data)
{
    Node *new_node = new Node(data);

    if(head==NULL)
    {
        head=new_node;
        return;
    }

    Node *cur = head;

    while(cur->next!=NULL)
    {
        cur=cur->next;
    }

    cur->next=new_node;
    size++;
}

void Linked_List :: Delete(int pos)
{
    if(head==NULL)
    {
        puts("List is Empty!");
        return;
    }
    if(pos<1 || pos>size)
    {
        cout << "Invalid location specified. Nothing deleted." << endl;
        return;
    }

    if(pos==1)
    {
        head=head->next;
        return;
    }

    Node *cur=head;

    for(int i=2; i<pos; i++)
    {
        cur=cur->next;
    }

    cur->next=(cur->next)->next;
    size--;
}

void Linked_List :: Traverse()
{
    Node *c=head;
    cout<<"(head)";
    while(c!=NULL)
    {
        cout<<c->data<<" ==> ";
        c=c->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    Linked_List LIST = Create_list();

    LIST.Traverse();
    LIST.Insert(100);
    LIST.Delete(2);
    LIST.Traverse();
    LIST.Insert(60);
    LIST.Traverse();
    LIST.Delete(1);
    LIST.Traverse();

    return 0;
}