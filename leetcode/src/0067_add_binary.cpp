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
* https://leetcode-cn.com/problems/add-binary
* 题目描述：
*     给定两个二进制字符串，返回他们的和(用二进制表示)。
*     输入为非空字符串且只包含数字 1 和 0。
* 
* 示例 1:
*     输入: a = "11", b = "1"
*     输出: "100"
* 
* 示例 2:
*     输入: a = "1010", b = "1011"
*     输出: "10101"
* 
* 解题思路：
*     1. 二进制运算相当简单了，不同之处在于这里是操作的字符串
*        所以需要程序实现字符相加的二进制运算
*     2. 两个二进制字符相加，再加上进位位，总共有种可能的结果
*        0, 1, 2, 3，所以最直白的做法就是写四个 if 语句即可
*     3. 但是为了进一步优化，我们可以定义一个数组，如程序中所示
*        最后直接根据数组获取进位位的值和当前和的结果即可
*        本来需要四条 if 语句的操作直接一步就可以解决了！
*/

class Solution {
public:
    string addBinary(string a, string b) {
        // bool first = false;
        // string *strs[2] = {&a, &b};
        // string *strs[2] = {a.c_str(), b.c_str()};

        if (a.size() < b.size()) {
            do_add(b, a);
            return b;
        }            
        else {
            do_add(a, b);
            return a;
        }            
    }

    void do_add(string &a, string &b) {
        char cs[4] = {0, 0, 1, 1};
        char ss[4] = {'0', '1', '0', '1'};
        char carry = 0;
        char base = '0';
        int i = a.size() - 1;
        int j = b.size() - 1;
        while (j >= 0 || (carry && i >= 0)) {
            char sum = 0;
            if (j >= 0) {
                sum += b[j] - base;
            }

            sum += a[i] - base;
            sum += carry;
            a[i] = ss[sum];
            carry = cs[sum];

            i--;
            j--;
        }

        if (carry)
            a = '1' + a;
    }
};