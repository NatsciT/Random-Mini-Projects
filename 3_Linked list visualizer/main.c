#include <stdio.h>
#include <stdlib.h>

#include "block.h"
#include "linkedlist.h"



int main(int argc, char* argv[])
{
	LinkedList l;
	Data data;
	Block* pb;

	int i;
	char buf[BLOCK_HEIGHT][BLOCK_WIDTH];

	if(argc < 2)
	{
		printf("Usage: %s <data1> <data2> ...\n", argv[0]);
		return -1;
	}

	if(!ListInit(&l)) return -1;

	for(i = 1; i < argc; i++)
		ListInsertNext(&l, argv[i]);

	ListNavigate(&l, NODE_HEAD);
	while(data = ListNavigate(&l, NODE_NEXT))
	{
		pb = NodeToBlock(&l, l.cur);
		
		StampBlockToBuffer(*pb, buf);

		for(i = 0; i < BLOCK_HEIGHT; i++)
			printf("%s\n", buf[i]);
	}	

	ListFree(&l);
	return 0;
}
