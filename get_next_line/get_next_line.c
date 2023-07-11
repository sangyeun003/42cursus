/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:43:00 by sangyepa          #+#    #+#             */
/*   Updated: 2023/07/11 18:42:24 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"
#include	<string.h>

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	char		*buf;
	int			read_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(backup);
		return (0);
	}
	if (backup)
	{
		if (!(*backup))
		{
			free(backup);
			return (0);
		}
	}
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
	{
		free(backup);
		return (0);
	}
	while (!strchr(backup, '\n'))
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
		{
			free(backup);
			free(buf);
			return (0);
		}
		buf[read_size] = 0;
		if (!backup)
			backup = strdup(buf);
		else
			backup = ft_strjoin(backup, buf);
		if (!backup)
		{
			free(buf);
			return (0);
		}
	}
	line = strdup(backup);
	if (!line)
	{
		free(backup);
		free(buf);
		return (0);
	}
	*(strchr(line, '\n') + 1) = 0;
	backup = strchr(backup, '\n') + 1;
	line = strdup(line);
	if (!line)
	{
		free(backup);
		free(buf);
		return (0);
	}
	return (line);
}



// 1. 읽은거에 개행이 들어있을 때
// 2. 읽은거에 개행이 없을 때 -> 더 읽어야함