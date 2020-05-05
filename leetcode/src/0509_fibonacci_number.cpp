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
* https://leetcode-cn.com/problems/fibonacci-number
* 斐波那契数，通常用 F(n) 表示，形成的序列称为斐波那契数列
* 该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和
* 也就是：
*     F(0) = 0,   F(1) = 1
*     F(N) = F(N - 1) + F(N - 2), 其中 N > 1
* 给定 N，计算 F(N)。
* 
* 示例 1：
*     输入：2
*     输出：1
* 解释：
*     F(2) = F(1) + F(0) = 1 + 0 = 1
* 
* 示例 3：
*     输入：4
*     输出：3
* 解释：
*     F(4) = F(3) + F(2) = 2 + 1 = 3
*/

class Solution {
public:
    int fib(int N) {
        if (N <= 0)
            return 0;

        if (N == 1)
            return 1;

        int f_n_1 = 0, f_n = 1;
        for (int i=2; i<=N; i++) {
            int temp = f_n + f_n_1;
            f_n_1 = f_n;
            f_n = temp;
        }

        return f_n;
    }
};