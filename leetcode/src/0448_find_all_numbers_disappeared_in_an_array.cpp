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
* https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array
* 题目描述：
*     给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组
*     数组中的元素一些出现了两次，另一些只出现一次
*     找到所有在 [1, n] 范围之间没有出现在数组中的数字
*     您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 
*     你可以假定返回的数组不算在额外空间内
* 
* 示例:
* 输入:
*     [4,3,2,7,8,2,3,1]
* 输出:
*     [5,6]
* 
* 解题思路：
*     由于不允许使用额外的空间，且时间复杂度为O(n)
*     只能在作为返回的数组上做文章了，第一遍统计出现次数
*     第二遍，即while循环，将出现次数为0的向前紧密排列即可
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if (nums.size() <= 0)
            return {};

        vector<int> res(nums.size()+1);
        // for (int i=0; i<res.size(); i++) res[i] = 0;
        for (int i=0; i<nums.size(); i++) {
            res[nums[i]]++;
        }

        int left = 0, right = 1;
        while (right < res.size()) {
            if (res[right] == 0) {
                res[left++] = right;
            }
            right++;
        }

        res.resize(left);
        return res;
    }
};