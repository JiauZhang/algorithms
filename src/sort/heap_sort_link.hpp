#include <stdio.h>
#include <stdlib.h>

struct Node {
	Node *parent, *lson, *rson;
	void *data;
};

struct Data {
	int val;	
	Node *node;
};

Node *create_node(void *data)
{
	Node *node = new Node();
	node->data = data;
	node->parent = 0;
	node->lson = 0;
	node->rson = 0;
	
	return node;
}

Node *insert_node(Node *head, Node *tail, Node *next)
{
	
}
