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
* https://leetcode-cn.com/problems/palindrome-linked-list
* 题目描述：
*     请判断一个链表是否为回文链表
* 
* 示例 1:
*     输入: 1->2
*     输出: false
* 
* 示例 2:
*     输入: 1->2->2->1
*     输出: true
* 
* 进阶：
*     你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
* 
* 解题思路：
*     先反转后半部分链表，然后比较即可
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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        int res = 0;
        int lenght = 0;
        ListNode *root = head;
        while (head) {
            head = head->next;
            lenght++;
        }
        /* 0, 1, 2, 3, 4, 5, middle = 3 */
        /* 0, 1, 2, 3, 4, 5, 6, middle = 3 */
        int middle = lenght / 2;
        if (lenght & 0x01)
            middle += 1;

        ListNode *temp = root;
        for (int i=0; i<middle; i++)
            temp = temp->next;
        
        temp = reverse_list(temp);
        if (lenght & 0x01)
            middle -= 1;
        for (int i=0; i<middle; i++)
            if (temp->val != root->val) return false;
            else { temp = temp->next; root = root->next; }
        
        return true;
    }

    ListNode *reverse_list(ListNode *root) {
        ListNode *prev = nullptr;
        ListNode *next = root->next;
        while (next) {
            root->next = prev;
            prev = root;
            root = next;
            next = next->next;
        }
        /* must be done! */
        root->next = prev;

        return root;
    }
};