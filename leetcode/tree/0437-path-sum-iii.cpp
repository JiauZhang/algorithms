/*
* Copyright(c) 2021 Jiau Zhang
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
 * 解题思路：
 *     朴素的做法就是以逐个节点为起点递归统计可能性的综合，但是存在太多的重复计算
 *     所以这里引入了前缀和，即记录从根节点到当前节点所有路径的和的中间结果
 *     当遍历到当前节点的时候，反向的查找是否存在某些节点的前缀和差值正好等于 target 的
 *     这一方向查找就避免了朴素做法中的以每个节点为起点查找的操作，消除了重复计算
 */

class Solution {
private:
    unordered_map<long long, int> buffer;
public:
    int pathSum(TreeNode* root, int targetSum) {
        buffer[0] = 1;
        return do_path(root, 0, targetSum);
    }

    int do_path(TreeNode *root, int cur, int target) {
        if (root == nullptr)
            return 0;
        
        int ret = 0;
        cur += root->val;
        if (buffer.count(cur-target)) // 反向查找符合要求的节点
            ret = buffer[cur-target];
        
        buffer[cur]++;
        ret += do_path(root->left, cur, target) + do_path(root->right, cur, target);
        buffer[cur]--;

        return ret;
    }
};