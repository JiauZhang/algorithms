#include <stdio.h>
#include <stdlib.h>

struct Node {
	Node *next, *prev;
	void *data;
};

typedef int Compare(Node *, Node *);


struct Data {
	int val;
};

const int max = 99, min = 0;
const int loop = 10;
Data data[loop];
Node nodes[loop];
Node *head = 0;

void print_nodes(Node *head)
{
	while (head) {
		printf("head: %d, hn: %d, hp: %d, data: %d\n", head, head->next, head->prev, head->data);
		head = head->next;
	}
}

void print_data(Data *data, int lenght)
{
	for (int i=0; i<lenght; i++) {
		Data *d = data + i;
		printf("data: %d=%d\n", d, d->val);
	}
	printf("\n");
}

void replace_node(Node *n, Node *prev, Node *next)
{
	n->next = next;
	n->prev = prev;
	
	if (prev)
		prev->next = n;
	if (next)
		next->prev = n;
}

void swap_node(Node *n1, Node *n2)
{
	Node *n1next = n1->next;
	Node *n1prev = n1->prev;
	Node *n2next = n2->next;
	Node *n2prev = n2->prev;
	
	replace_node(n1, n2prev, n2next);
	replace_node(n2, n1prev, n1next);
}

Node *partition(Node *start, Node *end, Compare *compare)
{
	Node *slow = start;
	Node *fast = start->next;
	
	while (fast != end) {
		if (compare(fast, start)) {
			slow = slow->next;
			swap_node(slow, fast);
			print_nodes(head);
		}
		
		fast = fast->next;
	}
}

void qsort(Node *start, Node *end, Compare *compare)
{
	if (start != end) {
		Node *mid = partition(start, end, compare);
		qsort(start, mid, compare);
		qsort(mid->next, end, compare);
	}
}

Node *insert_node(Node *head, Node *next)
{
	if (head) {
		next->next = head;
		head->prev = next;
	} else {
		next->next = 0;
	}
	next->prev = 0;
	
	return next;
}

int compare_data(Node *n1, Node *n2)
{
	Data *d1 = (Data *)n1->data;
	Data *d2 = (Data *)n2->data;
	return d1->val < d2->val;
}

void qsort_main()
{
	printf("Start qsort test...\n");

	for (int i=0; i<loop; i++) {
		Data *d = data + i;
		d->val = (rand()%(max-min+1))+min;
		
		Node *node = nodes + i;
		node->data = d;
		
		head = insert_node(head, node);
	}
	
	print_nodes(head);
	print_data(data, loop);
	qsort(head, 0, compare_data);
	
	printf("Finish qsort test...\n");
}
