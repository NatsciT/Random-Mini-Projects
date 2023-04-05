#pragma once

#define true	1
#define false	0

#define NODE_HEAD	0
#define NODE_NEXT	1
#define NODE_TAIL	2

typedef int bool;
typedef const char* Data;

typedef struct __node
{
	Data data;
	struct __node* next;
} Node;

typedef struct __linkedlist
{
	Node* head;
	Node* cur;
	Node* tail;
	int count;
} LinkedList;



bool ListInit(LinkedList* pList);
void ListFree(LinkedList* pList);

bool ListInsertNext(LinkedList* pList, Data data);
Data ListDeleteNext(LinkedList* pList);

Data ListNavigate(LinkedList* pList, int type);
int ListItemCount(LinkedList* pList);
