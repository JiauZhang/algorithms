/*
* Copyright(c) 2020 Jiau Zhang
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
* https://leetcode-cn.com/problems/find-mode-in-binary-search-tree
* 题目描述：
*     给定一个有相同值的二叉搜索树（BST）
*     找出 BST 中的所有众数（出现频率最高的元素）
* 
* 假定 BST 有如下定义：
*     结点左子树中所含结点的值小于等于当前结点的值
*     结点右子树中所含结点的值大于等于当前结点的值
*     左子树和右子树都是二叉搜索树
* 
* 例如：
*     给定 BST [1,null,2,2]
*        1
*         \
*          2
*         /
*        2
*     返回[2]
* 
* 提示：
*     如果众数超过1个，不需考虑输出顺序
* 
* 解题思路：
*     由于给的是二叉搜索树，因此使用中序遍历可以按从小到大来访问各个节点
*     每次先访问左节点，然后当前节点，最后右节点
*     所有的处理都在当前节点中，如果当前节点与上一个相等，则计数++
*     如果不等，则说明遇到了新的数值，则处理上一个数值是否为众数
*     然后重新初始化相关变量，继续下次递归调用
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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int max = 0, cur = 0;
        TreeNode *prev = nullptr;

        if (root) {
            prev = root;
            do_find_mode(root, prev, max, cur, res);
            // add the last node value
            if (cur > max) {
                res.clear();                
                res.push_back(prev->val);
                max = cur;
            } else if (cur == max) {
                res.push_back(prev->val);
            }
        }

        return res;
    }
    // 1 1 2 3 4 4 5 5 5 6 7 9 9 9
    // 1 2 3 3 3 4 4 5 6 7 7 7 7 8
    void do_find_mode(TreeNode *root, TreeNode* &prev, int &max, int &cur, vector<int> &res) {
        // left node
        if (root->left) {
            do_find_mode(root->left, prev, max, cur, res);
        }

        // current node
        if (root->val == prev->val) {
            cur++;
        } else { // new value
            // add previous node value
            if (cur > max) {
                res.clear();                
                res.push_back(prev->val);
                max = cur;
            } else if (cur == max) {
                res.push_back(prev->val);
            }

            cur = 1;
            prev = root;
        }

        // right node
        if (root->right)
            do_find_mode(root->right, prev, max, cur, res);
    }
};