#pragma once
#include "linkedlist.h"
#include "buffer.h"

#define DATA_COUNT	18

#define FLAGS_HEAD	0b00000001
#define FLAGS_CUR	0b00000010
#define FLAGS_TAIL	0b00000100

#define BLOCK_WIDTH	65
#define BLOCK_HEIGHT	7

typedef struct __block
{
	void* addr;
	char data[DATA_COUNT + 1];
	void* next;
	int flags;
} Block;

Block* NodeToBlock(LinkedList* pList, Node* pNode);
void StampBlockToBuffer(Block block, Buffer buffer);
