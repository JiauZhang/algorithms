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
* https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree
* 题目描述：
*     将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
*     本题中，一个高度平衡二叉树是指一个二叉树每个节点的
*     左右两个子树的高度差的绝对值不超过 1。
* 
* 示例:
*     给定有序数组: [-10,-3,0,5,9],
*     一个可能的答案是：[0,-3,9,-10,null,5]，
*     它可以表示下面这个高度平衡二叉搜索树：
*           0
*          / \
*        -3   9
*        /   /
*      -10  5
* 
* 解题思路：
*     由于题目要求需要转换为一个 -高度平衡- 的二叉搜索树
*     所以这里可以使用二分法对原数组进行分割
*     而树的构建可以分解为根节点、左子树、右子树子结构
*     因此最终的构建步骤就是使用二分法分割数组，然后
*     使用递归方法将树的构建分成根节点、左子树、右子树子结构
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
            return nullptr;

        return construct_tree(0, nums.size()-1, nums);
    }

    TreeNode *construct_tree(int start, int end, vector<int> &nums) {
        if (start > end)
            return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = construct_tree(start, mid - 1, nums);
        root->right = construct_tree(mid+1, end, nums);

        return root;
    }
};