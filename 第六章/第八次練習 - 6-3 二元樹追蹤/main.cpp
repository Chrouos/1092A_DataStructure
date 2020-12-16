#include <iostream>
#include <iomanip>
#include <queue>
#include <math.h>
using namespace std;

class TreeNode
{
public:
	friend class BinTree;
	TreeNode(int a) { data = a; leftChild = rightChild = 0; };
private:
	int data;
	TreeNode* leftChild;
	TreeNode* rightChild;
};

class BinTree
{
public:
	BinTree();
	void BuildTree(int data[], int n);
	void Plot();

	void Inorder(TreeNode*);
	void Preorder(TreeNode*);
	void Postorder(TreeNode*);

private:
	TreeNode* root;
};

BinTree::BinTree() {
	root = 0;
}
void BinTree::BuildTree(int data[], int n) {

	TreeNode* node, * newOne;
	root = new TreeNode(data[0]);
	for (int i = 1; i < n; i++) {

		node = root;
		newOne = new TreeNode(data[i]);
		while (node != 0) {
			if (node->data < data[i]) {
				if (node->rightChild == 0) {
					node->rightChild = newOne;
					break;
				}
				else node = node->rightChild;
			}
			else {
				if (node->leftChild == 0) {
					node->leftChild = newOne;
					break;
				}
				else node = node->leftChild;
			}

		}

		
			

	}//for i<n
	Inorder(root);
	cout << endl;

	Preorder(root);
	cout << endl;

	Postorder(root);
	cout << endl;

}

//¤¤
void BinTree::Inorder(TreeNode* ori) {
	if (ori != 0) {
		Inorder(ori->leftChild);
		if (ori != 0)
		cout << ori->data << " ";
		Inorder(ori->rightChild);
	}
}
void BinTree::Preorder(TreeNode* ori) {
	if (ori != 0) {
		if (ori != 0)
		cout << ori->data << " ";
		Preorder(ori->leftChild);
		Preorder(ori->rightChild);
	}
}
void BinTree::Postorder(TreeNode* ori) {
	if (ori != 0) {
		Postorder(ori->leftChild);
		Postorder(ori->rightChild);
		if (ori != 0)
		cout << ori->data << " ";
	}
}

void BinTree::Plot() {
	int MAX_HEIGHT = 7, CHAR_SPACE = 2;
	int capacity = pow(2, MAX_HEIGHT);
	int* arr = new int[capacity] {};
	queue<TreeNode*> q;
	queue<int> index_q;
	q.push(root);
	index_q.push(1);
	TreeNode* currentNode;
	int currentIndex, tail = 0;
	while (!q.empty()) {
		currentNode = q.front(); q.pop();
		currentIndex = index_q.front(); index_q.pop();
		arr[currentIndex] = currentNode->data;
		if (tail < currentIndex) tail = currentIndex;
		if (currentNode->leftChild) {
			q.push(currentNode->leftChild);
			index_q.push(currentIndex * 2);
		}
		if (currentNode->rightChild) {
			q.push(currentNode->rightChild);
			index_q.push(currentIndex * 2 + 1);
		}
	}
	int i, sps;
	int max_level = log(tail) / log(2) + 1;
	for (int lv = 1; lv <= max_level; lv++) {
		sps = pow(2, max_level - lv) * CHAR_SPACE;
		i = pow(2, lv - 1);
		cout << setw(sps);
		if (arr[i]) cout << arr[i]; else cout << " ";
		sps *= 2;
		for (i++; i <= pow(2, lv) - 1; i++) {
			cout << setw(sps);
			if (arr[i]) cout << arr[i]; else cout << " ";
		}
		cout << endl;
	}
}

int main(int argc, char* argv[])
{
	BinTree tree1;
	int n;
	cin >> n;
	int* data = new int[n];
	for (int i = 0; i < n; i++) cin >> data[i];
	tree1.BuildTree(data, n);
}