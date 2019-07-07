/*
 题目描述：
     输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
     要求不能创建任何新的结点，只能调整树中结点指针的指向。
 
 struct TreeNode {
 	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
 	TreeNode(int x) :
 			val(x), left(NULL), right(NULL) {
 	}
 };
 
 解题思路：
     1. 二叉搜索树转换为有序链表之后，其顺序与 中序 遍历相同，所以访问节点使用
        中序遍历进行
     2. 站在根节点的角度我们可以访问左节点和右节点，但是无法访问自身的根节点，除非
        从上次递归中传递下来根节点。
     3. 首先，进入递归，判断根节点是否 NULL，如果是直接返回，否则中序遍历节点
        当左子节点存在时，进入
     4. 把二叉搜索树分为 左子树 -- 根节点 -- 右子树，左子树返回最终的子链表尾部指针
        所以如果 子链表 != NULL, 则其需要指向根节点，而根节点必须指向 子链表
        然后指向右子树，然后进入右子树
     5. 整个流程就是：
        进入左子树 并 返回左子树链表指针 ---> 与根节点互联, 此时链表指针指向根节点 ---> 进入右子树
        
*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == NULL)
            return NULL;
        
        TreeNode *current = NULL;
        do_convert(pRootOfTree, &current);
        
        while (current != NULL && current->left != NULL)
            current = current->left;
        
        return current;
    }
    
    void do_convert(TreeNode *root, TreeNode **current)
    {
        if (root == NULL)
            return;
        // 处理左子树
        if (root->left)
            do_convert(root->left, current);
        // 更节点指向新链表
        root->left = *current;
        // 如果链表存在，则链表指向根节点，即完成子链表与跟节点的互联
        if (*current)
            (*current)->right = root;
        // 最终根节点成为新的链表头部
        *current = root;
        // 进入右子树
        if (root->right)
            do_convert(root->right, current);
    }
};