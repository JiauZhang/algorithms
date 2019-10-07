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
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * Valid operators are+,-,*,/. Each operand may be an integer or another expression.
 * Some examples:
 *   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 *
 * 解题思路：
 *      RPN每个运算符对应前边的两个操作数，因此采用栈的方式解决
 *      1. 如果取出的数不是运算符，那么就进行入栈操作
 *      2. 如果取出的数是运算符，那么就对栈顶的两个数进行操作
 *         所以这里涉及到 判断 栈中否至少包含两个操作数
 */
 
class Solution {
public:
    int evalRPN(vector<string> &tokens) {       
        stack<int> store;
        for (auto s: tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                 
                if (store.size()<2)
                    return false;
                 
                int a = store.top(); store.pop();
                int b = store.top(); store.pop();
                int c;
                //需要使用 双引号 而不是 单引号
                if (s == "+")
                    c = a+b;
                else if (s == "-")
                    c = b-a;
                else if (s == "*")
                    c = a*b;
                else if (s == "/")
                    c = b/a;
                store.push(c);
            } else {
                store.push(atoi(s.c_str()));
            }
        }
         
        return store.top();
    }
};