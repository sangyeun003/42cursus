#include	<unistd.h>
#include	<stdlib.h>

#ifndef BUFFER_SIZE
# define	BUFFER_SIZE	1
#endif

char	*get_next_line(int fd);