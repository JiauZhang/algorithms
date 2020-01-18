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

/*
* https://leetcode-cn.com/problems/max-consecutive-ones
* 题目描述：
*     给定一个二进制数组， 计算其中最大连续1的个数
* 
* 示例 1:
*     输入: [1,1,0,1,1,1]
*     输出: 3
* 解释: 
*     开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3
* 
* 注意：
*     输入的数组只包含 0 和1
*     输入数组的长度是正整数，且不超过 10,000
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, temp = 0;
        for (auto n: nums) {
            if (n) {
                temp++;
            } else if (temp) {
                res = max(res, temp);
                temp = 0;
            }
        }
        res = max(res, temp);

        return res;
    }
};