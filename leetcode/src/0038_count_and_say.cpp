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
* https://leetcode-cn.com/problems/count-and-say
* 题目描述：
*     报数序列是一个整数序列，按照其中的整数的顺序进行报数，
*     得到下一个数。其前五项如下：
*         1.     1
*         2.     11
*         3.     21
*         4.     1211
*         5.     111221
*     1  被读作  "one 1"  ("一个一") , 即 11。
*     11 被读作 "two 1s" ("两个一"）, 即 21。
*     21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
*     给定一个正整数 n(1≤n≤30)，输出报数序列的第 n 项。
* 注意：
*     整数顺序将表示为一个字符串。
* 
* 示例 1:
*     输入: 1
*     输出: "1"
* 
* 示例 2:
*     输入: 4
*     输出: "1211"
* 
* 解题思路：
*     1. 第一步是需要理解这个数组是怎么构造出来的，通过给出的解释
*        可以明白，每个部分的组成都是[某个字符连续出现的个数]+[该字符]
*     2. 基于字符串的构造模式就可以循环的构造指定 n 下的该字符串了
*/

class Solution {
public:
    string countAndSay(int n) {        
        unsigned int flag = 1;
        string str[2];
        str[!flag] = "1";
        str[flag].clear();

        for (int i=1; i<n; i++) {
            int count = 0;
            unsigned char target = str[!flag][0];

            for (int j=0; j<str[!flag].size(); j++) {
                if (str[!flag][j] == target) {
                    count++;
                } else { /* the last loop will be drop!!! */
                    str[flag] += to_string(count);
                    str[flag] += target;
                    target = str[!flag][j];
                    count = 1;
                }
            }
            /* save the last result */
            str[flag] += to_string(count);
            str[flag] += target;

            flag = !flag;
            str[flag].clear();
        }

        return str[!flag];
    }
};