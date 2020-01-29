/*
* Copyright(c) 2020 Jiau Zhang
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
* https://leetcode-cn.com/problems/keyboard-row
* 题目描述：
*     给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词
*     键盘如下图所示
* 
* 示例：
*     输入: ["Hello", "Alaska", "Dad", "Peace"]
*     输出: ["Alaska", "Dad"] 
* 
* 注意：
*     你可以重复使用键盘上同一字符。
*     你可以假设输入的字符串将只包含字母
*     
* 解题思路：
*     直接进行字母键值映射即可
*/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        char chars[26] = {0};
        string str = "qwertyuiop;asdfghjkl;zxcvbnm";
        int label = 1;
        for (auto c: str) {
            if (c == ';') {
                label++;
                continue;
            }
            
            char offset = c - 'A';
            if (c >= 'a')
                offset = c - 'a';
            
            chars[offset] = label;
        }

        vector<string> res;
        for (auto w: words) {
            bool filter = true;
            char offset = w[0] - 'A';
            if (w[0] >= 'a')
                offset = w[0] - 'a';
            char label = 1 << chars[offset];
            for (auto c: w) {
                char offset = c - 'A';
                if (c >= 'a')
                    offset = c - 'a';
                char temp = 1 << chars[offset];
                if (label != temp) {
                    filter = false;
                    break;
                }
            }

            if (filter)
                res.push_back(w);
        }

        return res;
    }
};