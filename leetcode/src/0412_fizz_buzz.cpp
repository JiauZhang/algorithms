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
* https://leetcode-cn.com/problems/fizz-buzz
* 题目描述：
*     写一个程序，输出从 1 到 n 数字的字符串表示
*     1. 如果 n 是3的倍数，输出“Fizz”
*     2. 如果 n 是5的倍数，输出“Buzz”
*     3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”
* 
* 示例：
*     n = 15
*     返回:
*     [
*         "1",
*         "2",
*         "Fizz",
*         "4",
*         "Buzz",
*         "Fizz",
*         "7",
*         "8",
*         "Fizz",
*         "Buzz",
*         "11",
*         "Fizz",
*         "13",
*         "14",
*         "FizzBuzz"
*     ]
* 
* 解题思路：
*     直接遍历即可，没有捷径~
*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        if (n < 1)
            return {};

        int cur = 1;
        vector<string> res;
        res.resize(n);
        while (cur <= n) {
            res[cur-1] = to_string(cur);
            cur++;
        }

        cur = 3;
        while (cur <= n) {
            bool d3 = cur % 3;
            bool d5 = cur % 5;
            if (d3 == 0)
                res[cur-1] = "Fizz";
            else if (d5 == 0)
                res[cur-1] = "Buzz";

            if (!d3 && !d5)
                res[cur-1] += "Buzz";

            cur++;
        }

        return res;
    }
};