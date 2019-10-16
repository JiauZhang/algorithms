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
* https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
* 题目描述：
*     给定一个二叉树，返回其节点值自底向上的层次遍历。
*     即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历
* 
* 例如：
*     给定二叉树 [3,9,20,null,null,15,7]
*         3
*        / \
*       9  20
*         /  \
*        15   7
*     返回其自底向上的层次遍历为：
*     [
*       [15,7],
*       [9,20],
*       [3]
*     ]
* 
* 解题思路：
*     由于需要按层进行组成，且是vector<vector<int>>
*     所以必须把每个层分开记录，另一点就是还要实现逆序
*     分层可以通过单独记录每层节点来完成，而逆序有两种方式
*     第一种是直接正序记录，然后再颠倒顺序
*     第二种是进行递归记录每层节点，最后在每层中添加数据
*     这样第二种就省去了第一种方法中颠倒顺序这步的操作
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL)
            return {};

        vector<vector<int>> res;
        vector<TreeNode *> nodes;
        nodes.push_back(root);
        do_order(nodes, res);

        return res;
    }

    void do_order(vector<TreeNode *> &nodes, vector<vector<int>> &res) {
        if (nodes.size() == 0)
            return;

        vector<TreeNode *> next_level;
        for (int i=0; i<nodes.size(); i++) {
            if (nodes[i]->left)
                next_level.push_back(nodes[i]->left);
            if (nodes[i]->right)
                next_level.push_back(nodes[i]->right);
        }

        do_order(next_level, res);
        vector<int> temp;
        for (int i=0; i<nodes.size(); i++) {
            temp.push_back(nodes[i]->val);
        }
        res.push_back(temp);
    }
};