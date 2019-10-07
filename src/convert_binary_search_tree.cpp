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

void convert_nodes(BinaryTree *head, BinaryTree **prev_node)
{
	if (head) {
		if (head->p_Left)
			convert_nodes(head->p_Left, prev_node);
		//实现 当前节点的p_Left指针指向比自己小的那一个节点 
		BinaryTree *current_node = head;
		current_node->p_Left = *prev_node;
		//实现 上一个节点的p_Right指针指向比自己大的那一个节点
		//因为节点的访问顺序是从小到大的，所以当前节点总是 > 上一个节点 
		if (*prev_node != NULL)
			(*prev_node)->p_Right = current_node;
		*prev_node = current_node;
		//节点得 p_Right 指向比自己大的节点是在父节点中完成的 
		if (head->p_Right)
			convert_nodes(head->p_Right, prev_node); 
	}
}

void convert_bst(BinaryTree **head)
{
	if (head) {
		BinaryTree *prev_node = NULL;
		convert_nodes(*head, &prev_node);
		
		while (prev_node && prev_node->p_Left)
			prev_node = prev_node->p_Left;
			
		*head = prev_node;
	}
}

void print_list(BinaryTree *head)
{
	while (head) {
		cout << head->m_Value << ' ';
		head = head->p_Right;
	}
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
	
	convert_bst(&root);
	print_list(root);

	return 0;	
}
