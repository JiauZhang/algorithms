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
* https://leetcode-cn.com/problems/path-sum
* 题目描述：
*     给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，
*     这条路径上所有节点值相加等于目标和
* 
* 说明: 
*     叶子节点是指没有子节点的节点
* 
* 示例: 
*     给定如下二叉树，以及目标和 sum = 22，
*                   5
*                  / \
*                 4   8
*                /   / \
*               11  13  4
*              /  \      \
*             7    2      1
*     返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径
*     5->4->11->2
* 
* 解题思路：
*     递归到叶子节点判断是否符合要去即可
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return false;

        return do_search(root, 0, sum);
    }

    bool do_search(TreeNode *root, int cur, int &target) {
        if (root == nullptr)
            return false;

        if (root->left == nullptr && root->right == nullptr) {
            return (cur + root->val == target);
        }

        bool res = false;
        if (root->left)
            res = do_search(root->left, cur+root->val, target);
        if (!res && root->right)
            res = do_search(root->right, cur+root->val, target);
        
        return res;
    }
};