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

/*
 * 题目描述：
 *     操作给定的二叉树，将其变换为源二叉树的镜像。
 *     
 * 输入描述:
 *     二叉树的镜像定义：源二叉树 
 *     	    8
 *     	   /  \
 *     	  6   10
 *     	 / \  / \
 *     	5  7 9 11
 *     	镜像二叉树
 *     	    8
 *     	   /  \
 *     	  10   6
 *     	 / \  / \
 *     	11 9 7  5
 * 
 * struct TreeNode {
 * 	int val;
 * 	struct TreeNode *left;
 * 	struct TreeNode *right;
 * 	TreeNode(int x) :
 * 			val(x), left(NULL), right(NULL) {
 * 	}
 * };
 * 
 * 解题思路：
 *     只要当前节点存在就交换左右子树，然后递归操作左右子节点
 *     注意事项：递归终止条件为当前节点为 NULL
 *     递归法：交换左右子树即可
 *     循环法：由于没有指向父节点的指针，所以只能边交换边将子节点压栈
 * 
 */

/* 递归法 */
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL)
            return;
        TreeNode *temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};

/* 循环法 */
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL)
            return;
        
        stack<TreeNode *> nodes;
        nodes.push(pRoot);
        while (nodes.size()) {
            TreeNode *node = nodes.top();
            nodes.pop();
            TreeNode *temp = node->left;
            node->left = node->right;
            node->right = temp;
            if (node->left)
                nodes.push(node->left);
            if (node->right)
                nodes.push(node->right);            
        }
    }
};