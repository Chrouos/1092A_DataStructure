#include <iostream>
using namespace std;

class Stack{
	
	public: 
	int capacity, top;
	int arr[10];
	int *array;
	
	Stack();
	void Pop();
	void Push(int x);
	void PrintStack();
	
};
Stack::Stack(){
	capacity = 0;
	top = -1;
	array = arr;

}
void Stack::Pop(){
	arr[top--];
}
void Stack::Push(int x){
	arr[++top] = x;
}
void Stack::PrintStack(){
	for(int i=top; i>=0; i--){
		cout<<arr[i]<<" ";
	}
}


int main(int argc, char *argv[])
{
    Stack stack;
    int times, input;
    cin >> times;
    for(int i = 0; i < times; i++) {
        cin >> input;
        stack.Push(input);
    }
    cin >> times;
    for(int i = 0; i < times; i++) {
        stack.Pop();
    }
    stack.PrintStack();
}
