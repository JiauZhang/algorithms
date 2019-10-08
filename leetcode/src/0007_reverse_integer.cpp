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
* https://leetcode-cn.com/problems/reverse-integer
* 题目描述：
*     给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
* 
* 示例 1:
*     输入: 123
*     输出: 321
* 
* 示例 2:
*     输入: -123
*     输出: -321
* 
* 示例 3:
*     输入: 120
*     输出: 21
* 
* 注意:
*     假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。
*     请根据这个假设，如果反转后整数溢出那么就返回 0。
* 
* 解题思路：
*     1. 逐个整数位取出，然后构造新的数即可
*     2. 注意事项是检查是否会超出最大最小值限制
*/

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x) {
            int remainder = x;
            x /= 10;
            remainder -= x * 10;
            /* 边界条件 */
            if (res > INT_MAX / 10 || res < INT_MIN / 10) {
                res = 0;
                break;
            }
            
            res *= 10;
            res += remainder;
        }
        
        return res;
    }
};