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

class LinkedList{
	
	public:
		LinkedList(){
			first=0;
			last=0;
		}
		
		void InsertFirst(int x){
			ListNode* a = new ListNode(x);
			if(first == 0) last = a;
			a->link = first;
			first = a;
		}
		void InsertLast(int x){
			ListNode* a = new ListNode(x);
			if(last==0) first = a;
			else last->link = a;
			last = a;
			last->link = 0; 
		}
		int DeleteFirst(){
			ListNode* temp = first;
			int num = temp->data;
			first = first->link;
			temp=0;
			return num;
		}
		int DeleteLast(){
			ListNode* temp = first;
			while(temp->link != last){
				temp = temp->link;
			}
			int num = last->data;
			temp->link = 0;
			last = temp;
			return num;
		}
		void PrintList(){
			ListNode* temp = first;
			for(; temp; temp=temp->link) cout<<temp->data<<" ";
			cout<<endl;
		}
		void Reverse(){
			ListNode* current = first;
			ListNode* next = 0,* prev = 0;
			
			while(current != 0){
				next = current->link;
				current->link = prev;
				prev = current;
				current = next; 
			}
			first = prev;
		}
		
	private:
		ListNode *first;
		ListNode *last;
};

class Stack: public LinkedList{
	public:
		
		Stack(){
		}
		
		void Push(int x){
			InsertLast(x);
		}
		int Pop(){
			return DeleteLast();
		}
		void PrintStack(){
			PrintList();
		}
		
};

int main(int argc, char *argv[])
{
    Stack stack;
    int times, input;
    for(cin >> times; times > 0; times--) {cin >> input; stack.Push(input);}
    for(cin >> times; times > 0; times--) stack.Pop();
    stack.PrintStack();
}
