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

bool isBalanced(BinaryTreeNode *root)
{
	if (root == NULL)
		return true;
		
	int left = treeDepth(root->left);
	int right = treeDepth(root->right);
	int diff = left - right;
	
	if (diff < -1 || diff > 1)
		return false;
		
	return isBalanced(root->left) && isBalanced(root->right);
} 

bool isBalanced_(BinaryTreeNode *root, int *depth)
{
	if (root == NULL) {
		*depth = 0;
		return true;
	}
	
	int left, right;
	if (isBalanced_(root->left, &left) && isBalanced_(root->right, &right)) {
		int diff = left - right;
		if (diff < -1 || diff > 1) {
			return false;
		}
		
		*depth = (left > right) ? (left + 1) : (right + 1);
		return true;
	}
	
	return false;
}

bool isBalanced_(BinaryTreeNode *root)
{
	int depth;
	return isBalanced_(root, &depth);	
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
	
	bool balan = isBalanced(root);
	cout << "is balanced: " << balan << endl;
	
	balan = isBalanced_(root);
	cout << "is balanced: " << balan << endl;
	
	return 0;
}
