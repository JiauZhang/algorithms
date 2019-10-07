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

//此函数不进行安全检查 
ListNode* find_prev(ListNode* root, ListNode* find)
{
	ListNode* prev;
	while(root->m_pNext!=find)
		root = root->m_pNext;
	prev = root;
	return prev;
} 

ListNode* deleteKthToEnd(ListNode** root, int k)
{
	if(!root || k<=0 || !(*root))
		return NULL;
	ListNode* pK, * pTail;
	pK = *root; pTail = *root;
	int pKCount = 1, pTailCount = 1;
	
	while(pTail->m_pNext) {
		/*
		if(pTail-pK == k-1) 不应该比较内存地址，而应该是比较第几个几个节点数 
		*/
		if(pTailCount-pKCount == k-1) {
			pK = pK->m_pNext;
			pKCount++;
		}
		pTail = pTail->m_pNext;
		pTailCount++;
	}
	//cout << pTail-pK << endl;
	/*if(pTail-pK == k-1) { */
	//此处删除节点应考虑删除的是否头部和尾部，需要特殊处理 
	ListNode* res;
	if(pTailCount-pKCount == k-1) {
		if(pK == *root) {
			*root = pK->m_pNext;
			res = pK;
			delete pK;
		} else if(pK->m_pNext==NULL) {
			ListNode* prev = find_prev(*root, pK);
			prev->m_pNext = NULL;
			res = pK;
			delete pK;
		} else {
			ListNode* pNext = pK->m_pNext;
			ListNode* pNextNext = pNext->m_pNext;
			pK->m_nKey = pNext->m_nKey;
			pK->m_pNext = pNextNext;
			res = pNext;
			delete pNext;
		}
		//cout << "successfully delete node" << endl;
		return res;
	} else {
		//cout << "failed to delete node" << endl;
		return NULL;
	}
}

int main(int argc, char** argv)
{
	ListNode* root = NULL;
	add_to_head(&root, 1);
	add_to_head(&root, 2);
	add_to_head(&root, 3);
	add_to_head(&root, 4);
	add_to_head(&root, 5);
	add_to_head(&root, 6);
	add_to_head(&root, 7);
	add_to_head(&root, 8);
	
	print_list_head_to_tail(root);
	deleteKthToEnd(&root, 3);
	print_list_head_to_tail(root);
	deleteKthToEnd(&root, 9);
	print_list_head_to_tail(root);
	deleteKthToEnd(&root, 0);
	print_list_head_to_tail(root);
	deleteKthToEnd(&root, 1);
	print_list_head_to_tail(root);
	
	return 0;
}
