#include "bits/stdc++.h"
using namespace std;
struct Node
{
    int data;
    Node *next, *prev;
    Node(int x)
    {
        data=x;
        next=prev=NULL;
    }
};
struct DL_List
{
    int size;
    Node *head, *tail;

    DL_List();
    ~DL_List();

    void Insert(int data);
    void Delete(int pos);
    void Traverse();
};
DL_List :: DL_List()
{
    size=0;
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
DL_List Create_list()
{
    DL_List list;
    for (int i = 2; i <= 32; i*=2)
    {
        list.Insert(i);
    }
    return list;
}
void DL_List :: Insert(int data)
{
    Node *p = new Node(data);
    if(head==NULL)
    {
        head=tail=p;
        return;
    }
    tail->next=p;
    p->prev=tail;
    tail=p;

    size++;
}
void DL_List :: Delete(int pos)
{
    if(head==NULL)
    {
        cout<<"List is empty..."<<endl;
        return;
    }
    if(pos<1 || pos>size)
    {
        cout << "Invalid location specified. Nothing deleted." << endl;
        return;
    }
    if(size==1)
    {
        head=tail=NULL;
        return;
    }
    Node *tmp = head;
    for(int i=2; i<=pos; i++)
    {
        tmp=tmp->next;
    }
    tmp->prev->next=tmp->next;
    tmp->next->prev=tmp->prev;

    delete tmp;
}
void DL_List :: Traverse()
{
    Node *t=head;
    cout<<"(head)";
    while(t!=NULL)
    {
        cout<<t->data<<" <==> ";
        t=t->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    auto LIST = Create_list();
    LIST.Traverse();
    LIST.Insert(26);
    LIST.Traverse();
    LIST.Delete(3);
    LIST.Insert(40);
    LIST.Traverse();
    return 0;
}