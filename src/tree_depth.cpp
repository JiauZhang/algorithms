#include <iostream>

using namespace std;

struct BinaryTreeNode {
	BinaryTreeNode(): left(NULL), right(NULL) {}
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

int treeDepth(BinaryTreeNode *root)
{
	if (root) {
		int left = treeDepth(root->left);
		int right = treeDepth(root->right);
		
		return (left > right) ? left+1 : right+1;
	} else {
		return 0;
	}
}

int main(int argc, char **argv)
{
	BinaryTreeNode *root = new struct BinaryTreeNode;
	BinaryTreeNode *left = new struct BinaryTreeNode;
	BinaryTreeNode *right = new struct BinaryTreeNode;
	cout << "node 1" << endl;
	root->left = left;
	root->right = right;
	left = new struct BinaryTreeNode;
	right = new struct BinaryTreeNode;
	cout << "node 2" << endl;
	root->left->left = left;
	root->right->right = right;
	left = new struct BinaryTreeNode;
	right = new struct BinaryTreeNode;
	cout << "node 3" << endl;
	root->left->right = right;
	root->left->right->left = left;
	
	cout << "tree depth: " << treeDepth(root) << endl;
	
	return 0;
}
