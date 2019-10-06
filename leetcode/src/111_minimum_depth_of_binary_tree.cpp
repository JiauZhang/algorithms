/*
 * 题目：
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path 
 * from the root node down to the nearest leaf node.
 * 
 * 解题思路：
 *    使用递归的方法，求最短路径，也就是左右子树的最短路径
 *    主要考虑几种特殊情况：
 *    1. 递归终止条件，即无子节点时终止，即空指针
 *    2. 没有左子树或右子树时如何处理
 *    3. 左右子树都存在时如何处理
 *    4. 左右子树都不存在时如何处理
 *    总之，只要进入递归的不是空指针，当节点都算一个深度值
 *    这也就是为什么返回值后都 +1 的原因
 */
class Solution {
public:
    int run(TreeNode *root) {
        if (!root)
            return 0;
        
        int left = run(root->left);
        int right = run(root->right);
        
        if (!left && right)
            return right+1;
        if (!right && left)
            return left+1;
        
        if ((!left) && (!right))
            return 1;
        
        return (left > right) ? (right+1) : (left+1);
    }
};