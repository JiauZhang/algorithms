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
* https://leetcode-cn.com/problems/implement-strstr
* 题目描述：
*     给定一个 haystack 字符串和一个 needle 字符串，
*     在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。
*     如果不存在，则返回  -1。
* 
* 示例 1:
*     输入: haystack = "hello", needle = "ll"
*     输出: 2
* 
* 示例 2:
*     输入: haystack = "aaaaa", needle = "bba"
*     输出: -1
* 
* 说明:
*     当 needle 是空字符串时，我们应当返回 1.
*
* 解题思路：
*     1. 最简单的方法就是暴力匹配了，这里不做叙述了
*     2. 经典的解法就是 KMP 算法进行匹配，KMP 算法的核心部分
*        是计算最大公共前后缀，产生 next 数组
*        换一种思路理解这个数组，该数组其实是指示模板字符串中
*        拥有的最大相同子字符串模板，这样就可以直接跳过那些不存在
*        相同模板的子字符串，从而加速模板迁移的速度，而不需要像
*        暴力匹配法那样，每一次失败都需要重头开始匹配，这就是
*        KMP 算法速度比较快的原因，其算法复杂度为 O(M+N)
*     3. 还一些与 KMP 算法类似的，比如 BM 算法、Sunday 算法等
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (!needle.size())
		    return 0;
        
        if (!haystack.size())
		    return -1;
        
        vector<int> next;
        get_next(needle, next);

        int i = 0, j = 0;
        while (i < (int)haystack.size() && j < (int)needle.size()) {
            if ((j == -1) || (haystack[i] == needle[j])) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }

        if (j == needle.size()) {
            return i - j;
        } else {
            return -1;
        }
    }
    
    void get_next(string &tmpl, vector<int> &next) {
        next.resize(tmpl.size());
        next[0] = -1;

        int k = -1;
        int j = 0;
        while (j < next.size() - 1)
        {
            if (k == -1 || tmpl[j] == tmpl[k]) 
            {
                k++;
                j++;
                if (tmpl[j] != tmpl[k])
                    next[j] = k;
                else
                    next[j] = next[k];
            }
            else 
            {
                k = next[k];
            }
        }
    }
};