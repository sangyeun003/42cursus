#include	"get_next_line.h"
#include	<stdio.h>
#include	<fcntl.h>

int main(void)
{
	int		check;
	int		fd = open("test2.c", O_RDONLY);
	char	*buf;

	check = read(fd, buf, 3);
	printf("%d", check);
}
