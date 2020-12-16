#include <iostream>
#include <iomanip>
#include <queue>
#include <math.h>
using namespace std;

class TreeNode
{
public:
	friend class BinTree;
	TreeNode(int a) {data = a; leftChild = rightChild = 0;};
private:
	int data;
	TreeNode *leftChild;
	TreeNode *rightChild;
};

class BinTree{
	public:
		void BuildTree(int data[], int n);	
		void Inorder(TreeNode*);
		void Preorder(TreeNode*);
		void Postorder(TreeNode*);
	private:		
		TreeNode* root;		
};

void BinTree::BuildTree(int data[], int n){
	
	root = new TreeNode(data[0]);
	TreeNode* node;
	for(int i=1; i<n; i++){		
		node = root;
		while(node != 0){
			if( node->data < data[i] ){
				if( node->rightChild == 0 ) {
					node->rightChild = new TreeNode(data[i]);
					break;
				}
				else node = node->rightChild;
			}
			else {
				if( node->leftChild == 0 ){
					node->leftChild = new TreeNode(data[i]);
					break;
				} 
				else node = node->leftChild;
			}
		}	
	}
	
	Inorder(root);
	cout<<endl;
	Preorder(root);
	cout<<endl;
	Postorder(root);
	cout<<endl;
	
}

void BinTree::Inorder(TreeNode* a){
	
	if( a != 0 ){
		
		Inorder(a->leftChild);
		if( a!=0 ) cout<<a->data<<" ";
		Inorder(a->rightChild);
		
	}
	
	
}
void BinTree::Preorder(TreeNode* a){
		if( a != 0 ){
		
		if( a!=0 ) cout<<a->data<<" ";
		Preorder(a->leftChild);
		Preorder(a->rightChild);
		
	}
}
void BinTree::Postorder(TreeNode* a){
	if( a != 0 ){
		
		Postorder(a->leftChild);
		Postorder(a->rightChild);
		if( a!=0 ) cout<<a->data<<" ";
		
	}
}

int main(int argc, char *argv[])
{   
    BinTree tree1;
    int n;
    cin >> n;
    int *data = new int[n];
    for (int i = 0; i < n; i++) cin >> data[i];
    tree1.BuildTree(data, n);
}
