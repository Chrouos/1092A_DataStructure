#include <iostream>
using namespace std;

class MaxHeap {

public:

    MaxHeap() {
  
        //for (int i = 0; i < 100; i++) arr[i] = 0;
        tail = 0;
    }

    void Insert(int x) {

        arr[++tail] = x;
        int temp = tail;
        while (arr[temp / 2] < arr[temp] && temp != 1) {
            swap(arr[temp], arr[temp / 2]);
            temp /= 2;
        }

    }

    void Print() {

        for (int i = 1; i <= tail; i++) cout << arr[i] << " ";

    }
private:
    int arr[100], tail;

};

int main(int argc, char* argv[])
{
    MaxHeap tree1;
    int times, input;
    for (cin >> times; times > 0; times--) { cin >> input; tree1.Insert(input); }
    tree1.Print();
}