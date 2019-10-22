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
* https://leetcode-cn.com/problems/min-stack
* 题目描述：
* 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
*     push(x) -- 将元素 x 推入栈中。
*     pop() -- 删除栈顶的元素。
*     top() -- 获取栈顶元素。
*     getMin() -- 检索栈中的最小元素。
* 
* 示例:
*     MinStack minStack = new MinStack();
*     minStack.push(-2);
*     minStack.push(0);
*     minStack.push(-3);
*     minStack.getMin();   --> 返回 -3.
*     minStack.pop();
*     minStack.top();      --> 返回 0.
*     minStack.getMin();   --> 返回 -2.
* 
* 解题思路：
*     使用两个辅助栈，一个用于出栈入栈，一个用于记录当前最小值
*/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        while (st.size())
            st.pop();
        while (min.size())
            min.pop();
    }
    
    void push(int x) {
        st.push(x);
        if (min.empty() || min.top() > x)
            min.push(x);
        else
            min.push(min.top());
    }
    
    void pop() {
        st.pop();
        min.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }

private:
    stack<int> st;
    stack<int> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */