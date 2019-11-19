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
* https://leetcode-cn.com/problems/longest-palindrome
* 题目描述：
*     给定一个包含大写字母和小写字母的字符串
*     找到通过这些字母构造成的最长的回文串
*     在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串
* 
* 注意:
*     假设字符串的长度不会超过 1010
* 
* 示例 1:
*     输入:
*     "abccccdd"
* 
* 输出:
*     7
* 
* 解释:
*     我们可以构造的最长的回文串是"dccaccd", 它的长度是 7
* 
* 解题思路：
*     既然是回文字符串，那么肯定需要成对出现，所以第一步是同时字符数
*     然后计算出现偶数次数的总和，最后再加上一个，即放在中间的字符
*     这个总数就是题解了
*/

class Solution {
public:
    int longestPalindrome(string s) {
        if (s.size() <= 1)
            return s.size();

        unsigned int hash_lower[26] = {0};
        unsigned int hash_upper[26] = {0};

        for (auto c: s) {
            if (c <= 'Z')
                hash_upper[c - 'A']++;
            else
                hash_lower[c - 'a']++;
        }

        int res = 0;
        for (int i=0; i<26; i++) {
            if (hash_lower[i] >= 2)
                res += (hash_lower[i] & (~0x01));
            if (hash_upper[i] >= 2)
                res += (hash_upper[i] & (~0x01));
        }

        if (res < s.size())
            res++;
        
        return res;
    }
};