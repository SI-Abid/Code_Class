#include <bits/stdc++.h>

using namespace std;

struct Queue 
{ 
    int rear, front; 
  
    int size; 
    int *arr; 
  
    Queue(int s) 
    { 
       front = rear = -1; 
       size = s; 
       arr = new int[s]; 
    } 
  
    void enQueue(int data); 
    int deQueue(); 
    void display(); 
}; 

void Queue::enQueue(int data) 
{ 
    if ((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))) 
    { 
        cout<<"Queue is Full"<<endl; 
        return; 
    } 
  
    else if (front == -1)
    { 
        front = rear = 0; 
        arr[rear] = data; 
    } 
  
    else if (rear == size-1 && front != 0) 
    { 
        rear = 0; 
        arr[rear] = data; 
    } 
    
    else
    { 
        rear++; 
        arr[rear] = data; 
    } 
} 

int Queue::deQueue() 
{ 
    if (front == -1) 
    { 
        cout<<"Queue is Empty"<<endl; 
        return 0; 
    } 
  
    int data = arr[front]; 
    arr[front] = -1; 

    if (front == rear) 
    { 
        front = -1; 
        rear = -1; 
    } 
    else if(front == size-1) 
        front = 0; 

    else
        front++; 
  
    return data; 
} 

void Queue::display() 
{ 
    if (front == -1) 
    { 
        cout<<"Queue is Empty"<<endl; 
        return; 
    } 
    cout<<"Elements in Circular Queue are: "; 
    if (rear >= front) 
    { 
        for (int i = front; i <= rear; i++) 
        {
            cout<<arr[i]<<" ";
        }
    } 
    else
    { 
        for (int i = front; i < size; i++) 
        {
            cout<<arr[i]<<" ";
        } 
  
        for (int i = 0; i <= rear; i++) 
        {
            cout<<arr[i]<<" ";
        } 
    }
    cout<<endl; 
} 

void linear_recursive(int curIndex, int arr[], int size, int data) 
{

    if (curIndex >= size) {
        cout<<data<<" not found!"<<endl;
        return;
    }

    if(arr[curIndex] == data) {
        cout<<"Item found at position "<<curIndex+1<<endl;
        return;
    }

    linear_recursive(curIndex + 1, arr, size, data);

}

void linear_non_recursive(int arr[], int size, int data)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i]==data)
        {
            cout<<"Item found at position "<<i+1<<endl;
            return;
        }
    }
    cout<<"Item not found!"<<endl;
}

void binary_recursive(int arr[], int l, int r, int data)
{
    if(l>=r)
    {
        cout<<"Item not found!"<<endl;
        return;
    }
    
    int mid=(l+r)/2;
    
    if(arr[mid]==data)
    {
        cout<<"Item found at position "<<mid+1<<endl;
        return;
    }
    
    else if(arr[mid]>data)
    {
        binary_recursive(arr, l, mid-1, data);
    }
    else
    {
        binary_recursive(arr, mid+1, r, data);
    }
}

void binary_non_recursive(int arr[], int l, int r, int data)
{
    while(l<r)
    {
        int mid=(l+r)/2;
        if(arr[mid]==data)
        {
            cout<<"Item found at position "<<mid+1<<endl;
            return;
        }
        else if(arr[mid]>data)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<"Item not found!"<<endl;
}

int main()
{
    //////////         Array implementation of circular queue          //////
    Queue q(5); 
    q.enQueue(14); 
    q.enQueue(22); 
    q.enQueue(13); 
    q.enQueue(-6); 
    q.display(); 

    cout<<"Deleted value = "<<q.deQueue()<<endl;
    cout<<"Deleted value = "<<q.deQueue()<<endl; 
  
    q.display(); 
    q.enQueue(9); 
    q.enQueue(5); 
    q.display(); 
    q.enQueue(20); 

///////////////             linear and binary search              //////

    int a[]={1,2,3,4,5,6,7,8,9,11,12,13,14,15,18,20,22,25};
    linear_recursive(0, a, 18, 13);
    linear_non_recursive(a, 18, 13);
    binary_recursive(a, 0, 18, 13);
    binary_non_recursive(a, 0, 18, 13);
    return 0;
}
