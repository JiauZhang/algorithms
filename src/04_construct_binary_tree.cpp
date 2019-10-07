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
 *题目描述
 *    输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
 *    假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 *    例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
 *    则重建二叉树并返回。
 *
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
 解题思路：
    前序遍历：根节点->左节点->右节点
    中序遍历：左节点->根节点->右节点
    所以前序遍历的第一个数就根节点，中序遍历中的根节点左边的
    就是左子树，右边的是右子树，递归解决即可。
 */

/* 该方法需要来回复制vector，浪费内存 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.size() == 0 || pre.size() ==0)
            return NULL;
        
        TreeNode *root = new TreeNode(pre[0]);
        
        vector<int> left_pre, left_vin;
        vector<int> right_pre, right_vin;
        bool flag = 0;
        int length = pre.size();
        for (int i=0; i<length; i++) {
            if (vin[i] != pre[0] && flag == 0) {
                left_vin.push_back(vin[i]);
                left_pre.push_back(pre[i+1]);
            } else if (flag == 0) {
                flag = 1;
            } else {
                right_vin.push_back(vin[i]);
                right_pre.push_back(pre[i]);
            }
        }
        
        TreeNode *pLeft = reConstructBinaryTree(left_pre, left_vin);
        TreeNode *pRight = reConstructBinaryTree(right_pre, right_vin);
        
        root->left = pLeft;
        root->right = pRight;
        
        
        return root;
    }
};

/* 在vector中就地比较，不需要复制，能节省内存 */
class Solution {
public:
    TreeNode *reConstruct(vector<int> &pre, int pstart, int pend, \
                          vector<int> &vin, int vstart, int vend) {
        if (pstart>=pend || vstart>=vend)
            return NULL;
        
        TreeNode *root = new TreeNode(pre[pstart]);
        int vin_start = vstart;
        for (; vin_start<vend; vin_start++) {
            if (vin[vin_start] == pre[pstart])
                break;
        }
        int dv = vin_start - vstart;
        /* 前序中左子树和右子树是紧挨着的，所以首尾相接 */
        /* 中序中左右子树是被更节点分开的，所以索引值并不连续 */
        TreeNode *pLeft = reConstruct(pre, pstart+1, pstart+dv+1, vin, vstart, vin_start);
        TreeNode *pRight = reConstruct(pre, pstart+dv+1, pend, vin, vin_start+1, vend);
        
        root->left = pLeft;
        root->right = pRight;
        
        return root;
        
    }
    
    
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.size() == 0 || pre.size() ==0)
            return NULL;
        return reConstruct(pre, 0, pre.size(), vin, 0, vin.size());
    }
};