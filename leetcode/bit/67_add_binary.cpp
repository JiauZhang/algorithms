/*
* Copyright(c) 2021 Jiau Zhang
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
* https://leetcode-cn.com/problems/add-binary/
* 给你两个二进制字符串，返回它们的和（用二进制表示）
* 输入为 非空 字符串且只包含数字 1 和 0
* 
* 示例 1:
*     输入: a = "11", b = "1"
*     输出: "100"
* 
* 示例 2:
*     输入: a = "1010", b = "1011"
*     输出: "10101"
* 
* 提示：
*     每个字符串仅由字符 '0' 或 '1' 组成
*     1 <= a.length, b.length <= 10^4
*     字符串如果不是 "0" ，就都不含前导零
* 
* 解题思路：
*     1. 直接模拟二进制加法运算即可
*     2. 另一种方法是先把字符串转换成比如 long 型数字，然后直接用 long 型运算
*        之后再转回字符串，但是字符数字的互相转换也需要计算量，所以这种方法是否
*        更高效还不好说
*/

class Solution {
public:
    string addBinary(string a, string b) {
        if (a == "0")
            return b;
        if (b == "0")
            return a;
        
        int la = a.size();
        int lb = b.size();
        int lmin = min(la, lb);
        char carry = 0;
        string res;
        // 相加之后字符串可能最长的长度
        res.reserve(max(la, lb) + 1);
        // 求和
        for (int i=0; i<lmin; i++) {
            char sum = a[--la] - '0' + b[--lb] + carry;
            if (sum >= '2') {
                res.push_back(sum - 2);
                carry = 1;
            } else {
                res.push_back(sum);
                carry = 0;
            }
        }
        // 计算较长的字符串剩余的部分
        if (la >= 0) {
            while (la > 0) {
                char sum = a[--la] + carry;
                if (sum >= '2') {
                    res.push_back(sum - 2);
                    carry = 1;
                } else {
                    res.push_back(sum);
                    carry = 0;
                }
            }
        }
        
        if (lb >= 0) {
            while (lb > 0) {
                char sum = b[--lb] + carry;
                if (sum >= '2') {
                    res.push_back(sum - 2);
                    carry = 1;
                } else {
                    res.push_back(sum);
                    carry = 0;
                }
            }
        }
        // 处理最后的进位
        if (carry) {
            res.push_back('1');
        }
        // 特殊情况
        if (res.size() == 0)
            res.push_back('0');
        reverse(res.begin(), res.end());

        return res;
    }
};