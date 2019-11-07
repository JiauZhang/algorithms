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
* https://leetcode-cn.com/problems/power-of-three
* 题目描述：
*     给定一个整数，写一个函数来判断它是否是 3 的幂次方
* 
* 示例 1:
*     输入: 27
*     输出: true
* 
* 示例 2:
*     输入: 0
*     输出: false
* 
* 示例 3:
*     输入: 9
*     输出: true
* 
* 示例 4:
*     输入: 45
*     输出: false
* 
* 进阶：
*     你能不使用循环或者递归来完成本题吗？
* 
* 解题思路：
*     1. 逐个除 3 判断是否整除
*     2. 将原数转化为 3 进制，如果是 3 的幂，则只含有一个 1
*        但该方法操作比方法 1 还复杂，但方法比较新颖
*     3. 找到 3 的幂的最大值，如果给定的数是 3 的幂，那么
*        一定可以被最大数整除，这个方法也有点意思，代码如下
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        /*
        int max = log(INT_MAX) / log(3);
        max = pow(3, max);
        */
        int max = 1162261467;

        return max % n == 0;
    }
};