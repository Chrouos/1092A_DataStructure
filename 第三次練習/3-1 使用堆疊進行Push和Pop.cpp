#include <iostream>
using namespace std;

class Stack{
	
	public:
		Stack();
		void Push(int x);
		void Pop();
		void PrintStack();
		
		int capacity, top;
		int array_temp[10];
		int *array = array_temp;
};

Stack::Stack(){
	capacity = 0;
	top = -1;
}
void Stack::Push(int x){
	array[++top] = x;
	capacity++;
}
void Stack::Pop(){
	array[top--] = 0;
	capacity--;
}
void Stack::PrintStack(){
	for(int i=capacity-1; i>=0; i--){
		cout<<array[i];
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
