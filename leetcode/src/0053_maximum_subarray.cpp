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
* https://leetcode-cn.com/problems/maximum-subarray
* 题目描述：
*     给定一个整数数组 nums ，找到一个具有最大和的连续子数组(子数组最少包含一个元素)
*     返回其最大和
* 
* 示例:
*     输入: [-2,1,-3,4,-1,2,1,-5,4],
*     输出: 6
*     解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
* 
* 进阶:
*     如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
* 
* 解题思路：
*     1. 这里使用的方法不是分治法，分治法时间复杂度反而变高了
*     2. 直接一次性扫描数组即可，每当当前和变为负数时，就重新计数即可
*        同时记录最大值
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN, sum = 0;
        for (int i=0; i<nums.size(); i++) {
            if (sum < 0) {
                sum = nums[i];
            } else {
                sum += nums[i];
            }

            if (sum > max)
                max = sum;
        }

        return max;
    }
};