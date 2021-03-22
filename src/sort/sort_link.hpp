#include <stdio.h>
#include <stdlib.h>

struct Node {
	Node *next, *prev;
	void *data;
};

typedef int Compare(Node *, Node *);
typedef void Swap(Node *, Node *);

struct Data {
	int val;
	
	Node *node; 
};

void print_nodes(Node *head)
{
	while (head) {
		Data *d = (Data *)head->data;
		printf("head: %d, hn: %d, hp: %d, data: [%d]=%d, node: %d\n", \
			head, head->next, head->prev, head->data, d->val, d->node);
		head = head->next;
	}
	printf("\n");
}

void print_data(Data *data, int lenght)
{
	for (int i=0; i<lenght; i++) {
		Data *d = data + i;
		printf("data: [%d]=%d, node: %d\n", d, d->val, d->node);
	}
	printf("\n");
}

Node *partition(Node *start, Node *end, Compare *compare, Swap *swap_node)
{
	Node *slow = start;
	Node *fast = start->next;
	
	while (fast != end) {
		if (compare(fast, start)) {
			slow = slow->next;
			if (slow != fast)
				swap_node(slow, fast);
		}
		
		fast = fast->next;
	}
	swap_node(slow, start);
	
	return slow;
}

void qsort(Node *start, Node *end, Compare *compare, Swap *swap)
{
	if (start != end) {
		Node *mid = partition(start, end, compare, swap);
		qsort(start, mid, compare, swap);
		qsort(mid->next, end, compare, swap);
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
	return d1->val > d2->val;
}

void swap_data(Node *n1, Node *n2)
{	
	void *data = n1->data;
	n1->data = n2->data;
	n2->data = data;
	
	Data *d1 = (Data *)n1->data;
	Data *d2 = (Data *)n2->data;
	d1->node = n1;
	d2->node = n2;
}

void qsort_main()
{
	const int max = 99, min = 0;
	const int loop = 10;
	Data data[loop];
	Node nodes[loop];
	Node *head = 0;
	
	printf("Start qsort test...\n");

	for (int i=0; i<loop; i++) {
		Data *d = data + i;
		d->val = (rand()%(max-min+1))+min;
		
		Node *node = nodes + i;
		node->data = d;
		d->node = node;
		
		head = insert_node(head, node);
	}
	
	print_nodes(head);
	print_data(data, loop);
	qsort(head, 0, compare_data, swap_data);
	print_nodes(head);
	print_data(data, loop);
	
	printf("Finish qsort test...\n");
}
