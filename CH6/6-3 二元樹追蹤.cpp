#include <math.h>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class TreeNode {
   public:
    friend class BinTree;
    TreeNode(int a) {
        data = a;
        leftChild = rightChild = 0;
    };

   private:
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;
};

class BinTree {
   public:
    BinTree() { root = 0; }
    TreeNode* returnRoot() { return root; }

    void BuildTree(int data[], int n) {
        int tail = 0;  // tail 代表最後一個數值

        // step 1: 設定根結點，從 1 開始
        root = new TreeNode(data[0]);

        // step 2:for 是由 data數量決定
        for (int i = 1; i < n; i++) {
            TreeNode* currentNode = root;  // 所有都從根結點開始
            while (currentNode != 0) {
                // step 3: 遇到大的放右邊
                if (data[i] > currentNode->data)
                    if (currentNode->rightChild != 0)
                        currentNode = currentNode->rightChild;
                    else {
                        currentNode->rightChild = new TreeNode(data[i]);
                        break;
                    }

                // step 4: 遇到小的放左邊
                else if (data[i] < currentNode->data)
                    if (currentNode->leftChild != 0)
                        currentNode = currentNode->leftChild;
                    else {
                        currentNode->leftChild = new TreeNode(data[i]);
                        break;
                    }
            }
        }
    }
    //中序遍歷 (Inorder Traversal)
    void Inorder(TreeNode* currentNode) {
        if (currentNode != NULL) {
            Inorder(currentNode->leftChild);
            cout << currentNode->data << " ";
            Inorder(currentNode->rightChild);
        }
    }
    //前序遍歷 (Preorder Traversal)
    void Preorder(TreeNode* currentNode) {
        if (currentNode != NULL) {
            cout << currentNode->data << " ";
            Preorder(currentNode->leftChild);
            Preorder(currentNode->rightChild);
        }
    }
    //後序遍歷 (Postorder Traversal)
    void Postorder(TreeNode* currentNode) {
        if (currentNode != NULL) {
            Postorder(currentNode->leftChild);
            Postorder(currentNode->rightChild);
            cout << currentNode->data << " ";
        }
    }

   private:
    TreeNode* root;
};

int main(int argc, char* argv[]) {
    BinTree tree1;
    int n;
    cin >> n;
    int* data = new int[n];
    for (int i = 0; i < n; i++)
        cin >> data[i];
    tree1.BuildTree(data, n);
    tree1.Inorder(tree1.returnRoot());
    cout << endl;
    tree1.Preorder(tree1.returnRoot());
    cout << endl;
    tree1.Postorder(tree1.returnRoot());
    cout << endl;
}