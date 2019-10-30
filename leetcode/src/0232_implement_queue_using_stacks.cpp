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
* https://leetcode-cn.com/problems/implement-queue-using-stacks
* 题目描述：
*     使用栈实现队列的下列操作：
*     push(x) -- 将一个元素放入队列的尾部。
*     pop() -- 从队列首部移除元素。
*     peek() -- 返回队列首部的元素。
*     empty() -- 返回队列是否为空。
* 
* 示例:
*     MyQueue queue = new MyQueue();
*     queue.push(1);
*     queue.push(2);  
*     queue.peek();  // 返回 1
*     queue.pop();   // 返回 1
*     queue.empty(); // 返回 false
*/

class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;

    /** Initialize your data structure here. */
    MyQueue() {
        while (st1.size())
            st1.pop();
        while (st2.size())
            st2.pop();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {        
        fresh(st1, st2);
        int res = st2.top();
        st2.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        fresh(st1, st2);
        return st2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st2.empty() && st1.empty();
    }

    void fresh(stack<int> &st1, stack<int> &st2) {
        if (st2.empty()) {
            while (st1.size()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */