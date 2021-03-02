#include "bits/stdc++.h"
using namespace std;
struct Node
{
    int data;
    Node *prev, *next;
    Node(int x)
    { 
        data = x;
    }
};
struct DL_List {
    Node *top;
    DL_List();  /// constructor
    ~DL_List(); /// destructor
    void insertAtEnd(int data);
    int deleteFromEnd();
    int getTopData();
};
DL_List :: DL_List() {
    top = NULL;
}
DL_List :: ~DL_List() {
    Node *t;
    while(top!=NULL)
    {
        t = top->next;
        delete top;
        top = t;
    }
}
void DL_List::insertAtEnd(int data) {
    Node *p = new Node(data);
    if(top==NULL)//stack is empty
    {
        top=p;
        top->next=NULL;
        top->prev=NULL;
    }
    else
    {
        p->prev=top;
        top->next=p;
        top=p;
    }
    cout<<getTopData()<<" has been pushed to the stack.\n";
}
int DL_List::deleteFromEnd()
{
    if(top == NULL)
    {
        return -1; //stack is empty
    }
    top=top->prev;
    return 1;
}
int DL_List::getTopData()
{
    if(top == NULL)
    {
        return -1; //Underflow
    }
    return top->data;
}
struct Stack
{
    DL_List S;
    Stack() {}
    void push(int data); /// to insert an element into the stack
    int pop();      /// to delete an element from the stack
    int readTop();  /// to read an element from the top of the stack
    bool isEmpty(); /// checking for Underflow
};
void Stack :: push(int data)
{
    S.insertAtEnd(data);
}
int Stack :: pop()
{
    if(!S.deleteFromEnd())
        puts("Nothing to pop. Stack is Empty.");
    
    return 0;
}
int Stack :: readTop()
{
    if(isEmpty())
        return -1;
    return S.getTopData();
}
bool Stack :: isEmpty()
{
    return (S.getTopData()==-1)? true : false;
}
int main()
{
    int MAX_SIZE=10;
    Stack stack;
    for(int i=0; i<MAX_SIZE; i++)
    {
        stack.push(i+1);
        
    }
    while(!stack.isEmpty())
    {
        cout<<"Popping "<<stack.readTop()<<endl;
        stack.pop();
    }
    puts("Stack is empty.");
    return 0;
}