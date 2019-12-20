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
* https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements
* 题目描述：
*     给定一个长度为 n 的非空整数数组，找到让数组所有元素相等的最小移动次数
*     每次移动可以使 n - 1 个元素增加 1
* 
* 示例:
* 输入:
*     [1,2,3]
* 输出:
*     3
* 
* 解释:
*     只需要3次移动（注意每次移动会增加两个元素的值）：
*     [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
* 
* 解题思路：
*     1. 同时增加最大值之外的数等价于仅减小最大值
*     2. 对数组进行排序，使用动态规划
*/

// solution #1
class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;

        int min = nums[0];
        for (int i=0; i<nums.size(); i++) {
            min = nums[i]<min ? nums[i] : min;
        }

        int res = 0;
        for (int i=0; i<nums.size(); i++) {
            res += nums[i] - min;
        }

        return res;
    }
};
// solution #2
class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;

        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i=1; i<nums.size(); i++) {
            int diff = res + nums[i] - nums[i-1];
            nums[i] += res;
            res += diff;
        }

        return res;
    }
};