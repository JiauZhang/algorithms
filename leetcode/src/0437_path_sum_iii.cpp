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
* https://leetcode-cn.com/problems/path-sum-iii
* 题目描述：
*     给定一个二叉树，它的每个结点都存放着一个整数值
*     找出路径和等于给定数值的路径总数
*     路径不需要从根节点开始，也不需要在叶子节点结束
*     但是路径方向必须是向下的（只能从父节点到子节点）
*     二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数
* 
* 示例：
*     root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
*           10
*          /  \
*         5   -3
*        / \    \
*       3   2   11
*      / \   \
*     3  -2   1
*     返回 3。和等于 8 的路径有:
*     1.  5 -> 3
*     2.  5 -> 2 -> 1
*     3.  -3 -> 11
* 
* 解题思路：
*     既然是连续路径，类似的题目就是连续数组求和了，所以使用积分数组
*     递归到每个节点即可
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
    int sums[1001] = {0};
    int count = 0;

    int pathSum(TreeNode* root, int sum) {
        /* no more than 1000 */
        do_path(root, sum, 1);

        return count;
    }

    void do_path(TreeNode *root, const int &target, int level) {
        if (root == nullptr)
            return;

        sums[level] = sums[level-1] + root->val;
        for (int i=0; i<level; i++)
            if (sums[level] - sums[i] == target)
                count++;

        do_path(root->left, target, level+1);
        do_path(root->right, target, level+1);
    }
};