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
* https://leetcode-cn.com/problems/is-subsequence
* 题目描述：
*     给定字符串 s 和 t ，判断 s 是否为 t 的子序列
*     你可以认为 s 和 t 中仅包含英文小写字母
*     字符串 t 可能会很长（长度 ~= 500,000）
*     而 s 是个短字符串（长度 <=100）
*     字符串的一个子序列是原始字符串删除一些（也可以不删除）字符
*     而不改变剩余字符相对位置形成的新字符串
*     例如，"ace"是"abcde"的一个子序列，而"aec"不是
* 
* 示例 1:
*     s = "abc", t = "ahbgdc"
*     返回 true.
* 
* 示例 2:
*     s = "axc", t = "ahbgdc"
*     返回 false.
* 
* 后续挑战 :
*     如果有大量输入的 S，称作S1, S2, ... , Sk 其中 k >= 10亿
*     你需要依次检查它们是否为 T 的子序列
*     在这种情况下, 你会怎样改变代码
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        unsigned int si = 0, ti = 0;
        while (si<s.size() && ti<t.size()) {
            if (s[si] == t[ti]) {
                si++;
                ti++;
            } else {
                ti++;
            }
        }

        return si == s.size();
    }
};