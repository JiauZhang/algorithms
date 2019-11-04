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
* https://leetcode-cn.com/problems/add-digits
* 题目描述：
*     给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数
* 
* 示例:
*     输入: 38
*     输出: 2 
* 解释: 
*     各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。由于 2 是一位数，所以返回 2
* 
* 进阶:
*     你可以不使用循环或者递归，且在 O(1) 时间复杂度内解决这个问题吗？
*/

class Solution {
public:
    int addDigits(int num) {
        if (num == 0)
            return 0;

        int res = num % 9;
        if (res == 0)
            res = 9;
        return res;
    }
};