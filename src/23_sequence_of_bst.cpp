/*
 * 题目描述：
 *     输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
 *     如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
 * 
 * 解题思路：
 *     1. 边界条件检查，当为空时返回false，当元素个数 <= 2 时必定为true
 *     2. 进入递归函数体，边界检查及递归终止条件：当递归到原数个数 <= 2 时当前递归返回true
 *     3. 如果元素个数 >= 3，则进行左右子树检查，然后递归左右子树
 *        3.1 根据后序遍历的特点，vector的最后一个元素为根节点，所以当第一个大于根节点出现时，
 *            就找到了左右子树的分界线，然后再检查右子树中的数是否都满足大于根节点的要求
 *        3.2 递归进入左右子树
 * 
 */

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() <= 0)
            return false;
        if (sequence.size() <= 2)
            return true;
        
        return do_verify(sequence, 0, sequence.size()-1);
    }
    
    bool do_verify(vector<int> &vec, int start, int end) {
        if (start > end)
            return false;
        if (start + 1 >= end)
            return true;
        
        int root_val = vec[end];
        int right = start;
        for (; right<end; right++) {
            if (vec[right] > root_val)
                break;
        }
        
        for (int i=right; i<end; i++) {
            if (vec[i] < root_val)
                return false;
        }
        
        // 默认赋值 true 是因为可能仅存在左子树或右子树或者某个子树仅一个节点
        bool l = true;
        bool r = true;
        // 当仅一个节点时不会进入，而是直接利用初始赋值的 true
        if (right>start)
            l = do_verify(vec, start, right-1);
        if (right<end)
            r = do_verify(vec, right, end-1);
        
        return (l && r);
    }
};