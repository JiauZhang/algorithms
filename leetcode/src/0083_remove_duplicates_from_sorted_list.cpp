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
* https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list
* 题目描述：
*     给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
* 
* 示例:
*     输入: 1->1->2->3->3
*     输出: 1->2->3
* 
* 解题思路：
*     直接从头遍历，删除重复的即可
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *res = head;
        while (res) {
            ListNode *next = res->next;
            if (next && next->val == res->val) {
                res->next = next->next;
                delete next;
            } else {
                res = next;
            }
        }

        return head;
    }
};