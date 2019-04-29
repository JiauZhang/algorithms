/*
 * 题目描述
 * 输入两个单调递增的链表，输出两个链表合成后的链表，
 * 当然我们需要合成后的链表满足单调不减规则。
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
 *     两个有序链表融合，其实就是有序的从两个链表中取节点即可
 *     1. 首先声明一个用于记录根节点的变量，然后根据排序要求选择
 *        从哪个链表中取节点
 *     2. 两个原始的头指针分别指向待取的节点
 *     3. 最后判断是否某一个链表还有剩余，如果有剩余直接连接上即可
 *     4. 返回新的头结点
 * 
 */
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == NULL)
            return pHead2;
        if (pHead2 == NULL)
            return pHead1;
        
        ListNode root(0);
        ListNode *cur = &root;
        
        while (pHead1 && pHead2) {
            if (pHead1->val < pHead2->val) {
                cur->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            
            cur = cur->next;
        }
        
        if (pHead1) {
            cur->next = pHead1;
        } else if (pHead2) {
            cur->next = pHead2;
        }
        
        return root.next;
    }
};