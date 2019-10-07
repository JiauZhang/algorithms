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

/**
 *题目描述：
 *  Given a binary tree, return the postorder traversal of its nodes' values.
 *  For example:
 *  Given binary tree{1,#,2,3},
 *     1
 *      \
 *       2
 *      /
 *     3
 *  return[3,2,1].
 *  Note: Recursive solution is trivial, could you do it iteratively? 

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
 解题思路：
    递归的思路：另外实现一个后序遍历的递归函数，其作用就是递归访问每个节点
    如果左节点存在就先递归进入左子树，然后递归右子树，最后添加当前节点到vector中
    
    迭代的思路：由于不能用递归，所以需要自己实现压栈，而当前节点只能看到
    根和左右子节点，总共两种压栈方式：根--左--右，或者 根--右--左
    而后续遍历的正确操作为：左--右--根，没有一个相同的，但是它的反操作
    根--右--左 确实存在的，根据栈的属性，先进后出，压栈顺序变为：根--左--右
    先把根节点压入栈，再循环中取出栈顶节点的值，然后压入左--右节点
    这样每次取的都是右节点，剩下的都是左节点的，即实现了根--先右--后左
    最后将整个vector反转即可
 */
 
/* 递归 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> array_list;
        if (root == NULL)
            return array_list;
        postOrder(root, array_list);
        
        return array_list; 
    }
    
    void postOrder(TreeNode* root, vector<int> &vec) {
        if (root == NULL)
            return;
        postOrder(root->left, vec);
        postOrder(root->right, vec);
        vec.push_back(root->val);
    }
};
/* 迭代的方法，非递归 */
class Solution {
public:
      vector<int> postorderTraversal(TreeNode *root) {
          vector<int> res;
          if(!root)
              return res;
          stack<TreeNode *> st;
          st.push(root);
          while (st.size())
          {
              TreeNode *temp = st.top();
              res.push_back(temp->val);
              st.pop();
              if (temp->left)
                  st.push(temp->left);
              if (temp->right)
                  st.push(temp->right);
          }
          
          reverse(res.begin(),res.end());
          return res;
     }
};
