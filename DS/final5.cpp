#include <bits/stdc++.h>
using namespace std;

#define N 3

struct ArrayQueue
{
	int head, tail;
	int q[N];

	ArrayQueue();
	void enqueue(int data);
	int dequeue();
	void display();
	bool isEmpty();
	bool isFull();
};

ArrayQueue ::ArrayQueue()
{
	head = tail = -1;
}

void ArrayQueue ::enqueue(int data)
{
	if (isFull())
	{
		cout << "Queue is full." << endl;
		return;
	}

	if (isEmpty())
	{
		head = 0;
	}

	tail = (tail + 1) % N;
	q[tail] = data;
	cout << data << " is inserted in the queue." << endl;
}

int ArrayQueue ::dequeue()
{
	if (isEmpty())
	{
		cout << "Queue is empty." << endl;
		return -1;
	}

	int data = q[head];
	cout << data << " is deleted from the queue." << endl;

	if (head == tail)
	{
		head = tail = -1;
	}
	else
	{
		head = (head + 1) % N;
	}

	return data;
}

void ArrayQueue ::display()
{
	cout << "The queue is (N=" << N << " h=" << head << " t=" << tail << "):";
	if (isEmpty())
	{
		cout << " empty" << endl
			 << endl;
		return;
	}

	int len = (head <= tail) ? (tail - head + 1) : (N - head) + (tail + 1);
	for (int i = head; len--; i = (i + 1) % N)
	{
		cout << " " << q[i];
	}
	cout << endl
		 << endl;
}

bool ArrayQueue ::isEmpty()
{
	return (head == -1);
}

bool ArrayQueue ::isFull()
{
	return (tail + 1) % N == head;
}

struct Node
{
	int data;
	Node *prev, *next;
	Node(int x)
	{ /// constructor
		data = x;
	}
};

struct DL_List
{
	Node *head, *tail;

	DL_List();	/// constructor
	~DL_List(); /// destructor
	void insertAtEnd(int data);
	int deleteFromBeginning();
	void printList();
};

struct ListQueue
{
	DL_List Q;

	ListQueue() {}
	void enqueue(int data);
	int dequeue();
	void display();
	bool isEmpty();
};

DL_List ::DL_List()
{
	head = tail = NULL;
}

DL_List ::~DL_List()
{
	Node *p = head;
	while (p)
	{
		head = p->next;
		delete p;
		p = head;
	}
}

void DL_List ::insertAtEnd(int data)
{
	Node *n = new Node(data);

	if (head == NULL)
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
}

int DL_List ::deleteFromBeginning()
{
	int data = head->data;
	if (head->prev == NULL and head->next == NULL)
	{
		delete head;
		head = tail = NULL;
	}
	else
	{
		Node *h = head;
		head = h->next;
		head->prev = NULL;
		delete h;
	}

	return data;
}

void DL_List ::printList()
{
	Node *p = head;
	while (p)
	{
		cout << p->data;
		p = p->next;
		if (p)
			cout << " <- ";
	}
	cout << endl;
}

void ListQueue ::enqueue(int data)
{
	Q.insertAtEnd(data);
	cout << data << " is inserted at the end of the queue." << endl;
}

int ListQueue ::dequeue()
{
	if (isEmpty())
	{
		cout << "Queue is empty." << endl;
		return -1;
	}

	int data = Q.deleteFromBeginning();
	cout << data << " is deleted from the queue." << endl;
	return data;
}

bool ListQueue ::isEmpty()
{
	return Q.head == NULL;
}

void ListQueue ::display()
{
	cout << "Queue: ";
	Q.printList();
}

int main()
{
	ListQueue myQueue;

	myQueue.enqueue(10);
	myQueue.enqueue(20);
	myQueue.display();
	myQueue.enqueue(30);
	myQueue.enqueue(40);
	myQueue.display();
	myQueue.dequeue();
	myQueue.display();

	ArrayQueue myqueue;

	myqueue.enqueue(10);
	myqueue.enqueue(20);
	myqueue.enqueue(30);
	myqueue.display();
	myqueue.dequeue();
	myqueue.display();
	myqueue.enqueue(40);
	myqueue.display();

	return 0;
}