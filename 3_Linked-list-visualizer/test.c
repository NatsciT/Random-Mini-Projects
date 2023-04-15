#includ <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>



int main(void)
{
	int cols = 0, lines = 0;
#if defined(TIOCGSIZE)
	struct ttysize sz;
	ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
	cols = ts.ts_cols;
	lines = ts.ts_lines;
#elif defined(TIOCGWINSZ)
	struct winsize ts;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &ts);
	cols = ts.ws_col;
	lines = ts.ws_row;
#endif
	printf("console is %dx%d", cols, lines);
	return 0;
}
