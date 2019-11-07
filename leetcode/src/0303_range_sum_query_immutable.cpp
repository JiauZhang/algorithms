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
* https://leetcode-cn.com/problems/range-sum-query-immutable
* 题目描述：
*     给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j)
*     范围内元素的总和，包含 i,  j 两点。
* 
* 示例：
*     给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()
*     sumRange(0, 2) -> 1
*     sumRange(2, 5) -> -1
*     sumRange(0, 5) -> -3
* 
* 说明:
*     你可以假设数组不可变。
*     会多次调用 sumRange 方法。
* 
* 解题思路：
*     计算一个积分表即可，了解图像处理的都知道有图像积分这个概念
*/

class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        if (nums.empty())
            return;

        sum.resize(nums.size());
        sum[0] = nums[0];
        for (int i=1; i<nums.size(); i++)
            sum[i] = sum[i-1] + nums[i];
    }
    
    int sumRange(int i, int j) {
        if (i == 0)
            return sum[j];
        else
            return sum[j]-sum[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */