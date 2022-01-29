#include <iostream>
using namespace std;

class ListNode
{
public:
	ListNode(int a) {data = a; link = 0;}
private:
	int data;
	ListNode *link;
	friend class LinkedList;
};

class LinkedList
{
public:
    LinkedList();
	void InsertFirst(int);
	void InsertLast(int);
	int DeleteFirst();
	int DeleteLast();
	void Reverse();
	void PrintList();
private:
	ListNode *first;
	ListNode *last;
};

LinkedList::LinkedList() {
	first = 0;
	last = 0;
}

void LinkedList::InsertFirst(int x) {
	ListNode *newNode = new ListNode(x);
	newNode->link = first;
	first = newNode;
	// ???Ĥ@????ƥ[?J?ɡA?]?wlast??m 
	if (last == 0) last = newNode;
}

void LinkedList::InsertLast(int x) {
	ListNode *newNode = new ListNode(x);
	if (last == 0)
		first = newNode;
	else
		last->link = newNode;
	last = newNode;
}

int LinkedList::DeleteFirst() {
	ListNode *oldNode = first;
	first = first->link;
	// ???S????ƮɡA?]?wlast??m 
	if (first == 0) last = 0;
	int rt_val = oldNode->data;
	delete oldNode;
	return rt_val;
}

int LinkedList::DeleteLast() {
	ListNode *oldNode = last;
	if (first == last) {
		first = 0;
		last = 0;
	}
	else {
		ListNode *current = first;
		while(current->link != last) {
			current = current->link;
		}
		current->link = 0;
		last = current;
	}
	int rt_val = oldNode->data;
	delete oldNode;
	return rt_val;
}

void LinkedList::Reverse() {
	ListNode *current = first, *previous = 0;
	while (current) {
		ListNode *r = previous;
		previous = current;
		current = current->link;
		previous->link = r;
	}
	first = previous;
}

void LinkedList::PrintList() {
    ListNode *current = first;
    while (current != 0) {
    	cout << current->data << " ";
    	current = current->link;
	}
	cout << endl;
}

class Queue : public LinkedList
{ 
public:
    void Enqueue(int x) {InsertLast(x);}
	int Dequeue() {return DeleteFirst();}
	void PrintQueue() {PrintList();}
};

int main(int argc, char *argv[])
{
    Queue queue;
    int times, input;
    for(cin >> times; times > 0; times--) {cin >> input; queue.Enqueue(input);}
    for(cin >> times; times > 0; times--) queue.Dequeue();
    queue.PrintQueue();
}