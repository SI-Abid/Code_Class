#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct CircularLinkedList
{
    Node *head;
    int nodeCount;

    CircularLinkedList();

    void Insert(int val);
    void Traverse();
    void Delete(int position);
};

CircularLinkedList ::CircularLinkedList()
{
    head = NULL;
    nodeCount = 0;
}

void CircularLinkedList ::Insert(int val)
{
    Node *n = new Node(val);

    if (head == NULL)
    {
        head = n;
        n->next = head;
    }
    else
    {
        Node *x = head;

        while (x->next != head)
        {
            x = x->next;
        }
        x->next = n;
        n->next = head;
    }
    nodeCount++;
}

void CircularLinkedList ::Traverse()
{
    Node *x = head;

    while (x->next != head)
    {
        cout << x->data << " ==> ";
        x = x->next;
    }
    cout << x->data << endl;
}

void CircularLinkedList ::Delete (int position)
{
    if (position == 1)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
        }
        else
        {
            Node *x = head;
            while (x->next != head)
            {
                x = x->next;
            }
            x->next = head->next;
            head = head->next;
        }
    }
    else if (nodeCount == position)
    {
        Node *x = head;

        int i = 1;
        while (i < position - 1)
        {
            x = x->next;
            i++;
        }
        x->next = head;
    }
    else
    {
        Node *x = head;

        int i = 1;
        while (i < position - 1)
        {
            x = x->next;
            i++;
        }
        Node *temp = x->next;
        x->next = temp->next;
    }
    nodeCount--;
}

CircularLinkedList Create_list()
{
    CircularLinkedList _list_;
    for(int i=10; i<=50; i+=10)
    {
        _list_.Insert(i);
    }
    return _list_;
}

int main()
{
    auto LIST = Create_list();
    LIST.Traverse();
    LIST.Insert(5);
    LIST.Traverse();
    LIST.Delete(2);
    LIST.Insert(18);
    LIST.Traverse();
    LIST.Insert(5);
    LIST.Traverse();
    LIST.Delete(1);
    LIST.Insert(18);
    LIST.Traverse();

    return 0;
}