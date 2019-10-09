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
* https://leetcode-cn.com/problems/longest-common-prefix
* 编写一个函数来查找字符串数组中的最长公共前缀。
* 如果不存在公共前缀，返回空字符串 ""。
* 
* 示例 1:
*     输入: ["flower","flow","flight"]
*     输出: "fl"
* 
* 示例 2:
*     输入: ["dog","racecar","car"]
*     输出: ""
*     解释: 输入不存在公共前缀。
* 
* 说明:
*     所有输入只包含小写字母 a-z 。
* 
* 解题思路：
*     1. 找出字符串组中最短的那一个，因为最长公共肯定 <= 这个数值
*     2. 逐个位比较是否相同即可
*     3. 对特殊情况进行处理，即空字符组、只有一个字符串
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        
        if (strs.size() == 0)
            return res;
        
        if (strs.size() == 1)
            return strs[0];
        /* step #1 */
        int min = INT_MAX;
        for (int i=0; i<strs.size(); i++) {
            if (strs[i].size() < min)
                min = strs[i].size();
        }
        /* step #2 */
        for (int i=0; i<min; i++) {
            bool success = true;
            for (int j=1; j<strs.size(); j++) {
                if (strs[0][i] != strs[j][i]) {
                    success = false;
                    break;
                }
            }
            
            if (success)
                res += strs[0][i];
            else
                break;
        }
        
        return res;
    }
};