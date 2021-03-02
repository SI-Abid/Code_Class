#include "bits/stdc++.h"
using namespace std;
const int SIZE=5;

struct Node{
    int data;
    Node *prev, *next;
    Node(int x) { 
        data = x;
    }
};

struct DL_List{
    Node *top;

    DL_List();  
    ~DL_List(); 
    void insertAtEnd(int data);
    int deleteFromEnd();
    int getTopData();
};

DL_List :: DL_List()
{
    top = NULL;
}

DL_List :: ~DL_List()
{
    Node *p = top;
    while(p)
    {
        top = p->prev;
        delete p;
        p = top;
    }
}

void DL_List :: insertAtEnd(int data)
{
    Node *n = new Node(data);

    if(top == NULL)
    {
        top = n;
        n->prev = NULL;
        n->next = NULL;
    }
    else
    {
        top->next = n;
        n->prev = top;
        n->next = NULL;
        top = n;
    }

}

int DL_List :: deleteFromEnd()
{
    int data;
    if(top->prev==NULL and top->next==NULL)
    {
        data = top->data;
        delete top;
        top = NULL;
    }
    else
    {
        data = top->data;
        Node *t = top;
        top = t->prev;
        top->next = NULL;
        delete t;
    }

    return data;
}

int DL_List :: getTopData()
{
    return top->data;
}

struct ListStack
{
    DL_List S;

    ListStack() {}
    void push(int data);    
    int pop();              
    int readTop();          
    bool isEmpty();
};

void ListStack :: push(int data)
{
    S.insertAtEnd(data);
    cout << data << " is pushed in the stack." << endl;
}

int ListStack :: pop()
{
    if( isEmpty() )
    {
        cout << "Stack is empty." << endl;
        return -1;
    }

    int data = S.deleteFromEnd();
    cout << data << " is popped from the stack." << endl;
    return data;
}

int ListStack :: readTop()
{
    if( isEmpty() )
    {
        cout << "Stack is empty." << endl;
        return -1;
    }

    return S.getTopData();
}

bool ListStack :: isEmpty()
{
    return (S.top == NULL);
}

struct ArrayStack
{
    int s[SIZE];
    int top;

    ArrayStack() : top(0) {}
    void push(int data);    
    int pop();              
    int readTop();          
    bool isEmpty();         
    bool isFull();    
};


void ArrayStack :: push(int data)
{
    if( isFull() )
    {
        cout << "Stack is full." << endl;
        return;
    }

    s[top] = data;
    top++;
    cout << data << " is pushed in the stack." << endl;
}

int ArrayStack :: pop()
{
    if( isEmpty() )
    {
        cout << "Stack is empty." << endl;
        return -1;
    }

    top--;
    cout << s[top] << " is popped from the stack." << endl;
    return s[top];
}


int ArrayStack :: readTop()
{
    if( isEmpty() )
    {
        cout << "Stack is empty." << endl;
        return -1;
    }

    return s[top - 1];
}


bool ArrayStack :: isEmpty()
{
    if(top == 0) return true;
    else return false;
}


bool ArrayStack :: isFull()
{
    if(top == SIZE) return true;
    else return false;
}

int main()
{
    ListStack myStack;

    myStack.push(10);
    myStack.push(20);
    cout << myStack.readTop() << endl;
    myStack.pop();
    myStack.pop();
    myStack.pop();

    ArrayStack mystack;

    mystack.push(10);
    mystack.push(20);
    cout << mystack.readTop() << endl;
    mystack.pop();
    mystack.pop();
    mystack.pop();
}