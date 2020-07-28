/*
 * Copyright(c) 2020 Jiau Zhang
 * For more information see <https://github.com/JiauZhang/algorithms>
 * 
 * SPDX-License-Identifier: GPL
 */

/*
 * 解题思路：首先二叉搜索树的特点就是右节点比左节点大，再根据题意
 * 需要累加比自己大的，所以就从大的往小的累加，即先访问右节点
 * 再访问当前节点，最后访问左节点即可 
 */

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        
        int sum = 0;
        do_convert(root, sum);

        return root;
    }

    void do_convert(TreeNode *root, int &sum) {
        if (root->right)
            do_convert(root->right, sum);
        
        root->val = root->val + sum;
        sum = root->val;

        if (root->left)
            do_convert(root->left, sum);
    }
};