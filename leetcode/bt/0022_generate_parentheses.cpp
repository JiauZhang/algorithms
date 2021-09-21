/*
* Copyright(c) 2021 Jiau Zhang
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
https://leetcode-cn.com/problems/generate-parentheses/
题目描述：
    数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且有效的括号组合
    有效括号组合需满足：左括号必须以正确的顺序闭合

 解题思路：
    核心思路就是在递归的过程中只有左括号的数量必须大于等于有括号，当右括号多时
    已经无法形成有效括号了
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        generate(res, str, n, n);

        return res;
    }

    void generate(vector<string> &res, string &str, int left, int right) {
        if (left == 0 && right == 0) {
            res.push_back(str);
            return;
        }

        if (right > left) {
            if (left > 0) {
                str.push_back('(');
                generate(res, str, left-1, right);
                str.pop_back();
            }

            str.push_back(')');
            generate(res, str, left, right-1);
            str.pop_back();
        } else {
            str.push_back('(');
            generate(res, str, left-1, right);
            str.pop_back();
        }
    }
};