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
* https://leetcode-cn.com/problems/binary-tree-paths
* 题目描述：
*     给定一个二叉树，返回所有从根节点到叶子节点的路径
* 说明:
*     叶子节点是指没有子节点的节点
* 
* 示例:
* 输入:
*        1
*      /   \
*     2     3
*      \
*       5
* 输出: 
*     ["1->2->5", "1->3"]
* 解释: 
*     所有根节点到叶子节点的路径为: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr)
            return {};

        vector<string> res;
        string str; // = to_string(root->val);
        do_search_path(res, str, root);

        return res;
    }

    void do_search_path(vector<string> &res, string str, TreeNode *root) {
        if (root->left == nullptr && root->right == nullptr) {
            str += to_string(root->val);
            res.push_back(str);
            return;
        }

        const string arrow = "->";
        str += to_string(root->val) + arrow;
        if (root->left)
            do_search_path(res, str, root->left);
        if (root->right)
            do_search_path(res, str, root->right);
    }
};