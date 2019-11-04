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
* https://leetcode-cn.com/problems/missing-number
* 题目描述：
*     给定一个包含 0, 1, 2, ..., n 中 n 个数的序列
*     找出 0 .. n 中没有出现在序列中的那个数。
* 
* 示例 1:
*     输入: [3,0,1]
*     输出: 2
* 
* 示例 2:
*     输入: [9,6,4,2,3,5,7,0,1]
*     输出: 8
* 
* 说明:
*     你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
* 
* 解题思路：
*     1. 递增数组求和公式
*     2. 官方给出的异或运算方法，方法很新颖，比较有意思
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = (nums.size() + 1) * nums.size() / 2;
        int sum = 0;
        for (int i=0; i<nums.size(); i++)
            sum += nums[i];
        
        return res-sum;
    }
};