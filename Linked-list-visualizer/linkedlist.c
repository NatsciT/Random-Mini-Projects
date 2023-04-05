#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"



// Internal functions
bool AddNode(Node* node_before, Data data);



bool ListInit(LinkedList* pList)
{
	// Make a dummy node
	// And point head and tail pointer toward it
	if(!(pList->head = malloc(sizeof(Node)))) return false;
	pList->cur = pList->head;
	pList->tail = pList->head;

	// Initialize the dummy node
	pList->head->data = NULL;
	pList->head->next = NULL;

	// Set element count to zero
	pList->count = 0;
	return true;
}

void ListFree(LinkedList* pList)
{
	pList->cur = pList->head;
	while(pList->head->next) ListDeleteNext(pList);

	free(pList->head);

	pList->head = NULL;
	pList->cur = NULL;
	pList->tail = NULL;
	pList->count = 0;
}



bool ListInsertNext(LinkedList* pList, Data data)
{
	// Create new node
	Node* newNode = malloc(sizeof(Node));
	if(!newNode) return false;

	newNode->data = data;
	newNode->next = pList->cur->next;
	pList->cur->next = newNode;
	pList->cur = newNode;

	(pList->count)++;
	return true;
}

Data ListDeleteNext(LinkedList* pList)
{
	Node* delNode = pList->cur->next;
	Data delData = delNode->data;

	pList->cur->next = delNode->next;

	free(delNode);
	(pList->count)--;
	return delData;
}



Data ListNavigate(LinkedList* pList, int type)
{
	switch(type)
	{
	case NODE_HEAD:
		pList->cur = pList->head;
		break;
	case NODE_NEXT:
		if(pList->cur->next == NULL)
			return NULL;
		pList->cur = pList->cur->next;
		break;
	case NODE_TAIL:
		pList->cur = pList->tail;
		break;
	default:
		return NULL;
	}

	return pList->cur->data;
}

int ListItemCount(LinkedList* pList)
{
	return pList->count;
}
