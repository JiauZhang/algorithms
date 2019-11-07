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
* https://leetcode-cn.com/problems/power-of-four
* 题目描述：
*     给定一个整数 (32 位有符号整数)
*     请编写一个函数来判断它是否是 4 的幂次方
* 
* 示例 1:
*     输入: 16
*     输出: true
* 
* 示例 2:
*     输入: 5
*     输出: false
* 
* 进阶：
*     使用循环或者递归来完成本题吗？
* 
* 解题思路：
*     根据 4 的幂的规律，先判断是否是 2 的幂，然后判断是否是 4 的幂
*/

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0)
            return false;

        if ((num & (num-1)) != 0)
            return false;
        
        const int check = 0x55555555;
        if ((num | check) != check)
            return false;

        return true;
    }
};