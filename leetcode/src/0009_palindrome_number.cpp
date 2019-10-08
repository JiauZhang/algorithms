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
https://leetcode-cn.com/problems/palindrome-number
题目描述：
    判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）
    读都是一样的整数。

示例 1:
    输入: 121
    输出: true

示例 2:
    输入: -121
    输出: false
    解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

示例 3:
    输入: 10
    输出: false
    解释: 从右向左读, 为 01 。因此它不是一个回文数。

进阶:
    你能不将整数转为字符串来解决这个问题吗？

解题思路：
    1. 从示例可以看出，负数一定不是对称的，所以排除了一半的数字
    2. 0 是对称的，所以现在只剩下正整数了
    3. 第一种思路是按照题目 0007_reverse_integer 的方法直接反转数字
       然后判断两个数是否相等即可
    4. 第二种思路是将整数转化为字符串，然后收尾两个指针同时进行比较即可

*/

/* solution #1 */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        if (x == 0)
            return true;

        int reverse = reverse_int(x);

        return (reverse == x);
    }

    int reverse_int(int x) {
        int res = 0;
        while (x) {
            int remainder = x;
            x /= 10;
            remainder -= x * 10;
            /* TODO: check overflow */
            if (res > INT_MAX / 10) {
                res = 0;
                break;
            }
    
            res *= 10;
            res += remainder;
        }

        return res;
    }
};

/* solution #2 */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        if (x == 0)
            return true;

        string int_string;
        int_to_string(x, int_string);

        int head = 0, tail = int_string.size() - 1;
        bool res = true;
        while (head < tail) {
            if (int_string[head] != int_string[tail]) {
                res = false;
                break;
            }
            
            head++; tail--;
        }
        
        return res;
    }
    
    void int_to_string(int x, string &str) {
        while (x) {
            int remainder = x;
            x /= 10;
            remainder -= x * 10;
            str += ('0' + remainder);
        }
    }
};