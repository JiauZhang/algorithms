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
* https://leetcode-cn.com/problems/power-of-two
* 题目描述：
*     给定一个整数，编写一个函数来判断它是否是 2 的幂次方
* 
* 示例 1:
*     输入: 1
*     输出: true
*     解释: 20 = 1
* 
* 示例 2:
*     输入: 16
*     输出: true
*     解释: 24 = 16
* 
* 示例 3:
*     输入: 218
*     输出: false
* 
* 解题思路：
*     2的幂次方其实就是该数的二进制中只含有一个 1
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == INT_MIN || n == INT_MAX || n == 0)
            return false;

        return (n & (n - 1)) == 0;
    }
};