/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 * 编写一个程序，找到两个单链表相交的起始节点。
 *
 * 注意：
 *    如果两个链表没有交点，返回 null.
 *    在返回结果后，两个链表仍须保持原有的结构。
 *    可假定整个链表结构中没有循环。
 *    程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
 *
 * 解题思路：
 *      题目中要求时间复杂度为 O(n)，且空间复杂度为 O(1)
 *      所以使用栈的方法就不适用了，只能先遍历两个链表
 *      然后较长的链表先走几步，然后两个指针同时走
 *      直到找到相同的一个为止
 */
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        
        if (lenA > lenB)
            headA = offsetHead(headA, lenA-lenB);
        else if (lenA < lenB)
            headB = offsetHead(headB, lenB-lenA);
        
        ListNode *res = NULL;
        while (headA && headB) {
            if (headA == headB) {
                res = headA;
                break;
            } else {
                headA = headA->next;
                headB = headB->next;
            }
        }
        
        return res;
    }
    
    int getLength(ListNode *head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        
        return len;
    }
    
    ListNode *offsetHead(ListNode *head, int offset) {
        while (offset) {
            head = head->next;
            offset--;
        }
        
        return head;
    }
};