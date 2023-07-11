#include	"get_next_line.h"
#include	<stdio.h>
#include	<fcntl.h>

int main(void)
{
	int		check;
	int		fd = open("a.txt", O_RDONLY);
	char	*buf;

	check = read(fd, buf, 3);
	printf("%d", check);
	printf("%s\n", get_next_line(fd));
}
