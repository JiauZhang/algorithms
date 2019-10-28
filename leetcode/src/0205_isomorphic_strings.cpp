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
* https://leetcode-cn.com/problems/isomorphic-strings
* 题目描述：
*     给定两个字符串 s 和 t，判断它们是否是同构的
*     如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的
*     所有出现的字符都必须用另一个字符替换，同时保留字符的顺序
*     两个字符不能映射到同一个字符上，但字符可以映射自己本身。
* 
* 示例 1:
*     输入: s = "egg", t = "add"
*     输出: true
* 
* 示例 2:
*     输入: s = "foo", t = "bar"
*     输出: false
* 
* 示例 3:
*     输入: s = "paper", t = "title"
*     输出: true
* 
* 说明:
*     你可以假设 s 和 t 具有相同的长度
* 
* 解题思路：
*     该题其实就是解决双映射问题，建立两个 hash 表即可
*     测试发现，unordered_map 实现的 hash 与自己用 vector 实现的
*     速度相差一倍，具体见程序注释
*/

/* 16ms */
class Solution_1 {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() == 0 && t.size() == 0)
            return true;        
        if (s.size() == 0 || t.size() == 0)
            return false;

        unordered_map<char, char> hash;
        unordered_map<char, char> ihash;
        for (int i=0; i<s.size(); i++) {
            if (hash.count(s[i])) {
                if (hash[s[i]] != t[i])
                    return false;
            } else {
                hash[s[i]] = t[i];
            }

            if (ihash.count(t[i])) {
                if (ihash[t[i]] != s[i])
                    return false;
            } else {
                ihash[t[i]] = s[i];
            }
        }

        return true;
    }
};

/* 8ms 95.83% */
class Solution_2 {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() == 0 && t.size() == 0)
            return true;        
        if (s.size() == 0 || t.size() == 0)
            return false;

        vector<char> hash(256, 0);
        vector<char> ihash(256, 0);
        for (int i=0; i<s.size(); i++) {
            if (hash[s[i]]) {
                if (hash[s[i]] != t[i])
                    return false;
            } else {
                hash[s[i]] = t[i];
            }

            if (ihash[t[i]]) {
                if (ihash[t[i]] != s[i])
                    return false;
            } else {
                ihash[t[i]] = s[i];
            }
        }

        return true;
    }
};