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
https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
题目描述：
    给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
    输入: s = "abcabcbb"
    输出: 3 
    解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3

 解题思路：
    因为要查找不重复的子串，所以需要能快速查找一个字符是否出现过，又因为字符有限多
    故使用固定长度数组来做哈希表，然后就是用两个指针来指示出字串的位置
    如果快指针对应的字符出现过，那么慢指针直接跳到上次出现的位置的下一个位置即可
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        
        int next[256] = {0};
        int left = 0, right = 1;
        int ml = 1;

        next[s[0]] = 0;
        while (right < s.size()) {
            char offset = s[right];
            if (next[offset] >= left && s[right] == s[next[offset]]) {
                left = next[offset] + 1;
            }
            next[offset] = right;
            right++;
            if (right - left > ml)
                ml = right - left;
        }

        return ml;
    }
};