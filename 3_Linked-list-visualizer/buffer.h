#pragma once

#define true	1
#define false	0

typedef int bool;
typedef char Data;

typedef struct __buffer
{
	char* addr;
	int width;
	int height;
} Buffer;



bool BufferInit(Buffer* pBuf);
void BufferFree(Buffer* pBuf);

void BufferSet(Buffer* pBuf, Data data)
