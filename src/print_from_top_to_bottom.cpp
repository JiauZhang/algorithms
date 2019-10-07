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
#include <list>
#include <deque>

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

void print_list(list<BinaryTree *> &nodes)
{
	list<BinaryTree *>::iterator it_begin = nodes.begin();
	list<BinaryTree *>::iterator it_end = nodes.end();
	for (;it_begin != it_end; it_begin++) {
		cout << (*it_begin)->m_Value << ' ';
	}
	cout << endl;
}

void print_tree_from_top_to_bottom(BinaryTree *root, int level=0)
{
	list<BinaryTree *> current_nodes;
	list<BinaryTree *> next_nodes;
	if (root) {
		cout << root->m_Value << endl;
		current_nodes.push_back(root);
		while (true) {
			next_nodes.clear();
			list<BinaryTree *>::iterator it_begin = current_nodes.begin();
			list<BinaryTree *>::iterator it_end = current_nodes.end();
			for (;it_begin != it_end; it_begin++) {
				if ((*it_begin)->p_Left)
					next_nodes.push_back((*it_begin)->p_Left);
				if ((*it_begin)->p_Right)
					next_nodes.push_back((*it_begin)->p_Right);
			}
			
			if (!next_nodes.size())
				break;
			print_list(next_nodes);
			
			current_nodes.clear();
			current_nodes = next_nodes;
		}	
	}
}

void print_tree_deque(BinaryTree *root)
{
	if (root) {
		deque<BinaryTree *> tree;
		tree.push_back(root);
		while(tree.size()) {
			BinaryTree *node = tree.front();
			tree.pop_front();
			cout << node->m_Value << ' ';
			if(node->p_Left)
				tree.push_back(node->p_Left);
			if(node->p_Right)
				tree.push_back(node->p_Right);			
		}
		cout << endl;
	}	
}

int main(int argc, char** argv)
{
	BinaryTree *root_test1 = NULL;
	//完全二叉树 
	add_node(&root_test1, 5);
	add_node(&root_test1, 3);
	add_node(&root_test1, 7);
	add_node(&root_test1, 1);
	add_node(&root_test1, 4);
	add_node(&root_test1, 6);
	add_node(&root_test1, 9);
	
	BinaryTree *root_test2 = NULL;
	add_node(&root_test2, 1);
	add_node(&root_test2, 2);
	add_node(&root_test2, 3);
	add_node(&root_test2, 4);
	add_node(&root_test2, 5);

	BinaryTree *root_test3 = NULL;
	add_node(&root_test3, 1);
	add_node(&root_test3, 5);
	add_node(&root_test3, 3);
	add_node(&root_test3, 6);
	add_node(&root_test3, 9);
	add_node(&root_test3, 2);
	
	BinaryTree *root_test4 = NULL;
	add_node(&root_test4, 1);	
	
	print_tree_from_top_to_bottom(root_test1);
	print_tree_deque(root_test1);
	print_tree_from_top_to_bottom(root_test2);
	print_tree_deque(root_test2);
	print_tree_from_top_to_bottom(root_test3);
	print_tree_deque(root_test3);	
	print_tree_from_top_to_bottom(root_test4);
	print_tree_deque(root_test4);	
	
	return 0;
}
