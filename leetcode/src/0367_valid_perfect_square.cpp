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
* https://leetcode-cn.com/problems/valid-perfect-square
* 题目描述：
*     给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数
*     则返回 True，否则返回 False。
* 
* 说明：
*     不要使用任何内置的库函数，如 sqrt
* 
* 示例 1：
*     输入：16
*     输出：True
* 
* 示例 2：
*     输入：14
*     输出：False
* 
* 解题思路：
*     1. 二分法；2. 等差数列法(N^2 = 所有奇数的和)
*     3. 位运算法: 从高位开始判断是否为 1，最多 31/2 = 15 位
*     2, 3 方法比较新颖，但是方法 1 速度最快
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        /* num is bigger than zero */
        if (num <= 1)
            return true;

        int left = 2, right = num/2;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid < num / mid)
                left = mid + 1;
            else if (mid > num / mid)
                right = mid - 1;
            /* check the remainder */
            else if (num % mid == 0)
                return true;
            else
                return false;
        }

        return ((left == num / left) && (num % left == 0));
    }
};