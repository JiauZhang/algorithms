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
* https://leetcode-cn.com/problems/valid-parentheses
* 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
* 有效字符串需满足：
*     左括号必须用相同类型的右括号闭合。
*     左括号必须以正确的顺序闭合。
* 
* 注意空字符串可被认为是有效字符串。
* 
* 示例 1:
*     输入: "()"
*     输出: true
* 
* 示例 2:
*     输入: "()[]{}"
*     输出: true
* 
* 示例 3:
*     输入: "(]"
*     输出: false
* 
* 示例 4:
*     输入: "([)]"
*     输出: false
* 
* 示例 5:
*     输入: "{[]}"
*     输出: true
* 
* 解题思路：
*     1. 有效括号肯定都是成对出现的，如果一个字符串是有效的
*        那么最外侧的括号括起来的子字符串一定也是有效的
*        即原问题可分解为子问题
*     2. 如果反过来想，那么最内层的一定也是有效的，而且是紧挨着的
*        例如 {[()]}, 如果把这个字符串逐个压入栈中，那么我们先
*        接收到的是开括号，后接收到的是闭括号，这就是为什么程序中
*        open_close 的映射关系是反着写的
*     3. 当接收到最内层时，紧接着就是最内层的闭括号，依次到最外层
*        当此时逐个消去时候，情况如下
*        {[( --> {[() --> {[ --> {[] --> { --> {} --> empty
*/

class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0)
            return true;
        
        stack<char> stk;
        unordered_map<char, char> open_close = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        
        for (int i=0; i<s.size(); i++) {
            if (stk.size() == 0) {
                stk.push(s[i]);
            } else if (stk.top() == open_close[s[i]]) {
                stk.pop();
            } else {
                stk.push(s[i]);
            }
        }
        
        return (stk.size() == 0);
    }
};