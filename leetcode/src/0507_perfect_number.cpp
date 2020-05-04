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
* https://leetcode-cn.com/problems/perfect-number
* 题目描述：
*     对于一个 正整数，如果它和除了它自身以外的所有正因子之和相等
*     我们称它为“完美数”，给定一个 整数 n， 如果他是完美数
*     返回 True，否则返回 False
* 
* 示例：
*     输入: 28
*     输出: True
*     解释: 28 = 1 + 2 + 4 + 7 + 14
*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        // 负数及 1 直接返回 false
        if (num <= 1)
            return false;

        bool res = true;
        int sum = 1, loop = 2;
        // 求各个因子的和
        while (loop <= sqrt(num)) {
            if (num % loop == 0) {
                sum += loop;
                sum += num / loop;
            }
            loop++;
        }
        // 如果恰好能够开方，则上一步多加了一个因子
        int s = sqrt(num);
        if (s*s == num)
            sum -= s;

        if (sum != num)
            res = false;

        return res;
    }
};