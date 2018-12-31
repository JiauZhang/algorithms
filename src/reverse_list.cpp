#include <iostream>

using namespace std;

struct ListNode {
	ListNode(): m_pNext(NULL) {}
	int m_nKey;
	ListNode* m_pNext;
};

void add_to_head(ListNode** pHead, int value)
{
	if(pHead) {
		if(*pHead) {
			ListNode* pHead_ = *pHead;
			*pHead = new ListNode();
			(*pHead)->m_nKey = value;
			(*pHead)->m_pNext = pHead_;
		} else {
			*pHead = new ListNode();
			(*pHead)->m_nKey = value;
		}
	}
}

void print_list_head_to_tail(ListNode* pHead)
{
	if(pHead) {
		ListNode* head = pHead;
		cout << head->m_nKey << ' ';
		while(head->m_pNext) {
			head = head->m_pNext;
			cout << head->m_nKey << ' ';
		}
		cout << endl;
	}
}
//解题思路
//1.把指针为空特殊情况排除 
//2.把仅有一个节点的情况特殊处理掉
//3.判断是否有多余两个节点的情况，如果有，使用三个指针
//  分别指向前一个，当前的，下一个，反转链表，平移这三个指针
//4.收尾工作 
void reverse_list(ListNode** root)
{
	if(!root || !(*root))
		return;
	if((*root)->m_pNext == NULL) { //仅一个节点 
		return; 
	}
	//现在只剩下至少有两个节点的情况了 
	ListNode* pCur, * pNext, * pPrev;
	pCur = *root; pNext = pCur->m_pNext;
	
	while(pNext->m_pNext) { //把所有中间节点都反转 
		pPrev = pCur;
		pCur = pNext;
		pNext = pCur->m_pNext;
		pCur->m_pNext = pPrev;		
	}
	//收尾工作
	pNext->m_pNext = pCur; //原来的尾节点 
	(*root)->m_pNext = NULL; //原来的头部节点
	*root = pNext;
}

int main(int argc, char** argv)
{
	ListNode* root = NULL;
	add_to_head(&root, 1);
	print_list_head_to_tail(root);
	reverse_list(&root);
	print_list_head_to_tail(root);
	
	add_to_head(&root, 2);
	add_to_head(&root, 3);
	add_to_head(&root, 4);
	print_list_head_to_tail(root);
	reverse_list(&root);
	print_list_head_to_tail(root);
	
	add_to_head(&root, 5);
	add_to_head(&root, 6);
	add_to_head(&root, 7);
	add_to_head(&root, 8);	
	print_list_head_to_tail(root);
	reverse_list(&root);
	print_list_head_to_tail(root);
	
	return 0;
}
