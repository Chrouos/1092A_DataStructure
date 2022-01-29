#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    MaxHeap tree1;
    int times, input;
    for (cin >> times; times > 0; times--) {
        cin >> input;
        tree1.Insert(input);
    }
    tree1.Print();
}