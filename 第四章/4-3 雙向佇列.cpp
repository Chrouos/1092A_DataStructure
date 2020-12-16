#include <iostream>
using namespace std;

class Queue{
	public:
		
		Queue(){
			for(int i=0; i<10; i++) arr[i]=0;
			rear = 0;
			front = 0;
		}
		void Enqueue(int x){
			if(rear>=9) rear-=10;
			arr[++rear] = x;
		}
		void Dequeue(){
			if(front>9) front-=10;
			arr[front++] = 0;
		}
		void PrintQueue(){
			for(int i=front+1; (rear<front)?i<=rear+10:i<=rear; i++) cout<<arr[i%10]<<" "; 
			cout<<"rear:"<<rear<<" front:"<<front<<endl;
		}	
		void BackEnqueue(int x){
			arr[front] = x;
			if(front<1) front+=9;
			else front--;		
		}
		void BackDequeue(){
			arr[rear]=0;
			if(rear<1) rear+=9;
			else rear--;			
		}
	private:
		int arr[10], rear, front;
};


int main(int argc, char *argv[])
{
    Queue queue;
    int times, input;
	cin >> times;
    for(int j = 0; j < times; j++) {
        cin >> input;
        queue.Enqueue(input);
    }
    cin >> times;
    for(int j = 0; j < times; j++) {
        queue.Dequeue();
    }
    cin >> times;
    for(int j = 0; j < times; j++) {
        cin >> input;
        queue.BackEnqueue(input);
    }
    cin >> times;
    for(int j = 0; j < times; j++) {
        queue.BackDequeue();
    }
    queue.PrintQueue();
}
