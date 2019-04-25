/**
 * 题目描述：
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * For example:
 * Given binary tree{1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 * return[1,2,3].
 * Note: Recursive solution is trivial, could you do it iteratively? 
 *
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
 解题思路：
    递归方法：实现一个递归的前序访问节点的函数即可，根据前序遍历规则添加节点值
    迭代方法：前序遍历为：根--左--右，而迭代时我们可以的压栈顺序是：
    根--左--右 或者 根--右--左，根据栈的特性，和我们想访问完 根 之后访问 左
    所以需要先把右压进去，然后压左，即压栈顺序为：根--右--左，然后从栈顶取指针
    迭代压栈即可。
 */
 
/* 递归 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> array_list;
        if (root == NULL)
            return array_list;
        
        preOrder(root, array_list);
        return array_list;
    }
    
    void preOrder(TreeNode *root, vector<int> &array_list) {
        if (root == NULL)
            return;
        
        array_list.push_back(root->val);
        preOrder(root->left, array_list);
        preOrder(root->right, array_list);
    }
};
/* 迭代的方法，非递归 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> array_list;
        if (root == NULL)
            return array_list;
        
        stack<TreeNode *> nodes;
        nodes.push(root);
        while (nodes.size()) {
            TreeNode *temp = nodes.top();
            nodes.pop();
            array_list.push_back(temp->val);
            if (temp->right)
                nodes.push(temp->right);
            if (temp->left)
                nodes.push(temp->left);
        }
        
        return array_list;
    }
};
