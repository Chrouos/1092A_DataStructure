#include <iostream>
using namespace std;

class ListNode
{
public:
	ListNode(int a) { data = a; link = 0; }
private:
	int data;
	ListNode* link;
	friend class LinkedList;
};

class LinkedList {

public:

	LinkedList() {
		first = 0;
		last = 0;
	}

	void InsertFirst(int x) {
		ListNode* a = new ListNode(x);
		if (first == 0) last = a;
		a->link = first;
		first = a;
	}
	void InsertLast(int x) {
		ListNode* a = new ListNode(x);
		if (last == 0) first = a;
		else last->link = a;
		last = a;
		last->link = 0;
	}
	int DeleteFirst() {
		ListNode* d_temp = first;
		first = first->link;
		int num = d_temp->data;
		d_temp = 0;
		return num;
	}
	int DeleteLast() {
		ListNode* d_temp = first;
		while (d_temp->link != last)
			d_temp = d_temp->link;

		int num = last->data;
		d_temp->link = 0;
		last = d_temp;
		return num;
	}
	void PrintList() {
		ListNode* d_temp = first;
		for (; d_temp; d_temp = d_temp->link) cout << d_temp->data << " ";
		cout << endl;
	}

	void Reverse() {

		ListNode* current = first, * prev = NULL, * next = NULL;
		while (current != NULL) {
			next = current->link;
			current->link = prev;
			prev = current;
			current = next;
		}
		first = prev;
	}

private:
	ListNode* first;
	ListNode* last;

};

class Stack : public LinkedList
{
public:

	Stack() {
		
	}
	
	void Push(int x) {
		InsertFirst(x);
	}
	int Pop() {
		return DeleteLast();
	}
	void PrintStack() {
		LinkedList* temp = this;
		temp->Reverse();
		temp->PrintList();
	}

};


int main(int argc, char* argv[])
{
	Stack stack;
	int times, input;
	for (cin >> times; times > 0; times--) { cin >> input; stack.Push(input); }
	for (cin >> times; times > 0; times--) stack.Pop();
	stack.PrintStack();
}