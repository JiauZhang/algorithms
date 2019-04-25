/*
 * 题目描述:
 *     用两个栈来实现一个队列，完成队列的Push和Pop操作。队列中的元素为int类型。
 * 
 * 解题思路：
 *     队列是先进先出，而栈是先进后出，但是两个栈串在一起操作就是先进先出了
 *     so....
 * 
 */
class Solution
{
public:
    void push(int node) {
        stack2.push(node);
    }

    int pop() {
        if (stack1.size() != 0) {
            int res = stack1.top();
            stack1.pop();
            return res;
        } else {
            while (stack2.size()) {
                int top = stack2.top();
                stack1.push(top);
                stack2.pop();
            }
            
            if (stack1.size()) {
                int res = stack1.top();
                stack1.pop();
                return res;
            }
        }
        
        return -1;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};