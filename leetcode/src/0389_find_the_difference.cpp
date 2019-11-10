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
* https://leetcode-cn.com/problems/find-the-difference
* 题目描述：
*     给定两个字符串 s 和 t，它们只包含小写字母
*     字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母
*     请找出在 t 中被添加的字母
*  
* 
* 示例:
* 输入：
*     s = "abcd"
*     t = "abcde"
* 输出：
*     e
* 
* 解释：
*     'e' 是那个被添加的字母。
* 
* 解题思路：
*     1. 可以使用映射统计每个字符的数量，然后相减，剩下的一个就是
*        要找的字符
*     2. 由于两个字符串只有一个不同，所以可以通过异或找出唯一的
*        那一个
*/

class Solution {
public:
    char findTheDifference(string s, string t) {        
        char res = 0;
        for (int i=0; i<s.size(); i++) {
            res ^= (s[i]^t[i]);
        }
        res ^= t[t.size()-1];

        return res;
    }
};