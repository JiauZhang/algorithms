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
* https://leetcode-cn.com/problems/number-of-segments-in-a-string
* 题目描述：
*     统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符
*     请注意，你可以假定字符串里不包括任何不可打印的字符
* 
* 示例:
*     输入: "Hello, my name is John"
*     输出: 5
* 
* 解题思路：
*     三步解决：
*     跳过前导空格，跳过一个非空格字符串，跳过空格直到下一个字符
*/

class Solution {
public:
    int countSegments(string s) {
        int count = 0, index = 0;
        /* skip the blank */
        while (index < s.size() && s[index] == ' ')
                index++;
        while (index < s.size()) {
            count++;
            /* skip the word */
            while (index < s.size() && s[index] != ' ')
                index++;
            /* find the next word */
            while (index < s.size() && s[index] == ' ')
                index++;
        }

        return count;
    }
};