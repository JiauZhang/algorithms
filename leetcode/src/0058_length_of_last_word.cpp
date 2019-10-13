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
* https://leetcode-cn.com/problems/length-of-last-word
* 题目描述：
*     给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
*     如果不存在最后一个单词，请返回 0 。
* 
* 说明：
*     一个单词是指由字母组成，但不包含任何空格的字符串。
* 
* 示例:
*     输入: "Hello World"
*     输出: 5
* 
* 解题思路：
*     只需要注意末尾会有空格的情况即可
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0)
            return 0;
        /*
        int end = s.size() - 1;
        for (int i=end; i>=0; i--) {
            if (s[i] != ' ')
                break;
            else
                end--;
        }
        */
        int count = 0;
        for (int i=s.size()-1; i>=0; i--) {
            if (s[i] != ' ')
                count++;
            else if (count)
                break;
        }

        return count;
    }
};