/*
* Copyright(c) 2021 Jiau Zhang
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
* https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
* 题目描述：
*     给定一个二叉树的根节点 root ，返回它的中序遍历
* 解题思路：
*     1. 最直接的就是递归
*     2. 用栈模拟递归，先 left 全部入栈，然后取栈顶，再操作 right
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        // do_work(res, root);
        stack<TreeNode *> stk;

        while (root != nullptr || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }

            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }

        return res;
    }

    void do_work(vector<int> &res, TreeNode *root) {
        if (root) {
            if (root->left)
                do_work(res, root->left);
            res.push_back(root->val);
            if (root->right)
                do_work(res, root->right);
        }
    }
};