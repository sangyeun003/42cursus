#include	<unistd.h>
#include	<stdlib.h>

#ifndef BUFFER_SIZE
# define	BUFFER_SIZE	1
#endif

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*newline;
	int			count_read;
	int			to_copy;

	line = ft_strdup(buf);
	while ()
}