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
* https://leetcode-cn.com/problems/first-unique-character-in-a-string
* 题目描述：
*     给定一个字符串，找到它的第一个不重复的字符
*     并返回它的索引。如果不存在，则返回 -1
* 
* 案例:
*     s = "leetcode"
*     返回 0
*     s = "loveleetcode"
*     返回 2 
* 
* 注意事项：
*     您可以假定该字符串只包含小写字母
*/

class Solution {
public:
    int firstUniqChar(string s) {
        if (s.size() == 0)
            return -1;

        const char base = 'a';
        unsigned int hash[26] = {0};
        for (int i=0; i<s.size(); i++) {
            hash[s[i]-base]++;
        }

        for (int i=0; i<s.size(); i++) {
            if (hash[s[i]-base] == 1)
                return i;
        }

        return -1;
    }
};