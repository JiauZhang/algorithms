#include <iostream>

using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* add_to_head(ListNode** pHead, int value)
{
	if(pHead) {
		if(*pHead) {
			ListNode* pHead_ = *pHead;
			*pHead = new ListNode();
			(*pHead)->m_nValue = value;
			(*pHead)->m_pNext = pHead_;
		} else {
			*pHead = new ListNode();
			(*pHead)->m_nValue = value;
		}
		return *pHead;
	}
}

//此函数不进行安全检查 
ListNode* find_prev(ListNode* root, ListNode* find)
{
	ListNode* prev;
	while(root->m_pNext!=find)
		root = root->m_pNext;
	prev = root;
	return prev;
} 

//主要思想就是，如果此节点不是链表中最后一个
//把它的下一个复制过来，然后当前的指针指向下一个的下一个
//最后删除下一个 
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
	if(pListHead) {
		if(*pListHead) {
			if(*pListHead==pToBeDeleted) { //如果这个节点在头部 
				/*if(pToBeDeleted->m_pNext==NULL) { //如果这个节点唯一的 
					*pListHead = NULL;
					delete pToBeDeleted;
				} else {
					*pListHead = pToBeDeleted->m_pNext;
					delete pToBeDeleted;
				}*/
				//可以简化代码
				*pListHead = pToBeDeleted->m_pNext;
				delete pToBeDeleted;
			} else if(pToBeDeleted->m_pNext==NULL) { //如果此节点在尾部，只能从头遍历
				ListNode* prev = find_prev(*pListHead, pToBeDeleted);
				prev->m_pNext = NULL;
				delete pToBeDeleted;
			} else { //只剩下在中间部分的情况了 
				ListNode* pNext = pToBeDeleted->m_pNext;
				ListNode* pNextNext = pNext->m_pNext;
				pToBeDeleted->m_nValue = pNext->m_nValue;
				pToBeDeleted->m_pNext = pNextNext;
				delete pNext; 
			}
		}
	} 
}

void print_list_head_to_tail(ListNode* pHead)
{
	if(pHead) {
		ListNode* head = pHead;
		cout << head->m_nValue << ' ';
		while(head->m_pNext) {
			head = head->m_pNext;
			cout << head->m_nValue << ' ';
		}
		cout << endl;
	}
}
//这个程序有个假设，那就是我们给出的节点一定就在此链表中 
int main(int argc, char** argv)
{
	ListNode* root = NULL;
	ListNode* node6 = add_to_head(&root, 6);
	ListNode* node5 = add_to_head(&root, 5);
	ListNode* node4 = add_to_head(&root, 4);
	ListNode* node3 = add_to_head(&root, 3);
	ListNode* node2 = add_to_head(&root, 2);
	ListNode* node1 = add_to_head(&root, 1);
	
	print_list_head_to_tail(root);
	
	DeleteNode(&root, node3);
//	DeleteNode(&root, node4); 与下边的程序同样的问题 
	print_list_head_to_tail(root);
	//由于为了实现 O(1) 的删除效率，所以删除node5的时候其实node6已经不存在了
	//所以执行删除node6才会出错 
	DeleteNode(&root, node5);
	//DeleteNode(&root, node6);替换为再次删除node5才可以，因为此时它在尾部 
	DeleteNode(&root, node5);
	print_list_head_to_tail(root);
	
	DeleteNode(&root, node1);
	print_list_head_to_tail(root);
	
	DeleteNode(&root, node2);
	DeleteNode(&root, node3);
	print_list_head_to_tail(root);
	
	return 0;
} 
