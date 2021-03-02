#include<bits/stdc++.h> 
using namespace std; 
  

int main() 
{ 
    Queue q(5); 
    q.enQueue(14); 
    q.enQueue(22); 
    q.enQueue(13); 
    q.enQueue(-6); 
  
    q.display(); 

    printf("\nDeleted value = %d", q.deQueue()); 
    printf("\nDeleted value = %d", q.deQueue()); 
  
    q.display(); 
  
    q.enQueue(9); 
    q.enQueue(5); 
  
    q.display(); 
  
    q.enQueue(20); 
    return 0; 
} 