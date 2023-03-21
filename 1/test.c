#include <stdio.h>

extern void _main_start(void);



int main(int argc, char* argv[])
{
	_main_start();

	return 0;
}
