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
* https://leetcode-cn.com/problems/repeated-substring-pattern
* 题目描述：
*     给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成
*     给定的字符串只含有小写英文字母，并且长度不超过10000
* 
* 示例 1:
*     输入: "abab"
*     输出: True
* 解释: 
*     可由子字符串 "ab" 重复两次构成。
* 
* 示例 2:
*     输入: "aba"
*     输出: False
* 
* 示例 3:
*     输入: "abcabcabcabc"
*     输出: True
* 解释: 
*     可由子字符串 "abc" 重复四次构成
*     或者子字符串 "abcabc" 重复两次构成
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() <= 1)
            return false;

        for (int i=1; i<=s.size()/2; i++) {
            if (s.size() % i)
                continue;
            int j;
            for (j=i; j<s.size()&&s[j]==s[j%i]; j++);
            if (j == s.size())
                return true;
       }

        return false;
    }
};