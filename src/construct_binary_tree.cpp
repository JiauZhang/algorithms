#include <iostream>

using namespace std;

struct BinaryTree
{
	BinaryTree(): p_Left(NULL), p_Right(NULL) {}
	int m_Value;
	BinaryTree* p_Left;
	BinaryTree* p_Right;
};
//此函数不进行安全检查 
BinaryTree* find_father(BinaryTree* root, int value)
{
	BinaryTree* father = root;
	while(true) {
		if(father->m_Value<value && father->p_Right)
			father = father->p_Right;
		else if(father->m_Value>=value && father->p_Left)
			father = father->p_Left;
		else
			break;
	}
	return father; 
}

void add_node(BinaryTree** root, int value)
{
	if(root) {
		if(*root) {
			BinaryTree* father = find_father(*root, value);
			BinaryTree* son = new BinaryTree();
			if(father->m_Value<value) {
				father->p_Right = son;
				son->m_Value = value;
			} else {
				father->p_Left = son;
				son->m_Value = value;
			}			
		} else {
			*root = new BinaryTree();
			(*root)->m_Value = value;
		}
	}
}
//先左子节点，然后根节点，最后右子节点 
void print_inorder(BinaryTree* root)
{
	if(root->p_Left)
		print_inorder(root->p_Left);
	cout << root->m_Value << ' ';
	if(root->p_Right)
		print_inorder(root->p_Right);
}
//先根节点，然后左子节点，最后右子节点 
void print_preorder(BinaryTree* root)
{
	cout << root->m_Value << ' ';
	if(root->p_Left)
		print_preorder(root->p_Left);
	if(root->p_Right)
		print_preorder(root->p_Right);
}
//先左子节点，然后右子节点，最后根节点 
void print_postorder(BinaryTree* root)
{
	if(root->p_Left)
		print_postorder(root->p_Left);
	if(root->p_Right)
		print_postorder(root->p_Right);
	cout << root->m_Value << ' ';
}
//用作递归的函数一定要有终止条件，否则将会陷入死循环 
void construct_binary_tree(BinaryTree** root, int* preorder, int* inorder, int length)
{
	if(root) {
		if(length==1) {
			*root = new BinaryTree();
			(*root)->m_Value = preorder[0];
		} else if(length>1) {
			//root节点 
			*root = new BinaryTree();
			(*root)->m_Value = preorder[0];
			//找到root节点的位置
			int index = 0;
			while(inorder[index] != preorder[0] && index < (length-1))
				index++;
			//找到正确的index，长度为index+1 
			if(inorder[index]==preorder[0]) {
				if(index+1==length) {
					//这里的index索引的是root，所以root前边的都是左子节点，所以前边的长度正好等于index
					//不需要再加 1 了！！ 
					construct_binary_tree(&((*root)->p_Left), &preorder[1], inorder, index);
				} else if(index==0) {
					construct_binary_tree(&((*root)->p_Right), &preorder[index+1], &inorder[index+1], length-index-1);
				} else {
					construct_binary_tree(&((*root)->p_Left), &preorder[1], inorder, index);
					construct_binary_tree(&((*root)->p_Right), &preorder[index+1], &inorder[index+1], length-index-1);
				}				 
			}
		} /*else if(length==2) {
			*root = new BinaryTree();
			(*root)->m_Value = preorder[0];
			if(preorder[0]<preorder[1]) {
				(*root)->p_Left = new BinaryTree();
				(*root)->p_Left->m_Value = preorder[1];
			}	
			else {
				(*root)->p_Right = new BinaryTree();
				(*root)->p_Right->m_Value = preorder[1];
			}
		}*/	
	}
}

void Test(BinaryTree* root, int* preorder, int* inorder, int length)
{
	root = NULL;
	construct_binary_tree(&root, preorder, inorder, length);
	print_preorder(root);
	cout << endl;
	print_inorder(root);
	cout << endl;
	print_postorder(root);
	cout << endl;
}

int main(int argc, char** argv)
{
	BinaryTree* root = NULL;
	//完全二叉树 
	add_node(&root, 5);
	add_node(&root, 3);
	add_node(&root, 7);
	add_node(&root, 1);
	add_node(&root, 4);
	add_node(&root, 6);
	add_node(&root, 9);
	cout << "basci test" << endl;
	print_preorder(root);
	cout << endl;
	print_inorder(root);
	cout << endl;
	print_postorder(root);
	cout << endl;
	
	int preorder_test1[7] = {5, 3, 1, 4, 7, 6, 9};
	int inorder_test1[7] = {1, 3, 4, 5, 6, 7, 9};
	cout << "test 1" << endl;
	BinaryTree* root__test1;
	Test(root__test1, preorder_test1, inorder_test1, 7);
	//只有左节点	
	int preorder_test2[7] = {7, 6, 5, 4, 3, 2, 1};	
	int inorder_test2[7] = {1, 2, 3, 4, 5, 6, 7};
	cout << "test 2" << endl;
	BinaryTree* root__test2;
	Test(root__test2, preorder_test2, inorder_test2, 7);
	//只有右节点 
	int preorder_test3[7] = {1, 2, 3, 4, 5, 6, 7};	
	int inorder_test3[7] = {1, 2, 3, 4, 5, 6, 7};
	cout << "test 3" << endl;
	BinaryTree* root__test3;
	Test(root__test3, preorder_test3, inorder_test3, 7);
	//单个节点 
	int preorder_test4[1] = {1};	
	int inorder_test4[1] = {1};
	cout << "test 4" << endl;
	BinaryTree* root__test4;
	Test(root__test4, preorder_test4, inorder_test4, 1);
	//普通二叉树	
	int preorder_test5[9] = {7, 5, 3, 1, 2, 15, 9, 8, 10};	
	int inorder_test5[9] = {1, 3, 2, 5, 7, 8, 9, 15, 10};
	cout << "test 5" << endl;
	BinaryTree* root__test5;
	Test(root__test5, preorder_test5, inorder_test5, 9);	
	
	return 0;
}
