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

using namespace std;

struct TreeNode {
	TreeNode(): left(NULL), right(NULL) {}
	struct TreeNode *left;
	struct TreeNode *right;
};

//把树公共节点问题转化为链表的公共节点问题
//通过这个函数将树问题转化为从根节点到达给定节点的链表问题 
bool GetNodePath(TreeNode *root, TreeNode *node, list<TreeNode *>& path)
{
	if (!root)
		return false;
	
	if (root == node)
		return true;
		
	//遍历root的每个子节点，进行递归查找是否能够到达给定节点 	
	
} 

TreeNode *GetLastCommonNode(const list<TreeNode *>&path1,
							const list<TreeNode *>&path2) 
{
	/*
				a
				b
				c
			   / \
			  d   e
			  f   g
		链表是从a开始的，所以只需要同时遍历两个两边，找到最后的
		公共节点即可	
	*/
	
	 
}

int main(int argc, char **argv)
{
	cout << "NOTINSTANCE!" << endl; 
} 
