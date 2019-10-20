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
* https://leetcode-cn.com/problems/valid-palindrome
* 题目描述：
*     给定一个字符串，验证它是否是回文串，只考虑字母和数字字符
*     可以忽略字母的大小写
* 
* 说明：
*     本题中，我们将空字符串定义为有效的回文串
* 
* 示例 1:
*     输入: "A man, a plan, a canal: Panama"
*     输出: true
* 
* 示例 2:
*     输入: "race a car"
*     输出: false
* 
* 解题思路：
*     双指针即可，注意跳过除了英文字符、数字之外的字符即可
*/

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() <= 1)
            return true;

        int head = -1, tail = s.size();
        move(s, head, 1);
        move(s, tail, -1);
        while (head < tail) {
            if (is_equal(s[head], s[tail])) {
                move(s, head, 1);
                move(s, tail, -1);
            } else {
                return false;
            }
        }

        return true;
    }

    void move(string &str, int &index, int offset) {
        index += offset;
        while (index < str.size() && index >= 0 &&
            !((str[index]>='a' && str[index] <= 'z') ||
            (str[index] >= 'A' && str[index] <= 'Z') ||
            (str[index] >= '0' && str[index] <= '9'))
        ) {
            index += offset;
        }
    }

    bool is_equal(unsigned char c1, unsigned char c2) {
        if (c1 <= '9')
            return num_is_equal(c1, c2);
        else
            return char_is_equal(c1, c2);
    } 

    bool char_is_equal(unsigned char &c1, unsigned char &c2) {
        const unsigned char diff = 'a' - 'A';
        if (c1 == c2)
            return true;
        if (c1 > c2)
            return (c1 == (c2+diff));
        else
            return (c2 == (c1+diff));
    }

    inline bool num_is_equal(unsigned char &c1, unsigned char &c2) {
        return (c1 == c2);
    }
};