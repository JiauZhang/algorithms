/*
 * 题目描述：
 *     输入一个链表，输出该链表中倒数第k个结点。
 * 
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 *     ListNode(int x) :
 *             val(x), next(NULL) {
 *     }
 * };
 *     
 * 解题思路：
 *     使用两个指针，快的比慢的多走 k 步
 *     注意事项：当链表长度不足 k 个时返回 NULL
 *     1. 一个指针先走 k 步，走k步后，该指针指向下一个
 *     2. 同时移动两个指针，直到快指针指向NULL
 *     3. 返回慢指针
 */
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == NULL)
            return NULL;
        
        ListNode *pRight = pListHead;
        ListNode *pLeft = pListHead;
        for (int i=0; i<k; i++) {
            if (pRight == NULL)
                return NULL;
            else
                pRight = pRight->next;
        }
        
        while (pRight) {
            pRight = pRight->next;
            pLeft = pLeft->next;
        }
        
        return pLeft;
    }
};