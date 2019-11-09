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
* https://leetcode-cn.com/problems/ransom-note
* 题目描述：
*     给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串
*     判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成
*     如果可以构成，返回 true ；否则返回 false
* 题目说明：
*     为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母
*     组成单词来表达意思
* 
* 注意：
*     你可以假设两个字符串均只含有小写字母
* 
* 示例：
*     canConstruct("a", "b") -> false
*     canConstruct("aa", "ab") -> false
*     canConstruct("aa", "aab") -> true
* 
* 解题思路：
*     该题目其实就是判断另一个字符串中是否含有不少于给定字符串
*     数量的字符元素，使用映射统计即可，可以使用 map, unordered_map
*     不过最快速的方法时使用 数组
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() == 0)
            return true;

        if (magazine.size() == 0)
            return false;

        unsigned int r[26] = {0}, m[26] = {0};
        make_hash(ransomNote, r);
        make_hash(magazine, m);

        for (int i=0; i<26; i++) {
            if (r[i] > m[i])
                return false;
        }

        return true;
    }

    void make_hash(string &s, unsigned int m[]) {
        const char base = 'a';
        for (int i=0; i<s.size(); i++) {
            m[s[i]-base]++;
        }
    }
};