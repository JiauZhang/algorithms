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
* https://leetcode-cn.com/problems/plus-one
* 题目描述：
* 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
* 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
* 你可以假设除了整数 0 之外，这个整数不会以零开头。
* 
* 示例 1:
*     输入: [1,2,3]
*     输出: [1,2,4]
*     解释: 输入数组表示数字 123。
* 
* 示例 2:
*     输入: [4,3,2,1]
*     输出: [4,3,2,2]
*     解释: 输入数组表示数字 4321。
* 
* 解题思路：
*     1. 由于是加一操作，所以只需要考虑当前位是否需要进位即可
*        即当前位是否为 9，如果不是直接加一结束
*     2. 如果是就把当前位置零，继续下一个加一操作，如此循环
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int head = digits[0];
        for (int i=digits.size()-1; i>=0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                break;
            }
        }

        if (head > digits[0]) {
            vector<int> res = {1};
            res.insert(res.end(), digits.begin(), digits.end());
            return res;
        } else {
           return digits;
        }
    }
};