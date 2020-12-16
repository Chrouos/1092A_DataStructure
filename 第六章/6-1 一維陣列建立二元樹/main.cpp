#include <iostream>
#include<cmath>
using namespace std;

class BinTree
{
public:

    BinTree() {
        for (int i = 0; i < 100; i++) {
            arr[i] = 0;
        }
        tail = 1;
    }

    void BuildTree(int data[], int n) {

        int father = 1, floor = 1;
        arr[1] = data[0];
        for (int i = 1; i < n; i++) {
           
            father = 1;
            while (arr[father] != 0) {
                if (arr[father] < data[i]) {
                    father = father * 2 + 1;
                    if (father > tail) tail = pow(2, ++floor) - 1;

                    if (arr[father] == 0) {
                        arr[father] = data[i];
                        break;
                    }
                }
                else {
                    father = father * 2;
                    if (father > tail) tail = pow(2, ++floor) - 1;

                    if (arr[father] == 0) {
                        arr[father] = data[i];
                        break;
                    }
                }

            }


        }
    }
    void Print() {
        for (int i = 1; i <= tail; i++) {
            cout << arr[i] << " ";
        }
        //cout << endl;
    }

private:
    int arr[100];
    int tail;
};

int main(int argc, char* argv[])
{
    BinTree tree1;
    int n;
    cin >> n;
    int* data = new int[n];
    for (int i = 0; i < n; i++) cin >> data[i];
    tree1.BuildTree(data, n);
    tree1.Print();
}