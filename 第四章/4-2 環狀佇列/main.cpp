#include <iostream>
using namespace std;

class Queue
{
public:
    Queue() {
        for (int i = 0; i < 10; i++) arr[i] = 0;
        front = 0;
        rear = 0;
    }

    // 加入到最後面
    void Enqueue(int x) {
        if (rear > 9) rear -= 10;
        arr[rear++] = x;
    }

    //刪除最前面
    void Dequeue() {
        if (front > 9) front -= 10;
        arr[front++] = 0;
    }

    //輸出
    void PrintQueue() {
        for (int i = front; (front > rear) ? i < rear + 10 : i < rear ; i++) cout << arr[i % 10] << " ";
        cout << "rear:" << rear << " front:" << front << endl;
    }

private:

    int arr[10], rear, front;

};


int main(int argc, char* argv[])
{
    Queue queue;
    int times, input;
    for (int i = 0; i < 2; i++) {
        cin >> times;
        for (int j = 0; j < times; j++) {
            cin >> input;
            queue.Enqueue(input);
        }
        cin >> times;
        for (int j = 0; j < times; j++) {
            queue.Dequeue();
        }
    }
    queue.PrintQueue();
}