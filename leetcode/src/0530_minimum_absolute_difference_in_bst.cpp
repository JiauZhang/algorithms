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

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr)
            return -1;

        int min = INT_MAX;
        TreeNode *prev = nullptr;

        find_min(root, &prev, min);

        return min;
    }

    void find_min(TreeNode *root, TreeNode **prev, int &min) {
        if (root->left)
            find_min(root->left, prev, min);

        if (*prev) {
            int tmp = root->val - (*prev)->val;
            min = tmp > min ? min : tmp;
        }

        *prev = root;

        if (root->right)
            find_min(root->right, prev, min);
    }
};