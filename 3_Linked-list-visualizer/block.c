#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "block.h"


Block* NodeToBlock(LinkedList* pList, Node* pNode)
{
	Block* newBlock = malloc(sizeof(Block));
	if(!newBlock || pNode == pList->head) return NULL;

	newBlock->addr = pNode;
	strncpy(newBlock->data, pNode->data, DATA_COUNT + 1);
	newBlock->next = pNode->next;
	newBlock->flags = 0;

	if(pNode == pList->head->next) newBlock->flags |= FLAGS_HEAD;
	if(pNode == pList->cur) newBlock->flags |= FLAGS_CUR;
	if(pNode == pList->tail) newBlock->flags |= FLAGS_TAIL;

	return newBlock;
}

void StampBlockToBuffer(Block block, char (*twodbuffer)[BLOCK_WIDTH])
{
	char temp[64];

	if(block.next)
	{
		// addr
		sprintf(temp, "%#018lx   ┌─▶", (unsigned long)block.addr);
		strcpy(twodbuffer[0], temp); 

		// wall 1
		strcpy(twodbuffer[1], "┌──────────────────┐ │");

		// data
		sprintf(temp, "│%-18s│ │", block.data);
		strncpy(twodbuffer[2], temp, BLOCK_WIDTH);

		// wall 2
		strncpy(twodbuffer[3], "├──────────────────┤ │", BLOCK_WIDTH);
	
		// next addr
		sprintf(temp, "│%#018lx●─┘", (unsigned long)block.next);
		strncpy(twodbuffer[4], temp, BLOCK_WIDTH);
	}
	else
	{
		// addr
		sprintf(temp, "%#018lx", (unsigned long)block.addr);
		strcpy(twodbuffer[0], temp); 

		// wall 1
		strcpy(twodbuffer[1], "┌──────────────────┐");

		// data
		sprintf(temp, "│%-18s│", block.data);
		strncpy(twodbuffer[2], temp, BLOCK_WIDTH);

		// wall 2
		strncpy(twodbuffer[3], "├──────────────────┤", BLOCK_WIDTH);
	
		// next addr
		strncpy(twodbuffer[4], "│NULL              ○", BLOCK_WIDTH);
	}
	// wall 3
	strncpy(twodbuffer[5], "└──────────────────┘", BLOCK_WIDTH);

	// flags
}
