#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
	ListNode(): m_pNext(NULL) {}
	int m_nKey;
	ListNode* m_pNext;
};
//此函数不进行安全检查 
ListNode* find_tail(ListNode* pHead)
{
	ListNode* res = pHead;
	while(res->m_pNext)
		res = res->m_pNext;	
	return res;
}
//此函数不进行安全检查 
ListNode* find_value_prev(ListNode* pHead, int value)
{
	ListNode* head = pHead; 
	ListNode* prev = pHead;
	while(head->m_nKey != value && head->m_pNext) {
		prev = head;
		head = head->m_pNext;
	}
	if(head->m_nKey == value)
		return prev;
	else
		return NULL;
}

void add_to_tail(ListNode** pHead, int value)
{
	if(pHead) {
		if(*pHead) {
			ListNode* tail = find_tail(*pHead);
			ListNode* next = new ListNode();
			tail->m_pNext = next;
			next->m_nKey = value;
		} else {
			*pHead = new ListNode();
			(*pHead)->m_nKey = value;
		}
	}
}

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

void remove_node(ListNode** pHead, int value)
{
	if(pHead && *pHead) {
		ListNode* prev = find_value_prev(*pHead, value);
		if(prev) {
			ListNode* rm = prev->m_pNext;			
			if(rm->m_pNext) {
				ListNode* next = rm->m_pNext;
				if(prev == *pHead)
					*pHead = next;
				else
					prev->m_pNext = next;
				delete rm;
			} else { //此情况时，待删除的节点为最后一个或仅有的且是第一个 
				if(prev == *pHead)
					*pHead = NULL;
				else
					prev->m_pNext = NULL;
				delete rm;
			}
		}
	}
}

void print_list_tail_to_head(ListNode* pHead)
{
	if(pHead) {
		stack<ListNode*> list_stack;
		ListNode* node = pHead;
		list_stack.push(node);
		while(node->m_pNext) {
			node = node->m_pNext;
			list_stack.push(node);			
		}
		while(!list_stack.empty()){
			node = list_stack.top();
			cout << node->m_nKey << ' ';
			list_stack.pop();
		}
		cout << endl;			
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

int main(int argc, char** argv)
{
	ListNode* pHead = NULL;
	
	add_to_tail(&pHead, 1);
	add_to_tail(&pHead, 2);
	add_to_tail(&pHead, 3);
	add_to_tail(&pHead, 4);
	add_to_tail(&pHead, 5);
	
	print_list_head_to_tail(pHead);
	print_list_tail_to_head(pHead);
	
	add_to_head(&pHead, 10);
	add_to_head(&pHead, 9);
	add_to_head(&pHead, 8);
	add_to_head(&pHead, 7);
	add_to_head(&pHead, 6);	
	
	print_list_head_to_tail(pHead);
	print_list_tail_to_head(pHead);
	
	remove_node(&pHead, 6);
	remove_node(&pHead, 5);
	remove_node(&pHead, 10);
	remove_node(&pHead, 3);
	remove_node(&pHead, 4);
	remove_node(&pHead, 7);
	
	print_list_head_to_tail(pHead);
	print_list_tail_to_head(pHead);
	
	return 0;
}
