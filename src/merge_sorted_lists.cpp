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

ListNode* merge(ListNode* root1, ListNode* root2)
{
	if(!root1 && root2) {
		return root2;
	}
	if(!root2 && root1) {
		return root1;
	}
	if(!root2 && !root1) {
		return NULL;
	}

	ListNode* root;	
	if(root1->m_nKey<root2->m_nKey) {
		root = root1;
		root1 = root1->m_pNext;
	} else {
		root = root2;
		root2 = root2->m_pNext;
	}
	root->m_pNext = merge(root1, root2);
	return root;
}

int main(int argc, char** argv)
{
	ListNode* root1 = NULL;
	add_to_head(&root1, 15);
	add_to_head(&root1, 13);
	add_to_head(&root1, 11);
	add_to_head(&root1, 9);
	add_to_head(&root1, 7);
	add_to_head(&root1, 5);
	add_to_head(&root1, 3);
	add_to_head(&root1, 1);
	
	ListNode* root2 = NULL;
	add_to_head(&root2, 16);
	add_to_head(&root2, 14);
	add_to_head(&root2, 12);
	add_to_head(&root2, 10);
	add_to_head(&root2, 8);
	add_to_head(&root2, 6);
	add_to_head(&root2, 4);
	add_to_head(&root2, 2);
	
	ListNode* root3 = NULL;
	add_to_head(&root3, 19);
	add_to_head(&root3, 14);
	add_to_head(&root3, 13);
	add_to_head(&root3, 10);
	add_to_head(&root3, 7);
	add_to_head(&root3, 4);
	add_to_head(&root3, 3);
	add_to_head(&root3, 2);
	
	ListNode* root4 = NULL;
	
	ListNode* root = merge(root1, root2);
	print_list_head_to_tail(root);
//此时root1 和 root2 指向的链表已经被改变了，不可再重复使用	
//	root = merge(root1, root3);
//	print_list_head_to_tail(root);
	
//	root = merge(root3, root2);
//	print_list_head_to_tail(root);

	ListNode* root5 = NULL;
	add_to_head(&root5, 10);
	add_to_head(&root5, 10);
	add_to_head(&root5, 10);
	add_to_head(&root5, 10);
	
	root = merge(root3, root4);
	print_list_head_to_tail(root);	
	
	root = merge(root3, root5);
	print_list_head_to_tail(root);
	
	return 0;
}
