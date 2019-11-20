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
* https://leetcode-cn.com/problems/arranging-coins
* 题目描述：
*     你总共有 n 枚硬币，你需要将它们摆成一个阶梯形状
*     第 k 行就必须正好有 k 枚硬币
*     给定一个数字 n，找出可形成完整阶梯行的总行数
*     n 是一个非负整数，并且在32位有符号整型的范围内
* 
* 示例 1:
*     n = 5
*     硬币可排列成以下几行:
*     ¤
*     ¤ ¤
*     ¤ ¤
*     因为第三行不完整，所以返回2
* 
* 示例 2:
*     n = 8
*     硬币可排列成以下几行:
*     ¤
*     ¤ ¤
*     ¤ ¤ ¤
*     ¤ ¤
*     因为第四行不完整，所以返回3
* 
* 解题思路：
*     等差数组求和公式即可
*/

class Solution {
public:
    int arrangeCoins(int n) {
        unsigned int un = n;
        double s = sqrt(2*un+0.25) - 0.5;
        int k = (int)s;

        return k;
    }
};