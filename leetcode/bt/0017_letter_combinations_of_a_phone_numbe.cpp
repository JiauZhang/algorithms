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
https://leetcode-cn.com/problems/3sum-closest
题目描述：
    给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按任意顺序返回

 解题思路：
    根据题意肯定是递归遍历所有组合了，关键是现在给定数字个数是不定的，递归的深度就依赖于数字字符串的长度
    然后就是局部维护一个字符串作为下一次递归的前缀，知道遍历到终止条件即完成了一个字符组合
*/

class Solution {
public:
    const vector<string> maps = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
    };

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};
        
        vector<string> res;
        make_string(res, digits, "", 0);

        return res;
    }

    void make_string(vector<string> &res, string &digits, string prefix, int start) {
        if (start == digits.size()) {
            res.push_back(prefix);
        } else {
            string cur_string = maps[digits[start] - '0'];
            for (auto c: cur_string) {
                prefix.push_back(c);
                make_string(res, digits, prefix, start+1, end);
                prefix.pop_back();
            }
        }
    }
};