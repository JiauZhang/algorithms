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
* https://leetcode-cn.com/problems/sqrtx
* 题目描述：
*     实现 int sqrt(int x) 函数。
*     计算并返回 x 的平方根，其中 x 是非负整数。
*     由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
* 
* 解题思路：
*     使用二分法，需要注意的问题就是数据溢出问题，解释见代码注释
*/

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;

        if (x <= 3)
            return 1;

        unsigned int head = 2, end = x / 2;
        while (head < end) {
            /* signed type can detect the overflow */
            /* but the multiple will be restricted */
            /* however unsigned cant detect overflow, so div is used! */
            unsigned int mid = head + (end - head) / 2;
            unsigned int res = x / mid;
            if (mid > res) {
                end = mid - 1;
            } else if (mid < res) {
                head = mid + 1;
            } else {
                return mid;
            }
        }

        if (head * head > x)
            return head - 1;
        return head;
    }
};