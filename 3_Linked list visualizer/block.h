#define DATA_COUNT	18

#define FLAGS_HEAD	0b00000001
#define FLAGS_CUR	0b00000010
#define FLAGS_TAIL	0b00000100

typedef struct __block
{
	void* addr;
	char data[DATA_COUNT + 1];
	void* next;
	int flags;
} Block;
