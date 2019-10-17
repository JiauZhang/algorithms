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
* https://leetcode-cn.com/problems/balanced-binary-tree
* 题目描述：
*     给定一个二叉树，判断它是否是高度平衡的二叉树。
*     本题中，一棵高度平衡二叉树定义为：
*     一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
* 
* 示例 1:
*     给定二叉树 [3,9,20,null,null,15,7]
*         3
*        / \
*       9  20
*         /  \
*        15   7
*     返回 true
* 
* 示例 2:
*     给定二叉树 [1,2,2,3,3,null,null,4,4]
*            1
*           / \
*          2   2
*         / \
*        3   3
*       / \
*      4   4
*     返回 false
* 
* 解题思路：
*     1. 判断左右子树深度值是否符合要求，如果符合则递归进入左右子树
*     2. 先递归进入左右子树，然后判断子树是否符合，在返回到上层节点
*     3. 第一种会出现重复遍历子树深度的过程，浪费时间
*        第二种不需要重复计算子树深度
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
class Solution_1 {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;

        int left = depth(root->left);
        int right = depth(root->right);

        int diff = abs(left - right);

        bool balance = (diff <= 1);
        if (!balance)
            return false;

        balance = isBalanced(root->left);
        if (!balance)
            return false;

        balance = isBalanced(root->right);   
        return balance;
    }

    int depth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        
        int left = depth(root->left);
        int right = depth(root->right);

        return left > right? left+1: right+1;
    }
};

class Solution_2 {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;

        int depth;
        return do_judge(root, &depth);
    }

    bool do_judge(TreeNode *root, int *depth) {
        if (root == nullptr) {
            *depth = 0;
            return true;
        }

        int left, right;
        if (!do_judge(root->left, &left)) 
            return false;
        if (!do_judge(root->right, &right))
            return false;

        int diff = abs(left-right);
        if (diff <= 1) {
            *depth = left>=right ? (left+1) : (right+1);
            return true;
        }

        return false;
    }
};