#include <iostream>
#define CAPACITY 100
using namespace std;

class BinTree {
   public:
    BinTree() {
        // initial
        for (int i = 0; i < CAPACITY; i++)
            arr[i] = 0;
    }

    // 可將大小為n的data建立成二元樹
    void BuildTree(int data[], int n) {
        tail = 0;  // tail 代表最後一個數值

        // step 1: 設定根結點，從 1 開始
        arr[1] = data[0];

        // step 2:for 是由 data數量決定
        for (int i = 1; i < n; i++) {
            int currentNode = 1;  // 所有都從根結點開始
            while (arr[currentNode] != 0) {
                // 左邊的子節點 = currentNode * 2
                // 右邊的子節點 = currentNode * 2 + 1

                // step 3: 遇到大的放右邊
                if (data[i] > arr[currentNode])
                    currentNode = currentNode * 2 + 1;

                // step 4: 遇到小的放左邊
                else if (data[i] < arr[currentNode])
                    currentNode = currentNode * 2;

                if (tail < currentNode)
                    tail = currentNode;
            }
            arr[currentNode] = data[i];
        }
    }
    void Print() {
        for (int i = 1; i <= tail; i++)
            cout << arr[i] << " ";
    }

   private:
    int arr[CAPACITY], tail;
};

int main(int argc, char* argv[]) {
    BinTree tree1;
    int n;
    cin >> n;
    int* data = new int[n];
    for (int i = 0; i < n; i++)
        cin >> data[i];
    tree1.BuildTree(data, n);
    tree1.Print();
}