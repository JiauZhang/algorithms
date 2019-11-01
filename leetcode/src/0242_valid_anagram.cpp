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
* https://leetcode-cn.com/problems/valid-anagram
* 题目描述：
*     给定两个字符串 s 和 t 
*     编写一个函数来判断 t 是否是 s 的字母异位词
* 
* 示例 1:
*     输入: s = "anagram", t = "nagaram"
*     输出: true
* 
* 示例 2:
*     输入: s = "rat", t = "car"
*     输出: false
* 
* 说明:
*     你可以假设字符串只包含小写字母
* 
* 进阶:
*     如果输入字符串包含 unicode 字符怎么办？
*     你能否调整你的解法来应对这种情况？
* 
* 解题思路：
*     这类题目直接 哈希表 即可解决 O(n)
*     另一种方法就是先排序，再逐个字符比较 O(nlogn)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        char shash[256] = {0};
        char thash[256] = {0};
        for (int i=0; i<s.size(); i++) {
            shash[s[i]]++;
            thash[t[i]]++;
        }

        for (int i=0; i<256; i++) {
            if (shash[i] != thash[i])
                return false;
        }

        return true;
    }
};