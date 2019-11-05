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
* https://leetcode-cn.com/problems/word-pattern
* 题目描述：
*     给定一种规律 pattern 和一个字符串 str
*     判断 str 是否遵循相同的规律
*     这里的 遵循 指完全匹配，例如
*     pattern 里的每个字母和字符串 str 
*     中的每个非空单词之间存在着双向连接的对应规律
* 
* 示例1:
*     输入: pattern = "abba", str = "dog cat cat dog"
*     输出: true
* 
* 示例 2:
*     输入:pattern = "abba", str = "dog cat cat fish"
*     输出: false
* 
* 示例 3:
*     输入: pattern = "aaaa", str = "dog cat cat dog"
*     输出: false
* 
* 示例 4:
*     输入: pattern = "abba", str = "dog dog dog dog"
*     输出: false
* 
* 说明:
*     你可以假设 pattern 只包含小写字母
*     str 包含了由单个空格分隔的小写字母
* 
* 解题思路：
*     双映射，使用 map 类型的数据结构即可，不过我这里
*     使用的是 hash 和 set 完成的，思想都是一样的，检查双映射即可
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        string hash[26];
        const char base = 'a';
        int offset = 0, p = 0;
        set<string> unique;
        for (; p<pattern.size(); p++) {
            char index = pattern[p] - base;
            string word = get_word(str, offset);
            /* check if str is shorter */
            if (word.empty())
                return false;

            if (hash[index].size()) {
                if (word != hash[index])
                    return false;
            } else if (unique.count(word)) {
                return false;
            } else {
                hash[index] = word;
                unique.insert(word);
            }
        }
        /* check if pattern is shorter */
        return  offset == str.size();
    }

    string get_word(string &str, int &offset) {
        while (offset<str.size() && str[offset] == ' ')
            offset++;
        string word;
        while (offset<str.size() && str[offset] != ' ')
            word += str[offset++];

        return word;        
    }
};