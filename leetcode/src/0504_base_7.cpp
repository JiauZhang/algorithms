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
* https://leetcode-cn.com/problems/base-7
* 题目描述：
*     给定一个整数，将其转化为7进制，并以字符串形式输出。
* 
* 示例 1:
*     输入: 100
*     输出: "202"
* 
* 示例 2:
*     输入: -7
*     输出: "-10"
*/

class Solution {
public:
    string convertToBase7(int num) {
        if (!num)
            return "0";

        unsigned n;
        string res;
        if (num < 0)
            n = -num;
        else
            n = num;

        char char_num[10] = {'0','1','2','3','4','5','6','7','8','9'};
        while (n) {
            unsigned int temp = n / 7;
            res = char_num[n-7*temp] + res;
            n = temp;
        }
        if (num < 0)
            res = "-" + res;

        return res;
    }
};
