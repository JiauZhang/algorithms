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
#include <vector>

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

void find_path(BinaryTree *root, int sum, vector<int> &path, int current_sum)
{
	current_sum += root->m_Value;
	path.push_back(root->m_Value);
	
	if (!root->p_Left && !root->p_Right && current_sum == sum) {
		cout << "A path is found: ";
		vector<int>::iterator it_begin = path.begin(), it_end = path.end();
		for (;it_begin != it_end; it_begin++)
			cout << *it_begin; 
		cout << endl;
	}
	
	if (root->p_Left) 
		find_path(root->p_Left, sum, path, current_sum);
	if (root->p_Right) 
		find_path(root->p_Right, sum, path, current_sum);
	
	path.pop_back();
}

void find_path(BinaryTree *root, int sum)
{
	if (root) {
		vector<int> path;
		int current_sum = 0;
		find_path(root, sum, path, current_sum); 
	}
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
	
	find_path(root, 8);
	find_path(root, 12);
	find_path(root, 18);
	find_path(root, 21);
	
	return 0;
}
