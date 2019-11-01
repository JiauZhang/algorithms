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
* https://leetcode-cn.com/problems/delete-node-in-a-linked-list
* 题目描述：
*     请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点
*     你将只被给定要求被删除的节点
*     
* 说明:
*     链表至少包含两个节点
*     链表中所有节点的值都是唯一的
*     给定的节点为非末尾节点并且一定是链表中的一个有效节点
*     不要从你的函数中返回任何结果
* 
* 解题思路：
*     直接 O(1) 操作，删除需要删除的节点的后一个节点即可
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
    void deleteNode(ListNode* node) {
        if (node == nullptr)
            return;

        ListNode *temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        
        delete temp;
    }
};