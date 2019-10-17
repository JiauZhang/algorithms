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
* https://leetcode-cn.com/problems/minimum-depth-of-binary-tree
* 题目描述：
*     给定一个二叉树，找出其最小深度。
*     最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
* 
* 说明: 
*     叶子节点是指没有子节点的节点。
* 
* 示例:
*     给定二叉树 [3,9,20,null,null,15,7],
*             3
*            / \
*           9  20
*             /  \
*            15   7
*     返回它的最小深度  2.
* 
* 解题思路：
*     使用递归的方法，求最短路径，也就是左右子树的最短路径
*     主要考虑几种特殊情况：
*     1. 递归终止条件，即无子节点时终止，即空指针
*     2. 没有左子树或右子树时如何处理
*     3. 左右子树都存在时如何处理
*     4. 左右子树都不存在时如何处理
*     总之，只要进入递归的不是空指针，当节点都算一个深度值
*     这也就是为什么返回值后都 +1 的原因
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
    int minDepth(TreeNode* root) {        
        if (root == nullptr)
            return 0;

        int left, right;
        left = minDepth(root->left);
        right = minDepth(root->right);

        if (right == 0 && left == 0)
            return 1;
        if (right == 0)
            return left+1;
        if (left == 0)
            return right+1;

        return left>right ? (right+1) : (left+1);
    }
};