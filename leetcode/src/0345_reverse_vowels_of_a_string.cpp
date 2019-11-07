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
* https://leetcode-cn.com/problems/reverse-vowels-of-a-string
* 题目描述：
*     编写一个函数，以字符串作为输入，反转该字符串中的元音字母
* 
* 示例 1:
*     输入: "hello"
*     输出: "holle"
* 
* 示例 2:
*     输入: "leetcode"
*     输出: "leotcede"
* 
* 说明:
*     元音字母不包含字母"y"
* 
* 解题思路：
*     与 0344_reverse_string 反转字符串一样使用双指针，只不过
*     指针移动规则变了而已，具体见代码
*/

class Solution {
public:
    const char base = 'a';
    char hash[26] = {0};
    const string pattern = "aeiou";

    string reverseVowels(string s) {
        if (s.size() <= 1)
            return s;

        for (int i=0; i<pattern.size(); i++)
            hash[pattern[i]-base] = 1;

        int left = -1, right = s.size();  
        move(s, left, +1);
        move(s, right, -1);      
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            move(s, left, +1);
            move(s, right, -1);
        }

        return s;
    }

    void move(string &str, int &index, int offset) {
        index += offset;
        while (index< str.size() && !find(str[index]))
            index += offset;
    }

    bool find(char c) {
        /* ascii: A, B, ..., Z, ..., a, b, ..., z*/
        if (c<='Z' && c>='A')
            return hash[c-'A'];
        else if (c<='z' && c>='a')
            return hash[c-base];
        else
            return 0;
    }
};