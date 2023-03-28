#include <stdio.h>

extern long sim_strlen(char* str);
extern long sim_strcpy(char* src, char* des, long count);
extern long sim_strcat(char* des, char* str, long count);

int main(int argc, char** argv)
{
	char str1[16] = "test1";
	char str2[16] = "";

	if(argc != 2)
		return -1;

	puts("---- strcat ----");
	printf("str1: %lxd, ret: %lxd\nstring: %s\n\n",
			(unsigned long)str1,
			(unsigned long)sim_strcat(str1, argv[1], 16),
			str1);

	puts("---- strcpy ----");
	printf("before: %s\ncount: %s\nafter: %s\n\n",
			str2,
			sim_strcpy(argv[1], str2, 16),
			str2);

	puts("---- strlen ----");
	printf("string: %s\nlength: %ld\n\n",
			argv[1],
			sim_strlen(argv[1]));

	return 0;
}
