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
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
* 
* https://leetcode-cn.com/problems/merge-two-sorted-lists
* 将两个有序链表合并为一个新的有序链表并返回。
* 新链表是通过拼接给定的两个链表的所有节点组成的。 
*
*示例：
*    输入：1->2->4, 1->3->4
*    输出：1->1->2->3->4->4
*
*解题思路：
*    1. 因为已经是排好序的了，所以直接根据大小选择先取哪个节点即可
*    2. 对特殊情况进行考虑
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {        
        if (!l1)
            return l2;
        
        if (!l2)
            return l1;
        
        ListNode root(-1), *temp;
        temp = &root;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            } else {
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            }
        }
        
        if (l1)
            temp->next = l1;
        if (l2)
            temp->next = l2;
        
        return root.next;
    }
};