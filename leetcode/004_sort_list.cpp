/**
 *Sort a linked list in O(n log n) time using constant space complexity. 
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 *考点：
 *    1. 快慢指针；2. 归并排序。
 *    复杂度分析:
 *             T(n)            拆分 n/2, 归并 n/2 ，一共是n/2 + n/2 = n
 *            /    \           以下依此类推：
 *          T(n/2) T(n/2)      一共是 n/2*2 = n
 *         /    \  /     \
 *        T(n/4) ...........   一共是 n/4*4 = n
 *
 *       一共有logn层，故复杂度是 O(nlogn)
 * 
 *思路：
 *    因为题目要求复杂度为O(nlogn),故可以考虑归并排序的思想。
 *    归并排序的一般步骤为：
 *    1）将待排序数组（链表）取中点并一分为二；
 *    2）递归地对左半部分进行归并排序；
 *    3）递归地对右半部分进行归并排序；
 *    4）将两个半部分进行合并（merge）,得到结果。
 *    
 *    所以对应此题目，可以划分为三个小问题：
 *    1）找到链表中点 （快慢指针思路，快指针一次走两步，慢指针一次走一步，
 *       快指针在链表末尾时，慢指针恰好在链表中点）；
 *    2）写出merge函数，即如何合并链表。
 *    3）写出mergesort函数，实现上述步骤。 
 * 
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next)
            return head;
        
        ListNode *p_slow = head;
        ListNode *p_fast = head->next;
        /* 使用快慢指针找到链表的中间位置 */
        while (p_fast && p_fast->next) {
            p_slow = p_slow->next;
            p_fast = p_fast->next->next;
        }
        /* 找到中间节点后，分别对左右链表进行递归操作 */
        ListNode *left = sortList(p_slow->next);
        /* 由于左边的链表也需要递归，所以需要把左右两边的链表断开连接 */
        p_slow->next = NULL;
        ListNode *right = sortList(head);
        
        return merge(left, right);
    }
    
    ListNode *merge(ListNode *left, ListNode *right) {
        ListNode dummy(0);
        ListNode *p = &dummy;
        /* 从左右链表中取值，根据从小到大的顺序取 */
        while (left && right) {
            if (left->val > right->val) {
                p->next = right;
                right = right->next;
            } else {
                p->next = left;
                left = left->next;
            }
            
            p = p->next;
        }
        
        if (left) {
            p->next = left;
        } else if (right) {
            p->next = right;
        }
        /* 返回从小到大排序的完整链表 */
        return dummy.next;
    }
};