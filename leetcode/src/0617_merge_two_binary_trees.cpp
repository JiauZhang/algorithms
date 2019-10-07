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

/**
 * https://leetcode-cn.com/problems/merge-two-binary-trees
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 题目：
 *     给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，
 *     两个二叉树的一些节点便会重叠。
 *     你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，
 *     那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。
 * 
 * 示例 1:
 * 
 * 输入: 
 *       Tree 1                     Tree 2                  
 *          1                         2                             
 *         / \                       / \                            
 *        3   2                     1   3                        
 *       /                           \   \                      
 *      5                             4   7                  
 * 输出: 
 * 合并后的树:
 *         3
 *        / \
 *       4   5
 *      / \   \ 
 *     5   4   7
 * 
 * 注意: 合并必须从两个树的根节点开始。 * 
 * 
 * 解题思路：
 *    既然是合并两个树，那么肯定就不需要额外的空间去重建树结构了
 *    根据合并规则可知，只需要对重合的节点求和即可
 *    树结构可拆分为根节点、左子树、右子树，故可用递归方法
 *    0. 选择一颗树为待更新的树
 *    1. 当一个节点为空，另一个节点不为空时，直接返回该节点即可
 *    2. 当两个节点都不为空时，合并两个节点的值到待更新树上
 *       然后再递归到左右子树即可
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL)
            return t2;
        if (t2 == NULL)
            return t1;
        
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        
        return t1;
    }
};