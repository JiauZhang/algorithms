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
* https://leetcode-cn.com/problems/sum-of-left-leaves
* 题目描述：
*     计算给定二叉树的所有左叶子之和
* 
* 示例：
*     3
*    / \
*   9  20
*     /  \
*    15   7
* 
* 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
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
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if (root) {
            if (root->left)
                do_sum(root->left, true);
            if (root->right)
                do_sum(root->right, false);
        }

        return sum;
    }

    void do_sum(TreeNode *root, bool is_left) {
        if (is_left && root->right == nullptr && root->left == nullptr) {
            sum += root->val;
            return;
        }
        
        if (root->left)
            do_sum(root->left, true);
        if (root->right)
            do_sum(root->right, false);
    }
};