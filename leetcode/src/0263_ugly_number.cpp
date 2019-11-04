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
* https://leetcode-cn.com/problems/ugly-number
* 题目描述：
*     编写一个程序判断给定的数是否为丑数。
*     丑数就是只包含质因数 2, 3, 5 的正整数。
* 
* 示例 1:
*     输入: 6
*     输出: true
*     解释: 6 = 2 × 3
* 
* 示例 2:
*     输入: 8
*     输出: true
*     解释: 8 = 2 × 2 × 2
* 
* 示例 3:
*     输入: 14
*     输出: false 
*     解释: 14 不是丑数，因为它包含了另外一个质因数 7
* 
* 说明：
*     1 是丑数。
*     输入不会超过 32 位有符号整数的范围: [−231,  231 − 1]
*/

class Solution {
public:
    bool isUgly(int num) {
        if (num < 1)
            return false;

        factor(num, 2);
        factor(num, 3);
        factor(num, 5);

        return num == 1;
    }

    void factor(int &num, int f) {
        while (num % f == 0)
            num /= f;
    }
};