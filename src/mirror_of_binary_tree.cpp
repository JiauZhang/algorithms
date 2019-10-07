/*
* Copyright(c) 2019 Jiau Zhang
* For more information see <https://github.com/JiauZhang/algorithms>
* 
* This repo is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation
*
* It is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with THIS repo. If not, see <http://www.gnu.org/licenses/>.
*/

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

void mirror_of_binary_tree(BinaryTree* root)
{
	if(root) {
			if(root->p_Left || root->p_Right) {
				BinaryTree* temp = root->p_Left;
				root->p_Left = root->p_Right;
				root->p_Right = temp;
				mirror_of_binary_tree(root->p_Left);
				mirror_of_binary_tree(root->p_Right);
			}
	}
}

void Test(BinaryTree* root)
{
	cout << "basic tree" << endl;
	print_preorder(root);
	cout << endl;
	print_inorder(root);
	cout << endl;
	print_postorder(root);
	cout << endl;
	
	cout << "mirror 1" << endl;
	mirror_of_binary_tree(root);
	print_preorder(root);
	cout << endl;
	print_inorder(root);
	cout << endl;
	print_postorder(root);
	cout << endl;
	
	cout << "mirror 2" << endl;
	mirror_of_binary_tree(root);
	print_preorder(root);
	cout << endl;
	print_inorder(root);
	cout << endl;
	print_postorder(root);
	cout << endl;
}

int main(int argc, char** argv)
{
	BinaryTree* root_test1 = NULL;
	//完全二叉树 
	add_node(&root_test1, 5);
	add_node(&root_test1, 3);
	add_node(&root_test1, 7);
	add_node(&root_test1, 1);
	add_node(&root_test1, 4);
	add_node(&root_test1, 6);
	add_node(&root_test1, 9);
	
	BinaryTree* root_test2 = NULL;
	add_node(&root_test2, 5);
	
	BinaryTree* root_test3 = NULL;
	add_node(&root_test3, 5);
	add_node(&root_test3, 4);
	add_node(&root_test3, 3);
	add_node(&root_test3, 2);
	
	Test(root_test1);
	Test(root_test2);
	Test(root_test3);
	
	
	return 0;
}

