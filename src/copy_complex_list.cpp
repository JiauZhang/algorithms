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

struct complex_list_node
{
	complex_list_node(int value): m_Value(value), m_pNext(NULL), m_pSibling(NULL) {}
	int m_Value;
	complex_list_node* m_pNext;
	complex_list_node* m_pSibling;
};

void make_complex_list(complex_list_node **head)
{
	*head = new complex_list_node(1);
	complex_list_node *current = *head;
	for (int i=2; i<7; i++) {
		complex_list_node *next = new complex_list_node(i);
		current->m_pNext = next;
		current = next;
	}
	
	complex_list_node *sibling;
	current = *head;
	sibling = current->m_pNext->m_pNext;
	current->m_pSibling = sibling;
	sibling->m_pSibling = current;
	sibling = sibling->m_pNext;
	sibling->m_pSibling = sibling;
}

void print_complex_list(complex_list_node *head)
{
	while (head) {
		cout << head->m_Value;
		if (head->m_pSibling)
			cout << " -> " << head->m_pSibling->m_Value << endl;
		else
			cout << endl;
		head = head->m_pNext;
	}
}

void clone_complex_list(complex_list_node *head, complex_list_node **clone)
{
	*clone = head;
	while (head) {
		complex_list_node *clone_next = new complex_list_node(head->m_Value);
		clone_next->m_pNext = head->m_pNext;
		head->m_pNext = clone_next;
		head = clone_next->m_pNext;
	}
}

void connect_sibling_nodes(complex_list_node *head)
{
	while(head) {
		if (head->m_pSibling) {
			complex_list_node *clone_next = head->m_pNext;
			clone_next->m_pSibling = head->m_pSibling->m_pNext;
		} 
		head = head->m_pNext->m_pNext;
	}
}

void reconnect_nodes(complex_list_node *head, complex_list_node **clone)
{
	if (head)
		*clone = head->m_pNext;
	while (head) {
		complex_list_node *clone_ = head->m_pNext;
		if (clone_->m_pNext) {
			complex_list_node *head_next = clone_->m_pNext;
			complex_list_node *clone_next = head_next->m_pNext;
			head->m_pNext = head_next;
			clone_->m_pNext = clone_next;
			head = head->m_pNext;
		} else {
			break;
		}
	}
}

int main(int argc, char** argv)
{
	cout << "step 1" << endl;
	complex_list_node *head = NULL;
	make_complex_list(&head);	
	print_complex_list(head);
	
	cout << "step 2" << endl;
	complex_list_node *clone;
	clone_complex_list(head, &clone);
	print_complex_list(head);
	
	cout << "step 3" << endl;
	connect_sibling_nodes(head);
	print_complex_list(head);
	
	cout << "step 4" << endl;
	reconnect_nodes(head, &clone);
	cout << "original complex list" << endl;
	print_complex_list(head);
	cout << "cloned complex list" << endl;
	print_complex_list(clone);
	
	return 0;
}
