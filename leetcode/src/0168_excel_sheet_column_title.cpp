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
* https://leetcode-cn.com/problems/excel-sheet-column-title
* 题目描述：
*     给定一个正整数，返回它在 Excel 表中相对应的列名称。
* 
* 例如
*     1 -> A
*     2 -> B
*     3 -> C
*     ...
*     26 -> Z
*     27 -> AA
*     28 -> AB 
*     ...
* 
* 示例 1:
*     输入: 1
*     输出: "A"
* 
* 示例 2:
*     输入: 28
*     输出: "AB"
* 
* 示例 3:
*     输入: 701
*     输出: "ZY"
* 
* 解题思路：
*     看代码
*     
*     做这道题认识到了，动手之前要理清思路才可以
*     否则就是在浪费时间!
*/

class Solution {
public:
    string convertToTitle(int n) {
        if (n <= 0)
            return nullptr;

        const int base = 'A' - 1;
        string res;
        while (n) {
            char index, c;              
            index = n % 26;

            if (index == 0) {
                res = 'Z' + res;
                n = n / 26 - 1;
                continue;
            }

            c = index + base;
            n = n / 26;
        
            /* must be [char + string] */
            res = c + res;            
        }

        return res;
    }
};