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
 * 题目描述
 *     输入一个链表，反转链表后，输出新链表的表头。
 *     
 * struct ListNode {
 * 	int val;
 * 	struct ListNode *next;
 * 	ListNode(int x) :
 * 			val(x), next(NULL) {
 * 	}
 * };
 * 
 * 解题思路：
 *     由于是单链表，在反转过程中链表肯定会断裂，所以需要临时指针来记录
 *     原来的连接关系，步骤如下：
 *     1. 确定是否为空链表，空链表则返回，非空则先把第一个和链表断开连接
 *     2. 一个指针指向第一个节点，另一个指向剩余的链表的头部
 *     3. 循环遍历所有节点，最后返回新的头结点指针
 * 
 */
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL)
            return NULL;
        
        ListNode *pTemp = pHead;
        pHead = pHead->next;
        pTemp->next = NULL;
        while (pHead) {
            ListNode *p = pHead->next;
            pHead->next = pTemp;
            pTemp = pHead;
            pHead = p;
        }
        
        return pTemp;
    }
};