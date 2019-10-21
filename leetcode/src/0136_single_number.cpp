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
* https://leetcode-cn.com/problems/single-number
* 题目描述：
*     给定一个非空整数数组，除了某个元素只出现一次以外
*     其余每个元素均出现两次。找出那个只出现了一次的元素
* 
* 说明：
*     你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
* 
* 示例 1:
*     输入: [2,2,1]
*     输出: 1
* 
* 示例 2:
*     输入: [4,1,2,1,2]
*     输出: 4
* 
* 解题思路：
*     由于只有一个数只出现一次，且其他数都出现两次
*     则可以通过 异或 操作来消除出现两次的数，从而保留只出现一次的数
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for (int i=1; i<nums.size(); i++) {
            res ^= nums[i];
        }

        return res;
    }
};