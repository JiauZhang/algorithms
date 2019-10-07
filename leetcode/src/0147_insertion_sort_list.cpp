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
 * 题目描述：
 *     Sort a linked list using insertion sort. 
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 * 解题思路：
 *    定义一个用作返回用的头变量，以它为其实点，逐个从单链表中取值
 *    这里按从小到大进行排序的，所以每次都是从头部开始比较
 *    同时使用两个指针，一个指向已排序列表的前一个，一个指向用于比较的
 *    当用于比较的值大于待插入值时，那么就把当前值插入到前一个指针指向的
 *    节点后边即可。每次插入节点后都要把插入的节点与原链表断开连接
 *    
 *    第二种方法是直接取第一个节点为初始值，不过这种情况下很有可能需要
 *    来回的改变头指针的值，不方便。
 *    
 *    如下算法时间复杂度为：O(N^2)，因此该算法仅适用于小数据排序
 */
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(-0x7fffffff);
        ListNode *cur = head;
        ListNode *pre = &dummy;
        
        while (cur) {
            ListNode *next = cur->next;
            pre = &dummy;
            
            ListNode *insertNode = pre->next;
            while (pre && insertNode && (cur->val > insertNode->val)) {
                pre = pre->next;
                insertNode = pre->next;
            }
            /*
            if (insertNode == NULL) {
                pre->next = cur;
                cur->next = NULL;
                cur = next;
            } else {
                pre->next = cur;
                cur->next = insertNode;
                cur = next;
            }
            */
            pre->next = cur;
            cur->next = insertNode;
            cur = next;
        }
        
        return dummy.next;
    }
};