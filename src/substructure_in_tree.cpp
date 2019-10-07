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
//此函数不做安全检查 
BinaryTree* find_by_value(BinaryTree* root1, BinaryTree* root2)
{
	if(root1 == NULL)
		return NULL;
	if(root1->m_Value == root2->m_Value) {
		return root1;
	} else {
		BinaryTree* res = find_by_value(root1->p_Left, root2);
		if(!res) {
			res = find_by_value(root1->p_Right, root2);
		}
		return res;
	}
}

bool check_tree(BinaryTree* root1, BinaryTree* root2)
{
	if(root2 == NULL)
		return true;
	if(root1 == NULL)
		return false;
	//cout << "check_tree value1: " << root1->m_Value << endl;
	//cout << "check_tree value2: " << root2->m_Value << endl;
	if(root1->m_Value == root2->m_Value) {
		return check_tree(root1->p_Left, root2->p_Left) && \
					 check_tree(root1->p_Right, root2->p_Right);
	} else {
		return false;
	}
}

bool dose_tree1_have_tree2(BinaryTree* root1, BinaryTree* root2)
{
	if(!root1)
		return false;
	if(!root2)
		return true;
	//应该先检查是否刚开始它们就相等
	if(root1->m_Value == root2->m_Value) {
		return check_tree(root1, root2);
	}	else { //根节点不相等的情况 
		BinaryTree* res;	
		if(root1->m_Value != root2->m_Value)
			res = find_by_value(root1, root2);
		if(!res)
			return false;	
		//cout << res->m_Value << endl; 
		if(res->m_Value==root2->m_Value) {
			return check_tree(res, root2);
		} else 
			return false;
	} 
}

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

int main(int argc, char** argv)
{
	BinaryTree* root1 = NULL;
	//完全二叉搜索树 
	add_node(&root1, 5);
	add_node(&root1, 3);
	add_node(&root1, 7);
	add_node(&root1, 1);
	add_node(&root1, 4);
	add_node(&root1, 6);
	add_node(&root1, 9);
	
	BinaryTree* root2 = NULL;
	add_node(&root2, 5);
	add_node(&root2, 3);
	add_node(&root2, 7);
	add_node(&root2, 1);
	add_node(&root2, 4);
	add_node(&root2, 6);
	add_node(&root2, 9);
	
	cout << dose_tree1_have_tree2(root1, root2); 
	
	return 0;
}
