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
* https://leetcode-cn.com/problems/reverse-linked-list
* 题目描述：
*     反转一个单链表
* 
* 示例:
*     输入: 1->2->3->4->5->NULL
*     输出: 5->4->3->2->1->NULL
* 
* 进阶:
*     你可以迭代或递归地反转链表，你能否用两种方法解决这道题？
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode *next = head->next;
        ListNode *prev = nullptr;
        while (next) {
            head->next = prev;
            prev = head;
            head = next;
            next = next->next;
        }
        head->next = prev;

        return head;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return head;

        if (head->next) {
            ListNode *next = head->next;
            head->next = nullptr;
            return do_reverse_list(head, next);
        } else {
            return head;
        }
    }

    ListNode *do_reverse_list(ListNode *head, ListNode *next) {
        ListNode *root = next;
        if (next->next) {
            root = do_reverse_list(next, next->next);            
        }         
        next->next = head;

        return root;
    }
};