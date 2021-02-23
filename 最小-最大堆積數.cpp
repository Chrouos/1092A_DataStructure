#include <iostream>
#define CAPACITY 100
using namespace std;

class MinMaxHeap
{
public:
        void Insert(int);
        void Print();
private:
        int arr[CAPACITY] = { 0 };
        int tail = 0;
};

void MinMaxHeap::Insert(int x) {
        
        tail++;      // tail 為 目前位置
        arr[tail] = x;

        if (tail == 1) return;

        //奇數層為 min-heap, 偶數層為 max-heap
        //floor 為 目前所在層數
        int temp = tail, floor = 0;
        while (temp != 0) {
                temp /= 2;
                floor++;
        }

        //cout << x << " floor =  " << floor << endl;

        int F_node = arr[tail / 2], node = arr[tail], t_tail = tail;
        if (node > F_node) { // 如果當前 大於 父節點

                //進入 max-heap ( 偶數層 )

                if (floor % 2 == 1) { //目前為奇數層，直接與上一層對調
                        temp = F_node;
                        arr[t_tail / 2] = node;
                        arr[t_tail] = temp;
                        t_tail /= 2;
                }

                //在跑到第一層之前 且 子大於父
                while (t_tail / 4 >= 1 && arr[t_tail / 4] < arr[t_tail]) {

                        temp = arr[t_tail / 4];
                        arr[t_tail / 4] = node;
                        arr[t_tail] = temp;
                        t_tail /= 4;

                }
                

        } else { // 如果當前 小於 父節點

                //進入 min-heap ( 奇數層 )
                if (floor % 2 == 0) { //目前為偶數層，直接與上一層對調
                        temp = F_node;
                        arr[t_tail / 2] = node;
                        arr[t_tail] = temp;
                        t_tail /= 2;
                }

                //在跑到第一層之前 且 子小於父
                while (t_tail / 4 >= 1 && arr[t_tail / 4] > arr[t_tail]) {

                        temp = arr[t_tail / 4];
                        arr[t_tail / 4] = node;
                        arr[t_tail] = temp;
                        t_tail /= 4;

                }

        }

}

void MinMaxHeap::Print() {
        for (int i = 1; i <= tail; i++)
                cout << arr[i] << " ";
}

int main(int argc, char* argv[])
{
        MinMaxHeap tree1;
        int times, input;
        for (cin >> times; times > 0; times--) { cin >> input; tree1.Insert(input); }
        tree1.Print();
}
