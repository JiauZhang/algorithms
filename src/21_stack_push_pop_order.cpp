/*
 * 题目描述：
 *     输入两个整数序列，第一个序列表示栈的压入顺序，
 *     请判断第二个序列是否可能为该栈的弹出顺序。
 *     假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
 *     序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
 *     但4,3,5,1,2就不可能是该压栈序列的弹出序列。(注意：这两个序列的长度是相等的)
 * 
 * 解题思路：
 *     1. 什么时候需要压栈：
 *        1.1 当栈为空时 或者 当前栈顶值不等于待出栈数据时
 *        1.2 压栈终止条件为栈顶值等于待出栈数值，也可能没有，所以while
 *            循环内需要判断，当所有数据都压栈了还没有时就break
 *        1.3 该步骤结束时必然是三种情况之一：
 *            栈顶值等于待出栈数值
 *            所有数据都已入栈，但还是没有相等
 *            数据入栈完毕且栈顶值等于待出栈数值
 *     2. 根据步骤1.3可知，上一步执行完毕之后，如果栈顶值不等于待出栈值，那么一定是没找到
 *        所以如果当前栈顶不等于待出栈数值，则返回false
 *        等于时则出栈，待出栈索引值后移
 * 
 */

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.size() && popV.size()) {
            stack<int> st;
            unsigned long push_index = 0;
            unsigned long pop_index = 0;
            
            while (pop_index < popV.size()) {
                while (st.empty() || st.top() != popV[pop_index]) {
                    if (push_index < pushV.size()) {
                        st.push(pushV[push_index]);
                        push_index++;
                    } else {
                        break;
                    }
                }
                
                if (st.top() == popV[pop_index]) {
                    pop_index++;
                    st.pop();
                } else {
                    return false;
                }
            }
            
            return true;
        } else {
            return false;
        }
    }
};