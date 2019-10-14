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
* https://leetcode-cn.com/problems/climbing-stairs
* 题目描述：
*     假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
*     每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
* 
* 解题思路：
*     斐波那契数列
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;

        if (n == 2)
            return 2;

        int n_1 = 2, n_2 = 1;
        int nn = 3, step;
        while (nn <= n) {
            step = n_1 + n_2;
            n_2 = n_1;
            n_1 = step;
            nn++;
        }

        return step;
    }
};