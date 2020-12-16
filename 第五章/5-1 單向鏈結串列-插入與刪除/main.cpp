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
		while (d_temp->link != last )
			d_temp = d_temp->link;

		int num = last->data;
		d_temp->link = 0;
		last = d_temp;
		return num;
	}
	void PrintList() {
		for (; first; first = first->link) cout << first->data << " ";
	}

private:
	ListNode* first;
	ListNode* last;

};

int main(int argc, char* argv[])
{
	LinkedList list;
	int times, input;
	for (cin >> times; times > 0; times--) { cin >> input; list.InsertFirst(input); }
	for (cin >> times; times > 0; times--) list.DeleteFirst();
	for (cin >> times; times > 0; times--) { cin >> input; list.InsertLast(input); }
	for (cin >> times; times > 0; times--) list.DeleteLast();
	list.PrintList();
}