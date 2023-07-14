/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:43:00 by sangyepa          #+#    #+#             */
/*   Updated: 2023/07/14 23:58:40 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"
#include	<string.h>
#include	<stdio.h>

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	char		*temp;
	char		*buf;
	int			read_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (backup)
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
		if (backup)
			free(backup);
		return (0);
	}
	if (!backup)
	{
		backup = strdup("");
		if (!backup)
		{
			free(buf);
			return (0);
		}
	}
	while (!strchr(buf, '\n'))
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
		{
			free(backup);
			backup = 0;
			free(buf);
			return (0);
		}
		else if (read_size == 0)
			break ;
		buf[read_size] = 0;
		temp = backup;
		backup = ft_strjoin(temp, buf);
		free(temp);
		if (!backup)
		{
			free(backup);
			backup = 0;
			free(buf);
			return (0);
		}
	}
	line = backup;
	if (strchr(line, '\n'))
		*(strchr(line, '\n') + 1) = 0;
	if (strchr(backup, '\n') && *(strchr(backup, '\n') + 1))
		backup = strchr(backup, '\n') + 1;
	else if (!*(strchr(backup, '\n') + 1))
		backup = 0;
	line = strdup(line);
	if (!line)
	{
		free(backup);
		backup = 0;
		free(buf);
		return (0);
	}
	free(buf);
	return (line);
}



// 1. 읽은거에 개행이 들어있을 때
// 2. 읽은거에 개행이 없을 때 -> 더 읽어야함
	// i) 계속 읽다가 개행을 만나면 1로 가면 됨
	// ii)EOF 만남