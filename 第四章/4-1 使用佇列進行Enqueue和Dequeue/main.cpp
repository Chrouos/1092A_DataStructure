#include <iostream>
using namespace std;

class Queue
{
public:
    Queue() {
        for (int i = 0; i < 10; i++) arr[i] = NULL;
        front = -1;
        rear = -1;
    }

    // 加入到最後面
    void Enqueue(int x) {
        arr[++rear] = x;
    }

    //刪除最前面
    void Dequeue() {
        arr[++front] = NULL;
    }

    //輸出
    void PrintQueue() {
        for (int i = front + 1; i <= rear; i++) cout << arr[i] << " ";
    }

private:

    int arr[10], rear, front;

};


int main(int argc, char* argv[])
{
    Queue queue;
    int times, input;
    cin >> times;
    for (int i = 0; i < times; i++) {
        cin >> input;
        queue.Enqueue(input);
    }
    cin >> times;
    for (int i = 0; i < times; i++) {
        queue.Dequeue();
    }
    queue.PrintQueue();
}