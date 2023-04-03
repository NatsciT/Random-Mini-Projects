#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"



int main(int argc, char* argv[])
{
	LinkedList l;
	Data tmp;
	int i;

	if(argc < 2)
	{
		printf("Usage: %s <data1> <data2> ...\n", argv[0]);
		return -1;
	}

	if(!ListInit(&l)) return -1;

	for(i = 1; i < argc; i++)
	{
		ListInsertNext(&l, argv[i]);
		printf("%d\n", ListItemCount(&l));
	}

	ListNavigate(&l, NODE_HEAD);

	while(tmp = ListNavigate(&l, NODE_NEXT))
		printf("%s ", tmp);

	ListNavigate(&l, NODE_HEAD);
	printf("\n");

	while(ListItemCount(&l))
	{
		printf("%d. ", ListItemCount(&l));
		printf("%s\n", ListDeleteNext(&l));
	}

	ListFree(&l);
	return 0;
}
