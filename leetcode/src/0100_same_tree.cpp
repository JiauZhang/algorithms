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
* https://leetcode-cn.com/problems/same-tree
* 题目描述：
*     给定两个二叉树，编写一个函数来检验它们是否相同。
*     如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
* 
* 示例 1:
*     输入:       1         1
*               / \       / \
*              2   3     2   3
*             [1,2,3],   [1,2,3]
*     输出: true
* 
* 示例 2:
*     输入:      1          1
*               /           \
*              2             2
*             [1,2],     [1,null,2]
*     输出: false
* 
* 示例 3:
*     输入:       1         1
*               / \       / \
*              2   1     1   2
*             [1,2,1],   [1,1,2]
*     输出: false
* 
* 解题思路：
*     深度优先递归判断子树是否相同即可
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q != NULL)
            return false;
        if (p != NULL && q == NULL)
            return false;
        if (p == NULL && q == NULL)
            return true;

        if (p->val == q->val) {
            bool left = isSameTree(p->left, q->left);
            if (!left)
                return false;

            bool right = isSameTree(p->right, q->right);
            return right;
        } else {
            return false;
        }
    }
};