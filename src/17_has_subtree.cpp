/*
 * 题目描述：
 *     输入两棵二叉树A，B，判断B是不是A的子结构。
 *     
 * struct TreeNode {
 * 	int val;
 * 	struct TreeNode *left;
 * 	struct TreeNode *right;
 * 	TreeNode(int x) :
 * 			val(x), left(NULL), right(NULL) {
 * 	}
 * };
 * 
 * 解题思路：
 *     核心部分为：
 *     1. 如何判断树是否相等
 *         只有当子树中每个节点都与给定树中节点相等时才相等
 *         1.1 当子树为NULL时则返回true，说明这个分支完全匹配
 *         1.2 当子树非空，给定树为NULL时，则返回false
 *         1.3 当根节点相等时，判断左右子树是否相等，即递归
 *     2. 如何找到子树根节点在给定树中对应的节点
 *         根据平衡二叉树的规则找val相等的节点即可，这里需要注意的是
 *         二叉树中  可能存在val相等的节点
 *         所以需要遍历所有的val相等的节点后才能确定是否匹配失败
 * 
 */
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot1 == NULL || pRoot2 == NULL)
            return false;
        
        return do_has_subtree(pRoot1, pRoot2);
    }
    
    bool do_has_subtree(TreeNode *pRoot1, TreeNode *pRoot2) {
        int val = pRoot2->val;
        while (pRoot1) {
            if (pRoot1->val > val)
                pRoot1 = pRoot1->right;
            else if (pRoot1->val < val)
                pRoot1 = pRoot1->left;
            else {
                bool success = compare(pRoot1, pRoot2);
                if (!success)
                    success = do_has_subtree(pRoot1->left, pRoot2);
                if (!success)
                    success = do_has_subtree(pRoot1->right, pRoot2);
                return success;
            }
        }
        
        return false;
    }
    
    bool compare(TreeNode *pRoot1, TreeNode *pRoot2) {
        if (pRoot2 == NULL) {
            return true;
        } else if (pRoot1 == NULL) {
            return false;
        } else {
            if (pRoot1->val == pRoot2->val) {
                bool left = compare(pRoot1->left, pRoot2->left);
                bool right = compare(pRoot1->right, pRoot2->right);
                return left && right;
            } else {
                return false;
            }
        }
    }
};