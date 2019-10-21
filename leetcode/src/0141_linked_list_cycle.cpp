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
* https://leetcode-cn.com/problems/linked-list-cycle
* 题目描述：
* 给定一个链表，判断链表中是否有环。
* 
* 解题思路：
*     两种方法：1. 快慢指针；2. 哈希表
*     代码给出的是使用快慢指针判断的
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
    bool hasCycle(ListNode *head) {
        if (head == nullptr)
            return false;

        ListNode *temp = head->next;
        while (head && temp) {
            if (head == temp)
                return true;
            else {
                head = head->next;
                temp = temp->next;
                if (temp)
                    temp = temp->next;
            }
        }

        return false;
    }
};