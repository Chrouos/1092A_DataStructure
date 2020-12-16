#include <iostream>
using namespace std;

class Queue
{
public:

    Queue() {
        for (int i = 0; i < 10; i++) arr[i] = 0;
        arr[9] = {};
        front = 0;
        rear = 0;
    }

    // 程
    void Enqueue(int x) {
        if (rear > 9) rear -= 10;
        arr[rear++] = x;
    }

    //埃程玡
    void Dequeue() {
        if (front > 9) front -= 10;
        arr[front++] = 0;
    }

    //块
    void PrintQueue() {
        for (int i = front; (front > rear) ? i < rear + 10 : i < rear; i++) cout << arr[i % 10] << " ";
        cout << "rear:" << rear << " front:" << front << endl;
    }

    //程玡
    void BackEnqueue(int x) {
        (front < 1) ? front = (front+9)%10 : front-- ;
        arr[front] = x;
    }
    //埃程
    void BackDequeue() {
        (rear < 1) ? rear = (rear+9)%10 : rear--;
        arr[rear] = 0;
    }

private:

    int arr[10], rear, front;

};


int main(int argc, char* argv[])
{
    Queue queue;
    int times, input;
    cin >> times;
    for (int j = 0; j < times; j++) {
        cin >> input;
        queue.Enqueue(input);
    }
    cin >> times;
    for (int j = 0; j < times; j++) {
        queue.Dequeue();
    }
    
    cin >> times;
    for (int j = 0; j < times; j++) {
        cin >> input;
        queue.BackEnqueue(input);
    }
    cin >> times;
    for (int j = 0; j < times; j++) {
        queue.BackDequeue();
    }
    
    queue.PrintQueue();
}