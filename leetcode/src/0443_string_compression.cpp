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
* https://leetcode-cn.com/problems/string-compression
* 题目描述：
*     给定一组字符，使用原地算法将其压缩
*     压缩后的长度必须始终小于或等于原数组长度
*     数组的每个元素应该是长度为1 的字符（不是 int 整数类型）
*     在完成原地修改输入数组后，返回数组的新长度
* 进阶：
*     你能否仅使用O(1) 空间解决问题？
* 
*  
* 
* 示例 1：
* 输入：
*     ["a","a","b","b","c","c","c"]
* 
* 输出：
*     返回6，输入数组的前6个字符应该是：["a","2","b","2","c","3"]
* 说明：
*     "aa"被"a2"替代。"bb"被"b2"替代。"ccc"被"c3"替代
* 
* 示例 2：
* 输入：
*     ["a"]
* 输出：
*     返回1，输入数组的前1个字符应该是：["a"]
* 说明：
*     没有任何字符串被替代
* 
* 示例 3：
* 输入：
*     ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
* 输出：
*     返回4，输入数组的前4个字符应该是：["a","b","1","2"]
* 
* 说明：
*     由于字符"a"不重复，所以不会被压缩。"bbbbbbbbbbbb"被“b12”替代
*     注意每个数字在数组中都有它自己的位置。
* 
* 注意：
*     所有字符都有一个ASCII值在[35, 126]区间内。
*     1 <= len(chars) <= 1000。
* 
* 解题思路：
*     一个指针指向待更新字符位置，另一个遍历字符串，统计字符即可
*     统计完一个字符后根据第一个指针更新数据即可
*     注意处理最后一个字符
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() <= 1)
            return chars.size();

        int head = 0, count = 0;
        char cur = chars[0];
        for (auto c: chars) {
            if (cur == c) {
                count++;
            } else { /* a new char */
                if (count > 1) {
                    /* write cur char first */
                    chars[head++] = cur;

                    string sn = to_string(count);
                    for (auto s: sn) {
                        chars[head++] = s;
                    }                              
                } else {
                    chars[head++] = cur;
                }

                cur = c;
                count = 1;                    
            }
        }
        /* deal with the last char */
        if (count > 1) {
            chars[head++] = cur;
            string sn = to_string(count);
            for (auto s: sn) {
                chars[head++] = s;
            }                              
        } else {
            chars[head++] = cur;
        }


        chars.resize(head);

        return head;
    }
};