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
* https://leetcode-cn.com/problems/add-strings
* 题目描述：
*     给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和
* 
* 注意：
*     num1 和num2 的长度都小于 5100
*     num1 和num2 都只包含数字 0-9
*     num1 和num2 都不包含任何前导零
*     你不能使用任何內建 BigInteger 库
*     也不能直接将输入的字符串转换为整数形式
* 
* 解题思路：
*     将字符串相加分解为单个字符相加即可，主要是人工模拟相加
*     和进位即可，这里直接对较长的字符串进行更新
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        /* '0' = 0011 0000 */
        if (num1.size() > num2.size()) {
            do_add(num1, num2);
            return num1;
        } else {
            do_add(num2, num1);
            return num2;
        }
    }

    void do_add(string &s1, string &s2) {
        int i=s1.size()-1, j=s2.size()-1;
        char carry = 0;
        while (j>=0) {
            s1[i] = add_char(s1[i], s2[j], carry);
            i--;
            j--;
        }

        while (carry && i>=0) {
            s1[i] = add_char(s1[i], '0', carry);
            i--;
        }

        if (carry)
            s1 = '1' + s1;
    }

    char add_char(char &c1, char c2, char &carry) {
        char add1 = c1 - '0';
        char add2 = c2 - '0';
        char sum = add1 + add2 + carry;
        if (sum > 9) {
            carry = 1;
            sum -= 10;
        } else {
            carry = 0;
        }

        return (sum + '0');
    }
};