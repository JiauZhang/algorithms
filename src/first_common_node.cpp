#include <iostream>

using namespace std;

struct ListNode {
	int key;
	ListNode *pNext;
};

ListNode *add(ListNode **root, int key)
{
	if (!root)
		return NULL;
	
	ListNode *next = new ListNode;
	
	if (*root == NULL) {
		*root = next;
	} else {
		(*root)->pNext = next;
	}	
	next->key = key;
	next->pNext = NULL;
	
	return next;
}

int getListLength(ListNode *root)
{
	int length = 0;
	cout << 7 << endl;
	while (root->pNext) {
		length++;
		root = root->pNext;
	}
	cout << 6 << endl;
	return length;
}

ListNode *find_fisrt_common_node(ListNode *root1, ListNode *root2)
{
	cout << 7 << endl;
	int len1 = getListLength(root1);
	int len2 = getListLength(root2);
	cout << 8 << endl;
	int bias = len1-len2;
	ListNode *longerList = root1;
	ListNode *shorterList = root2;
	if (len1 < len2) {
		bias = -bias;
		longerList = root2;
		shorterList = root1;
	}
	cout << 9 << endl;
	while (bias > 0) {
		longerList = longerList->pNext;
		bias--;
	}
	cout << 10 << endl;
	while (longerList != shorterList && longerList->pNext && shorterList->pNext) {
		longerList = longerList->pNext;
		shorterList = shorterList->pNext;
	}
	
	return longerList;	
}

int main(int argc, char **argv)
{
	ListNode *root1 = NULL;
	ListNode *root2 = NULL;
	cout << 111 << endl;
	ListNode *next1 = new ListNode;
	root1 = next1;
	root1->pNext = NULL;
	ListNode *next2 = new ListNode;
	next1->pNext = next2;
	ListNode *next3 = new ListNode;
	next2->pNext = next3;
	ListNode *next4 = new ListNode;
	next3->pNext = next4;
	next4->pNext = NULL;
	cout << 112 << endl;
	ListNode *next5 = new ListNode;
	//此时的root2还为NULL，所以不存在实例 
	//root2->pNext = next5;
	root2 = next5;
	ListNode *next6 = new ListNode;
	next5->pNext = next6;
	next6->pNext = next4;
	ListNode *next8 = new ListNode;
	next4->pNext = next8;
	ListNode *next9 = new ListNode;
	next8->pNext = next9;
	next9->pNext = NULL;
	cout << 110 << endl;
	cout << "common node: " << next4 << endl;
	ListNode *result = find_fisrt_common_node(root1, root2);
	cout << "result: " << result << endl;	
	
	return 0;
}
