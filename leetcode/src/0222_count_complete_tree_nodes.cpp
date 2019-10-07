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
 题目描述：
     给出一个完全二叉树，求出该树的节点个数。
     完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，
     并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。
     
     struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };
    
 示例:
 
 输入: 
     1
    / \
   2   3
  / \  /
 4  5 6
 
 输出: 6
 https://leetcode-cn.com/problems/count-complete-tree-nodes
 
 解题思路：
     0. 检查左子树的最左子节点深度和右子树最右子节点深度，如果深度相同
        则为满完全二叉树，否则不是
     1. 如果是满完全二叉树，则直接用公式 2^n - 1 计算即可，其中
        2^n = 1 << n
     2. 如果不是满完全二叉树，则递归求解左右子树
        1 + countNodes(root->left) + countNodes(root->right)
        其中 1 表示根节点
     3. 该方法之所以快，是因为把非满完全二叉树分割成了小的树
        这样即使大树不满，而小树部分是满的，所以可以加速计数
        浪费计算的只有不满的部分，可以说大概节约了一般的时间
        相比于暴力计数而言~

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
    int countNodes(TreeNode* root) {
       if (root == NULL)
           return 0;
        
        int left_level = get_left_level(root);
        int right_level = get_right_level(root);
        
        if (left_level == right_level)
            return ((1<<left_level) - 1);
        
        return 1 + countNodes(root->left) + countNodes(root->right);
        
        
    }
    
    int get_left_level(TreeNode *root) {
        if (root == NULL)
            return 0;
        
        int level = 1;
        while (root->left) {
            level++;
            root = root->left;
        }
        
        return level;
    }
    
    int get_right_level(TreeNode *root) {
        if (root == NULL)
            return 0;
        
        int level = 1;
        while (root->right) {
            level++;
            root = root->right;
        }
        
        return level;
    }
};