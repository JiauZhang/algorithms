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
* https://leetcode-cn.com/problems/remove-linked-list-elements
* 题目描述：
*     删除链表中等于给定值 val 的所有节点。
* 
* 示例:
*     输入: 1->2->6->3->4->5->6, val = 6
*     输出: 1->2->3->4->5
* 
* 解题思路：
*     典型的双指针法，需要注意的是头结点等于目标值的情况
*     该特例可以通过引入一个额外的节点消除，如代码所示
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return nullptr;

        ListNode res(val+1);
        res.next = head;
        ListNode *left = &res;
        ListNode *right = head;
        while (right) {
            if (right->val == val) {
                left->next = right->next;
                delete right;
                right = left->next;
            } else {
                left = right;
                right = right->next;
            }
        }

        return res.next;
    }
};