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
* https://leetcode-cn.com/problems/sum-of-two-integers
* 题目描述：
*     不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和
* 
* 示例 1:
*     输入: a = 1, b = 2
*     输出: 3
* 
* 示例 2:
*     输入: a = -2, b = 3
*     输出: 1
* 
* 解题思路：
*     根据二进制加法原则，使用 异或 实现 加 法
*     使用 与 运算实现 进位
*/

class Solution {
public:
    int getSum(int a, int b) {
        /* carray is unsinged int */
        int carry = (unsigned int)(a & b) << 1;
        int sum = a ^ b;
        while (carry) {
            int temp = sum & carry;
            sum ^= carry;
            carry = (unsigned int)temp << 1;
        }

        return sum;
    }
};