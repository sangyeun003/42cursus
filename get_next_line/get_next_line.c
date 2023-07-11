/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:43:00 by sangyepa          #+#    #+#             */
/*   Updated: 2023/07/11 21:48:00 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"
#include	<string.h>
#include	<stdio.h>

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
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
		free(backup);
		return (0);
	}
	if (!backup)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
		{
			free(backup);
			backup = 0;
			free(buf);
			return (0);
		}
		buf[read_size] = 0;
		backup = strdup(buf);
		if (!backup)
		{
			free(backup);
			backup = 0;
			free(buf);
			return (0);
		}
	}
	while (!strchr(backup, '\n') && read_size == BUFFER_SIZE)
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
		backup = ft_strjoin(backup, buf);
		if (!backup)
		{
			free(backup);
			backup = 0;
			free(buf);
			return (0);
		}
	}
	line = strdup(backup);
	if (!line)
	{
		free(backup);
		backup = 0;
		free(buf);
		return (0);
	}
	if (strchr(line, '\n'))
		*(strchr(line, '\n') + 1) = 0;
	if (strchr(backup, '\n'))
	{
		backup = strchr(backup, '\n') + 1;
		line = strdup(line);
		if (!line)
		{
			free(backup);
			backup = 0;
			free(buf);
			return (0);
		}
	}
	else
		backup = 0;
	return (line);
}



// 1. 읽은거에 개행이 들어있을 때
// 2. 읽은거에 개행이 없을 때 -> 더 읽어야함
	// i) 계속 읽다가 개행을 만나면 1로 가면 됨
	// ii)EOF 만남