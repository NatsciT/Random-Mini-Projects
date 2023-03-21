#include <stdio.h>


extern long sim_strcpy(char* src, char* des, long count);

int main(int argc, char** argv)
{
	char empty[50] = "";

	if(argc != 2)
		return -1;

	printf("%ld\n%s\n", sim_strcpy(argv[1], empty, 10), empty);
	
	return 0;
}
