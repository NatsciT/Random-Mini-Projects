#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"
#include "block.h"



Block* NodeToBlock(LinkedList* pList, Node* pNode);
{
	Block* newBlock = malloc(sizeof(Block));
	if(!newBlock || pNode == pList->head) return NULL;

	newBlock->addr = pNode;
	strncpy(newBlock->data, pNode->data, DATA_COUNT + 1);
	newBlock->next = pNode->next;
	newBlock->flags = 0;

	if(pNode == pList->head->next) flags |= FLAGS_HEAD;
	if(pNode == pList->cur) flags |= FLAGS_CUR;
	if(pNode == pList->tail) flags |= FLAGS_TAIL;
}
